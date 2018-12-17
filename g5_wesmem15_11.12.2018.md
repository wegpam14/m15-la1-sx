# Protokoll 4

**Mercedes Wesonig  
11.12.2018  
  Gruppe 3**

## Übersicht
[1] Makefile Wiederholung  
[2] Datenübertragung - Allgemein  
[3] Datenübertragung - Arten  
[4] Echtzeitfähig - Was heißt das?  
[5] Feldbus  
[6] Modbus  
[7] Modbus - Anfrage  
[8] Modbus - Funktionscode  


### [1] Makefile Wiederholung

Aufgrund von einigen Unklarheiten besprachen wir in dieser Einheit das Funktionsprinzip von Makefile nochmal durch. Makefile dient dazu, den Übersetzungsvorgang zu steuern. Bei Netbeans beispielsweiße ist eine Makefiel bereits vorhanden. Zunächst besprachen wir das Beispiel von der Letzten Einheit. 

```
ue04.elf: main.o monitor.o lcd.o
	gcc -o ue04.elf main.o monitor.o lcd.o  

main.o: main.c monitor.h lcd.h
	gcc -c main.c
        
monitor.o: monitor.c lcd.h
	gcc -c monitor.c
        
lcd.o: lcd.c
	gcc -c lcd.c
        
clean: 
	rm *.o
```

**Bedeutung:**

Die erste Zeile (zb. ue04.elf: main.o monitor.o lcd.o oder main.o: main.c monitor.h lcd.h) ist das Ziel, welches Kompiliert werden soll bzw Dateien welche zum kompilieren benötigt werden.
Die Zweite Zeile welche mit einem Tabulator eingerückt wird (zb. gcc -o ue04.elf main.o monitor.o lcd.o oder gcc -c main.c) ist ein Befehl. Wenn alle auf dem neuesten Stand sind, wird gelinkt. Der Rest der Befehle warten auf den Zeitstempel, welcher aussagt ob die Dateien auf dem neuesten Stand sind oder nicht und werden dementsprechend kompiliert oder auch nicht.
Der letzte Befehl, clean, ist dafür verantwortlich den Bildschirm zu löschen (Konsolenbefehl rm *.o).
Mit ``@ (mute)``  blendet man überschüssige Konsolenbefehle aus.

### [2] Datenübertragung - Allgemein

**Was ist Datenübertragung?**

In Computern finden laufend (digitale) Datenübertragungen statt, zum Beispiel von der Festplatte in den Arbeitsspeicher. Die ersten Versuche Computer zwecks Datenaustausch zu verbinden gibt es seit geraumer Zeit. Zu Anfang waren dies häufig direkte Verbindungen ähnlich der heutigen seriellen Schnittstelle oder der parallelen Schnittstelle  mit speziellen Link-Programmen. Später erfolgte die Datenübertragung über Telefonleitungen mit Akustikkoppler oder Modems und einfachen Protokollen wie XMODEM, YMODEM, ZMODEM oder Sealink-Protokoll. Diese wurden später durch bidirektional arbeitende Protokolle wie Hydraoder Janus ergänzt, welche die gleichzeitige Übertragung von Dateien in beide Richtungen ermöglichen. Dabei wurden im Wesentlichen nur Daten im Sinne von Dateien übertragen. Eine erste Vernetzung erfolgte über Mailboxen. Datenübertragung ist heute in der Regel netzwerkbasiert. Dabei wird fast immer das Internetprotokoll verwendet, auch wenn dieses bei Modem-Verbindungen in den Protokollen der niederen Übertragungsschichten (vgl. OSI-Modell) verpackt wird. Geht die Datenübertragung über ein eigenes Netzwerk hinaus und erfolgt die Verbindung mit einem anderen Netzwerk nur zeitweise und verwendet man es hauptsächlich zur Dateiübertragung, so spricht man oft von einer Datenfernübertragung.

