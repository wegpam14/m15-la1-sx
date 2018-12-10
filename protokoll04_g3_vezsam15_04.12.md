
## Protokoll 4

    Name: Sarah Vezonik
    Datum, Ort: 04. Dezember 2018, CAD Saal Kaindorf
    Gruppe: 3
    Anwesend: Vezonik, Vollmaier, Wegl, Wesonig, Winter M. ;
    Abwesend: Winter T.


----------


## Übersetzungsvorgang eines C Programms:
![enter image description here](http://openbook.rheinwerk-verlag.de/c_von_a_bis_z/bilder/09_004.gif)

**Warum dieser Vorgang?**

 1. übersichtlicher
 2. Wiederverwendbarkeit
 3. mehr Übersetzungszeit (früher)


----------


## make

make (englisch für machen, erstellen) ist ein Build-Management-Tool, das Kommandos in Abhängigkeit von Bedingungen ausführt.
Genutzt wird es beispielsweise, um in Projekten, die aus vielen verschiedenen Dateien mit Quellcode bestehen, automatisiert alle Arbeitsschritte (Übersetzung, Linken, Dateien kopieren etc.) zu steuern, bis hin zum fertigen, ausführbaren Programm. make ist jedoch so flexibel ausgelegt, dass es auch beliebige andere Aufgaben steuern kann, bei denen die zeitliche Abhängigkeit von Dateien eine Rolle spielt.

> Steuerdatei :   
> Kommando **make**   


----------


##  **Makefile** 
Anordnung:  
 >Ziel: Abhängigkeiten 
 >Tabulator Kommando  
 > Tabulator (weitere Kommandos)  
 >..  
 >Ziel 2: 
 >..  


**Wichtig!!**
 - Tabulator! (keine Spaces)
 - um die Übung durchführen zu können, ist ein Verzeichnis nötig!


----------
## Aufgabenstelllung
Es sind drei Programme zu schreiben, welche miteinander verknüpft werden. Die *main.c* ist das Hauptprogramm. Sie soll sich aus den beiden anderen Programmen, *lcd.c* und *monitor.c*  und Funktionen aus diesem Programm ausführen.


----------


### Programm 1 (main.c)

    #include <stdio.h>
    int main()
	{          
		printf("Programmstart\n);          
		return 0;    
	}

ue04 :
 - .exe (Windows)
 - .elf (Linux,  ist jedoch nicht unbedingt erforderlich)

**clean:**
 - `rm * o` (remove,alle .o Dateien)
 - `rm * elf` (alle ausführbaren Dateien)
 - 
 **Wichtig!**
 Verzeichnis entleeren (Zustand vor dem bauen zurücksetzen)

`make`(bauen)
`clean`(zurücksetzen)

----------


### Programm 2 (Makefile)

    clean:
	    rm * o
	    rm * elf
### Programm 3 (monitor.c)

    nano monitor.c
    
    #include <stdio.h>
    void start Monitor (int speed)
    {
	    printf("start Monitor speed = %d\n",speed);
    }
	  
  
  
   
Makefile Datei wie gehabt ergänzen mit `monitor.o` !!

    make



**Wichtig**!
main. c Datei fehlt, da sie schon übersetzt wurde!


----------


### main.c
mit der Funktion von monitor.o ergänzen
  

    #include <stdio.h>
    #include "monitor.h"
    int main()
	{          
		printf("Programmstart\n);
		startMonitor(1);        
		return 0;    
	}

**Wichtig!**
Vergisst man, das Makefile zu ergänzen, sucht der Linker nach der Funktion,welche er jedoch nicht finden kann. Weiters ist die monitor.h Datei einzubinden.


----------


### Programm 4  ( monitor.h)

    void startMonitor(int speed)

Die monitor.h Datei dient dazu, die Funktionen in ein Programm einzubinden,damit die main Datei weiß , was welche Funktion macht.


----------


#### main.c

    
    #include <stdio.h>
    #include "monitor.h"
    void checkMonitor(char text[])
    {
	    printf("check Monitor -> %s\n",text);
    }
    int main()
	{          
		printf("Programmstart\n);
		startMonitor(1); 
		return 0;    
	}

**Wichtig!**
    monitor.h    (einbinden)


----------


### Programm 5 (lcd.c)

    #include <stdio.h>
    void startLcd()
    {
	    printf("startLcd\n");

    }

    void checkLcd (chart text[])
    {
	    prinft("checkLcd -> %s \n", text);
    }
    


----------


## Programm 6 (lcd.h)

    void startLcd();
    void checkLcd (char text[]);

**Wichtig!**
Makefile mit lcd.o und lcd.h ergänzen!


----------


### main.c 
 
    #include <stdio.h>
    #include <lcd.h>
    #include "monitor.h" 
    
    void checkMonitor(char text[])
    {
	    printf("check Monitor -> %s\n",text);
    }
    
    int main()
	{          
		printf("Programmstart\n);
		startMonitor(1);
		startLcd();
		checkLcd("main");
		return 0;    
	}

**Wichtig!**
`lcd.h` einbinden.


----------


### monitor.c

mit 

    void test();
    {
	    printf("test in lcd\n)";
    }

erweitern.


----------


### monitor.h und  lcd.h
mit 

    void test();
 
erweitern.


----------


### Makefile
mit

    lcd.d
erweitern.


----------


### lcd.h

    struct Lcd_Info
    {
	    int status;
    }


----------


### monitor.h

    #inndef MONITOR_H
    #define MONITOR_H
    
damit das nicht nochmals definiert wird!
**Wichtig!**  
jeder Datei Name darf nur einmal vorkommen. (eindeutige Namen vergeben)  
**Doppelte Namengebung**  
Als Übungszwecken erstellten wir in der monitor.c und in der lcd.c eine Funktion test(). In der main.c werden dann die Headerdateien eingebunden. Der Linker weiß dann nicht welche Funktion gemeint ist. Es wird ein Fehler ausgegeben.
Mit verschieden Namen wie zb *monitor_test()* und *lcd_test()* kann dieses Problem gelöst werden.


----------


### lcd.c

    int lcd_counter = 0;
    void lcd_test(()
    {
	    printf("...");
	    lcd_counter++;
    }
	   


----------


### main.c
mit 

    printf("lcd_counter = %d\n ",lcd_counter);
   
erweitern.

    int lcd_counter
hat zufällig funktioniert
Linker erkennt das es die gleiche Variable ist 
nur wenn KEINE Zuweisung vorhanden ist 


----------


    




 

