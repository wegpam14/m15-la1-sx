# **Übersetzung von C Programmen**

## Wie übersetzt man ein C-Programm?
Um ein C-Programm zu übersetzen sind mehrere Schritte notwendig:

![](http://fbmathe.bbs-bingen.de/Informatik/C_plusplus/Uebersetzungsvorgang__c++.jpg)

#### Begriffserklärung:
**Quellcodedatei**
Der Begriff Quellcode bezeichnet in der Informatik einen in einer Programmiersprache verfassten, für Menschen lesbaren Text eines Programmes. Aus abstrakter Sicht ist ein Quellcode ein Software-Dokument, welches das Computerprogramm derart vollständig und exakt beschreibt, dass der Quellcode von einem Rechner automatisch in ausführbare Maschinensprache übersetzt werden kann.

**Objektdatei**
Objektcode ist ein Zwischenergebnis eines Compiler- bzw. Übersetzungsvorgangs von einem Computerprogramm. Einfache Compiler können diesen Schritt überspringen.
Der Objektcode besteht hauptsächlich aus Maschinencode für die Architektur, für die das Programm übersetzt wurde. Er enthält üblicherweise kompakten und vorgeparsten Code und oft benutzte Programmbibliotheken, die dann mit anderen Objektdateien gebunden werden.
Das Format eines Objektcodes ist abhängig von Programmiersprache, Compiler und der Maschine. Nach dem Erstellen von Objektcode erfolgt normalerweise das Linken, welches als Ergebnis das fertige, ausführbare Programm liefert. 

**Präprozessor**
Ein Präprozessor ist ein Computerprogramm, das Eingabedaten vorbereitet und zur weiteren Bearbeitung an ein anderes Programm weitergibt. Der Präprozessor wird häufig von Compilern oder Interpretern dazu verwendet, einen Eingabetext zu konvertieren und das Ergebnis im eigentlichen Programm weiter zu verarbeiten. 

**Compiler**
Ein Compiler ist eine Implementierungsform von Software. Generell geht es beim Compilieren darum, den Quelltext, der mit einer höheren Programmiersprache (zum Beispiel C++, C# oder Java) geschrieben wurde, in Maschinenbefehle umzusetzen. Das bedeutet, die lesbaren Programmierbefehle müssen in weniger komplexe Instruktionen übersetzt werden, damit der Prozessor diese ausführen kann.

**Bibliotheken** 
Die C-Standard-Bibliothek (englisch C standard library) ist die Standardbibliothek der Programmiersprache C. In jeder standardkonformen betriebssystemgestützten Implementierung (hosted environment) von C muss die C-Standard-Bibliothek in vollem Umfang vorhanden sein. Hingegen müssen freistehende Umgebungen (freestanding environment), wie man sie beispielsweise im Embedded-Bereich häufig antrifft, nur eine festgelegte Untermenge der Standardbibliothek anbieten, um standardkonform zu sein. 

**Linker**
Ein Linker ist ein Programm, das (z.B. vom Compiler generierte) Objektdateien mit anderen Objektdateien und/oder Libraries verknüpft. 



## GNU:
* Open Source Compiler
* Dieser Compiler ist gratis und jeder kann ihn für seine Programme verwenden
* Ändert man am Compiler etwas muss man es veröffentlichen ( Open Source)

**Microsoft Visual C/C++:**

* Nicht gratis

Compiler wie **Borland** und **Keil** spielen heute keine große Rolle mehr

**gcc** ist die Abkürzung für **GNU – C – Compiler** 

## Shell
In der Informatik bezeichnet man als Shell die Software, mittels derer ein Benutzer mit einem Betriebssystem interagiert – eine Mensch-Maschine-Schnittstelle. Während „Kernel“ den innersten Kern eines Betriebssystems bezeichnet, bezeichnet „Shell“ (englisch für „Schale“, „Hülle“ oder „Außenhaut“) dessen äußerste Schicht und damit jene Schnittstelle (englisch Interface) auf die ein Benutzer trifft.

Shells arbeiten entweder mit:

1. einer Kommandozeilen-Schnittstelle (englisch command-line interface, CLI ) oder
    einer grafischen Benutzer­schnittstelle (englisch graphical user interface, GUI ),

1. abhängig von Art und Zweck des Betriebssystems. Damit ist es möglich, Kerneldienste zu nutzen und sich über Systemkomponenten zu informieren oder sie und andere Programme zu benutzen. 


## Terminal

* **strg +alt + t** → Terminal öffnen

mercedes@mercedes-VirtualBox:~$ 

* mercedes → Benutzername
* mercedes-VirtualBox → auf welchem System ich mich befinde
* ~$ → Trennzeichen (Normaler Benutzer)
* ~# → Wäre das Trennzeichen für den Superuser

**Optionen:**

* --all
  * lange Option
*  -a 
  * Kurze Option

### Befehle:

* **cd** → change diractary
  * in einen anderen Ordner wechseln
  * mit "cd /" kommt man zb. in das Root-Verzeichnis
  * um ein Verzeichnis zu suchen muss man cd eingeben und a.) zweimal die Tabulatortaste drücken um eine Liste aller Verzeichnisse zu erhalten oder b.) einen Anfangsbuchstaben eingeben und die Tabulatortaste drücken um bestimmte Verzeichnisse zu suchen

