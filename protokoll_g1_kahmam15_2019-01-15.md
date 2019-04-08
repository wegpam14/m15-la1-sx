![HTBLA Kaindorf](https://upload.wikimedia.org/wikipedia/commons/thumb/3/30/HTL_Kaindorf_Logo.svg/1200px-HTL_Kaindorf_Logo.svg.png)
# 5. Protokoll (15.01.2019)
Name: Kahr Markus  
Klasse: 4AHME  
KNr.: 6  
Gruppe: 1  
___

## Inhalte:  

* **1. [Modbus](#modbus)**  
  * *1.1 [Feldbus-Systeme](#feldbusse)*
* **2. [Übung](#übung)**
   * *2.1 [Request](#request)*  
   * *2.2 [Response](#response)*  
   
___
  <a name="modbus"></a>
### 1. Modbus 
Das Grundkonzept hinter dem **[Modbus]** ist es über verschiedene Schnittstellen miteinander zu kommunizieren.  
Mögliche Schnittstellen sind:  
* **[TCP/IP] Ethernet: Modbus-Port: 502**  
* **[RS232]: UART-Schnittstelle mit anderen Spannungsniveaus ([Punkt zu Punkt])**  
* **[RS485]: Zweidrahtleitung mit vielen Anhängen (bis zu 32)**  
  
Wir wenden Modbus an, da man bei jeglichen anderen Bus-Systemen nicht wirklich "offen" Informationen zur Verfügung stellen.
  

<a name="feldbusse"></a>
#### 1.1 Feldbus-Systeme
  Geräte die Aktoren und Sensoren echzeitfähig verbinden (Prozessrechner) nennt man **Geräte der Feldebene** oder **Feldbusse**.   
  Ein **[Datenbus]** ist ein System, wo man Bausteine mit mehreren Leitungen verbindet.  
    
  **Industrie:**  
  * Profinet/Profibus  
  * **[Powerlink]**  
  * Interbus S  
  
  **Automotive:** 
  * LIN  
  * CAN  
  * FLEXRAY  
  
  **Hausautomatisierung:**  
  * KNX  
  * **[Modbus]**  
  * Homematic  
  * CAN  
  
Eine Alternative zum Feldbus ist eine sogenannte **"proprietäre Schnittstelle"** (Bussystem). Proprieätar = "Eigenkreation", daher kann es nicht mit anderen Systemen verbunden werden, jedoch bezieht es geringen Aufwand.
  
___
<a name="übung"></a>
### 2. Übung
Das Ziel unserer Übung war es einen Temperaturwert über die Modbus-Schnittstelle verfügbar zu machen, dazu soll der Temperatursensor an die SPS angeschlossen werden.  

<a name="request"></a>
#### 2.1 Request
Um vom Modbus-Server eine Antwort zu erhalten muss er zuerst vom Client eine Request empfangen. Diese Request haben wir mithilfe des **ASCII Transmission Mode** versendet. Dieser Modus sendet die Bytes als ASCII-Text. Frames beginnen hier mit einem Doppelpunkt.  
  
**Basis-Frame:**  
![ASCII-Frame](https://github.com/HTLMechatronics/m15-la1-sx/blob/kahmam15/ASCII-Frame.png)  
  
**Übungs-Frame:**

Start Byte|Adresse|Funktions Code|Daten|LRC|Ende
-|-|-|-|-|-
:|10|04|0001 0001|b9|13 10

**Start Byte**  
Bei ASCII Transmission Mode immer ein **:**, um die Kommunkation einzuleiten
  
**Adresse**  
Damit das System weiß, an wenn die Request zu senden ist**Adresse 10**
  
**Funktions Code**  
Im Funktions Code wird angegeben was mit der Request gemacht werden soll-**04 für Read Input Register**
  
**Daten**  
Gibt die Quantity (Anzahl der Register) und das zu lesende Register weiter-**1 Register, das Erste**

**LRC**  
LRC-Prüfsumme: Bytewerte werden addiert(ohne Überlauf Berücksichtigung) und der Wert wird als Zweierkomplement betrachtet und negiert
* 1-0x31	49  
* 0-0x30	48  
* 0-0x30	48  
* 4-0x34	52  
* 0-0x30	48  
* 0-0x30	48  
* 0-0x30	48  
* 1-0x31	49  
* 0-0x30	48  
* 0-0x30	48  
* 0-0x30	48  
* 1-0x31	49  
Summe: 583 = 0x247 => 0x47 => negieren: -71 +255 =185 = **b9**
  
**Ende**  
Damit der Server weiß, dass die Request beendet wurde-**13 10**
  
  
<a name="response"></a>
#### 2.2 Response
Beim Response antwortet der Modbus-Server auf unsere Request. In unserem Beispiel sollte er mit dem gemessenen Temperaturwert antworten.
  
**Übungs-Frame:**

Start Byte|Adresse|Funktions Code|Daten|LRC|Ende
-|-|-|-|-|-
:|10|04|02 xx|xx|13 10

**Start Byte**  
Bei ASCII Transmission Mode immer ein **:**, um die Kommunkation einzuleiten
  
**Adresse**  
Damit das System weiß, an wenn die Response zu senden ist-**Adresse 10**
  
**Funktions Code**  
Im Funktions Code wird angegeben was mit der Response gemacht werden soll-**04 für Read Input Register**
  
**Daten**  
Gibt die Quantity (Anzahl der Register) und das zu lesende Register weiter-**2 Register, xx Daten**  
* Mögliche Kodierung:  
23,5°C -> 16Bitwert (Kodierung)[][][][][][][][]|[][][][][][][][]  
-32768… +32767 (/256) -> komma | => Werte von 127,996°C…-128°C
  
**LRC**  
LRC-Prüfsumme: Bytewerte werden addiert(ohne Überlauf Berücksichtigung) und der Wert wird als Zweierkomplement betrachtet und negiert
  
**Ende**  
Damit der Client weiß, dass die Response angekommen ist-**13 10**
  
___



[RS232]: https://de.wikipedia.org/wiki/RS-232
[RS485]: https://de.wikipedia.org/wiki/EIA-485
[TCP/IP]: https://de.wikipedia.org/wiki/Transmission_Control_Protocol/Internet_Protocol
[Modbus]: https://de.wikipedia.org/wiki/Modbus
[Datenbus]: https://de.wikipedia.org/wiki/Bus_(Datenverarbeitung)
[Powerlink]: https://de.wikipedia.org/wiki/Bus_(Datenverarbeitung)
[Punkt zu Punkt]: https://www.itwissen.info/Punkt-zu-Punkt-Verbindung-PzP-point-to-point-P2P.html
