### 5. Protokoll
Name: **Grebien Markus**  
Klasse: **4AHME**  
Knr: **3**  
Gruppe: **1**


**Inhaltsverzeichnis**
 1. [Bussysteme](#Bussysteme)
	 * [Allgemein](#Allgemein)
 2. [Übungsauftrag](#Übungauftrag)
	 * [Aufbau des Requests](#AufbaudesRequests)
	 * [Aufbau des Response](#AufbaudesResponse)
---
### Bussysteme <a name="Bussysteme"></a>
#### Allgemein <a name="Allgemein"></a>
Man redet von einem Bus, wenn mehrere elektische Geräte miteinander auf der selben verbindung komunizeiren möchten. Über Ethernet ist dies allerdings nicht möglich, weil die echtzeitfähigkeit nicht garanitert ist. Darum wurde es leicht umgeändert und echtzeitfähig gemacht. Je nach Anwendungsgebiet und Firma werden unterschiedliche Bussysteme verwendet:
+ Industriebusse:
	+ Profinet
	+ Interbus
	+ **Powerlink**
+ Autobusse:
	+ LIN
	+ CAN
	+ Flexray
+ Hausautomatisierung:
	+ KNX
	+ **Modbus**
	+ Homemotive
	+ CAN
 
Die Fett makierten sind Open-Sorce, wodurch jeder mit diesen Bussen arbeiten kann, ohne sich zwangsweise kostenpflichtige Programme kaufen zu müssen

``In der Elektrotechnik wird von einem Bus geredet, wenn zwei Bausteine miteinander über mehreren Leitungen kommunizieren``

In unserem Beispiel arbeiten wir mit Modbus.

## Übungauftrag <a name="Übungauftrag"></a>
### Aufgabenstellung:
Wir wollen den Temperatursensor vom Arduino Nano auslesen und dann mithilfe von Modbus an eine SPS übertragen.
Gründe für die Wahl von Mosbus:
+ Weil es Open-Sorce ist
+ Weil nur die Funktionen implementiert werden müssen die man braucht. Dadurch wird der Speicher von einem $\mu$C nicht unnötig voll gemacht. 

Wir wollen ihn mit UART ansteuern. Mithilfe von einem Modbus Gateway kann man von UART auf TCP/IP gehen und damit über das Internet auch dem $\mu$C ansprechen. Außerdem arbeiten wir mit dem ASCII Transmission Mode.

### Aufbau des Requests <a name="AufbaudesRequests"></a>

Damit der Server was macht, muss er von einem Client einen Request bekommen

Name der Datenelemente|Start Byte|Adresse|Funktions Code|Daten|LRC|Schluss
-|-|-|-|-|-|-
Größe der Datenelemente|1 Byte|2 Byte|2 Byte|n Byte|2 Byte|2 Byte
Daten in unserem Beispiel|:|10|04|0001 0001|B9|13 10

##### Start Byte
Ist der Start einer Kommunikation und ist immer ein `:`
##### Adresse
Sagt, an welche Adresse/welches Gerät diese Kommunikation gerichtet ist.
##### Funktion Code
Was man genau machen will. Senden, Empfangen und viele mehr. 
##### Daten
Gibt das zu lesende register und wie viele Register zu lesen sind.
##### LRC 
Die LRC bytes sind eine Absicherug, dass die Übertragung ohne Fehler stattgefunden hat. Die Berechnung der Bytes sieht folgendermaßen aus: es werden alle Bytes zusammengezählt ohne den Start(`:`) und dem Schluss und in ein 8-Bit Register gespeichert, damit alle bit, die Darüber hinausgehen verschwinden. Subdrahiere dann den Wert mit FF hex und addiere 1. Dann hat man den Wert. 
##### Schluss
Ist dazu dar, die Kommunikation zwischen Client und Server wieder zu beenden. 

### Aufbau des Response <a name="AufbaudesResponse"></a>

Nach einem Request vom Client kommt eine Response(Antwort) vom Server.

Name der Datenelemente|Start Byte|Adresse|Funktions Code|Quantität Bytes|Daten|LRC|Schluss
-|-|-|-|-|-|-|-
Größe der Datenelemente|1 Byte|2 Byte|2 Byte|2 Byte|n Byte|2 Byte|2 Byte
Daten in unserem Beispiel|:|10|04|02|xx|xx|13 10

##### Quantität Bytes
Sagt, wie viele Bytes als rückgabe verwendet werden.

#### Genauer auf unser Beispiel bezogen
Mit dem Funktions Code `04` meinen wir, dass es sich hierbei um einen *read input register* handelt.

Mit dem Quantität Bytes haben wir 2 Bytes als Rückgabewert festgelegt. Diese 2 Bytes haben wir dann auf einen Ganzzahlwert und einen Kommazahlwert aufgeteilt.

Die ersten 8 Bit verwenden wir als Ganzzahlspeicher und die letzten 8 Bit als Kommazahlspeicher. Auf diese weise kann man einen Temperaturbereich von -128°C bin ~+128°C übertragen.

