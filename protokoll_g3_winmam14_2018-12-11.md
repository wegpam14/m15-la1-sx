# Protokoll 5
## Thema: Schnittstellen und Feldbus
**Professor:** SX  
**Übungsdatum:** 11.12.2018  
**Author, KNr.:** Winter Matthias, 17  
**Anwesend:** Sarah Vezonik, Alois Vollmaier, Patrick Wegl, Mercedes Wesonig, Winter Matthias, Winter Thomas  

---

## Stundenübersicht
### 1. Schnittstellen
#### 1.1 Echtzeitfähige Schnittstllen
##### 1.1.1 RS485
#### 1.2 Nicht Echtzeitfähige Schnittstellen
##### 1.2.1 Ethernet
### 2. Feldbus
### 3. Normierte Feldbus Protokolle  
### 4. Modbus-Protokoll
#### 4.1 Daten-Modell
#### 4.2 Modbus-ASCII
#### 4.3 Modbus-RTU
#### 4.4 Modbus-TCP  
#### 4.5 LRC

--- 

## 1. Schnittstellen
Eine Schnittstelle dient zur Komunikation verschiedener Systeme oder einzelner Komponenten. Der Austausch von Informationen erfolgt in Form von physikalischen oder logischen Größen (Daten) und kann analog oder digital erfolgen. Eine Schnittstelle wird durch eine Menge von Eigenschaften beschrieben. Wenn diese Eigenschaften mit einer anderen Schnittstelle übereinstimm kann man Komponenten und Module gegeneinander austauschen. Dafür gibt es mehrere verschiedene Standarts.

### 1.1 Echtzeitfähige Schnittstellen
Echtzeitfähigkeit bedeutet, dass die Übertragung von Daten immer verlässlich innerhalb einer festgelegten Zeit erfolgen kann.
Ein Beispiele für eine echtzeitfähige Schnittstelle ist **RS485**.  

