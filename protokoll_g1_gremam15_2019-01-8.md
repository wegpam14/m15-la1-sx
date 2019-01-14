### 1. Protokoll
Name: **Grebien Markus**  
Klasse: **4AHME**  
Knr: **3**  


**Inhaltsverzeichnis**
1. Makefile
2. Kompeliervorgang
3. Programmerklärung
4. Wichtige Befehle
---

### 1.  Makefile
	
In einem Makefile stehen die nötgen Informationen, welche zum übersetztenvon Projekten dringend notwendig sind. Diese Datei macht das Entwickeln von großen projekten effizienter. Und bei Änderungen wird nur doe Datei mit den Änderungen Kompiliert und nicht das gesamte Projekt.
Mithilfe von dem befehl `make` wird diese Datei abgearbeitet. Falls man keine zusätzlichen Parameter angibt, wird einfach der Befehl ausgeführt, welcher ganz oben steht. Dies funktioniert so, obwohles keine direkte priorität gibt, allesdings wird eben das, was ganz oben steht als "default target" verwendet.

In unserem Fall Kompiliert er die dateien zusammen und bindet die nötigen `header files` dazu.
	
```Makefile
ue03: main.o lcd.o log.o
	gcc -o ue03 main.o lcd.o log.o

main.o: main.c lcd.h log.h
	gcc -c main.c

lcd.o: lcd.c lcd.h log.h
	gcc -c lcd.c

log.o: log.c log.h lcd.h
	gcc -c log.c

clean:
	echo "alles gelöscht"
	-rm *.o
	-rm ue03
```

Mithilfe von `ue03` Kompelieren wir die Dateien miteindnder.
Um alle Kompilierten Objektdateien(.o) zu löschen, verwenden wir den zusatzparameter `clean`.

### 2. Kompeliervorgang

Der Übersetzungsvorgang von einer c(c++) Datei:
![c_compilersteps]

+ Zuerst hat man eine Quelldatei(main.c)
	+ Beim Start wird diese Datei mit den headerdateien zusammengeführt und zu präprozessoren Quelltext.
	+ Anschließend wird diese Datei mithilfe des Compilers zu Assemblerquelltext
	+ Und zuletzt werden mithilfe vom Linker die Bibliotheksfunktionen miteingebunden und ers wird eine ausführbare Datei.



Wie er kompiliert:
+ Als erstes wird geschaut, ob die Dateien schon existieren oder noch gar nie Kompiliert wurden. 
+ Danach wird geschaut, ob er eine `main.c` findet. Falls keine gefunden werden kann, wird eine Fehlermeldung geworfen.
+ Als nächstes schaut er sich die Zeitstempel an. Falls sie gleich sein sollten,muss er nichts machen, außer es gibt änderungen im Zeitstempel. Egal welche.
+ Zu schluss wird dann aus der `main.c` eine `main.o`.
+ Danach geht das ganze Spielmit der `lcd.c` => `lcd.o` weiter.

Der befehl `include` fügt spezielle dateienoder Befehle aus externen Bibliotheken oder anderen dateien hinzu. 
Wen man etwas in <>  schreibt, handelt es sich um eine Bibliotheksfunktion. Wenn man eine selbst geschreiebene `header file` hinzufügen möchte muss man es mit Anführührungstriche "" machen. Dies kann man auf zwei arten machen:
+ Man kann den Absoluten Pfad angeben
+ Einfach nur den Namen der Datei. Bei dieser Methode sucht er im aktuellem Verzeichnis.

Probleme des Compilers:
+ Tunnelblick
	+ Er sieht nur die momentan zu Kompelierende Datei und sonst nichts. Das kan dazu führen, dass wenn Funktionen in einer `header file` definiert sind, er sie nicht sieht, wenn er z.B. die main.c kompiliert, wodurch ein Fehler ausgegeben wird.
	+ Allerding ist der Kompiler schlau genug, um zu erkennen, ob es sich um eine Funktion handelt oder nicht. Jedenfalls versucht es es mit einer Funktion, weil nach den Namen der Funkton runde Klammern () kommen.
	+ Er nimmt funktionen nit einem `int`  als rückgabewert an. Dies nennt man  implizite Implemetntion.
