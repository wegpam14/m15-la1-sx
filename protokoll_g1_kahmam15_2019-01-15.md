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
* **2. [Modbus over serial line](#mosl)**
* **3. [Telegramm](#telegramm)**
   * *3.1 [Request](#request)*  
   * *3.2 [Response](#response)*  
* **4. Programme**

 
___
  <a name="modbus"></a>
### 1. Modbus 
Das Grundkonzept hinter dem Modbus ist es über verschiedene Schnittstellen 
Wir wenden Modbus an, da man bei jeglichen anderen Bus-Systemen nicht wirklich "offen" Informationen zur Verfügung stellen.
  

<a name="feldbusse"></a>
#### 1.1 Feldbus-Systeme
  Geräte die Aktoren, Sensoren echzeitfähig verbinden (Prozessrechner) nennt man **Geräte der Feldebene** oder **Feldbusse**.  
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
  - Eine Alternative zum Feldbus ist eine sogenannte **"proprietäre Schnittstelle"** (Bussystem). Proprieätar = "Eigenkreation", daher kann es nicht mit anderen Systemen verbunden werden, jedoch bezieht es geringen Aufwand.
  
<a name="realisierung"></a>
#### 1.2 Realisierung

* [Präprozessor]:   
Präprozessorbefehle beginnen immer mit einem "**#**" und enden nicht mit einem Semikolon (#include <stdio.h>, #define ...). Präprozessordateien werden "**Header-Dateien**" (* .h) gennant, da sie im Kopf der C-Datei stehen.  
  
**Unterschied zwischen "" und <> bei dem #include:**  
<a name="serverClient"></a>
#### 1.2 Server-Client System

* [Präprozessor]:   
Präprozessorbefehle beginnen immer mit einem "**#**" und enden nicht mit einem Semikolon (#include <stdio.h>, #define ...). Präprozessordateien werden "**Header-Dateien**" (* .h) gennant, da sie im Kopf der C-Datei stehen.  
  
___ 
<a name="mosl"></a>
### 2. Modbus over serial line

![Makefiles](http://new.c-howto.de/wp-content/uploads/2017/04/Makefiles.gif)  
Das sogenannte "[maketool]" benötigt eine "[Makefile]" (Textdatei), dieses tool übersetzt nur das Erforderliche. Es wird in der Makefile meist ein "Cleaner" eingebaut, der dazu dient alle vom Compiler erzeugten Datei zu löschen. Dies wird zum Beispiel mit dem Befehl **``-rm *.o``** gemacht.  
**-rm**: Es wird "gezwungen ausgeführt  
***.o** : alle Dateien mit der Endung .o  

___
<a name="telegramm"></a>
### 3. Telegramm

<a name="request"></a>
#### 3.1 Request

* [Präprozessor]:   
Präprozessorbefehle beginnen immer mit einem "**#**" und enden nicht mit einem Semikolon (#include <stdio.h>, #define ...). Präprozessordateien werden "**Header-Dateien**" (* .h) gennant, da sie im Kopf der C-Datei stehen.  

<a name="response"></a>
#### 3.2 Response

* [Präprozessor]:   
Präprozessorbefehle beginnen immer mit einem "**#**" und enden nicht mit einem Semikolon (#include <stdio.h>, #define ...). Präprozessordateien werden "**Header-Dateien**" (* .h) gennant, da sie im Kopf der C-Datei stehen.  
    
___



#### 3.1 Aufbau

#... Kommentare(comments)  
Ziel: Abhängigkeit  
Darunter mit echtem Tabulator->Kommando1...  
  
Bsp:  

![Makefile](https://github.com/HTLMechatronics/m15-la1-sx/blob/kahmam15/Makefile.jpg)  
**Ue03:** ... Target (Ziel)  
**main.o LCD.o log.o** ... dependencies (Abhängigkeiten)  
**gcc -o Ue03 main.o LCD.o log.o** ... commands (auszuführende Befehle)  

#### 3.2 Maker

**Wie arbeitet der "Maker":**  
1)Holt sich die Makfile  
2)Wenn es ein Target gibt versucht er es zu machen (falls kein/e Target/Datei vorhanden ist gibt er eine Mitteilung an den 
Benutzer aus)  
3)Schaut ob diese Abhängigkeiten als Ziele vorhanden sind  
4)Schaut auf den Zeitstempel: Wenn der Zeitstempel einer Datei nicht dem "alten" Zeitstempel entspricht erfordert der Maker eine Übersetzung  
  
Priorität: "Erster Target"  



___
### 4. Programme

**main.c:**  
![main](https://github.com/HTLMechatronics/m15-la1-sx/blob/kahmam15/main_c.jpg)  
In der main.c haben wir in den ersten Zeilen die Headerdateien eingefügt. Im Hauptprogramm befindet sich die im LCD.h deklarierte Struktur **```struct LcdTyp```**. Eine Funktion **```logMain()```**, deklariert in log.h folgt darauf. Die letzte Funktion **```show()```** wurdde in LCD.c deklariert. Damit die main.c auch funktionieren kann müssen die Äbhangigen Headerfiles eingebunden sein!  
  
**LCD.*:**  
![LCDh](https://github.com/HTLMechatronics/m15-la1-sx/blob/kahmam15/LCD_h.jpg)  
In dieser Datei (LCD.h) haben wir ein **```#ifndef```**, **```#define```** und **```#endif```** verwendet um zu verhindern, dass der Compiler die Struktur nicht doppelt sieht (Vermeidung einer Doppeldefiniton)!  
  
![LCDc](https://github.com/HTLMechatronics/m15-la1-sx/blob/kahmam15/LCD_c.jpg)  
  
**log.*:**  
![logh](https://github.com/HTLMechatronics/m15-la1-sx/blob/kahmam15/log_h.jpg)  
Erneute Vermeidung der Doppeldefinition
  
![logc](https://github.com/HTLMechatronics/m15-la1-sx/blob/kahmam15/log_c.jpg)  

___
### 5. neu erlernte Befehle

**```echo "Text"```** - Gibt einen Text im Terminal aus  
**```echo $?```** - Fragt den Rückgabewert des letzten Prozess ab  
**```make```** - Führt, falls vorhanden, eine Makefile im aktuellen Verzeichnis aus  


[Präprozessor]: https://de.wikipedia.org/wiki/C-Pr%C3%A4prozessor
[Compiler]: https://de.wikipedia.org/wiki/Compiler
[Assembler]: https://de.wikipedia.org/wiki/Assembler_(Informatik)
[Linker]: https://de.wikipedia.org/wiki/Linker_(Computerprogramm)
[GNU-Projekt]: https://de.wikipedia.org/wiki/GNU-Projekt
[Richard Stallman]:https://de.wikipedia.org/wiki/Richard_Stallman
[maketool]:https://de.wikipedia.org/wiki/Make
[Makefile]:http://www.c-howto.de/tutorial/makefiles/
