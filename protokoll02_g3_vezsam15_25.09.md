# Protokoll2

 
Name: Sarah Vezonik   
Datum: 25.09.2018


**Quellcodedatei**

Quelltext oder auch Quellcode genannt , ist in der Informatik der für Menschen lesbare, in einer Programmiersprache geschriebene Text eines Computerprogrammes. Abstrakt betrachtet kann der Quelltext für ein Programm auch als Software-Dokument bezeichnet werden, welches das Programm formal so exakt und vollständig beschreibt, dass dieses aus ihm vollständig automatisch von einem Computer in Maschinensprache übersetzt werden kann. 

**History**

In der Bash ist es möglich, die zuletzt eingegebenen Befehle mit den Pfeiltasten ( ↑ / ↓ ) durchzublättern oder zu durchsuchen. Dies vereinfacht die Bedienung in der Praxis enorm.

Als Standardwert werden die letzten 500 Befehle gespeichert. Einstellen lässt sich dieser Wert mit einem Editor in der Datei ~/.bashrc. Mit dem Eintrag HISTSIZE=2000 wird die History z.B. auf 2000 Befehle erweitert.


**Assembler**
Als Assembler bezeichnet man ein Programm das zum Entwickeln von Anwendungsprogrammen in Maschinensprache dient. Dabei werden die einzelnen Maschinenkommandos durch leicht einprägsame Symbole, die sogenannten Mnemoniks dargestellt. Die Programmierung mit einem Assembler ist weitaus komfortabler als die direkte Eingabe des Maschinencodes. Durch die symbolische Adressierung entfällt bei nachträglichen hinzufügen oder entfernen von Anweisungen das zeitaufwendige manuelle anpassen der einzelnen Adressen, da dies vom Assembler übernommen wird. Ein zusätzlicher Vorteil ist, das er das implementieren von Bemerkungen ermöglicht, wodurch der Quellcode übersichtlicher wird. Programme die in einer Assembler Sprache formuliert sind, sind nicht sofort lauffähig, da der Quellcode erst umgewandetlt bzw. assembliert werden muss um lauffähig zu sein. Dies geschieht mit Hilfe eines Assemblierer. Um den assemblierten Code zurückzuübersetzen benötigt man einen Disassembler. Zu den Sonderformen gehört der Makro- sowie der Cross-Assembler. Assembler unterscheiden sich je nach verwendeten Prozessortyp, da für jeden Prozessortyp ein spezieller Befehlssatz und somit ein spezieller Assembler existiert, der genau auf den prozessor-spezifischen Befehlssatz zugeschnitten ist. 

**Alias**

Alias definiert Kurznamen (Aliase) für Befehlsaufrufe. Alias ist als Shell-Builtin
bei vielen Shells integriert, unter anderem bei der Bash, der Standard-Shell unter
Ubuntu.
Ein Alias ist eine Funktion mit der mehrere Unix-Kommandos, oder ein Unix-Kommando
mit mehreren Optionen, durch einen neuen Befehl ersetzt werden können. Es wird
benutzt, um Zeit zu sparen und weniger zu tippen.

**Präprozessor, Compiler und Linker**

Ein klassischer C-Compiler besteht aus drei Teilen: Einem Präprozessor, dem eigentlichen Compiler, und einem Linker:

1. Der Präprozessor bereitet einerseits den Quellcode vor (entfernt beispielsweise Kommentare und Leerzeilen); andererseits kann er mittels der im nächsten Abschnitt näher beschriebenen Präprozessor-Anweisungen Ersetzungen im Quellcode vornehmen.
1. Der Compiler analysiert den Quellcode auf lexikalische oder syntaktische Fehler, nimmt gegebenenfalls Optimierungen vor und wandelt schließlich die aufbereiteten Quellcode-Dateien in binäre Objekt-Dateien (Endung: .o) um.
1. Der Linker ergänzt die Objekt-Dateien um verwendete Bibliotheken und setzt die einzelnen Komponenten zu einem ausführbaren Gesamt-Programm zusammen.

