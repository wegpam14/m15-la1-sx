# Protokoll der 6.Einheit   
  
  
  
  **Name**:  *Patrick Wegl*  
  **Datum:** *18.12.2018*  
  **Uhrzeit:** *8:00-10:30*  
  **Gruppe:** *3*  
  
   
    
 **Anwesend:** Sarah Vezonik, Alois Vollmaier, Patrick Wegl, Mercedes Wesonig, Matthias Winter, Thomas Winter  
  **Abwesend:** ---  

***********************************************************************************************************************************  

 ## UART Wiederholung  
 Wie bereits in FIVU gelernt, zählten wir die wichtigsten Schritte zur UART-Übertragung auf. UART dient zum Übertragen von Daten. Es benötigt immer ein *Start Bit* und einem oder zwei *Stop Bits*. Dazwischen werden die Daten Byteweise übertragen. Nach den Daten und vor dem Stop Bit, kann es eventuell noch ein *Parity Bit* geben.    
[Wikipedia/UART](https://de.wikipedia.org/wiki/Universal_Asynchronous_Receiver_Transmitter)  

 ***********************************************************************************************************************************  

## Feldbussysteme  
  
Feldbussystem | Andwendungsgebiet | Details  
------------- | ----------------- | -----  
**Powerlink** | Industrie | setzt auf Ethernet auf, ist echtzeitfähig, häufig für SPS  
**Profibus** | Industrie | setzt auf RS485 auf  
**Modbus** | Industrie | setzt auf RS485 und TCP/IP auf   
**CAN, LIN, Flexray** | Automobilindustrie | 
**KNX** | Haustechnik |    
***********************************************************************************************************************************   
# Modbus  
Das Feldbusprotokoll Modbus wurde 1979 für die Kommunikation zwischen zwei SPS Geräten entwickelt. Heutzutage wird es gerne in der Haustechnik und in der Industrie verwendet, da es ein offenes Protokoll ist und sich Lösungen mit RS232-, RS482- und TCP/IP- Verbindungen realisieren lassen.  
  
Modbus arbeitet nach dem einfachen Prinzip **Server/Client(Request/Response)**. In unserem Fall arbeitet der PC als Client und fragt nach der Temperatur und das Sureboard arbeitet als Server, welcher die Anfragen bearbeitet und zurückübermittelt.  
![Server/Client](https://github.com/HTLMechatronics/m14-la1-sx/blob/reibem14/reibem14/modbus.png)    
## Modbus Gateway  
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
 ***********************************************************************************************************************************   

     
# Temperatursensor  
Mittels, dem am Atmega 328p verbauten Temperatursensors, soll die aktuelle Temperatur über eine Java Swing Applikation angezeigt werden.  Die eigentliche Datenübertragung zwischen den Atmega 328p und PC erfolgt mittels eines Feldbussystems, in unserem Fall MODBUS.  
   
## Intelligenter Sensor  
Ein Sensor ist nur dann intelligent, wenn er ein Rechenwerk besitzt. Das heißt nun, dass wir bei einem unintelligenten Sensor nur einen Spannungswert zurückbekommen und diesen dann selbst in den richtigen Temperaturwert umrechnen müssen. Bei einem Intelligenten Sensor passiert diese Umrechnung bereits im eigenen Rechenwerk.   
In unserem Fall ist es ein unintelligenter Sensor, jedoch in Verbindung am Atmega328p ist er intelligent.   

# Java Programm  

Durch [successive Approximation](https://en.wikipedia.org/wiki/Successive_approximation_ADC) wandelt der Analog Digital Wandler eine analoge Eingagsspannung in einen 10 Bit Digitalwert, dabei entspricht der kleinste Wert GND und der maximale Wert entspricht der ausgewählten Referenzspannung minus ein LSB.  
![enter image description here](http://www.vias.org/mikroelektronik/img/adcsukap.png)


Unser Temperatursensor hat eine Betriebsspannung von -3.0V bis 5.5V. Der Messbare Temperaturbereich geht von -55°C bis +125°C 
Die Referenzspannung für den Analog-Digital-Wandler kann durch die Bits REFS1 und REFS0 im ADMUX-Register ausgewählt werden, die Referenzspannung liegt dann auch am AVCC Pin an.

In den Registern von ADC --> ADCH & ADCL werden vom Analog-Digital-Wandler 10 bit Ergebnise erzeugt, die in diesen beiden Registern abgelegt werden.
Normalerweise wird das Ergebnis rechtsbündig in den beiden Registern abgelegt, optional kann das Ergebnis aber auch linksbündig in ADCH und ADCL geschrieben werden. Die Einstellung erfolgt mit dem ADLAR-Bit im ADMUX-Register.

Zuerst wurden diese Register des ADC’s initialisiert und der app.modbus.frameIndex auf -1 gesetzt um in einen Idle Zustand zu gehen.

Im nächsten Schritt wird der linksbündige Wert des ADCH Registers in eine Zwischenvariable gespeichert und der ADC gestartet, indem das ADCH Register gesetzt wird.

Werte der Temperatur werden als 16Bit Werte übertragen.  
Danach werden die werte in Festkommacodierung übertragen und sind dann links und rechts vom Komma 8 Bit. Um vom Temperaturwert mit z.B 23,5°C zum hex Wert zu kommen muss man den wert zuerst mit 256 Multiplizieren und danach in eine Hexadezimalzahl umwandeln 23,5 * 256 = 6016 => 1780hex

Als das Programm lauffähig war, bemerkten wir, dass falsche Werte in der Konsole ausgegeben werden, aber dies war kein großes Problem, da es sich nur um einen statischen Fehler handelte und dies konnte durch einfaches Kallibrieren behoben werden.

## app.c 
```
void app_init (void)
{
memset((void *)&app, 0, sizeof(app));

ADMUX = (1 << REFS1) | (1<< REFS0) | ( 1<< ADLAR) | 0x08;

ADCSRA = (1<< ADEN) | 7; // 7 bedeutet durch 128, dass sind 125 kHz

app.modbus.frameIndex = -1;
}




void app_task_16ms (void)
{

app.adch = ADCH;


ADCSRA |= (1<< ADSC); //Starte ADC
}




void app_handleUartByte(char c){


struct Modbus *p = &app.modbus;

if (p ->frameIndex < 0)

{
return;
}


if( c == ':')
{

p ->frameIndex = 0;
p->frameError = 0;

}


else if ( c == '\n'){

if (p->frameError == 0){

app_parseModbusFrame();

}
}


else if (p ->frameIndex < 16)
{

p ->frameIndex [p ->frameIndex] = c;

}


else if (p -> errCnt == 0)
{

p->frameError = 1;

if(p->errCnt < 0xffff)
{

p-> errCnt++;

}

}
}
```
## app.h 
```
app.h
struct Modbus // Struktur um alle Komponenten
{

char frame[16];

int8_t frameIndex;

uint16_t frameError;

uint16_t errCnt;

};


struct App


{


uint8_t adch;


struct Modbus modbus;

};
```
## sys.c

```
ISR (SYS_UART_RECEIVE_VECTOR)
{


static uint8_t lastChar;
uint8_t c = SYS_UDR;



if (c=='R' && lastChar=='@')

{

wdt_enable(WDTO_15MS);
wdt_reset();
while(1) {};

}
lastChar = c;
app_handleUartByte(c);
```
