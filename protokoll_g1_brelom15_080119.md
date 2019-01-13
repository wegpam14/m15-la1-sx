# Protokoll 4 (08.01.2019)

Name: Breitenthaler Lorenz  
Klasse: 4ahme  
KNR: 1  
Gruppe: 1

---
## Inhalte

**1. Übersetzungsvorgang in C**  
**2. Übersetzung mit Make**  
**3. Ablauf der Übung**  

--- 

## 1. Übersetzungsvorgang in C

### 1.1 Theoretische Grundlagen

Die Übersetzung des in C programmiertem Quelltext in eine von der CPU lesbaren sprache ist in mehrere Schritte unterteilt.

Convertieren in die Maschinensprache:  
1. Preprozessing (der C-Quelltext wird in Prozessoranweisungen umgeschrieben)  
2. Compiler (Erzeugt eine Assembler Quelltext Datei)  
3. Assembler (erzeugt aus dem Assembler Quelltext eine Objectdatei)  
4. Linker (weißt die Adressen zu und das Programm ist ausführbar)  


_Compiler:_GNU Compiler, Visual C/C++ Compiler;

### 1.2 Praktische Umsetzung

In unserem Beispiel haben wir den gcc Compiler unter Ubuntu benutzt. Dieser wird für gewöhnlich mit der Terminalanweisung `gcc`
gestartet. Dahinter wird anschließend noch eine Option und der Name des Quelltextes angegeben (bsp: `gcc -E main.c`).
Wenn der Befehl ohne option ausgeführt wird Kompiliert der compiler das Vorliegende Programm mit allen Schritten auf einmal durch.
Um nun aber alle Schritte einzeln durchzuführen sind verschiedene Optionen nötig welche im Manual des `gcc` Befehls einzulesen sind.
1. Um das Preprocessing durchzuführen muss der Befehl `gcc -E main.c` ausgeführt werden. Somit wird aus der main.c eine main.pp Datei.  
2. Für die Transformation in den Assembler Quelltext muss der Befehl `gcc -S main.c` ausgeführt werden um die main.s Datei zu bekommen.  
3. Um daraus nun die Objektdatei zu erhalten muss der Befehl `gcc -c main.c` ausgeführt werden um die main.o Datei zu erhalten.

---
## 2. Make

Make ist ein Build-Management-Tool, das Kommandos in Abhängigkeit von Bedingungen ausführt, welche im so genannten Makefile angeführt werden.
Es wird hauptsächlich bei der Softwareentwicklung als Programmierwerkzeug eingesetzt da es den Kompiliervorgang von großen Projekten 
um einiges effizienter gestaltet. Dies wird erreicht indem nur Datein neu kompiliert werden, welche einer Änderung unterzogen wurden.
Die restlichen werden nicht angerührt sondern nur neu gelinkt.

**Aufbau des Makefiles:** 

```
Ziel(z.B.: ue03) : Abhängigkeit (z.B.:main.o)
    Kommandos(z.B.: gcc -o ue03 main.o)
```

**Vorgehensweise:**  
 - Es wird geprüft ob Abhängigkeiten als Ziel aufgeführt wurden  
 - Falls keine Abhängigkeit mit entsprechendem Namen vorhanden ist, wird eine Datei mit folgendem Namen gesucht.
 - Ist eine vorhanden wird dessen Zeitstempel überprüft  
 - Wenn die Quelltextdatei älter als die kompilierte ist, kann das Ziel Übersprungen werden   
 
Tritt bei der ausführung eines Kommandos ein Fehler auf, wird der vorgang abgebrochen und die folgenden Komandos werden nicht ausgeführt. Dies kann man verhindern indem man ein "-" vor alle Kommandoes schreibt bei welchen ein fehler auftreten kann.   










