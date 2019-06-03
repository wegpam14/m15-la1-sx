# Protokoll der 7. Einheit

 **Name**:  *Patrick Wegl*  
  **Datum:** *05.04.2019*  
  **Uhrzeit:** *8:00-10:30*  
  **Gruppe:** *3*  
  
   
    
 **Anwesend:** Alois Vollmaier, Patrick Wegl, Matthias Winter, Thomas Winter  
  **Abwesend:** Sarah Vezonik, Mercedes Wesonig  

***********************************************************************************************************************************     
 
 # Aufgabenstellung  
In dieser Einheit war es Ziel einen Modbusfähigen Temperatursensor einzurichten und diesen dann auf dem PC im Terminal ausgeben.
  
***********************************************************************************************************************************     
  
 # Temperatursensor  
Mittels, dem am Atmega 328p verbauten Temperatursensors, soll die aktuelle Temperatur über eine Java Swing Applikation angezeigt werden.  Die eigentliche Datenübertragung zwischen den Atmega 328p und PC erfolgt mittels eines Feldbussystems, in unserem Fall MODBUS.  

### Modbus  
Das Feldbusprotokoll Modbus wurde 1979 für die Kommunikation zwischen zwei SPS Geräten entwickelt. Heutzutage wird es gerne in der Haustechnik und in der Industrie verwendet, da es ein offenes Protokoll ist und sich Lösungen mit RS232-, RS482- und TCP/IP- Verbindungen realisieren lassen.  
  
