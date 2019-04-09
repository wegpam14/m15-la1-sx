# Protokoll 5 (15.01.2019)
Name: Fischer Maximilian  
KNr.: 2  
Klasse: 4AHME  
Gruppe: 1  
___
### Übersicht

1. Schnittstellen / Feldbusse
    1. Bus-Systeme
    1. Modbus
1. Übung: Temperaturwert über Schnittstelle mithilfe von Modbus
    1. Design der Request
    1. Design der Response
___

## **1** Schnittstellen / Feldbusse

Über Schnittstellen werden SPS, PC, Aktoren sowie Sensoren miteinander verbunden.
Es empfehlen sich standartisierte Feldbus-Systeme, da so die einzlenen Komponenten mit dem gleichen Feldbus miteinander kommunizieren können.

Schnittstellen wie zum Beispiel **Ethernet TCP/IP** sind **nicht echtzeitfähig**, daher sollte auf abgewandelte Standards wie **Powerlink** gelegt werden.

### **1.1** Bus-Systeme

**Datenbus**: Ein system bestehend aus mehreren Leitern, welche genützt werden um Daten auszutauschen.

**Im Industriebereich**:
- Powerlink *(open-source)*
- Profibus/Profinet
- Interbus-S

**Im Automotivebereich**:
- LIN
- CAN
- Flexray

**Zur Hausautomatisierung**:
- KNX
- CAN
- Homematic
- Modbus *(einfach, vielseitig)*

**Proprietäre Schnittstelle**: Selber zusammengeschnitztes Bus-System
- geringer Aufwand
- funktioniert für die dafür vorgesehene Anwendung sehr gut
- erfüllt genau was erfüllt sein muss
- kann nicht mit anderen Systemen verbunden werden

### **1.2** Modbus

In den folgenden Übungen werden wir den Modbus verwenden. Der Modbus ünterstutzt mehrere Übertragungsarten:
- über TCP/IP Ethernet (Port 502)
- über RS-232

**Modbus-Server**: dieser besitzt die Informationen - in unserem Fall die Temperaturwerte, also ist bei unserer Anwendung der Arduino der Modbus-Server

**Modbus-Client**: dieser fragt nach den Informationen

___

## **2** Übung: Temperaturwert über Schnittstelle mithilfe von Modbus

Ziel dieser Übung ist es, den Temperatursensor vom Arduino Nano über einen Modbus verfügbar zu machen.

### **2.1** Design der Request

Damit der Modbus-Server eine Antwort sendet muss dieser eine Request empfangen.
Für die Request arbeiten wir mit dem **ASCII Transmission Mode**, bei diesem werden die Bytes als ASCII-Text versendet.

**Request Grundaufbau:**

|   Startbyte   |    Adresse    |  Funktion |     Daten     |    LCR    |    Ende    |
|:-------------:|:-------------:|:---------:|:---------:|:---------:|------------|
|        :      |       2 Bytes      |    2 Bytes     |   n Bytes   |     2 Bytes    |    CR LF   |

**Request in unserer Übung:**

|   Startbyte   |    Adresse    |  Funktion |     Daten     |    LCR    |    Ende    |
|:-------------:|:-------------:|:---------:|:---------:|:---------:|------------|
|        :      |       10      |    04     |   0001 0001   |     B9    |    13 10   |

##### Startbyte

Damit Server/Client wissen wann eine neue Request/Response beginnt wird als erstes Byte ein `:` gesendet.

##### Adresse

Adresse damit Server und Client die Request zuordnen können.

##### Funktion

Der Function code gibt an was der Server mit der Request machen soll.
In unserem Fall der Function Code 4 der für **read input register** steht.

##### Daten

Enthält die Nummer des Registers *(16)* - da die Register beim Modbus bei 1 beginnen, muss dieser Wert um 1 erhöht werden.

##### LCR

Um den LCR zu berechnen werden alle Bytes nach dem `:` bis zum LCR zusammengezählt (overflow zulässig)
und dann mit *-1* multipliziert.

Bei dieser Request, mit genau diesen Werten also: **B9**

##### Ende

Damit Server/Client wissen wann eine Request/Response endet werden am Ende `13 10` gesendet *(für carriage return und line feed)*.

### **2.2** Design der Response

Der Modbus-Server sendet nach der Request eine Response mit dem Temperaturwert.

**Response Grundaufbau:**

|   Startbyte   |    Adresse    |  Funktion | Quantität Bytes |     Daten     |    LCR    |    Ende    |
|:-------------:|:-------------:|:---------:|:---------:|:---------:|:---------:|------------|
|    :      |    2 Bytes     |    2 Bytes   |    2 Bytes | n Bytes  |   2 Bytes |    CR LF   |

**Response in unserer Übung:**

|   Startbyte   |    Adresse    |  Funktion | Quantität Bytes |     Daten     |    LCR    |    Ende    |
|:-------------:|:-------------:|:---------:|:---------:|:---------:|:---------:|------------|
|        :      |       10      |    04     |      02         |   .........   |     ..    |    13 10   |

##### Startbyte

Damit Server/Client wissen wann eine neue Request/Response beginnt wird als erstes Byte ein `:` gesendet.

##### Adresse

Adresse damit Server und Client die Request zuordnen können.

##### Funktion

Der Function code gibt an was der Server mit der Request machen soll.
In unserem Fall der Function Code 4 der für **read input register** steht.

#### Quantität

Gibt an wie viele Datenbytes zurückgesendet werden, bzw wie viele Bytes die Response enthält.

##### Daten

Um den Temperaturwert dem Client zu senden stehen uns 16 Bit zur verfügung. Um diese 16 Bit optimal nutzen zu können nutzen wir folgende Kodierung:
Die ersten 8 Bit stehen für den vollen **°C-Wert** und die anderen 8 Bit für die Kommerzahl.
Mit dieser Konfiguration sind Temperaturwerte von **127,996°C** bis **- 128.0°C** möglich.

**Schema:**

Das Schema konnten wir selber aussuchen. Um ein optimales Verhältniss zwischen Genauigkeit und Zahlenweite erreichen verwenden wir:

|    8 Bit    |    8 Bit    |
|:-----------:|:-----------:|
| Ganze Zahl  | Kommerzahl  |

##### LCR

Um den LCR zu berechnen werden alle Bytes nach dem `:` bis zum LCR zusammengezählt (overflow zulässig)
und dann mit *-1* multipliziert.

Kann erst beim senden der Daten berechnet werden.

##### Ende

Damit Server/Client wissen wann eine Request/Response endet werden am Ende `13 10` gesendet *(für carriage return und line feed)*.
