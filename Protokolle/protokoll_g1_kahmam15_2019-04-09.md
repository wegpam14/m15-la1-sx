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
   * *2.1 [Register Konfiguration](#Register-Konfiguration)*  
   * *2.2 [Main-Programm](#Main-Programm)*  
* **3. [Berchenungen](#Berechnung)**  
   
___
  <a name="Server-client"></a>
### 1. Übertragung mittels Server-Client System
Die Aufgabe bestand daraus die Temperatur über den µC(Server) zu messen, und diese dann jederzeit auf dem PC(Client) abrufbar zu machen. Der PC sendet zu Beginn eine Request an den µC, falls es keine Fehler dabei gab senden der µC eine Response and mit der gemmessen Temperatur zurück.  
![Server-Client](https://github.com/HTLMechatronics/m15-la1-sx/blob/kahmam15/rsz_server-client-modbus.png)
  

<a name="request"></a>
#### 1.1 Request  
**Aufbau im Übungs-Frame:**

| Start Byte | Adresse | Funktions Code |  Daten  | LRC |  Ende  |
|:----------:|:-------:|:--------------:|:-------:|:---:|:------:|  
|     :      |    01   |       04       |0001 0001|  B9 |'\r''\n'|

  
    
<a name="response"></a>
#### 1.2 Response  
**Aufbau im Übungs-Frame:**

| Start Byte | Adresse | Funktions Code | Daten | LRC |  Ende  |
|:----------:|:-------:|:--------------:|:-----:|:---:|:------:|  
|     :      |    01   |       04       |02 1780| --  |'\r''\n'|
  
**1780** entspricht einer Temperatur von **23,5°C**
___  

<a name="Programm"></a>
### 2. Programm
Als nächstes fingen wir an die Aufgabenstellung in einem C-Programm umzusetzen.  
  

<a name="Register-Konfiguration"></a>
#### 2.1 Register Konfiguration

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
#### 2.2 Main-Programm
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
**Beschreibung**  
Zu Beginn wird mithilfe des ```ADSC``` Registers die Verbindung mit dem ADC gestarten. Danach wird ein Wert zur Kontrolle am Bildschirm ausgegeben. Als nächstes haben wir **k** und **d** in der Formel angepasst, um relativ gute Messwerte zu erhalten. Dann haben wir überprüft, ob der Wert sich im zulässigen Bereich befindet, falls dies nicht der Fall ist soll der Maximalwert ausgegeben werden, um dem Benutzer zu zeigen, dass es sich um einen Fehler handelt.
___
  

### 3. Berechnungen <a name="Berechnung"></a>

**Gradientberechnung:**  (ADCH = Vin *256/Vref; Annahme: V<sub>ref</sub>=1,1V)  
-45°C… 242mV => 0,242 * 256/1,1 =~56  
 25°C… 314mV => 0,314 * 256/1,1 =~73  
 85°C… 380mV => 0,380 * 256/1,1 =~88  
   
 **Gradient:** (88-56)/(85°C-(-45°C)) = **0,24/°C**   
 Daraus folgt: Alle ~4°C ändert sich der gemessene Wert; genaues Messen der Temperatur nicht möglich  
   
**Tenmperaturberechnung:**  
Als erstes haben wir den Wert der Umgebung genommen, damit wir einen fixen Startpunkt haben. Die Kennlinie des Temperatursensors kann man linear annehmen. Danach haben wir ein paar Werte mithilfe von dem Datenblatt geschätzt, die Temperatur mit 2^8 multipliziert und sind dann auf folgende Tabelle gekommen:

| Gemessen (ADCH) |Temperatur| Umgerechnet (Temperatur) |
|:---------------:|:--------:|:------------------------:|
|    75           |-45°C     |    -11520                |  
|    92           |25°C      |     6400                 |
|    107          |85°C      |    21760                 |
  
Dannach haben wir ein Funktion nach y=kx+d erstellt um die Werte einer besseren geschätzten linearität zuweisen zu können.  
```Temperatur(16Bit) = 1040 * ADCH - 96000```  
  
___  


