# Protokoll 8  

Name: Simon Szapacs  
KNR: 12  
Gruppe 2  
Klasse: 4AHME  

1. [EEPROM auslesen](#eeprom-auslesen)  
2. [Sensorkalibrierung](#sensorkalibrierung)
3. [Aufgabe](#aufgabe)  


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
  
  Wie man sieht ist unser Ergebnis weit weg vom Istwert, dieser beträgt ca. 25°C. Um den korrekten Wert zu erhalten, muss man den Sensor kalibrieren. 
  
