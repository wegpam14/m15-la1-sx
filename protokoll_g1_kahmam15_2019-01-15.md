![HTBLA Kaindorf](https://upload.wikimedia.org/wikipedia/commons/thumb/3/30/HTL_Kaindorf_Logo.svg/1200px-HTL_Kaindorf_Logo.svg.png)
# 5. Protokoll (15.01.2019)
Name: Kahr Markus  
Klasse: 4AHME  
KNr.: 6  
Gruppe: 1  
___

## Inhalte:  

* **1. [Modbus](#1.-Modbus)**  
  * *1.1 Arten von Feldbussen*
  * *1.2 Realisierung*
  * *1.3 Server-Client System*
* **2. Modbus over serial line**
* **3. Telegramm**
   * *3.1 Request*  
   * *3.2 Response*  
* **4. Programme**

 
___
  
### 1. Modbus

  


#### 1.1 Arten von Feldbussen
  
  Zu Beginn eines Programms wird ein [Quelltext] benötigt (gewöhnliche Textdatei).
  In diesem Quelltext werden Programmieranweisungen geschrieben, welche den Aufgaben des Programms entsprechen.
  Durch Syntaxhervorhebung werden Teile des Quelltextes entsprechend ihrer Funktionalität farblich hervorgehoben, was die Lesbarkeit
  verbessert. Ebenfalls zur Verbesserung der Lesbarkeit halten sich Programmierer meist an eine bestimmte Quelltextformatierung
  (z. B. Einrückung von Unterabschnitten, Groß-/Kleinschreibung …). 

#### 1.2 Realisierung

* [Präprozessor]:   
Präprozessorbefehle beginnen immer mit einem "**#**" und enden nicht mit einem Semikolon (#include <stdio.h>, #define ...). Präprozessordateien werden "**Header-Dateien**" (* .h) gennant, da sie im Kopf der C-Datei stehen.  
  
**Unterschied zwischen "" und <> bei dem #include:**  
  
-Wenn die Variante mit den Anführungszeichen gewählt wird, sucht der Preprozessor die angegebene Datei zuerst im Verzeichnis der Quelldatei. Kann er die betreffende Datei dort nicht finden, dann durchsucht er anschließend all jene Verzeichnisse, die er normalerweise bei der #include-Anweisung mit spitzen Klammern berücksichtigt. Anführungszeichen um den Dateinamen finden im allgemeinen dann Verwendung, wenn Header-Dateien einzufügen sind, die der Programmierer selbst erstellt hat.  
  
-Hingegen sollten Sie den Dateinamen in spitze Klammern setzen, wenn Sie sich auf Header-Dateien der Standardbibliothek beziehen. In diesem Fall erfolgt die Suche in extra angegebenen include-Verzeichnissen. Die Liste der Verzeichnisse, die dabei berücksichtigt werden, muß entweder über ein Optionsmenü bekanntgegeben werden, sofern eine integrierte Entwicklungsumgebung vorliegt, oder in Form einer Umgebungsvariable verfügbar sein. Die Kommandozeilen-Versionen von C-Compilern erwarten die Angaben über include-Verzeichnisse meist in Form eines Arguments.

* [Compiler]:  
Der Compiler verarbeitet die Quelltextdatei in eine maschinenlesbare Sprache (Assembler).  
Befehle für den Compiler sind:  
**``gcc -c``** - Erzeugt eine Objektdatei, auch Objectcode genannt -> **``main.o``**  
**```gcc -S```** - Codiert die Datei in einen Assembler-Quelltext -> **``main.s``**  
**``gcc -E``** -Reprozessiert die Datei -> **``main.s``**  
  
* [Assembler]:  
Der Assembler erzeugt aus der Assembler Quelltextdatei eine/n Objektdatei/Objectcode  
  
* [Linker]:  
Übergibt die Adressen und es ergibt sich schlussendlich ein ausführbares Programm.  

___

### 2. GNU-Projekt

Das [GNU-Projekt] wurde von [Richard Stallman] mit dem Ziel gegründet, ein offenes, unixähnliches Betriebssystem zu schaffen, das sicherstellt, dass die Endbenutzer die Freiheiten haben, es verwenden, untersuchen, verbreiten (kopieren) und ändern zu dürfen. Software, deren Lizenz diese Freiheiten garantiert, wird Freie Software (Free Software) genannt, GNU ist in diesem Sinne frei.
___
### 3. Makefile

![Makefiles](http://new.c-howto.de/wp-content/uploads/2017/04/Makefiles.gif)  
Das sogenannte "[maketool]" benötigt eine "[Makefile]" (Textdatei), dieses tool übersetzt nur das Erforderliche. Es wird in der Makefile meist ein "Cleaner" eingebaut, der dazu dient alle vom Compiler erzeugten Datei zu löschen. Dies wird zum Beispiel mit dem Befehl **``-rm *.o``** gemacht.  
**-rm**: Es wird "gezwungen ausgeführt  
***.o** : alle Dateien mit der Endung .o  


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
