# Protokoll ![](https://www.koerbler.com/neuigkeiten/wp-content/uploads/2013/03/htl-kaindorf.jpg)  

**von Anna Murko**  

Datum: 21.05.2019  

Gruppe: 2  

Betreuer: Professor Steiner  

abwesend: -  

  

Thema: **Modbus, RS458, Übung Temperatursensor** 

 

#Inhalt
1. [Modebus]()
1. [RS485]()
  1. [Wellenwiderstand]()
1. [Temperatursensor]()
  1. [Konfiguration des ADC]()
  1. [Auslesen des Temperatursensors]()
  1. [Kalibrieren des ADC]()
  
 
 ## Modebus
 Das offen zugänglich Kommunikationsprotokoll Modbus wurde 1979 von Gould-Modicon ins Leben gerufen. Die Anwendungsgebiete sind die Hausautomatisierung und die Industrie. Es basiert auf dem **Server/Client** Prinzip. 

In unserem Fall stellt das SURE-Board den Server und der PC den Client dar. Am folgenden Bild lässt sich das gut erkennen:

![Server/Client Prinzip bei Modbus](https://github.com/HTLMechatronics/m14-la1-sx/blob/rufflm14/rufflm14/ModbusServerClient.png)

**Es gibt 3 Arten der Datenübertragung:**

* Modbus ASCII - Die Daten werden textuell und byteweise übertragen. Frames beginnen mit einem Doppelpunkt
* Modbus RTU - Die Daten werden byteweise übertragen (= Remote Terminal Unit)
* Modbus TCP - Die Daten werden in TCP-Paketen übertragen. 

 
 ## RS485
- einfach  
- skalierbar mit µC betreibbar  
- 2 Busleitungen  
- bis zu 32 Teilnehmer  

### Wellenwiderstand
Das elektrische Feld breitet sich in den Leitungen mit Lichtgeschwindigkeit aus, dadurch schwappen Elektronen am Ende der Leitung wieder zurück. Mit einem Wellenwiderstand kann man dies verhindern.


## Temperatursensor  
  
### Konfiguration des ADC

Folgende Bits müssen gesetzt werden:

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

Die Dokumentation der Register kann man sich im Datenblatt ansehenn.

**ADMUX:**

Das Register **MUX** legt fest, welcher Sensor verwendet werden soll.

Das Register **REFS** legt fest, welche Referenzspannung der ADC
verwenden soll. 

Das Register **ADLAR** left fest, ob das Messergebniss im Datenregister
links oder rechts ausgerichtet abgelegt werden soll. 

**ADCSRA:**

Das Register **ADEN** aktiviert den ADC.

Das Register **ADPS** legt den sogenannten Prescaler des ADCs fest.


### Auslesen des Temperatursensors

**Vin** wird mit einer Referenzspannung **Vref** verglichen und dann im ADC Register abgelegt.
Da wir bei der Konfiguration des ADC die Bandgap Spannung ausgewählt haben hat Vref 1.1V.
  
`ADC = (Vin * 1024) / Vref`

Nach der Konvertierung befindet sich das Ergebnis im 16 bit ADC Register (ADCL + ADCH).

`ADCH = Vin * (256 / Vref)`

|    Temperatur   |    Strom    |    ADCH    |
|:-----------:|:-----------:|:-----------:|
| -45°C | 242mV | 56.32 |
|25°C | 314mV | 73.08 |
|85°C |380mV | 88.44 |

**Gradient**: (88 - 56) / (85 - (-45)) = 0.24338 pro °C


### Kalibrieren des ADC

Da das Programm einen falschen Wert ausgibt, ist eine Kalibrierung erforderlich.

Die einfachste Art der Kalibrierung besteht darin eine **lineare Funktion** (2 Parameter, Offset und Steigung) auf die Ausgangswerte anzuwenden.

**y = kx + d**
**Temperatur in °C = k * ADCH + d**

Gemessene Werte für die lineare Funktion:

|    Temperatur   |    Gemessener Wert    |    Wert der Funktion     |
|:-----------:|:-----------:|:-----------:|
| -45°C | 75 | -11520 |
|25°C | 92 | 6400 |
|85°C |107 | 21760 |


Mit diesen Werten kann man sich die Regressionsgerade berechnen:

gemittelte Werte:

k = 1040
d = -96000

  
