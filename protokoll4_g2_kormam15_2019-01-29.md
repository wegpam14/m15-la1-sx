# Protokoll 4 (29.01.2019)

Name: Korrenn Marwin  
Klasse: 4ahme  
KNR: 7  
Gruppe: 2

---
## Inhalte

[**1. Übersetzung mit Make**](#1-Übersetzung-mit-Make)  
[**2. Ablauf der Übung**](#3-ablauf-der-übung)  

--- 


# 1. Übersetzung mit Make

Make ist ein Build-Management-Tool, das Kommandos in Abhängigkeit von Bedingungen ausführt, welche im so genannten Makefile angeführt werden.
Es wird hauptsächlich bei der Softwareentwicklung als Programmierwerkzeug eingesetzt da es den Kompiliervorgang von großen Projekten 
um einiges effizienter gestaltet. Dies wird erreicht indem nur Dateien neu kompiliert werden, welche einer Änderung unterzogen wurden.
Die restlichen werden nicht angerührt sondern nur neu gelinkt.

**Aufbau des Makefiles:** 

```
Ziel(z.B.: ue03) : Abhängigkeit (z.B.:main.o)
    Kommandos(z.B.: gcc -o ue03 main.o)
```

**Vorgehensweise:**  
 - Es wird geprüft ob Abhängigkeiten als Ziel aufgeführt wurden  
 - Falls keine Abhängigkeit mit entsprechendem Namen vorhanden ist, wird eine Datei mit folgendem Namen gesucht.
 - Ist eine vorhanden wird dessen Zeitstempel überprüft  
 - Wenn die Quelltextdatei älter als die kompilierte ist, kann das Ziel Übersprungen werden   
 
Tritt bei der Ausführung eines Kommandos ein Fehler auf, wird der Vorgang abgebrochen und die folgenden Kommandos werden nicht ausgeführt. Dies kann man verhindern indem man ein "-" vor alle Kommandos schreibt bei welchen ein Fehler auftreten kann.   


## 3. Ablauf der Übung

In dieser Einheit sollte ein C-Programm aus mehreren Datein (.c und Headerfiles) zu einem ausführbaren Programm kompiliert werden. 

**main.c:**
´´´c  
#include <stdio.h>
#include "lcd.h"
#include "log.h"

int main(){

   printf("Guten Morgen");
   lcd_init();
   log_init();
   show("Mal schauen...");

   return 0;
}
```

In der main.c Datei werden in den ersten 3 Zeilen die Headerdateien eingebunden, danach folgt das Hauptprogtramm. In diesem befindet sich die Funktionen *lcd_init()* und *show()* welche in **lcd.c** definiert wurde und eine Funktion *log_init()* welche in *log.c* deklariert wurde. Um diese Funktionen in der main.c zu benutzen müssen beide Dateien in dem Header der main.c Datei mit eingebunden werden. 

**lcd.c:**
```c
#include <stdio.h>

void lcd_init(){
   printf("LCD: init\n");
}

void show (char text[]){
   printf("show: %s\n", text);
}
```

**log.c:**
```c
#include <stdio.h>

struct LogRecord {
   char  src[10];
   char  message[50];
};

void log_init () {
   printf("LOG: init\n");
}

void log (struct LogRecord r) {
   printf("LOG: record %s: %s\n", r.src, r.message);
}

```
In den beiden Quelldateien werden die Logiken hineinprogrammiert die mit der main.c Datei zusammengefügt werden sollen.   

**log.h:**
```c
void log_init();
```

**lcd.h:**
```c
void lcd_init();
void show(char text[]);
```
In den Headerdateien werden die Funktionen nur deklariert damit der Compiler weiß dass es die definierten Funktionen bereits gibt.  

**Makefile:**
```make
a.out: main.o lcd.o log.o
	gcc main.o lcd.o log.o

main.o: main.c lcd.h
	gcc -c main.c
#lcd.h kann nicht compeliert werden

lcd.o: lcd.c
	gcc -c lcd.c

log.o: log.c
	gcc -c log.c

clean:
	-rm a.out
	-rm *.o
#damit trotz Fehler trotzdem weiter gemacht wird
```
