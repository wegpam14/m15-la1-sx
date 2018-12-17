## Protokoll 5

Name: Sarah Vezonik  
Datum, Ort: 11. Dezember 2018, Kaindorf  
Gruppe: 3  
Anwesend: Vezonik, Vollmaier, Wegl, Wesonig, Winter M., Winter T.;  


----------
### **Inhaltsverzeichnis**   
[1] Wiederholung Makefile  
[2]Serielle Schnittstellen  
[3]Feldbusse  
[4]LRC  


----------


### [1] Wiederholung Makefile


----------


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

**Erklärung:**

	ue04.elf: main.o monitor.o lcd.o 
	
Ziel,welches Kompiliert werden soll bzw Dateien welche zum kompilieren benötigt werden

		gcc -o ue04.elf main.o monitor.o lcd.o 

Befehle, wenn alle auf dem neuesten Stand sind,wird gelinkt
der Rest der Befehle warten auf den Zeitstempel, welcher aussagt ob die Dateien auf dem neuesten Stand sind oder nicht und werden dementsprechend kompiliert oder auch nicht.

      rm *.o
Löschht alle Object Dateien

**@ (mute)**:  blendet überschüssige Konsolenbefehle aus 

Makefile dient dazu, den Übersetzungsvorgang zu steuern. Bei Netbeans beispielsweiße ist eine Makefiel bereits vorhanden. 


----------
## [2] Serielle Schnittstellen


----------


### Rs485
**Übertragung der Daten**

Die Übertragung der Daten erfolgt durch einen differenziellen, seriellen Spannungspegel zwischen den Leitungen [A] und [B]. Da Daten auf den Leitungen zwischen Sender und Empfänger übertragen werden, spricht man auch von Halbduplex oder Wechselbetrieb. Jeder Empfänger oder Sender hat einen invertierten und nicht-invertierenden Anschluss. Die Übertragung der Daten erfolgt symmetrisch. Das heißt, hat eine Leitung ein „High“-Signal, hat die andere Leitung ein „Low“-Signal. Leitung A ist somit der Komplementär von B und umgekehrt. Der Vorteil der Messung der Spannungsdifferenz zwischen A und B ist, dass Gleichtaktstörungen weitestgehend keinen Einfluss haben. Eine eventuelle Gleichtaktstörung wird auf beiden Signalleitungen annähernd gleichmäßig eingekoppelt, und durch die Differenzmessung haben sie somit keinen Einfluss auf die zu übertragenden Daten. Der Sender (Driver) erzeugt eine differenzielle Ausgangsspannung von mindestens 1,5 V an 54 Ohm Last. Der Empfänger (Receiver) hat eine Empfindlichkeit +/-200 mV.
 
 **Logischer Zustand**
 A–B < 0,25 V = Logisch 1
A–B > 0,25 V = Logisch 0

**Vorteile:**

 - günstig
 - einfach
 - man kann intelligent abfragen 

