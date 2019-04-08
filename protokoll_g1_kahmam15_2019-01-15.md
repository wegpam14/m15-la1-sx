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
  * *1.2 [Realisierung](#realisierung)*
  * *1.3 [Server-Client System](#serverClient)*
* **2. [Übung](#übung)**
   * *2.1 [Request](#request)*  
   * *2.2 [Response](#response)*  
   
___
  <a name="modbus"></a>
### 1. Modbus 
Das Grundkonzept hinter dem Modbus ist es über verschiedene Schnittstellen miteinander zu kommunizieren.  
Mögliche Schnittstellen sind:  
* **TCP/IP Modbus-Port: 502**  
* **RS232: UART-Schnittstelle mit anderen Spannungsniveaus (Punkt zu Punkt)**  
* **RS485: Zweidrahtleitung mit vielen Anhängen (bis zu 32)**  
  
Wir wenden Modbus an, da man bei jeglichen anderen Bus-Systemen nicht wirklich "offen" Informationen zur Verfügung stellen.
  

<a name="feldbusse"></a>
#### 1.1 Feldbus-Systeme
  Geräte die Aktoren und Sensoren echzeitfähig verbinden (Prozessrechner) nennt man **Geräte der Feldebene** oder **Feldbusse**.   
  Ein **Datenbus** ist ein System, wo man Bausteine mit mehreren Leitungen verbindet.  
    
  **Industrie:**  
  * Profinet/Profibus  
  * **Powerlink**  
  * Interbus S  
  
  **Automotive:** 
  * LIN  
  * CAN  
  * FLEXRAY  
  
  **Hausautomatisierung:**  
  * KNX  
  * **Modbus**  
  * Homematic  
  * CAN  
  
Eine Alternative zum Feldbus ist eine sogenannte **"proprietäre Schnittstelle"** (Bussystem). Proprieätar = "Eigenkreation", daher kann es nicht mit anderen Systemen verbunden werden, jedoch bezieht es geringen Aufwand.
  
___
<a name="übung"></a>
### 3. Übung
Das Ziel unserer Übung war es einen Temperaturwert über die Modbus-Schnittstelle verfügbar zu machen, dazu soll der Temperatursensor an die SPS angeschlossen werden.  

<a name="request"></a>
#### 3.1 Request
Um vom Modbus-Server eine Antwort zu erhalten muss er zuerst vom Client eine Request empfangen. Diese Request haben wir mithilfe des **ASCII Transmission Mode** versendet. Dieser Modus sendet die Bytes als ASCII-Text. Frames beginnen hier mit einem Doppelpunkt.  
![ASCII-Frame](https://github.com/HTLMechatronics/m15-la1-sx/blob/kahmam15/ASCII-Frame.png)  

**Start Byte|Adresse|Funktions Code|Daten|LRC|Ende**
-|-|-|-|-|-
:|10|04|0001 0001|B9|13 10



<a name="response"></a>
#### 3.2 Response

    
___



[Präprozessor]: https://de.wikipedia.org/wiki/C-Pr%C3%A4prozessor
[Compiler]: https://de.wikipedia.org/wiki/Compiler
[Assembler]: https://de.wikipedia.org/wiki/Assembler_(Informatik)
[Linker]: https://de.wikipedia.org/wiki/Linker_(Computerprogramm)
[GNU-Projekt]: https://de.wikipedia.org/wiki/GNU-Projekt
[Richard Stallman]:https://de.wikipedia.org/wiki/Richard_Stallman
[maketool]:https://de.wikipedia.org/wiki/Make
[Makefile]:http://www.c-howto.de/tutorial/makefiles/
