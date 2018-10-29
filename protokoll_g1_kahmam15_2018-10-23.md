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
* **3. Atmel Studio**
* **4. Assembler-Befehle**

 
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
### 3. Atmel Studio

[Atmel Studio 7] ist eine integrierte Entwicklungsplattform (IDP) für die Entwicklung und das Debugging aller AVR®- und SAM-Mikrocontroller-Anwendungen. In unserer Laboreinheit haben wir einen ATmega328P mit folgenden Programm simuliert:  
```C
#include <avr/io.h>

int main(void)
{

 volatile unsigned char a = 0x10;
 volatile unsigned char b = 0x20;  
	
 return a + b;
}
```

___
### 4. [Assembler-Befehle]


* **```CLR <R>```** - Alle Werte im Register werden auf 0 gesetzt
* **```OUT <A,R>```** - Speichert Daten in das I/O-Register
* **```IN <R,A>```** - Holt Daten aus dem I/O-Register
* **```SER <R>```** - Alle Werte im Register werden auf 1 gesetzt
* **```LDI <R,K>```** - Ladet eine 8 Bit Konstante in das Register
* **```RCALL <k>```** - Speichert in den Stack
* **```RET```** - Holt Wert aus dem Stack und speichert diesen im Programm Counter
* **```CLI```** - Löscht das I-Flag
* **```RJMP <k>```** -  Springt in eine Adresse (z.B.: **```RJMP PC-0x0000```** => Endlose Schleife)
* **```PUSH <R>```** - Speichert das Register in den Stack
* **```POP <R>```** - Gibt Variable aus dem Stack frei  
* **```STD```** - Speichert Daten aus den Registern **X**, **Y** oder **Z**
* **```LDD```** - Holt Daten aus den Registern **Y** oder **Z**
* **```LDS <R,k>```** - Holt Daten aus dem SRAM
* **```ADC <R>```** - Addiert mit C-Flag
* **```ADD <R>```** - Addiert ohne C-Flag
* **```MOV <R,R>```** - Kopiert in ein Register (Source-Register unverändert)
* **```CPI <R,K>```** - Vergleicht ein Register mit einer Konstanten
* **```STS <k,R>```** - Speichert direkt Daten aus einem Register
* **```BRNE <R>```** - Spingt wenn kein Z-Flag gesetzt is (else)


[AVR]: https://de.wikipedia.org/wiki/Microchip_AVR#cite_note-ATmega640-3
[Tunneleffekt]: https://de.wikipedia.org/wiki/Tunneleffekt#Flash-Speicher
[Floating-Gate-Transistor]: https://de.wikipedia.org/wiki/Floating-Gate-Transistor
[Flash]: https://de.wikipedia.org/wiki/Flash-Speicher
[EE-PROM]: https://de.wikipedia.org/wiki/Electrically_Erasable_Programmable_Read-Only_Memory
[SRAM]: https://de.wikipedia.org/wiki/Static_random-access_memory
[Atmel Studio 7]: (https://www.microchip.com/mplab/avr-support/atmel-studio-7)
[ATmega328P]: http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-42735-8-bit-AVR-Microcontroller-ATmega328-328P_Summary.pdf
[mega Avr]: https://en.wikichip.org/wiki/MegaAVR
[Assembler-Befehle]: https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_LDI.html
