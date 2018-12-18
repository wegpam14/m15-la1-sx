

# Protokoll Nr. 05  ![](https://upload.wikimedia.org/wikipedia/commons/thumb/3/30/HTL_Kaindorf_Logo.svg/300px-HTL_Kaindorf_Logo.svg.png) 
Übungsdatum: **11.12.2018**  
Name: Vollmaier Alois  
KNr.: 14 Klasse: 4AHME  
Gruppe: 3  

Anwesenheit:  

| Anwesend | Abwesend|
| ------------- |:-------------:|
| Vezonik, Vollmaier, Wesonig, Wegl, WinterM., WinterT.    | ---- |

___
### Themen-Übersicht
 - **[1]**-Serielle Schnittstellen
	 - [1.1] - *USB* 
	 - [1.2] - *RS232* 
	 - [1.3] - *Ethernet* 
	 - [1.3] -*RS485* 
 - **[2]** - Serielle Schnittstelle Feldbus [SPS]
	 - [2.1] - *Grundlagen* 
 - **[3]** - Modbus
	 - [3.1] - *Wie funktioniert Modbus?* 
	 - [3.2] - *Modbus - ASCII* 
	 - [3.3] - *Modbus - TCP* 
	 - [3.4] - *Modbus - RTU* 

## [1] Serielle Schnittstellen
### [1.1] - **USB** 
Der USB (**U**niversal  **S**erial  **B**us) ist ein serielles Bussystem zur Verbindung eines Computers mit externen Geräten, zum Beispiel Speichermedien oder µC-Boards.
Mit USB ausgestattete Geräte können im laufenden Betrieb miteinander verbunden werden. Die Eigenschaften der angeschlossenen Geräte werden automatisch erkannt.
Der USB ist nur im logischen, nicht aber im physischen Sinne ein Bussystem. Jede Verbindung ist eine Punkt zu Punkt Verbindung.

