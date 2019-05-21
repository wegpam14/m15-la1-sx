# Protokoll 7 #
Name: Skof Jonas  
Klasse: 4AHME  
KNR: 11  
Gruppe: 2  


| Anwesend  | Abwesend  |
|---|---|
| Korrenn,Perl,Skof,Szapacs | Murko,Orthofer  |


## Inhalt 

1. [Die RS-485 Schnittstelle](#rs485)  
2. [Modbus](#modbus)     
3. [Temperaturwert des ADC auslesen](#temp)               
    3.1. [Konfiguration des ADC](#config)                 
    3.2. [Auslesen des Temperatursensors](#auslesen)                                                                                          

## **1.** Die RS-485 Schnittstelle <a name="rs485"> </a>

**Aufbau:**
* 2 Busleitungen => Spannungsdifferenzen
* bis zu 32 Teilnehmer
* Baudrate, Datenbits, Paritybits und Stopbits

**Vorteile:**
* einfach
* hohe Kompatibilität
* geringer Energiebedarf

___

*RS-485 mit drei Teilnehmer:*
![](https://github.com/HTLMechatronics/m15-la1-sx/blob/skojom15/RS485.svg)  


![](https://github.com/HTLMechatronics/m15-la1-sx/blob/skojom15/Wellenwiderstand.png) 

**Wellenwiderstand**
Im gezeigten Bild breitet sich das elekatromagnetische Feld mit Lichtgeschwindigkeit aus.Dadurch kann es vorkommen
das die Elektronen am Ende wieder zurückschwappen.

==>Durch einen Wellenwiderstand kann die Welle auslaufen und wird durch den Widerstand in Wärme umgewandelt.

* Nur bei langen Leitungen nötig
* Bei höheren Frequenzen wie bei Ethernet nötig,aber bei UART gibt es kein Problem

___

## **2.** Modbus <a name="modbus"> </a>
**Modbus RTU**  

* binäre Übertragung von Daten 

3,5 mal eine Bitzeit = neues Paket beginnt  
1,5 mal eine Bitzeit = Paketende  

**Modbus ASCII**  

* textuelle, byteweise Übertragung von Daten 

*Kodierung* 

|0 .. 9|	A .. F	|:|	\r | \n |
|-------|---------|-|----|----|
| 48 ... 57	| 65 ... 70	| 58 | 13 | 10 |

Weitere Details siehe: [Protokoll Nr.6](https://github.com/HTLMechatronics/m15-la1-sx/blob/skojom15/protokoll_g2_skojom15_12.02.2019.md)


## **3.** Temperaturwert des ADC auslesen <a name="temp"> </a>

Bevor wir irgendwelche Werte aus dem ADC des Arduino Nanos auslesen
können müssen wir den ADC zuerst einmal konfigurieren. Alle wichtigen
Register die bei der Konfiguration zum Einsatz kommen, können in der
Dokumentation des Atmega328P nachgeschlagen werde.

### **3.1** Konfiguration des ADC <a name="config"> </a>

Um den ADC zu konfigurieren müssen einige Bits gesetzt werden. In der
unserer Übung haben wir in der `app.c` folgende Bits gesetzt.

```c
void app_main (void)
{
  ADCSRA = 7; // Prescaler 
  ADMUX |= (1 << REFS1) | (1<< REFS0); // VREF Nutzt die interne Referenzspannung VRef = 1.1V 
  ADMUX |= 8; // multiplexer Temperatur
  ADCSRA |=(1<< ADEN); // adc enable
  ADCSRA |= (1<< ADSC);  //adc start
  
  printf("%d\r",ADC);
}
```

Die Dokumentation der Register kann man sich im Datenblatt des ATmega328 ansehen.
Eine kleine Übersicht über die Funktion der Register:

**ADMUX:**

Das Register **MUX** legt fest, welchen Sensor, bzw. welchen Pin der ADC
verwenden soll. *(In unserem Fall: 1000 für den Temperatursensor)*

Das Register **REFS** legt fest, welche Referenzspannung der ADC
verwverwenden soll. *(In unserem Fall: 11 für die innere Bandgap
Spannung von 1.1V)*

Da wir in unserem Fall das ADLAR auf 1 setzten und somit das Ergebnis
links ausgerichtet wird, können wir die obsteren 8 Bits unseres 10 Bits
Arduino Nano ADCs im ADCH auslesen. Die untersten 2 Bits sind nicht zu
gebrauchen da diese 2 Bits sehr schwanken.

**ADCSRA:**

Das Register **ADEN** aktiviert den ADC.

Das Register **ADPS** legt den sogenannten Prescaler des ADCs fest. In
unserem Fall passt der Wert 128 als Prescaler sehr gut*, da der ADC so
auf **125kHz**(16MHz / 128 = 125kHz) betrieben wird.

**(der ADC sollte zwischen 50MHz und 200MHz betrieben werden, da sich in
dieser Spannweite ein optimales Messergebnis ergibt)*

### **3.2** Auslesen des Temperatursensors <a name="auslesen"> </a>

**Vin** wird mit einer Referenzspannung **Vref** verglichen und dann im ADC Register abgelegt.
Da wir bei der Konfiguration des ADC die Bandgap Spannung ausgewählt haben hat Vref 1.1V.
  
`ADC = (Vin * 1024) / Vref`

`ADC = (314mA * 1024) / 1100mA = 292mV`

`ADC = (314mA * 1024) / 1072,3mA = 300mV`

Diese Abweichungen kommen durch die Ungenauigkeit der Referenzspannung zustande.

Nach der konvertierung befindet sich das Ergebnis im 16 bit ADC Register (ADCL + ADCH).

|    Temperatur   |    Strom    |
|:-----------:|:-----------:|
| -45°C | 242mV |
|25°C | 314mV |
|85°C |380mV |
