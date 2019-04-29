![HTBLA Kaindorf](https://github.com/HTLMechatronics/m15-la1-sx/blob/kahmam15/rsz_htl_kaindorf_logosvg.png)
# 6. Protokoll (09.04.2019)
Name: Kahr Markus  
Klasse: 4AHME  
KNr.: 6  
Gruppe: 1  
___

## Inhalte:  

* **1. [Übertragung mittels Server-Client System](#Server-client)**  
   * *1.1 [Request](#request)*  
   * *1.2 [Response](#response)*  
   
___
  <a name="Server-client"></a>
### 1. Übertragung mittels Server-Client System
Die Aufgabe bestand daraus die Temperatur über den µC(Server) zu messen, und diese dann jederzeit auf dem PC(Client) abrufbar zu machen. Der PC sendet zu Beginn eine Request an den µC, falls es keine Fehler dabei gab senden der µC eine Response and mit der gemmessen Temperatur zurück.
![Server-Client](https://github.com/HTLMechatronics/m15-la1-sx/blob/kahmam15/rsz_server-client-modbus.png)
  

<a name="request"></a>
#### 1.1 Request  
**Aufbau im Übungs-Frame:**

Start Byte|Adresse|Funktions Code|Daten|LRC|Ende
-|-|-|-|-|-
:|01|04|0001 0001|B9|'\r' '\n' 
  
    
<a name="response"></a>
#### 1.2 Response
Beim Response antwortet der Modbus-Server auf unsere Request. In unserem Beispiel sollte er mit dem gemessenen Temperaturwert antworten.
  
**Aufbau im Übungs-Frame:**

Start Byte|Adresse|Funktions Code|Daten|LRC|Ende
-|-|-|-|-|-
:|01|04|0217 80-- |--|'\r' '\n' 
  
**17 80** entspricht einer Temperatur von **23,5°C**
___



[RS232]: https://de.wikipedia.org/wiki/RS-232
[RS485]: https://de.wikipedia.org/wiki/EIA-485
[TCP/IP]: https://de.wikipedia.org/wiki/Transmission_Control_Protocol/Internet_Protocol
[Modbus]: https://de.wikipedia.org/wiki/Modbus
[Datenbus]: https://de.wikipedia.org/wiki/Bus_(Datenverarbeitung)
[Powerlink]: https://de.wikipedia.org/wiki/Bus_(Datenverarbeitung)
[Punkt zu Punkt]: https://www.itwissen.info/Punkt-zu-Punkt-Verbindung-PzP-point-to-point-P2P.html