![enter image description here](https://lh3.googleusercontent.com/YS9nJb-RJGYLwt30isDuG8QPVTOz0nhTxYYGF2uLypMNcaOUENMr7JR_NsoUkrI26Bu5eNlty_6_)
### [1.2] - **RS232** 
Die RS-232 Schnittstelle (RS = Recommended Standard, EIA-232, EIA = Electronic Industries Alliance) existiert seit 1960, war lange Zeit die am häufigsten eingesetzte serielle Schnittstelle (zum Beispiel beim PC).

Sie wurde durch USB abgelöst und ist heute nur mehr in Ausnahmefällen zu finden.

Eigenschaften der RS-232 Schnittstelle sind:
-   Übertragung von Wörtern (7 Bit, 8 Bit = 1 Byte, 9 Bit)
-   Spannungsschnittstelle (-15V bis +15V)
-   9- und 25-polige D-Sub Stecker (als Stecker oder Buchse)
-   Software- und Hardware-Handshake zur Datenflusssteuerung möglich


![enter image description here](https://lh3.googleusercontent.com/qWws_SXxD20g61MxubX6-vKKs2GNlVQZJzKB-5j2Wx7V77gIILYhLi5waEwOVJgXNehJ4YrxyuPC)

### [1.3] - **RS485** 
Bei der RS-422/RS-485 Schnittstelle wird durch eine echte differentielle Übertragungstechnik hinsichtlich Fehlerrate ein besseres Ergebnis als bei der RS-232 erzielt, trotz geringerer Spannungspegel.

Die RS-422/RS-485 Schnittstelle ist durch die folgenden Eigenschaften gekennzeichnet:

-   Voll differentielle Übertragungstechnik mit Signalpegeln ±6V
-   Die Übertragung funktioniert auch mit den Signalpegeln 0V und 5V
-   Es werden zwei Leitungen A (nicht invertiertes Signal) und B (invertiertes Signal) für den Datentransfer verwendet
-   Die maximale Datenübertragungsrate beträgt 10MBit/s (bei max. 12m Länge)
-   Die maximale Buslänge beträgt 1200m (bei maximal 90kBit/s)
-   Bei höherer Übertragungsgeschwindigkeit ist am Ende der Leitung ein Abschlusswiderstand (120Ω) erforderlich. Eine Stichleitung zu einem einzelnen Teilnehmer darf maximal 5m lang sein

Die RS-422 ist für den Datenaustausch zwischen einem Sender und maximal 10 Empfängern konzipiert (unidirektionale Verbindung).

![enter image description here](https://lh3.googleusercontent.com/h3FqCm3mGWy4NN22-do4YYMhz-5VK29IX6jXfgvoJ9DBlT-gBn_soL82BPzoUnMgkyeQ5RS1Oaiz)

## [2] Serielle Schnittstelle Feldbus [SPS]
### [2.1] - **Grundlagen** 
Ein Feldbus ist ein **Bussystem**, das in einer Anlage Feldgeräte wie Messfühler (Sensoren) und Stellglieder (Aktoren) zwecks Kommunikation mit einem Automatisierungsgerät verbindet. Wenn mehrere Kommunikationsteilnehmer ihre Nachrichten über dieselbe Leitung senden, dann muss festgelegt sein, wer (Kennung) was (Messwert, Befehl) wann (Initiative) sagt. Hierfür gibt es normierte Protokolle. Oft wird es im Zusammenhang mit einer **SPS** verwendet.

Man unterscheidet große 4 Bereiche:

 1.   **Industrie**
 -  Netbus (Profibus)
 - Powerlink  
 3.   **Automotiv**
   - LIN 
   - CAN 
   - Flexray
 4.   **Gebäudetechnik**
   - KNX
   - Homemartic
   - LON
   - CAN
   - **Modbus**
 5.   **Industrie 4.0**
   - Web-Dienste
   - HTTP-Protokolle
   - REST-Server
   - (KI Systeme (z.B Alexa))
### Automotive Schnittstellen näher erklärt:
### LIN
Der LIN-Bus (**L**ocal **I**nterconnect **N**etwork) wurde entwickelt, um die **Kosten der Vernetzung im Automobil** weiter **zu senken**. Er soll die vorhandenen und bewährten Bussysteme ergänzen und überall dort zum Einsatz kommen, wo lediglich geringe Datenmengen zuverlässig übertragen werden müssen.

![enter image description here](http://www.schleissheimer.de/caneasyhilfe/master_slave.png)

___
### CAN
Der CAN-Bus (**C**ontroller **A**rea **N**etwork) ist ein asynchrones, lineares Bussystem für die elektronische Vernetzung der Steuergeräte (sowie Aktuatoren und Sensoren) in **Automobilen**. Teilweise kommt es auch in anderen Bereichen, wie z. B. der Haustechnik zum Einsatz. Gründe für die Entwicklung des CAN-Busses waren u. a. die **relativ niedrigen Kosten,** **die Fähigkeit auch in schwierigen elektrischen Umgebungen zu funktionieren** sowie die **Echtzeit-Fähigkeiten**.
___
### Flexray

FlexRay **Flex**ibilität und Eleganz eines Rochen (**Ray**) ist im Prinzip bis zu 20 Mal schneller als CAN-Bus, aber das ist nicht der wichtigste Unterschied. Es ist bus- aber eher noch sternförmig aufgebaut und kommt damit den Gegebenheiten der Leitungsführung im Kraftfahrzeug entgegen, wenn ein Stern z.B. alle Teilnehmer in einer der beiden vorderen Türen zusammenfasst.

## [3] Modbus
Bei Modbus handelt es sich um ein Kommunikationsprotokoll, welches den **Datenaustausch** zwischen einem **Master** und **mehreren Slaves** ermöglicht.
Das **offene Protokoll** gehört heutzutage zum **Industriestandard** für die Verbindung von Computern mit Mess- und Regelsystemen.

### [3.1] - **Wie funktioniert Modbus?** 

Die prinzipielle Funktionsweise des Protokolls ist **simpel**. Das Informationsprotokoll sorgt dafür, dass ein **Master-Gerät** (hierbei handelt es sich zumeist um einen Computer) und ein oder mehrere **Slave-Geräte** miteinander verbunden werden. So lassen sich zum Beispiel verschiedene Messgeräte durch einen Computer steuern, bzw. können Daten zurück an diesen übertragen werden. 

Die Datenübertragung funktioniert dabei über drei verschiedene Wege, **ASCII**, **RTU** und **TCP**, welche sich für **unterschiedliche Zwecke** eignen. Die Übertragungssysteme können entweder **Ethernet** sein oder die etwas ältere Variante der **seriellen** **Verbindung**.


### [3.2] - **Modbus ASCII** 
Dieser Modus zeichnet sich vor allem dadurch aus, dass er **anstatt im Binär-Code** zu übertragen, seine Daten **in ASCII sendet**, so dass sie von Menschen gelesen werden können. 

Dies ist bei dem Senden von binär verschlüsselten Codes wesentlich schwieriger zu bewerkstelligen. **Der Aufbau des Codes ist immer gleich**: 

Die Nachricht beginnt mit einem Doppelpunkt, gefolgt von der Adresse des Empfängers (in ASCII). Danach wird der auszuführende Befehl dargestellt, woraufhin die eigentliche Nachricht folgt. Diese kann in der Länge variieren. Zur Fehlerprüfung wird ein sogenannter LRC-Befehl angehängt. Jede ASCII-Nachricht endet mit den Zeichen CRLF.


|     Start     |    Adresse    |  Funktion |   Daten   |    LCR    | Ende             |
|:-------------:|:-------------:|:---------:|:---------:|:---------:|------------------|
| Zeichenanzahl | 2 Zeichen (:) | 2 Zeichen | n Zeichen | 2 Zeichen | 2 Zeichen (CRLF) |
|               |               |           |           |           |                  |


**Standartmäßig werden  nur 7 Daten-Bits verwendet!  
Eine Abänderung des Übertragungsprotokolles ist immer möglich! Grund: OPEN SOURCE**


![enter image description here](https://lh3.googleusercontent.com/oXf93FG7f49IL8FFqhGlDwtn8rDdTnHm_7rXPu1lqiuQPKavAFmnJrB6MVkjN7YbfkeeeWyDDl6r=s1920)

___
### **Modbus ASCII** anhand eines Beispieles zur Datenübertragung:

> :01  04  0000  0001 __  <[CR]><[LF]>

 1. :01 Start mit Doppelpunkt & Adresse des Geräts
 2. Function Code *04* 
 3. Input Rey Adresse 1->0000
 4. Anzahl der Input Register
 5. LRC/CRC Prüfsumme
 6. <[CR]><[LF]>
		
Am Ende sollte sich durch die Übertragung über Modbus folgendes Muster bilden, welches durch ein Oszilloskop ersichtlich wird:

![enter image description here](http://www.simplymodbus.ca/images/volts.gif)

Die Daten werden als Reihe von Einsen und Nullen also Bits gesendet. Eine typische Übertragungsgeschwindigkeit beträgt **9600 Baud (Bits pro Sekunde)**

#### Wie wird die Prüfsumme(LRC) gebildet?
Anhand eines Beispieles bilden wir nun die Prüfsumme
> **:0401000A000868<CR><LF>**
> 
Übertragen werden folgende Bytes:

0x3a **0x30 0x34 0x30 0x31 0x30 x030 0x30 0x41 0x30 0x30 0x30 0x38** 0x36 0x38 0x0d 0x0a

Die Summe aller fett geschriebenen Bytes als 8-Bit Addition ohne Berücksichtigung des Überlaufs ergibt: **0x98**

**Das Zweierkomplement ergibt: 0xff-0x98+1 = 0x68**

### [3.3] - **Modbus TCP/IP** 
Dieser **Modus** ist speziell für das Ethernet gedacht. Er ist dem RTU-Modus sehr ähnlich, da auch er in binären Codes sendet, allerdings müssen bei TCP-**Modbus** **keine Kontrollbytes** berechnet werden, so dass die Handhabung und Implementierung von TCP-Treibern einfacher zu bewerkstelligen sind. 

Der Aufbau des Protokolls unterscheidet sich allerdings ein wenig vom Aufbau der RTU-Codes.

 Am Start jeder TCP-Nachricht steht die Transaktionsnummer, welche 2 Byte groß ist. Darauf folgt das Protokollzeichen. Dieses hat immer den gleichen Aufbau: 0x0000. Danach kommen die Zahl der noch folgenden Bytes sowie die Adresse und das Funktionsfeld. 

Am Ende der Nachricht stehen dann die Daten, welche immer unterschiedlich groß sind, je nach Länge der Nachricht. 

### [3.4] - **Modbus RTU** 

Der sogenannte Remote Terminal Unit Modus sendet im Gegensatz zum ASCII-Modus **binäre Codes**, welche vom Menschen nicht einfach lesbar sind. Allerdings ist der **Datendurchsatz** bei dieser Methode **weitaus besser**. 

Jeder Modbus RTU Code fängt mit einer **mindestens 3,5 Zeichen langen Pause an**, variiert jedoch mit der Übertragungsgeschwindigkeit.

Danach folgen die Adresse des Empfängers, welche in 8 Bit dargestellt wird sowie der Funktionscode, welcher ebenfalls aus 8 Bit besteht. 
Bei Fehlern kommt es zu Codeänderungen. Überprüft wird die ganze Nachricht via CRC. 
Das Ende einer jeden RTU-Nachricht wird durch eine weitere Wartezeit von **mindestens 3,5 Zeichen** gekennzeichnet. 


|    Start   | Adresse | Funktion | CR-Check |      Ende     |
|:----------:|:-------:|:--------:|:--------:|:-------------:|
| Wartezeit1 | Byte1   | Byten    | Byte2    | ByteWartezeit |
|            |         |          |          |               |

___
### Bildung des Function Codes:

Der Function-Code in einem Modbus-Frame **definiert** die **Bedeutung des Frames**.
Im Modbus-Datenmodell werden 4 Adressräume beschrieben:
-   **Discrete Inputs**  
    Ein  _Discrete Input_  ist ein einzelnes Bit, das nur gelesen werden kann.  
    Beispiele: ein Taster, ein Endschalter, ...
-   **Coils**  
    Eine  _Coil_  ist ein Bit das gelesen und beschrieben werden kann.  
    Der Name stammt vermutlich von der Spule eines Relais.  
    Beispiele: ein Relais, eine LED, ...
-   **Input Registers**  
    Ein  _Input-Register_  ist ein 16-Bit Wert der nur gelesen werden kann.  
    Beispiele: ein Temperatursensor, ein ADC, die Geräte-ID, ...
-   **Hold-Registers**  
    Ein  _Hold-Register_  ist ein 16-Bit Wert der gelesen und beschrieben werden kann.  
    Beispiele: PWM-Einheit, DAC, ...

**Nachfolgend eine Übersicht alles Function Codes:**

| Function-Code | Hex | Subcode | Name                             | Typ                |
|---------------|-----|---------|----------------------------------|--------------------|
| 1             | 01  |         | Read Coils                       | Bit                |
| 2             | 02  |         | Read Dicrete Inputs              | Bit                |
| 3             | 03  |         | Read Holding Registers           | 16-Bit             |
| 4             | 04  |         | Read Input Register              | 16-Bit             |
| 5             | 05  |         | Write Single Coil                | Bit                |
| 6             | 06  |         | Write Single Register            | 16-Bit             |
| 7             | 07  |         | Read Exception Status            | Diagnose           |
| 8             | 08  | 0-18,20 | Diagnostic                       | Diagnose           |
| 11            | 0B  |         | Get Com event counter            | Diagnose           |
| 12            | 0C  |         | Get Com Event Log                | Diagnose           |
| 15            | 0F  |         | Write Multiple Coils             | Bit                |
| 16            | 10  |         | Write Multiple Registers         | 16-Bit             |
| 17            | 11  |         | Report Server ID                 | Diagnose           |
| 20            | 14  |         | Read File record                 | File record access |
| 21            | 15  |         | Write File record                | File record access |
| 22            | 16  |         | Mask Write Register              | 16-Bit             |
| 23            | 17  |         | Read/Write Multiple Registers    | 16-Bit             |
| 24            | 18  |         | Read FIFO queue                  | 16-Bit             |
| 43            | 2B  | 14      | Read device Identification       | Diagnose           |
| 43            | 2B  | 13,14   | Encapsulated Interface Transport |                    |
| 43            | 2B  | 13      | CANopen General Reference        |                    |

*Anhand dieser Grundlagen kann im nächsten Schritt unser Temperatursensor auf dem Chip des Atmega 328P angesteuert und ausgelesen werden.
