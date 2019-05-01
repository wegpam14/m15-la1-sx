 # 4. Protokoll	
 - Name: Lara Hofer
 - Datum, Ort: 08. Jänner 2019, AUT Labor Kaindorf
 - Gruppe: 1
 - Anwesend: Breitenthaler, Fischer, Grebien, Hofer, Hörmann, Kahr
 - Abwesend: -

## Inhaltsangabe

 1. Übersetzungsverhältnis in C
 
[1.1] Wie funktioniert ein Übersetzungsverhältnis in C?

[1.2] Konvertieren in die Maschinensprache

[1.3] Was ist GNU

[1.4] Das GNU Projekt

 2. Makefile
 
[2.1] Allgemeines

[2.2] Kompilieren der Quelltext Datei

[2.3] Compiler und Linker

[2.4] Ausschnitte der einzelnen Programme

 3. Wichtige Begriffe

## Übersetzungsverhältnis
#### Wie funktioniert ein Übersetzungsverhältnis in C?
Allgemein spricht man bei einem Übersetzungsverhältnis von der Erstellung einer Quelltextdatei (auch Source Code genannt).
- Ein Beispiel dazu wäre eine main.c Datei
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

![enter image description here](https://www.tutorialspoint.com/de/compiler_design/images/language_processing_system.jpg)

#### Was ist GNU?  

![GNU](https://upload.wikimedia.org/wikipedia/commons/thumb/3/39/Official_gnu.svg/220px-Official_gnu.svg.png)

GNU ist ein unixoides Betriebssystem. Das bedeutet, dass es eine Zusammenstellung aus vielerlei Programmen ist: Anwendungen, Bibliotheken, Extras für Entwickler, sogar Spielen. Die Entwicklung von GNU begann im Januar 1984 und ist als das *GNU-Projekt* bekannt. 

Das Programm in einem unixoiden System, was Rechnerressourcen zuteilt und die Hardware anspricht, wird als _Betriebssystemkern_ bezeichnet. GNU wird häufig mit einem Systemkern namens *Linux* genutzt. Die Kombination des GNU-Systems mit dem Linux-Kern ist das *GNU/Linux-Betriebssystem*. GNU/Linux wird von Millionen genutzt, obwohl es viele fälschlicherweise _„Linux“_ nennen.

#### Das GNU Projekt

Das [GNU Projekt](https://de.wikipedia.org/wiki/GNU-Projekt) wurde von Richard Stallman mit dem Ziel gegründet, ein offenes, unixähnliches Betriebssystem zu schaffen, das sicherstellt, dass die Endbenutzer die Freiheiten haben, es verwenden, untersuchen, verbreiten (kopieren) und ändern zu dürfen. Software, deren Lizenz diese Freiheiten garantiert, wird Freie Software (Free Software) genannt, GNU ist in diesem Sinne _frei_. 

![Richard Stallman](https://upload.wikimedia.org/wikipedia/commons/thumb/a/a8/Richard_Stallman_at_CommonsFest_Athens_2015_2.JPG/295px-Richard_Stallman_at_CommonsFest_Athens_2015_2.JPG)

## Makefile

#### Allgemeines

Makefiles sind Beschreibungsdateien für das Programm "make". Damit kann 
man Compiler, Linker und andere Tools (Avrdude, ...) so aufrufen, dass 
Abhängigkeiten berücksichtigt werden (zB. .c -> .o -> exe -> srec -> 
flashtool)

#### Kompilieren der Quelltext Datei

Das Kompilieren von Quelltext-Dateien kann mit dem Programm *make* gesteuert werden. Dies ist vor allem dann sinnvoll, wenn es sich um ein großes Projekt handelt bei dem die Kompilierung aus vielen einzelnen Schritten und Abhängigkeiten besteht. Die einzelnen Schritte können zum Beispiel separate Kompilierungen oder andere Dateioperationen wie Kopieren und Löschen sein. Abhängigkeiten können zum Beispiel bedingte Kompilierungen sein. Diese Schritte und Abhängigkeiten werden in ein Makefile zusammengefasst, welches dann vom Programm *make* verarbeitet wird.

#### Compiler und Linker

Hier sehen wir eine Veranschaulichung der Verwendung von Makefiles – mehrere Dateien tragen zum kompilierten Programm bei. Quelltext-Dateien werden vom Compiler in Objektdateien bzw. Programmmodule übersetzt. Der Linker verbindet die Programmmodule zu einem Programm.


![Makefiles](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoflam15/data/makefiles.png?raw=true)


#### Makefile erstellen

Zum nachvollziehen des obigen Beispiels erstellt man die drei Dateien *main.c*, *lcd.c* und *log.c* mit beliebigen C-Code, Funktionsnamen sollten sich aber nicht in die Quere kommen. Dazu schreiben wir jetzt als vierte Datei noch das Makefile, diese trägt immer den Namen *makefile*.

Im Makefile werden sogenannte Ziele definiert, auch *target* genannt, welche mit einem Doppelpunkt dargestellt werden. Das erste Ziel ist immer das Hauptziel, wir finden es hier in der ersten Zeile: ue03 besteht aus den Objektdateien *main.o*, *lcd.o* und *log.o*. Darunter findet mit *gcc* die Kompilierung dieser Dateien statt; die Ausgabe erfolgt in die Datei *ue03*. Darunter sind noch die benötigten Ziele für die Objektdateien, zum Beispiel wird *main.o* aus *main.c* erstellt. Der Compiler wird hierbei mit dem Parameter *-c* gestartet, d.h. es wird nur kompiliert und nicht gelinkt. Das Linken geschieht im Hauptziel.

Wichtig ist hier, dass die Compiler-Aufrufe mit einem Tabulator eingerückt werden müssen.

![Makefile](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoflam15/data/Makefile1.png)

Das Makefile speichern wir mit dem Namen *makefile* im gleichen Verzeichnis wie die Quelltext-Dateien. Ein Aufruf des Programms *make* genügt. Hier sehen wir die Bildschirmausgabe zu den folgenden Aktionen:

1.  Aufruf von *make clean*
2.  Aufruf von *make*
3.  Verzeichnis-Inhalt nach *make* mit Objektdateien und Programm-Datei

![Aufruf make](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoflam15/data/make.png)

#### Ausschnitte der einzelnen Programme
*main.c*

![main.c](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoflam15/data/main_c1.png)

Am Anfang des main.c Programmes werden die Header Dateien eingebunden. Wir mussten auch die Dateien *lcd.h* und *log.h* einbinden, da wir im Programm die Funktionen *logMain()* (aus der Datei log.h) und *show()* (aus der Datei lcd.h) benutzten. Zusätzlich befindet sich im Hauptprogramm eine Struktur, die auch im lcd.h deklariert wurde.

*log.c*

![log.c](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoflam15/data/log_c1.png)

*log.h*

![log.h](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoflam15/data/log_h1.png)

*lcd.c*

![lcd.c](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoflam15/data/lcd_c1.png)

*lcd.h*

![lcd.h](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoflam15/data/lcd_h1.png)

Nicht zu vergessen: Um ein doppeltes deklarieren in einer Struktur zu vermeiden muss *#endif* am Schluss eingebunden werden. Sons tretet die Fehlermeldung *ifndef* (not defined) auf.


## wichtige Begriffe


`nano`

Ein einfacher Editor, der die Bearbeitung von Dateien in einem Terminal bzw. auf der Konsole erlaubt.

`make`

Um das Programm zu kompilieren.

`make clean`

Das Bereinigen ist notwendig, weil make bereits kompilierte Programmteile erkennt und nicht neu kompilieren würde. Dieser Vorgang erfolgt mit make clean.

`echo $?`

Gibt einen Text auf der Konsole aus. ("printf" der Shell)

`-c`

Der Quellcode wird nur kompiliert, aber noch nicht gelinkt (neue Endung oft „.o“)

`-o`

Bestimmt den Namen der Ausgabedatei (Standard: „a.out“)

`cd ue03`

Wechselt in das angegebene Verzeichnis, in diesem Fall ue03. ("change directory")

`mkdir`

Legt ein neues Verzeichnis an.

`rm`

Löscht Dateien und Verzeichnisse. ("remove")




