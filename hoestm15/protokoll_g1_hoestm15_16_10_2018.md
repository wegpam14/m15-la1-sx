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


__2.2 Aufbau eines Compilern

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
				 - Bei der Programmoptimierung versuch der Compiler oder die CPU das Programm, bzw. den Code einfacher zu machen, indem sie unnötige oder falsche Befehle weglässt. Beispiel: 
![Programmieroptimierung](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoestm15/hoestm15/TabelleCompilerZoomed.png)







 
