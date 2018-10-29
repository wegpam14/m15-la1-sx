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
    * *1.2.1 Reset*
    * *1.2.2 Speicherverwaltung*
    * *1.2.3 Befehls-Register*
    * *1.2.4 Befehls-Decoder*
    * *1.2.5 CPU-Register*
    * *1.2.6 ALU*
    * *1.2.7 Status-Register*
    * *1.2.8 Stack-Pointer*
    * *1.2.9 Multiplexer*
    * *1.2.10 Program-Counter*
* **2. AVR**
   * *2.1 mega AVR μC Speicher*  
* **3. Assembler-Befehle**

 
 ___
  
### 1. Struktur einer CPU

#### 1.1 Schema
  
![CPU](https://user-images.githubusercontent.com/43982802/47662783-e7319400-db9b-11e8-9ebd-884aff99a37d.PNG)  


#### 1.2 Funktionsweise

* 1.2.1 Reset - Bringt den CPU auf einen definierten Ausgangszustand
* 1.2.2 Speicherverwaltung - Enthält die Adressen der Maschinenbefehle  
* 1.2.3 Befehls-Register - Speichert die Adresse der Befehle mithilfe von Taktflankengesteuerten D-Flip-Flops zwischen  
* 1.2.4 Befehls-Decoder - Decodiert die Maschinenbefehle in Assembler und gibt diese als Steuersignale weiter  
* 1.2.5 CPU-Register - Nimmt auf Befehl Daten aus der Speicherverwaltung  
  * 32 Bit Speicher (R00... R31)  
  * X (R26, R27); Y (R28, R29); Z (R30, R31)  
* 1.2.6 ALU (Arithmetic Logic Unit) - Verarbeitet die Befehle mithilfe von logischen und arithmetischen Operationen  
* 1.2.7 Status-Register - Beinhaltet Status-Flags (Z-Flag, C-Flag, O-Flag, ...)  
* 1.2.8 Stack-Pointer - Enthält die letzte Speicheradresse des SRAMs  
* 1.2.9 Multiplexer - Signalweiche für einen Programmsprung  
* 1.2.10 Program-Counter - Speichert die Adresse des nächsten Befehls
___

### 2. AVR

#### 2.1 [mega AVR] μC Speicher ([ATmega328P])

* [Flash] (Segmente werden angesprochen)
  * [Floating-Gate-Transistor] um den [Tunneleffekt] zu verwenden  
  ![FGT](https://upload.wikimedia.org/wikipedia/commons/thumb/a/a9/FGMOS_Symbol.svg/330px-FGMOS_Symbol.svg.png)
*  [EE-PROM](Einzelne Bits werden angesprochen)
*  [SRAM](Flüchtiger Speicher)
___

### 3. Assembler-Befehle


* **```CLR```** - Alle Werte werden auf 0 gesetzt
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
[ATmega328P]: http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-42735-8-bit-AVR-Microcontroller-ATmega328-328P_Summary.pdf
[mega Avr]: https://en.wikichip.org/wiki/MegaAVR
