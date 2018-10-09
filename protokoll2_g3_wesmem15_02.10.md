# **Protokoll 3**
2.10.2018
4AHME
Mercedes Wesonig

### Konsole
Zuerst gaben wir folgenden Befehl in der Konsole ein:
```javascript
>avc -gcc -mmcu = atmega328p -E ma^C |tail
``` 
* mit dem `|tail` am Ende bezwecken wir, dass nur das Ende ausgegeben wird

Es erschien folgende Zeile:
```javascript
(*(volatile uint8_t*)((0x05)+(0x20)) = 0x20;
``` 
**Bedeutung:**

* **volatile** → verletzlich
*   `(volatile uint8_t*)` → Type cast
*   `((0x05)+(0x20))` → Nur Port 5 soll geändert werden, alles andere soll gleich bleiben

Insgesamt betrachtet bedeutet es einfach nur `PORTB = 0x20;` → Assemlersprache 

**Was ist ein "Type cast"?**

* Datentypen in C sind Systemabhängig
  * je nach dem ob man sich zb auf einem µC oder einem PC befindet ist ein Datentyp größer oder kleiner

Um so Etwas zu vermeiden gibt es folgenden Trick:
```javascript
char c= 3;
int x= (int) c;
main.c 
``` 
Das ist eine sogenannte Datentypumwandlung
* `(int)` -> Wird in diesem Zusammenhang **Type cast** genannt

### Atmel Studio

Das ist ein Simulationsprogramm mit dem wir am PC einen µC simulieren können!
Zuerst musste ein neues Projekt angelegt werden:

New project → STK600_Atmega328p

Danach schrieben wir ein einfaches Programm:
```javascript
#include <avr/io.h>
int main()
{
DDBR =0x20;
PORTB =0x20;
return 0;
}
```
Am Rand auf der rechten Seite konnte man die Register sehen. Sie waren vom R00 bis R31 aufgelistet, sprich 32 Register:

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

### Wichtige Kürzel
* `mnemonic` → Ein für den Menschen lesbares Kürzel für einen Befehl einer Assemblersprache.
*  `LDI R24, 0x20` → Speichere 0x20 in das Register R24
  * Was passiert im Hintergrund?
  
Folgendes Bitmuster entsteht:

 1110 0010 1000 0000

1) K= 0010 000 (0x20)
Es wird jedoch nicht als ganzes an das Muster angefügt sondern in 2 Teile aufgeteilt. 0010 findet man an der Position drei (von rechts aus gesehen). 0000 wird ganz am Anfang hingeschrieben.
2)  R24= 1000
Das wird an Position 2 geschrieben
3) Hexadezimal gesehen ergibt das Bitmuster den Wert **e2 80**!
4) Nun steht im Register R24 der Wert 0x20

* `OUT 0x04, R24`→ Stores data from register R in the Register File to I/O Space (Ports,...)
  * Was passiert im Hintergrund?
 
 Folgendes Bitmuster entsteht:

1011 1001 1000 0100

1) K= 00 0100 (0x04)
Wird wieder in 2 Teile aufgeteilt. 00 kommt in die Mitte der dritten Position von rechts. 0100 kommt an die erste Position.
2) 1 1000 (R24)
Wird ebenfalls aufgeteilt. 1000 kommt an Position zwei und der Einser rückt nach vorne an die erste Stelle von Position drei.
3) Hexadezimal gesehen ergibt das Bitmuster den Wert **b9 84**!
4) Nun steht im Register R24 der Wert 0x04

Cycle Counter 12
Frequency 6
Stp Watch 0,75µs

0000003A 85.b9 → 2 Bite 
Maschinenbefehl was zu tun ist!
1. Teil Adresse
2. Teil Inhalt

* `RET` → Ähnlich zu "return". Damit kann man eine Funktion öfters aufrufen. 
* `reset`→ Setzt das System zurück
* `Relative Jump`→ Neue Befehl in den Programm Counter
* `CLR`→ clear, Bildschirm löschen

### Speicherarten
Es gibt 3 Arten von Speicher:

* **Programmspeicher** (*Flash*)
  * 32kiB
  * Flash-Speicher sind digitale Speicherbausteine; die genaue Bezeichnung lautet Flash-EEPROM. Sie gewährleisten eine nichtflüchtige Speicherung bei gleichzeitig niedrigem Energieverbrauch. Flash-Speicher sind portabel und miniaturisiert, es lassen sich jedoch bei Flash-EEPROM, im Gegensatz zu gewöhnlichem EEPROM-Speicher, Bytes, die kleinsten adressierbaren Speichereinheiten, nicht einzeln löschen oder überschreiben. Flash-Speicher sind auch langsamer als Festwertspeicher (ROM). 
