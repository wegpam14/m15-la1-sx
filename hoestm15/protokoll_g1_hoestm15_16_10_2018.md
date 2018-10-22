 # Protokoll der 2. Einheit (16.10.2018)
  Name: 		Hörmann
  Gegenstand: Labor
  Lehrer: SX
  Klasse: 4AHME
  Gruppe: 1
  ## Inhaltsverzeichnis

 1. Compiler
 2.  Shell
 3.  Linux Terminal-Befehle
 
 ## 1. Compiler
 __1.1  Definition__  
Ein [Compiler](https://de.wikipedia.org/wiki/Compiler) ist ein Programm, das den Quellcode einer gewissen Programmiersprache (z.B. [C](https://de.wikipedia.org/wiki/C_(Programmiersprache)), [C++](https://de.wikipedia.org/wiki/C%2B%2B), [Java](https://de.wikipedia.org/wiki/Java_(Programmiersprache)))  so übersetzt, dass der Computer diese direkt ausführen kann.


__1.2 Aufbau eines Compilers__

Das bauen oder auch programmieren eines Compilers ist in der Informatik ein eigener Fachbereich. Der Bau eines Compilers kann in zwei Bereiche gegliedert werden:

 - __Frontend__ _(auch "Analysephase")_ 
	 - Im Frontend wird der Quellcode analysiert, strukturiert und auf Fehler geprüft. Das Frontend kann nochmal in drei Bereiche gegliedert werden:
		 - __Lexikalische Analyse__
			 - Zerteilt den Quelltext in verschiedene Lexikalische Einheiten ( Schlüsselwörter, Bezeichner, Zahlen, Zeichenketten) um Fehler in Quelltext zu analysieren und deren Position zu bestimmen.			
			   
		 - __Syntaktische Analyse__
			 - Die Syntaktische Analyse Prüft, ob der Quelltext die "Grammatik" (Syntax) der Programmiersprache einhält, wenn er einen Fehler der Grammatik im Quellcode findet, gibt er einen sogenannten [Syntaxfehler](https://de.wikipedia.org/wiki/Syntaxfehler) aus.
		 - __Semantische Analyse__
			 - Die semantische Analyse Überprüft die sogenannte statische [Semantik](https://de.wikipedia.org/wiki/Semantik), das hießt, sie überprüft, ob zum Beispiel eine Variable bevor sie benutzt wird auch deklariert worden ist.
	
 - __Backend__ _(auch "Synthesephase")_
	 - Das Frontend liefert dem Backend einen sogenannten attributierten Syntaxbaum, aus diesem wird nun der Programmcode erstellt. Das Backend kann in folgende Teile gegliedert werden:
		 - __Zwischencodeerzeugung__
			 - Moderne Compiler erzeugen durch den Syntaxbaum einen [Zwischencode](https://de.wikipedia.org/wiki/Zwischencode), dieser Zwischencode ist bereits relativ maschinennah, dies hat den Vorteil, das der Übersetzungsprozess einfacher wird und das die Software unter anderem auch Plattformunabhängig sein kann. 
		 - __Programmoptimierung__
				
			 -  Bei der Programmoptimierung versuch der Compiler oder die CPU das Programm, bzw. den Code einfacher zu machen, indem sie unnötige oder falsche Befehle weglässt. Beispiel: 
![Programmieroptimierung](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoestm15/hoestm15/TabelleCompilerZoomed.png)

		 - __Codegenerierung__
			 - Die [Codegenerierung](https://de.wikipedia.org/wiki/Codegenerator) kann direkt aus dem Syntaxbaum oder auch über den Zwischencode erzeugt werden. Falls die Zielsprache der Generierung die Maschinensprache ist, kann das Ergebnis direkt das ausführbare Programm sein.
![Aufbau eines Compilers
](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoestm15/hoestm15/Aufbau+eines+einfachen+Compilers.jpg)

__1.3 Verschiedene Compiler__ 

 - [GNU Compiler](https://gcc.gnu.org/)
 - [MatLab Compiler](https://www.mathworks.com/products/compiler.html)
 - [Fortran Compiler](http://www.fortran.de/)

__1.4 GNU Compiler__
Der GNU Compiler ist eine Sammlung für Compiler verschiedener Programmiersprachen, darunter sind [C](https://de.wikipedia.org/wiki/C_(Programmiersprache)), [C++](https://de.wikipedia.org/wiki/C%2B%2B), [Objective-C](https://de.wikipedia.org/wiki/Objective-C), [Fortran](https://de.wikipedia.org/wiki/Fortran), [Ada](https://de.wikipedia.org/wiki/Ada_(Programmiersprache)), und [Go](https://de.wikipedia.org/wiki/Go_(Programmiersprache)).
Die erste Version wurde von [Richard Stallman](https://de.wikipedia.org/wiki/Richard_Stallman) am 22. März 1987 veröffentlicht, bis heute ist der GNU Compiler einer der meist genutzten Compiler. ![GNU Logo](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoestm15/hoestm15/gnu-gcc.png)

 _

## 2. Shell

__2.1 Definition__
 Eine [Shell](https://de.wikipedia.org/wiki/Unix-Shell) ermöglicht die text- bzw. kommandobasierte Benutzung des Computersystems und ist vor allem auf unixoiden Systemen anzutreffen. Die Kombinierbarkeit von kleinen, aber leistungsfähigen und flexiblen Kommandozeilenprogrammen ist ein wichtiger Eckpfeiler der Unix-Philosophie. Dies verhilft der Shell, eigentlich ein Programm wie jedes andere, zu einem prominenten Status vor allem bei fortgeschrittenen Anwendern, die mit ihr Routinen automatisieren und permanent ein oder mehrere Instanzen einer Shell für den schnellen Zugriff offen halten. [Quelle](https://wiki.ubuntuusers.de/Shell/)
 
__2.2 Bash (Unix Shell)__
[Bash](https://en.wikipedia.org/wiki/Bash_(Unix_shell)) (Kurz für **B**ourne-**a**gain **sh**ell) ist eine Unix Shell und eine commando basierte Sprache erstellt von [Brian Fox](https://en.wikipedia.org/wiki/Brian_Fox_(computer_programmer)) für das GNU Projekt als freie Software alternative für die Bourne Shell. Sie wurde am 8. Juni 1989 veröffentlicht.

##  3. Linux Terminal-Befehle
__4.1 Befehlsliste__
 
	 gcc --version
Version Überprüfen

	cd..
Auf Übergeordnetes Verzeichnis wechseln 

	whoami
Benutzer abfragen

	man ls
Handbuch für ls Befehle wird geöffnet

	pwd
Fragt aktuelles Verzeichnis ab

	cat/etc/hostname
Hostname abfragen

	man man
Handbuch für "man" Befehle öffnen

	mkdir "Verzeichnisname"
Verzeichnis erstellen

	mv "Verzeichnisname" "Zielverzeichnis"
Verzeichnis in Zielverzeichnis verschieben

	history 
alle Befehle der Vergangenheit abrufen#

	 reset
löschen des Shell Inhalts

	cat "Dateiname"
Inhalt der Datei wird im Terminal ausgegeben

	hexdump "Dateiname"
Inhalt der Datei wird in Bytes ausgegeben
