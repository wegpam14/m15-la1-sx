
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
 ![ Übersetzungsvorgang](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoestm15/hoestm15/Images/Uebersetzungsvorgang__c%2B%2B.jpg) 

Jeder Quellcode muss von einer höheren Programmiersprache in Maschinensprache Übersetzt werden, da der Prozessor nur diese simple Sprache versteht. Diesen Vorgang nennt man Übersetzungsvorgang, dieser ist in C in 3 Bereich aufgeteilt:

#### Präprozessor
Die Präprozessorbefehle beginnen bin einem '#' und enden ohne Semikolon. Der wichtigste Befehl des Präprozessors ist #include. Damit wird der Inhalt einer Datei eingelesen und an dieser Steller platziert, als ob man sie hineinkopiert. Solche Dateien nennt man Header Dateien, da sie in dem Kopf der C_Datei stehen, deshalb auch die Endung '.h'
Es gibt zwei  Varianten von 'include', einmal das einlesen einer selbstgeschriebenen C-Datei mit '#include "..." ' und einmal das einlesen einer Systemdatei die schon in der C Bibliothek ist mit '#include <...>'. 
![Includes in nano](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoestm15/hoestm15/Images/%23include.png)


#### Compiler
Der Compiler liest was der Präprozessor  C Datei gemacht hat und produziert eine Objektdatei '.o'.  Diese enthält Maschinensprache die der Linker benötigt um die verschiedenen Funktionen aus den Objektdateien zu Verknüpfen.
![Compiling Prozess](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoestm15/hoestm15/Images/c-compiling.png)


#### Linker
Der Linker bindet die Objektdatei, die der Compiler erzeugt hat, noch mit "statischen" Funktionsbibliotheken zusammen und erzeugt somit ein ausführbares Programm. 
![Linker](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoestm15/hoestm15/Images/1200px-Linker.svg.png)

## 2. Makefile
Das Kompilieren von Quelltext-Dateien kann mit dem Programm **make** gesteuert werden, dies ist sinnvoll wenn das Projekt groß ist und die Kompilierung aus mehreren Schritten und Abhängigkeiten besteht.

#### Makefile erstellen
 
 Im Makefile werden Zeile definiert, sogenannte **Targets**, welche mit einem Doppelpunkt dargestellt werden. Dieses Target ist immer das Hauptziel, neben den Hauptziel steht die Abhängigkeit die erfüllt sein muss, um das Ziel zu erreichen. In den Zeilen unter dem Ziel stehen die Kommandos die das Ziel zu erreichen.
 ![Makefile](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoestm15/hoestm15/Images/Makefile.png)

Im oberen Beispiel ist das Ziel die 'ue03:' neben den Ziel stehen die Abhängigkeiten 'main.o lcd.o log.o'. Unter dem Ziel und der Abhöngigkeit steht der auszuführende Befehl, in diesem Fall 'gcc -o ue03 main.o lcd.o log.o'.

## 3 Befehle

d
