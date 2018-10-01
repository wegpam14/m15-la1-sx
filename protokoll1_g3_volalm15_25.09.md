
# Protokoll Nr. 02  ![](https://upload.wikimedia.org/wikipedia/commons/thumb/3/30/HTL_Kaindorf_Logo.svg/300px-HTL_Kaindorf_Logo.svg.png) 
Übungsdatum: **25.09.2018**  
Name: Vollmaier Alois  
KNr.: 15 Klasse: 4AHME  
Gruppe: 3  

Anwesenheit:  

| Anwesend | Abwesend|
| ------------- |:-------------:|
| Vezonik, Vollmaier, Wesonig, WinterM., WinterT.    | Wegl |

___
### Themen-Übersicht
 - **[1]**-Terminal Grundbefehle
	 - [1.1] - *Grundbegriffe* 
 - **[2]** - Terminal
	 - [2.1] - *Commands und deren Erklärung* 
 - **[3]** - Manuelles Kompilieren mithilfe der Konsole
	  

## [1] Übersetzungsvorgang von C-Programmen
[1.1] - **Grundbegriffe** 

**Was ist ein Compiler?**  
Ein **Compiler** ist ein Programm, das in einer höheren Programmiersprache wie z.B. Java verfassten **Quellcode in maschinenlesbare Sprache**, den sogenannten Objektcode, Zielsprache oder auch Assemblersprache übersetzt. Man könnte einen Compiler demnach auch als Übersetzer bezeichnen, doch seine Aufgaben sind weitreichender, denn beim Compilen ermittelt das Programm zusätzlich Fehler beim Auslesen des Codes.

**Wie arbeitet ein Compiler?**  
Ein **Compiler** arbeitet sich immer komplett durch ein gesamtes Dokument durch. Auf diese Weise unterscheidet sich seine Arbeit vom  Interpreter. Bevor der Compiler höheren Quellcode in maschinenlesbare Zielsprache übersetzen kann, muss der Quellcode gescannt und Programmsymbole extrahiert werden. Nach dieser lexikalischen Analyse erfolgt das Parsing. Hierbei wird die syntaktische Korrektheit des Codes überprüft. Anschließend wird die Semantik des Codes ermittelt, um zum Schluss den Zielcode zu erstellen. Fehler im Code versucht der Compiler zu optimieren bzw. auszublenden. Üblicherweise laufen alle Einzelschritte in wenigen Sekunden ab.

Wichtig ist, dass der Compiler trotz Fehler im Code weiterarbeitet. Ansonsten kann der Quellcode nicht in maschinenlesbare Zielsprachen übertragen werden.

**Was ist ein Linker?**  
**Linker** helfen den Programmierer, die übersetzten Programme zum Ablauf zu bringen. Die kompilierten Objektprogramme sind noch nicht lauffähig. Da im Quellprogramm verlangte Programmteile, wie z.B. Ein- und Ausgabeprozeduren, hinzugefügt werden müssen, bindet der Linker diesen Objektcode mit externen Bibliotheken zusammen. Ergebnis dieses Binden ist dann das ablauffähige Programm.

**Was ist ein Assembler?**  
**Assembler** ist eine Programmiersprache, welche eine für Menschen bessere, lesbare Repräsentation der Maschinensprache ist. Als _Assembler_ wird nicht nur die Sprache selbst, sondern auch ihr Compile benannt. Übersetzt der Compiler ein Assembler-Programm in die Maschinensprache, so nennt man den Vorgang "_assemblieren_". Den umgekehrten Vorgang nennt man "_disassemblieren_".

**Was ist ein GCC-Compiler**  
Der C-Compiler von **GNU**, _gcc_, ist einer der vielseitigsten und fortschrittlichsten aller verfügbaren Compiler. Anders als andere C-Compiler (zum Beispiel die mit AT&T- oder BSD-Distributionen ausgelieferten oder solche von Drittherstellern) unterstützt _gcc_ alle modernen C-Standards - etwa ANSI-C - sowie viele Erweiterungen, die nur in _gcc_ zu finden sind. Glücklicherweise kann _gcc_ trotzdem zu älteren C-Compilern und älteren Methoden der C-Programmierung kompatibel gemacht werden.
___

**Was ist ein Terminal/Shell/Bash?**

Weil die direkte Kommunikation mit dem Betriebssystem-Kern für einen Benutzer viel zu komplex wäre, ist eine vereinfachte Benutzer-Schnittstelle erforderlich. Neben einer grafischen Schnittstelle wie dem X Window System wird diese Leistung vor allem von einer Shell bereitgestellt. Der englische Ausdruck **Shell**, zu Deutsch etwa **Schale** oder **Ummantelung**, drückt diesen Sachverhalt bereits aus. Die Übersetzung oder Symbolisierung als **Muschel** hat dabei wohl mehr mit Spieltrieb und Anschaulichkeit als mit einem echten technischen Hintergrund zu tun. Jedenfalls lässt sich eine Shell als eine Schicht zwischen Betriebssystem und Benutzer verstehen.

