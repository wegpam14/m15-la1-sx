 # Protokoll der 4. Einheit (08.01.2019)
  Name: 		Hörmann
  Gegenstand: Labor
  Lehrer: SX
  Klasse: 4AHME
  Gruppe: 1
  ## Inhaltsverzeichnis

 1. Übersetzungsvorgang
 2. Makefile
 3. Befehle
 
 ## 1. Übersetzungsvorgang
 ### 1.1  Vorgang
 ![ 
 ](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoestm15/hoestm15/cpu_svg.svg)
 
__Programm Counter:__ enthält die Adresse des nächsten Befehls
__Befehls Register: __ Speichert das Befehlsmuster das aus dem Speicher kommt
__Befehls Decoder:__ gibt Steuersignale aus (z.B. Signal an das CPU Register welche Register verwendet werden sollen
__Multiplexer:__ Signal weiche die dafür sorgt das der Programm Counter weitergezählt wird
__Status Register:__ Setz die verschiedenen Flags

## 2. Mikrocontroller

### 2.1  Theorie

__megaAVR Microcontroler__ 
 _Speicher:_ 
	

 -  __Flash Speicher__ (digitale Speicherbausteine die eine nichtflüchtige Speicherung bei geringen Energieverbrauch ermöglichen | Eine besondere Bauform des EEPROM; das löschen und reprogrammieren des Bausteins erfolgt besonders schnell)
 - __SRAM__ (IRAM | Static RAM | Die Speicherzellen behalten Ihren Inhalt solange der Baustein mit ausreichend Spannung versorgt wird)
 - __EEPROM__ (Electrical Eraseable PROM | Wiederprogrammierbares ROM das auf elektrische Weise gelöscht werden kann)

__Reset Arten:__ 
(Programm Counter wird "normalerweise" auf 0 gesetzt)

 - "Spannungs" Reset (Der CPU wird die Spannung entzogen, durch diesen Effekt wird der Programm Counter auf 0 gesetzt)
 - Reset Pin (Ein gewisser Pin bekommt eine Signal und setzt den Programm Counter somit auf 0, beim ATmega 328: PIN1 )
 - Watchdog Reset (Wird verwendet um die Funktion der Komponenten zu überwachen, erkennt der Watchdog Timer eine Fehlfunktion, so wird eine geeignete Sprunganweisung eingeleitet, diese kann z.B auf den 0ten Befehl im Programm Counter gehen.)

 

# 3 ATMEL Studio


### 3.1 Erstes einfaches Programm
__Die ersten Schritte__
1. Ein neues Projekt in ATMEL Studio anlegen
2. Board auswählen: In unserem Beispiel wurde das STK600-ATmega328 benutzt
3.  Danach erstellten wird eine Simple main Funktion.
![main funktion](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoestm15/hoestm15/ersteMainFunktion.PNG)



5. Beim ersten debuggen(F11) wird eine Fehlermeldung ausgegeben, diese öffnet ein neues Fenster, in dem neu geöffneten Fenster muss man nun bei  "Selected Debugger / programmer" den Simulator auswählen.

![Simulator asuwählen](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoestm15/hoestm15/simulationAusw%C3%A4hlen.PNG)

6. Nach dem erneuten debuggen, kann man auf der Icon leiste das Symbol für Disassembly ![ ](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoestm15/hoestm15/disassembly.PNG) auswählen, dort sieht man das Programm in den einzelnen Assembly Befehlen zerlegt.
![In Assembly codierte Maschinenbefehle](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoestm15/hoestm15/assembler%20codierte%20maschienenbefehle.PNG)

7. Nun begannen wir die einzelnen Befehle nachzuschlagen und deren Bedeutung zu verstehen.

__Assembly Befehle__
		
		00000000  RJMP PC+0x0034		Relative jump 
_Sprung zu einer Adresse im Bereich PC - 2k +1 und PC + 2k_

 Operation: __PC ← PC + k + 1__

		 00000034  CLR R1		Clear Register 
_Reinigt alle Bits im Register R1, da das Register R1 immer 0 sein muss._
Operation: __Rd ← Rd ⊕ Rd__


	00000035  OUT 0x3F,R1		Out to I/O location 
_Speichert Daten von Registern in die I/O Register, und setzt alle Statusflags auf 0_

(I/O Register z.B. DDRA, DDRAB...)
  
Operation: __I/O(A) ← Rr__
	
	00000036  SER R28		Set Register 

_Set all Bits in Register_

Operation:__Rd ← $FF__

	00000037  LDI R29,0x08		Load immediate 
	
_Ladet eine 8 Bit constante in eine Register zwischen 16 und 31_

Operation:__Rd ← K__


	00000038  OUT 0x3E,R29		Out to I/O location 
  
_setzt R28 auf I/O_

Operation: __I/O(A) ← Rr__


	00000039  OUT 0x3D,R28		Out to I/O location 
  
_Stackpointer bekommt die letzte Adresse im Speicher_

Operation: __I/O(A) ← Rr__

	0000003A  RCALL PC+0x0003		Relative call subroutine 
  
_Ein relativer Aufruf einer Adresse im Bereich PC - 2k + 1 und PC + 2k. Die Rücksprungadresse ist im Stack gespeichert._

Operation: __ PC ← PC + k + 1__


	0000003B  RJMP PC+0x0005		Relative jump 
  
_Sprung zu einer Adresse im Bereich PC - 2k +1 und PC + 2k_

 Operation: __PC ← PC + k + 1__


	0000003C  RJMP PC-0x003C		Relative jump 
  
_Sprung zu einer Adresse im Bereich PC - 2k +1 und PC + 2k_

 Operation: __PC ← PC + k + 1__


__Start der Main Funktion__

	0000003D  LDI R24,0x00		Load immediate 

_Ladet eine 8 Bit constante in eine Register zwischen 16 und 31_

Operation:__Rd ← K__

Speicher 0 (return 0) in das Register R24

	0000003E  LDI R25,0x00		Load immediate 
_Ladet eine 8 Bit constante in eine Register zwischen 16 und 31_

Operation:__Rd ← K__

Speicher 0 (return 0) in das Register R25

	0000003F  RET 		Subroutine return 

_Returns von Subroutine. Die Rücksprungadresse wird vom Stack geladen._

Operation:__PC(15:0)__ ← STACKDevices with 16 bits PC, 128K bytes Program memory maximum.

Operation:__PC(21:0)__ ← STACKDevices with 22 bits PC, 8M bytes Program memory maximum.
	
	00000040  CLI 		Global Interrupt Disable 
		
_Bereinigt das GlobalInteruptFlag (I) im SRGE (Status Register). Dies führt dazu, das alle Prozesse beendet werden._

Operation:__I ← 0__


	00000041  RJMP PC-0x0000		Relative jump 
  
_Programm ist beendet und verhaart in einer Endlosschleife._

![Assembly Befehle der Main Funktion](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoestm15/hoestm15/maincassembler.PNG)

### Das Zweite Programm: zurückgeben von Variablen 

Durch die Programmoptimierung des Compilers wird das Programm nicht sehr groß sein, aus diesem Grund werden die Variablen mit dem Schlüsselwort __volatile__ versehen, dies sagt dem Compiler das sie sich jederzeit ändern können, somit behandelt er sie gleich, als würden die Variablen von einem Benutzer eingegeben werden. 

![Main Funktion mit volatile Variablen](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoestm15/hoestm15/zweitemainvolatile.PNG)
![Main Funktion mit volatile Variablen Assembly](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoestm15/hoestm15/zweitemainvolatileAssembly.PNG)

Da der "Header" der Assembly Befehle immer gleich ist, wird er weggelassen und es wird direkt bei der Main Funktion gestartet. 

	0000003D  PUSH R28		Push register on stack 
  
Speichert den Inhalt des Registers am Stack, der Stack Pointer wird nach der Operation um 1 verringert. 

Operation:__STACK ← Rr__

	0000003E  PUSH R29		Push register on stack 
  
Speichert den Inhalt des Registers am Stack, der Stack Pointer wird nach der Operation um 1 verringert. 

Operation:__STACK ← Rr__

	0000003F  RCALL PC+0x0001		Relative call subroutine 
  
_Ein relativer Aufruf einer Adresse im Bereich PC - 2k + 1 und PC + 2k. Die Rücksprungadresse ist im Stack gespeichert._

 Operation: __ PC ← PC + k + 1__

	00000040  IN R28,0x3D		In from I/O location 
  
Ladet Daten von I/O Plätzen in das gewählte Register

Operation:__Rd ← I/O(A__

	00000041  IN R29,0x3E		In from I/O location 
  
Ladet Daten von I/O Plätzen in das gewählte Register

Operation:__Rd ← I/O(A)__

	00000042  LDI R24,0x10		Load immediate 
  
_Ladet eine 8 Bit constante in eine Register zwischen 16 und 31_

Operation:__Rd ← K__

Speichert den Wert 0x10 in das Register R24

	00000043  STD Y+1,R24		Store indirect with displacement 
  
Speichert einen Byte von R 24 direkt in Y+1.

Operation: __Rd ← K__

	00000044  LDI R24,0x20		Load immediate 
  
_Ladet eine 8 Bit constante in eine Register zwischen 16 und 31_

Operation:__Rd ← K__

Speichert den Wert 0x20 in das Register R24

	00000045  STD Y+2,R24		Store indirect with displacement 
  
Speichert einen Byte von R 24 direkt in Y+2.

Operation: __Rd ← K__

	00000046  LDD R18,Y+1		Load indirect with displacement 
  
Setzt R18 auf den Wert von Y+1 (Da sich durch das Schlüsselwort volatile die Werte geändert haben könnten)

Operation:__Rd ← (Y)__

	00000047  LDD R24,Y+2		Load indirect with displacement 
  
Setzt R24 auf den Wert von Y+2 (Da sich durch das Schlüsselwort volatile die Werte geändert haben könnten)

Operation:__Rd ← (Y)__

	00000048  LDI R25,0x00		Load immediate 

_Ladet eine 8 Bit constante in eine Register zwischen 16 und 31_

Operation:__Rd ← K__

R25 wird auf 0x00 gesetzt

	00000049  ADD R24,R18		Add without carry 
  
_Addiert zwei Register ohne dem Carry Flag und speichert das Ergebnis in das zweit genannte Register_

Addiert R24 mit R18 und speichert das Ergebnis in R24

Operation:__Rd ← Rd + Rr__


	0000004A  ADC R25,R1		Add with carry 
  
Addiert zwei Register mit dem Carry Flag und speichert das Ergebnis in das zweit genannte Register_
Addiert R25 mit R1 und speichert das Ergebnis in R25

Operation:__Rd ← Rd + Rr + C__

falls das C Flag gesetzt ist steht im R25 jetzt der Wert 0x01

	0000004B  POP R0		Pop register from stack 
  
Läd das Register mi mit einem Byte vom Stack. Der Stack Pointer wird vor dem POP um 1 erhöht und somit freigegeben.

Operation:__Rd ← STACK__

	0000004C  POP R0		Pop register from stack 
  
Läd das Register mi mit einem Byte vom Stack. Der Stack Pointer wird vor dem POP um 1 erhöht und somit freigegeben.

Operation:__Rd ← STACK__

	0000004D  POP R29		Pop register from stack 
  
Läd das Register mi mit einem Byte vom Stack. Der Stack Pointer wird vor dem POP um 1 erhöht und somit freigegeben.

Operation:__Rd ← STACK__

	0000004E  POP R28		Pop register from stack 
  
Läd das Register mi mit einem Byte vom Stack. Der Stack Pointer wird vor dem POP um 1 erhöht und somit freigegeben.

Operation:__Rd ← STACK__


	0000004F  RET 		Subroutine return 
_Returns von Subroutine. Die Rücksprungadresse wird vom Stack geladen._

Operation:__PC(15:0)__ ← STACKDevices with 16 bits PC, 128K bytes Program memory maximum.

Operation:__PC(21:0)__ ← STACKDevices with 22 bits PC, 8M bytes Program memory maximum.


### Das Dritte Programm: das zurückgeben von globalen Variablen
 Das Programm wird kleiner, das der Linker der Variable eine Fixe Speicheradresse zuteilt, reservieren und abbauen am Stack wird daher nichtmehr gebraucht.
 
Beshalb sollte man bei Platz- sowie Zeitprobleme globale Variablen verwenden.
Der AVR Compiler ist bei der Programmoptimierung relativ schlecht, deshalb kann bei großem Platzmangel das Programm selbst Optimiert werden. 


![Main funktion mit globalen Variablen](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoestm15/hoestm15/drittemain.PNG)
![Main Funktion mit globalen Variablen Assembler](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoestm15/hoestm15/drittemainAssembler.PNG)

	00000045  LDI R24,0x10		Load immediate 
_Ladet eine 8 Bit constante in eine Register zwischen 16 und 31_

Operation:__Rd ← K__

Ladet den Wert 0x10 in das Register R24

	00000046  STS 0x0101,R24		Store direct to data space 
Speichert den Wert im Register direkt in den "Datenraum".

Operation:__(k) ← Rr__

Speichert den Wert von R24 in die Speicheradresse con 0x0101

	00000048  LDI R24,0x20		Load immediate 
_Ladet eine 8 Bit constante in eine Register zwischen 16 und 31_

Operation:__Rd ← K__

Ladet den Wert 0x20 in das Register R24

	00000049  STS 0x0100,R24		Store direct to data space 
Speichert den Wert im Register direkt in den "Datenraum".

Operation:__(k) ← Rr__

Speichert den Wert von R24 in die Speicheradresse con 0x0100

	0000004B  LDS R18,0x0101		Load direct from data space 
Ladet einen Wert vom Datenraum in das Register

Operation:__Rd ← (k)__

Läd den Wert aus dem Datenraum 0x0101 in des Register R18

	0000004D  LDS R24,0x0100		Load direct from data space 
Ladet einen Wert vom Datenraum in das Register

Operation:__Rd ← (k)__

Läd den Wert aus dem Datenraum 0x0100 in des Register R24

	0000004F  LDI R25,0x00		Load immediate 
_Ladet eine 8 Bit constante in eine Register zwischen 16 und 31_

Operation:__Rd ← K__

Ladet den Wert 0x00 in das Register R25

	00000050  ADD R24,R18		Add without carry 
_Addiert zwei Register ohne dem Carry Flag und speichert das Ergebnis in das zweit genannte Register_

Addiert R24 mit R18 und speichert das Ergebnis in R24

Operation:__Rd ← Rd + Rr__
	
	00000051  ADC R25,R1		Add with carry 
  
Addiert zwei Register mit dem Carry Flag und speichert das Ergebnis in das zweit genannte Register_

Addiert R25 mit R1 und speichert das Ergebnis in R25

Operation:__Rd ← Rd + Rr + C__

falls das C Flag gesetzt ist steht im R25 jetzt der Wert 0x01

	00000052  RET 		Subroutine return 
_Returns von Subroutine. Die Rücksprungadresse wird vom Stack geladen._

Operation:__PC(15:0)__ ← STACKDevices with 16 bits PC, 128K bytes Program memory maximum.

Operation:__PC(21:0)__ ← STACKDevices with 22 bits PC, 8M bytes Program memory maximum.


### Das Vierte Programm: Verzweigungen

![Verzweigung](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoestm15/hoestm15/vierteMainC.PNG)

![Verzweigung Assembler](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoestm15/hoestm15/viertemain.PNG)

	00000045  LDI R24,0x10		Load immediate 
_Ladet eine 8 Bit constante in eine Register zwischen 16 und 31_

Operation:__Rd ← K__

Ladet den Wert 0x10 in das Register R24

	00000046  STS 0x0101,R24		Store direct to data space 
Speichert den Wert im Register direkt in den "Datenraum".

Operation:__(k) ← Rr__

Speichert den Wert von R24 in die Speicheradresse con 0x0101

	00000048  LDS R24,0x0101		Load direct from data space 
Ladet einen Wert vom Datenraum in das Register

Operation:__Rd ← (k)__

Läd den Wert aus dem Datenraum 0x0101 in des Register R24

	0000004A  CPI R24,0x10		Compare with immediate 
  
Führt einen Vergleich zwischen den Register und einer konstanten aus 

Operation:__Rd - K__

Hier wird R24 mit 0x10 verglichen

	0000004B  BRNE PC+0x05		Branch if not equal 
Prüft das Z Flag, ist das Z Flag gesetzt, so springt er auf den angegebenen Befehl.

Operation:__If Rd ≠ Rr (Z = 0) then PC ← PC + k + 1, else PC ← PC + 1__

	0000004C  LDI R24,0x20		Load immediate 
  
_Ladet eine 8 Bit constante in eine Register zwischen 16 und 31_

Operation:__Rd ← K__

Ladet den Wert 0x20 in das Register R24

	0000004D  STS 0x0100,R24		Store direct to data space 
Speichert den Wert im Register direkt in den "Datenraum".

Operation:__(k) ← Rr__

Speichert den Wert von R24 in die Speicheradresse con 0x0100

	0000004F  RJMP PC+0x0004		Relative jump 
_Sprung zu einer Adresse im Bereich PC - 2k +1 und PC + 2k_

 Operation: __PC ← PC + k + 1__
 
	00000050  LDI R24,0x30		Load immediate 
_Ladet eine 8 Bit constante in eine Register zwischen 16 und 31_

Operation:__Rd ← K__

Ladet den Wert 0x30 in das Register R24


	00000051  STS 0x0100,R24		Store direct to data space 
  
Speichert den Wert im Register direkt in den "Datenraum".

Operation:__(k) ← Rr__

Speichert den Wert von R24 in die Speicheradresse con 0x0100


	00000053  LDS R18,0x0101		Load direct from data space 
  
Ladet einen Wert vom Datenraum in das Register

Operation:__Rd ← (k)__

Läd den Wert aus dem Datenraum 0x0101 in des Register R18



	00000055  LDS R24,0x0100		Load direct from data space 
  
Ladet einen Wert vom Datenraum in das Register

Operation:__Rd ← (k)__


Läd den Wert aus dem Datenraum 0x0100 in des Register R24

	00000057  LDI R25,0x00		Load immediate 
  
_Ladet eine 8 Bit constante in eine Register zwischen 16 und 31_

Operation:__Rd ← K__

Ladet den Wert 0x00 in das Register R25


	00000058  ADD R24,R18		Add without carry 
  
_Addiert zwei Register ohne dem Carry Flag und speichert das Ergebnis in das zweit genannte Register_

Addiert R24 mit R18 und speichert das Ergebnis in R24

Operation:__Rd ← Rd + Rr__


	00000059  ADC R25,R1		Add with carry 
  
Addiert zwei Register mit dem Carry Flag und speichert das Ergebnis in das zweit genannte Register_

Addiert R25 mit R1 und speichert das Ergebnis in R25

Operation:__Rd ← Rd + Rr + C__

falls das C Flag gesetzt ist steht im R25 jetzt der Wert 0x01


	0000005A  RET 		Subroutine return 
  
_Returns von Subroutine. Die Rücksprungadresse wird vom Stack geladen._

Operation:__PC(15:0)__ ← STACKDevices with 16 bits PC, 128K bytes Program memory maximum.

Operation:__PC(21:0)__ ← STACKDevices with 22 bits PC, 8M bytes Program memory maximum.


