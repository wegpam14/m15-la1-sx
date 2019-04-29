![HTBLA Kaindorf](https://github.com/HTLMechatronics/m15-la1-sx/blob/kahmam15/rsz_htl_kaindorf_logosvg.png)
# 6. Protokoll (09.04.2019)
Name: Kahr Markus  
Klasse: 4AHME  
KNr.: 6  
Gruppe: 1  
___

## Inhalte:  

* **1. [Übertragung mittels Server-Client System](#Server-client)**  
   * *1.1 [Request](#request)*  
   * *1.2 [Response](#response)*  
* **2. [Programm](#Programm)**  
   * *1.1 [Register Konfiguration](#Register-Konfiguration)*  
   * *1.2 [Main-Programm](#Main-Programm)*  
* **2. [Berchenung der Temperaturwerte](#Berchenung)**  
   
___
  <a name="Server-client"></a>
### 1. Übertragung mittels Server-Client System
Die Aufgabe bestand daraus die Temperatur über den µC(Server) zu messen, und diese dann jederzeit auf dem PC(Client) abrufbar zu machen. Der PC sendet zu Beginn eine Request an den µC, falls es keine Fehler dabei gab senden der µC eine Response and mit der gemmessen Temperatur zurück.  
![Server-Client](https://github.com/HTLMechatronics/m15-la1-sx/blob/kahmam15/rsz_server-client-modbus.png)
  

<a name="request"></a>
#### 1.1 Request  
**Aufbau im Übungs-Frame:**

Start Byte|Adresse|Funktions Code|Daten|LRC|Ende
-|-|-|-|-|-
:|01|04|0001 0001|B9|'\r' '\n' 
  
    
<a name="response"></a>
#### 1.2 Response
Beim Response antwortet der Modbus-Server auf unsere Request. In unserem Beispiel sollte er mit dem gemessenen Temperaturwert antworten.
  
**Aufbau im Übungs-Frame:**

Start Byte|Adresse|Funktions Code|Daten|LRC|Ende
-|-|-|-|-|-
:|01|04|02 1780 |--|'\r' '\n' 
  
**1780** entspricht einer Temperatur von **23,5°C**
___  

<a name="Programm"></a>
### 1. Programm
Als nächstes fingen wir an die Aufgabenstellung in einem C-Programm umzusetzen.  
  

<a name="Register-Konfiguration"></a>
#### 1.1 Register Konfiguration

``` c
ADMUX = 8;
ADMUX |= (1<<REFS0) | (1<<REFS1);
ADMUX |= (1<<ADLAR);
  
ADCSRA = (1<<ADEN) | 7;
ADCSRB = 0;
```
```ADMUX = 8``` : Wir setzten den Multiplexer auf 8 für den Temperatursensor auf ADC8
```ADMUX |= (1<<REFS0) | (1<<REFS1)``` Damit nehmen wir die Bandgapspannung von 1.1V als Refernz (Voraussetzung: Sensorsignal liefert Spannung zwischen 0 und 1V)  
```ADMUX |= (1<<ADLAR)``` Ausgabe wird linksbündig gesetzt  
```ADCSRA = (1<<ADEN) | 7``` Die Taktfrequenz des ADC's wird auf 125kHz  
```ADCSRB = 0;``` Zur Sicherheit deaktiviert  
  
    
<a name="Main-Programm"></a>
#### 1.2 Main-Programm
```c
void app_main (void)
{
  ADCSRA |= (1<< ADSC);
  _delay_ms(1);
  printf("ADCH= %u  ", ADCH);
  
  int32_t k = 1040;
  int32_t d = -96000;
  int16_t mbInputReg01;
  
  int32_t x = k*ADCH + d;
  if(x> 0x7fff) {
    mbInputReg01 = 0x7fff;
  } else if(x < -32768) {
    mbInputReg01 = -0x8000;
  } else {
    mbInputReg01 = (int8_t)x;
  }
  printf("Versuch: %d \r",mbInputReg01);
}
```
___
  

### Berechnung des Temperaturwertes <a name="Temperaturberechnung"></a>

Als erstes haben wir den Wert der Umgebung genommen, damit wir einen fixen Startpunkt haben. Die Kennlinie des Temperatursensors kann man linear annehmen. Danach haben wir ein paar Werte mithilfe von dem Datenblatt geschätzt, die Temperatur mit 2^8 multipliziert und sind dann auf folgende Tabelle gekommen:

| Gemessen (ADCH) |Temperatur| Umgerechnet (Temperatur) |
|:---------------:|:--------:|:------------------------:|
|    72           |-45°C     |    -11520                |  
|    89           |25°C      |     6400                 |
|    104          |85°C      |    21760                 |

Damit wir die Werte besser schätzen konnten, haben wir eine Formel verwendet, um einen durchschnittliche Temperaturänderung pro mV zu berechnen: ADCH = V<sub>in</sub>*256/V<sub>ref</sub>  Generell kann man aber sagen, dass sich Wert um 1°C pro mV ändert. 

Daraus haben wir dann mithilfe von y=k*x+d eine Funktion erstellt:
```Temperatur = 1040 * ADCH - 86400```  

__  



[Punkt zu Punkt]: https://www.itwissen.info/Punkt-zu-Punkt-Verbindung-PzP-point-to-point-P2P.html