![enter image description here](https://image.ibb.co/hjjOGz/8YD.png)
Während Benutzer, die noch nicht häufig mit Shells in Berührung gekommen sind, den wartenden Eingabeprompt einer Shell als trist und abweisend, ja sogar als Hindernis empfinden mögen, wurden Shells doch mit der gegenteiligen Absicht entwickelt: Sie sollten die tägliche Arbeit vereinfachen und erleichtern.

## [2] Terminal
[2.1] - **Grundbefehle und deren Erklärung** 

**Verzeichnis wechseln**: Über die Eingabe des Befehls "`cd`" wechselt man in das nächsthöhere Verzeichnis.

> [user@linux user1]$  **cd**

**Anzeige des aktuellen Verzeichnisses**: Wenn man nicht mehr weißt, in welchem Verzeichnis man sich gerade befindet, kann man es sich mit Hilfe von "`pwd`" anzeigen lassen.

> [user@linux user1]$  **pwd**

**Inhalte von Verzeichnisse anzeigen**: "`ls`" zeigt alle Dateien an, die sich im momentanen Verzeichnis befinden.

> [user@linux user1]$  **ls**

**ls** [OPTION]… [DATEI]…

**Beispiele für Operatoren:**  

**-a**, **--all**
              Einträge nicht ignorieren, die mit ».« beginnen
              **-A**, **--almost-all**
              Die impliziten Einträge ».« und »..« nicht auflisten
              **-b**, **--escape**
              Bei nichtdruckbaren Zeichen Maskierungen im C-Stil ausgeben
Liste aller Operatoren: [Mirror
](http://manpages.ubuntu.com/manpages/bionic/de/man1/ls.1.html)
___
**Eingabefenster löschen**: Mit dem Befehl "`clear`" räumt man das Eingabefenster auf und löscht alle bisherigen Eingaben.

> [user@linux user1]$  **clear**            


**Handbuch aufrufen**: Über den Befehl "`man`" ruft man eine Handbuchseite mit Informationen zu einem Befehl oder einer Anwendung auf.
> [user@linux user1]$  **man**            
  
  **Verknüpfung von Dateien**: Mit dem Befehl "`cat`" kannst du dir Dateien anzeigen lassen und Inhalte verknüpfen.
> [user@linux user1]$  **cat**    
  ___

  `which`--Anzeige der Datei, die bei Eingabe eines Befehls ausgeführt wird

`mkdir`--**mkdir** steht für **m**a**k**e **dir**ectory und dient zum Anlegen von einem oder mehreren Verzeichnissen.

`rmdir`---**rmdir** steht für **r**e**m**ove **dir**ectory und dient zum Löschen von Verzeichnisse, die leer sind. Mit Hilfe des Befehl "`rm`" lassen sich auch nicht-leere Verzeichnisse löschen.

`mv`---**mv** steht für **m**o**v**e und verschiebt eine Datei, wobei der Befehl teilweise auch zum Umbenennen verwendet wird.

> **mv** [OPTION] QUELLE ZIEL

`cp`---**cp** steht für **c**o**p**y und ist der Befehl zum Kopieren, es können Dateien oder ganze Verzeichnisse kopiert werden.

> cp [OPTIONEN] QUELLE ZIEL
___
**Absolut:** genauer Platz z.b `/home/schueler/folder`  
**Relativ:**  von der Position abhängig `/Schreibtisch`

### Das Zeichen  **"~"**

Oft wird die Kurzform  **~/Ordnername**  verwendet. Die Tilde  **~**  steht für eine Shell-Extension, also quasi eine Abkürzung, die immer auf  **/home/BENUTZERNAME/**  verweist.

### Der Pipe-Operator **"|"**

Der Pipe-Operator leitet die Ausgabe eines Befehls direkt an einen anderen Befehl weiter (anstatt ins Terminal). Damit kann der zweite Befehl das Ergebnis bzw. die Ausgabe des ersten Befehls weiterverarbeiten. Die allgemeine Syntax lautet (man kann natürlich auch mehr als zwei Befehle miteinander verbinden):

> Befehl1 | Befehl2
> 
**Nano** ist ein einfacher Editor, der die Bearbeitung von Dateien in einem Terminal bzw. auf der Konsole erlaubt.

    nano [OPTIONEN] [DATEI]

## [2] Manuelles Kompilieren mithilfe der Konsole

`nano main.c` | - Öffnet die main.c mithilfe des **nano** Editors -> Programm schreiben

`hexdump -C ("DATEINAME")` |-Anzeigen des Codes auf der Konsole in Hexadezimal 

**Kompilierungsvorgang:**

`gcc main.c **-E** ` |-Preprozessieren
`gcc main.c **-S** ` |-Kompilieren
`gcc main.c **-c** ` |-Assemblieren     --- `objdump--dissasemble-all main.c`
`gcc main.c **-o**`  |-Object Datei erstellen  
![enter image description here](https://image.ibb.co/hjjOGz/8YD.png)  
  *`avr-gcc` Wird nur für Mikrocontroller verwendet*

