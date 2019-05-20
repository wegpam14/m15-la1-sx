# Protokoll 7 (14.05.2019)

![](https://www.koerbler.com/neuigkeiten/wp-content/uploads/2013/03/htl-kaindorf.jpg)![](https://www.htl-kaindorf.at/images/startpage/logoMecha.png)   
Name: Korrenn Marwin  
Klasse: 4aHME  
KNR: 7  
Gruppe: 2
Abwesend: Orthofer D, Murko A

---

## Inhalt 
1. [Übung](#übung)  
   1. [ADMUX](#admux)  
   1. [ADCSRA](#adcsra)  
1. [Aufgabe](#aufgabe)  

---
### Übung  
Bevor wir irgendwelche Werte aus dem ADC des Arduino Nanos auslesen können müssen wir den ADC zuerst einmal konfigurieren. Alle wichtigen Register die bei der Konfiguration zum Einsatz kommen, können in der Dokumentation des Atmega328P nachgeschlagen werde.  

Um die Kommunikation mit Modbus am Arduino328P zu starten und die Temperatur auszulesen müssen folgende Bits gesetzt werden:  
```c
void app_init (void) {
  memset((void *) &app, 0, sizeof (app));

  ADMUX = 8; // Multiplexer ADC8 = Temperature (1000)
  ADMUX |= (1 << REFS0) + (1 << REFS1); // Nutzt die interne Referenzspannung VRef = 1.1V
  ADMUX |= (1 << ADLAR); // Left Adj, -> Result in ADCH

  ADCSRA = (1 << ADEN); //Enable the adc
  ADCSRA |= 7; // fADC = 125 kHz

  ADCSRB = 0; // Sicherheitshalber
}
```  
#### Grobe Erklärung der verwendeten Register:

### ADMUX 

Registername | Aufgabe | unsere einstellung  
------ | ------------------------------------------------------------- | ------------------------------------------
MUX | legt fest welchen PIN der ADC verwenden soll | 1000 für den Temperatursensor
REFS | legt fest welche Referenzspannung verwendet werden soll | 11 = für Bandgabspannung von ca. genau 1.1V
ADLAR | legt fest ob das Messergebniss links oder rechts ausgerichtet werden soll | 1 für links

---

### ADCSRA

Registername | Aufgabe | unsere einstellung
------ | ------------------------------------------------------------- | ------------------------------------------
ADEN | aktiviert den ADC | ----------------
ADPS | legt den Prescaler divisor fest | 111 (128) weil 16MHz/128 = 125kHz

---
### Aufgabe  

Als Aufgabe sollten wir herrausfinden wie man den EEPROM ausließt:

```c
/*
 * EEPROM Read
 *
 * Reads the value of each byte of the EEPROM and prints it
 * to the computer.
 * This example code is in the public domain.
 */

#include <EEPROM.h>

// start reading from the first byte (address 0) of the EEPROM
int address = 0;
byte value;

void setup() {
  // initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {
  // read a byte from the current address of the EEPROM
  value = EEPROM.read(address);

  Serial.print(address);
  Serial.print("\t");
  Serial.print(value, DEC);
  Serial.println();

  /***
    Advance to the next address, when at the end restart at the beginning.

    Larger AVR processors have larger EEPROM sizes, E.g:
    - Arduno Duemilanove: 512b EEPROM storage.
    - Arduino Uno:        1kb EEPROM storage.
    - Arduino Mega:       4kb EEPROM storage.

    Rather than hard-coding the length, you should use the pre-provided length function.
    This will make your code portable to all AVR processors.
  ***/
  address = address + 1;
  if (address == EEPROM.length()) {
    address = 0;
  }

  /***
    As the EEPROM sizes are powers of two, wrapping (preventing overflow) of an
    EEPROM address is also doable by a bitwise and of the length - 1.

    ++address &= EEPROM.length() - 1;
  ***/

  delay(500);
}
```  
Quelle:[https://www.arduino.cc](https://www.arduino.cc/en/Tutorial/EEPROMRead)  

---
