
# Protokoll 5 #
Name: Skof Jonas  
Klasse: 4AHME  
KNR: 11  
Gruppe: 2  


| Anwesend  | Abwesend  |
|---|---|
| Korrenn,Murko,Orthofer,Perl,Szapacs | -  |



## Inhalte ##  
** 1. Wiederholung C-Kompilierungsvorgang **        
** 2. Der Kernel **        
** 3.  Das Kernelmodul  **       
** 4. Fertigstellen des Programms **          
           
***

# 1.Wiederholung C-Kompilierungsvorgang #

Es wurde ein weiteres mal diese Grafik durchbesprochen.
Vor allem ,warum das Kernelmodull eine große Rolle spielt.
![Kompiliervorgang in C](C-Kompilierungsvorgang.png) 

Für genauere Beschreibung ==> Siehe [4.Protokoll](protokoll_g2_skojom15_29.01.2019.md):


***
## 2. Der Kernel ##




***
# 3. Das Kernelmodul #
Vor allem ,warum man wegen dem Kernelmodul nicht jedes mal bei Aktualisirung des Treibers den Pc neu starten muss.



***
# 4. Fertigstellen des Programms #

**main.c**

```c
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

**log.c**

```c
#include <stdio.h>
#include "log.h"

void log_init()
{
 printf("LOG: init\n");
}
                                 
void log_log(struct LogRecord r) 
{
 printf("LOG: record %s: %s\n",r.src,r.message);
```

**log.h**
```c
#ifndef LOG_H
#define LOG_H

struct LogRecord   
{
char src[10];
char message[50];
};

void log_init();
void log_log(struct LogRecord r); 
 
#endif 
```
**lcd.c**
```c
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

**lcd.h**

```c

#ifndef LCD_H  
#define LCD_H

#include "log.h"

void lcd_init();
void show(char text[]);
void showLog(struct LogRecord r);

#endif

```

**Makefile:**
```c
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
***




