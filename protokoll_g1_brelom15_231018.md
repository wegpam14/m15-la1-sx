# Protokoll 3 (23.10.2018)

Name: Breitenthaler Lorenz  
Klasse: 4ahme  
KNR: 1  
Gruppe: 1

---
## Inhalte

**1. Simulationen in Atmet Studio** 

--- 

## 1. Simulationen in Atmet Studio

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

Möchte man nun sein geschriebenes Programm analysieren, muss man es erst compelieren und anschließend lässt sich mit der Funktion "Disassambly"  des Assembler Quelltext einlesen. Mit Hilfe des Debuggers kann man nun Schritt für Schritt durch sein Programm gehen und beobachten wie die einzelnen Befähle die Register, Flags usw. verändern. 




## Assambler Befehle 

RJMP --> Relativer Programmsprung (bsp.: RJMP 0x0034)  
CLR --> löscht wert aus Register (bsp.: CLR R1 (Compiler benutzt R1 als stabile 0))  
OUT —> Speichert Daten aus register x in ein IO register (bsp.: OUT 0x3F, R1)  
SER —> set all bits in register (bsp.: SER R28)  
LDI —> Lädt eine 8-Bit-Konstante direkt in Register 16 bis 31.(bsp.: LDI R29, 0x08)  
RCALL —> ist ein relatiever jump und der stack pointer wird um 2 verringert. Wird für den Rücksprung aus einer Funktion genutzt.   
RET —> holt die im Stack gespeicherte Adresse  
PUSH —> Speichert Register im Stack zwischen (bsp.: PUSH R28)  
POP —> Holt den Wert vor dem ret wilder aus dem Stack  
IN —> holt werte aus dem IO register
STD —> 
