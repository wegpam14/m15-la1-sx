 # 5. Protokoll	
 - Name: Lara Hofer
 - Datum, Ort: 15. Jänner 2019, AUT Labor Kaindorf
 - Gruppe: 1
 - Anwesend: Breitenthaler, Fischer, Grebien, Hofer, Hörmann, Kahr
 - Abwesend: -

## Inhaltsangabe

1. Feldbusse

*[1.1] Was sind Feldbusse?*

*[1.2] Feldbus Vorteile*

*[1.3] Feldbus Nachteile*

2. Modbus

 *[2.1] Was ist ein Modbus?*
 
 *[2.2]Was ist eine proprietäre Schnittstelle (Bussysteme)?*
 
4. Übung: Temperaturwert über Modbus - Schnittstelle

## 1. Feldbusse

### Was sind Feldbusse?

Feldbusse sind Kommunikationssysteme, die Geräte der Feldebene miteinander verbinden. Dadurch ist der Datenaustausch zwischen Messfühler (Sensoren) und Stellglieder (Aktoren) möglich. Die Wahl des Feldbusses variiert vom Anwendungsgebiet:

*Industrie*:

 - Pofinet / Profibus
 - Powerlink
 - Interbus
 - Modbus

*Automative*:
- LIN
- CAN
- Flexray
- MOST

*Hausautomatisierung*:
- KNX
- Modbus
- Homematic
- CAN

#### *Feldbus Vorteile:*

-   *Schnelligkeit*:
Durch den reduzierten Verkabelungsaufwand können Feldbus-Systeme rascher geplant und installiert werden. Feldbusse kommunizieren lediglich über ein Kabel.
-   *Zuverlässigkeit*: 
Kurze Signalwege erhöhen sowohl die Verfügbarkeit als auch die Zuverlässigkeit der Systeme.
-   *Störungssicherheit*: 
Vor allem bei analogen Werten bieten Feldbusse einen erhöhten Schutz vor Störungen.
-   *Einheitlichkeit*: 
Durch genormte Busprotokolle und vereinheitlichte Anschlusstechnik können Geräte verschiedener Hersteller einfacher eingesetzt und ausgetauscht werden. Somit müssen nicht zwingend alle einzelnen Komponenten vom selben Hersteller stammen.
-  *Flexibilität*: 
Erweiterungen und Änderungen lassen sich bei Feldbussen einfach und schnell durchführen. So kann man die Systeme variabel an neue Anforderungen anpassen und auch in der Zukunft verwenden.

#### *Feldbus Nachteile:*

-   *Komplexität*: 
Da ein Feldbus ein komplexes System darstellt, sind für dessen Verwendung qualifizierte Mitarbeiter nötig.
-   *Kosten*: 
Die einzelnen Feldbus-Komponenten sind wesentlich teurer
-   *Längere Reaktionszeit*


## 2. Modbus

### Was ist ein Modbus?

