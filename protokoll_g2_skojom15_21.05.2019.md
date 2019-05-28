 # Protokoll 8 #
Name: Skof Jonas  
Klasse: 4AHME  
Datum: 21.05.2019   
KNR: 11  
Gruppe: 2  


| Anwesend  | Abwesend  |
|---|---|
| Korrenn, Murko, Orthofer, Perl, Skof, Szapacs |  -- |

## Inhalt 
1. [EEPROM auslesen](#eeprom)  
1. [Kalibrieren des Sensors](#sensor)   
2.1 [Berechnung](#berechnung)

---
### 1. EEPROM auslesen <a name="eeprom"> </a>

Um den EEPROM auszulesen muss die Bibliothek "avr/eeprom.h" eingebunden werden damit wir die Funktion "eeprom_read_byte()" zur Verfügung haben die das auslesen erledigt.  
 
```c 
#include "avr/eeprom.h"
```

Realisiert wurde diese dann in der **app_init** Schleife:  

```c 
void app_init (void)
{
  memset((void *)&app, 0, sizeof(app));    
  for(uint16_t add = 0; add < 1024; add++) { //for Schleife über alle Register
    uint8_t b = eeprom_read_byte(add);       
    printf("%04x: %02x\n\r", add, b);        //Registerwert und Adresse werden ausgegeben
  }
}
```

---
###  2. Kalibrieren des Sensors   <a name="sensor"> </a>
**Messen der Inneren Bandgabspannung:**  

Um die innere Bandgabspannung zu messen muss man nur am Arduino die Spannungdifferenz zwischen den PINs *REF* und *GND* mit einem Multimeter messen.  

==> Vref = 1,0830V  
   
Um die Daten aus dem ADCH Register in eine Temperatur um zu rechen, wird eine Formel benötigt.  
Da diese einen linearen Zusammenhang besitzt, kann man zur Brechnung diese Grundform "y = k*x + d" verwenden.  
  
--> T = ADCH * k + d

Um dieses Problem zu lösen wurde die Gerade aus der ersten Einheit in zwei unabhängige lineare Funktionen (y = k * ADCH +d) zerlegt.

|   |T (aus dem Datenblatt)| Vin (aus dem Datenblatt)| ADCH\* |   Modbus Register Wert    |  ADC  |
|:-:|:--------------------:|:-----------------------:|:------:|:-------------------------:|:-----:|
| A |         -45°C        |           242 mV        |  56,79 |     -45 \* 2⁸ = -11520    | 230,73|
| B |          25°C        |           314 mV        |  73,08 |      25 \* 2⁸ =   6400    | 299,38|
| C |          85°C        |           380 mV        |  88,4  |      85 \* 2⁸ =  21760    | 362,31|
  

<img src="https://github.com/HTLMechatronics/m15-la1-sx/blob/skojom15/Temperatursensor.PNG" alt="drawing" width="800"/>

\* Der ADCH Wert errechnet sich aus der Formel ADC = Vin \*1024/Vref.*

Vref = 1.1V (da wir die Bandgapspannung als Referenzspannung verwenden)

Multipliziert man die die Temperatur aus der Tabelle mit 2⁸, 
ergeben sich die Werte vom Modbus Register. 

---

###  2.1 Berechnung  <a name="berechnung"> </a>

Allgemein gilt die Formel *y = k  \* ADCH + d*. Somit kann man jetzt die Geradengleichungen aufstellen.  

 Die erste lineare Funktion kann man sich aus den Werten von A & B aufstellen: 
 
==> -11520 = k * 56,79 + d    
==>   6400 =  k * 73,08 + d     

Die zweite lineare Funktion kann aus den Werten B & C aufgestellt werden:   

==>  k = 1100,06     
==>  d = -73992,49     

Aus diesen beiden linearen Funktionen kann k & d ausgerechnet werden:   

==>  6400 = k * 73,08 + d   
==>  21760 = k * 88,4 + d    

==> k = 1002,61  
==> d = -66870,809  
  
Aus den vorliegenden Werten ergeben sich nun folgenden Gleichungen:   

    G1 :  y1 = 1100,06 * ADCH - 73992,49
    G2 :  y2 = 1002,61 * ADCH - 66870,809
