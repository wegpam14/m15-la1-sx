 # Protokoll der 6. Einheit (09.04.2019)
  Name: 		Hörmann
  Gegenstand: Labor
  Lehrer: SX
  Klasse: 4AHME
  Gruppe: 1
  ## Inhaltsverzeichnis

 1. Allgemeines / Aufgabenstellung
 2. Temperatursensor
 3. Registerkonfiguration
 4. Auslesung
 
 ## 1. Allgemeines / Aufgabenstellung
Ziel der Übung ist es die Werte eines Temperatursensor über einen Modbus ausgeben.![](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoestm15/hoestm15/PC-USB_UART-%C2%B5C2.svg)
	
Der Client sendet einen Request an den Server. 
Sobald der diesen erhält, sendet er eine Response zurück.

Der Request ist wie gefolgt aufgebaut:

		:01 04 00 01 00 01 B9 '\r' '\n'

'01' - Geräte Adresse
'04' - FC
'00 01' - Adresse 2 für Temperatur
'00 01' - 1. Register lesen

Die Response ist wie gefolgt aufgebaut:
		
		:01 04 02 17 80 __ '\r' '\n'
'17 80' - Temperaturwerte

## 2. Temperatur Messung
Die Messung basiert auf einem, auf dem Chip angebrachten temperatur Sensor, der zu einem ADC input gekoppelt ist.
MUX[4..0] bits imADMUX Register aktivieren diesen Sensor.
Die interne 1.1V Referenzspannung muss auch für die ADC Referenzspannungsquelle in der Temperatursensormessung ausgewählt sein.

Die Messspannung verläuft linear mit der Temperatur, wie in folgender Tabelle gezeigt wird.
 
 | Temperature / C° | -40°C | +25°C | +125°C |
 |:---------------------:|:------:|:--------:|-
 |Sensor output code | 0x010D| 0x016|0x01E0


 | Temperature / C° | -45°C | +25°C | +85°C |
 |:---------------------:|:------:|:--------:|-
 |Voltage | 242 mV| 341 mV|380 mV|
 |value ADCH | 56,79|73,08|88,4
 

## 3. Registerkonfiguration
Die notwendigen Register müssen konfiguriert werden. Die richtigen Konfigurationen finden Sie im Datenblatt.
[Datenblatt ATmega 328P](http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf)
Hinweise zur Temperaturmessung finden sie ab Kapitel 23.8 auf Seite 215.

Das Bit ADMUX muss auf 8 gesetzt werden um den Multiplexer auf den Temperatursensor zu legen.
Die beiden Bits REFS1 und REFS0 müssen auf 1 gesetzt werden um eine interne 1.1V Spannungsversorgung zu generieren. 
Das ADLAR (ADC Left Adjust Result) muss gesetzt werden, um das Ergebnis 'linksbündig' zu stellen.
Da wir eine gewünschte Abtastfrequenz von 125 kHz haben möchten, wird das ADCSRA Register noch verändert.

```C
void app_init (void) {  
  memset((void * )&app, 0, sizeof(app));  
  ADMUX = 8;     
  ADMUX |= (1 << REFS1) | (1 << REFS0);
  ADMUX |= (1 << ADLAR);  
  ADCSRA |= (1 << ADEN) | 7;   
  ADCSRB = 0;
}  
```

## 4. Auslesung

Die Daten des ADCH Registers sind noch nicht fertig formatiert, der letzte Schritt besteht darin die Werte in °C umzurechnen. Durch die Linearität von Temperatur und den ADCH Register-werten kann die Formel y = kx + d hergenommen werden. In unserem Fall sieht die Formel wie gefolgt aus: "T = ADCH * k + d".

![](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoestm15/hoestm15/Temperaturverlauf2.svg)


|ADCH    | mbInputRegister|
|--------|----------------|
|68      |	-11520	      |
|87      |	6400	        |
|102     |	21760	        |

Wenn man die Temperatur aus der vorherigen Tabelle mit 2^8 multipliziert, ergeben siech die Werte vom mbInputRegister. Somit verschieben sich ide Bits um 8 stellen und der µC kann eine einfache Division durhführen.

Aus diesen Werten ergibt sich für 'k' der Wert '1024' und für 'd' der Wert '-82688'.

Die Umsetzung in C sieht wie gefolgt aus: 

```C
void app_main (void) {
   ADCSRA |= (1 << ADSC);
   _delay_ms(1);

   int16_t mbInputRegister;
   int32_t k = 1024;
   int32_t d = -82688;
   int32_t x = k * ADCH + d;

   if(x > 32768){
      mbInputRegister = 32768;
   } else if(x < -32768) {
      mbInputRegister = -32768;
   } else {
      mbInputRegister = (int16_t)x;
   }
   printf("ADCH --> %u    Reg 1: %d\r",ADCH, mbInputRegister);
}
```
