

 # Protokoll der 8. Einheit (07.05.2019)
  Name: Hörmann
  
  Gegenstand: Labor
  
  Lehrer: SX
  
  Klasse: 4AHME
  
  Gruppe: 1
  ## Inhaltsverzeichnis

 1.
 2.  
 3. 
 
 
## 1. Überprüfung der Request
````C
void app_handleUartByte (char c)
{
  if (c == ':')
  { //Wenn Zeichen kommt
    if (app.bufferindex > 0)
    { //Wenn im Bufferindex bereits ein ":" ist, wird der ErrorCount hochgezählt
      app.ErrorCount = app_inc16BitCount(app.ErrorCount);
    }
    app.modbusBuffer[0] = c;
    app.bufferindex = 1; //Buffer Frame wird auf 1 gesetzt
  }
  else if (app.bufferindex == 0)
  { //Wenn ein ungünstiges Zeichen hgeschickt wird ( alles außer ':')
    app.ErrorCount = app_inc16BitCount(app.ErrorCount); //ErrorCount wird erhöht / LED in funktion wird gesetzt
  }
  else if (app.bufferindex >= (sizeof (app.modbusBuffer)))
  { //Wenn zu speichernder Wert größer als Buffergröße ist
    app.ErrorCount = app_inc16BitCount(app.ErrorCount);
  }
  else
  { //Wenn alles richtig läuft
    app.modbusBuffer[app.bufferindex++] = c; //Input wird eingelesen
    if (c == '\n')
    { //Wenn Übertragung beendet wird durch '\n'
      uint8_t errorCode = app_handleModbusRequest();
      if (errorCode > 0)
      {
        //printf("Fehler %u \n \r", err
    app.modbusBuffer[app.bufferindex++] = c; //Input wird eingelesenorCode);
        app.ErrorCount = app_inc16BitCount(app.ErrorCount);
      }

      app_handleModbusRequest(); //in Funktion app_handleModbusRequest springen
      app.bufferindex = 0; //bufferindex auf  setzen
    }
  }
}
````

Wenn im Buffer bereits ein Startbyte ':' vorhanden ist, darf kein Zweites innerhalb der Request geschrieben werden, da dies sonst zu Fehlern führen könnte. Falls ein solcher Fehler auftritt, sollte in einer Funktion ein ErrorCount hochgezählt werden. 

 Das erste Byte der Request muss aus einem Kolon ':' bestehen, falls dies nicht der Fall ist muss sollte im ErrorCount hochgezählt werden. 
 
Falls mehr Zeichen in die Request geschrieben werden, als erlaubt, so soll auch der errorCount hochgezählt werden. 

Falls beim Beenden der Reqeust mit '\n' ein Fehler auftritt, so soll auch der ErrorCount hochgezählt werden. 

Wenn nach beenden des schreibens der Reqeust der ErrorCount größer als 0 ist, so soll dies ausgegeben werden.

## 2.  ErrorCount

````C
uint16_t app_inc16BitCount(uint16_t cnt) {
  sys_setLed(1); //Wenn ein Fehler auftritt, leuchtet LED 1
  return cnt == 0xffff ? cnt : cnt + 1; //Count wird hochgezählt
}
````

Zuerst muss im app.c die Funktion app_inc16BitCount erstellt werden, um den Counter hochzuzählen.

````C
struct App
{
  uint8_t flags_u8;
  char modbusBuffer[32];
  uint8_t bufferindex;
  uint16_t ErrorCount;
  uint16_t mbInputRegister;
};
````

Im app.h muss danach die varaiable ErrorCount erstellt werden

## 3. Aufleuchten der LED bei Fehler 
Um den Fehler nicht nur im Terminal zu sehen, wäre es Vorteilhaft eine LED beim eintreffen eines Fehlers zu aktivieren. Diese LED sollte aber nicht dauerhaft leuchten, da man sonst nur den ersten Fehler erkennen könnte. Um dies zu erreichen muss im 1ms Task die LED für 2 Sekunden zum leuchten gebracht werden.


## 4. Abschließen der Übertragung 

## 5. Modbus Request auf Fehler Überprüfen

## 6. LAC berechnen

## 7. Überprüfung der Ausgabe der Zeichen am Terminal

## 8. Zeichen von ':' bis 'B9' ausgeben


