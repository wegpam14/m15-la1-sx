# Protokoll 7


Name: Simon Szapacs  
Klasse: 4AHME  
KNR: 12  
Gruppe 2   

1. [Konfiguration der Register](#konfiguration-der-register)  
2. [Konfiguration-des-ADC](#konfiguration-des.adc)  
3. [Auslesen des Temperatursensors](#auslesen-des-temperatursensors)

## Konfiguration der Register  

Bevor wir überhaupt erst starten konnten mussten mussten wir unseren ADC konfigurieren. Alle Register, die wir benötigten konnten wir im DatenBlatt des Admega328P nachlesen.  

## Konfiguration des ADC  

**Erklärung** der folgenden Register:  

**ADMUX:**  

***MUX***  
Das MUX Register legt fest, welchen Sensor oder welchen Pin der ADC ansteuern soll.  

***REFS***  
Dieses Register legt fest, welche Referenzspannung der ADC verwenden soll. Wir verwendeten den Wert 11 für die Bandgapspannung 1.1V.  

***ADLAR***  
Das Register legt fest, ob das Messergebnis im Datenregister rechts oder links abgelegt werden soll.  

**ADCSRA**  

***ADEN***  
Das ADEN Register aktiviert den ADC  

***ADPS***  
Dieses Register legt den Prescaler fest. Wir verwendeten den Wert 128, da der ADC so auf 125kHz betrieben werden kann.  

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

## Auslesen des Temperatursensors 

Hier gibt es zwei wichtige Formeln:  

`ADC = (VIN * 1024) / Vref `  

`ADCH = Vin * (256 / Vref)`  

**Achtung**: 

- Ergebniswert ändert sich nur alle 4 Grad  
- Genaue Messung nicht möglich!!

















