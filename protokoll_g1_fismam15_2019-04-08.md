# Protokoll 6 (08.04.2019)
Name: Fischer Maximilian  
KNr.: 2  
Klasse: 4AHME  
Gruppe: 1  
___
### Übersicht

1. Theoretisches Grundgerüst
   1. Aufbau
   1. Request
   1. Response
   1. Codierung der Temperatur
1. Temperaturwert des ADC auslesen
   1. Konfiguration des ADC
   1. Auslesen des Temperatursensors
   1. Kalibrieren des ADC
   1. Quick and Dirty ausgeben
1. Lessons Learned
___

## **1** Theoretisches Grundgerüst

### **1.1** Aufbau

In unserer Übung ist der Arduino Nano der **Modbus Server**, da er die
Temperaturwerte besitzt und diese an den Client, also den PC, schickt.

### **1.2** Request Grundaufbau

|          | Startbyte |  Adresse  | Funktion  |   Daten   |    LCR    |   Ende    |
|:--------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|
| Struktur | 1 Zeichen | 2 Zeichen | 2 Zeichen | n Zeichen | 2 Zeichen | '\r' '\n' |
|  Inhalt  |     :     |    10     |    04     | 0001 0001 |    B9     |   13 10   |

### **1.3** Response Grundaufbau

Der Modbus-Server (also der Arduino Nano in unserem Fall) sendet nach
einer Request vom Client (dem PC) eine Response mit dem Temperaturwert
codiert als 16-bit Wert.

|          | Startbyte |  Adresse  | Funktion  | Quantität Bytes |   Daten   |    LCR    | Ende      |
|:--------:|:---------:|:---------:|:---------:|:---------------:|:---------:|:---------:|:----------|
| Struktur |     1 Zeichen     | 2 Zeichen | 2 Zeichen |    2 Zeichen    | n Zeichen | 2 Zeichen | '\r' '\n' |
|  Inhalt  |     :     |    10     |    04     |       02        | .... .... |    ..     | 13 10     |

### **1.4** Kodierung der Temperatur

Um den Temperaturwert vom Sever zum Client zu senden stehen uns 16 Bit
zur Verfügung. Um diese 16 Bit optimal nutzen zu können nutzen wir
folgende Kodierung: Die ersten 8 Bit stehen für den ganzzahligen
**°C-Wert** und die anderen 8 Bit für die Kommerzahl. Mit diesem Schema
sind Temperaturwerte von **127,996°C** bis **- 128.0°C** möglich.

**Schema:**

|    8 Bit    |    8 Bit    |
|:-----------:|:-----------:|
| Ganze Zahl  | Kommerzahl  |

So würde bei einer Temperatur von 23,5°C z.B. 1780 gesandt werden.

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
void app_init (void) {
  memset((void *) &app, 0, sizeof (app));

  ADMUX = 8; // Multiplexer ADC8 = Temperature (1000)
  ADMUX |= (1 << REFS0) + (1 << REFS1); // Nutzt die interne Referenzspannung VRef = 1.1V
  ADMUX |= (1 << ADLAR); // Left Adj, -> Result in ADCH

  ADCSRA = (1 << ADEN); //Enable the adc
  ADCSRA |= 7; // fADC = 125 kHz

  ADCSRB = 0; // Sicherheitshalber
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

Das Register **ADLAR** left fest, ob das Messergebniss im Datenregister
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

### **2.3** Kalibrieren des ADC

Ohne weitere konfiguration und kalibrierung hat das Programm nun folgenden Wert ausgespuckt:

ADCH = 91 (laut dem Wert hat es in unserem Raum über 100°C)

Aus diesem Grund ist eine kalibrierung erforderlich.
Die einfachste Art der Kalibrierung besteht darin eine **lineare Funktion** (also 2 Parameter, Offset und Steigung) auf die Ausgangswerte anzuwenden.

**y = kx + d**
**Temperatur in °C = k * ADCH + d**

Gemessene Werte für die lineare Funktion:

|    Temperatur   |    Gemessener Wert    |    Wert der Funktion     |
|:-----------:|:-----------:|:-----------:|
| -45°C | 75 | -11520 |
|25°C | 92 | 6400 |
|85°C |107 | 21760 |
(*diese Werte konnten nicht gemessen werden und wurden von uns angenommen)

Mit diesen Werten haben wir dann eine Kalibrierungsgerade ausgerechnet. Dabei haben wir unsere beiden Ergebnisse gemittelt um einen *genaueren* Wert zu erhalten.

k = 1054
d = -101856

k = 1024
d = -90578

Gemittelt ergeben sich dann folgende Werte für k und d:

k = 1040
d = -96000

Damit ist die finale Funktion für die Temperatur also: T() = ADCH * 1040 - 96000

### **2.3** Quick-and-dirty Ausgabe (printf)

Da wir zu diesem Zeitpunkt den Modbus noch nicht implementiert haben,
müssen wir die Temperaturwerte auf der Console ausgeben.

Dazu haben wir in die main Methode folgendes geschrieben:

```c
void app_main (void) {
  ADCSRA |= (1 << ADSC); // Start the adc
  _delay_ms(1);

  int32_t k = 1040;
  int32_t d = -96000 + 1792 + 25;
  int32_t x = ADCH * k + d;
  int16_t modbustemp;
  
  if(x > INT16_MAX){
    modbustemp = INT16_MAX;
  }else if( x < INT16_MIN){
    modbustemp = INT16_MIN;
  }else{
    modbustemp = (int16_t) x;
  }
  
  printf("ADCH=%u       %d      \r", ADCH, modbustemp);
  _delay_ms(10);
}
```

Es wird dabei abgefragt ob unser Temperaturwert **x** zwischen
**INT16_MIN** *(-32768)* und **INT16_MAX** *(32767)* liegt. Wenn der
Wert außerhalb dieser Grenze liegt wird er zu INT16_MIN oder INT16_MAX
gesetzt. Danach wird dieser mit `printf` ausgegeben.

**Endergebnis:** Am Ende der Unterrichteinheit hat die Ausgabe eines
Temperaturwertes geklappt, jedoch waren alle anderen Werte falsch und
somit nicht brauchbar. In der nächsten Einheit werden wir diesen Fehler
(hoffentlich) beheben.

## **3** Lessons learned

1. Bei Datentypen muss man in C sehr stark aufpassen. So kann sich der
   Wert `32768` in einer Rechnung anders verhalten als der Wert `0x7FFF`

2. Es ist bei komplexen Berechnungen in C besonders verstärkt auf die
   Wahl der richtigen Datentypen zu achten.
