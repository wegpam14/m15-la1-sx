
# Protokoll-2  
## Thema: Terminal 
**Professor**: SX    
**Übungsdatum:** 26.09.2018   
**Author, Kat. Nr:** Winter M, 18  
**Anwesend:** Vollmaier, Vezonik, Wesonig, Winter T.   
**Abwesend:** Wegl
- - -  
## Übersicht  
#### 1. Übersetzuzngsvorgang von C-Programmen  
##### 1.1 Einzelne Schritte
##### 1.2 Der Compiler
#### 2. Das Terminal
##### 2.1 Allgemein
##### 2.2 Wichtige Befehle
_ _ _
  
## 1. Übersetzuzngsvorgang von C-Programmen  
Der Weg von einer Quellcodedatei bis zu einem funktionierenden Pogramm geschiet jedes  
mal über die gleiche Reihenfolge, jedoch kann man die Reihenfolge auch unterbrechen wenn man dies möchte.  
**Blockdiagramm zur erklärung:**  

![alt text](https://www.bilder-upload.eu/thumb/c8841e-1538417759.jpg)  
### 1.1  Einzelne Schritte  
 **1.1.1 Die Quellcodedatei**  
 Als erstes muss man die Grundlage für ein C Programm schaffen, dies ist die Quellcodedatei.  
 Diese Datei wird meistens mit Hilfe einer Entwicklungsumgebung erstellt, jedoch haben wir in der  
 letzten Einheit gelernt, wie wir einen Quelltext auch mit einfachen Hilfsmitteln erstellen können,  
 wie zum Beispiel dem Terminal.  
   
   **1.1.2 Der Preprozessierte Quellcode**  
   Der Präprozessor der Sprache C führt gewisse Änderungen am Programmtext durch,  
   bevor der eigentliche C-Compiler das Programm übersetzt. Zum Beispiel ersetzt er Kommentare  
   durch Lehrzeichen oder führt die include-Befehle durch.  
     
   **1.1.3 Assemblerquelltext**  
   Nachdem der preproz. Quellcode mit dem Compiler kompiliert wurde, entsteht ein Assemblerquelltext,  
   welcher dann mithilfe des Assemblers in einen Objektcode umgewandelt wird.  
     
   **1.1.4 Objektcode**  
   Der Objektcode ist eine Ansammlung von bereits fertigen Befehlen die eine Maschine verstehen kann,  
   jedoch kann ein Mensch mit diesen Befehlen nicht mehr viel anfangen.  
     
   **1.1.5 Fertiges Programm**  
   Nachdem ein Objektcode erstellt wurde kann nun der Linker seine Arbeit verrichten. Er bindet alle Dateien  
   aus der Bibliothek ein und macht aus dem Objektcode ein fertiges, funktionierendes(solange der Mensch keinen   
   Fehler gemacht hatt) und ausführbares Programm.  
   
  - - -
### 2. Das Terminal  
#### 2.1 Allgemein  
Ein Terminal, auch Shell oder Kommandozeile genannt, stellt eine textbasierte Ein-/Ausgabe-Schnittstelle für ein Computersystem dar. Auch der Begriff Konsole ist geläufig, bezeichnet aber kein Fenster, sondern einen Bildschirm im Textmodus. Im Terminalfenster können Befehle eingegeben und so das System gesteuert oder Dateien bearbeitet werden.

#### 2.2 Die wichtigsten Befehle  
```
cd  
cd.. 
```   
für change directory, nur "cd" bedeuted zurück zum homeverzeichnis, "cd.." bedeuted eine ebene nach Oben 

``` 
ls
```  
gibt eine liste z.b. im aktuellen verzeichnis aus  
  
```
mkdir/rmdir
```  
Verzeichnis erstellen/löschen  

```
cp
```  
um etwas zu kopieren

oder die Tastenkombination _**Strg + C**_ um den Bildschirm zu löschen!
    

