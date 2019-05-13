# Protokoll 6  
Name: Simon Szapacs  
Klasse 4AHME  
KNR: 12  
Gruppe: 2  

## Inhalt 
1. Intelligenter Sensor  
2. Feldbus  
3. Modbus  
  3.1 RTU  
  3.2 ASCII  
  3.3 TCP  
4. Objekt Types    
6. Request PC zum µC  
7. Response µC zum PC  


## Intellignter Sensor  

Dieser Sensor ist intelligent, weil er schon einen Temperaturwert zurückliefert. Er besitzt eine digitale Elektronik, deswegen kann er selbst Informationen verarbeiten. Diese Informationen liefert er direkt auf einen Schnittstelle. Zum Beispiel ist der Temperatursensor auf unserm µC intelligent. 

## Feldbus  
Dies ist ein Bussystem, das Sensoren und Aktoren mit einem Automatisierungsgerät verbindet. Wenn mehrere Teilnehmer ihr Nachrichten über die selbe Leitung senden wollen, muss festgelegt sein wer was wann sagt. 
Quelle: [Wikipedia](https://de.wikipedia.org/wiki/Feldbus)  

Diese Bussysteme sind weit verbreitet:  
* Powerlink  (Industriebereich)
* LIN  (Automobilbereich)
* CAN  (Automobilbereich)
* Flexray  (Automobilbereich)
* Profibus  (Industrie)
* KNX  (Haustechnik)
* Modbus  (Industire)

## Modbus  
Das Modbus-Protokoll ist ein Kommunikationsprotokoll, das auf einer Master/Slave- bzw. Client/Server-Architektur basiert. Es wurde 1979 von Gould-Modicon für die Kommunikation mit seinen speicherprogrammierbaren Steuerungen ins Leben gerufen. In der Industrie hat sich der Modbus zu einem De-facto-Standard entwickelt, da es sich um ein offenes Protokoll handelt. Seit 2007 ist die Version Modbus TCP Teil der Norm IEC 61158.  
Quelle: [Wikepedia](https://de.wikipedia.org/wiki/Modbus)  
![](https://github.com/HTLMechatronics/m15-la1-sx/blob/szasim15/Modbus.PNG)  

### RTU  
Im RTU-Modus wird der Sendebeginn durch eine Sendepause von mindestens der 3,5-fachen Zeichenlänge markiert. Ein Zeichen besitzt abhängig von der verwendeten Betriebsart des UARTs eine Länge von 10 bis 12 Bit (je nach Anzahl der Stopbits und dem Vorhandensein eines Paritätsbits). Die Länge der Sendepause hängt somit von der Übertragungsgeschwindigkeit ab. Dies muss bei niedrigen Baudraten exakt eingehalten werden. Ab 19200 Baud kann eine feste Pausenzeit von 2 ms verwendet werden. Das Adressfeld besteht aus acht Bit, die die Empfängeradresse darstellen. Der Slave sendet bei seiner Antwort an den Master ebendiese Adresse zurück, damit der Master die Antwort zuordnen kann. Das Funktionsfeld besteht aus 8 Bit. Hat der Slave die Anfrage des Masters korrekt empfangen, so antwortet er mit demselben Funktionscode. Ist ein Fehler aufgetreten, so verändert er den Funktionscode, indem er das höchstwertige Bit des Funktionsfeldes auf 1 setzt. Das Datenfeld enthält Hinweise, welche Register der Slave auslesen soll, und ab welcher Adresse diese beginnen. Der Slave setzt dort die ausgelesenen Daten (z. B. Messwerte) ein, um sie an den Master zu senden. Im Fehlerfall wird dort ein Fehlercode übertragen. Das Feld für die Prüfsumme, die mittels CRC ermittelt wird, beträgt 16 Bit. Das gesamte Telegramm muss in einem kontinuierlichen Datenstrom übertragen werden. Tritt zwischen zwei Zeichen eine Sendeunterbrechung auf, die länger als 1,5 Zeichen ist, so ist das Telegramm als unvollständig zu bewerten und sollte vom Empfänger verworfen werden.  
Quelle: [Wikepedia](https://de.wikipedia.org/wiki/Modbus)  

### ASCII  
Im ASCII-Modus beginnen Nachrichten mit einem vorangestellten Doppelpunkt, das Ende der Nachricht wird durch die Zeichenfolge Carriage return – Line feed (CRLF) markiert.
Die ersten zwei Bytes enthalten zwei ASCII-Zeichen, die die Adresse des Empfängers darstellen. Der auszuführende Befehl ist auf den nächsten zwei Bytes codiert. Über weitere n Zeichen folgen die Daten. Über das gesamte Telegramm (ohne Start- und Ende-Markierung) wird zur Fehlerprüfung ein LRC ausgeführt, dessen Paritätsdatenwort in den abschließenden zwei Zeichen untergebracht wird. Tritt während der Übertragung eines Frames eine Pause von > 1s auf, wird der Frame als Fehlerfall bewertet. Der Benutzer kann ein längeres Timeout konfigurieren.  
Quelle: [Wikepedia](https://de.wikipedia.org/wiki/Modbus)  

### TCP  
Modbus/TCP ist RTU sehr ähnlich, allerdings werden TCP/IP-Pakete verwendet, um die Daten zu übermitteln. Der TCP-Port 502 ist für Modbus/TCP reserviert. Modbus/TCP ist seit 2007 in der Norm IEC 61158 festgelegt und wird in IEC 61784-2 als CPF 15/1 referenziert.  

Transaktionsnummer |	Protokollkennzeichen |	Zahl der noch folgenden Bytes | Adresse | Funktion | Daten  
-------------------|-----------------------|--------------------------------|---------|----------|-------  
2 Byte |	2 Byte (immer 0x0000) |	2 Byte (n+2) |	1 Byte |	1 Byte |	n Byte    


Quelle: [Wikepedia](https://de.wikipedia.org/wiki/Modbus)  


## Objekt Types  

Schnittstellentyp | Objekttyp | Zugriff | Größe  
------------------|-----------|---------|------  
Analoger Eingang | "Input Register" | Lesen | 16 bit  
Digitaler Eingang | "Discrete Input" | Lesen | 1 bit  
Digitaler Ein-/Ausgang | "Coil" | Lesen & Schreiben | 1 bit  
Analoger Ein-/Ausgang | "Holding Register" | Lesen & Schreiben | 16 bit  

## Request PC zum µC  

Aufbau Modbus Serial Line ASCII Frame:  

3a | Beliebige Adresse | Function Code | Daten | LRC-Prüfsumme | CR | LF |  
---|-------------------| --------------| ------|---------------|----|----|  
| : | 0C | 04  | 0000 0001  | A8   |  \r   |  \n  |

Bilden der LRC Prüfsumme:  

| : | 0C | 04  | 0000 0001  | Prüfsumme Ergebniss   |  \r   |  \n  |
---|-------------------| --------------| ------|---------------|----|----| 
| - | 30H+43H | 30H+34H | 30H * 7  + 31H |  |  | Summe = 600 Dezimal |  


## Response µC zum PC  

3a | Beliebige Adresse | Function Code | Anzahl der Bytes | Temperatur | LRC-Prüfsumme | CR |  LF | 
---|-------------------| --------------| ------|---------------|----|----|------|  
| : | 0C | 04  | 02  | 1752   | F8   |  \r  |   \n   |