* **Arbeitsspeicher**  (*SRAM*)
  * 24kiB
  * Der Arbeitsspeicher oder Hauptspeicher (englisch core, main store, main memory, primary memory) eines Computers ist die Bezeichnung für den Speicher, der die gerade auszuführenden Programme oder Programmteile und die dabei benötigten Daten enthält. Der Hauptspeicher ist eine Komponente der Zentraleinheit. Da der Prozessor unmittelbar auf den Hauptspeicher zugreift, beeinflussen dessen Leistungsfähigkeit und Größe in wesentlichem Maße die Leistungsfähigkeit der gesamten Rechenanlage.
* **Electrically Erasable Programmable Read-Only Memory** (*EEPROM*)
  *  Er wird verwendet zur Speicherung kleinerer Datenmengen in elektrischen Geräten, bei denen die Information auch ohne anliegende Versorgungsspannung erhalten bleiben muss oder bei denen einzelne Speicherelemente bzw. Datenworte einfach zu ändern sein müssen

### CPU
Im LMS Laborkurs befindet sich ein Bild von einer Vereinfachten CPU. Wir diskutierten wie eine CPU funktionierte und besprochen folgende Begriffe näher:

Bild

* **Programm counter** → Adresse des nächsten Programms das ausgeführt werden soll. NICHT der "Programm Zähler"!!!
* **ALU** → (*Arithmetisch-logische Einheit*) "elektronisches Rechenwerk" Kann sowohl Addieren, Multiplizieren, usw. wie auch Logische Verknüpfungen wie zb AND, OR, usw. lösen.

**Funktionsweise:**
Ein Prozessor(kern) besteht aus Registern (Speicher), einem Rechenwerk (der Arithmetic Logic Unit, kurz ALU), einem Steuerwerk sowie den Datenleitungen (Busse), die die Kommunikation mit anderen Komponenten ermöglichen (Abbildung siehe weiter unten). Diese Komponenten sind im Allgemeinen weiter unterteilbar, zum Beispiel enthält das Steuerwerk zur effizienteren Bearbeitung von Befehlen die Befehls-Pipeline mit meist mehreren Stufen, unter anderem den Befehlsdecoder; die ALU enthält unter anderem zum Beispiel Hardwaremultiplizierer. Darüber hinaus befinden sich vor allem in modernen Mikroprozessoren mitunter sehr viel feiner unterteilte Einheiten, die flexibel einsetzbar/zuteilbar sind sowie mehrfach ausgeführte Einheiten, die das gleichzeitige Abarbeiten mehrerer Befehle erlauben (siehe zum Beispiel Simultaneous Multithreading, Hyper-Threading, Out-of-order execution). 

### Assemblersprache
Eine Assemblersprache, kurz auch Assembler genannt (von englisch to assemble, deutsch ‚montieren‘), ist eine Programmiersprache, die auf den Befehlsvorrat eines bestimmten Computertyps (d. h. dessen Prozessorarchitektur) ausgerichtet ist. Assemblersprachen bezeichnet man deshalb als maschinenorientierte Programmiersprachen und – als Nachfolger der direkten Programmierung mit Zahlencodes – als Programmiersprachen der zweiten Generation: Anstelle eines Binärcodes der Maschinensprache können Befehle und deren Operanden durch leichter verständliche mnemonische Symbole in Textform (z. B. „MOVE“), Operanden z. T. als symbolische Adresse (z. B. „PLZ“), notiert und dargestellt werden.

### Register
Als Register oder genauer Rechenregister werden in der Digital- oder Computertechnik Speicherbereiche bezeichnet, die innerhalb eines Prozessorkerns unmittelbar mit der eigentlichen Recheneinheit verbunden sind und die ebenso unmittelbaren Operanden und Ergebnisse aller Berechnungen aufnehmen. Allzweck- oder Ganzzahl-Register sind in der Regel höchstens so groß wie die Wortgröße des Prozessorkerns (8, 16, 32 oder 64 Bit). Die Gesamtheit aller Register einer solchen logischen Komponente bezeichnet man als dessen Registersatz. Spezielle Register werden für die Wahl der Betriebsmodi eines Prozessorkerns verwendet. Verschiedene Register dienen zum Zwischenspeichern von Befehlen, Speicheradressen, Rechenoperanden und in Peripheriebausteinen auch zum Zwischenspeichern von Ein- und Ausgabewerten. Die Breite eines Registers wird in Bit angegeben und ist üblicherweise eine Zweierpotenz. 
