 # 3. Protokoll	
 - Name: Lara Hofer
 - Datum, Ort: 23. Oktober 2018, AUT Labor Kaindorf
 - Gruppe: 1
 - Anwesend: Breitenthaler, Fischer, Grebien, Hofer, Hörmann, Kahr
 - Abwesend: -

## Inhaltsangabe

 1. CPU
[1.1] Aufbau der CPU
[1.2] Hauptbestandteile der CPU
 2. Mikroprozessor
[2.1] Was ist ein Mikroprozessor?
[2.2] Speicherarten
[2.3] Arten des Resets
 3. Allgemeines zum Atmel Studio
[3.1] Was ist ein Atmel Studio?
 4. Benutzung des Atmel Studios
  4.1 Erklärung
  4.2 wichtige Begriffe

## CPU
#### Aufbau der CPU
![enter image description here](https://screenshotscdn.firefoxusercontent.com/images/ceda06ce-9a71-4fdb-980c-8f7ba00734cd.png)

#### Hauptbestandteile der CPU
***Rechenwerk***
= ALU (Arithmetic Logic Unit) ist das diegitale Schaltwerk zur Durchführung arithmetischer/logischer Befehle (addieren, subtrahieren, schieben, rotieren, NOT, AND, OR, XOR)

***Das Steuerwerk***
ist für die Abarbeitung des Programms (also Befehlskette) verantwortlich. Im Steuerwerk befindet sich der Befehlszähler (Programmcounter, Instruktionpointer) und der Befehls-Decoder.

*Program Counter:* Er enthält die Adresse des nächsten Befehls.
*Multiplexer*:  Ist die Signalweiche für einen Programmsprung.

***Die Register***
sind Speichereinheiten, die direkt mit der Recheneinheit verbunden sind. Sie beinhalten Daten, Operanden und Berechnungsergebnisse in Dualcodierung. 

*Status-Register:* Dient zum Setzen und Löschen von Flags.
*Befehls-Register:* Er speichert das Befehlsmuster.
*Befehls-Decoder:*  Im Befehls-Decoder befinden sich Logische Funktion, abhängig vom Befehlsmuster.

***Die Speicherverwaltungseinheit***
ist für den Zugriff auf den Arbeitsspeicher zuständig. Sie ist bei großen Prozessen durch die MMU realisiert.

***Reset***
bringt die CPU in einen definierten Grundzustand. Register und Status-Flag Register werden in einen definierten Grundzustand gesetzt. Der Befehlszähler (PC) wird auf die Programmstartadresse gesetzt (meist 0).

## Mikroprozessor
#### Was ist ein Mikroprozessor?
Der µC ist eine modernere Form eines Prozessors, bei dem alle Funktionen des Prozessors auf einem Microchip (IC) gefertigt sind.

#### Speicherarten

1. Flash
ist eine besondere Bauform eines EEPROM. Das Löschen und Reprogrammieren erfolgt hier besonders schnell.
- Beim Atmega 328P: 32KiB
- Beim Atmega 16: 16KiB

2. SRAM
= Static RAM. Die Speicherzellen behalten ihren Inhalt solange der Speicherbaustein mit ausreichender Spannung versorgt wird.
- Beim Atmega 328P: 2KiB
- Beim Atmega 16: 1KiB
- Arbeitsspeicher

3. EEPROM
= Electrical Eraseable PROM. WIederprogrammierbares ROM. Kann auf elektrischer Weise gelöscht werden, zB.: durch eine höhere Spannung an einem speziellen Pin. Ein EPROM im Gegensatz konnte damals mit UV-Licht gelöscht werden.
- Beim Atmega 328P: 1024 Bytes
- Beim Atmega 16: 512 Bytes

#### Arten des Resets
1. Watchdog
Löst bei einem Programmabsturz einen Reset aus, damit der µC seine Aufgaben wieder erledigen kann. 

2. Brownout Reset
Er bewirkt, dass ein Computerprozessor im Falle eines Brownouts zurückgesetzt (oder neu gestartet) wird

3. interner Reset
Er findet dann Verwendung, wenn zB. in einem Mikroprozessor - System ein Fehlerverhalten eines Rechnerkerns vorliegt. Dieser kann dann mit dem Reset neu gestartet werden, ohne das er andere, nicht beteiligte, Rechner stört.

## ![enter image description here](https://micrium.com/wp-content/uploads/2012/08/Atmel-Logo.png)
#### Was ist das Atmel Studio?
Das **Atmel Studio** (vor Version 6: "**AVR Studio**") ist eine kostenlose Entwicklungsumgebung ([IDE](https://www.mikrocontroller.net/articles/Editoren/IDEs "Editoren/IDEs")) für die Programmierung der AVR - Mikrocontroller und ARM-Mikrocontroller (ab Version 6) von Atmel. Sie basiert ab Version 5 auf der Visual Studio Shell von Microsoft und besteht aus einer Projektverwaltung, einem [Editor](https://www.mikrocontroller.net/articles/Editoren/IDEs#Texteditoren_f.C3.BCr_Programmierer "Editoren/IDEs"), einem [Debugger](https://www.mikrocontroller.net/articles/AVR-Studio#Debugger "AVR-Studio") und Werkzeugen zum Beschreiben der Mikrocontroller.
Mit dem Atmel Studio kann in [Assembler](https://www.mikrocontroller.net/articles/Assembler "Assembler") sowie in [C](https://www.mikrocontroller.net/articles/C "C")/[C++](https://www.mikrocontroller.net/articles/C-Plusplus "C-Plusplus") programmiert werden.


## Benutzung des Atmel Studios
#### Erklärungen
1. Um mit diesem Programm arbeiten zu können muss erstmals ein Projekt unter 'New Project' angelegt werden und weiters muss man auch den µC auswählen (in unserem Fall 'Atmega328'). Auf der Benutzungsoberfläche erscheint rechts mit dem Namen 'Prozessor' in dem befand sich:

 - der Programmcounter
 -  das X Register
 -  das Y Register
 -  das Z Register
 - das Status Register
 - der Cycle Counter
 - Frequenzy
 - die CPU Register
 
 Der Cycle Counter ist ein Zähler, exestiert aber nicht in der CPU, ebenfalls gibt es auch keine Frequenzy. Näheres zu den CPU Registern:
 - Ein Block, aus jeweils 8 Bit
 - Die Register beginnen bei R0 und enden mit R30
 - Um ein 16-Bit Register zu erstellen werden jeweils 2 8-Bit Register zusammengeführt.
 - 16-Bit Opcode:
k=33
k= 0000 0011 0011
1100 0000 0011 0011
= C	    0		3	3  -> operation code
k= 0x33
PC + k + 1
PC + 0x34

2. Beim erstellten Programm sieht man in der obersten Leiste ein main.c und nach dem debuggen kann man ein Disasseble Fenster auswählen, wo man dann das Programm in einzelnen Assambly Befehlen sehen kann.

![enter image description here](https://microchip.wdfiles.com/local--files/mplabx:debug-disassembly-window/bothopen.png)

Tunneleffekt: Bei Materalien hat man Energieschwellen, dh. da können keine Teilchen durchdringen. Doch irgendwo gibt es einen Punkt wo sie es schaffen durchzukommen, das nennt man dann Tunneleffekt (Flash-Technologie).

#### wichtige Begriffe
*Zum Nachlesen:*
- [megaAVR InstructionSetManual](http://ww1.microchip.com/downloads/en/devicedoc/atmel-0856-avr-instruction-set-manual.pdf)

 `Reset`
 Adresswert = 0 -> Gewisse Register werden auf den Anfang gesetzt.
 
`rjmp` 
 = relative jump (16-bit Operation)
 
`CLR` 
= Clear Register; Er reinigt das Register, das heißt er setzt auf Null.. dazu wird ein Taktzyklus benötigt.

`Compiler`
 Er verwendet R1 ausschließlich als stabile 0.

`OUT`
`I/O Register`
 Beispiele für I/O Register: DDRB/DDRA...
Beispiel: OUT 0x3F -> Welches I/O Register ist das? 

` SER R28`
Setzt alle Bits in Register.

*Mapping im S-RAM*
1. R0...R31
2. I/O Regsiter
3. SRAM

 **!!!** Ein Beispiel um die Suche im Datenblatt zu erleichtern:
  0x3E -> Man muss 20 dazuzählen das man es im Datenblatt findet (0x5E)

`SP = 0x08FF `
= Letzte Speicheradresse

`RCALL` 
= Relative Call to Subroutine; Ein Spungbefehl, der etwas auf dem Stack speichert (Der Stack Pointer wird anschließlich um 2 veringert)
`F11 Stack into`
` F10 Stack over`

`LDI`
 Lade eine Unbekannte ins Register.
 
`RET`
Stack ist quasi wieder leer
`CLI`
 = Clear Global Ingterrupt Flag (I-Flag).
 
`PUSH` 
Stack wird als Zwischenspeicherung verwendet.

`POP` 
Somit wird die Zwischenspeicherung wieder zurück geholt.

`IN` 
 Holt es sich aus dem I/O Register und speichert es in die Register zurück.
 - Variable definieren = Platz im Stack machen:
	r26,r27 ->x
	r28,r29 ->y
	r30,r31 ->z

`LD`
Additionsbefehl; Carry Flagb

` POP R0`
Variablen werden wieder Freigegeben.
*Globale Variablen*: Man spart sich das Reservieren im Stack, die Werte werden gleich am Anfang des SRAMS gespeichert

`BRNE` 
Springe wenn Z-Flag = 0.
 

 

