# Protokoll 4 (08.01.2019)
Name: Fischer Maximilian  
KNr.: 2  
Klasse: 4AHME  
Gruppe: 1  
___
### Übersicht

In dieser Einheit lernten wir, wie mehrere C-Quelldatein miteinander verknüpft werden können.

1. Übersetzungsvorgang C
1. Make
    1. Makefile
    1. Problem mit mehreren Headerdateien
1. Übung
___

## **1** Übersetzungsvorgang C

Eine Quelldatei (z.B. main.c) muss mithilfe eines Texteditors erstellt werden. 

**Präprozzesor**:
Der Präprozessor löst Präprozessorbefehle in der Quelldatei auf und ersetzt diese durch die jeweilige Funktionalität.

**Compiler**:
Der Compiler übersetzt die Bitketten zu Assembler.

**Assembler**:
Der Assembler erzeugt danach eine Objektdatei.

**Linker**:
Ersetzt im Objectcode die Adressen, sodass das Programm danach ausgeführt werden kann.

![Bild: Übersicht eines Übersetzungsvorganges](http://nerdyelectronics.com/wp-content/uploads/2017/07/GCC_CompilationProcess.png)

In unserer Übung haben wir den **gcc** genutzt.
Wenn der Befehl (`gcc <datei>`) ohne weitere Optionen eingegeben wird erzeugt
der Compiler eine ausführbare Datei.

Um die Schritte einzeln durchzuführen, können verschiedene Optionen verwendet werden:

- Nur Prokompiler: `gcc -E <datei>`
- Nur Assembler: `gcc -S <datei>`
- Nur Objektdatei: `gcc -c <datei>` - *erzeugt main.o*

___

## **2** Make

make ist ein Build-Management-Tool, welches genutzt wird um ein Projekt zu kompilieren.

Das durchführen eines *Builds* mit make hat mehrere Vorteile.

Einer der größten Vorteile besteht darin, dass das kompilieren von großen Programmen
sehr beschleunigt wird, da nur die Quelldateien kompiliert werden die seit dem letzten Vorgang verändert wurden.

### **2.1** Makefile

Der Syntax des Makefiles sieht wie folgt aus:

```
# Comments
Target: Dependencies
	Command
	Command

Target: ..
```

**Vorgehensweise von make:**

Wenn bei dem Aufruf des Kommandos `make` ein Makefile im aktuellen Verzeichnis gefunden wird
beginnt das Tool automatisch das oberste Ziel im Makefile zu builden.

Um ein bestimmtes Ziel aufzurufen kann `make <target>` verwendet werden.

- Zuerst werden die Abhängigkeiten des Ziels überprüft
- Falls kein Ziel mit dem Namen der Abhängigkeit im Makefile vorhanden ist, wird nach einer Datei mit dem Namen gesucht.
- Ist eine Datei vorhanden wird der Zeitstempel mit dem darüberliegenden Ziel verglichen.
- Ist die Quelltextdatei älter als das Ziel, wird das Ziel ignoriert und nicht erneut kompiliert

### **2.2** Probleme mit mehreren Headerdateien

Da es zu einem Fehler kommt wenn eine Headerdatei zweimal eingebunden wird,
sollte jede Headerdatei **ifndef**, **define** und **endif** verwenden um sicherzustellen,
dass diese nicht mehrfach eingebunden wird.

Als Beispiel die *log.h*:

**log.h**
```c
#ifndef LOG_H
#define LOG_H

#include "lcd.h"

void logLcd(struct LcdTyp type);

void logMain(char text[]);

#endif //LOG_H
```

Wenn das Headerfile zum ersten mal eingebunden wird ist **LOG_H** nochnicht definiert, deswegen
springt der Präprozessor in den if-block. In diesem wird dann **LOG_H** definiert. Wird die Headerdatei erneut
eingebunden so ist **LOG_H** schon definiert und der if-block wird ignoriert.

### Best-Practice

Ein **best-practice** für das Verwenden von define um Headerdatein nur einmal einzubinden
ist folgenden Pattern zu verwenden. Er stellt sicher, dass zwei Headerdatein nicht den gleichen Wert beim define nutzen.

`#define __<FILENAME>_H_<UUID>__`

Im Fall von der log.h in unserem Beispiel würde dann folgendes define genutz werden:

`#define __LOG_H_79057761_16D6_478A_BFBC_BBF17BD3E9B9__`
___
## **3** Übung

Als Übung haben wir ein kleines Programm geschrieben bestehend aus:

- main.c
- lcd.c & lcd.h
- log.c & log.h
- Makefile

**Makefile**
```
ue03: main.o lcd.o log.o
	gcc -o ue03 main.o lcd.o log.o

main.o: main.c lcd.h log.h
	gcc -c main.c

lcd.o: lcd.c lcd.h log.h
	gcc -c lcd.c

log.o: log.c lcd.h log.h
	gcc -c log.c

clean:
	echo "Alle erzeugten Dateien werden gelöscht"
	-rm *.o
	-rm ue03
```

Das `-` vor den beiden Kommandos unter dem Ziel `clean` bewirken, dass **make**
bei einem auftetenden Fehler nicht automatisch den Vorgang beendet,
sondern den Fehler einfach ignoriert und weitermacht.

Das Ziel `clean` bewirkt, dass alle Objektdatein und das Programm aus dem Verzeichnis gelöscht werden.

**main.c**
```c
#include <stdio.h>
#include "lcd.h"
#include "log.h"

int main(){

	struct LcdTyp typ = init();

	logMain("Programm gestartet");
	printf("LCD %d vom Hersteller %s\n", typ.sn, typ.hersteller);
	printf("Hallo, guten Morgen!\n");
	show("Kleiner Test;)");

	return 0;
}

```

**log.c**
```c
#include "lcd.h"
#include <stdio.h>

void logLcd(struct LcdTyp typ){
	printf("logLcd: %s %d\n", typ.hersteller, typ.sn);
}

void logMain(char text[]) {
	printf("logMain: %s\n", text);
}
```

An diesem Beispiel ist schön zu erkennen, dass in beiden Datein *(main.c und log.c)* die **lcd.h** eingebunden wird
und es beim Kompilationsvorgang zu keinem Fehler kommt! Hurray! :)

Der Rest der Datein ist nicht allzu relevant, kann aber im Repository angesehen werden.
