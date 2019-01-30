# Protokoll ![](https://www.koerbler.com/neuigkeiten/wp-content/uploads/2013/03/htl-kaindorf.jpg)
**von Anna Murko**  
Datum: 29.01.2019  
Gruppe: 2  
Betreuer: Professor Steiner  
abwesend: -
  
  Thema: **Übersetzungsvorgang am yC**  
  Definition: *Beschreibt wie ein C-Quellcode für den yC in ein ausführbares Programm übersetzt wird.*  

## Inhalt 
1. [Übersetzungsvorgang](https://github.com/HTLMechatronics/m15-la1-sx/blob/muranm15/protokoll_g2_muranm15_2018-01-29.md#1%C3%BCbersetzungsvorgang)   
1. [Make-tool}(https://github.com/HTLMechatronics/m15-la1-sx/blob/muranm15/protokoll_g2_muranm15_2018-01-29.md#2maketool)
1. Makefiles
    1. Aufbau von Makefiles
    1. Zeitstempel
    1. Fehler beim Durchführen der Kommandos
    1. Übersetzung eines Programmes durch ein Makefile
    
  ___  
### 1.Übersetzungsvorgang
Um den C-Code in eine ausführbahre Datei umzuwandeln sind folgende Schritte notwendig:

 Name | Dateityp vorher | Dateityp nacher | Beschreibung
 ------- | --------  |------- | --------  
*Präprozessieren* | main.c | main.? | Bearbeitung von Anweisungen wie `#include`, `#define` und `#if`. Da diese Datei im Normalfall nicht wirklich entsteht, gibt es auch keine eigene Endung.
*Compelieren* | main.? | main.a | Der durch den Präprozzessor bearbeitete Code wird in Assmeblercode umgewandelt
*Assemblieren* | main.a | main.o | Der Assemblercode wird in Maschinencode übersetzt
*Linken* | main.o | main.exe/ main.out |  Alle Programmteile werden durch den Linker vereint. Daraus entsteht ein ausführbares Programm
*Umwandeln* | main.exe/main.out | z.B. main.hex | Die ausführbare Datei wird in ein Format umgewandelt, das der Programmer versteht. (z.B. Hex)

Im Sprachgebrauch werden meist die Schritte des Vorgangs bis zum entstehen einer Beispiel.o-Datei als "**compelieren**" bezeichnet. Ganz grob werden teilweise auch alle hier angeführten Schritte als "**compelieren**" verstanden.
    
 

### 2.Maketool
Der gesamte Übersetzungsvorgang wird im Normalfall durch das **make-Tool** übernommen. Dieses ruft sogenannte *Makefiles*  auf.  

Wenn bei dem Aufruf des Kommandos make ein Makefile im aktuellen Verzeichnis gefunden wird beginnt das Tool automatisch das oberste Ziel im Makefile zu builden.  

Um ein bestimmtes Ziel aufzurufen kann make <target> verwendet werden.

Zuerst werden die Abhängigkeiten des Ziels überprüft und falls kein Ziel mit dem Namen der Abhängigkeit im Makefile vorhanden ist, wird nach einer Datei mit dem Namen gesucht. Ist eine Datei vorhanden wird der Zeitstempel mit dem darüberliegenden Ziel verglichen. Ist die Quelltextdatei älter als das Ziel, wird das Ziel ignoriert und nicht erneut kompiliert


### 3.Makefiles  
Makefiles werden in einem Texteditor geschrieben und beinhalten die Anweisungen für das make-Tool. Sie können nicht nur für den Übersetzungsvorgang von Programmen eingesetzt werden, sondern sie sind auch für andere Anwendungen, in denen die zeitliche Abhängigkeit von Dateien ein Rolle spielt, nützlich. Makefiles sind aus **Zielen**, **Abhängigkeiten** und **Kommandos** aufgebaut.

   #### i.  Aufbau von Makefiles
   
   ```
Ziel 1: Abhängigkeiten 
  ->  Kommando A
  ->  Kommando B
  ->  Kommando C

Ziel 2: Abhängigkeiten
  ->  Kommando A
  ->  Kommando B
```
__*Anmerkung*:__ Für den Tabulator vor den Kommandos müssen echte Tabulatoren verwendet werden, da sonst eine Fehlermeldung ausgegeben wird. Das ist vorallem dann zu beachten, wenn Text kopiert wird, da sich ein Tabulator optisch nicht von Leerzeichen unterscheidet.
   
   #### ii. Funktionsweise von Makefiles
   Beim Aufruf des Makefiles wird zuerst das erste Ziel aufgerufen. Die Abhängigkeiten werden dabei zuerst auf andere Ziele und dann auf Datein untersucht. Bei **anderen Zielen als Abhängigkeit** werden zuerst die abhängigen Ziele  abgearbeitet. Bei **Datein als Abhängigkeit** wird der Zeitstempel von dem Ziel und der Datei verglichen um zu erfassen, ob ein neuerliches Durchführen der Kommandos überhaupt nötig ist. 
   #### iii. Zeitstempel
   Der **Zeitstempel** gibt an wann eine Datei das letzte Mal verändert wurde. Mit dem Befehl `touch <Datei>` kann dieser Zeitstempel auf Linux-Systemen aktualisiert werden.

[Weitere Informmationen zum touch-Befehl](https://wiki.ubuntuusers.de/touch/)  

   #### iv.Fehler beim Durchführen der Kommandos
   
   Wenn das Makefile aufgerufen wird, läuft das Makefile soweit durch, bis ein **Fehler** auftritt. Das bedeutet, dass alle nachfolgenden Schritte nicht abgewickelt werden. Um das bei Befehlen, bei denen Fehler auftreten können, zu verhindern kann ein vor dem jeweiligen Kommando ein `-` eingefügt werden. 

Ob ein **Fehler** aufgetreten ist lässt sich über die Rückgabewerte der Kommandos erfahren. Ist der Rückgabewert ungleich 0, so wird ein Fehler ausgegeben. In der Konsole kann der Rückgabewert des letzten Kommandors mit dem Befehle `echo $?`ausgeben werden
  
  #### v. Übersetzung eines Programms durch ein Makefile
   #### Makefile:
  ```C
  a.out: main. o lcd.o log.o
          gcc main.o lcd.o log.o
          
   lcd.o: lcd.c
          gcc -c lcd.c
          
   log.o: log.c
          gcc -c log.c
          
   main.o: main.c lcd.h log.h
           gcc -c main.c
           
   clean:
           -rm a.out
           -RM +.o
   ```
   ##### main.c:
   ```C
   #include <stdio.h>
   #include <lcd.h>
   #include <log.h>
   
   void inti();
   void show(char text[]);
   
   int main(){
    printf("Guten Morgen\n");
    lcd_init();
    log_init();
    show("Mal schauen..");
   return 0;
   }
   ```
   #### log.c:
   ```C
   #include <stdio.h>
   
   struct LogRecord{
    char src[10];
    char message[50];
   }
   
   void log_init()
   {
    printf("LOG: init\n");
   }
   
   void log(struct LogRecord r)
   {
    printf("LOG: record %s: %s\n",r.src,r.message);
   }
   ```
   #### log.h:
   ```C
   void log_init();
   ```
   #### lcd.c:
   ```C
   #include <stdio.h>
   
   void lcd_init(){
    printf("LCD:init\n");
   }
   
   void show(char text[])
   {
    printf("show: %s\n",text);
   }
   ```
   #### lcd.h:
   ```C
   void init();
   void show(char text[]);
   ```
   
    


