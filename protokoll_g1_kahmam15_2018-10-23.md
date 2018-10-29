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
* **2. AVR**
   * *2.1 mega AVR μC Speicher*  
* **3. Assembler-Befehle**

 
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

#### 2.1 [mega AVR] μC Speicher

* [Flash] (Segmente werden angesprochen)
  * [Floating-Gate-Transistor] um den [Tunneleffekt] zu verwenden  
  ![FGT](https://upload.wikimedia.org/wikipedia/commons/thumb/a/a9/FGMOS_Symbol.svg/330px-FGMOS_Symbol.svg.png)
*  (Einzelne Bits werden angesprochen)
*  (Flüchtiger Speicher)
___

### 3. Assembler-Befehle


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


[AVR]: https://de.wikipedia.org/wiki/Microchip_AVR#cite_note-ATmega640-3
[Tunneleffekt]: https://de.wikipedia.org/wiki/Tunneleffekt#Flash-Speicher
[Floating-Gate-Transistor]: https://de.wikipedia.org/wiki/Floating-Gate-Transistor
[Flash]: https://de.wikipedia.org/wiki/Flash-Speicher
[EE-PROM]: https://de.wikipedia.org/wiki/Electrically_Erasable_Programmable_Read-Only_Memory
[SRAM]: https://de.wikipedia.org/wiki/Static_random-access_memory
[mega Avr]: https://en.wikichip.org/wiki/MegaAVR
