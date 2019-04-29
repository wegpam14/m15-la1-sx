 # 6. Protokoll	
 - Name: Lara Hofer
 - Datum, Ort: 9. April 2019, AUT Labor Kaindorf
 - Gruppe: 1
 - Anwesend: Breitenthaler, Fischer, Grebien, Hofer, Hörmann, Kahr
 - Abwesend: -
 
## Inhaltsangabe
1. Allgemeines zur Übung
2. Konfiguration der Register
3. Auslesen der Werte / Kalibrierung
 3.1 Auslesen der Werte
 3.2 Kalibrierung
 3.3 Berechnung
 3.4 Umsetzung in C

## Allgemeines zur Übung
Das Ziel unserer Übung war es den Temperatur Sensor über einen Modbus auszugeben. 
//Bild

Der Client sendet einen Request an den Server.
**Request:**

    :|0|1|0|4|0|0|0|1|0|0|0|1|B|9|'\r'|'\n'
0 1 : Gerät - Adresse
0 4 : Function Code
0 0 0 1 : Adresse 2 für Temperatur
B 9 : LCR


Der Server sendet eine Response zurück.
**Resonse:**

    :|0|1|0|4|0|2|1|7|8|0| | |'\r'|'\n'
Kein LCR noch vorhanden, weil wir es noch berechnen müssen.
1 7 8 0 : steht für die Temperatur 23,5°C


## Konfiguration der Register
Konfiguriert werden die Register in *app_init*. Alles was zum konfigurieren ist, kann man im  [Datenblatt](https://www.sparkfun.com/datasheets/Components/SMD/ATMega328.pdf) nachlesen.

        void app_init (void)
    {
      memset((void *)&app, 0, sizeof(app));
      
      ADMUX = 8;
      ADMUX |= (1 << REFS1) | (1<<REFS0); //Bit setzten
      ADMUX |= (1<< ADLAR);
      
      ADCSRA = (1<<ADEN) | 7; //fADC = 125 kHz
      ADCSRB = 0;
    }
Der Temperatursensor hängt am ADC8 Kanal somit muss zum Aktivieren der Temperatur **ADMUX** 8 sein. Die interne 1,1-V-Spannungsreferenz muss auch für die ADC-Spannungsreferenzquelle bei der Temperatursensormessung ausgewählt werden. Dabei müssen das **REFS1** und das **REFS0** Bit auf 1 gesetzt werden. Wenn der Temperatursensor aktiviert ist, kann der ADC-Wandler im Konvertierungsmodus verwendet werden, um die Spannung über dem Temperatursensor zu messen. Die gemessene Spannung hat eine lineare Beziehung zur Temperatur. Die Spannungsempfindlichkeit beträgt ca. 1 mV/°C und die Genauigkeit der Temperaturmessung beträgt +/- 10 °C.

|Temperatur °C|  Spannung mV|
|--|--|
| -45°C | 242mV |
|  25°C | 314mV |
|  85°C | 380mV |

Die in Tabelle beschriebenen Werte sind typische Werte. Aufgrund der Prozessvariation variiert die Temperatursensorausgangsspannung jedoch von einem Chip zum anderen.
Das **ADLAR**-Bit beeinflusst die Darstellung des ADC-Konvertierungsergebnisses im ADC-Datenregister. Da das System linksbündig ausgerichtet ist, muss das ADLAR Bit gesetzt werden. Das **ADCSRA** Register ist ebenso noch zu verändern um die gewünschte Frequenz (liegt zwischen 50 & 200kHz) zu erreichen. 
Somit ist der ADC konfiguriert.

## Auslesen der Werte / Kalibrierung



### Auslesen der Werte

    ADCSRA |= (1 << ADSC);
          _delay_ms(1);
          printf("ADCH=%u     ", ADCH);
In diesem Teil wird der Wert ausgelesen und ist auf 90°C (+/- 10%). Somit wird nun eine Kalibrierung gebraucht die man wie folgt berechnen kann.

### Kalibrierung
Wie oben schon beschrieben haben die gemessene Spannung und die Temperatur ein lineares Verhältnis. So kann zur Umrechnung von den Daten des ADCH Registers in eine Temperatur eine lineare Funktion (y=k\*x+d) verwendet werden. In diesem Falle lautet die Formel: *T=k\*ADCH+d*


|laut Datenblatt|  gemessen | Temperatur |
|--|--|--|
| -45°C | 75°C* | -45*2⁸ = -11520 |
|  25°C | 92°C | 25*2⁸ = 6400 |
|  85°C | 107°C | 85*2⁸ = 21760 |
\* geschätzt, Messung nicht möglich

Aus dieser Tabelle ergibt sich das folgende Diagramm:
//Diagramm

#### Berechnung
Aus der Tabelle können nun Gleichungen aufgestellt werden um k und d zu berechnen.

 - -11520 = k \* 75 + d
 -   6400 = k \* 92 + d
 -  21760 = k \* 107 + d

Zu guter Letzt sollte man sich auf einen Wert in der Mitte einigen in unserem Fall einigten wir uns auf k=1040 und d=-96000.

#### Umsetzung in C
    void app_main (void)
    {
      
      ADCSRA |= (1 << ADSC);
      _delay_ms(1);
      printf("ADCH=%u     ", ADCH);
      
      uint16_t k = 1040;
      int32_t d = -96000;
      int16_t mbInputReg01;
      
      int32_t x = (uint32_t)k * ADCH + d;
      if(x > 32767) {
        mbInputReg01 = 32767;
      } else if (x < -32768) {
        mbInputReg01 = -32768;
      } else {
        mbInputReg01 =(int16_t)x;
      }
      printf(" REG 1 = %d \r", mbInputReg01);
    }
Zuerst wird die Formel konfiguriert.
! Wichtig: *int16_t* verwenden, da der Wert auch negativ sein kann.
Doch die Formel kann noch nicht funktionieren da ein 32-Bit Wert vorhanden ist, somit kommt noch ein *if-else*.
Zuletzt wird die Formel mit *printf* ausgegeben.


Der Wert scheint immer noch nicht genau zu sein, doch das liegt wahrscheinlich an k&d. 


