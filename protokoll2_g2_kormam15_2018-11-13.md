# Protokoll 2 (16.11.1018)  
Name: Korrenn Marwin  
KNr.: 7  
Klasse: 4AHME  
Gruppe: 2  
___  
## Übersicht  
1. Übersetzungsvorgang in C
    1. Compiler
    1. Schritte eines Übersetzungsvorganges
1. Betriebssystem Linux
    1. Zugriffsrechte des Systems
    1. Texteditoren /-viewer
    1. [Shell][unixshell]
1. Wichtige Konsolenbefehle  
___
## **1** Übersetzungsvorgang in C

### 1.1 Compiler

C-Compiler waren vor dem [GCC][gcc] und ähnlichen Projekten kostenspielige Software. Die Lizensen für Compiler musste mit viel Geld erworben werden.

[Richard Stallman][richardstallman] entwickelte daher um die 1990 den GNU C Compiler.
Dieser ist ein freier Compiler unter der GPL Lizenz. In ständiger zusammenarbeit mit den Linuxsystemen haben sie sich gegenseitig groß gemacht. Dadurch sind diskussionen entstanden ob man nicht "GNU/Linux - Systeme" sagt, jedoch hat sich das im Sprachgebrauch nicht durchgesetzt.  

### 1.2 Schritte eines Übersetzungsvorganges

**Erstellen der Quelldatei**:
Eine Quelldatei, der sogenannte *Sourcecode*, also das eigentliche C-Programm in Form einer gewöhnlichen Textdatei muss mithilfe eines Texteditors oder einer IDE erstellt werden. 

**Präprozzesor**:
Der Präprozessor löst Präprozessorbefehle in der Quelldatei auf und ersetzt diese durch die jeweilige Funktionalität.

**Compiler**:
Der Compiler übersetzt die Bitketten zu Assemblerquelltext.

**Assembler**:
Der Assembler erzeugt danach eine Objektdatei - auch Objectcode genannt welches in Maschinensprache geschrieben ist.

**Linker**:
Fügt vorcompelierten Code ein und verwandelt die Maschinensprache in ein ausführbares Programm.

![Bild: Übersicht eines Übersetzungsvorganges](http://nerdyelectronics.com/wp-content/uploads/2017/07/GCC_CompilationProcess.png)

___
## 2 Linux als Betriebssystem

### 2.1 Zugriffsrechte des Systems

Mit dem Befehl `ls -l` kann der Benutzer die Rechte einer Datei einsehen.

Das Rechtesystem wird mit dem folgenden Bild gut beschrieben:

![Bild: Zugriffsrechtesystem unter Linux](http://original.cyber-tec.org/img/anleitungen/linux/zugriffsrechte.png)

### 2.2 Texteditoren /-viewer

#### VI

Das VI ist ein 1976 von [Bill Joy](https://de.wikipedia.org/wiki/Bill_Joy) auf einem ADM-3A-Computerterminal für eine frühe BSD-Version geschriebener und von POSIX standardisierter Texteditor. Er ist ohne Vorwissen beinahe unmöglich zu bedienen.

#### NANO

Ein strukturierter und einfach zu bedienender Texteditor mit wenigen aber ausreichendem Funktionsumfang.

### 2.3 [Unix-Shell][unixshell]

Im Fall von Ubuntu ist die [Bash][bash] (Bourne-again shell) die Standartshell.
Die Shell führt eingegebene Kommandos sofort aus und im gegesatz zu den *"Kommandozeileninterpreter"* manch anderer Betriebssysteme 
(z. B. VMS) sind Unix-Shells gewöhnliche Anwenderprogramme ohne besondere Privilegien.  

___
## 3 Wichtige Konsolenbefehle

`cd` - (change directory) wechselt das aktuelle Arbeitsverzeichnis zum Home-Verzeichnis des Benutzers  

`cd <path>` - wechselt das aktuelle Arbeitsverzeichnis zum angegebenen Pfad  

`ls` - listet alle Datein im aktuellen Arbeitsverzeichnis auf  

`ls --a`/`ls -a` - listet auch versteckte Datein  

`rm`- (remove) löscht  

`ll` -  für 'ls -la' unter ubuntu  

`less`- lässts am Bildschirm ausgeben  

`whoami` - gibt den aktuellen benutzer aus 

`mkdir <name>` - erstellt ein verzeichnis  

`mv <file> <target>` - verschiebt eine datei oder einen ordner an eine andere stelle  

`mv`- alleine um eine Datei umzubenennen  

`man <expression>` - ruft das manual auf  

`cat` - gibt den text einer oder mehrerer datein aus  

`pwd` - gibt aktuelle working directory aus 

`reset` - setzt die shell auf den anfangszustand zurück  

`history` - zeigt die shell-befehls-historie an  

`hexdump` - gibt bytes einer datei aus, kann mit dem parameter -C erweitert werden um auch den text zu sehen  

`chmod <permissions> <file>` - erteilen von rechten

[richardstallman]: https://de.wikipedia.org/wiki/Richard_Stallman
[gcc]: https://de.wikipedia.org/wiki/GNU_Compiler_Collection
[unixshell]: https://de.wikipedia.org/wiki/Unix-Shell
[bash]: https://de.wikipedia.org/wiki/Bash_(Shell)
[Bill Joy]:(https://de.wikipedia.org/wiki/Bill_Joy)
