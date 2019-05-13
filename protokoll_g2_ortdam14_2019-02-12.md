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
  
