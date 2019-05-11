# Protokoll 6 (13.02.2019)

![](https://www.koerbler.com/neuigkeiten/wp-content/uploads/2013/03/htl-kaindorf.jpg)![](https://www.htl-kaindorf.at/images/startpage/logoMecha.png)   
Name: Korrenn Marwin  
Klasse: 4aHME  
KNR: 7  
Gruppe: 2

---

## Inhalt 
1. [Intelligenter Sensor](#intelligenter-sensor)  
1. [Feldbus](#feldbus)  
   1. [Modbus](#modbus)  
      1. [RTU](#rtu)  
      1. [ASCII](#ascii)  
      1. [TCP](#TCP)  
   1. [Datenmodel](#datenmodel)  
   1. [Funktion-Code](#funktion-code)  
   1. [Protokoll-definition](#protokoll-definition)  
   1. [Request vom PC zum µC](#request-vom-pc-zum-µc)  
   1. [Response vom µC zum PC](#response-vom-µc-zum-pc)  
   1. [Exceptions](#exceptions)  
  
---
  
### Intelligenter Sensor  
Ein *intelligenter* Sensor kann Informationen selbst verarbeiten (zB. Temperatursensor auf dem µC) und kann über eine standartisierte Schnittstelle nach außen kommunizieren.  
Ein *unintelligenter* Sensor (zB. PT100) liefert nur eine physikalische Größe zurück und man muss sich selbst um die Informationsgewinnung kümmern.  

---
  
### Feldbus  
Unter "Feldbus" versteht man ein Kommunikationssystem das Sensoren und Aktuatoren mit einem "Kontroll"-Gerät verbindet. Welches Bussystem sinnvoll ist hängt von der Anwendung ab. Weit verbreitet sind:  

Name | Anwendung |
------------|--------------------------------------------------------------------------------------------------------------
Powerlink | basiert auf Ethernet, das für Echtzeitanwendungen erweitert wurde. hauptsächlich für Maschinen- und Anlagenbau
LIN | für wenig komplexe Anwendungen in der Automobilindustrie
CAN | für mittel-komplexe Anwendungen in der Automibilindustrie
Flexray | für komplexe Anwendungen in der Automobilindustrie
Profibus | für z.B. Roboter, Maschinenbau, Anlagenbau
KNX | für die Gebäudeautomatisierung
Modbus | freier Standard für unterschiedlichste Anwendungen in der Industrie

Wir verwenden Modbus weil es ein frei verfügbarer Standart ist und verhältnismäßig einfach zu lernen ist.

---
  
### Modbus  
> Das Modbus-Protokoll ist ein Kommunikationsprotokoll, das auf einer Master/Slave-bzw. Client/Server-Architektur basiert. Es wurde 1979 von Gould-Modicon für die Kommunikation mit seinen speicherprogrammierbaren Steuerungen ins Leben gerufen. In der Industrie hat sich der Modbus zu einem De-facto-Standard entwickelt, da es sich um ein offenes Protokoll handelt. Seit 2007 ist die Version Modbus TCP Teil der Norm IEC 61158.  
[Quelle Wikipedia.org](https://de.wikipedia.org/wiki/Modbus)  

Es funktioniert nach dem Server/Client Prinzip:
![](https://github.com/HTLMechatronics/m15-la1-sx/blob/muranm15/ModbusServerClient.png)  

Die Datenübertragung wird hierbei unter 3 Betriebsarten unterteilt: 
* RTU (bniäre Übertragung von Daten)  
* ASCII (textuelle, byteweise Übertragung von Daten)  
* TCP (Daten werden in TCP Paketen übertragen)  
---
  
### RTU
> Im RTU-Modus wird der Sendebeginn durch eine Sendepause von mindestens der 3,5-fachen Zeichenlänge markiert. Die Länge der Sendepause hängt somit von der Übertragungsgeschwindigkeit ab. Das Adressfeld besteht aus acht Bit, die die Empfängeradresse darstellen. Der Slave sendet bei seiner Antwort an den Master ebendiese Adresse zurück, damit der Master die Antwort zuordnen kann. Das Funktionsfeld besteht aus 8 Bit. Hat der Slave die Anfrage des Masters korrekt empfangen, so antwortet er mit demselben Funktionscode. Ist ein Fehler aufgetreten, so verändert er den Funktionscode, indem er das höchstwertige Bit des Funktionsfeldes auf 1 setzt. Das Datenfeld enthält Hinweise, welche Register der Slave auslesen soll, und ab welcher Adresse diese beginnen. Der Slave setzt dort die ausgelesenen Daten (z. B. Messwerte) ein, um sie an den Master zu senden. Im Fehlerfall wird dort ein Fehlercode übertragen. Das Feld für die Prüfsumme, die mittels CRC ermittelt wird, beträgt 16 Bit. Das gesamte Telegramm muss in einem kontinuierlichen Datenstrom übertragen werden. Tritt zwischen zwei Zeichen eine Sendeunterbrechung auf, die länger als 1,5 Zeichen ist, so ist das Telegramm als unvollständig zu bewerten und sollte vom Empfänger verworfen werden.  
[Quelle Wikipedia.org](https://de.wikipedia.org/wiki/Modbus) 
  
---
  
### ASCII  
Im ASCII-Modus wird der Beginn der Information mit einem vorangestellten Doppelpunkt und das Ende der Nachricht mit der Zeichenfolge Carriage return – Line feed (CRLF) markiert.  

> Die ersten zwei Bytes enthalten zwei ASCII-Zeichen, die die Adresse des Empfängers darstellen. Der auszuführende Befehl ist auf den nächsten zwei Bytes codiert. Über ein Zeichen folgen die Daten. Über das gesamte Telegramm (ohne Start- und Ende-Markierung) wird zur Fehlerprüfung ein LRC ausgeführt, dessen Paritätsdatenwort in den abschließenden zwei Zeichen untergebracht wird. Tritt während der Übertragung eines Frames eine Pause von > 1s auf, wird der Frame als Fehlerfall bewertet. Der Benutzer kann ein längeres Timeout konfigurieren.  
[Quelle Wikipedia.org](https://de.wikipedia.org/wiki/Modbus) 

---
  
### TCP  
Der TCP Modus ist dem [RTU](#rtu) Modus sehr ähnlich, allerdings werden TCP/IP-Pakete verwendet, um die Daten zu übermitteln. 
  
---
  

### Datenmodell  
Es wird zwischen vier Adressräumen unterschieden:

Adressraum | Beschreibung | Beispiel
----------- | ------------ | ------------------------
Input Registers | Ein Input-Register ist ein 16-Bit Wert der nur gelesen werden kann | Temperatursensor
Discrete Input | Ein Discrete Input ist ein einzelnes Bit, das nur gelesen werden kann | Taster
Coils (Spulen) | Eine Coil ist ein Bit das gelesen und beschrieben werden kann | LED
Hold-Registers | Ein Hold-Register ist ein 16-Bit Wert der gelesen und beschrieben werden kann | 7-Segment-Anzeige

In Modbus kann jeder Adressraum Adresswerte von 1 bis 65536 verwenden. Dies jedoch koräliert nicht mit der Protocol Data Unit die Werte zwischen 0 und 65535 annehmen kann.

---
  
### Funktion Code  
Über Function-Codes sind die Bedeutungen der Frames im Modbus-Frame definiert.  
Für Requests und Non-Error-Responses werden folgende Codes verwendet:  
* User defined Function Codes (65-72, 100-110, dürfen individuell verwendet werden)   
* Reserved Function Codes (8, 9, 10, 13, 14, 41, 42, 90, 91, 125, 126, 127, Werte, welche von Unternehmen werwendet wurden)  
* Public Function Codes (alle zwischen 1 und 127 übrigen Werte, eindeutig von der Modbus.org community festgelegt)  

Hier sind einige wichtige Public Function Codes aufgeführt:  

 Function-Code | Hex | Name | Typ
 --------------- | --------- | --------- | ---
 1 | 01 | Read Coils | Bit
 2 | 02 | Read Discrete Inputs | Bit
 3 | 03 | Read Holding Registers | 16-Bit 
 4 | 04 | Read Input Register | 16-Bit 
 5 | 05 | Write Single Coil | Bit 
 6 | 06 | Write Single Register | 16-Bit  
 15 | 0F | Write Multiple Coils |	Bit 
 16 | 10 | Write Multiple Registers | 16-Bit  
  
---
  
### Protokoll-definition
Mit dem Modbus-Gateway können verschiedene Modbus-Varianten miternander verbunden werden.  

> Das Modbus Application Layer Protocol definiert dabei als Frame sogenannte Protocol Data Units (PDU). Diese enthalten noch kein Adressierungsschema, da unterschiedliche Varianten (UART, TCP, ...) auch unterschiedliche Adressierungsarten verwenden. 
Die zusätzlichen Spezifikationen für die jeweiligen Varianten definieren dann auch zusätzliche Frame-Felder für die Adressierung und Fehlererkennung, wodurch dann die Application Data Unit (ADU) entsteht.  

> Die maximale Größe einer ADU liegt bei Modbus ASCII/RTU bei 256 Bytes und bei Modbus TCP bei 260 Bytes. 

> Der *Socket* ist der sog. Modbusserver. Er besitzt die Portnummer 502. Erst über die IP-Adresse und die Portnummer (Socket) kann der Rechner etwas mit der Information anfangen. Aufgrund der IP-Adresse und der Prüfsumme (Checksum) ist keine Adresse und kein Errorcheck nötig.  
[Quelle modbus.org](http://modbus.org/)

---
  
### Request vom PC zum µC  
Aufbau von einem Modbus Serial Line ASCII Frame:

3a | Beliebige Adresse | Function Code | Daten | LRC-Prüfsumme | CR | LF |  
---|-------------------| --------------| ------|---------------|----|----|  
| : | 0C | 04  | 0000 0001  | A8   |  \r   |  \n  |
   
Bei jedem neuen Packet wird mit einem **:** begonnen.

Bilden der **LRC-Prüfsumme**:

| : | 0C | 04  | 0000 0001  | Prüfsumme Ergebniss   |  \r   |  \n  |
---|-------------------| --------------| ------|---------------|----|----| 
| - | 30H+43H | 30H+34H | 30H * 7  + 31H |  |  | Summe = 600 Dezimal | 
     
--> 600-256-256= **88**

-88 ==> -88+256 = 168 ==> **A8 Hex** ==> **LRC-Prüfsumme**  
  
---
  
### Response vom µC zum PC  
3a | Beliebige Adresse | Function Code | Anzahl der Bytes | Temperatur | LRC-Prüfsumme | CR |  LF | 
---|-------------------| --------------| ------|---------------|----|----|------|  
| : | 0C | 04  | 02  | 1752   | F8   |  \r  |   \n   |
   
---
  
### Exceptions  
Ist bei einer Übertragung ein fehler aufgetreten wird das Bit 7 im function Code Feld gesetzt.  
Einige wichtigen Fehlermeldungen sind:  
![](https://screenshotscdn.firefoxusercontent.com/images/8c40bbe9-eade-4673-8aca-8950b3511bba.png)
  
---
