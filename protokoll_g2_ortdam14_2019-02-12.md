# Protokoll  
**Datum:** 12.2.2019  
**Gruppe:** 2  
**abwesend:** -  
  
## Inhalt  
1. Intelligenter Sensor
1. UART
1. Feldbusse  
  
## Intelligenter Sensor  
Smart Sensors bzw. Intelligente Sensoren bieten die Messwertaufnahme, Signalaufbereitung und -verarbeitung. Für die verschiedenen Bussysteme wie den Modbus, CAN-Bus, CANopen oder Ethernet haben sie digitale Schnittstellen und teilweise sogar Funkmodule. Sie sind mit Mikroprozessoren ausgestattet, die nur einen geringen Leistungsverbrauch haben. Der Mikroprozessor verarbeitet die Messwerte, digitalisiert und konvertiert sie.  
[Weitere Informationen zum Intelligenten Sensor](https://de.wikipedia.org/wiki/Smart-Sensor)  
  
  
## UART
Die Abkürzung UART steht für Universal Asynchronous Receiver Transmitter. Eine UART-Schnittstelle dient zum Senden und Empfangen von Daten über eine Datenleitung und bildet den Standard der seriellen Schnittstellen an PCs und Mikrocontrollern. Auch im industriellen Bereich ist die Schnittstelle mit verschiedenen Interfaces (z. B. RS-232 oder EIA-485) sehr verbreitet.  
  
Neuere Mikrocontroller verfügen meist über einen oder zwei USARTs. USART steht für Universal Synchronous/Asynchronous Receiver Transmitter und bietet die Möglichkeit einer zusätzlichen synchronen Datenübertragung.  
  
![](https://upload.wikimedia.org/wikipedia/commons/f/f3/RS-232_timing.svg)
  
[Weitere Informationen zu UART](https://de.wikipedia.org/wiki/Universal_Asynchronous_Receiver_Transmitter)
  
  
## Feldbusse  
Feldbus ist der Oberbegriff für verschiedene physikalisch ausgeprägte Bussysteme für die Automatisierung, Fertigungstechnik, Gebäudeautomation und die Automotive-Technik. Es handelt sich um leitungsgebundene oder drahtlose Bussysteme mit denen Feldgeräte, das sind Sensoren und Aktoren, wie Antriebe, Schalter, Motoren, Stellglieder und Lampen mit den Steuerungsgeräten und Leitrechnern verbunden werden und über die der schnelle Datenaustausch zwischen den Komponenten erfolgt.  
  
**Welches Bussystem sinnvoll ist hängt von der Anwendung ab:**  

* **[POWERLINK](https://de.wikipedia.org/wiki/Ethernet_Powerlink)** - basiert auf Ethernet, das für Echtzeitanwendungen erweitert wurde. Hauptsächlich für Maschinen- und Anlagenbau. 
* **[LIN](https://de.wikipedia.org/wiki/Local_Interconnect_Network)** - für wenig komplexe Anwendungen in der Automobilindustrie
* **[CAN](https://de.wikipedia.org/wiki/Controller_Area_Network)** - für mittel-komplexe Anwendungen in der Automibilindustrie
* **[Flexray](https://de.wikipedia.org/wiki/FlexRay)** - für komplexe Anwendungen in der Automobilindustrie
* **[Profibus](https://de.wikipedia.org/wiki/Profibus)**- für z.B. Roboter, Maschinenbau, Anlagenbau
* **[KNX](https://de.wikipedia.org/wiki/KNX-Standard)** - für die Gebäudeautomatisierung
* **[Modbus](https://de.wikipedia.org/wiki/Modbus)** - freier Standard für unterschiedlichste Anwendungen in der Industrie  
  
Wir verwenden Modbus da es nicht zu komplex ist.  
  
[Weiteren Informationen zu Feldbusse](https://de.wikipedia.org/wiki/Feldbus)
  
## Modbus Arten der Datenübertragung  
* Modbus ASCII - Die Daten werden textuell und byteweise übertragen. Frames beginnen mit einem Doppelpunkt
* Modbus RTU - Die Daten werden byteweise übertragen (= Remote Terminal Unit)
* Modbus TCP - Die Daten werden in TCP-Paketen übertragen. Besonderheit: Paketanfang/Paketende werden durch Pausen detektiert, was in auf nicht deterministischen Betriebssystemen wie Windows schnell zu Problemen führen kann.  
  
## Modbus TCP  
Modbus TCP/IP ist ein Client/Server-Protokoll für den verbindungsorientierten gesicherten Austausch von Prozessdaten. Dies bietet ein hohes Maß an Flexibilität für dezentrale Automatisierungsarchitekturen: Die Rollen des Clients und der Servers sind nicht fest zugeordnet. Jedes Gerät im Netzwerk kann beide Rollen spielen. Somit können Zugriffe auf Daten – lesend oder schreibend – flexibel den jeweiligen Aufgabenstellungen angepasst werden.  
  
Der Server bearbeitet eine Anfrage des Clients – den so genannten Request – und quittiert die Anfrage mit einer Erfolgsmeldung (Response), der gegebenenfalls angefragte Daten oder Statusinformationen mitgegeben werden, bzw. mit einer Fehlermeldung, die Informationen über die Fehlerursache enthält. Die Bearbeitung dieser Anfrage läuft für den Anwender völlig transparent im Hintergrund ab. Bei üblichen Implementierungen ist kein Applikationsprogramm auf der Client-Seite erforderlich.  
  
Transaktionsnummer | Protokollkennzeichen | Zahl der noch folgenden Bytes | Adresse | Funktion | Daten
------|---------|----------|-------|----------|------
2 Byte|2 Byte (immer 0x0000)|2 Byte (n+2)|1 Byte|1 Byte|n Byte  
  
![](https://www.kynetics.com/docs/2018/images/xmasterSlave.png.pagespeed.ic.KpoegtBDIi.png)  
  
## Modbus RTU
Modbus RTU (RTU: Remote Terminal Unit) überträgt die Daten in binärer Form. Dies sorgt für einen guten Datendurchsatz, allerdings können die Daten nicht direkt vom Menschen ausgewertet werden, sondern müssen zuvor in ein lesbares Format umgesetzt werden. 
  
Start | Adresse | Funktion | Daten | CR-Check | Ende
------|---------|----------|-------|----------|------
Wartezeit (min. 3,5 Zeichen)|1 Byte|1 Byte|n Byte|2 Byte|Wartezeit (min 3,5 Zeichen) 
  
## Modbus ASCII  
Im Modbus ASCII wird keine Binärfolge, sondern ASCII-Code übertragen. Dadurch ist es direkt für den Menschen lesbar, allerdings ist der Datendurchsatz im Vergleich zu RTU geringer.  
  
Start | Adresse | Funktion | Daten | LR-Check | Ende
------|---------|----------|-------|----------|------
1 Zeichen (:)|2 Zeichen|2 Zeichen|n Zeichen|2 Zeichen|2 Zeichen (CRLF)  
  

## Function Codes
Function-Codes defineren ein Modbus-Frame. Für Requests sind Werte zwischen 1 und 127 zulässig. Dabei können Function Codes in den Bereichen 65-72 und 100-110 vom Benutzer selber vergeben werden. Der Großteil der restlichen Function Codes werden von der Modbus.org Community eindeutig definiert.  
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
  
[Weitere Informationen zu Modbus](https://de.wikipedia.org/wiki/Modbus)
  
## Modbus ASCII Beispiel  
### Request vom PC zum µC
Aufbau des Serial Line ASCII Frame:

3a|Beliebige Adresse|Function Code|Daten|LRC-Prüfsumme|CR|LF  
--|-----------------| ------------|-----|-------------|--|--  
:|0C|04|0000 0001|A8|\r|\n  
   
Bei jedem neuen Packet wird mit einem **:** begonnen.

#### Bilden der LCR Prüfsumme:
  
:|0C|04|0000 0001|Prüfsumme Ergebniss|\r|\n|
-|--|--|---------|-------------------|--|--| 
-|30H+43H|30H+34H|30H * 7  + 31H| | |Summe = 600 Dezimal| 
     
---------> 600 - 256 - 256 = 88
  
---------> -88 + 256 = 168 ---------> A8 Hex -> **LRC-Prüfsumme** 
  
### Response vom µC zum PC  
  
3a | Beliebige Adresse | Function Code | Anzahl der Bytes | Temperatur | LRC-Prüfsumme | CR |  LF | 
---|-------------------| --------------| ------|---------------|----|----|------|  
| : | 0C | 04  | 02  | 1752   | F8   |  \r  |   \n   |