+ Doppeldefinitionen
	+ Wenn eine `header file`mehr als einmal Implementiert wird kann es zu doppeldefinitionen kommen.
	+ Bei einem `struct` hat das zur Folge, weil es ja nur einmal deiniert werden darf, selbst wenn es zweimal genau gleich aussaut, dass der Compiler sagt, dass er nicht fertig machen kann, weil das `struct` schon definiert ist.

Behebungen:
+ Tunnelblick
	+ Durch Expliziete deklaration in der Datei, wo die Funktion verwendet wird oder in einer eigenen header file.
+ Doppeldefinition
	+ Hierfür gibt es eine spezielle anweisung, welche `#ifdef || #ifndef` und `'endif` zusätzich mit `#define`.
	+ Dafür macht man am Anfang einer header file folgendes: 
	```C
	#infdef LOG.H
	#define LOG.H
	...
	#endif
	```
	+ Dies hat zur folge, dasses bei der ersten Implementierung definiert wird und dann nicht mehr, weil es schon definiert worden ist.

### 3. Programmerklärung

main.c
```C
#include <stdio.h>
#include "lcd.h"
#include "log.h"

//Expliziete Deklaration von Funktionen
//void init();
//void show(char tect [] );

int main () {

	struct LcdTyp typ = init();
	logMain("Programm gestartet");
	printf("Nr: %d, Hersteller: %s", typ.sn, typ.hersteller);
	printf("Hallo\n");
	show("Guten Morgen\n");

	return 0;
}
```
Hier wird als erste ein LcdTyp struct erstellt, welches sich in header files befinet.
Als nächstes bediehnt es sich an der loh.h um eine ausgabe zu machen.
Danach kommen zwei ausgaben, welche die Daten des LCDs ausgeben.
Danach kommt noch ein stumpfer Text.
  

lcd.c
```C
#include <stdio.h>
#include "lcd.h"
#include "log.h"

struct LcdTyp init() {
	printf("lcd.c init() aufgerufen\n");
	struct LcdTyp rv = {123456, "Irgendwas"};
	logLcd(rv);
	return rv;
}


void show (char s[]) {
	printf("lcd.c show %s\n", s);
}
```
Hier wird das LCD initalisiert und zurückgegeben.
Danach noch eine LCD ausgabefunktion.

lcd.h
```C
#ifndef LCD_H
#define LCD_H

struct LcdTyp init();
void show(char text[]);

struct LcdTyp {
	int sn;
	char hersteller[20];
};
#endif
```
Hier werden die Funktionen expliziet Deklariert.
Zusätzlich wird das struct definiert.

log.c
```C
#include <stdio.h>
#include "lcd.h"

void logLcd(struct LcdTyp typ) {
	printf("logLcd: %s %d\n", typ.hersteller, typ.sn);
}

void logMain(char text[]) {
	printf("logMain: %s\n", text);
}
```
Diese Datei ist für diverse Ausgaben zuständig.

log.h
```C
#ifndef LOG_H
#define LOG_H

#include "lcd.h"

void logLcd(struct LcdTyp typ);
void logMain(char text[]);

#endif
```
Diese header file macht einfach nur expliziete Deklarationen.

### 4. Wichtige Befehle:
`history` -> Mit diesem Befehl kann man sich seine Befehlshistory anschauen  
`echo` -> Kann einen Text im Terminal ausgeben  
`nano` -> Öffnen einen Editor, mit welchen man z.B. c oder Makefiles schreiben kann.  
`make` -> Wenn man diesen Befehlausführt, versucht er im derzeitem Verzeichnis eine Makefile zu finden. Falls eine Voranden ist, führt er sie aus.  





[c_compilersteps]: http://fbmathe.bbs-bingen.de/Informatik/C_plusplus/Uebersetzungsvorgang__c++.jpg
