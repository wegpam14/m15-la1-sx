 # 1. Protokoll	
 - Name: Lara Hofer
 - Datum, Ort: 23. Oktober 2018, AUT Labor Kaindorf
 - Gruppe: 1
 - Anwesend: Breitenthaler, Fischer, Grebien, Hofer, Hörmann, Kahr
 - Abwesend: -

## Inhaltsangabe

 1. Allgemeines zum Atmel Studio
 	1.1 Struktur einer CPU
	1.2 Beschreibung des Blockdiagramms
 2. Benutzung des Atmel Studios
 	2.1 Erklärung
	2.2 wichtige Begriffe

## Atmel Studio
#### Was ist das Atmel Studio?
Das **Atmel Studio** (vor Version 6: "**AVR Studio**") ist eine kostenlose Entwicklungsumgebung ([IDE](https://www.mikrocontroller.net/articles/Editoren/IDEs "Editoren/IDEs")) für die Programmierung der AVR - Mikrocontroller und ARM-Mikrocontroller (ab Version 6) von Atmel. Sie basiert ab Version 5 auf der Visual Studio Shell von Microsoft und besteht aus einer Projektverwaltung, einem [Editor](https://www.mikrocontroller.net/articles/Editoren/IDEs#Texteditoren_f.C3.BCr_Programmierer "Editoren/IDEs"), einem [Debugger](https://www.mikrocontroller.net/articles/AVR-Studio#Debugger "AVR-Studio") und Werkzeugen zum Beschreiben der Mikrocontroller.
Mit dem Atmel Studio kann in [Assembler](https://www.mikrocontroller.net/articles/Assembler "Assembler") sowie in [C](https://www.mikrocontroller.net/articles/C "C")/[C++](https://www.mikrocontroller.net/articles/C-Plusplus "C-Plusplus") programmiert werden.
#### Struktur einer CPU
![Blockdiagramm CPU](https://screenshotscdn.firefoxusercontent.com/images/ceda06ce-9a71-4fdb-980c-8f7ba00734cd.png)
#### Beschreibung des Blockdiagramms
*Program Counter:* Er enthält die Adresse des nächsten Befehls.
*Befehls-Register:* Er speichert das Befehlsmuster.
*Befehls-Decoder:*  Im Befehls-Decoder befinden sich Logische Funktion, abhängig vom Befehlsmuster.
*Multiplexer*:  Ist die Signalweiche für einen Programmsprung.
*Status-Register:* Dient zum Setzen und Löschen von Flags.
## Benutzung des Atmel Studios
#### Erklärungen
Um mit diesem Programm arbeiten zu können muss erstmals ein Projekt unter 'New Project' angelegt werden und weiters muss man auch den µC auswählen (in unserem Fall 'Atmega328'). Auf der Benutzungsoberfläche erscheint rechts mit dem Namen 'Prozessor' in dem befand sich:

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

Speicherarten in AVR und megaAVR µC:
1. Flash
2. SRAM
3. E²PROM
- E²PROM: jedes Bit wird einzeln programmiert
- Flash: kann nur in Segmenten angesprochen werden 
- Kurze Info am Rande: 
-> SRAM wird zu IRAM in diesem Programm.
-> E²PROM wird zu EEPROM in diesem Programm.

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
Somit wird die Zwischenspeierung wieder zurück geholt.

`IN` 
 Holt es sich aus dem I/O Register und speichert es in die Register zurück.
 - Variable definieren = Platz im Stack machen:
	r26,r27 ->x
	r28,r29 ->y
	r30,r31 ->z

`LD`
Additionsbefehl; Carry Flag

` POP R0`
Variablen werden wieder Freigegeben.
*Globale Variablen*: Man spart sich das Reservieren im Stack, die Werte werden gleich am Anfang des SRAMS gespeichert

`BRNE` 
Springe wenn Z-Flag = 0.
 

 


