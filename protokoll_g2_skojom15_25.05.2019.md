# Protokoll 7 #
Name: Skof Jonas  
Klasse: 4AHME  
KNR: 11  
Gruppe: 2  


| Anwesend  | Abwesend  |
|---|---|
| Korrenn,Perl,Szapacs | Murko,Orthofer  |


## Inhalt 

1. [Temperaturwert des ADC auslesen](#temperaturwert-des-adc-auslesen)                                           
 2. [Feldbus](#feldbus) 
 3. [Programm](#programm)

## **2** Temperaturwert des ADC auslesen

Bevor wir irgendwelche Werte aus dem ADC des Arduino Nanos auslesen
können müssen wir den ADC zuerst einmal konfigurieren. Alle wichtigen
Register die bei der Konfiguration zum Einsatz kommen, können in der
Dokumentation des Atmega328P nachgeschlagen werde.

**Kleiner Tipp aus dem Unterricht:**

Arduino Language ist umgangssprachlich gesprochen*dreck*. Man sollte
sich bei low-level-programmierung selber um alle Dinge kümmern und
sollte keine abstrakte Sprache verwenden.

### **2.1** Konfiguration des ADC

Um den ADC zu konfigurieren müssen einige Bits gesetzt werden. In der
unserer Übung haben wir in der `app.c` folgende Bits gesetzt.

```c
void app_main (void)
{
  ADCSRA = 7; // Prescaler
  ADMUX |= (1 << REFS1) | (1<< REFS0); // VREF 
  ADMUX |= 8; // multiplexer Temperatur
  ADCSRA |=(1<< ADEN); // adc enable
  ADCSRA |= (1<< ADSC);  //adc start
  
  printf("%d\r",ADC);
  //EEprom auslesen adresse 0,1,2,3,4,5,6,7
  //und ausgeben
  
}
```

Die Dokumentation der Register kann man sich im Datenblatt des ATmega328 ansehen. (Seite 262)
TODO: LINK
Eine kleine Übersicht über die Funktion der Register:

**ADMUX:**

Das Register **MUX** legt fest, welchen Sensor, bzw. welchen Pin der ADC
verwenden soll. *(In unserem Fall: 1000 für den Temperatursensor)*

Das Register **REFS** legt fest, welche Referenzspannung der ADC
verwverwenden soll. *(In unserem Fall: 11 für die innere Bandgap
Spannung von 1.1V)*

Das Register **ADLAR** legt fest, ob das Messergebniss im Datenregister
links oder rechts ausgerichtet abgelegt werden soll. *(In unserem Fall:
1 für links ausgerichtet)*

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

### **2.2** Auslesen des Temperatursensors

**Vin** wird mit einer Referenzspannung **Vref** verglichen und dann im ADC Register abgelegt.
Da wir bei der Konfiguration des ADC die Bandgap Spannung ausgewählt haben hat Vref 1.1V.
  
`ADC = (Vin * 1024) / Vref`

Nach der konvertierung befindet sich das Ergebnis im 16 bit ADC Register (ADCL + ADCH).

`ADCH = Vin * (256 / Vref)`

|    Temperatur   |    Strom    |    ADCH    |
|:-----------:|:-----------:|:-----------:|
| -45°C | 242mV | 56.32 |
|25°C | 314mV | 73.08 |
|85°C |380mV | 88.44 |

**Gradient**: (88 - 56) / (85 - (-45)) = 0.24338 pro °C

Wichtig:
- Ergebniswert ändert den Wert nur alle 4 Grad
- Gradgenaue Messung nicht möglich, da der Gradient zu gering ist

## **3** Programm






