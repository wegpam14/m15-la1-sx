# Protokoll 2 (16.10.2018)
Name: Fischer Maximilian  
KNr.: 2  
Klasse: 4AHME  
Gruppe: 1  
___
### Übersicht

1. Übersetzungsvorgang in C
    1. Compiler
    1. Schritte eines Übersetzungsvorganges
1. Linux als Betriebssystem
    1. Zugriffsrechte des Systems
    1. Texteditoren /-viewer
    1. [Shell][unixshell]
1. Wichtige Konsolenbefehle 

___
## **1** Übersetzungsvorgang in C

### **1.1** Compiler

C-Compiler waren vor dem [GCC][gcc] und ähnlichen Projekten kostenspielige Software. Die Lizensen für Compiler musste mit viel Geld erworben werden.

[Richard Stallman][richardstallman] entwickelte daher um die 1990 den GNU C Compiler.
Dieser ist ein freier Compiler unter der GPL Lizenz.

Der GCC ist heutezutage ein sehr guter Compile und daher auch der Meistgenutzte.

### **1.2** Schritte eines Übersetzungsvorganges

**Erstellen der Quelldatei**:
Eine Quelldatei, der sogenante *Sourcecode*, also das eigentliche C-Programm in form einer gewöhnlichen Textdatei muss mithilfe eines Texteditors oder einer IDE erstellt werden. 

**Präprozzesor**:
Der Präprozessor löst Präprozessorbefehle in der Quelldatei auf und ersetzt diese durch die jeweilige Funktionalität.

**Compiler**:
Der Compiler übersetzt die Bitketten zu Assembler.

**Assembler**:
Der Assembler erzeugt danach eine Objektdatei - auch Objectcode genannt.

**Linker**:
Ersetzt im Objectcode die Adressen, sodass das Programm danach ausgeführt werden kann.

![Bild: Übersicht eines Übersetzungsvorganges](http://nerdyelectronics.com/wp-content/uploads/2017/07/GCC_CompilationProcess.png)

___
### **2** Linux als Betriebssystem

### **2.1** Zugriffsrechte des Systems

Alle Linux Distributionen haben ein System für Rechte. 
Mit dem Befehl `ls -l` kann der Benutzer die Rechte einer Datei einsehen.

Das Rechtesystem wird mit dem folgenden Bild gut beschrieben:

![Bild: Zugriffsrechtesystem unter Linux](http://original.cyber-tec.org/img/anleitungen/linux/zugriffsrechte.png)

### **2.2** Texteditoren /-viewer

#### VI

Ein gewöhnungsbedürftiger Texteditor unter allen Linuxdistibutionen. Er ist als standart-package immer installiert. Ohne Vorwissen ist es nahezu unmöglich sich mit diesem Editor zurechtzufinden.

> I've been using Vi for about 2 years now, mostly because I can't figure out how to exit it.
~@iamdevloper

#### NANO

Ein einfach zu bedienenter freier Texteditor mit wenig, aber genügendem Funktionsumfang.

#### Weitere Editoren/Viewer:
- GEDIT (editor)
- LESS (viewer)

### **2.3** [Unix-Shell][unixshell]

Im fall von Ubuntu ist die [Bash][bash] (Bourne-again shell) die Standartshell.
Mithilfe der Shell kann der Benutzer durch eingeben verschiedenster Befehle mit dem Betriebssystem kommunizieren.

Mithilfe der Bash kann ein Programm mithilfe des folgenden Befehls ausgeführt werden:
`./programm`

___
### **3** Wichtige Konsolenbefehle

Wir lernten weitere Konsolenbefehle unter Linux, gleich wie in der Woche davor. Die Befehle letzter Woche können im [alten Protokoll] angesehen werden.

#### Linux

`whoami` - steht für 'change directory', wechselt das aktuelle arbeitsverzeichnis zum home-verzeichnis des benutzers  

`mkdir <name>` - wechselt das aktuelle arbeitsverzeichnis zum angegebenen pfad  

`mv <file> <target>` - verschiebt eine datei oder einen ordner an eine andere stelle 

`man <expression>` - ruft das manual auf  

`cat` - listet alle datein im aktuellen arbeitsverzeichnis auf  

`pwd` - listet auch versteckte datein  

`reset` - setzt die shell auf den anfangszustand zurück  

`history` - zeigt die shell-befehls-historie an  

`hexdump` - gibt bytes einer datei aus, kann mit dem parameter -C erweitert werden um auch den text zu sehen  

`chmod <permissions> <file>` - erteilen von rechten

[richardstallman]: https://de.wikipedia.org/wiki/Richard_Stallman
[gcc]: https://de.wikipedia.org/wiki/GNU_Compiler_Collection
[unixshell]: https://de.wikipedia.org/wiki/Unix-Shell
[bash]: https://de.wikipedia.org/wiki/Bash_(Shell)