![Compiler](http://www.c-howto.de/wp-content/uploads/2017/04/Compiler.gif)


**Präprozessor-Anweisungen**

Der Präprozessor lässt sich im Wesentlichen durch zwei Anweisungen steuern, die jeweils durch ein Hash-Symbol # zu Beginn der Anweisung gekennzeichnet sind und ohne einen Strichpunkt abgeschlossen werden.
```javasript
#include <stdio.h>
#include <math.h>
#define MAXGR 100
```
**Shell**
In der Informatik bezeichnet man als Shell die Software, mittels derer ein Benutzer mit einem Betriebssystem interagiert – eine Mensch-Maschine-Schnittstelle. Während „Kernel“ den innersten Kern eines Betriebssystems bezeichnet, bezeichnet „Shell“ (englisch für „Schale“, „Hülle“ oder „Außenhaut“) dessen äußerste Schicht und damit jene Schnittstelle (englisch Interface) auf die ein Benutzer trifft.

Shells arbeiten entweder mit:

1. einer Kommandozeilen-Schnittstelle (englisch command-line interface, CLI ) oder
    einer grafischen Benutzer­schnittstelle (englisch graphical user interface, GUI ),

1. abhängig von Art und Zweck des Betriebssystems. Damit ist es möglich, Kerneldienste zu nutzen und sich über Systemkomponenten zu informieren oder sie und andere Programme zu benutzen. 

![Shell](http://physik.uni-graz.at/~cbl/Unix/contents/imglocal/kernel.gif)

## Übersetzung von C Programmen

* Quellcodedatei(main.c)  
**Compiler**
* Objektdatei .obj (Maschinensprache)  
**Linker**
* fertiges Programm (Bibliotheken)   
 
1.  Quelldatei  
**Präprozessor**
1.   Präprozessor Quellcode
1.  Assemblerquelltext  
**Assembler**
1.  Objectcode(Maschinenbefehle)  
**Linker**
1.  fertiges Programm   


**GNU – C – Compiler**
 Open Source Compiler
1.  gratis
2. jeder kan ihn verwenden
3. sollte man etwas am Compiler verändern muss man es veröffentlichen 

ein anderer Beispiel hingegen:
Microsoft Visual C/C++:
- kostenpflichtig

## Terminal

sarah@sarah-VirtualBox:~$

* sarah → Benutzername
* sarah-VirtualBox → System

## Übungsbeispiel

```javasript
#incude <stdio.h>
int main()
{
printf("Hallo, Guten Morgen\n");
return 0;
}
``` 


## manuelles Kompilieren

Kompilierung:

gcc main.c **-E**→  -Preprozessieren  
gcc main.c **-S** → -Kompilieren  
gcc main.c **-c** → -Assemblieren  
gcc main.c **-o** → -Objekt Datei erstellen     

## Befehle

**hexdump -C**  → Anzeigen des Codes auf der Konsole in Hexadezimal

**gcc main.c** → main.c ausführen

**ll** → Liste erscheint

**./a.out** → Programm starten
 
**| less** → "less" ist ein Pager zum Anzeigen von (Text-) Dateien auf der
Kommandozeile

**| grep** → Mit grep lassen sich Dateien nach bestimmten Textstücken durchsuchen.
Die Suchmuster werden "regular expressions" (auf Deutsch: regulärer Ausdruck)
genannt. Sie sind vielfältig einsetzbar, und werden nicht nur von grep verwendet.
zb. *gcc -E main.c |grep*

**| tail** → Zeigt die letzten Zeilen einer Datei an
zb. *gcc -E main.c |tail*

**gcc --version** → aktuelle Version abfragen

**cd** → change diractary
 wechselt in einen anderen Ordner 
 
**Absolut**: genauer Platz z.b /home/schueler/folder  
**Relativ:** von der Position abhängig /Schreibtisch

**pwd** → print working directary
 gibt das aktuelle Verzeichnis aus

**ls** → list
 gibt die Daten und das aktuelle Verzeichnis aus

**which** → Anzeige der Datei, die bei Eingabe eines Befehls ausgeführt wird
 
**man** → Ausgabe der Handbuchseite zu einem Befehl oder einer Anwendung
("manual")

**[optinal]** → sobald ein Wort in eckigen Klammern steht, ist es optional

**Q** → mit Q beendet man das Handbuch
 
**echo $0** → zeigt in welcher Shell man sich befindet

**echo$PS1** → Bildschirm anpassen
 zb.  Benutzernamen abkürzen 


**whoami** → "Wer bin ich?" sagt wer du bist.









