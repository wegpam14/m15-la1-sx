

# Protokoll Nr. 04  ![](https://upload.wikimedia.org/wikipedia/commons/thumb/3/30/HTL_Kaindorf_Logo.svg/300px-HTL_Kaindorf_Logo.svg.png) 
Übungsdatum: **04.12.2018**  
Name: Vollmaier Alois  
KNr.: 14 Klasse: 4AHME  
Gruppe: 3  

Anwesenheit:  

| Anwesend | Abwesend|
| ------------- |:-------------:|
| Vezonik, Vollmaier, Wesonig, Wegl, WinterM., WinterT.    | ---- |

___
### Themen-Übersicht
 - **[1]**-Wiederholung des Kompilierungsvorganges
	 - [1.1] - *Grundlagen* 
 - **[2]** - Einführung in Makefiles
	 - [2.1] - *Grundlagen* 
	 - [2.2] - *Übungsbeispiel* 
	 - [2.3] - *Eigenschaften von Makefiles* 

## [1] Wiederholung des Kompilierungsvorganges
### [1.1] - **Grundlagen** 
**Wie arbeitet ein Compiler?**  

Ein  **Compiler**  arbeitet sich immer komplett durch ein gesamtes Dokument durch. Auf diese Weise unterscheidet sich seine Arbeit vom Interpreter. Bevor der Compiler höheren Quellcode in maschinenlesbare Zielsprache übersetzen kann, muss der Quellcode gescannt und Programmsymbole extrahiert werden. Nach dieser lexikalischen Analyse erfolgt das Parsing. Hierbei wird die syntaktische Korrektheit des Codes überprüft. Anschließend wird die Semantik des Codes ermittelt, um zum Schluss den Zielcode zu erstellen. Fehler im Code versucht der Compiler zu optimieren bzw. auszublenden. Üblicherweise laufen alle Einzelschritte in wenigen Sekunden ab.

Wichtig ist, dass der Compiler trotz Fehler im Code weiterarbeitet. Ansonsten kann der Quellcode nicht in maschinenlesbare Zielsprachen übertragen werden.