**Relativer Pfad:**
*zb. cd Schreibtisch/*

**Absoluter Pfad:**
*zb. cd Home/Schreibtisch*

* **pwd** → print working directary
 * gibt das aktuelle Verzeichnis aus, in dem man sich befindet
* **ls** → list
   * gibt die Daten und das aktuelle Verzeichnis aus
* **which** → Anzeige der Datei, die bei Eingabe eines Befehls ausgeführt wird
*  **type** → "Was ist das?" 
*  **man** → Ausgabe der Handbuchseite zu einem Befehl oder einer Anwendung ("manual")
  * um die Suche zu filter gibt man hinter dem "man" den Begriff ein, zu dem man Information benötigt
 * **[optinal]** wenn etwas in einer eckigen Klammer steht heißt das, dass es optional ist, also dass man es nicht zwangsweiße hinschreiben muss
 * mit einem **g** kommt man zurück zum Anfang der Seite zurück
 * mit einem **G** kommt man zum Ende der Seite
 *  mit **/n** kommt man zur nächsten Position
 * mit **schift+n** hüpft man eine Position zurück
 * mit **Q** beendet man das Handbuch
 * um Begriffe zu suchen gibt man / + den zu suchenden Begriff ein
* **echo $0** → "In welcher Shell befinde ich mich?"
*  **cat~/.bashrc** → Das "*cat*" steht dafür, dass alles was ich ausgeben möchte, in einer Tabelle gebunden wird
*  **echo$PS1** → Mit diesem Befehl kann man den Bildschirm anpassen
   * Zb. kann man den Benutzernamen abkürzen wenn man sich in einem Verzeichnis mit langem Namen befindet
 * **whoami** → "Wer bin ich?" Wenn man in viele Terminals gleichzeitig offen hat, kann man den Überblick recht schnell verlieren! Mit diesem Befehl kann man abfragen wer man jetzt eigentlich gerade ist.


**Verzeichnisse verwalten:**

* **mkdir** → Erzeugung von Verzeichnissen („make directory“)
  * zb. */home$ mkdir 4AHME*
* **rmdir**  → Löschen eines Verzeichnisses („remove directory“)
  * zb. */home$ rmdir 4AHME*
 * Achtung! man kann mit diesem Befehl aus Sicherheitsgründen nur leere Verzeichnisse löschen
* **rm -r** → Damit kann man auch Verzeichnisse löschen in denen sich ein Inhalt befindet
  * Aber Achtung! Man sollte vorsichtig sein um nicht aus versehen Etwas zu löschen was man noch benötigt
*  **mv** → Mit diesem Befehl kann man ein Verzeichnis verschieben ("move")
  * *zb. mv von ... zu ...*
*  **cp** → Mit diesem Befehl kann man ein Verzeichnis kopieren ("copy")
  * *zb. cp von ... zu ...*

## C - Programm

* **nano main.c** → Mit diesem Befehl wechselt man in den Editor. Hier kann man ein C-Programm schreiben. In unserer Übung schrieben wir folgendes Programm als Übungszweck:

```javasript
#incude <stdio.h>
int main()
{
printf("Hallo, Guten Morgen\n");
return 0;
}
```
* Mit **strg + o** wird die Datei gespeichert
* Mit **strg + x** beendet man den Editor
* Mit **strg + r** kann man Dateien öffnen

**Befehle im Terminal:**

* **hexdump -C** → Codierung wird ausgegeben
*  **gcc main.c** → main.c ausführen
*  **ll** → Es erscheint eine Liste. Die Datei a.out* (meistens in grün geschrieben) ist das fertige Programm
*  **./a.out** → Programm starten
*  **| less** → "less" ist ein Pager zum Anzeigen von (Text-) Dateien auf der Kommandozeile unter Linux
  * *zb. gcc -E main.c |less*
*  **| grep** → Mit grep lassen sich Dateien nach bestimmten Textstücken durchsuchen. Die Suchmuster werden "regular expressions" (auf Deutsch: regulärer Ausdruck) genannt. Sie sind vielfältig einsetzbar, und werden nicht nur von grep verwendet.
  * *zb. gcc -E main.c |grep*
