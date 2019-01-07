# Protokoll 3 (23.10.2018)

Name: Breitenthaler Lorenz  
Klasse: 4ahme  
KNR: 1  
Gruppe: 1

---
## Inhalte

**1. CPU**  
**2. Simulationen in Atmet Studio**  
**3. Arten von Speichern**  
**4. Ablauf der Übungseinheit**  
**5. Assambler Befehle**  

--- 

## **1** CPU

### **1.1** Aufbau

![Bild: CPU Aufbau](https://github.com/HTLMechatronics/m15-la1-sx/blob/brelom15/cpu.png)

### **1.2** Komponenten

**Programm Counter:** enthält die Adresse des nächsten Befehls

**Befehls-Register:** speichert das Befehlsmuster aus dem Speicher

**Befehls-Decoder:** logische Funktion welche passend zum Befehlsmuster diverse Steuersignale setzt  

**CPU-Register:** bekommt Signal für zwei Register (z.B. R10 und R11), um diese an die ALU weiterzugeben  

**ALU:** bekommt Signal für eine Rechenfunktion, führt diese mit den angelegten Registern durch und gibt das Ergebniss wieder an das CPU-Register zurück  

**Status Register:** setzt und löscht verschiedenste Flags  

**Multiplexer:** Signalweiche um Programmsprünge durchzuführen  

**Stack Pointer:** zeigt auf die Addresse welche den beginn des Stacks kennzeichnet  

### **1.3**  Resets

**Spannungsabfall:** Wird der CPU die Spannung entzogen, bei erneuter Anlegung der Versorgungsspannung beginnt der Programm Counter wieder von 0.

**Reset Pin:** Wird an einem bestimmten Pin eine Spannung angelegt wird der Programm Counter auf 0 gesetzt.

**Watchdog Reset:** Der Watchdog resitiert den µC nachdem ein Kommando in einer gewissen Zeit nicht ausgeführt wurde.

## 2. Simulationen in Atmet Studio

Atmel Studio (in der Version 6.1) ist eine IDEA welche zur Programmierung von Microcontrolern benutzt wird. Sie kann allerdings auch dazu verwendet werden um Programme mit Hilfe eines Debug Tools zu Simulieren. 
Um dies durchzuführen muss zuerst ein neues Projekt angelegt werden, in welchem  der gewünscht Controller ausgewählt werden kann (in unserem Fallder ATmega 328). Daraufhin muss noch in den Einstellungen das "Simulator" Tool als Debugger angegeben werden.  
Nun kann der gewünschte C-Quellcode in die man.c Datei geschrieben werden.  
Startet man nun den Debugger, so werden einem alle relevanten Informationen im "Prozessor Status" Fenster angezeigt.  

_Inhalt:_
 - Program Counter (beinhaltet die Adresse des nächsten Befehls)
 - Stack Pointer (markiert den Beginn des Stacks im Speicher) 
 - X Register (ist ein 16 Bit Register gebildet aus R26, R27)
 - Y Register (ist ein 16 Bit Register gebildet aus R28, R29)
 - Z Register (ist ein 16 Bit Register gebildet aus R30, R31)
 - Status Register (beinhaltet Flags)
 - Cycle Counter (zählt die bereits abgelaufenen Takte)
 - Frequenz
 - Stop watch (zeig die verstrichene Zeit an)

Möchte man nun sein geschriebenes Programm analysieren, muss man es erst compelieren und anschließend lässt sich mit der Funktion "Disassambly"  des Assembler Quelltext generrieren und einlesen. Mit Hilfe des Debuggers kann man nun Schritt für Schritt durch sein Programm gehen und beobachten wie die einzelnen Befähle die Register, Flags usw. verändern. 

## 3. Arten von Speichern

- Flash  
Ist ein nicht-flüchtiger Speicher, welcher mithilfe des Tunneleffekts beschriben wird. Ausßerdem kann der Flash Speicher nur in Segmenten angesprochen werden.  

- SRAM(IRAM)  
gehört zur Familie der flüchtigen Speicher und verliert alle gespeicherten Inhalte wenn die Betriebsspannung abgetrennt wird.

- EEPROM  
Ist ein nicht flüchtiger Speicher, bei dem einzelne Bits angesprohen werden.  

## 4. Ablauf der Übungseinheit

1. Programm
Als erstes haben wir ein einfaches C-Programm mit einer main Funktion ohne Inhalt verfasst. Hirbei wird vom Compiler nur die wichtigsten Befehle durchgeführt damit das Programm überhaupt laufen kann(z.B.: Wird an das CPU-Register R1 eine NUll geschrieben damit das System eine zuverlässige Null hat).

Dazugehöriger Code: 
```
00000000  RJMP PC+0x0034		Relative jump
--- ../../../../crt1/gcrt1.S ---------------------------------------------------
00000034  CLR R1		Clear Register
00000035  OUT 0x3F,R1		Out to I/O location
00000036  SER R28		Set Register
00000037  LDI R29,0x08		Load immediate
00000038  OUT 0x3E,R29		Out to I/O location
00000039  OUTDas 0x3D,R28		Out to I/O location
0000003A  LDI R18,0x01		Load immediate
0000003B  LDI R26,0x00		Load immediate
0000003C  LDI R27,0x01		Load immediate
0000003D  RJMP PC+0x0002		Relative jump
0000003E  ST X+,R1		Store indirect and postincrement
0000003F  CPI R26,0x02		Compare with immediate
00000040  CPC R27,R18		Compare with carry
00000041  BRNE PC-0x03		Branch if not equal
00000042  RCALL PC+0x0003		Relative call subroutine

--- D:\Documents\Atmel Studio\7.0\SXLabor_Uebung\Project\Debug/../src/main.c
int main(void){
	return 0;
}
0000003D  LDI R24,0x00		Load immediate
0000003E  LDI R25,0x00		Load immediate
0000003F  RET 		Subroutine return
```

2. Programm
Anschließend haben wir zwei lokale Variablen angelegt und haben diese miteinander addiert. Die Variablen werden im Stack mit dem Befehl RECAL angelegt. Anschließend wird die Variable a mit der Variable b addiert und auf die Adresse von Variable a gespeichert. 

Dazugehöriger Code(Ohne Standartkonfiguration): 
```
--- D:\Documents\Atmel Studio\7.0\SXLabor_Uebung\Project\Debug/../src/main.c
int main(void){
0000003D  PUSH R28		Push register on stack
0000003E  PUSH R29		Push register on stack
0000003F  RCALL PC+0x0001		Relative call subroutine
00000040  IN R28,0x3D		In from I/O location
00000041  IN R29,0x3E		In from I/O location
    volatile unsigned char a = 0x10;
00000042  LDI R24,0x10		Load immediate
00000043  STD Y+1,R24		Store indirect with displacement
    volatile unsigned char b = 0x20;
00000044  LDI R24,0x20		Load immediate
00000045  STD Y+2,R24		Store indirect with displacement
    return a + b;
00000046  LDD R18,Y+1		Load indirect with displacement
00000047  LDD R24,Y+2		Load indirect with displacement
00000048  LDI R25,0x00		Load immediate
}
00000049  ADD R24,R18		Add without carry
0000004A  ADC R25,R1		Add with carry
0000004B  POP R0		Pop register from stack
0000004C  POP R0		Pop register from stack
0000004D  POP R29		Pop register from stack
0000004E  POP R28		Pop register from stack
0000004F  RET 		Subroutine return
```

3. Programm
Hierbei haben wir das Selbe wie im 2. Programm durchgeführt nur diesmal mit globalen Variablen. Der Unterschied zu lokalen Variablen besteht darin, dass globale Variablen nicht im Stack sonder direkt am Anfang des SRAM's gespeichert werden. Daher empfielt es sich globale Variablen zu verwenden wenn man nur begrenste Speichermöglichkeiten hat.  

Dazugehöriger Code(Ohne Standartkonfiguration):  
```
--- D: \Documents\Atmel Studio\7.0\SXLabor_Uebung\Project\Debug/../src/main.c
int main(void){
    a = 0x10;
00000045  LDI R24,0x10		Load immediate
00000046  STS 0x0101,R24		Store direct to data space
    b = 0x20;
00000048  LDI R24,0x20		Load immediate
00000049  STS 0x0100,R24		Store direct to data space
    return a + b;
0000004B  LDS R18,0x0101		Load direct from data space
0000004D  LDS R24,0x0100		Load direct from data space
0000004F  LDI R25,0x00		Load immediate
}
00000050  ADD R24,R18		Add without carry
00000051  ADC R25,R1		Add with carry
00000052  RET         Subroutine return
```

4. Programm 
Verwirklichung von if Verzweigungen. Hierbei wird mit dem Befehl CPI die beiden Argumente verglichen. Sind diese gleich wird das Zero Flag gesetz und der Code im if Block wird ausgeführt. Ist dies nicht so wird der if Block einfach übersprungen.  

Dazugehöriger Code(Ohne Standartkonfiguration):  
```
--- D: \Documents\Atmel Studio\7.0\SXLabor_Uebung\Project\Debug/../src/main.c
int main(void){
    a = 0x10;
00000045  LDI R24,0x10		Load immediate
00000046  STS 0x0101,R24		Store direct to data space
    if(a == 0x10){
00000048  LDS R24,0x0101		Load direct from data space
0000004A  CPI R24,0x10		Compare with immediate
0000004B  BRNE PC+0x05		Branch if not equal
        b = 0x20;
0000004C  LDI R24,0x20		Load immediate
0000004D  STS 0x0100,R24		Store direct to data space
0000004F  RJMP PC+0x0004		Relative jump
        b = 0x30;
00000050  LDI R24,0x30		Load immediate
00000051  STS 0x0100,R24		Store direct to data space
    return a + b;
00000053  LDS R18,0x0101		Load direct from data space
00000055  LDS R24,0x0100		Load direct from data space
00000057  LDI R25,0x00		Load immediate
}
00000058  ADD R24,R18		Add without carry
00000059  ADC R25,R1		Add with carry
0000005A  RET 		Subroutine return
```


## 5. Assambler Befehle 

RJMP --> Relativer Programmsprung (bsp.: RJMP 0x0034)  
CLR --> löscht wert aus Register (bsp.: CLR R1 (Compiler benutzt R1 als stabile 0))  
OUT —> Speichert Daten aus register x in ein IO register (bsp.: OUT 0x3F, R1)  
SER —> setzt all bits in register (bsp.: SER R28)  
LDI —> Lädt eine 8-Bit-Konstante direkt in Register 16 bis 31.(bsp.: LDI R29, 0x08)  
RCALL —> ist ein relatiever jump und der stack pointer wird um 2 verringert. Wird für den Rücksprung aus einer Funktion genutzt.   
RET —> holt die im Stack gespeicherte Adresse  
PUSH —> Speichert Register im Stack zwischen (bsp.: PUSH R28)  
POP —> Holt den Wert vor dem return wilder aus dem Stack  
IN —> holt werte aus dem IO register  
STD —> erzeugt eine lokale Variable

Liste aller Assembler Befehle [hier](data/Assemblerbefehle.pdf).
