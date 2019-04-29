![HTBLA Kaindorf](https://upload.wikimedia.org/wikipedia/commons/thumb/3/30/HTL_Kaindorf_Logo.svg/1200px-HTL_Kaindorf_Logo.svg.png)

# 2. Protokoll (16.10.2018)
Name: Kahr Markus  
Klasse: 4AHME  
KNr.: 6  
Gruppe: 1  
___

## Inhalte:  

* **1. Übersetzungsvorgang in C**  
* *1.1 Sourcecode erstellen*
* *1.2 Konvertierung in Maschinen lesbares Programm*
* **2. Compiler**
 * *2.1 Verschiedene Compiler*  
 * *2.2 Arbeitsvorgang des GNU Compiler* 
* **3. Bash-Shell**
* **4. Linux**
 * *4.1 Linux-Befehle* 
 * *4.2 Linux-Zugriffsrechte* 
 
 ___
  
### 1. Übersetzungsvorgang in C

#### 1.1 Sourcecode erstellen
  
  Zu Beginn eines Programms wird ein [Quelltext] benötigt (gewöhnliche Textdatei).
  In diesem Quelltext werden Programmieranweisungen geschrieben, welche den Aufgaben des Programms entsprechen.
  Durch Syntaxhervorhebung werden Teile des Quelltextes entsprechend ihrer Funktionalität farblich hervorgehoben, was die Lesbarkeit
  verbessert. Ebenfalls zur Verbesserung der Lesbarkeit halten sich Programmierer meist an eine bestimmte Quelltextformatierung
  (z. B. Einrückung von Unterabschnitten, Groß-/Kleinschreibung …). 

#### 1.2 Konvertierung in Maschinen lesbares Programm

* [Präprozessor] (#include, #define, #...) - erzeugt einen präprozzesierten Quelltext  
* [Compiler] - übersetzt in Assembler (Maschinensprache)  
* [Assembler] - erzeugt aus der Assembler Quelltextdatei eine/n Objektdatei/Objectcode  
* [Linker] - übergibt die Adressen damit das Programm ausgeführt werden kann

___

### 2. Compiler

#### 2.1 Verschiedene Compiler

* [GNU Compiler]  
* [Visual C/C++ Compiler]  


#### 2.2 Arbeitsvorgang des GNU Compiler

![GCC Schema](https://upload.wikimedia.org/wikipedia/commons/thumb/4/41/GCC_Schema.svg/600px-GCC_Schema.svg.png)

___

### 3. Bash-Shell

**[Bash]** (für **B**ourne-**a**gain **sh**ell) ist eine freie [Unix-Shell] und Teil des GNU-Projekts. Sie ist heute auf vielen [unixoiden] Systemen die **Standard-Shell**. Viewer/Editoren für die Unix-Shell sind z.B.: nano, less.
![Leere Bash](https://hosting.1und1.de/digitalguide/fileadmin/DigitalGuide/Screenshots/ubuntu-bash.png)  
Informationen aus der Bash-Shell:
* Die Tilde **```~```** zeigt mir, dass ich mich im Home-Verzeichnis befinde  
* Das Endzeichen kann ein **```$```** (=Benutzer) oder ein **```#```** (=Admin) sein  

___

### 4. Linux

#### 4.1 Linux-Befehle

* **```whoami```** - Zeigt dir welcher Benutzer du bist
* **```pwd```** - Zeigt dir in welchem Verzeichniss du dich befindest
* **```man```** - Ruft das Manual/die Mainpages auf (z.B.: **```man 3 printf```**)
* **```cat```** - Gibt eine Textdatei in der Konsole aus
* **```mkdir <name>```** - Erstellt ein neues Verzeichniss
* **```history```** - Zeigt dir deine Befehls-History an  
* **```reset```** - Setzt die Shell zurück
* **```ls -l```** - Zeigt die Rechte auf die Dateien (Ersten 3 = Rechte der Eigentümer, Zweiten 3 = Rechte der Gruppen,  
Ersten 3 = Rechte aller Benutzer)  
* **```hexdump```** - Zeigt Bytes der Datei  
* **```hexdump -C```** - Zeigt Bytes der Datei mit Textinhalt  
* **```gcc <main.c>```** - Compeliert eine Datei  
* **```gcc -E <main.c>```** - Reprozessiert die Datei -> **```main.pp```**  
* **```gcc -S <main.c>```** - Codiert in Assembler-Quelltext -> **```main.s```**
* **```gcc -c <main.c>```** - Erstellt Objektdatei -> **```main.o```**
* **```./a.out```** - Führt Programm im Terminal aus  

#### 4.2 Linux-Zugriffsrechte

![Zugrifssrechte](http://www.easylinux.de/Artikel/ausgabe/2003/09/071-guru-chmod/rwx-grafix_s.jpg)


[Quelltext]: https://de.wikipedia.org/wiki/Quelltext
[GNU Compiler]: https://de.wikipedia.org/wiki/GNU_Compiler_Collection
[Visual C/C++ Compiler]: https://de.wikipedia.org/wiki/Visual_C%2B%2B
[Bash]: https://de.wikipedia.org/wiki/Bash_(Shell)
[Unix-Shell]: https://de.wikipedia.org/wiki/Unix-Shell
[GNU-Projekts]: https://de.wikipedia.org/wiki/GNU-Projekt
[unixoiden]: https://de.wikipedia.org/wiki/Unixoides_System
[Präprozessor]: https://de.wikipedia.org/wiki/C-Pr%C3%A4prozessor
[Compiler]: https://de.wikipedia.org/wiki/Compiler
[Assembler]: https://de.wikipedia.org/wiki/Assembler_(Informatik)
[Linker]: https://de.wikipedia.org/wiki/Linker_(Computerprogramm)