### 1.1.1 RS485
Die **RS485-Schnittstelle** ist eine aufwandsarme serielle Schnittstelle für die Datenkommunikation über große Entfernungen. Sie stellt ein bidirektional nutzbares Bussystem dar, das mit bis zu **128 Geräten** an einem Bus betrieben werden kann. Die Datenübertragung erfolgt symmetrisch, massefrei als Spannungsdifferenz (Differenz: < -0,3 V = H, > +0,3 V = L) zwischen den beiden Busleitungen A (invertierte Leitung) und B (nicht invertierte Leitung), so können sich Gleichtaktstörungen auf der Leitung nicht störend auswirken.  
  ![alt text](https://files.elv.com/bilder/elvexpertenwissen/gross/rs485_bus01.jpg)

### 1.2 Nicht Echtzeitfähige Schnittstellen
Keine Echtzeitfähigkeit bedeutet, dass die Übertragung von Daten nicht immer verlässlich innerhalb einer festgelegten Zeit erfolgen kann. Ein Beispiel für eine Schnittstelle die nicht echtzeitfähig ist, ist **Ethernet**(kabelgebunden oder kabellos).

### 1.2.1 Ethernet
Ethernet finded verwendung wenn man sehr große Datenmengen hat die man übertrage muss, es jedoch nicht sehr schlimm ist wenn man keine Echtzeitfähigkeit hat. Ethernet kann aber mit ein paar Modifikationen echtzeitfähig gemacht werden. Hersteller die ihr eigens echtzeitfähiges Ethernet bereits entwickelt haben sind zum Beispiel B&R mit **"Power Link"** und Profinet.

## 2. Feldbus
Feldbus ist ein Bussystem welches zur Komunikation von Sensoren und Aktoren verwendet wird. Wenn mehrere Kommunikationsteilnehmer ihre Nachrichten über dieselbe Leitung senden, dann muss festgelegt sein, **wer** (Kennung), **was** (Messwert, Befehl), **wann** (Initiative), sagt. Hierfür gibt es normierte **Protokolle**.  
## 3. Normierte Feldbus Protokolle  

Anwendung | Protokolle
----------|------
Industire | Profibus, Powerlink, Interbus-5
Automotive | LIN, CAN, Flexray
Gebäudetechnik | KNX,  HomeMatic, LON, CAN, **Modbus**
Industrie 4.0 | Web-Dienst, HTTP-Protokoll, Rest-Server

## 4. Modbus-Protokoll
Das Kommunikationsprotokoll ist ein einfaches zustandsloses Protokoll basierend auf einem Request/Response Prinzip. Grundsätzlich unterscheidet man zwischen **drei** Varianten:   
  
  
* **Modbus ASCII** Rein textuelle byteweise Übertragung von Daten.  
* **Modbus RTU** Binäre byteweise Übertragung von Daten.  
* **Modbus TCP** Übertragung der Daten in TCP Paketen.   

 ![alt text](https://github.com/winmam14/Protokoll-5/blob/master/modbus_general_modbus_frame_png.png)  
 Quelle: LMS Skript

### 4.1 Daten-Modell  
Das Modbus Daten-Modell unterscheidet vier Tabellen (Adressräume) für:  

* **Discrete Inputs**  
Ein Discrete Input ist ein einzelnes Bit, das nur gelesen werden kann.  
Beispiele: ein Taster, ein Endschalter, ...   
  
* **Coils**  
Eine Coil ist ein Bit das gelesen und beschrieben werden kann.  
Der Name stammt vermutlich von der Spule eines Relais.  
Beispiele: ein Relais, eine LED, ...  
  
* **Input Registers**  
Ein Input-Register ist ein 16-Bit Wert der nur gelesen werden kann.  
Beispiele: ein Temperatursensor, ein ADC, die Geräte-ID, ...  
  
* **Hold-Registers**  
Ein Hold-Register ist ein 16-Bit Wert der gelesen und beschrieben werden kann.  
Beispiele: PWM-Einheit, DAC, ...  

### 4.2 Modbus-ASCII
Im ASCII Transmission Mode werden die Frame-Bytes als ASCII-Text versendet. Für die Konfiguration der seriellen Schnittstelle werden standardmäßig nur 7 Daten-Bits verwendet! Geräte dürfen im Bedarfsfall aber auch eine davon abweichende Festlegung haben.   

Jeder Modbus **Serial Line ASCII Frame** hat folgenden Aufbau:  
 ![alt text](https://github.com/winmam14/Protokoll-5/blob/master/modbus_serial_ascii_frame_png.png)  
 Quelle: LMS Skript
 
 #### Unterrichts Beispiel
 
 Die im Unterricht als Beispiel gebrachte ADU ist die Request um einen Sensor auszlesen:  
 ``` 
 :010400000001BA<CR><LF>
 ```  
Die PDU für dieses Beispiel sieht wie folgt aus:  
 ``` 
 0400000001
 ```    

### 4.3 Modbus-RTU
Die Abkürzung **RTU** steht für die **„Remote Terminal Unit“**, also die entfernte Terminaleinheit. Der Zweck von Modbus RTU ist die Übertragung von Daten in einer **binären Form**. Diese Dateien können demnach im Gegensatz zu einer einfachen Textdatei auch nicht-alphabetische Zeichen enthalten. Zwar können solche binären Daten **nicht unmittelbar** von einem Menschen **ausgewertet** werden, da hierfür erst einmal die Umwandlung in ein lesbares Format erforderlich ist, dennoch liegt der Vorteil dieser Methode in dem **guten Datendurchsatz**.  
  
  Wie auch die anderen beiden Protokollvarianten, die des **Modbus ASCII** und des **Modbus TCP**, basiert diese Version ebenso auf dem **Master-Slave-System**. Innerhalb dieses Netzwerks ist es erforderlich, dass jeder Busteilnehmer **eindeutig** eine Adresse zugeordnet bekommt und somit von den anderen Teilnehmern direkt angesprochen und identifiziert werden kann. 

### 4.4 Modbus-TCP  
Die Länge eines **Datenblocks**, der in einem Modbus-Telegramm übertragen werden kann, beträgt **252 Bytes**. Diese Restriktion geht auf die ursprüngliche Definition des Modbus-Protokolls zurück, bei der die Maximallänge eines Telegramms auf 256 Bytes festgelegt wurde. In diesem Telegramm sind folgende Bestandteile enthalten:  

* **Geräteadresse**: 1 Byte  
* **Function Code**: 1 Byte. Mit diesem Function Code wird festgelegt, welche Operation auf Grund eines Requests durch den Server ausgeführt werden soll.  
* **Datensicherung mit CRC**: 2 Bytes    

Aus dieser Betrachtung ergibt sich die Länge des Nutzdatenblocks von 252 Bytes, die auch bei **Modbus/TCP** erhalten geblieben ist. Als Folge hieraus lassen sich Modbus-Requests mit **minimalem Aufwand** von seriellen Übertragungsstrecken über ein Gateway auf Ethernet umsetzen. Die Art und Weise des Zugriffs auf Gerätedaten wird über Funktionscodes gesteuert.  

### 4.5 LRC
Longitudinal Redundancy Check kurz **LRC** ist ein Verfahren zur Erkennung von 1-Bit **Fehlern** bei digitaler Datenübertragung, indem über eine gewisse Anzahl von übertragenen Datenwörtern eine **Prüfsumme** gebildet wird. Diese Prüfsumme wird dann am Ende des **Frames** angehängt und mit versendet. Um die Prüfsumme zu bilden werden alle Bytes des Frames **exklusive** dem Start ':' und dem Ende (CR + LF) mit 8-Bit Additionen **ohne** Berücksichtigung des **Überlaufs** zusammenaddiert und am Ende einem Zweierkomplement unterzogen.
