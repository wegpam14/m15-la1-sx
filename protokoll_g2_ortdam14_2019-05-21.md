# Protokoll  
**von David Orthofer**  
**Datum:** 21.05.2019  
**Gruppe:** 2  
**Betreuer:** Professor Steiner  
**abwesend:** -  
  
# Inhalt  
1. Modbus[]()  
1. RS485[]() 
1. Temperatursensor[]()  

## Modbus  
Das Modbus-Protokoll ist ein Kommunikationsprotokoll, das auf einer Master/Slave- bzw. Client/Server-Architektur basiert. n der Industrie hat sich der Modbus zu einem De-facto-Standard entwickelt, da es sich um ein offenes Protokoll handelt. Seit 2007 ist die Version Modbus TCP Teil der Norm IEC 61158.  
  
Das Master-Gerät, welches meist ein Computer ist, und die Slave-Geräte, wie Mess- und Steuereinheiten, werden miteinander verbunden. Als Übertragungssystem wird dabei meist Ethernet genutzt oder die etwas ältere Variante über den seriellen Anschluss.  
  
### Die drei Arten der Datenübertragung  
*Modbus TCP*  
Modbus TCP/IP ist ein Client/Server-Protokoll für den verbindungsorientierten gesicherten Austausch von Prozessdaten.  
  
*Modbus RTU*
Modbus RTU (RTU: Remote Terminal Unit) überträgt die Daten in binärer Form. Dies sorgt für einen guten Datendurchsatz, allerdings können die Daten nicht direkt vom Menschen ausgewertet werden, sondern müssen zuvor in ein lesbares Format umgesetzt werden.  
  
*Modbus ASCII*  
Im Modbus ASCII wird keine Binärfolge, sondern ASCII-Code übertragen. Dadurch ist es direkt für den Menschen lesbar, allerdings ist der Datendurchsatz im Vergleich zu RTU geringer.  
  
## RS485  
RS485 ist ein Industriestandard für eine physische Schnittstelle für die asynchrone serielle Datenübertragung. Die symmetrische Leitung erhöht die elektromagnetische Verträglichkeit.  
  
- einfach  
- skalierbar mit µC betreibbar  
- 2 Busleitungen  
- bis zu 32 Teilnehmer  
  
### Wellenwiderstand
Das elektrische Feld breitet sich in den Leitungen mit Lichtgeschwindigkeit aus, dadurch schwappen Elektronen am Ende der Leitung wieder zurück. Mit einem Wellenwiderstand kann man dies verhindern.  
  
## Temperatursensor  
  
### Konfiguration des ADC

Folgende Bits müssen gesetzt werden:

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
  
Die Dokumentation der Register ist im Datenblatt ersichtlich.
  
**Beschreibung des Programmes**  
  
**ADMUX:**

Das Register **MUX** legt fest, welcher Sensor verwendet wird, bzw. wie die Weiche eingestellt wird.. *(In unserem Fall: 1000 für den Temperatursensor)*

Das Register **REFS** legt fest, welche Referenzspannung der ADC
verwenden soll. *(In unserem Fall: 11 für die innere Bandgap
Spannung von 1.1V)*

**ADCSRA:**

Das Register **ADEN** aktiviert den ADC.

Das Register **ADSC** startet den ADC.

Das Register **ADCSRA** legt den sogenannten Prescaler des ADCs fest. In
unserem Fall passt der Wert 128 als Prescaler sehr gut*, da der ADC so
auf **125kHz**(16MHz / 128 = 125kHz) betrieben wird.

(der ADC sollte zwischen 50kHz und 200kHz betrieben werden, da sich in
dieser Spannweite ein optimales Messergebnis ergibt)  
  
### Auslesen des Temperatursensors

**Vin** wird mit der Referenzspannung **Vref** verglichen und dann im ADC Register abgelegt.
  
`V = ADC * (Vref/1024) => 
ADC = (Vin * 1024) / Vref`

Nach der Konvertierung befindet sich das Ergebnis im 16 bit ADC Register.

`ADCH = Vin * (256 / Vref)`

|Temperatur|Strom|ADCH|
|:--------:|:---:|:--:|
|-45°C|242mV|56.32|
|25°C|314mV|73.08|
|85°C|380mV|88.44|

**Gradient**: (88 - 56) / (85 - (-45)) = 0.24338 pro °C
