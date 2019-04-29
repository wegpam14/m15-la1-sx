### 6. Protokoll
Name: **Grebien Markus**  
Klasse: **4AHME**  
Knr: **3**  


**Inhaltsverzeichnis**
1. [Übertragung  zwischen μC und PC](#Übertragung)
1. [Beschreibung der Register und app_main](#Register)
1. [Berechnung des Temperaturwertes](#Temperaturberechnung)

---
### Übertragung  zwischen μC und PC <a name="Übertragung"></a>
Der μC soll die Temperatur messen, welche man jederzeit vom PC aus abrufen kann.  
In unserem System übernimmt der μC die Arbeit des Servers und der PC ist der Client.  
Der PC sendet einen Request an den μC und wenn der Request ohne Fehler war, wird vom μC eine Response mit der Temperatur zurückgesendet. 

#### Beschreibung der Register und app_main<a name="Register"></a>
``` c
ADMUX = 8;
ADMUX |= (1<<REFS0) | (1<<REFS1);
ADMUX |= (1<<ADLAR);
  
ADCSRA = (1<<ADEN) | 7;
ADCSRB = 0;
```
```ADMUX = 8``` Damit setzen wir den Multiplexer ADC auf den wert 8 wo der Temperatursensor liegt.  
```ADMUX |= (1<<REFS0) | (1<<REFS1)``` Damit setzten wir die Referenzspannung auf die internen 1.1V.  
```ADMUX |= (1<<ADLAR)``` Damit wird das Ergebnis linksbündig ausgegeben.   
```ADCSRA = (1<<ADEN) | 7``` Damit setzt man die Frequenz des ADC, in unserem fall auf 125kHz.  
```ADCSRB = 0;``` Wird zur Sicherheit komplett deaktiviert.  

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
**Erklärung**
Als erstes wird Mithilfe des ```ADSC``` Registers der Konvertierungsprozess gestartet. Danach Geben wir den Wert zur Kontrolle am Bildschirm aus.  Danach definieren wir **k** und **d** für die Formel, die wir gleich danach verwenden, um die Temperatur zu berechnen. Darauf prüfen wir, ob der Wert sich in einem zulässigen Bereich befindet, ansonsten wird der Maximalwert ausgegeben damit der Benutzer erkennt, dass es sich hier um einen Fehler handeln muss. sollte der Wert in einem Gültigem Bereich liegen, wird dieser gespeichert und anschließend zur Kontrolle ausgegeben. 

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


