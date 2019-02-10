# Protokoll 5 (05.02.2019)

![](https://www.koerbler.com/neuigkeiten/wp-content/uploads/2013/03/htl-kaindorf.jpg)  
Name: Korrenn Marwin  
Klasse: 4aHME  
KNR: 7  
Gruppe: 2

---
## Inhalte
[Kernel](##kernel)  
   [Kernelmodul](###kernelmodul)   
[Erweiterung der Übung](##erweiterung-der-übung)  
   [Dateiauszüge](###dateiauszüge)  
   [Resümee](###resümee)  


## 1. Kernel  

Der Kernel ist der wichtigste Teil des Betriebssystems und man könnte ihn auch als Programm beschreiben der die anderen Programme managed. Er wird in kurzen Abständen abgedated damit das Betriebssytem mit der Hardware aktuell bleibt. Das heißt die Treiberdateien werden aktualisiert.  

### i. Kernelmodul  
*"Ein Kernel-Modul (kurz „LKM“ für englisch: „loadable kernel module“) ist ein spezielles Computerprogramm, das im laufenden Betrieb in den Kernel eines Betriebssystems geladen und wieder daraus entfernt werden kann."*  
Quelle: [Wikepedia](https://de.wikipedia.org/wiki/Kernel-Modul)  

![](https://upload.wikimedia.org/wikipedia/commons/thumb/8/8f/Kernel_Layout.svg/1200px-Kernel_Layout.svg.png)
Zeigt die Aufgabe des Kernels.  

---
## 2. Erweiterung der Übung  

### i. Auszüge  
**main.c:**
```c  
#include <stdio.h>
#include "lcd.h"
#include "log.h"

int main(){

   printf("Guten Morgen");
   lcd_init();
   log_init();
   struct LogRecord msg = {"main.c", "Start..."};
   log_log(msg);
   show("Mal schauen...");

   return 0;
}
```

In der main.c Datei werden in den ersten 3 Zeilen die Headerdateien eingebunden, danach folgt das Hauptprogtramm. In diesem befindet sich die Funktionen *lcd_init()* und *show()* welche in **lcd.c** deklariert wurden und eine Funktion *log_init()* welche in **log.c** deklariert wurde. Um diese Funktionen in der **main.c** zu benutzen müssen beide Dateien in dem Header der **main.c** Datei mit eingebunden werden. Außerdem wird ein im **log.h** definierter *struct* angelegt und mit der Funktion *log_log()* ausgegeben.  

**lcd.c:**
```c
#include <stdio.h>
#include "log.h"

void lcd_init(){
   printf("LCD: init\n");
   struct LogRecord msg = {"lcd.c", "init"};
   log_log(msg);
}

void show (char text[]){
   printf("show: %s\n", text);
   struct LogRecord msg = {"lcd.c", "show"};
   log_log(msg);
}

void showLog(struct LogRecord r){

}
```

**log.c:**
```c
#include <stdio.h>
#include "log.h"

void log_init () {
   printf("LOG: init\n");
}

void log_log (struct LogRecord r) {
   printf("LOG: record %s: %s\n", r.src, r.message);
}
```
In den beiden Quelldateien werden die Logiken hineinprogrammiert die mit der main.c Datei zusammengefügt werden sollen.   

**log.h:**
```c
#ifndef LOG_H
#define LOG_H

struct LogRecord {
   char  src[10];
   char  message[50];
};

void log_init();
void log_log(struct LogRecord r);

#endif //LOG_H
```

**lcd.h:**
```c
#ifndef LCD_H
#define LCD_H

#include "log.h"

void lcd_init();
void show(char text[]);
void showLog(struct LogRecord r);

#endif
```
In den Headerdateien werden die Funktionen bekanntgegeben damit der Compiler weiß dass es die definierten Funktionen bereits gibt.  

**Makefile:**
```make
a.out: main.o lcd.o log.o
	gcc main.o lcd.o log.o

main.o: main.c lcd.h
	gcc -c main.c
#lcd.h kann nicht compeliert werden

lcd.o: lcd.c log.h
	gcc -c lcd.c

log.o: log.c log.h
	gcc -c log.c

clean:
	-rm a.out
	-rm *.o
#damit trotz Fehler trotzdem weiter gemacht wird
```
Im Makefile wird programmiert mit welchen Abhängigkeiten die verschiedenen Ziele erfüllt werden müssen.  

### ii. Resümee  
Neu gelernt haben wir die Befehle:
```c
#ifndef LCD_H
#define LCD_H
...
...
#endif
```
Sie sorgen dafür das eine Headerdatei nur einmal eingefügt wird. Damit kann man Headerdateien einbinden so oft man möchte und es ist sichergestellt, dass sie nur die notwendige Anzahl (meistens einmal) eingebunden wird. Man muss also nicht mehr darüber nachdenken ob etwas doppelt eingebunden oder deklariert wird.  

---
