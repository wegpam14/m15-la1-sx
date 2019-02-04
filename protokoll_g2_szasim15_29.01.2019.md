# 4.Protokoll  

Name: Simon Szapacs  
Datum: 29.01.2019  
Klasse: 4AHME  
Gruppe: 2  

Anwesend: Jonas SKof, Nicolas Perl, Marwin Korrenn, Anna Murko, David Orthofer, Simon Szapacs  

## Inhalsverzeichnis  

**1)** Make-Command  
**2)** Programm  

## 1) Make-Command  

Das Kompilieren von Quelltext-Dateien kann mit dem Programm **make** gesteuert werden. Dies ist vor allem dann sinnvoll,
wenn es sich um ein großes Projekt handelt bei dem die Kompilierung aus vielen einzelnen Schritten und Abhängigkeiten besteht.
Die einzelnen Schritte können zum Beispiel separate Kompilierungen oder andere Dateioperationen wie Kopieren und Löschen sein.
Diese Schritte und Abhängigkeiten werden in ein Makefile zusammengefasst, welches dann vom Programm make verarbeitet wird.  

Aufbau der Makefiles:  

```

Ziel1: Abhängigkeit(en)
	Kommando 
	Kommando 
	Kommando 
Ziel2: Abhängigkeit(en)
	Kommando 
	Kommando 
Ziel3: Abhängigkeit(en)
	Kommando  
  ```  
  
  ## 2) Programm  
  
  ### Zeitstempel  
  Der Zeitstempel gibt an zu welchem Zeitpunkt das Programm das letzte mal verändert wurde.  
   
  ### Befehle  
  
 Mit dem Befehl ```make clean ``` werden Dateien in der Shell gelöscht. Es kann aber passieren das make clean beim ausführen einen Fehler wirft. Dies unterbindet man, indem man vor den Commands ein ```-``` Zeichen schreibt. 

  ### main.c  
  *nano main.c*  
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
### Makefile  
*nano makefile* 
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

### log.c  
*nano log.c* 
 
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
### log.h  
*nano log.h*  
```C
void log_init();  
``` 
####lcd.c  
*nano lcd.c*  
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
### lcd.h  
*nano lcd.h*  
```C  
void init();
void show(char text[]);  
```