**Kompilierungsvorgang:**
`gcc main.c **-E**` |-Preprozessieren  
`gcc main.c **-S**` |-Kompilieren  
`gcc main.c **-c**` |-Assemblieren ---  `objdump--dissasemble-all main.c`  
`gcc main.c **-o**`  |-Object Datei erstellen  
[
![enter image description here](https://camo.githubusercontent.com/7bc9f3cae120ce83427fae67d70539c1b191db6f/68747470733a2f2f696d6167652e6962622e636f2f686a6a4f477a2f3859442e706e67)](https://camo.githubusercontent.com/7bc9f3cae120ce83427fae67d70539c1b191db6f/68747470733a2f2f696d6167652e6962622e636f2f686a6a4f477a2f3859442e706e67)  
_`avr-gcc`  Wird nur für Mikrocontroller verwendet_
## [2] Einführung in Makefiles
### [2.1] - **Grundlagen** 
Das Kompilieren von Quelltext-Dateien kann mit dem Programm **make** gesteuert werden. Dies ist vor allem dann sinnvoll, wenn es sich um ein großes Projekt handelt bei dem die Kompilierung aus vielen einzelnen Schritten und Abhängigkeiten besteht. 

Die einzelnen Schritte können zum Beispiel separate Kompilierungen oder andere Dateioperationen wie Kopieren und Löschen sein. Abhängigkeiten können zum Beispiel bedingte Kompilierungen sein. Diese Schritte und Abhängigkeiten werden in ein Makefile zusammengefasst, welches dann vom Programm **make** verarbeitet wird.
___
![enter image description here](http://new.c-howto.de/wp-content/uploads/2017/04/Makefiles.gif)
Das Bild veranschaulicht die Verwendung von Makefiles – **mehrere Dateien** tragen zur kompilierten Programm bei. Quelltext-Dateien werden vom Compiler in Objektdateien bzw. Programmmodule übersetzt. Der Linker verbindet die Programmmodule zu einem Programm.

Im Makefile werden sogenannte Ziele definiert, auch **target** genannt, welche mit einem Doppelpunkt dargestellt werden. Das erste Ziel ist immer das Hauptziel, wir finden es hier in der ersten Zeile. 

### **Wie ist ein Makefile aufgebaut?**

- **target**: Name der zu erstellenden Datei (.exe oder .o). Das erste Target in einem
	Makefile heißt Goal und wird als default erstellt, wenn nur make aufgerufen wird

- **dependencies**: Dateien, die zur Erstellung des Targets benotigt werden

- **commands**: Kommandos, die zum Updaten des Targets an die Shell weitergegeben werden, falls das 		      Target nicht existiert oder out-of-date ist

- **vor Shell-Kommandos muss ein Tab gesetzt werden - nicht bloß white space**

-   **alle Zeilen, die mit einem Tab beginnen, werden als Kommandos an die Shell geschickt**

-  **Kommentare beginnen mit Hash, der Rest der Zeile wird ignoriert**

-   **Newline-Zeichen sind nicht vernachlässigbar!** Ein langer Eintrag muss mit einem
	Backspace auf zwei Zeilen umgebrochen werden

### [2.2] - **Übungsbeispiel** 

### Code-Makefile:

```c
    ue03.elf: main.o monitor.o lcd.o 	gcc -o ue03.elf  main.o monitor.o lcd.o
    
    main.o: main.c monitor.h lcd.h 	gcc -c main.c
    
    monitor.o: monitor.c lcd.h 	gcc -c monitor.c
    
    lcd.o: lcd.c 	gcc -c lcd.c
    
    clean: 	rm *.o 	rm *.elf
 ```
```
```   
Hier findet mit **gcc** die Kompilierung dieser Dateien statt. Darunter sind noch die benötigten Ziele für die Objektdateien, zum Beispiel wird **main.o** aus **main.c** erstellt. Der Compiler wird hierbei mit dem Parameter **-c** gestartet, d.h. es wird nur kompiliert und nicht gelinkt. Das Linken geschieht im Hauptziel.
### Code-main.c:
```c
    #include <stdio.h>
    #include "monitor.h"
    #include "lcd.h"
    
    void startMonitor (int speed);
    
    int main ()
    {
        printf("Programmstart\n");
        startMonitor(1);
        checkMonitor("main.c");
        checkLcd("main.c");
       
        monitor_test();
        lcd_test();
    
       printf("lcd_counter=%d\n",lcd_counter);
        return 0;
    
    }
   ```  
### Code-monitor.c:
```c
    #include <stdio.h>
    #include "lcd.h"
    
    void startMonitor (int speed)
    {
       printf("startMonitor speed=%d\n", speed);
    
    }
    
    void checkMonitor (char text[])
    {
      printf("checkMonitor -> %s\n", text);
    }
    
    
    void monitor_test() 
    { 
	   printf("test in monitor --> lcd_counter=%d\n", lcd_counter);
    }
   ```  
### Code lcd.c
   ```c
    #include <stdio.h>
    
    int lcd_counter=0;
    
    void startLcd ()
    {
       printf("startLcd\n");
    }
    
    void checkLcd (char text[])
    {
    
	   printf("checkLcd --> %s\n",text);
    
    }
    
    void lcd_test() 
    {
	   printf("test in lcd\n");
	   lcd_counter++;
    }
   ```  
Zum nachvollziehen des obigen Beispiels erstellt man die drei Dateien **main.c**, **monitor.c** und **lcd.c** mit beliebigen C-Code.

***.h Dateien wurden erstellt, da es sich hierbei um einen Funktionshandler handelt!** 
### Headerdatei-monitor.h
   ``` c
    void startMonitor(int speed);
    void checkMonitor(char text[]);
    void monitor_test();
  ```  
### Headerdatei-lcd.h
``` c
    extern int lcd_counter;
    void startLcd ();
    void checkLcd (char text[]);
    void lcd_test();
  ```  
In Summe haben wir nun einerseits unser Makefile & andererseits 3 C-Dateien + 2 Header Dateien  in unserem Projektordner
___
### [2.3] - **Eigenschaften von Makefiles** 

### **Wichtige Eigenschaften von Makefiles müssen erfüllt sein:**

 1. Funktionsnamen müssen eindeutig sein! 
	 In C++ wird dieser Fehler verhindert
 2. Bei Variablen kann man nicht implizit deklarieren!
	 Schlüsselwort "extern"
 3. In unserem Beispiel wird struct 2 mal definiert da es einen import in monitor.h und in main.c gibt
	Um diesen Fehler zu verhindern wird das Schlüsselwort #ifdef verwendet.
	 

### **Beschreibung von clean:**
**clean:**

-   `rm * o`  (remove,alle .o Dateien)
-   `rm * elf`  (alle ausführbaren Dateien)
### **Beschreibung von extern:**
Das Schlüsselwort **extern** deklariert eine Variable oder Funktion und gibt an, dass sie eine externe Verknüpfung hat (Ihr Name ist von Dateien aus sichtbar, mit Ausnahme der Datei, in der sie definiert wurde). Wenn eine Variable geändert wird, gibt **extern** an, dass die Variable eine statische Dauer hat (sie wird zugeordnet, wenn das Programm beginnt, und die Zuordnung wird aufgehoben, wenn das Programm beendet wird). Die Variable oder Funktion können in einer anderen Quelldatei oder später in derselben Datei definiert werden. Deklarationen von Variablen und Funktionen im Dateigültigkeitsbereich sind standardmäßig extern.

### **Beschreibung von #ifdef und #endif:**
Mit **#ifdef** und **#endif** kann man einen Quelltextbereich eingrenzen, der nur kompiliert wird, wenn eine bestimmte symbolische Konstante definiert wurde. Möchte man prüfen, ob eine Konstante nicht definiert ist, verwendet man **#ifndef**. Ein **#else** kann man in einen solchen Block optional auch einfügen, dieser wird dann kompiliert wenn die Bedingung in **#ifdef**, #**ifndef** oder **#if** (siehe unten) nicht wahr ist.

### **Wie erkennt der Compiler ob etwas verändert wurde?**

Mit dem Befehl **touch** lassen sich Zugriffs- und Änderungs-Zeitstempel von Dateien ändern. Existiert die von touch zu ändernde Datei nicht, wird sie neu angelegt. **touch** wird daher häufig auch zum Erstellen leerer Dateien verwendet.

### Was sind *.h Dateien?

Als **Header** -Datei bezeichnet man eine **Datei** die allgemeine **Deklarationen** zur Nutzung einer **Bibliothek** enthält. Header-Dateien gehören im wesentlichen zum Konzept der Programmiersprachen C und C++. Um eine Bibliothek zu nutzen, muss die Header-Datei unter Zuhilfenahme der**Anweisung** #Include in den **Quellcode** eingebunden werden. Header-Dateien sind vor allem an der [**Dateierweiterung  *.h erkennbar. Die bekanntesten Header-Dateien sind die im Lieferumfang von C und C++ - **Compilern** befindlichen Dateien, die Header-Datei STDIO.H (Standard Input Output) und die Header- Datei IO.H (Input Output).


