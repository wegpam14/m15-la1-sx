# Przokoll 2

Name: Breitenthaler Lorenz  
Klasse: 4ahme  
KNR: 1  
Gruppe: 1  

--- 

## Inhalte

**1. Übersetzungsvorgang in C**  
  *1.1 Theoretische Grundlagen*  
  *1.2 Praktische Umsetzung*  
**2. Linux Terminal Befehle**

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

### 1.2 Praktische umsetzung

In unserem Beispiel haben wir den gcc Compiler unter Ubuntu benutzt. Dieser wird für gewöhnlich mit der Terminalanweisung `gcc`
gestartet. Dahinter wird anschleißend noch eine Option und der Name des Quelltextes angegeben (bsp: `gcc -E main.c`).
Wenn der Befehl ohne option ausgeführt wird Kompiliert der compiler das Vorliegende Programm mit allen Schritten auf einmal durch.
Um nun aber alle Schritte einzeln durchzuführen sind verschiedene Optionen nötig welche im Manual des `gcc` Befehls einzulesen sind.
//Fortsetzung folgt

## 2. Linux Terminal Befehle

`whoami` --> gibt den aktuellen Benutzer in der Konsole aus  
`pwd`--> Gibt das Verzeichniss zurück in dem grade Gearbeitet wird  
`man` --> Ruft das Manual einer Funktion im less Viewer auf  
`mv` --> Kann das Dateien bewegen  
`cat` --> Gibt den Inhalt eiern Textdatei in der Konsole aus  
`lass` --> ist eine Viewerapplikation  
`nano` --> ist ein primitiver Texteditor in der Konsole  
`hexdump`  
