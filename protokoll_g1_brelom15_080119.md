# Protokoll 4 (08.01.2019)

Name: Breitenthaler Lorenz  
Klasse: 4ahme  
KNR: 1  
Gruppe: 1

---
## Inhalte

[**1. Übersetzungsvorgang in C**](#1-übersetzungsvorgang-in-c)  
[**2. Übersetzung mit Make**](#2-make)  
[**3. Ablauf der Übung**](#3-ablauf-der-übung)  

--- 

## 1. Übersetzungsvorgang in C

### 1.1 Theoretische Grundlagen

Die Übersetzung des in C programmiertem Quelltext in eine von der CPU lesbaren sprache ist in mehrere Schritte unterteilt.

Convertieren in die Maschinensprache:  
1. Preprozessing (der C-Quelltext wird in Prozessoranweisungen umgeschrieben)  
2. Compiler (Erzeugt eine Assembler Quelltext Datei)  
3. Assembler (erzeugt aus dem Assembler Quelltext eine Objectdatei)  
4. Linker (weißt die Adressen zu und das Programm ist ausführbar)  


_Compiler:_GNU Compiler, Visual C/C++ Compiler;

### 1.2 Praktische Umsetzung

In unserem Beispiel haben wir den gcc Compiler unter Ubuntu benutzt. Dieser wird für gewöhnlich mit der Terminalanweisung `gcc`
gestartet. Dahinter wird anschließend noch eine Option und der Name des Quelltextes angegeben (bsp: `gcc -E main.c`).
Wenn der Befehl ohne option ausgeführt wird Kompiliert der compiler das Vorliegende Programm mit allen Schritten auf einmal durch.
Um nun aber alle Schritte einzeln durchzuführen sind verschiedene Optionen nötig welche im Manual des `gcc` Befehls einzulesen sind.
1. Um das Preprocessing durchzuführen muss der Befehl `gcc -E main.c` ausgeführt werden. Somit wird aus der main.c eine main.pp Datei.  
2. Für die Transformation in den Assembler Quelltext muss der Befehl `gcc -S main.c` ausgeführt werden um die main.s Datei zu bekommen.  
3. Um daraus nun die Objektdatei zu erhalten muss der Befehl `gcc -c main.c` ausgeführt werden um die main.o Datei zu erhalten.

---
## 2. Make

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
```c
#include <stdio.h>
#include "lcd.h" // lagert die explezierte Deklaration in eine externe Datei
#include "log.h"

int main () {

	struct LcdTyp typ = init();
	logMain("Program gestartet");
	printf("LCD Sn %d vom Hersteller %s", typ.sn, typ.hersteller);

	printf("Hallo Welt \n");
	show("Grias Di");

	return 0;
}
```

In der main.c Datei werden in den ersten 3 Zeilen die Headerdateien eingebunden, danach folgt das Hauptprogtramm. In diesem befindet sich ein Struktur welche in lcd.h deklariert wurde. Außerdem befindet sich eine Funktion logMain() welche in log.h definiert wurde und eine Funktion show() welche in lcd.c deklariert wurde. Um diese Funktionen in der main.c zu benutzen müssen beide Dateien in dem Header der main.c Datei mit eingebunden werden. 

**lcd.c:**
```c
#include <stdio.h>
#include "lcd.h"
#include "log.h"

struct LcdTyp init() {
	printf("lcd.c init aufgerufen \n");

	struct LcdTyp rv = {123456, "Limits"};
	logLcd(rv);
	return rv;
}

void show (char s[]) {
	printf("lcd.c show: %s \n", s);
}
```
**log.c:**
```c
#include <stdio.h>
#include "lcd.h"

void logLcd( struct LcdTyp typ) {
	printf("logLcd: %s %d\n",typ.hersteller, typ.sn);
}

void logMain(char text[]) {
	printf("logMain: %s\n", text);
}

```

**lcd.h:**
```c
#ifndef LCD_H // wenn LCD_H nicht deffiniert ist wird der code ausgeführt
#define LCD_H // beim zweiten durchlauf wird LCD_H deffiniert und der code nicht ausgeführt

//expliziete Deklaration
struct LcdTyp init ();
void show (char s[]);

struct LcdTyp {
	int sn;
	char hersteller [20];
};

#endif
```
Da eine doppeltes deklarieren einer Struktur zu einem Fehler führt, wird mit dem Befehl "#ifndef" und "#enfif" überprüft ob die lcd.h Datei schon einmal aufgerufen wurde.

**log.h:**
```c
#ifndef LOG_H
#define LOG_H

#include "lcd.h"

void logLcd( struct LcdTyp typ);
void logMain(char text[]);

#endif
```

**Makefile:**
```make
ue03: main.o lcd.o log.o
	gcc -o ue03 main.o lcd.o log.o

main.o: main.c lcd.h log.h
	gcc -c main.c

lcd.o: lcd.c lcd.h log.h
	gcc -c lcd.c

log.o: log.c log.h lcd.h
	gcc -c log.c

#clean reinigt / löscht unnötige datein
clean:
	echo "Alle zuvor erstellten datein werden gelöscht" # Ausgebetext
	-rm main.o # - bricht das Programm nicht ab wenn ein Fehler auftritt
	-rm *.o
	-rm ue03
```
