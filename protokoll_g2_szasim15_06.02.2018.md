# Protokoll 5  

Name: Simon Szapacs  
Datum: 06.02.2019  
Gruppe: 2  
4AHME  

## Übersicht  

1. Kernel  
  1.1 Kernelmodul  
2. Fortsetzung Übungsbeispiel  


## Kernel  

Der Kernel auch Betriebssystemkern genannt ist eigendlich das zetrale Bestandteil des Betriebssystems.  
In ihm ist die Prozess- und Datenorganisation festgelegt, auf der alle weiteren Softwarebestandteile des Betriebssystems aufbauen.
Er bildet die unterste Softwareschicht des Systems und hat direkten Zugriff auf die Hardware. Weitere Softwarekomponenten eines 
Betriebssystems liegen in der Regel in einer übergeordneten Schicht. Neue Kernelmodule werden ständig erneuert, da die Hardware immer weiter 
erneuert wird.  

[Quelle](https://de.wikipedia.org/wiki/Kernel_(Betriebssystem))


### Kernelmodul  

Ein Kernel-Modul ist ein spezielles Computerprogramm, das im laufenden Betrieb in den 
Kernel eines Betriebssystems geladen und wieder daraus entfernt werden kann.
Kernel-Module werden häufig für Gerätetreiber verwendet, da eine große Auswahl der Module für die unterschiedlichsten
Hardware-Komponenten mit dem Betriebssystem mitgeliefert werden können, aber nur die wirklich benötigten Treiber in den Speicher geladen werden müssen.
Kernel-Module gibt es bei unterschiedlichen Betriebssystemen, wie zum Beispiel Linux, BSD oder Solaris.  

[Quelle](https://de.wikipedia.org/wiki/Kernel-Modul)  


## Fortsetzung Übungsbeispiel  


**main.c**  
``` C
#include <stdio.h>
#include "lcd.h"
#include "log.h"

void inti();
void show(char text[]);

int main()
{
 printf("Guten Morgen\n");
 lcd_init();
 log_init();
 struct LogRecord msg = {"main.c","Start..."};
 log_log(msg);
 show("Mal schauen...");
 return 0;
}
```  

**lcd.h**  

``` C  
#ifndef LCD_H   //ein mehrmaliges Aufrufen der lcd.h und somit ein mehrmaliges Deklarieren wird verhindert
#define LCD_H

#include "log.h"

void lcd_init();
void show(char text[]);
void showLog(struct LogRecord r);

#endif  
```  

**lcd.c**  
```C  
#include <stdio.h>
#include "log.h"

void lcd_init()
{
 printf("LCD:init\n");
 struct LogRecord msg = {"lcd.c","init"};
 log_log(msg);
}

void show(char text[])
{
 printf("show: %s\n",text);
 struct LogRecord msg = {"lcd.c","shows");
 log_log(msg);
}

void showLog(struct LogRecord r)
{
  //...
}  

```  

**log.c**  
```C  
#include <stdio.h>
#include "log.h"

void log_init()
{
 printf("LOG: init\n");
}
                                  //Namensraum ist global, Namen müssen global einzigartig sein
void log_log(struct LogRecord r)  //Umbenamsen aufgrund Namenskonflikt mit sdt.-Bibliothek in log_log()
{
 printf("LOG: record %s: %s\n",r.src,r.message);
}  
```  

**log.h**  

```C  
#ifndef LOG_H
#define LOG_H

struct LogRecord   //Quelle und Meldungs-Strings in Feldern speichern
{
char src[10];
char message[50];
};

void log_init();
void log_log(struct LogRecord r); 
 
#endif  

```  
**Makefile**  

```C  
a.out: main. o lcd.o log.o
        gcc main.o lcd.o log.o
main.o: main.c lcd.h log.h
        gcc -c main.c     
lcd.o: lcd.c
        gcc -c lcd.c
        
log.o: log.c
        gcc -c log.c
         
 
clean:
        -rm a.out
        -rm *.o    
        
        ```
