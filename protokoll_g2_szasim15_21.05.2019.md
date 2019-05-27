# Protokoll 8  

Name: Simon Szapacs  
KNR: 12  
Gruppe 2  
Klasse: 4AHME  

1. [EEPROM auslesen](#eeprom-auslesen)  
2. [Sensorkalibrierung](#sensorkalibrierung)
3. [Berechnug](#berechnung)  


## EEPROM auslesen

Zu allererst brauchten wir Kalibriewerte aus dem Datenblatt, um eine Formel, zur Temperaturumwandlung aufstellen zu können.  

Bevor das geschiet mussten wir eine Headerdatei einfühgen: 

 ```C
 #include "avr/eeprom.h"
 ```  
 
 Realisierung:  
 
 ```C   
 void app_init (void)
{
  memset((void *)&app, 0, sizeof(app));
  for(uint16_t add = 0; add = 1024;add++) {
       uint8_t b = eeprom_read_byte (add);
       printf("%04x : %02x\n\r", add, b);   
  }  
  ```  
  ## Sensorkalibrierung  
  
  Zu erst haben wir die Bandgapspannung  mittelst Multimeter ausgemessen.  
  Vref: 1,0229V  
  ADC= 344
  
  V= ADC* Vref/1024  
  V= 343,63 mA  
  
  Diesen Wert mussten wir natürlich noch in einen Temperatur umwandelen. Dies haben wir wie folgt gemacht:  
  
  y = kx + d  
  y´= ΔmV / ΔT  
  1,0229 = (344-314)/(T-25)  
  1.0229T - (1,0229 * 25) = 344-314  
  1,0229T - 25,5725 = 30  
  1,0229T = 55.5725  
  T = 54.3283°C  
  
  Wie man sieht ist unser Ergebnis weit weg vom Istwert, dieser beträgt ca. 25°C. Um den korrekten Wert zu erhalten, muss man den   Sensor kalibrieren.  
  Grundsätzlich geht man davon aus das dies ein Offsetfehler ist.  
  
  Datenblatt:  
  
|   |T (aus dem Datenblatt)| Vin (aus dem Datenblatt)| ADCH   | Modbus Register Wert (MRT)|  ADC  |
|:-:|:--------------------:|:-----------------------:|:------:|:-------------------------:|:-----:|
| A |         -45°C        |           242 mV        |  56,79 |     -11520                |242,2402|
| B |          25°C        |           314 mV        |  73,08 |      6400                 |314,3376|
| C |          85°C        |           380 mV        |  88,4  |      21760                |380,4086|
  
  
  ## Berechnug  
  
  Normalerweise gilt die Formel: y = k * ADCH + d. Daraus ergibt sich die Gereadengleichung
  
  -11520 = k * 56,79 + d  
  6400 = k * 73,08 + d  
  
  k = 1100,06  
  d = -73992,49  
  
  6400 = k * 73,08 + d  
  21760 = k * 88,4 + d  
  
  **k = 1002,61**  
  **d = -66870,809**   
  
  Dadurch ergeben sich folgende Gleichnugen:  
  
  ```  
  G1: y1 = 1100,06 /* ADCH - 73992,49  
  G2: y2 = 1002,61 /* ADCH - 66870,809  
  ``` 
  
  
  