[Modbus - LMS Skript](https://lms.at/dotlrn/classes/htl_elektrotechnik/610437.4AHME_LA1SX.18_19/xolrn/2148F16AC6F2E.symlink?resource_id=0-333368687&m=view#167572556) 
Theoretische Erklärungen befinden sich in diesem Skript wo man sie perfekt nachlesen kann. Ein Modbus besitzt auch eine eigene PORT - Nr.: *PORT 502*

### Was ist eine proprietäre Schnittstelle (Bussysteme)?

Eine Schnittstelle, die nur auf einem herstellereigenen Computermodell einsetzbar ist.
*Vorteil*: Bezieht sich genau auf meine Aufgabenstellung (es ist einfacher zu realisieren).
*Nachteil*: Es ist nur im eigenen System verfügbar.

#### Serielle Schnittstellen

***RS 232***
![RS485](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoflam15/Unbenannt3.png)



***RS 485***
![RS485](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoflam15/Unbenannt.png)




#### Modbus Server
Der Modbus Server besitzt die Informationen (in unserem Beispiel die Temperaturwerte) und stellt sie zur Verfügung.

#### Modbus Client
Der Modbus Client fragt nach diese Informationen.



## 3. Übung: Temperaturwert über Modbus - Schnittstelle
In dieser Übung müssen den Temperatursensor vom Aduino Nano über einen Modbus verfügbar zu machen.
![Temperatur](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoflam15/Temperatur.png)

#### Request Grundaufbau:
Um eine Antwort vom Modbus - Server zu erhalten muss eine Request gesendet werden. Dabei arbeiten wir mit dem ASCII Transmission Mode.
*ASCII Transmission Mode*: Bytes werden als ASCII Text versendet


|   Startbyte   |    Adresse    |  Funktion |     Daten     |    LCR    |    Ende    |
|:-------------:|:-------------:|:---------:|:---------:|:---------:|------------|
|        :      |       2 Bytes      |    2 Bytes     |   n Bytes   |     2 Bytes    |    CR LF   |

#### Übung:

|   Startbyte   |    Adresse    |  Funktion |     Daten     |    LCR    |    Ende    |
|:-------------:|:-------------:|:---------:|:---------:|:---------:|------------|
|        :      |       10      |    04     |   0001 0001   |     B9    |    13 10   |

##### Startbyte
Es wird ein `:` gesendet, damit der Server/Client weiß, wann eine neue Request/Response beginnt.

##### Adresse
Die Adressen dienen zum Zuordnen einer Request. Adressen sind Hexadezimal.

##### Funktion
Der Function-Code sagt was mit der Request gemacht wird, in unserer Übung ist der Function Code 4 zu realisieren.

##### Daten
Enthält die Nummer des Registers. Achtung! Register beginnen bei 1.

##### LCR
Um den LCR zu berechnen werden alle Bytes nach dem Startbit bis zum LCR zusammengezähl und dann mit  -1 multipliziert.

Bei dieser Request: *B9*

| 1 | 0x31 |49|
|:-:|:----:|:-:|
| 0 | 0x30 |48|
| 0 | 0x30 |48|
| 4 | 0x34 |52|
| 0 | 0x30 |48|
| 0 | 0x30 |48|
| 0 | 0x30 |48|
| 1 | 0x31 |49|
| 0 | 0x30 |48|
| 0 | 0x30 |48|
| 0 | 0x30 |48|
| 1 | 0x31 |49|
|   |      |  |
|  | 0x247 |583

    0x247 -> 0x47 = +71 
    71 * -1 = -71 -> = 185 = B9

##### Endwert
Um zu erfahren wann eine Request/Response endet werden am Ende die Zahlen `13 10` gesendet.

#### Response Grundaufbau:

|   Startbyte   |    Adresse    |  Funktion | Quantität Bytes |     Daten     |    LCR    |    Ende    |
|:-------------:|:-------------:|:---------:|:---------:|:---------:|:---------:|------------|
|    :      |    2 Bytes     |    2 Bytes   |    2 Bytes | n Bytes  |   2 Bytes |    CR LF   |

#### Übung:

|   Startbyte   |    Adresse    |  Funktion | Quantität Bytes |     Daten     |    LCR    |    Ende    |
|:-------------:|:-------------:|:---------:|:---------:|:---------:|:---------:|------------|
|        :      |       10      |    04     |      02         |   .........   |     ..    |    13 10   |

Startbyte, Adresse, Funktion, LCR und Ende funktioniert gleich wie oben beschrieben.

##### Quantität

Die Quantität gibt an wie viele Datenbytes zurückgesendet werden muss, bzw wie viele Bytes die Response enthält.

##### Daten

Bei der Response stehen uns 16 Bit zur Verfügung um den Temperaturwert zu senden. Um diese optimal zu nutzen verwenden wir folgende Codierung: Die ersten 8 Bit stehen für den °C-Wert und die anderen 8 Bit für die Kommerzahl. Mit dieser Anwendung sind Temperaturwerte von 127,996°C bis - 128.0°C möglich. -> Bestmögliche Codierung!

