





### Protokoll 3

 **Atmega 328p**


----------


    enter code here avr - gcc -mmcu =atmega328p - E main.c |tail

    (*(volatile uint8_t *)((0x04) + 0x20))  
    

Erklärung:

* Speicheradresse
* `uint8_t` = gekürzter Datentyp (#define unsiged char uinit5_t) 
Ein Nachteil beim C programmieren ist, dass Datentypen systemabhängig sind.
Bsp: int 16 oder 32 bit
* nicht mehr systemabhänging
* `volatile` = verletzlich
* `uint8_t*` = ein Zeiger auf deinen Datentyp 
* man weist am Speicher an dieser Stelle einen Wert zu `(*(volatile uint8_t *)` ( = erster Stern)
* `portb` = `(*(volatile uint8_t *)((0x04) + 0x20))` => für den Laptop
*  `|tail` = Ende der Liste anzeigen lassen  



**Type Cast** = einen Datentyp in einen anderen konvertieren
Bsp:	 

    char c=3;
    int x= (int) c;  
    
    


----------

## Atmel Studio ##

*  Simulator  


Übungsbeispiel: 

    {
	     DDBR = 0x20;
	     PORTB = 0x 20;
	     return 0;
    }  
    
Am Rand auf der rechten Seite konnte man die Register sehen. Sie waren vom R00 bis
R31 aufgelistet, sprich 32 Register:
R00
R01
R02
...
R31
Die letzten 6 Register kann man zu sogenannten "16 Bit Register zusammenfassen"  


R26 und R27 bilden **X**
R28 und R29 bilden **Y**
R30 und R31 bilden **Z**  


Die Taktfrequenz für den Ardoino Nano betragt **16MHz**.   


* `mnemonic` → Ein für den Menschen lesbares Kürzel für einen Befehl einer
Assemblersprache.
* `LDI R24, 0x20` → Speichere 0x20 in das Register R24

* `RET` → Ähnlich zu "return". Damit kann man eine Funktion öfters aufrufen.
* `reset`→ Setzt das System zurück
* `Relative Jump`→ Neue Befehl in den Programm Counter
* `CLR`→ clear, Bildschirm löschen 



----------  



## Speicherarten ##

**Was ist ein Speicher?*  

Merkt sich Bitmuster an einer bestimmten Adresse um sie später wieder auslesen zu können.    

**Arten:**  


 1. Programmspeicher (Flash) 32 kiB
 2. Arbeitsspeicher (SRAM) 24 kiB
 3. EEPROM
 
 ![CPU Blockschaltbild](https://www-user.tu-chemnitz.de/~heha/viewchm.php/hs/ATmegaX8.chm/bild/b7-1.png)  
 
 
----------   

## Erklärung ##

**ALU:**  

Die Arithmetic Logic Unit (ALU) ist das Rechenwerk für arithmetische und logische Operationen und Bestandteil der Zentraleinheit (CPU). An mathematischen Operationen kann ein solches Rechenwerk alle Operationen der Dualarithmetik ausführen wie Addition, Subtraktion, Multiplikation und Division, an logischen Funktionen die Und-Funktion durch das AND-Gatter, die Oder-Funktion durch das OR-Gatter und die Nicht-Funktion durch das NOT-Gatter. Darüber hinaus kann das Rechenwerk Vergleiche und Schiebebefehle ausführen. Das Rechenwerk arbeitet die Befehle ab, die es vom Steuerwerk erhält.  

 

**Befehls - Decoder:**  

Der Befehlsdecoder ist ein Teil des Prozessors im Computer, ein sogenannter Interpreter.  


Seine Aufgabe besteht darin, die Maschinenbefehle in Micro-Instructions zu übersetzen und, falls nötig, in einzelne Arbeitsschritte zu zerlegen. Diese werden dann von ihm an die zugehörigen Einheiten der Central Processing Unit weitergeleitet.

In einem typischen Mikroprozessor mit einer Pipeline werden die Befehle von der Instruction Fetch Unit (IFU) aus dem Speicher geholt und dann dem Befehlsdecoder übergeben. Anhand des gespeicherten Wertes kann dieser dann den nächsten Befehl entschlüsseln. Vermenschlicht entspricht dies dem Nachschlagen in einer Tabelle. Neben der Dekodierung des Befehls (z. B. Addition oder Sprung) müssen auch die Operanden dekodiert werden. Im Falle einer Addition beispielsweise welche Werte addiert werden sollen.

Wie schwierig dieser Vorgang ist, hängt von der jeweiligen Architektur des Prozessors ab. Im günstigen Fall handelt es sich um einen RISC (Reduced Instruction Set Computer) Prozessor, bei dem jeder Befehl mit der gleichen Anzahl von Bits gespeichert wird. Auch müssen bei der Dekodierung des Befehls nicht neue Mikro-Befehle generiert werden, falls der gespeicherte Befehl es zum Beispiel erfordert einen Operanden aus dem Speicher zu laden. Dies kann bei CISC (Complex Instruction Set Computer) Architekturen passieren. Erschwerend kommt bei dieser Architektur hinzu, dass die Befehle häufig unterschiedlich lang sind, also unterschiedlich viele Bits zum Speichern brauchen. Die berühmtesten Vertreter dieser Problematik sind die zum x86 Befehlssatz kompatiblen Prozessoren.

Ähnlich einfach ist es bei Prozessoren mit VLIW (Very Long Instruction Word) Architektur. Befehle dieser Architektur sind relativ einfach zu dekodieren, enthalten aber neben der gewünschten Operation und den Operanden auch Informationen über die zu verwendenden Ausführungseinheiten.

Die dekodierten Befehle werden an die nachfolgenden Ausführungseinheiten weitergeleitet. Danach kann der nächste Befehl dekodiert werden.   


**CPU Register:**  

Als Register oder genauer Rechenregister werden in der Digital- oder Computertechnik Speicherbereiche bezeichnet, die innerhalb eines Prozessorkerns unmittelbar mit der eigentlichen Recheneinheit verbunden sind und die ebenso unmittelbaren Operanden und Ergebnisse aller Berechnungen aufnehmen. Allzweck- oder Ganzzahl-Register sind in der Regel höchstens so groß wie die Wortgröße des Prozessorkerns (8, 16, 32 oder 64 Bit).

Die Gesamtheit aller Register einer solchen logischen Komponente bezeichnet man als dessen Registersatz. Spezielle Register werden für die Wahl der Betriebsmodi eines Prozessorkerns verwendet. Verschiedene Register dienen zum Zwischenspeichern von Befehlen, Speicheradressen, Rechenoperanden und in Peripheriebausteinen auch zum Zwischenspeichern von Ein- und Ausgabewerten.

Die Breite eines Registers wird in Bit angegeben und ist üblicherweise eine Zweierpotenz.

Neben den stets vorhandenen Allzweck- oder Ganzzahl-Registern besitzen viele Prozessorkerne spezielle Register für Gleitkommaberechnungen, mitunter auch für (Ganzzahl- oder Gleitkomma-)SIMD-Befehle. Diese sind häufig größer als die Wortgröße des Prozessorkerns.  


**Die Register**:  

Das sind Speichereinheiten die direkt mit der Recheneinheit verbunden sind. Sie beinhalten Daten, Operanden und Berechnungsergebnisse in Form von Dualzahlen, und haben in der Regel die „Wortgröße“ des Prozessors (8 Bit, 16 Bit, 32 Bit oder 64 Bit). Schaltungstechnisch handelt es sich hier meist um taktflankengesteuerte D-Flip-Flops.

**Sprungbefehle**:  

Sprungbefehle dienen zur Änderung des Programmablaufs.
Es gibt unbedingte Sprünge (JMP), bedingte Sprünge (BREQ, BRNE, BRGE, BRLT, BRMI, BRPL) und Sprünge mit relativen Sprungzielen (IJMP, RJMP).
Daneben gibt es auch Funktionsaufrufe bei denen die Rücksprungadresse am Stack gespeichert wird (CALL, ICALL) und Funktionsrücksprung-Befehle (RET)

**Z Flag** : 

Ist das Ergebnis einer Operation Null,wird dies durch ein gesetztes Zero Flag( Z=1) signalisiert.

**C Flag**  :

Mit Hilfe des Carry Flags wird gekennzeichnet (C= 1)ob bei einer vorzeichenlosen Operation ein Überlauf, also ein Verlassen des dargestellten Zahlenbereichs aufgetreten ist. 

**V Flag** : 

Das Overflow Flag signalisiert mit V=1bei vorzeichenbehafteten Operationen wie der Addition oder der Subtrakion. 

**decodieren**  

das Muster wird in konkrete Signale übersetzt.  

----------  

## Handbuch ##  

**Handbuch Atmel Studio**

[Handbuch](http://ww1.microchip.com/downloads/en/devicedoc/atmel-42735-8-bit-avr-microcontroller-atmega328-328p_datasheet.pdf)  

**Beispiele:**

    DDRB = 0x20;
    0000003D 80.e2                LDI R24,0x20        Load immediate 
    0000003E 84.b9                OUT 0x04,R24        Out to I/O location 
    PORTB = 0x20;
    0000003F 85.b9                OUT 0x05,R24 

       Out // 2 Bit jedoch nur um 1 erhöht

**Speicheradresse**: (0x25)  

**Maschinenbefehle**: 0x05

    00000042 08.95                RET         Subroutine return 
    RET = return in C

damit man es wie eine Funktion öfter aufrufen kann


     RJMP PC-0x0000        Relative jump 

er kann nicht die ganze Adresse angeben 
nimmt die jetzige Stelle und zählt 24 dazu

    00000034 11.24                CLR R1        Clear Register 

R1 = immer Null 
schaut das er immer Null hat, daher R1 immer  Null 
 
----------  

Wichtige Zusatzinformationen:
-----------------------------

    **Dezimales Zahlensystem**

**Nennwerte:** 0 1 2 3 4 5 6 7 8 9  

**Basis:** 10  

**Größter Nennwert:** 9  

**Stellenwerte:** 100 = 1, 101 = 10, 102 = 100, usw.  



    Duales Zahlensystem

**Nennwerte:** 0 1  

**Basis:** 2  

**Größter Nennwert:** 1  

**Stellenwerte:** 20 = 1, 21 = 2, 22 = 4, usw.  



    Hexadezimales Zahlensystem

**Nennwerte:** 0 1 2 3 4 5 6 7 8 9 A B C D E F  

**Basis:** 16  

**Größter Nennwert:** F  

**Stellenwerte:** 160 = 1, 161 = 16, 162 = 256, usw.  


 