Modbus arbeitet nach dem einfachen Prinzip **Server/Client(Request/Response)**. In unserem Fall arbeitet der PC als Client und fragt nach der Temperatur und das Sureboard arbeitet als Server, welcher die Anfragen bearbeitet und zurückübermittelt.  
![Server/Client](https://github.com/HTLMechatronics/m14-la1-sx/blob/reibem14/reibem14/modbus.png)    
#### Modbus Gateway  
![Modusse](https://github.com/HTLMechatronics/m14-la1-sx/blob/reibem14/reibem14/modi.PNG)  
Wie im Bild ersichtlich, gibt es zwei unterschiedliche Varianten der Pakete. Die PDU besteht immer aus *Function Code* und *Data*. Bei der ADU kommen noch zusätzlich *Adresse* und ein *Fehler-Check* hinzu. Bei Modbus TCP fällt dies weg, da Adresse und Prüfsumme schon im TCP/IP Paket enthalten sind. Die Maximalgröße der ADU-Pakte bei *RS232 / RS485 = 256 Bytes* und bei *TCP = 260 Bytes*.

Es gibt drei unterschiedliche Übertragungsvarianten:  
* **Modbus ASCII** Die Übertragung findet textuell byteweise Datenpakete statt.   
* **Modbus RTU** Hier findet die Datenübertragung binär byteweise statt.  
* **Modbus TCP** Hier werden die Daten über ein TCP Pakete übertragen.  
## Modbus-Daten-Modell  
Das Modbus-Daten-Modell unterscheidet sich in vier Bereiche:    

Name | Funktion  
---- | --------   
Discrete Inputs |  ist ein einzelnes Bit, das nur gelesen werden kann  
Coils |  ist ein Bit, das gelesen und beschrieben werden kann; Coil bedeutet soviel wie Relais  
Input Registers |  ist ein 16 Bit Wert, der nur gelesen werden kann  
Hold Registers |  ist ein 16 Bit Wert, der gelesen und beschrieben werden kann    

## Exceptions  
Tritt beim Request ein Fehler auf, so wird in der darauffolgenden Response das Bit-7 gesetzt. Dies hat die Funktion, dass sich der Function Code ändert und im Daten-Bereich wird ein Exception-Code generiert. Mithilfe dieses Exception-Codes, kann man den vorliegenden Fehler kategorisieren.  



**ADC** (ADCH & ADCL)   
Da das Ergebnis des ADC ein 10 Bit Wert ist, passt dieser Wert naturgemäß nicht in ein einzelnes Register, das ja bekanntlich nur 8 Bit breit ist. Daher wird das Ergebnis in 2 Register ADCL und ADCH abgelegt. Standardmäßig werden von den 10 Ergebnisbits die niederwertigsten 8 im Register ADCL abgelegt und die noch fehlenden 2 Bits im Register ADCH an den niederwertigsten Bitpositionen gespeichert.
```
             ADCH                                   ADCL
  +---+---+---+---+---+---+---+---+   +---+---+---+---+---+---+---+---+  
  |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
  +---+---+---+---+---+---+---+---+   +---+---+---+---+---+---+---+---+  
                            9   8       7   6   5   4   3   2   1   0  
```
Normalerweise wird das Ergebnis rechtsbündig in den beiden Registern abgelegt, optional kann das Ergebnis aber auch linksbündig in ADCH und ADCL geschrieben werden. Die Einstellung erfolgt mit dem ADLAR-Bit im ADMUX-Register.

In unserer Übung im Unterricht wurde der linksbündige Wert des ADCH Registers in eine Zwischenvariable gespeichtert und der ADC gestartet, indem das ADCH Register gesetzt wird.
 
 **Intelligenter Sensor**  
Ein Sensor ist nur dann intelligent, wenn er ein Rechenwerk besitzt. Das heißt nun, dass wir bei einem unintelligenten Sensor nur einen Spannungswert zurückbekommen und diesen dann selbst in den richtigen Temperaturwert umrechnen müssen. Bei einem Intelligenten Sensor passiert diese Umrechnung bereits im eigenen Rechenwerk.   
In unserem Fall ist es ein unintelligenter Sensor, jedoch in Verbindung am Atmega328p ist er intelligent.   
  
***********************************************************************************************************************************     
  
# Java Programm  
Unser Temperatursensor hat eine Betriebsspannung von -3.0V bis 5.5V. Der Messbare Temperaturbereich geht von -55°C bis +125°C 
Die Referenzspannung für den Analog-Digital-Wandler kann durch die Bits REFS1 und REFS0 im ADMUX-Register ausgewählt werden, die Referenzspannung liegt dann auch am AVCC Pin an.

Werte der Temperatur werden als 16Bit Werte übertragen.  
Danach werden die werte in Festkommacodierung übertragen und sind dann links und rechts vom Komma 8 Bit. Um vom Temperaturwert mit z.B 23,5°C zum hex Wert zu kommen muss man den wert zuerst mit 256 Multiplizieren und danach in eine Hexadezimalzahl umwandeln 23,5 * 256 = 6016 => 1780hex

Als das Programm lauffähig war, bemerkten wir, dass falsche Werte in der Konsole ausgegeben werden, aber dies war kein großes Problem, da es sich nur um einen statischen Fehler handelte und dies konnte durch einfaches Kallibrieren behoben werden.

## Datenanfrage
Um die Daten auszulesen wurde folgender Datenframe verwendet
```
:010400000001 _ _ <CR><LF>
```  

**Modbus ASCII Frame**  
  
:|01|04|0000|0001|_ _|<CR><LF>
  
```:``` -> Start Frame  
```01``` -> Adresse des Geräts am Bus  
```04``` -> Read Input Register  
```0000``` -> Inputregister 1 für die Temperatur  
```0001``` -> Anzahl der Gewählten Input Register  
```_ _``` -> LRC/Prüfsumme  
```<CR><LF>``` -> End-Frame   
  
**Antwort**  
Der folgende Datenframe wurde verwendet um die Antwort des Microcontrollers zum PC zu senden.
```
:010402xxxx _ _ <CR><LF>
```  





### app.c
```

void app_init (void)
{
  memset((void *)&app, 0, sizeof(app));
  ADMUX = (1<<REFS1) | (1<<REFS0) | (1<<ADLAR) | 0x08; 
  ADCSRA = (1<<ADEN) | 7; 
  app.modbus.frameIndex = -1;
}


void app_main (void)
{

  printf("-----\n\r");
  printf("  frameIndex: %d\n\r",app.modbusForPrint.frameIndex);
  printf("  frameError: %d\n\r",app.modbusForPrint.frameError);
  printf("ErrorCounter: %d\n\r",app.modbusForPrint.errorcounter);
  printf("  invalidBytes: %d\n\r",app.modbusForPrint.invalidByteCount);
  printf("------\n\r");
  for (int i=0; i <sizeof(app.modbusForPrint.frame);i++)
  {
    printf("%02x",(uint8_t)app.modbusForPrint.frame);
  }
    
    printf("\n\r");
}


void app_task_1ms (void) 
{
  app_handleUartByte();
}
void app_task_2ms (void) {}
void app_task_4ms (void) {}
void app_task_8ms (void) {}
void app_task_16ms (void) {
  app.adch=ADCH;
  ADCSRA |= (1<< ADSC); //Starte ADC
  
}
void app_task_32ms (void) {}
void app_task_64ms (void) {}
void app_task_128ms (void) {}
void app_parseModbusFrame(){
  app.modbusForPrint = app.modbus;
  sys_setEvent(APP_EVENT_MODBUS);
}
void app_handleUartByte (char c)
{
  struct Modbus *p = &app.modbus;
  
  if (p ->frameIndex <0){
    if(c==':'){
      p->frameIndex =0;
      p->frameError =0;
    } else {
      if(p -> invalidByteCount < 0xffff){
        p->invalidByteCount++;
      }
    }
    
  } else {
    if(c==':'){
      p->frameIndex=0;
      p->frameError = 0; 
      if(p->errorcounter < 0xffff)
        p->errorcounter++;
      
    } else {
    
    //in buffer speichern
    if (p->frameIndex < sizeof p->frame)
    p->frame [p->frameIndex++] = c;
    
    else {
      p-> frameError = 1;
    }
    if(c== '\n')
      app_parseModbusFrame();
      p->frameIndex = -1;
      p->frameError = 0; 
    }
  }
}
```
### app.h
```
#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

// declarations
struct Modbus
{
  char frame[16];
  uint8_t frameIndex;
  uint16_t errorcounter;
  uint8_t frameError;
  uint16_t invalidByteCount;
};
struct App
{
  uint8_t adch;
  struct Modbus modbus;
  struct Modbus modbusForPrint;
};

extern volatile struct App app;


// defines

#define APP_EVENT_MODBUS   0x01
#define APP_EVENT_1   0x02
#define APP_EVENT_2   0x04
#define APP_EVENT_3   0x08
#define APP_EVENT_4   0x10
#define APP_EVENT_5   0x20
#define APP_EVENT_6   0x40
#define APP_EVENT_7   0x80


// functions

void app_init (void);
void app_main (void);

void app_task_1ms   (void);
void app_task_2ms   (void);
void app_task_4ms   (void);
void app_task_8ms   (void);
void app_task_16ms  (void);
void app_task_32ms  (void);
void app_task_64ms  (void);
void app_task_128ms (void);

void app_handleUartByte(char c);

#endif // APP_H_INCLUDED

```
### sys.c
```
int sys_uart_getch (FILE *f)
{
  if (f != stdin)
    return _FDEV_EOF;
  if (sys.uart.wpos_u8 == sys.uart.rpos_u8)
    return _FDEV_EOF;
  uint8_t c = sys.uart.rbuffer_u8[sys.uart.rpos_u8++];
  if (sys.uart.rpos_u8>=GLOBAL_UART_RECBUFSIZE)
    sys.uart.rpos_u8 = 0;
  return (int) c;
}


int sys_uart_putch (char c, FILE *f)
{
  if (f != stdout)
    return _FDEV_EOF;
  while (!SYS_UART_UDR_IS_EMPTY);
  SYS_UDR = c;
  return (int)c;
}

  sys_sei();

Sys_Event sys_clearEvent (Sys_Event event)
{
  uint8_t eventIsPending = 0;
  sys_cli();
  if (sys.eventFlag & event)
    eventIsPending = 1;
  sys.eventFlag &= ~event;
  sys_sei();

  return eventIsPending;
}


Sys_Event sys_isEventPending (Sys_Event event)
{
  return (sys.eventFlag & event) != 0;
}
```
