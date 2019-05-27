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
  Sensorkalibrierung
  
  
