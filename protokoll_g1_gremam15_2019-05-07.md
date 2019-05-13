### 7. Protokoll  
Name: **Grebien Markus**  
Klasse: **4AHME**  
Knr: **3**

**Inhaltsverzeichnis**
1. [Das Modbusprotokoll](#Prot)
1. [Fazit](#Finally)
---

##### In dieser Übungseinheit haben wir mit der Übung vom letzten Mal weitergemacht. Für genauere Informationen klicken sie [hier](https://github.com/HTLMechatronics/m15-la1-sx/blob/gremam15/protokoll_g1_gremam15_2019-04-30.md)

### Das Modbusprotokoll <a name = "Prot"></a>
In unserem Programm müssen wir nun den Request und die Response ausprogrammieren.

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

In der `app.h` definieren wir zuerst noch zusätzlich einen Error-Zähler und den Temperaturwert, damit wir beide Werte global zur Verfügung  haben. 

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

Zuerst schauen wir, ob sich im 'char' ein Doppelpunkt befindet. Sollte es einer sein, prüfen wir,ob unser Modbusbuffer leer ist, wird der 'bufferIndex' wieder auf 1 gesetzt, weil der letzte Request unvollständig war. Dann prüfen wir auch noch, ob der 'bufferIndex' nicht den Maximalwert überschreitet, ansonsten wird der 'ErrorCounter' um 1 erhöht und die LED leuchtet für zwei Sekunden. Später genaueres.
Sollte es sich um keinen Doppelpunkt handeln, wird der wert direkt an die nächste Stelle des Ringbuffers geschrieben. Sollte dann ein '\n' kommen, wird der Request abgearbeitet und wenn kein Fehler auftritt, auch ausgegeben.


```c
uint16_t app_inc16BitCount(uint16_t cnt) {
  //sys_setLed(1);
  return cnt == 0xffff ? cnt : cnt+1;
}
```
In dieser Funktion wird einfach nur die zahl um 1 erhöht und sollte sie schon a Maximalwert sein, wird der gleiche Wert zurückgegeben. 

```c
uint8_t hex2int(char h) {
  if(h >= '0' && h<= '9') return h-'0';
  if(h >= 'A' && h<= 'F') return h-'A'+10;
  return 0xff; //Fehler
}
```
Hier wird ein `hex` wert in einen `int` wert umgewandelt.

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
Hier wird jetzt die LED für 2 Sekunden gesetzt, falls ein Fehler passiert sein sollte.

Von der nächsten Funktion zerlege ich in kleinere Teile, damit die leichter zu lesen ist.
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
```
Als ersten Schritt prüfen wir den Request nach Fehlern.
Zuerst wird geprüft, ob der Request eine akzeptable Größe aufweist.
Danach ob er mit einem Doppelpunkt beginnt und mit einem '\r\n' aufhört.
Darauf prüfen wir, ob die Anzahl an Byte stimmt und ob keine falschen Zeichen sich im Buffer befinden.

```c
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
```

Nun Überprüfen wir den LRC und konvertieren den Request auf `int`.

```c
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

Sollte der Request komplett richtig sein und auch der Function code stimmt, dann können wir auch eine Antwort schicken. Dafür nehmen wir einfach die deviceAdress und den functionCode vom Request... Dann setzten wir die startAdress und das quantity Byte. Falls eines der beiden Bytes falsch sein sollte, wird ein Fehler zurückgegeben. Ansonsten werden die Temperaturdaten in das Register geschrieben. Als letzten Schritt wird dann noch das LRC Byte berechnet und zusammen mit dem '\r\n' in den buffer geschrieben und an die SPS geschickt.


### Fazit <a name="Finally"></a>
So ein Protokoll kann Sinnvoll sein, wenn man mehrere Geräte miteinander verbindet, aber einmal das ganze Protokoll zu schreiben und damit dann am Ende auch alles funktioniert, ist sehr viel Arbeit. Darum sollte man es nur verwenden, wenn es nicht vermeidbar ist.
