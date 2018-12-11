# Protokoll 4
**Mercedes Wesonig**
**Protokoll 4
4.12.2018**

In dieser Einheit lernten wir, wie wir mehrere C-Programme miteinander verknüpfen konnten. Ziel der Aufgabenstellung war es, auf Funktionen verschiedener Programme zuzugreifen. 

## Wichtige Begriffe und Vorgänge

### C-Programm übersetzen

![Bild](https://www.google.at/search?q=c+programm+%C3%BCbersetzen&rlz=1C1GCEU_deAT819AT820&source=lnms&tbm=isch&sa=X&ved=0ahUKEwiN3q3T75XfAhXNy4UKHeMZBsYQ_AUIDigB&biw=1536&bih=723#imgrc=wfQXmJdVSVsJYM:)

Im Gegensatz zu früher, haben Programme sehr kurze Übersetzungszeiten.

### Makefile
*make* (englisch für machen, erstellen) ist ein Build-Management-Tool, das Kommandos in Abhängigkeit von Bedingungen ausführt.  Genutzt wird es beispielsweise, um in Projekten, die aus vielen verschiedenen Dateien mit Quellcode bestehen, automatisiert alle Arbeitsschritte (Übersetzung, Linken, Dateien kopieren etc.) zu steuern, bis hin zum fertigen, ausführbaren Programm. make ist jedoch so flexibel ausgelegt, dass es auch beliebige andere Aufgaben steuern kann, bei denen die zeitliche Abhängigkeit von Dateien eine Rolle spielt. 

Um eine neue Steuerdatei zu erstellen, benutz man den Befehl ```make```.

**Anordnung:** 
 Ziel: 
 Abhängigkeiten  
 Tabulator -> Kommando
 Tabulator -> (weitere Kommandos)  
 ...  
 Ziel 2:  
 -> ..

**Wichtig!**  --> Tabulator! (keine Spaces) 
### Neuen Reiter erstellen

Um schneller und übersichtlicher arbeiten zu können, öffnen wir in der Konsole ein zweites Fenster zum hin und her skipen. Einen sogenannten Reiter.

**Befehl:**
`strg + shift + enter`
 
### Wichtige Befehle

```>nano main.c```     --> Neues C
```>nano Makefile``` --> Makefile öffnen
```>ll``` --> Verzeichnis anzeigen
```>./ue04.elf``` --> Programmstart/Programm ausführen
.exe (Windows)  
.elf (Linux,  ist jedoch nicht unbedingt erforderlich)
```>make``` --> Bauen
```>clean``` --> Zurücksetzen
rm *o -> (remove, alle .o Dateien)  
rm *elf -> (alle ausführbaren Dateien)
**Wichtig!**  Verzeichnis entleeren (Zustand vor dem bauen zurücksetzen)
```strg + l``` --> Bildschirm löschen

### Doppelte Namengebung
Als Übungszwecken erstellten wir in der monitor.c und in der lcd.c eine Funktion test(). In der main.c werden dann die Headerdateien eingebunden. Der Linker weiß dann nicht welche Funktion gemeint ist. Es wird ein Fehler ausgegeben.
Mit verschieden Namen wie zb *monitor_test()* und *lcd_test()* kann dieses Problem gelöst werden.

### Andere Variablen einfügen
Mit dem Schlüsselwort `extern` sagt man dem Linker, dass er die Variable wo anders suchen soll. 

**Beispiel:**
`extern int lcd counter`
 
## Aufgabenstellung

Es sind drei Programme zu schreiben, die miteinander verknüpft werden. Die *main.c* ist das Hauptprogramm. Sie soll sich aus den beiden anderen Programmen, *lcd.c* und *monitor.c*, und Funktionen aus diesem Programm ausführen.

### Programm 1:
**main.c**

Die main.c ist das Hauptprogramm. In diesem Programm sollen alle Funktionen aus den anderen Programmen ausgeführt werden.

Zuerst wird einmal ein Verzeichnis erstellt, in welches die Dateien gespeichert werden. Der Name des Projektes lautet *ue.04*.

**Programm:**
```java
#include <stdio.h>    
     
int main(){  	    
printf("Programmstart\n);  	    
return 0;    
}
```

Nach erstellen von **Programm 2** führen wir eine Funktion in diesem Programm aus:
```java
#include <stdio.h>    

void startMonitor(int speed);

int main(){  	    
printf("Programmstart\n); 
startMonitor(); 	    
return 0;    
}
```

Würden wir die Funktion oben nicht nochmal hinschreiben, könnte er sie nicht finden und würde eine Fehlermeldung ausgeben.
Um sowas einfacher und übersichtlicher zu machen, erstellen wir eine Headerdatei um diese Funktionen einfach einzubinden. 

Das Programm lautet dann folgender Maßen:
```java
#include <stdio.h>    
#include "monitor.h"

int main(){  	    
printf("Programmstart\n); 
startMonitor(); 	    
return 0;    
}
```
Ebenfalls werden die Funktionen der *lcd.c* Datei auf die gleiche Weiße eingebunden.


### Programm 2:
**monitor.c**

Das zweite Programm heißt *monitor.c* und soll Funktionen enthalten, welche in *main.c* ausgeführt werden.

**Programm:**
```java
#include <stdio.h>    
     
void startMonitor(int speed){  	    
printf("StartMonitor speed=%d\n);  	       
}
```

Makefile Datei wie gehabt ergänzen mit `monitor.o` !!
**Wichtig**!  main. c Datei fehlt, da sie schon übersetzt wurde!

### Programm 3:
**lcd.c**

**Programm:**
```java
#include <stdio.h>

void startLcd(){  	    
printf("startLcd\n");       
} 
      
void checkLcd (chart text[]){  	    
prinft("checkLcd -> %s \n", text);     
}
```
Auch in diesem Programm fügten wir noch einige Funktionen hinzu.

### Headerdatei:
**monitor.h**
```java
 void startMonitor(int speed)
```
**lcd.h**
```java
 void startLcd();    
 void checkLcd (char text[]);
```
Im Laufe der Einheit fügten wir auch alle anderen benötigten Funktionen hinzu.

Manchmal war es auch nötig .h Dateien in anderen .h Dateien einzufügen.
**Wichtig!**  Makefile mit lcd.o und lcd.h ergänzen!

Mit dem Befehl `#ifndef` kann man abfragen ob etwas schon mal definiert worden ist (if nicht defeniert) 
