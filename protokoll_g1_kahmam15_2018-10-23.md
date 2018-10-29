![HTBLA Kaindorf](https://upload.wikimedia.org/wikipedia/commons/thumb/3/30/HTL_Kaindorf_Logo.svg/1200px-HTL_Kaindorf_Logo.svg.png)
# 3. Protokoll (23.10.2018)
Name: Kahr Markus  
Klasse: 4AHME  
KNr.: 6  
Gruppe: 1  
___

## Inhalte:  

* **1. Struktur einer CPU**  
  * *1.1 Schema*
  * *1.2 Funktionsweise*
* **2. [AVR]**
   * *2.1 AVR mega AVR μC Speicher*  
   * *2.2 Simulation mit Atmel Studio* 
* **3. Bash-Shell**
* **4. Linux**
   * *4.1 Linux-Befehle* 
   * *4.2 Linux-Zugriffsrechte* 
 
 ___
  
### 1. Struktur einer CPU

#### 1.1 Schema
  
![CPU](https://user-images.githubusercontent.com/43982802/47662783-e7319400-db9b-11e8-9ebd-884aff99a37d.PNG)  


#### 1.2 Funktionsweise

* Reset - Bringt den CPU auf einen definierten Ausgangszustand
* Speicherverwaltung - Enthält die Adressen der Maschinenbefehle  
* Befehls-Register - Speichert die Adresse der Befehle mithilfe von Taktflankengesteuerten D-Flip-Flops zwischen  
* Befehls-Decoder - Decodiert die Maschinenbefehle in Assembler und gibt diese als Steuersignale weiter  
* CPU-Register - Nimmt auf Befehl Daten aus der Speicherverwaltung  
  * 32 Bit Speicher (R00... R31)  
  * X (R26, R27); Y (R28, R29); Z (R30, R31)  
* ALU (Arithmetic Logic Unit) - Verarbeitet die Befehle mithilfe von logischen und arithmetischen Operationen  
* Status-Register - Beinhaltet Status-Flags (Z-Flag, C-Flag, O-Flag, ...)  
* Stack-Pointer - Enthält die letzte Speicheradresse des SRAMs  
* Multiplexer - Signalweiche für einen Programmsprung  
* Program-Counter - Speichert des nächsten Befehls
___

### 2. AVR

#### 2.1 AVR mega AVR μC Speicher

* Flash (Segmente werden angesprochen)
  * [Tunneleffekt]
* EE-PROM (Einzelne Bits werden angesprochen)
* SRAM (Flüchtiger Speicher)


#### 2.2 Simulation mit Atmel Studio



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


[AVR]: https://de.wikipedia.org/wiki/Microchip_AVR#cite_note-ATmega640-3
[Tunneleffekt]: https://de.wikipedia.org/wiki/Tunneleffekt#Flash-Speicher
[Bash]: https://de.wikipedia.org/wiki/Bash_(Shell)
[Unix-Shell]: https://de.wikipedia.org/wiki/Unix-Shell
[GNU-Projekts]: https://de.wikipedia.org/wiki/GNU-Projekt
[unixoiden]: https://de.wikipedia.org/wiki/Unixoides_System
[Präprozessor]: https://de.wikipedia.org/wiki/C-Pr%C3%A4prozessor
[Compiler]: https://de.wikipedia.org/wiki/Compiler
[Assembler]: https://de.wikipedia.org/wiki/Assembler_(Informatik)
[Linker]: https://de.wikipedia.org/wiki/Linker_(Computerprogramm)
