# Protokoll ![](https://www.koerbler.com/neuigkeiten/wp-content/uploads/2013/03/htl-kaindorf.jpg)
**von Anna Murko**  
Datum: 12.02.2019  
Gruppe: 2  
Betreuer: Professor Steiner  
abwesend: -  
  
  Thema: **Temperatursensor,Feldbus**  
  

## Inhalt 

## **Realisierung**

Die grundsätzliche Struktur sieht folgendermaßen aus:

![Grundstruktur als SVG](https://github.com/HTLMechatronics/m14-la1-sx/blob/rufflm14/rufflm14/BildGrundstruktur.svg)

Der  **Temperaturensor LM75** gibt die Messdaten an das Rechenzentrum des Mikrocontrollers über I²C weiter. Während der LM75 hier als _unintelligenter_ Sensor agiert, kann das **SURE-Board** als Ganzes durchaus als _intelligenter_ Sensor bezeichnet werden. Der Mikorcontroller gibt die Messdaten über UART weiter. Die Verbindung zwischen dem SURE-Board und dem PC (MiniUSB/USB) ist in diesem Fall ein **Feldbus**.



### UART

Der UART ist eine einfache **serielle Schnittstelle**, die in Bezug auf Datenübertragungsrate, Anzahl der Stop-Bits und Even Parity/Uneven Parity konfiguriert werden kann. UART steht für **U**niversial **A**synchronous **R**eceiver **T**ransmitter. 

[Weitere Informationen zum UART](https://www.mikrocontroller.net/articles/AVR-Tutorial:_UART)


### Feldbusse


Ein Feldbus ist ein Bussystem, das in einer Anlage Sensoren und Aktoren mit einem Automatisierungsgerät verbindet. Welches Bussystem sivoll ist  hängt stark von der Anwendung ab. Folgende Feldbusse sind stark verbreitet:

* **[POWERLINK](https://de.wikipedia.org/wiki/Ethernet_Powerlink)** - basiert auf Ethernet, das für Echtzeitanwendungen erweitert wurde. Hauptsächlich für Maschinen- und Anlagenbau. 
* **[LIN](https://de.wikipedia.org/wiki/Local_Interconnect_Network)** - für wenig komplexe Anwendungen in der Automobilindustrie
* **[CAN](https://de.wikipedia.org/wiki/Controller_Area_Network)** - für mittel-komplexe Anwendungen in der Automibilindustrie
* **[Flexray](https://de.wikipedia.org/wiki/FlexRay)** - für komplexe Anwendungen in der Automobilindustrie
* **[Profibus](https://de.wikipedia.org/wiki/Profibus)**- für z.B. Roboter, Maschinenbau, Anlagenbau
* **[KNX](https://de.wikipedia.org/wiki/KNX-Standard)** - für die Gebäudeautomatisierung
* **[Modbus](https://de.wikipedia.org/wiki/Modbus)** - freier Standard für unterschiedlichste Anwendungen in der Industrie

Wir verwenden Modbus, da dies ein frei verfügbarer Standard ist und nicht zu komplex ist.

### Modbus

Das offen zugänglich Kommunikationsprotokoll Modbus wurde 1979 von Gould-Modicon ins Leben gerufen. Die Anwendungsgebiete sind die Hausautomatisierung und die Industrie. Es basiert auf dem **Server/Client** Prinzip. 

In unserem Fall stellt das SURE-Board den Server und der PC den Client dar. Am folgenden Bild lässt sich das gut erkennen:

![Server/Client Prinzip bei Modbus](https://github.com/HTLMechatronics/m14-la1-sx/blob/rufflm14/rufflm14/ModbusServerClient.png)

**Es gibt 3 Arten der Datenübertragung:**

* Modbus ASCII - Die Daten werden textuell und byteweise übertragen. Frames beginnen mit einem Doppelpunkt
* Modbus RTU - Die Daten werden byteweise übertragen (= Remote Terminal Unit)
* Modbus TCP - Die Daten werden in TCP-Paketen übertragen. Besonderheit: Paketanfang/Paketende werden durch Pausen detektiert, was in auf nicht deterministischen Betriebssystemen wie Windows schnell zu Problemen führen kann
**ASCII Transmission Mode**

Die Übertragung der Frames erfolgt hier wie bereits bekannt als ASCII-Text. Die serielle Schnittstelle wird standardmäßig 7E1 oder 7N2 konfigueriert, also nur 7 Daten-Bits! Im Bedarfsfall darf aber auch eine davon abweichende Festlegung verwendet werden.

Ein Modbus ASCII-Frame hat somit folgenden Aufbau:
![Modbus ASCII Frame](https://github.com/HTLMechatronics/m14-la1-sx/blob/rufflm14/rufflm14/ModbusASCII.png)

**Modbus Datenpaket**

Ein Modbus Datenpaket muss mindestens aus den Teilen **Function Code** und **Data** bestehen. Bei den Varianten ASCII und RTU kommen zusätzlich noch die Adresse und eine Prüfsumme dazu. Das ist bei Modbus TCP nicht notwendig, da diese Bestandteile bereits im TCP-Standard beinhaltet sind. Folgendes Bild stellt den Unterschied zwischen **ADU**(Application Data Unit) und **PTU**(Protocoll Data Unit):

![ADU/PTU Modbus](https://github.com/HTLMechatronics/m14-la1-sx/blob/rufflm14/rufflm14/ModbusADUPDU.png)

Die maximale Größe einer ADU liegt bei Modbus ASCII/RTU bei 256 Bytes und bei Modbus TCP bei 260 Bytes.

**Daten-Modell**

Beim Modbus Daten-Modell wird in vier verschiedene Adressräume unterschieden:

* Discrete Inputs (ein einzelnes Bit, welches nur gelesen werden kann) zum Beispiel: ein Taster
* Coils (ein Bit, welches gelesen und beschrieben werden kann) zum Beispiel: eine LED
* Input Registers (ein 16-Bit Wert der nur gelesen werden kann) zum Beispiel: ein Temperatursensor
* Hold-Registers (ein 16-Bit Wert der gelesen und beschrieben werden kann) zum Beispiel: die Anzeige am Sure-Board

**Function Codes**

Die  bereits oben erwähnten Function-Codes defineren ein Modbus-Frame. Für Requests sind Werte zwischen 1 und 127 zulässig. Dabei können Function Codes in den Bereichen 65-72 und 100-110 vom Benutzer selber vergeben werden. Der Großteil der restlichen Function Codes werden von der Modbus.org Community eindeutig definiert (**Public Function Codes**).
Einige wichtigte Public Function Codes sind hier zusammengefasst:

Function Code | Hex | Name | Typ
--------------- | --------- | --------- | ---
1 | 01 | Read Coils | Bit
2 | 02 | Read Discrete Inputs | Bit
3 | 03 | Read Holding Registers | 16-Bit
4 | 04 | Read Input Register | 16-Bit
5 | 05 | Write Single Coil | Bit
6 | 06 | Write Single Register | 16-Bit 
15| 0F | Write Multiple Coils |	Bit
16| 10 | Write Multiple Registers | 16-Bit

[Mehr Infos in der Spezifikation](http://www.modbus.org/docs/Modbus_Application_Protocol_V1_1b3.pdf)


