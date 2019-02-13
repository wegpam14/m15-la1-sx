# Protokoll ![](https://www.koerbler.com/neuigkeiten/wp-content/uploads/2013/03/htl-kaindorf.jpg)
**von Anna Murko**  
Datum: 12.02.2019  
Gruppe: 2  
Betreuer: Professor Steiner  
abwesend: -  
  
 Thema: **Feldbus**  
  


## Inhalt 
1. [Intelligenter Sensor](https://github.com/HTLMechatronics/m15-la1-sx/blob/muranm15/protokoll_g2_muranm15_2018-02-12.md#intelligenter-sensor)     
1. [UART](https://github.com/HTLMechatronics/m15-la1-sx/blob/muranm15/protokoll_g2_muranm15_2018-02-12.md#uart)    
1. [Feldbusse](https://github.com/HTLMechatronics/m15-la1-sx/blob/muranm15/protokoll_g2_muranm15_2018-02-12.md#feldbusse)  
    1. [Modbus](https://github.com/HTLMechatronics/m15-la1-sx/blob/muranm15/protokoll_g2_muranm15_2018-02-12.md#modbus)  
    1. [Wie funktioniert ein Modbus?](https://github.com/HTLMechatronics/m15-la1-sx/blob/muranm15/protokoll_g2_muranm15_2018-02-12.md#wie-funktioniert-modbus) 
    1. [Arten der Datenübertragung](https://github.com/HTLMechatronics/m15-la1-sx/blob/muranm15/protokoll_g2_muranm15_2018-02-12.md#arten-der-daten%C3%BCbertragung)  
    1. [ASCII Transmission Mode](https://github.com/HTLMechatronics/m15-la1-sx/blob/muranm15/protokoll_g2_muranm15_2018-02-12.md#ascii-transmission-mode)
    1. [Datenpaket](https://github.com/HTLMechatronics/m15-la1-sx/blob/muranm15/protokoll_g2_muranm15_2018-02-12.md#datenpaket)
    1. [Daten-Modell](https://github.com/HTLMechatronics/m15-la1-sx/blob/muranm15/protokoll_g2_muranm15_2018-02-12.md#daten-modell)
    1. [Function Codes](https://github.com/HTLMechatronics/m15-la1-sx/blob/muranm15/protokoll_g2_muranm15_2018-02-12.md#function-codes)
    1. [Wie weiß der Modbus-Empfänger, wann beim RTU-Modus die Übertragung beendet ist?  ](https://github.com/HTLMechatronics/m15-la1-sx/blob/muranm15/protokoll_g2_muranm15_2018-02-12.md#wie-wei%C3%9F-der-modbus-empf%C3%A4nger-wann-beim-rtu-modus-die-%C3%BCbertragung-beendet-ist)
    
    

### Intelligenter Sensor
Intelligent ist der Sensor deswegen, weil er schon einen fertigen Temperaturwert zurückliefert, das heißt, er muss irgendwie einen eingebauten Prozessor haben, welcher die Werte umrechenen kann. Im Gegensatz dazu würde ein unintelligenter Sensor (zB Pt100) einfach zB eine Spannung zwischen 0 und 10 Volt zurückliefern und mann müsste sich selbst um die Auswertung kümmern.

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
![](https://github.com/HTLMechatronics/m15-la1-sx/blob/muranm15/ModbusServerClient.png)


### Wie funktioniert Modbus? 

Die prinzipielle Funktionsweise des Protokolls ist **simpel**. Das Informationsprotokoll sorgt dafür, dass ein **Master-Gerät** (hierbei handelt es sich zumeist um einen Computer) und ein oder mehrere **Slave-Geräte** miteinander verbunden werden. So lassen sich zum Beispiel verschiedene Messgeräte durch einen Computer steuern, bzw. können Daten zurück an diesen übertragen werden. 

Die Datenübertragung funktioniert dabei über drei verschiedene Wege, **ASCII**, **RTU** und **TCP**, welche sich für **unterschiedliche Zwecke** eignen. Die Übertragungssysteme können entweder **Ethernet** sein oder die etwas ältere Variante der **seriellen** **Verbindung**.



### Arten der Datenübertragung

* Modbus ASCII - Die Daten werden textuell und byteweise übertragen. Frames beginnen mit einem Doppelpunkt
* Modbus RTU - Die Daten werden byteweise übertragen (= Remote Terminal Unit)
* Modbus TCP - Die Daten werden in TCP-Paketen übertragen. Besonderheit: Paketanfang/Paketende werden durch Pausen detektiert, was in auf nicht deterministischen Betriebssystemen wie Windows schnell zu Problemen führen kann

### ASCII Transmission Mode

Die Übertragung der Frames erfolgt hier wie bereits bekannt als ASCII-Text. Die serielle Schnittstelle wird standardmäßig 7E1 oder 7N2 konfigueriert, also nur 7 Daten-Bits! Im Bedarfsfall darf aber auch eine davon abweichende Festlegung verwendet werden.

Ein Modbus ASCII-Frame hat somit folgenden Aufbau:
![](https://github.com/HTLMechatronics/m15-la1-sx/blob/muranm15/ModbusASCII.png)


### Datenpaket

Ein Modbus Datenpaket muss mindestens aus den Teilen **Function Code** und **Data** bestehen. Bei den Varianten ASCII und RTU kommen zusätzlich noch die Adresse und eine Prüfsumme dazu. Das ist bei Modbus TCP nicht notwendig, da diese Bestandteile bereits im TCP-Standard beinhaltet sind. Folgendes Bild stellt den Unterschied zwischen **ADU**(Application Data Unit) und **PTU**(Protocoll Data Unit):
![](https://github.com/HTLMechatronics/m15-la1-sx/blob/muranm15/ModbusADUPDU.png)



Die maximale Größe einer ADU liegt bei Modbus ASCII/RTU bei 256 Bytes und bei Modbus TCP bei 260 Bytes.

### Daten-Modell

Das Modbus-Daten-Modell unterscheidet vier verschiedene Bereiche:  

Name | Zweck | Beispiel
-----|-------|---------
Discrete Inputs | ein einzelnes Bit, welches nur lesbar ist | Taster am SHURE-Board
Coils | les- und beschreibbares Bit | LED oder Spule (daher der Name)
Input Registers | lesbares Register (16-Bit-Wert) | ADC, Temperatursensor
Hold-Registers | les- und beschreibbares Register (16-Bit) | DAC, Pulsweitenmodulatormodul  
  

### Function Codes

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


### Wie weiß der Modbus-Empfänger, wann beim RTU-Modus die Übertragung beendet ist?  
Da der RTU-Modus die Daten bitweise überträgt, kann man nicht so einfach feststellen, wann eine Übertragung beendet ist. Daher wurde festgelegt, dass, wenn auf der Leitung eine Pause von 3,5 Zeichen auftritt, der Empfänger die Übertragung des Pakets als abgeschlossen interpretieren soll. Dies kann jedoch zu einem Problem führen, da 3,5 Zeichen je nach Konfiguration zeitlich gesehen deutlich unter einer Millisekunde sein können und es durch das Betriebssystem des Rechners ohne weiters zu solchen Verzögerungen kommen kann. In diesem Moment würde der Empfänger (zB µC) zwei Pakete bekommen, aber anhand der Prüfsummen sehen, dass etwas nicht stimmt und beide Pakete als korrupt erkennen und verwerfen. An diesem Punkt ist die Abhilfe nur durch "pfuschen" möglich, nämlich in dem man zum Beispiel in der Konfiguration die Wartezeit von 3,5 Zeichen auf 35 oder 70 Zeichen erhöht. Außerdem darf in einer RTU-Übertragung keine Pause von mehr als 1,5 Zeichen sein, da der Empfänger das Paket dann auch verwerfen würde. Gegebenenfalls muss auch diese Zeit angepasst werden. Alternativ wäre nur der Umstieg auf eine anderes Verfahren zu nennen. Außerdem darf in einer RTU-Übertragung keine Pause von mehr als 1,5 Zeichen sein, da der Empfänger das Paket dann auch verwerfen würde. Gegebenenfalls muss auch diese Zeit angepasst werden. 


