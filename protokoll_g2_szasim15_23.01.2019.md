# Protokoll 7


Name: Simon Szapacs  
Klasse: 4AHME  
KNR: 12  
Gruppe 2   

1. [Konfiguration der Register](#konfiguration-der-register)  
2. [Konfiguration-des-ADC](#konfiguration-des.adc)

## Konfiguration der Register  

Bevor wir überhaupt erst starten konnten mussten mussten wir unseren ADC konfigurieren. Alle Register, die wir benötigten konnten wir im DatenBlatt des Admega328P nachlesen.  

## Konfiguration des ADC  

Es mussten folgende Bits in der `app.c` gesetzt werden:  


```c  
void app_init (void) {
  memset((void *) &app, 0, sizeof (app));

  ADMUX = 8; 
  ADMUX |= (1 << REFS0) + (1 << REFS1); 
  ADMUX |= (1 << ADLAR); 


  ADCSRA = (1 << ADEN); //Enable the adc
  ADCSRA |= 7; // fADC = 125 kHz


  ADCSRB = 0;
}
```  












