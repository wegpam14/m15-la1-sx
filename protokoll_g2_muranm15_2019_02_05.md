# Protokoll ![](https://www.koerbler.com/neuigkeiten/wp-content/uploads/2013/03/htl-kaindorf.jpg)
**von Anna Murko**  
Datum: 05.02.2019  
Gruppe: 2  
Betreuer: Professor Steiner  
abwesend: -  
  
  Thema: **Übersetzungsvorgang, Kernel, Kernelmodul**  
  

## Inhalt 
1. [Wiederholung Übersetzungsvorgang](https://github.com/HTLMechatronics/m15-la1-sx/blob/muranm15/protokoll_g2_muranm15_2019_02_05.md#1-wiederholung-%C3%BCbersetzungsvorgang)     
1. [Kernel](https://github.com/HTLMechatronics/m15-la1-sx/blob/muranm15/protokoll_g2_muranm15_2019_02_05.md#2-kernel)  
    1. [Kernelmodul](https://github.com/HTLMechatronics/m15-la1-sx/blob/muranm15/protokoll_g2_muranm15_2019_02_05.md#i-kernelmodul)    
1. [Fortsetzung unsere Übungsbeispiels](https://github.com/HTLMechatronics/m15-la1-sx/blob/muranm15/protokoll_g2_muranm15_2019_02_05.md#3-fortsetzung-unsere-%C3%BCbungsbeispiels)  
    1. [Auszüge](https://github.com/HTLMechatronics/m15-la1-sx/blob/muranm15/protokoll_g2_muranm15_2019_02_05.md#i-ausz%C3%BCge)  
    1. [auftretende Fehler](https://github.com/HTLMechatronics/m15-la1-sx/blob/muranm15/protokoll_g2_muranm15_2019_02_05.md#iiauftretende-fehler)  

###  1. Wiederholung Übersetzungsvorgang  
![Übersetzungsvorgang](https://raw.githubusercontent.com/HTLMechatronics/m15-la1-sx/muranm15/Unbenannt.GIF)  
Eine genauere Erklärung findet man in dem [Protokoll](https://github.com/HTLMechatronics/m15-la1-sx/blob/muranm15/protokoll_g2_muranm15_2018-01-29.md) der 4.Einheit.
###  2. Kernel  
Das Kernel ist die innerste Schicht eines Betriebssystems. Es ist für alles was im Betriebssystem wichtig ist, verantwortlich. Zum Beispiel für die Speicherreservierung. 
#### i. Kernel wird erneuert
Der Kernel wird sehr oft erneuert, da sich die Hardware auch regelmäßig verändert und so der Kernel nicht mehr mit der Hardware arbeiten könnte.
#### ii. Kernelmodul  
Das ist ein spezielles Computerprogramm, das im laufenden Betrieb in den Kernel eines Betriebssystems geladen und wieder daraus entfernt werden kann.
###  3. Fortsetzung unsere Übungsbeispiels  
#### i. Auszüge  
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
    struct LogRecord msg={"main.c","Start.."};
    log_log(msg);
    show("Mal schauen..");
   return 0;
   }
   ```
   #### log.c:
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
   #### log.h:
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
   #### lcd.c:
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
   #### lcd.h:
   ```C
  #ifndef LCD_H
  #define LCD_H
  
  #include "log.h"
  
  void lcd_init();
  void show(char text[]);
  void showLog(struct LogRecord r);
  
  #endif
   ```
#### ii.auftretende Fehler  