### [3] Datenübertragung Arten

Im Unterricht sprachen wir folgende Möglichkeiten durch:

**USB-Verbindung:**

![Bild](https://github.com/HTLMechatronics/m15-la1-sx/blob/wesmem15/USB.png?raw=true)

* Billig
* Einfach
* Oft verwendet

**Allgemein:**

Der Universal Serial Bus (USB) ist ein serielles Bussystem zur Verbindung eines Computers  mit externen Geräten. Mit USB ausgestattete Geräte oder Speichermedien, wie etwa USB-Speichersticks, können im laufenden Betrieb miteinander verbunden (Hot Plugging) und angeschlossene Geräte sowie deren Eigenschaften automatisch erkannt werden. Vor der Einführung von USB gab es eine Vielzahl verschiedener Schnittstellentypen mit unterschiedlichsten Steckern zum Anschluss von Zubehör und Peripheriegeräten an Heim- und Personal Computer. Fast alle diese Schnittstellenvarianten wurden durch USB ersetzt, was für die Anwender Vereinfachungen mit sich brachte, die jedoch durch die Vielzahl an unterschiedlichen USB-Steckern und -Buchsen wieder teilweise relativiert wurden. USB wurde 1996 mit einer maximalen Datenrate von 12 Mbit/s als USB 1.0 eingeführt. Im Jahr 2000 ist Version USB 2.0 spezifiziert worden, mit 480 Mbit/s die heute noch meistverbreitete Version. Bei dem 2014 eingeführten Standard USB 3.1 Gen 2 beträgt die maximale Brutto- Datentransferrate  für SuperSpeed+ 10 Gbit/s.  2017 wurde USB 3.2 mit einer Übertragungsrate von bis zu 20 GBit/s spezifiziert.

**RS232-Verbingung:**

![Bild](https://github.com/HTLMechatronics/m15-la1-sx/blob/wesmem15/RS232.png?raw=true)

* Veraltet 

**Allgemein:**

Serielle Schnittstellen dienen zum physischen Austausch von Daten zwischen Computer und Peripheriegeräten. Die Datenbits werden hierbei nacheinander (also seriell) übertragen.  Die RS-232-Schnittstelle (oft auch COM-Schnittstelle oder V.24 genannt) wurde in den 1960er Jahren hauptsächlich für Einsatzbereiche in der Telekommunikation (z.B. Fernschreiber, später Modems) und EDV (zur Anbindung von Terminals an Mainframes) entwickelt. Die letzte Aktualisierung der Spezifikationen der RS-232-Schnittstelle erfolgte 1997.
Mit der zunehmenden Digitalisierung von elektronischen Geräten stieg auch der Bedarf diese rechnergestützt auszulesen und zu verwalten. Aufgrund der einfachen Implementierbarkeit und Zuverlässigkeit fand die  RS-232  schnell Anwendung in der allgemeinen PC-Technik und sogar in der Unterhaltungselektronik. Die  RS-232 eignet sich zum Anschluss von Kassenterminals, Druckern und Messgeräten, steuert Plasmabildschirme und man kann Firmware auf DVD-Player und Satellitenreceiver übertragen. Bis zum Erscheinen des  USB(Universal Serial Bus) war praktisch jeder PC mit mindestens einer RS-232-Schnittstelle ausgestattet.

**R8485-Verbindung und RS485 Bussystem:**

![Bild](https://github.com/HTLMechatronics/m15-la1-sx/blob/wesmem15/r8485.png?raw=true)

* Altes System
* Noch oft verwendet
* Funktionsprinzip der beiden Systeme ist sehr ähnlich

**Allgemein:**

Die Übertragung der Daten erfolgt durch einen differenziellen, seriellen Spannungspegel zwischen den Leitungen [A] und [B]. Da Daten auf den Leitungen zwischen Sender und Empfänger übertragen werden, spricht man auch von Halbduplex oder Wechselbetrieb. Jeder Empfänger oder Sender hat einen invertierten und nicht-invertierenden Anschluss. Die Übertragung der Daten erfolgt symmetrisch. Das heißt, hat eine Leitung ein „High“-Signal, hat die andere Leitung ein „Low“-Signal. Leitung A ist somit der Komplementär von B und umgekehrt. Der Vorteil der Messung der Spannungsdifferenz zwischen A und B ist, dass Gleichtaktstörungen weitestgehend keinen Einfluss haben. Eine eventuelle Gleichtaktstörung wird auf beiden Signalleitungen annähernd gleichmäßig eingekoppelt, und durch die Differenzmessung haben sie somit keinen Einfluss auf die zu übertragenden Daten. Der Sender (Driver) erzeugt eine differenzielle Ausgangsspannung von mindestens 1,5 V an 54 Ohm Last. Der Empfänger (Receiver) hat eine Empfindlichkeit +/-200 mV.

**Ethernet - Verbindung:**

![](https://github.com/HTLMechatronics/m15-la1-sx/blob/wesmem15/ethernet.png?raw=true)

* Nicht Echtzeitfähig
* WLAN nicht immer verfügbar
* Power Link sehr teuer

**Allgemein:**

Mithilfe von Ethernet können Daten zwischen verschiedenen Geräten innerhalb eines geschlossenen Netzwerks transportiert werden.
Zu diesen Ethernet-fähigen Geräten gehören unter anderem Computer, Drucker, Server, SmartTVs und externe Festplattenspeicher.
Um Daten über Ethernet zu senden oder zu empfangen, benötigen Sie ein Ethernet-Kabel. Die deckungsgleiche Bezeichnung "LAN-Kabel" wird deutlich häufiger verwendet.
Die LAN-Kabel sind mit Ihrem Router verbunden und bilden ein Heimnetzwerk. Sie können innerhalb dieses Netzwerkes auf jedes Gerät zugreifen und zum Beispiel Fotos vom Computer auf dem Fernseher anschauen.

### [4] Echtzeitfähig - Was heißt das?

Als  Echtzeitsysteme werden „Systeme zur  _unmittelbaren_  Steuerung und Abwicklung von Prozessen“  bezeichnet, die dafür an sie gestellte quantitative  Echtzeitanforderungen  erfüllen müssen. Diese kommen in diversen Technikgebieten zur Anwendung, etwa in der  Prozessleittechnik, in Motorsteuerungen, in der Satellitensystemtechnik, in Signal- und Weichenstellanlagen, in der  Robotik und in weiteren Bereichen.
Oft besteht die Anforderung darin, dass ein Ergebnis innerhalb eines vorher fest definierten Zeitintervalles garantiert berechnet ist, also vor einer bestimmten Zeitschranke vorliegt. Die Größe des Zeitintervalles spielt dabei keine Rolle: Während bei einigen Aufgaben (z. B. in der Motorsteuerung) eine Sekunde bereits zu lang sein kann, reichen für andere Probleme Stunden oder sogar Tage. Ein Echtzeitsystem muss also nicht nur ein Mess- oder Berechnungsergebnis mit dem richtigen Wert, sondern dasselbe auch noch  _rechtzeitig_  liefern. Andernfalls hat das System versagt.
In der Praxis lässt sich eine beliebig kleine Zeitschranke mangels genügend schneller Hardware nicht immer realisieren. Daher spricht man auch von „in  Echtzeit“, wenn Programme ohne spürbare Verzögerung arbeiten. Diese Definition ist jedoch sehr unsauber. Grundsätzlich falsch ist es, „Echtzeitsystem“ als Synonym für „besonders schnell“ anzusehen. Im Gegenteil, Echtzeitsysteme müssen entsprechende Leerläufe einplanen, um auch in besonders fordernden Situationen ihren Echtzeitanforderungen gerecht zu werden.

### [5] Feldbus
Ein Feldbus ist ein Bussystem, das in einer Anlage Feldgeräte wie Messfühler (Sensoren) und  Stellglieder (Aktoren) zwecks Kommunikation mit einem Automatisierungsgerät  verbindet. Wenn mehrere Kommunikationsteilnehmer ihre Nachrichten über dieselbe Leitung senden, dann muss festgelegt sein, wer (Kennung) was (Messwert, Befehl) wann (Initiative) sagt. Hierfür gibt es normierte Protokolle.

Man unterscheidet große 4 Bereiche:

* **Industrie**
	* Profibus
	* Powerliny

* **Automobile**
	* LIN (zusätzlich)
	* CAN (alt)
	* Flexray (am besten)
	
* **Gebäudetechnik**
	* KNX
	* Homemartic
	* LON
	* CAN
	* Modbus

* **Industrie 4.0**
	* Web-Dienste
	* HTTP-Protokolle
	* REST-Server
	* (Alexa)

### [6] Modbus:
Das Modbus-Protokoll wurde 1979 von Gould-Modicon für die Kommunikation mit SPS Geräten entwickelt. In der Industrie und Hausautomatisierung wird Modbus gerne verwendet, da es sich einerseits um einen offen Standard handelt, und andererseits Lösungen für RS-232-Verbindungen, RS-485-Busse und TCP/IP-Netzwerke ermöglicht.

Das Kommunikationsprotokoll ist ein einfaches zustandsloses Protokoll basierend auf einem Request/Response Prinzip. Modbus ist eigentlich ein Application-Protocol, das im OSI-Layer 7 (Application Layer) angesiedelt ist. Dadurch lassen sich Geräte mit unterschiedlichsten Verbindungstechnolgien miteinander verbinden.

Zwei Varianten sind für uns wichtig:

-   **Serielle Schnittstelle  UART,  RS-232  oder  RS-485  Bus**
-   **Netzwerk via  TCP/IP**

Man unterscheidet 3 Varianten:

* **Modbus - ASCII**
	* Rein textuelle byteweise Übertragung von Daten. Frames beginnen mit einem Doppelpunkt
* **Modbus - RTU** (Remote  Terminal  Unit)
	* Binäre byteweise Übertragung von Daten
* **Modbus - TCP**
	* Übertragung der Daten in TCP Paketen


**Adressräume der Modbus Daten-Modell:**
 
  * Einzelnes Bit, das nur gelesen werden kann:
	  * Taster 
	  * Endschalter
* Bit das gelesen und beschrieben werden kann: 
	* Relais
	* LED
* 16-Bit Wert der nur gelesen werden kann: 
	* Temperatursensor
	* ADC
	*  Geräte-ID
* 16-Bit Wert der gelesen und beschrieben werden kann:
	*  PWM-Einheit
	* DAC

### [7] Modbus - Anfrage

![Bild](https://www.picotech.com/images/uploads/library/topics/_med/modbus-frame-structure.jpg)

Beispiel für eine Anfrage:
   
*: 01 **04 0000 0001** BA<CR><LF>*

1) Der Doppelpunkt kennzeichnet den Beginn
2) Die ersten beiden Ziffern geben die Adresse des Geräts im Bus an
3) die nächsten beiden Ziffern bilden den Funktionscode
	* in diesem Fall 04 -> READ INPUT REG
4) Weitere Daten
	* 0000 -> INPUT REG Adresse (Temperatur)
	* 0001 -> Anzahl der gew. Input Regs.
5) Dahinter befindet sich die LRC (Prüfsumme)
 
 Der fett geschriebene Teil wird **PDU** genannt.
 Die gesamte Zeile nennt man **ADU**.

### [8] Modbus - Funktionscode 

Gibt den Zweck der Datenübertragung an.

![Bild](https://github.com/HTLMechatronics/m15-la1-sx/blob/wesmem15/funktionscode.PNG?raw=true)

