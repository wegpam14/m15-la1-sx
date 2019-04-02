# Protokoll 4 <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/30/HTL_Kaindorf_Logo.svg/300px-HTL_Kaindorf_Logo.svg.png" alt="">  
  
Professor: SX  
Übungsort: Kaindorf Aut-Labor  
Übungsdatum: 4.12.2018  
Anwesend: Vollmaier Alois, Vezonik Sarah, Wegl Patrick, Wesonig Mercedes, Winter Matthias

## Übersetzungsvorgang eines C-Programms  

1.  Quellcodedatei -> main.c
2.  Compilieren -> Object-Datei (".obj")
3.  Linken -> fertiges Programm (".exe", ".elf")

## Make-tool  
  
Das make-tool ermöglicht es größere Programme aufgeteilt in mehrere Quelldateien zu schreiben, da man sie anschließend in verbindung mit einem Makefile zu einem Programm Verbinden kann.  
Ein großer Vorteil dieser Art der Softwareentwicklung ist, dass man bei änderungen eines Programmteils nur die betroffene Quelldatei neu combilieren muss und nicht das gesammte Projekt.  

### Makefile  
Das Makefile wird mit hilfe eines Editors geschrieben. Im makefile stehen die Wichtigsten Informationen für das make-tool. Es werden Ziel (targets), Abhängigkeiten(dependences) und Befehle(Comands) benötig.
```
Ziel A: Abhängigkeiten  
[tab] Befehl1
[tab] Befehl2
[tab] Befehl3
... 
```  
```
ue04.elf: main.o monitor.o lcd.o  
[tab] gcc -o ue04.elf main.o monitor.o lcd.o  
  
main.o: main.c monitor.h lcd.h  
[tab] gcc -c main.c  
  
monitor.o: monitor.h lcd.h  
[tab] gcc -c monitor.c  
  
lcd.o: lcd.h  
[tab] gcc -c lcd.c  

monitor.o: monitor.h lcd.h  
[tab] -rm *.o  
[tab] -rm *.elf  
```
Wichtig hierbei ist es auf die Formatierung zu achten und bei [tab] einen Tabulator zu setzen. Da ansonsten das Makefile nicht funktioniert.  
### Im Terminal  
Gibt man den Befehl ```make``` in der Console ein, sucht sich das make-tool selbstständig anhand des Makefiles die benötigten Dateien um die Anforderungen des Makefiles zu erfüllen.  
Fals eine *.c Datei einen jüngeren Zeitstempel als die anderen *.c Dateien hat, wird diese neu Kompiliert und an das Projekt angefügt(gelinkt).  
Im Grunde Läuft die Abarbeitung eines Makefiles solange kein Fehler auftritt. Das Stoppen bei Fehlern kann speziell kritisch werden, wenn gerade ein Befehl ausgeführt wird. Um dieses Problem vorzubeugen, wird vor ```rm``` ein ```-``` gesetzt. Dies führt dazu, dass auch bei einem Fehler, der Löschbefehl ausgeführt wird.

#### Touch  
Mit ```touch``` kann man den Zeitstempel von Dateien manuell ändern. Falls noch keine Datei vorhanden ist, erzeugt touch eine neue leere Datei. 

## Übung mit dem Make-tool  
Mit hilfe des nano Editors soll "Hallo, Guten Morgen!" im Terminal ausgegeben werden.  
Der Quelltext der main.c Datei sieht wie folgt aus:
```
#include <stdio.h>  

int main(){  
  
printf("Hallo, Guten Morgen!\n");  
return 0;  
  
}  
```  
Das Makefile für diese Aufgabe sieht wie folgt aus:
```  
#Dies ist ein Komentar  
  
test1: main.o  
  gcc -o test1 main.o

main.o: main.c
  gcc -o main.c  
    
cleanAndBuild: clean test1
  
clean:
  -rm main.o  
  -rm test1  
  
```  
Nun kann die Abarbeitung mit dem Befehl ```make``` gestartet werden.
#### Befehle aus dem Unterricht
Befehl    | Beschreibung  
--------- | -------------  
make clean| Alle von ```make``` erstellten Datein werden gelöscht  
make cleanAndBuild| Alle von ```make``` erstellten Dateien erden gelöscht und danach wider erstellt   
make main.o | Der Quelltext wird in eine Object Datei umgewandelt
