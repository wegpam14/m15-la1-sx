## 3. Protokoll
Name: **Grebien Markus**  
Klasse: **4AHME**  
Knr: **3**


**Inhaltsverzeichnis**

1. CPU (**C**entral **P**rocessing **U**nit)
	1. Programm Counter
	1. Multiplexer
	1. Befehls-Register
	1. Befehls-Decoder
	1. Status Register
	1. Stack Pointer
	1. CPU-Register
	1. ALU
	1. Speicherverwaltung
1. Speicher
	1. Flash
	1. SRAM
	1. EEPROM
1. Atmel Studio
1. Maschinenbefehle
1. Wichtiges
---
### CPU
1. Programm Counter
	* Beinhaltet die Position des nächsten Befehls.
1. Multiplexer
	* Kann man sich wie einen Schalter vostellen. Entweder wird es um eins erhöht oder ein Befehl sagt, dass er um einen speziellen wert steigen oder fallen soll. 
1. Befehls-Register
	* Empfängt die Programmbefehle und speichert sie wärend des Ablaufs
1. Befehls-Decoder
	* Wandelt den Befehl um in assemblersprache und gibt diesen mithilfe von Steuersignalen weiter.
1. Status Register
	* Beinhaltet spezielle flags. Zum Beispiel: Overflow-Flag, Carry-Flag, Zero-Flag....
1. Stack Pointer
	* Beinhaltet die letzte Speicheradresse des SRAM
1. CPU-Register
	* Das CPU-Register nimmt auf Befehl des befehls-Decoder Daten aus der Speicherverwaltung und übergibt sie der ALU. Er besitzt 32 Register, wobei es 3 ausnahmen gibt: 
		* X (R26 und R27)
		* Y (R28 und R29)
		* Z (R30 und R31)
1. ALU
	* Ist das rechenwerk für mathematische und Logische Operationen. 
1. Speicherverwaltung
	*  Beinhaltet die Befehle für den CPU, die vom Programm Counter in das befehlsregister kommen

### Speicher
1. Flash
	* Wist ein nicht-flüchtiger Speicher, welcher mithilfe des Tunneleffekts beschriben wird.
2. SRAM(IRAM) 
	* gehört zur Familie der flüchtigen Speicher und verliert alle gespeicherten inhalte wemm die Betriebsspannung ausgeschaltet wird. 
3. EEPROM
	* Ist ein nicht flüchtiger Speicher, bei dem einzelne Bits angesprohen werden. 

### Atmel Studio
Ist eine IDE, mit dem man Mikroprozessoren simulieren kann. Und unter dem Menüpunkt Debug, kann man sich auch den Assemblerquelltext anzeigen lassen. 
In unserer Übungseinheit haben wir einen ATmega 328P simuliert mit folgendem Programm:
```C
#include <avr/io.h>


int main(void)
{
    volatile unsigned char a = 0x10;
    volatile unsigned char b = 0x20;
    return a+b;
}
```

Diese Programm haben wir dann als Assemblersprache ausgeben lassen und die wichtigsten Befehle durchgesprochen.

### Assemblerbefehle

`PUSH` ---> Speicher daten in den Stack.  
`IN` ---> Holt sich Werte von einem I/O Register.  
`OUT` ---> Speichert Werte in ein I/O Register.  
`STD` ---> Es wird eine lokale Variable erzeugt.  
`LDD` ---> Laded Daten vom Stack ins register.  
`ADD` ---> Addiereon ohne Carry.  
`ADC` ---> Addieren mit Carry.  
`POP` ---> Holt sich ein Byte vom Stack.  
`RJMP` ---> Spring relativ vom jetztigen standpunkt.  
`CPI` ---> Vergleicht und ändert nur die Statusflags.  

Liste aller Assemblerbefehle [hier][code_list]

### Wichtiges

Bei einem Mikroprozessor können globale variablen vorteile bringen, weil sie einen fixen Platz im Stack bekommen. Aber solange man keine Platz oder Zeitprobleme hat, sollte man bei den lokalen variablen bleiben.

[code_list]: https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_CPI.html
