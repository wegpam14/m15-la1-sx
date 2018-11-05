# Protokoll 3 (23.10.2018)

Name: Breitenthaler Lorenz  
Klasse: 4ahme  
KNR: 1  
Gruppe: 1

---
## Inhalte

**1. Simulationen in Atmet Studio**  
**2. Arten von Speichern**  
**3. Ablauf der Übungseinheit**  
**4. Assambler Befehle**  

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

Möchte man nun sein geschriebenes Programm analysieren, muss man es erst compelieren und anschließend lässt sich mit der Funktion "Disassambly"  des Assembler Quelltext generrieren und einlesen. Mit Hilfe des Debuggers kann man nun Schritt für Schritt durch sein Programm gehen und beobachten wie die einzelnen Befähle die Register, Flags usw. verändern. 

## 2. Arten von Speichern

- Flash  
Ist ein nicht-flüchtiger Speicher, welcher mithilfe des Tunneleffekts beschriben wird. Ausßerdem kann der Flash Speicher nur in Segmenten angesprochen werden.  

- SRAM(IRAM)  
gehört zur Familie der flüchtigen Speicher und verliert alle gespeicherten Inhalte wenn die Betriebsspannung abgetrennt wird.

- EEPROM  
Ist ein nicht flüchtiger Speicher, bei dem einzelne Bits angesprohen werden.  

## 3. Ablauf der Übungseinheit

1. Programm
Als erstes haben wir ein einfaches C-Programm mit einer main Funktion ohne Inhalt verfasst. Hirbei wird vom Compiler nur die wichtigsten Befehle durchgeführt damit das Programm überhaupt laufen kann(z.B.: Wird an das CPU-Register R1 eine NUll geschrieben damit das System eine zuverlässige Null hat).

2. Programm
Anschließend haben wir zwei lokale Variablen angelegt und haben diese miteinander addiert. Die Variablen werden im Stack mit dem Befehl RECAL angelegt. Anschließend wird die Variable a mit der Variable b addiert und auf die Adresse von Variable a gespeichert. 

3. Programm
Hierbei haben wir das Selbe wie im 2. Programm durchgeführt nur diesmal mit globalen Variablen. Der Unterschied zu lokalen Variablen besteht darin, dass globale Variablen nicht im Stack sonder direkt am Anfang des SRAM's gespeichert. Daher empfielt es sich globale Variablen zu verwenden wenn man nur begrenste Speichermöglichkeiten hat.  

4. Programm 
Verwirklichung von if Verzweigungen. Hierbei wird mit dem Befehl CPI die beiden Argumente verglichen. Sind diese gleich wird das Zero Flag gesetz und der Code im if Block wird ausgeführt. Ist dies nicht so wird der if Block einfach übersprungen.  

## 4. Assambler Befehle 

RJMP --> Relativer Programmsprung (bsp.: RJMP 0x0034)  
CLR --> löscht wert aus Register (bsp.: CLR R1 (Compiler benutzt R1 als stabile 0))  
OUT —> Speichert Daten aus register x in ein IO register (bsp.: OUT 0x3F, R1)  
SER —> set all bits in register (bsp.: SER R28)  
LDI —> Lädt eine 8-Bit-Konstante direkt in Register 16 bis 31.(bsp.: LDI R29, 0x08)  
RCALL —> ist ein relatiever jump und der stack pointer wird um 2 verringert. Wird für den Rücksprung aus einer Funktion genutzt.   
RET —> holt die im Stack gespeicherte Adresse  
PUSH —> Speichert Register im Stack zwischen (bsp.: PUSH R28)  
POP —> Holt den Wert vor dem return wilder aus dem Stack  
IN —> holt werte aus dem IO register  
STD —> erzeugt eine lokale Variable

Liste aller Assembler Befehle [hier](data/Assemblerbefehle.pdf).
