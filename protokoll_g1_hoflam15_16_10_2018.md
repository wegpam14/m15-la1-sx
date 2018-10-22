 # 2. Protokoll	
 - Name: Lara Hofer
 - Datum, Ort: 16. Oktober 2018, AUT Labor Kaindorf
 - Gruppe: 1
 - Anwesend: Breitenthaler, Fischer, Grebien, Hofer, Hörmann, Kahr
 - Abwesend: -

## Inhaltsangabe

 1. Übersetzungsvorgang in C
	 1.1 Allgemeines
	 1.2 Kovertierung
 2. Compiler
	 2.1 CNU Compiler
3. Shell
4. Terminal Begriffe

## Übersetzungsvorgang in C
#### Was versteht man unter einen Übersetzungsvorgang?

 - Ein Übersetzungsvorgang ist allgemein gesagt eine Erstellung einer Quelltextdatei (auch Source Code genannt).
 - Ein Beispiel wäre die main.c Datei.
 - Dabei handelt es sich um eine ganz gewöhnliche Textdatei, die Programmanweisungen, die der Sprache C entsprechen, enthält.

#### Konvertieren in die Maschinensprache
 - Preprozessoranweisungen:
	  Sind Anweisungen, welche mit einem # beginnen. Beispiele: #include, #define, #if 
 - Compiler:
	  Erzeugt eine Assembler Quelltext Datei.
 - Assembler:
	  Erzeugt aus dem Assembler Quelltext eine Objektdatei.  (Oject Code) 
 - Linker:
	  Adressen und Programme werden jetzt in ein Ausführendes Programm umgewandelt.
	  ![Konvertierung](https://www.tutorialspoint.com/de/compiler_design/images/language_processing_system.jpg)
 
 #### Beispiele von Programmen, die all jene Sachen beinhalten, die oben genannt wurden:

 - [Gnu Compiler](https://de.wikipedia.org/wiki/GNU_Compiler_Collection)
 - [Visual C/C++ Compiler](https://de.wikipedia.org/wiki/Visual_C++)
 


## Compiler
#### Was ist ein Compiler?
-  = ein Programm, das dazu dient, eine andere Programmiersprache in die Programmiersprache eines bestimmten Computers zu übersetzen
![Compiler](https://www.ilsb.tuwien.ac.at/~pahr/317.530/_images/Compiler.png)
#### GNU Compiler

 *- Allgemeines:*
  - Richard Stallman war der Erfinder des Compilers.
  - Grund: ein offenes, [unixähnliches](https://de.wikipedia.org/wiki/Unixoides_System "Unixoides System") [Betriebssystem](https://de.wikipedia.org/wiki/Betriebssystem "Betriebssystem") zu schaffen, das sicherstellt, dass die Endbenutzer die Freiheiten haben, es verwenden, untersuchen, verbreiten (kopieren) und ändern zu dürfen. Software, deren Lizenz diese Freiheiten garantiert, wird Freie Software (Free Software) genannt, GNU ist in diesem Sinne _frei_.
 
## Shell
#### Was ist eine Shell?
![Shell](https://www.selflinux.org/selflinux/bilder/was_ist_shell_shell_funktionsweise01.png)
Der englische Ausdruck **Shell**, zu Deutsch etwa **Schale** oder **Ummantelung**, drückt diesen Sachverhalt bereits aus. Ist auch sehr gut an dem Bild (oben) zu erkennen.

#### Bash Shell
=(**B**ourne-**a**gain **sh**ell)
- Der Name ist absichtlich mehrdeutig und bedeutet unter anderem „wiedergeborene (born again) Shell“, „wieder (eine) "Bourne-Shell"oder auch aus dem Englischen _to bash_ (schlagen, kritisieren, schlecht machen) bzw. umgangssprachlich „Party/Fete“.
- Diese Shell kann alles andere was die anderen auch können und noch dazu ermöglicht sie, jedem Benutzer eigene Einstellungen, wie eine individuelle Gestaltung der Eingabeaufforderung (Prompt), sitzungsübergreifend zu gestalten.
## Linux Terminal
#### Erklärung wichtiger Befehle
 - **cd  ("change directory")**
*Wechsel des Arbeitsverzeichnisses*
 - **ls -a -l	("list")**
 *Zeigt den Inhalt eines Verzeichnisses an; 
 "-a" bedeutet: listet auch [versteckte Dateien](https://wiki.ubuntuusers.de/Versteckte_Dateien/) und Verzeichniseinträge wie .. und .. auf;
 "-l" bedeutet: gibt die Datei-Informationen in Langform aus*
 - **git clone**
 *clont das Repository, um auf einer eigenen Kopie arbeiten zu können*
 - **git add** 
 *alle Dateien werden im Index aufgenommen*
 - **git push**
 *zum Einfügen vom lokalen Repository in die remote*
 - **git commit -m "..."** 
*Dateien kommen vom Index in das lokale Repository
 Mit den 3 Befehlen wird nachdem es geklont wurde initialisiert*
 - **sudo apt update; sudo apt install build-essential;...**
 *apt... Paketmanagement-System*
 - **whoami**
 *"Wer bin ich?" -> gibt mir meinen Namen aus*
 - **man ls**
 *Man steht für manual.*
 - **mkdir**
 *Somit kommt man ins Verzeichnis.*
 - **cat**
 *Kann man die Syntax angeben*
 - **./a.out**
 Zur Ausführung des Programmes.
- **hexdump "Dateiname"**
*Inhalt der Datei wird in Bytes ausgegeben*

 
















