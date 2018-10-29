### 3. Protokoll
Name: **Grebien Markus**
Klasse: **4AHME**
Knr: **3**


**Inhaltsverzeichnis**

1. CPU (**C**entral **P**rocessing **U**nit)
	1. Programm Counter
	2. Multiplexer
	3. Befehls-Register
	4. Befehls-Decoder
	5. Status Register
	6. Stack Pointer
	7. CPU-Register
	8. ALU
	9. Speicherverwaltung
2. Speicher
1. Maschinenbefehle
 ---

### CPU
1. Programm Counter
	* Beinhaltet die Position des nächsten Befehls.
2. Multiplexer
	* Kann man sich wie einen Schalter vostellen. Entweder wird es um eins erhöht oder ein Befehl sagt, dass er um einen speziellen wert steigen oder fallen soll. 
3. Befehls-Register
	* Empfängt die Programmbefehle und speichert sie wärend des Ablaufs
4. Befehls-Decoder
	* Wandelt den Befehl um in assemblersprache und gibt diesen mithilfe von Steuersignalen weiter.
5. Status Register
	* Beinhaltet spezielle flags. Zum Beispiel: Overflow-Flag, Carry-Flag, Zero-Flag....
6. Stack Pointer
	* Beinhaltet die letzte Speicheradresse des SRAM
7. CPU-Register
	* Das CPU-Register nimmt auf Befehl des befehls-Decoder Daten aus der Speicherverwaltung und übergibt sie der ALU. Er besitzt 32 Register, wobei es 3 ausnahmen gibt: 
		* X (R26 und R27)
		* Y (R28 und R29)
		* Z (R30 und R31)
8. ALU
	* Ist das rechenwerk für mathematische und Logische Operationen. 
9. Speicherverwaltung
	*  Beinhaltet die Befehle für den CPU, die vom Programm Counter in das befehlsregister kommen

### Speicher


### Maschienenbefehle

PUSH ---> Speicher daten in den Stack
IN ---> Holt sich Werte von einem I/O Register.
OUT ---> Speichert Werte in ein I/O Register.
STD ---> Es wird eine lokale Variable erzeugt
LDD ---> Laded Daten vom Stack ins register
ADD ---> Addiereon ohne Carry
ADC ---> Addieren mit Carry
POP ---> Holt sich ein Byte vom Stack
RJMP ---> Spring relativ vom jetztigen standpunkt.
CPI ---> Vergleicht und ändert nur die Statusflags

