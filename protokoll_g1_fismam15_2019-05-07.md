# Protokoll 7 (07.05.2019)
Name: Fischer Maximilian  
KNr.: 2  
Klasse: 4AHME  
Gruppe: 1  
___

### Übersicht

1. Korrigieren des Programmes der vorigen Einheit
   1. Problemstelle
   1. Lösung
       1. Berechnung
       1. Ausgleich des Fehlers
1. Übertragung mithilfe von UART
___

## **1** Modbus Request handler

Zuerst haben wir ein paar Funktionen definiert um das Modbus Protokoll in C zu implementieren.

uint8_t hex2int(char h);
uint16_t app_inc16BitCount (uint16_t cnt);
void app_handleUartByte (char c);

In der `app.h` haben wir zusätzlich noch einen Error-Zähler und den *Temperaturwert* (mbInputReg01) definiert um sie global nutzen zu können.

```c
struct App
{
  uint8_t flags_u8;
  char modbusBuffer[32];
  uint8_t bufferIndex;
  uint16_t errCnt;
  uint16_t mbInputReg01;
};
```

Die Funktion handleUartByte kümmert sich um neue Zeichen die der µC empfängt.
Er versucht die Zeichen in einen Buffer zu speichern um diese Zeichenkette bei abschließendem *\n*
dann als Request zu interpretieren.

Bei einem Fehler ruft die Funktion app_inc16BitCount auf.

```c
void app_handleUartByte(char c) {
  if(c == ':') {
    
    if(app.bufferIndex > 0) {
      app.errCnt = app_inc16BitCount(app.errCnt);
    }
    //app.bufferIndex=0;
    app.modbusBuffer[0] = c;
    app.bufferIndex=1;
  } else if(app.bufferIndex == 0){
    app.errCnt = app_inc16BitCount(app.errCnt);
    
  } else if (app.bufferIndex >= sizeof(app.modbusBuffer)) {
    app.errCnt = app_inc16BitCount(app.errCnt);
    
  } else {
    app.modbusBuffer[app.bufferIndex++] = c;
    if(c == '\n') {
      uint8_t errCode =  app_handleModbusRequest();
      if(errCode != 0) {
        //printf("Fehler: %u\r\n", errCode);
        app.errCnt = app_inc16BitCount(app.errCnt);
      }
      app.bufferIndex = 0;
    }
  }
}
```

Die Funktion app_inc16BitCount erhöht eine zahl um 1, aber lässt diese nicht overflown.

```c
uint16_t app_inc16BitCount(uint16_t cnt) {
  //sys_setLed(1);
  return cnt == 0xffff ? cnt : cnt+1;
}
```

Die Funktion hex2int wandelt einen Character im Hexadezimalformat um zu einer Dezimalzahl.

```c
uint8_t hex2int(char h) {
  if(h >= '0' && h<= '9') return h-'0';
  if(h >= 'A' && h<= 'F') return h-'A'+10;
  return 0xff; //Fehler
}
```

Der 1ms Task wird in diesem Fall dazu genutz die LED für 2 Sekunden einzuschalten wenn ein Fehler auftritt.
Diese Art der Fehlerausgabe ist sehr einfach, aber trotzdem wirksam.
Wenn das Programm einige Fehler hintereinander auswirft, bleibt die LED im eingeschaltenen Zustand.


```c
void app_task_1ms (void) {
  static uint16_t oldErrCnt = 0;
  static uint16_t timer = 0;
  if(app.errCnt != oldErrCnt) {
    oldErrCnt = app.errCnt;
    timer = 2000;
    sys_setLed(1);
    printf("Err");
  }
  if(timer > 0) {
    timer--;
    if(timer <= 0) {
      sys_setLed(0);
    }
  }
}
```

Nachdem der Buffer gefüllt ist wird die Funktion app_handleModbusRequest aufgerufen die sich jetzt um diese Anfrage kümmert.

Die Funktion macht folgendes:
- Sie schaut ob die Zeichenkette einer validen Modbus Request entspricht. 
- Danach schaut die ob die Adresse mit der Adresse des µC übereinstimmt.
- Wenn diese Adresse übereinstimmt kann der µC eine Response schicken.

```c
uint8_t app_handleModbusRequest() {
  char *b = app.modbusBuffer;
  uint8_t size = app.bufferIndex;
  
  if(size < 9) return 1;
  if(b[0] != ':') return 2;
  if(b[size -1] != '\n') return 3;
  if(b[size -2] != '\r') return 4;
  if((size - 3) %2 != 0) return 5;
  for (uint8_t i = 1; i < (size -2); i++) {
    char c= b[i];
    if(!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))) return 6;
  }
  
  uint8_t lrc = 0;
  for(uint8_t i = 1;i <(size - 4); i++) {
    lrc += b[i];
  }
  lrc = (uint8_t) (-(int8_t) lrc);
  char s[3];
  snprintf(s, sizeof s, "%02X", lrc);
  if(b[size -4] != s[0] || b[size -4] != s[0]) return 7;
  
  uint8_t i, j;
  for (i = 1, j = 0; i < (size -4); i+=2, j++) {
    uint8_t hn = hex2int(b[i]);
    uint8_t ln = hex2int(b[i+1]);
    if(hn == 0xff || ln == 0xff) {
      return 8;
    }
    uint8_t value = hn *16+ln;
    b[j] = value;
  }
  size = j;
  
  uint8_t deviceAddress = b[0];
  if(deviceAddress != 1) return 0;
  
  uint8_t funcCode = b[1];
  switch(funcCode) {
  case 0x04: {
      uint16_t startAddress = b[2] << 8 | b[3];
      uint16_t quantity = b[4] << 8 | b[5];
      if(quantity < 1 || quantity > 0x7d) {
        b[1] = 0x80 | b[1]; //Error
        b[2] = 0x03; // quantity aou of range
        size = 3;
      } else if(startAddress != 1 || quantity != 1) {
        b[1] = 0x80 | b[1]; //Error
        b[2] = 0x02; //wrong start adress
        size = 3;
      } else {
        b[2] = 2;
        b[3] = app.mbInputReg01 >> 8;
        b[4] = app.mbInputReg01 &0xff;
        size = 5;
      }
      
      break;
  }
  default: {
    b[1] = 0x80 | b[1]; //Error
    b[2] = 0x01; //function code not supported
    size = 3;
  }
  }
  
  lrc= 0;
  printf(":");
  for(i = 0; i<size; i++) {
    printf("%02X", (uint8_t)b[i]);
    lrc += b[i];
  }
  lrc = (uint8_t)(-(int8_t)lrc);
  printf("%02X", lrc);
  printf("\r\n");
  
  return 0;
}
```