* **| tail** → Mit dem Befehl tail lassen sich die letzten Zeilen einer Datei anzeigen. Wird nicht angegeben, wie viele Zeilen angezeigt werden sollen, werden die letzten 10 Zeilen ausgegeben. Werden mehrere Dateien übergeben, so wird die Ausgabe jeder Datei mit einer Kopfzeile versehen. Wird keine Datei angegeben, liest tail von der Standardeingabe.
  * *zb. gcc -E main.c |tail*
* **gcc --version** → Mit diesem Befehl kann man die aktuelle Version der gcc abfragen

**Programme compilieren:**

Mit folgenden Befehlen kann man ein Programm nur bis zu gewissen Stellen compilieren. Diese Befehle kann man auch im Handbuch *(man gcc)* nachschlagen:

* **-E** → Stoppt nach den Präprozessorbefehlen
* **-S** → Stoppt nach der eigentlichen Kompilierungsstufe. Das Programm wird jedoch nicht zusammengebaut
*  **-c** → Kompiliert die Quelldateien, verknüpft sie jedoch nicht

## Mikrocontrollerprogramm 

Um für einen Mikrocontroller ein Programm zu schreiben benötigt man den **avr -gcc** Befehl.

* **man avr-gcc** → Leider gibt es kein eigenes Handbuch. Jedoch sind die meisten Befehle gleich.

Zunächst schrieben wir ein neues Programm für einen Mikrocontroller:
```javasript
#incude <avr/in.h>
int main()
{
DDRB = 0x20;
PORTB = 0x20;
return 0;
}
```
**avr -gcc -mmcu -atmega328p main.c** → Befehl zum Ausführen

Aber Achtung! Das Programm kann selbstverständlich nur am Mikrocontroller ausgeführt werden und nicht am PC!!!

## Wichtige Begriffe und Funktionen 

#### History

* in der History sind alle Befehle die man in den letzten 3 Monaten in der Konsole eingegeben hat gespeichert
*  Der Speicherplatz dafür befindet sich im **.bash_history** Verzeichnis
* mit den Pfeiltasten kann man nach oben und unten switchen und es erscheinen jeweils die letzten Befehle die man eingegeben hat
*  mit dem Befehl **history** erscheint die gesamte History am Bildschirm
* Man muss sehr vorsichtig sein dass man nicht aus Versehen sein Passwort eingibt! Das würde sonst nämlich in dieser Datei gespeichert werden!
  * Hacker suchen deshalb in der History nach solchen Passwörtern. Deshalb sollte man das Passwort aus der History raus löschen wenn man es aus Versehen eintippt.


#### Alias 

Alias definiert Kurznamen (Aliase) für Befehlsaufrufe. Alias ist als Shell-Builtin bei vielen Shells integriert, unter anderem bei der Bash, der Standard-Shell unter Ubuntu. 
Ein Alias ist eine Funktion mit der mehrere Unix-Kommandos, oder ein Unix-Kommando mit mehreren Optionen, durch einen neuen Befehl ersetzt werden können. Es wird benutzt, um Zeit zu sparen und weniger zu tippen. 


#### Assembler
Als Assembler bezeichnet man ein Programm das zum Entwickeln von Anwendungsprogrammen in Maschinensprache dient. Dabei werden die einzelnen Maschinenkommandos durch leicht einprägsame Symbole, die sogenannten Mnemoniks dargestellt. Die Programmierung mit einem Assembler ist weitaus komfortabler als die direkte Eingabe des Maschinencodes. Durch die symbolische Adressierung entfällt bei nachträglichen hinzufügen oder entfernen von Anweisungen das zeitaufwendige manuelle anpassen der einzelnen Adressen, da dies vom Assembler übernommen wird. Ein zusätzlicher Vorteil ist, das er das implementieren von Bemerkungen ermöglicht, wodurch der Quellcode übersichtlicher wird. Programme die in einer Assembler Sprache formuliert sind, sind nicht sofort lauffähig, da der Quellcode erst umgewandetlt bzw. assembliert werden muss um lauffähig zu sein. Dies geschieht mit Hilfe eines Assemblierer. Um den assemblierten Code zurückzuübersetzen benötigt man einen Disassembler. Zu den Sonderformen gehört der Makro- sowie der Cross-Assembler. Assembler unterscheiden sich je nach verwendeten Prozessortyp, da für jeden Prozessortyp ein spezieller Befehlssatz und somit ein spezieller Assembler existiert, der genau auf den prozessor-spezifischen Befehlssatz zugeschnitten ist. 









