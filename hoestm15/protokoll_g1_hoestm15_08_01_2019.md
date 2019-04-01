
 # Protokoll der 5. Einheit (15.01.2019)
  Name: 		Hörmann
  Gegenstand: Labor
  Lehrer: SX
  Klasse: 4AHME
  Gruppe: 1
  ## Inhaltsverzeichnis

 1. Bussysteme
 2. Modbus konfiguration
 
 ## 1. Bussysteme
 ### 1.1  Definition
 Bus ist im Grunde eine Abkürzung für das „Binary Unit System“. Dieses System dient innerhalb eines Netzwerkes für die Übertragung von Daten zwischen den einzelnen Teilnehmern.

![Prinzipieller Aufbau eines parralelbussystem](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoestm15/hoestm15/Images/Prinzipielle_Struktur_eines_parallelen_Bussystems.svg.png)


#### Compiler
Der Compiler liest was der Präprozessor  C Datei gemacht hat und produziert eine Objektdatei '.o'.  Diese enthält Maschinensprache die der Linker benötigt um die verschiedenen Funktionen aus den Objektdateien zu Verknüpfen.
![Compiling Prozess](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoestm15/hoestm15/Images/compiling-linking.png)


#### Linker
Der Linker bindet die Objektdatei, die der Compiler erzeugt hat, noch mit "statischen" Funktionsbibliotheken zusammen und erzeugt somit ein ausführbares Programm. 

<img src="https://github.com/HTLMechatronics/m15-la1-sx/blob/hoestm15/hoestm15/Images/1200px-Linker.svg.png" width="300" height="400" />

## 2. Makefile
Das Kompilieren von Quelltext-Dateien kann mit dem Programm **make** gesteuert werden, dies ist sinnvoll wenn das Projekt groß ist und die Kompilierung aus mehreren Schritten und Abhängigkeiten besteht.

#### Makefile erstellen
 
 Im Makefile werden Zeile definiert, sogenannte **Targets**, welche mit einem Doppelpunkt dargestellt werden. Dieses Target ist immer das Hauptziel, neben den Hauptziel steht die Abhängigkeit die erfüllt sein muss, um das Ziel zu erreichen. In den Zeilen unter dem Ziel stehen die Kommandos die das Ziel zu erreichen.

**Makefile:**
```
                  Makefile                                 

ue03: main.o lcd.o log.o
        gcc -o ue03 main.o lcd.o log.o

main.o: main.c lcd.h log.h
        gcc -c main.c

lcd.o: lcd.c lcd.h log.h
        gcc -c lcd.c

log.o: log.c log.h lcd.h
        gcc -c log.c

clean:
        echo "Alle zuvor erzeugten Daten werden gelöscht"  
        -rm *.o
        -rm ue03
```

Im oberen Beispiel ist das Ziel die 'ue03:' neben den Ziel stehen die Abhängigkeiten 'main.o lcd.o log.o'. Unter dem Ziel und der Abhängigkeit steht der auszuführende Befehl, in diesem Fall 'gcc -o ue03 main.o lcd.o log.o'.

Das Makefile wird im gleichen Verzeichnis wie die Quelltext-Dateien gespeichert, der Aufruf des Befehles 'make' genügt.
Falls keine Abhängigkeit vorhanden ist, werden die Befehle des Zieles immer ausgeführt. 

Auch werden beim Makefile die Zeitstempel der diversen Ziele und Abhängigkeiten verglichen, damit das erneute compiling einer berreits aktuellen Datei Verhindert wird.

## 3 Befehle
**main.c:**

```#include <stdio.h>
#include "lcd.h"
#include "log.h"
//Explizite Deklaration von Funktionen

int main() {

        struct LcdTyp typ = init();
        logMain("Programm gestartet");
        printf("LCD SN %d vom Hersteller %s \n", typ.sn, typ.hersteller);

        printf("Hallo, guten Morgen!\n");
        show("Guten Morgen");
 
        return 0;

}

```

In der main.c Datei werden in den ersten 3 Codelines die Headerdateien eingebunden, danach folgt in der main das Hauptprogtramm, in diesem befindet sich ein struct der im lcd.h deklariert ist. Außerdem befindet sich eine Funktion logMain() die im log.h definiert worden ist und eine Funktion show() im Programm, die lcd.c deklariert worden ist. Um diese Funktionen in der main.c zu benutzen müssen beide Dateien in dem Header der main.c Datei mit eingebunden werden.

**log.c**
```
#include <stdio.h>
#include "lcd.h"
#include "log.h"
//Explizite Deklaration von Funktionen

int main() {

        struct LcdTyp typ = init();
        logMain("Programm gestartet");
        printf("LCD SN %d vom Hersteller %s \n", typ.sn, typ.hersteller);

        printf("Hallo, guten Morgen!\n");
        show("Guten Morgen");
 
        return 0;

}

```


**log.h**

```
#ifndef LOG_H
#define LOG_H

#include "lcd.h"

void logMain(char text[]); 
void logLcd(struct LcdTyp typ); 


#endif //LOG_H
```

In der oberen Grafik wird in den Header-Dateien ein #ifndef und ein #endif benutzt, dies dient dazu, dass eine doppeldefinition verhindert wird. 

**lcd.c**

```#include <stdio.h>
#include "log.h"
#include "lcd.h"

struct LcdTyp init() {
        printf(" lcd.c init() aufgerufen\n");
        struct LcdTyp rv = {1234, "LCD"};
        logLcd(rv);
        return rv;
}

void show (char s[]) {
        printf("lcd.c show: %s \n", s);
}

```


**lcd.h**

```#ifndef LCD_H
#define LCD_H


struct LcdTyp init();
void show(char text[]);

struct LcdTyp {
        int sn;
        char hersteller[20];
};

#endif
```


