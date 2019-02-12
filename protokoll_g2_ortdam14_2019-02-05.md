# Protokoll  
**Datum:** 5.2.2019  
**Gruppe:** 2  
**Abwesend:** -  
  
## Inhalt  
1. Kernel  
1. Kernelmodul  
1. Treiber  
1. Übungsbeispiel  
  
## Kernel  
Ein [Kernel](https://de.wikipedia.org/wiki/Kernel_(Betriebssystem)) ist der zentrale Bestandteil eines Betriebssystems. In ihm ist die Prozess- und Datenorganisation festgelegt, auf der alle weiteren Softwarebestandteile des Betriebssystems aufbauen. Er bildet die innerste Softwareschicht des Systems und hat direkten Zugriff auf die Hardware.  
  
## Aufgaben des Kernels   
**Ein Betriebssystem-Kernel hat die folgenden Aufgaben:**  
  
1. Schnittstelle zu Anwenderprogrammen (Starten, Beenden, Ein-/Ausgabe, Speicherzugriff)  
1. Kontrolle des Zugriffs auf Prozessor, Geräte, Speicher (Scheduler, Gerätetreiber, Speicherschutz). Möglichst alleiniger Zugriff des Kernels auf diese Ressourcen.  
1. Verteilung der Ressourcen wie zum Beispiel der Prozessorzeit bzw. der Prozessoren auf die Anwenderprogramme.  
1. Strukturierung der Ressourcen, etwa Abbildung von Dateisystemen auf blockorientierte Geräte wie Festplattenlaufwerke, Netzwerkstack auf Netzwerkkarten.  
1. Auflösung von Zugriffskonflikten, etwa Verriegelung bei Mehrprozessorsystemen, Warteschlangen bei knappen Ressourcen.
1. Virtualisierung der Ressourcen (Prozessor: Prozesse, Festplatte: Dateien, Netzwerkkarte: z. B. Sockets, Speicher: virtueller Speicher, Geräte: Spezialdateien).  
1. Überwachung von Zugriffsrechten auf Dateien und Geräte bei Mehrbenutzersystemen.  
  
![Kernel](https://upload.wikimedia.org/wikipedia/commons/thumb/8/8f/Kernel_Layout.svg/1200px-Kernel_Layout.svg.png)  
Der Kernel stellt die Schnittstelle zwischen Software und Hardware dar.
  
## Kernelmodul  
Ein Kernel-Modul ist ein spezielles Programm, das im laufenden Betrieb in den Kernel eines Betriebssystems geladen und wieder daraus entfernt werden kann.  
  
Kernel-Module werden häufig für Gerätetreiber verwendet, da eine große Auswahl der Module für die unterschiedlichsten Hardware-Komponenten mit dem Betriebssystem mitgeliefert werden können, aber nur die wirklich benötigten Treiber in den Speicher geladen werden müssen.  
  
## Treiber  
Ein [Treiber](https://de.wikipedia.org/wiki/Ger%C3%A4tetreiber), häufig kurz nur Treiber genannt, ist ein Computerprogramm oder Softwaremodul, das die Interaktion mit angeschlossenen, eingebauten (Hardware) oder virtuellen Geräten steuert. Dazu kommuniziert der Treiber auf der einen Seite meist direkt mit dem Gerät und tauscht Steuersignale und Daten mit dem Gerät aus.  
  
##  3. Fortsetzung unsere Übungsbeispiels  
**Auszüge**  
  ### Makefile:
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
   ### main.c:
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
      struct LogRecord msg={"main.c","Start.."};
      log_log(msg);
      show("Mal schauen..");
   return 0;
   }
   ```
   ### log.c:
   ```C
   #include <stdio.h>
   #include "log.h"
   
   void log_init()
   {
      printf("LOG: init\n");
   }
   
   void log_log(struct LogRecord r)
   {
      printf("LOG: record %s: %s\n",r.src,r.message);
   }
   ```
   ### log.h:
   ```C
   #ifndef LOG_H
   #define LOG_H
   struct LogRecord
   {
     char src[10];
     char message[50];
   };
   
   void log_init();
   void log_log(strcut LogRecord r);
    
   #endif //LOG_H
   ```
   ### lcd.c:
   ```C
   #include <stdio.h>
   #include "log.h"
   
   void lcd_init(){
      printf("LCD:init\n");
      structLogRecord msg={"lcd.c","init");
      log_log(msg);
   }
   
   void show(char text[])
   {
      printf("show: %s\n",text);
      structLogRecord msg={"lcd.c","shows");
      log_log(msg);
   }
   
   void showLog(struct LogRecord r)
   {
   //...
   }
   ```
   ### lcd.h:
   ```C
  #ifndef LCD_H
  #define LCD_H
  
  #include "log.h"
  
  void lcd_init();
  void show(char text[]);
  void showLog(struct LogRecord r);
  
  #endif
   ```
