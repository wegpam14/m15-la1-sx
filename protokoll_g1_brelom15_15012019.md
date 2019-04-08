# Protokoll 5 (15.1.2019)
Name: Lorenz Breitenthaler  
KNr.: 1  
Klasse: 4ahme  
Gruppe: 1  
- - - -
## Übersicht
1. Bus-Systeme
	1. Allgemein
	2. Modbus
2. Übung: Temperaturauswertung eines Sensors Mittels Modus
	1. Definition der Request
	2. Definition der Response

- - - -

## 1. Bus-Systeme
### 1.1 Allgemein
Ein Bus-System besteht aus mehreren Leitern, welche genützt werden um Daten zwischen mehreren Geräten in einer Master/Slave Beziehung in Echtzeit auszutauschen.  Hierbei sind die meisten Systeme eine Ableitung von Ethernet.

**Im Industriebereich** —> Powerlink, Profinet  
**Im Automotivbereich** —> LIN, CAN, Flexray  
**In der Hausautomatisierung** —>  KNX, Modbus, Homeatic, CAN  

Oft wird auch von _Proprietäre Schnittstellen_ gesprochen. 
Darunter versteht man  selbst entwickelte Bus-Systeme.  

**Vorteile:**
* Geringer Aufwand
* Funktioniert für die Anwendung nach wünschen des Anwenders
* Kann nur das was es soll und macht es somit übersichtlicher

### 1.2 Modbus

In unserer Übung haben wir uns für Modbus entschieden da es ein offenes System ist.  

Das **Modbus Daten-Modell** unterscheidet vier Tabellen (Adressräume) für: 

**Discrete Inputs**  
	Ein _Discrete Input_ ist ein einzelnes Bit, das nur gelesen werden kann.
	Beispiele: ein Taster, ein Endschalter, …  
  
**Coils**  
	Eine _Coil_ ist ein Bit das gelesen und beschrieben werden kann.  
	Der 	Name stammt vermutlich von der Spule eines Relais.  
	Beispiele: ein Relais, eine LED, … 
  
 **Input Registers**  
	Ein _Input-Register_ ist ein 16-Bit Wert der nur gelesen werden kann.  
	Beispiele: ein Temperatursensor, ein ADC, die Geräte-ID, …  
  
**Hold-Registers**  
	Ein _Hold-Register_ ist ein 16-Bit Wert der gelesen und beschrieben werden kann.  
	Beispiele: PWM-Einheit, DAC, …  

In unserem Beispiel wurde das **Input Register** Mit dem Function Code 4 (Lesen) gewählt.  

## 2. Übung: Temperaturauswertung eines Sensors Mittels Modus

Ziel dieser Übung ist es, den Temperatursensor des Arduino Nanos auszulesen, und die Ergebnisse über Modbus zu einem Client zu Übertragen. 

### 2.1 Definition der Request

Damit der Server eine Antwort sendet muss dieser eine Request (Anfrage) empfangen. Für die Request arbeiten wir mit dem **ASCII Transmission Mode**, bei welchem die Bytes als ASCII-Text versendet werden. 

**Request:**

|  Start | Address  | Funktion |    Daten  |  LRC | END   |  
|--------|----------|----------|-----------|------|-------|  
|   „:“  |  10      |  04      | 0001 0001 | 0xB9 | 13 10 |

**Startbyte:** 
Um dem Server_Client zu signalisieren, dass eine neue Request_Response  Eintrifft. 

**Addresse:**
Damit der Server und der Client die Request zuordnen können. 

**Funktions Code:** 
Gibt an was mit dem Request gemacht werden soll. In unserem fall „4“ (Lesen).

**Daten:**
Enthält die Nummer des Registers _(16)_- da die Register beim Modbus bei 1 beginnen, muss dieser Wert um 1 erhöht werden. 

**LCR:**
Das LCR wird aus der Summe der Bytes die nach dem : folgen zusammengezählt. und anschließend mit -1 multipliziert. 
Bei unserer Request ergibt dies den Wert „B9“.

**Ende:**
Damit der Server_Client weiß wann eine Request_Response fertig ist, wird am ende das Carriage return (13) und dem Line feed (10) gesendet.

### 2.2 Deffinition der Response
Nach dem empfangen der Response sendet der Server eine Response(Antwort) mit dem Temperaturwert. 


|  Start | Address  | Funktion |   Daten  |  LAC | END   |  
|--------|----------|----------|----------|------|-------|  
|   „:“  |  10      |    04    |   ...    |  ... | 13 10 |


**Startbyte:** 
Um dem Server_Client zu signalisieren, dass eine neue Request_Response  Eintrifft. 

**Addresse:**
Damit der Server und der Client die Request zuordnen können. 

**Funktions Code:** 
Gibt an was mit dem Request gemacht werden soll. In unserem fall „4“ (Lesen).

**Quantität**
Gibt an wie viele Datenbytes zurückgesendet werden, beziehungsweise wie viele Bytes die Response enthält. 

**Daten:**
Es stehen 16 Bit zur verfügung um den Temperaturwert zu senden. Um diese optimal zu nutzen repräsentieren die ersten 8 Bit Ganze zahlen und die Letzten 8 Bit die Kommerzahl. Somit ist ein Wertbereich von 127.996 °C bis -128.0 °C möglich. 

**LAC:**
Das LAC wird aus der Summe der Bytes die nach dem : folgen zusammengezählt. und anschließend mit -1 multipliziert. 
Es kann erst beim versenden der Daten berechnet werden.

**Ende:**
Damit der Server_Client weiß wann eine Request_Response fertig ist, wird am ende das Carriage return (13) und dem Line feed (10) gesendet.
