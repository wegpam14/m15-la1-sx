

 # Protokoll der 5. Einheit (15.01.2019)
  Name: 		Hörmann
  Gegenstand: Labor
  Lehrer: SX
  Klasse: 4AHME
  Gruppe: 1
  ## Inhaltsverzeichnis

 1. Bussysteme
 2. Modbus konfiguration
 
 ## 1. Bussysteme
 ### 1.1  Definition
 Bus ist im Grunde eine Abkürzung für das „Binary Unit System“. Dieses System dient innerhalb eines Netzwerkes für die Übertragung von Daten zwischen den einzelnen Teilnehmern.

![Prinzipieller Aufbau eines parralelbussystem](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoestm15/hoestm15/Images/Prinzipielle_Struktur_eines_parallelen_Bussystems.svg.png)


### 1.2 Arten der Bussysteme
1. Datenbus
2.  Adressbus
3. Steuerbus
4. CPU - interner Bus
5. CPU - externer Bus
6. Rechner internen Bus
7. Rechner externer Bus

### 1.3 Modbus in der Wirtschaft
#### Industrie
-Powerlink
-Profibus
-Interbus-S

#### Automotivenbereich
-CAN
-LIN
-Flexray
#### Hausautomatisierung

-Modbus
-CAN
-KNX


	
## 2. Modbus Übung
### 2.1 Requestdesign
Damit der Modbus eine Antwort sendet muss dieser erst einen Request erhalten, diese Request werden mittels ASCII-Text versendet.

Der Request ist wie gefolgt aufgebaut:


|   Startbyte   |    Adresse    |  Funktion |     Daten     |    LCR    |    Ende    |
|:-------------:|:-------------:|:---------:|:---------:|:---------:|------------|
|        :      |       2 Bytes      |    2 Bytes     |   n Bytes   |     2 Bytes    |    CR LF   |

**Startbyte:** Besteht aus einem ':', sodass der Client weis das ein neuer Request beginnt,

**Adresse:** Damit Client und Server Request zuzuordnen

**Funktion:** Gibt an was Server mit Request machen soll

**Daten:** Enthält Nummer des Registers

**LCR:** Alle Bytes nach dem Startbyte werden zusammengezählt mit -1 Multipliziert

**Ende:** Carriage return und line feed werden gesendet um mitzuteilen dass der Request zu Ende ist

Der Request den wir in unserer Übung erstellten sah folgendermaßen aus:
|   Startbyte   |    Adresse    |  Funktion |     Daten     |    LCR    |    Ende    |
|:-------------:|:-------------:|:---------:|:---------:|:---------:|------------|
|        :      |       10      |    04     |   0001 0001   |     B9    |    13 10   |

### 2.1 Responsedesign
Modbus sendet nach dem erhalten der Request einen Response mit den Temperaturwerten.

Die Response ist wie gefolgt aufgebaut:


|   Startbyte   |    Adresse    |  Funktion | Quantität Bytes |     Daten     |    LCR    |    Ende    |
|:-------------:|:-------------:|:---------:|:---------:|:---------:|:---------:|------------|
|    :      |    2 Bytes     |    2 Bytes   |    2 Bytes | n Bytes  |   2 Bytes |    CR LF   |



**Startbyte:** Besteht aus einem ':', sodass der Client weis das ein neuer Request beginnt,

**Adresse:** Damit Client und Server Request zuzuordnen

**Funktion:** Gibt an was Server mit Request machen soll

**Quantität:** Wie viel Bytes die Response erhält, bzw. wie viele Datenbytes zurückgesendet werden 

**Daten:** 16 Bits stehen für den zu versendenden Wert zur Verfügung. In unseren Beispiel werden diese Bits wie befolgt genutzt: ersten 8 Bits : °C Wert letzten 8 Bits für die Kommerzahl.

**LCR:** Alle Bytes nach dem Startbyte werden zusammengezählt mit -1 Multipliziert
Das LCR kann erst beim senden berechnet werden.

**Ende:** Carriage return und line feed werden gesendet um mitzuteilen dass der Request zu Ende ist


Der Response den wir in unserer Übung erstellten sah folgendermaßen aus:
|   Startbyte   |    Adresse    |  Funktion | Quantität Bytes |     Daten     |    LCR    |    Ende    |
|:-------------:|:-------------:|:---------:|:---------:|:---------:|:---------:|------------|
|        :      |       10      |    04     |      02         |   .........   |     ..    |    13 10   |
