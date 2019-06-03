# Protokoll 4
## Thema: Überstzen von Programmen(MakeTool)
**Professor:** SX  
**Übungsdatum:** 4.12.2018  
**Author, KNr.:** Winter Matthias, 17  
**Anwesend:** Sarah Vezonik, Alois Vollmaier, Patrick Wegl, Mercedes Wesonig, Winter Matthias  
**Abwesend:** Winter Thomas    
  
  
---

## Stundenübersicht
#### 1. MakeTool
##### 1.1 Grundlagen
##### 1.2 Makefile
##### 1.3 Befehle des Maketools
#### 3. Übung
#### 4. Probleme und Lösungen

--- 

## 1. MakeTool  
---
Das MakeTool ist ein Tool welches bei der Übersetzung verschiedener Teilprogramm zu einem fertigen ausführbaren Programm hilft und ist nicht zu einer Programmiersprache gebunden.  
Das MakeTool weis auch automatisch welche Datei neu kompiliert werden muss, falls es nötig ist. Dies geschiet mit Hilfe von **Zeitstempel** die das System der Datei verleit.
### 1.1 Grundlagen  
---
Grundlägend muss man, um das **MakeTool** anwenden und verstehen zu können, wissen wie ein Programm aufgebaut ist und zusammen gebaut wird.
Wichtig ist, dass im **1.Schritt** der Quelltext als ".c"-Datei Gespeichert wird. Danach wird der Quelltext mit dem Compiler **kompiliert** und zum Schluss mit dem **Linker** zusamen gebaut. Heraus kommt eine **ausführbare Datei** mit der Extention ".elf". Das fertige Programm kann auch  aus mehreren Objektdateien zusammen gelinkt werden. Das hat die Vorteile der Wiederverwendbarkeit, der besseren Übersicht und damit es Recourcen sparender ist. Zur Übersicht der einzelnen Schritte siehe das nachfolgende Bild.  
![alt text](http://new.c-howto.de/wp-content/uploads/2017/04/Makefiles.gif)     

### 1.2 Makefile
---
Das MakeTool benötigt ein **Makefile**, welches auch mit dem Namen "Makefile" gespeichert werden muss! Es wird mit einem Texteditor geschrieben und in diesem Makefile müssen dann die **Informationen für das MakeTool** stehen. Die Informationen setzen sich aus Ziele(targets), Abhängigkeiten(dependencies) und Befehle(commands).  
Der **prinzipielle Aufbau** eines Makefiles:  /  Hier noch ein **Beispiel aus der Übung**:
```
Ziel x: Abhängigkeiten             |             main.o: main.c monitor.h lcd.h
*tabulator* Befehl 1               |                     gcc -c main.c
*tabulator* Befehl 2               |
*tabulator* Befehl 3               |
                                   |
Ziel y: Abhängigkeiten             |             clean: 
*tabulator* Befehl 1               |                   -rm *.o
*tabulator* Befehl 2               |                   -rm *.elf
*tabulator* Befehl 3               |
``` 
```-rm``` wird im Makefile beim "Clean" verwendet (falls vorhanden) um Sicher zu stellen, dass auch bei einem Fehler des Programmes der Anfangszustand hergestellt werden kann.
### 1.3 Befehle Des MakeTools
---
```make``` -> führt das MakeTool aus  
```make clean``` -> kann verwendet werden wenn "clean" im Makefile steht  
```./(Name der Datei).elf /.exe``` ->führt die Anwendung aus (nicht nur für das MakeTool, jedoch bei der verwendung sehr Hilfreich)  

### 2.Übung  
---
Am Anfang wollten wir eine Programm schreiben welches "Programm Start" ausgeben soll! Dafür musstn wir einen Quelltext schreiben!
```c
#include <stdio.h>

int main(){
        printf("Programm Start\n");
        return 0;
}  
```
Um mit dem **MakeTool** aus dem Quelltext ein ausführbares Programm zu erzeugen, mussten wir als nächstes ein **Makefile** erzeugen!
```c
ue04.elf: main.o monitor.o lcd.o
        gcc -o ue04.elf main.o monitor.o lcd.o  

main.o: main.c monitor.h lcd.h
        gcc -c main.c
        
        
monitor.o: monitor.c lcd.h
        gcc -c monitor.c
        
lcd.o: lcd.c
        gcc -c lcd.c
        
clean: 
        rm *.o
        rm *.elf
```

Nun kann man das Makefile speichern und danach im Terminal den befehl ```make``` eingeben. Das MakeTool wird aufgerufen und sucht sich anhand des Makefiles die einzelnen Dateien die es braucht um alle Anforderungen des Makefiles zu erfüllen. Falls nur eine Datei verändert wird, so wird nur diese eine Datei neu Kompiliert. Das macht das MakeTool mit Hilfe des Zeitstempels, welchen das System der Datei anhängt.  
  
  
### 3.Probleme und Lösungen
---
**_Variablennamen_:**  
Sie müssen immer **Eindeutig** sein, einerseits um einen Quelltext Übersichtlich zu machen und um Fehler zu vermeiden.    
  
**_Mehrfache definition von Ausdrücken_:**  
Wenn man den Fehler ausgegeben bekommt, dass ein Ausdruck mehrfach definiert wurde, liegt der Fehler meist in der Headerdatei da dort der ausdruck ```#ifndef``` fehlt!  ```#ifndef``` verhindert dieses Problem. Es beinhaltet alles was zwischen ```#ifndef``` und ```#endif``` steht. Dieser Ausdruck darf **NICHT** vergessen werden.!

