# Protokoll der 5.Einheit   
  
  
  
  **Name**:  *Patrick Wegl*  
  **Datum:** *11.12.2018*  
  **Uhrzeit:** *8:00-10:30*  
  **Gruppe:** *3*  
  
   
    
 **Anwesend:** Sarah Vezonik, Alois Vollmaier, Patrick Wegl, Mercedes Wesonig, Matthias Winter, Thomas Winter  
  **Abwesend:** ---  

***********************************************************************************************************************************  
## Rückblick

Zu Beginn der Einheit besprachen wir die Themen, mit welchen wir uns in der [vorherigen Einheit](https://github.com/wegpam14/Protokoll-4)
beschäftigten, insbesondere mit dem Aufbau von einem Makefile.

*********************************************************************************************************************************** 
## Serielle Schnittstellen  

### Möglichkeiten zum Abfragen von Temperatursensoren am PC
 
 #### RS 232  

RS-232 ist eine am Computern häufig vorhandene serielle Schnittstelle, welche aber veraltet ist únd heute durch USB ersetzt wird.
 Punkt zu Punkt Schnittstellen

![RS232](https://s15.directupload.net/images/181217/3o5zo3gk.png)    
 
 ***********************************************************************************************************************************  
  
#### RS 485



Die Übertragung der Daten erfolgt durch einen differenziellen, seriellen Spannungspegel zwischen den Leitungen [A] und [B]. Da Daten auf den Leitungen zwischen Sender und Empfänger übertragen werden, spricht man auch von Halbduplex oder Wechselbetrieb. Weitere Informationen ![hier](https://www.janitza.de/kommunikation-ueber-die-rs485-schnittstelle.html).  
Jeder Empfänger oder Sender hat einen invertierten und nicht-invertierenden Anschluss. Die Übertragung der Daten erfolgt symmetrisch. Das heißt, hat eine Leitung ein „High“-Signal, 
hat die andere Leitung ein „Low“-Signal. Leitung A ist somit der Komplementär von B und umgekehrt. Der Vorteil der Messung der Spannungsdifferenz zwischen A und B ist, dass Gleichtaktstörungen weitestgehend keinen Einfluss haben. Eine eventuelle Gleichtaktstörung wird auf beiden Signalleitungen annähernd gleichmäßig eingekoppelt, und durch die Differenzmessung haben sie somit keinen Einfluss auf die zu übertragenden Daten. Der Sender (Driver) erzeugt eine differenzielle Ausgangsspannung von mindestens 1,5 V an 54 Ohm Last. Der Empfänger (Receiver) hat eine Empfindlichkeit +/-200 mV.
 
 **Logischer Zustand**  
 A–B < 0,25 V = Logisch 1  
A–B > 0,25 V = Logisch 0  

**Vorteile:**
 
 es wird sehr häufig verwendet weil es ein billiges System ist und da viele Dinge noch damit funktionieren.



![RS 485 ](https://s15.directupload.net/images/181217/qyarhalw.png)    

***********************************************************************************************************************************
## Feldbus
Feldbussystem | Andwendungsgebiet | Details  
------------- | ----------------- | -----  
**Powerlink** | Industrie | setzt auf Ethernet auf, ist echtzeitfähig, häufig für SPS  
**Profibus** | Industrie | setzt auf RS485 auf  
**Modbus** | Industrie | setzt auf RS485 und TCP/IP auf   
**CAN, LIN, Flexray** | Automobilindustrie | 
**KNX** | Haustechnik |  

***********************************************************************************************************************************   

# Modbus  
Das Feldbusprotokoll Modbus wurde 1979 für die Kommunikation zwischen zwei SPS Geräten entwickelt. Heutzutage wird es gerne in der Haustechnik und in der Industrie verwendet, da es ein offenes Protokoll ist und sich Lösungen mit RS232-, RS482- und TCP/IP- Verbindungen realisieren lassen.  
Das Kommunikationsprotokoll ist ein einfaches zustandsloses Protokoll basierend auf einem Request/Response Prinzip.  
 
## Modbus Gateway  

Es gibt zwei unterschiedliche Varianten der Pakete. Die PDU besteht immer aus *Function Code* und *Data*. Bei der ADU kommen noch zusätzlich *Adresse* und ein *Fehler-Check* hinzu. 
Bei Modbus TCP fällt dies weg, da Adresse und Prüfsumme schon im TCP/IP Paket enthalten sind. Die Maximalgröße der ADU-Pakte bei *RS232 / RS485 = 256 Bytes* und bei *TCP = 260 Bytes*.

Es gibt drei unterschiedliche Übertragungsvarianten:  
* **Modbus ASCII** Die Übertragung findet textuell byteweise Datenpakete statt.   
* **Modbus RTU** Hier findet die Datenübertragung binär byteweise statt.  
* **Modbus TCP** Hier werden die Daten über ein TCP Pakete übertragen.    

![Modbus](https://www.sma.de/fileadmin/content/global/Partner/Images/partner/sma_developer/modbus-request-response-tcp-ip.png)

***********************************************************************************************************************************

## Modbus-Daten-Modell  
Das Modbus-Daten-Modell unterscheidet sich in vier Bereiche:    

Name | Funktion  
---- | --------   
Discrete Inputs |  ist ein einzelnes Bit, das nur gelesen werden kann  
Coils |  ist ein Bit, das gelesen und beschrieben werden kann; Coil bedeutet soviel wie Relais  
Input Registers |  ist ein 16 Bit Wert, der nur gelesen werden kann  
Hold Registers |  ist ein 16 Bit Wert, der gelesen und beschrieben werden kann    

***********************************************************************************************************************************

### LRC

Longitudinal Redundancy Check LRC.. Summe einzelner Daten Bytes  


Am Ende des Frame wird ein 8-Bit LRC (ein Byte als Hexstring = 2 ASCII Zeichen) gesendet.

Dazu werden alle Bytes des Frames exklusive dem Start ':' und dem Ende (CR + LF) mit 8-Bit Additionen ohne Berücksichtigung des Überlaufs zusammenaddiert und am Ende einem Zweierkomplement unterzogen.

Beispiel: Read Coils (Coil-Address 11, Quantity=8) von Device #4

:0401000A000868<CR><LF>
Übertragen werden folgende Bytes:

0x3a 0x30 0x34 0x30 0x31 0x30 x030 0x30 0x41 0x30 0x30 0x30 0x38 0x36 0x38 0x0d 0x0a
Die Summe aller roten Bytes als 8-Bit Addition ohne  Berücksichtigung des Überlaufs ergibt: 0x98

Das Zweierkomplement ergibt: 0xff-0x98+1 = 0x68


  
