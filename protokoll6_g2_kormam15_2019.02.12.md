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
  
  
---
  
### Funktion Code  
  
  
---
  
### Protokoll-definition
  
  
---
  
### Request vom PC zum µC  
  
  
---
  
### Response vom µC zum PC  
  
  
---
  
### Exceptions  
  
  
---