**Blockdiagramm**
![enter image description here](https://raw.githubusercontent.com/HTLMechatronics/m15-la1-sx/vezsam15/Unbenannt.png)


----------


### Ethernet 
**Erklärung:**

Ethernet ist eine Technik, die Software (Protokolle usw.) und Hardware (Kabel, Verteiler, Netzwerkkarten usw.) für kabelgebundene Datennetze spezifiziert, welche ursprünglich für lokale Datennetze (LANs) gedacht war und daher auch als LAN-Technik bezeichnet wird. Sie ermöglicht den Datenaustausch in Form von Datenframes zwischen den in einem lokalen Netz (LAN) angeschlossenen Geräten (Computer, Drucker und dergleichen). Derzeit sind Übertragungsraten von 1, 10, 100 Megabit/s (Fast Ethernet), 1000 Megabit/s (Gigabit-Ethernet), 2,5, 5, 10, 40, 50, 100, 200 und 400 Gigabit/s spezifiziert. In seiner ursprünglichen Form erstreckt sich das LAN dabei nur über ein Gebäude; Ethernet-Varianten über Glasfaser haben eine Reichweite von bis zu 70 km. 

**Blockdiagramm**
![enter image description here](https://raw.githubusercontent.com/HTLMechatronics/m15-la1-sx/vezsam15/Unbenannt4.png)


----------


### USB 
**Erklärung:**

Der Universal Serial Bus (USB)  ist ein serielles Bussystem zur Verbindung eines Computers mit externen Geräten. Mit USB ausgestattete Geräte oder Speichermedien, wie etwa USB-Speichersticks, können im laufenden Betrieb miteinander verbunden (Hot Plugging) und angeschlossene Geräte sowie deren Eigenschaften automatisch erkannt werden. Vor der Einführung von USB gab es eine Vielzahl verschiedener Schnittstellentypen mit unterschiedlichsten Steckern zum Anschluss von Zubehör und Peripheriegeräten an Heim- und Personal Computer. Fast alle diese Schnittstellenvarianten wurden durch USB ersetzt, was für die Anwender Vereinfachungen mit sich brachte, die jedoch durch die Vielzahl an unterschiedlichen USB-Steckern und -Buchsen wieder teilweise relativiert wurden. USB wurde 1996 mit einer maximalen Datenrate von 12 Mbit/s als USB 1.0 eingeführt. Im Jahr 2000 ist Version USB 2.0 spezifiziert worden, mit 480 Mbit/s die heute noch meistverbreitete Version. Bei dem 2014 eingeführten Standard USB 3.1 Gen 2 beträgt die maximale Brutto-Datentransferrate für SuperSpeed+ 10 Gbit/s.2017 wurde USB 3.2 mit einer Übertragungsrate von bis zu 20 GBit/s spezifiziert.


----------


## Rs 232

RS-232 (Recommended Standard 232) ist ein Standard für eine bei Computern häufig vorhandene serielle Schnittstelle, der in den frühen 1960er Jahren von dem US-amerikanischen Standardisierungskomitee Electronic Industries Association (EIA) erarbeitet wurde. Es wird eher selten verwendet 

![enter image description here](https://raw.githubusercontent.com/HTLMechatronics/m15-la1-sx/vezsam15/Unbenannt3.png)


----------


### [3] Feldbusse


----------


Ein Feldbus ist ein Bussystem, das in einer Anlage Feldgeräte wie Messfühler (Sensoren) und Stellglieder (Aktoren) zwecks Kommunikation mit einem Automatisierungsgerät verbindet. Wenn mehrere Kommunikationsteilnehmer ihre Nachrichten über dieselbe Leitung senden, dann muss festgelegt sein, wer (Kennung) was (Messwert, Befehl) wann (Initiative) sagt. Hierfür gibt es normierte Protokolle. 

**Industrie**  
*Profibus, Powerlink,...*  
**Automobile**  
*LIN,CAN,Flexray,..*

 - CAN ist am ältesten und wird für Motorsteuergeräte verwendet
 - LIN wird nur in der Autoindustrie verwenden, welche gut für
   Lichtmasken,Sitzheizung etc. zu verwenden sind.
 - Flexray wurde früher vor allem bei BMW eingesetzt, heute ist das der
   Standard in der Autoindustrie.

**Gebäudetechnik**  
*KNX,Homematic,LON,CAN,Modbus*    

**Industrie4.0**     
*Web Dienst, HTTP  Protokoll, REST -Server*  


----------


## Modbus 

**Grundkonzept**
 Das Kommunikationsprotokoll ist ein einfaches zustandsloses Protokoll basierend auf einem Request/Response Prinzip.

Modbus ist eigentlich ein Application-Protocol, das im OSI-Layer 7 (Application Layer) angesiedelt ist. Dadurch lassen sich Geräte mit unterschiedlichsten Verbindungstechnolgien miteinander verbinden.

 Bei der eigentlichen Datenübertragung werden drei Varianten unterschieden:

 - **Modbus ASCII**
    *Rein textuelle byteweise Übertragung von Daten. Frames beginnen mit einem Doppelpunkt.*   
 - **Modbus RTU (Remote Terminal Unit)**
    *Binäre byteweise Übertragung von Daten.*
 - **Modbus TCP**
    *Übertragung der Daten in TCP Paketen*


**Modbus-Gateway, ADU/PDU**

![enter image description here](https://www.sma.de/fileadmin/content/global/Partner/Images/partner/sma_developer/modbus-request-response-tcp-ip.png)

 Die maximale Größe einer ADU ist:

 - 256 Bytes bei RS-232/RS-485
 - 260 Bytes bei TCP-Modbus
### Datenmodell
 Das Modbus Daten-Modell unterscheidet vier Tabellen (Adressräume) für:

 **Discrete Inputs**
    Ein Discrete Input ist ein einzelnes Bit, das nur gelesen werden kann.
    Beispiele: ein Taster, ein Endschalter, ...
    **Coils**
    Eine Coil ist ein Bit das gelesen und beschrieben werden kann.
    Der Name stammt vermutlich von der Spule eines Relais.
    Beispiele: ein Relais, eine LED, ...
    **Input Registers**
    Ein Input-Register ist ein 16-Bit Wert der nur gelesen werden kann.
    Beispiele: ein Temperatursensor, ein ADC, die Geräte-ID, ...
    **Hold-Registers**
    Ein Hold-Register ist ein 16-Bit Wert der gelesen und beschrieben werden kann.
    Beispiele: PWM-Einheit, DAC, ...
    


----------


### [4] LRC


----------


Longitudinal Redundancy Check (LRC)

Am Ende des Frame wird ein 8-Bit LRC (ein Byte als Hexstring = 2 ASCII Zeichen) gesendet.

Dazu werden alle Bytes des Frames exklusive dem Start ':' und dem Ende (CR + LF) mit 8-Bit Additionen ohne Berücksichtigung des Überlaufs zusammenaddiert und am Ende einem Zweierkomplement unterzogen.

Beispiel: Read Coils (Coil-Address 11, Quantity=8) von Device #4


    :0401000A000868<CR><LF>

Übertragen werden folgende Bytes:

    0x3a 0x30 0x34 0x30 0x31 0x30 x030 0x30 0x41 0x30 0x30 0x30 0x38 0x36 0x38 0x0d 0x0a

Die Summe aller  Bytes als 8-Bit Addition ohne  Berücksichtigung des Überlaufs ergibt: 0x98

Das Zweierkomplement ergibt: 0xff-0x98+1 = 0x68

**Error**:

Error code | 1 Byte | 0x84  
Exception code  | 1Byte | 01 or 02 or 03 or 04



