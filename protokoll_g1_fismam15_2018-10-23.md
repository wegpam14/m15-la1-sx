# Protokoll 3 (23.10.2018)
Name: Fischer Maximilian  
KNr.: 2  
Klasse: 4AHME  
Gruppe: 1  

___
### Übersicht

1. CPU
    1. Schema
    1. Funktionsweise der Komponenten
    1. Arten von Resets
1. Speicherarten
1. Atmel Studio
    1. Generelle Informationen
    1. X, Y, Z- Register
    1. Stack Pointer
    1. Startup Routine
    1. Simulations-Übungen
        1. Leeres Programm *(return 0)*
        1. Addieren von zwei lokalen Variablen
        1. Addieren von zwei globalen Variablen
        1. Verzweigung
___

## **1** CPU

### **1.1** Schema

![Bild: CPU Schema](https://github.com/HTLMechatronics/m15-la1-sx/blob/fismam15/cpu_schema.svg)

### **1.2** Funktionsweise der Komponenten

**Programm Counter:** enthält die Adresse des nächsten Befehls

**Befehls-Register:** speichert das Befehlsmuster welches aus dem Speicher kommt

**Befehls-Decoder:** logische Funktion welche abhängt vom Befehlsmuster diverse Steuersignale richtig setzt, damit der Befehl richtig ausgeführt wird

**CPU-Register:** bekommt Signal für zwei Register (z.B. R10 und R11), um diese an die ALU weiterzugeben

**ALU:** bekommt Signal für eine Rechenfunktion

**Status Register:** setzt und löscht verschiedenste Flags wie z.B. Zero-Flag, Carrie-Flag, Overflow-Flag

**Multiplexer:** Signalweiche

**Stack Pointer:** zeigt auf die aktuelle Stelle des Stacks

### **1.3**  Arten von Resets

**Spannungsabfall:** Wird der CPU die Spannung entzogen, bei erneuter Anlegung der Versorgungsspannung beginnt der Programm Counter wieder von 0.

**Reset Pin:** Wird an einem bestimmten Pin eine Spannung angelegt wird der Programm Counter auf 0 gesetzt.

**Watchdog Reset:** Der Watchdog resitiert den µC nachdem eine gewisse Zeit ein Kommando nicht ausgeführt wurde.

___

## **1** Speicherarten

In jedem µC gibt es mehrere Arten von Speicher. Diese können in folgende Arten eingeordnet werden:

- Programmspeicher *(Flash)*
    - 32kiB
    - nicht flüchtig
    - wird in Segmenten angesprochen *(64 Bytes)*
- Arbeitsspeicher *(SRAM)*
    - 24kiB im Fall vom Atmega328P
    - flüchtig
    - Der Arbeitsspeicher eines Systems ist die Bezeichnung für den Speicher der die geraden auszuführenden Programme oder Programmteile und die dabei benötigten Daten enthält.
- Electrically Erasable programmable Read-Only Memory *(EEPROM oder auch E²PROM)*
    - nicht flüchtig
    - jedes Bit kann einzeln programmiert werden
    - Wird meistens zum Kalibrieren verwendet.
    - Besteht aus Feldeffekttransistoren, es wird der Tunneleffekt genutzt. *(Dieser führt bei höhren Temperaturen zu Problemen)*

___

## **1** Atmel Studio

Atmel Studio ist ein Simulationsprogramm mit dem am PC ein µC simuliert werden kann.
Im Unterricht wurde das **Atmel Studio 6** genutzt, zuhause habe ich mit **Atmel Studio 7** gearbeitet.

### **1.1** Generelle Informationen

Das **[Instruction Set Manual](http://ww1.microchip.com/downloads/en/devicedoc/atmel-0856-avr-instruction-set-manual.pdf)** enthält und erklärt alle verfügbaren Befehlsmuster.

### **1.2** X, Y, Z -Register
Die letzten 6 Register kann man zu 3 sogennanten 16 Bit Register zusammenfassen:

- **X-Register:** wird aus **R26** und **R27** gebildet
- **Y-Register:** wird aus **R28** und **R29** gebildet
- **Z-Register:** wird aus **R30** und **R31** gebildet

### **1.3** Stack-Pointer

Ein Register welches auf die letzte Benützte Adresse des Stacks zeigt.

### **1.4** Startup Routine

Der µC führt bei jedem Start eine bestimmte Startup Routine aus die folgende Ziele hat:

- R1 wird auf 0 gesetzt
- Die Statusflags werden zurückgesetzt
- Der Stack-Pointer wird inizialisiert
- Ein Spring zum eigentlichen Programm wird ausgeführt

Das Disassembly der Startup Routine sieht wie folgt aus:
```
00000000  RJMP PC+0x0034		Relative jump
--- ../../../../crt1/gcrt1.S ---------------------------------------------------
00000034  CLR R1		Clear Register
00000035  OUT 0x3F,R1		Out to I/O location
00000036  SER R28		Set Register
00000037  LDI R29,0x08		Load immediate
00000038  OUT 0x3E,R29		Out to I/O location
00000039  OUT 0x3D,R28		Out to I/O location
0000003A  LDI R18,0x01		Load immediate
0000003B  LDI R26,0x00		Load immediate
0000003C  LDI R27,0x01		Load immediate
0000003D  RJMP PC+0x0002		Relative jump
0000003E  ST X+,R1		Store indirect and postincrement
0000003F  CPI R26,0x02		Compare with immediate
00000040  CPC R27,R18		Compare with carry
00000041  BRNE PC-0x03		Branch if not equal
00000042  RCALL PC+0x0003		Relative call subroutine
```

### **1.5** Simulations-Übungen

Im Unterricht haben wir 4 verschiedene Programme geschrieben und diese simuliert.
Um ein Programm zu schreiben muss im Atmel Studio ein neues Projekt angelegt werden. Dazu einfach:

New project -> GCC-C Project -> Atmega328P

Danach schrieben und wir folgende programme, von welchen wir uns im Nachhinein das Disasseembly angeschaut haben:

Nachdem man ein Programm geschrieben hat kann man über `start debugging and break` das geschriebene Programm simulieren.


#### **1.6.1** Simulations-Übung 1: Leeres Programm (return 0)

Das C-Programm der 1. Übung sieht wie folgt aus:
```C
int main(void){
    return 0;
}
```

Disassembly der 1. Übung ohne startupcode:

```
--- N:\ftp\hooks\data-with-backup\simulated\windows\Users\Fischer\Maximilian\Shared\Documents\Atmel Studio\7.0\BoardProject1_Gcc__Uebung\Project\Debug/../src/main.c
int main(void){
	return 0;
}
0000003D  LDI R24,0x00		Load immediate
0000003E  LDI R25,0x00		Load immediate
0000003F  RET 		Subroutine return
```


Die Register `R24` und `R25` werden für den Rückgabewert verwendet.
Mit `LDI´R24, R25` wird in beide Register eine 0 geschrieben, somit ist der Rückgabewert des Programms 0.

#### **1.6.2** Simulations-Übung 2: Addieren von zwei lokalen Variablen

Das C-Programm der 2. Übung sieht wie folgt aus:
```C
int main(void){
    volatile unsigned char a = 0x10;
    volatile unsigned char b = 0x20;
    return a + b;
}
```

Disassembly der 2. Übung ohne startupcode:
```
--- N:\ftp\hooks\data-with-backup\simulated\windows\Users\Fischer\Maximilian\Shared\Documents\Atmel Studio\7.0\BoardProject1_Gcc__Uebung\Project\Debug/../src/main.c
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

Mit `PUSH R28, R29` werden die aktuellen Inhalte von R28 und R29 auf dem Stack abgelegt. Diese werden am Ende des Programms mit `POP R29, R28` wieder zurückgeholt.


#### **1.6.3** Simulations-Übung 3: Addieren von zwei globalen Variablen

Das C-Programm der 3. Übung sieht wie folgt aus:
```C
volatile unsigned char a;
volatile unsigned char b;

int main(void){
    a = 0x10;
    b = 0x20;
    return a + b;
}
```

Disassembly der 3. Übung ohne startupcode:
```
--- N:\ftp\hooks\data-with-backup\simulated\windows\Users\Fischer\Maximilian\Shared\Documents\Atmel Studio\7.0\BoardProject1_Gcc__Uebung\Project\Debug/../src/main.c
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
00000052  RET 		Subroutine return
```

An dieser Übung kann man sehen, dass globale Variablen auch teilweise zu einem effizienteren/kürzerem Programm führen können.
Da die Variablen in diesem Beispiel global sind *(also im Speicher liegen)* muss mithilfe von `PUSH` und `POP` nicht mit dem Stack gearbeitet werden.

#### **1.6.4** Simulations-Übung 4: Verzweigung

Das C-Programm der 4. Übung sieht wie folgt aus:
```C
volatile unsigned char a;
volatile unsigned char b;

int main(void){
    a = 0x10;
    if(a == 0x10){
        b = 0x20;
    } else {
        b = 0x30;
    }
    return a + b;
}
```

Disassembly der 4. Übung ohne startupcode:
```
--- N:\ftp\hooks\data-with-backup\simulated\windows\Users\Fischer\Maximilian\Shared\Documents\Atmel Studio\7.0\BoardProject1_Gcc__Uebung\Project\Debug/../src/main.c
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
___

