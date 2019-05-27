# Protokoll 8 #
Name: Skof Jonas  
Klasse: 4AHME  
Datum: 21.05.2019   
KNR: 11  
Gruppe: 2  


| Anwesend  | Abwesend  |
|---|---|
| Murko,Orthofer,Korrenn,Perl,Skof,Szapacs |   |

## Inhalt 
1. [EEPROM auslesen](#eeprom-auslesen)  
1. [Kalibrieren des Sensors](#kalibrieren-des-sensors)  

---
### EEPROM auslesen  

Um den EEPROM auszulesen muss die Bibliothek  
```c 
#include "avr/eeprom.h"
```
inkludiert werden damit wir eine Funktion zur verfügung haben die das auslesen erledigt.  
Realisiert wurde diese dann in der **app_init** schleife:  
```c 
void app_init (void)
{
  memset((void *)&app, 0, sizeof(app));
  for(uint16_t add = 0; add < 1024; add++) {
    uint8_t b = eeprom_read_byte(add);
    printf("%04x: %02x\n\r", add, b);
  }
}
```


---
###  Kalibrieren des Sensors  
**Messen der Inneren Bandgabspannung:**  
Um die innere Bandgabspannung zu messen muss man nur am Arduino die Spannungdifferenz zwischen den PINs *REF* und *GND* mit einem Multimeter messen.  
Avref = 1,074V  
   
Um die Daten aus dem ADCH Register in eine Temperatur um zu rechen, wird eine Formel benötigt.  
Da diese einen linearen Zusammenhand besitzen, kann dessen Grundform "y = k*x + d" verwendet werden.  
  
--> T = ADCH * k + d

|   | Temp | Spannung | ADCH | ModBusRegister   |   ADC   |
|---|------|----------|------|------------------|---------|
|A: | -45°C|  242mV   | 56,79| -45*256 = -11520 |  230,73 |
|B: |  25° |  314mV   | 73,08|  25*256 = 6400   |  299,38 |
|C: |  85° |  380mV   | 88,4 |  85*256 = 21760  |  362,31 |

<img src="https://github.com/HTLMechatronics/m15-la1-sx/blob/brelom15/data/Temperaturverlauf.png" alt="drawing" width="500"/>

Aus den vorliegenden Werten ergeben sich nun folgenden Gleichungen:  
G1.  A - B  y1 = ADCH * 1100,06 - 73992,486  
G2.  B - C  y2 = ADCH * 1002,61 - 66870,80  

