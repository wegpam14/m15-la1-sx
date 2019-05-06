![HTBLA Kaindorf](https://github.com/HTLMechatronics/m15-la1-sx/blob/kahmam15/rsz_htl_kaindorf_logosvg.png)
# 7. Protokoll (30.04.2019)
Name: Kahr Markus  
Klasse: 4AHME  
KNr.: 6  
Gruppe: 1  
___

## Inhalte:  

* **1. [Problem](#Server-client)**  
   * *1.2 [Lösung](#response)*  
* **2. [Programm](#Programm)**  
   * *2.1 [Register Konfiguration](#Register-Konfiguration)*  
   * *2.2 [Main-Programm](#Main-Programm)*  
* **3. [Berechnungen](#Berechnung)**  
   
___
  <a name="Server-client"></a>
### 1. Problem
In dieser Einheit haben wir festgestellt, dass unsere Systeme unterschiedlich große Abweichungen vom eigentlichen Temperaturwert haben. 
Als wir die aus dem Datenblatt entnommen Werte in einem Diagramm dargestellt haben, konnten wir erkennen, dass es die Linie einen Knick hat und zwei verschiedene Geraden beschriebt.  

| Temperatur (°C) | Spannung (mV) |  
|:---------------:|:--------------|  
|-45 |242 |
|25  |314 |
|85  |380 |

![Diagramm](https://github.com/HTLMechatronics/m15-la1-sx/blob/kahmam15/Diagramm.PNG)  
*Die rote Gerade zeigt die zuerst erwartete Linie.*  
*Die blaue Linie  zeigt die wahre Linie (Es ist eine kleine Abweichung zu erkennen)*
    
<a name="response"></a>
#### 1.2 Lösung  
Um dieses Problem zu lösen, teilten wir die Linie beim Knick in zwei Geraden auf und verwendeten zur Berechnung eines Offsets die genauen ADCH-Werte
___  

<a name="Programm"></a>
### 2. Programm
Als nächstes fingen wir an die Aufgabenstellung in einem C-Programm umzusetzen.    
    
<a name="Main-Programm"></a>
#### 2.2 Main-Programm
```c
void app_main (void)
{
  ADCSRA |= (1 << ADSC);
  _delay_ms(1);
  uint8_t adch = ADCH;
  //printf("ADCH ist %u", adch);

  //Gerade ModbusRegister = kADCH + d
  //aus Datenblatt: 
  //-45°C -> 242mV -> ADCH=56,79  - MBR = -45256+ (-11520)
  //22°C -> ...mV -> ADCH=72,38  - MBR = 22256+ 5632
  //25°C -> 314mV -> ADCH=73,08  - MBR = 25256+ 6400
  //85°C -> 380mV -> ADCH=88,4  - MBR = 85*256+ 21760
  //daraus ergibt sich:
  // <= 25°C -> MBR = k1 *ADCH+d1
  // > 25°C -> MBR = k2 *ADCH+d2

  float k1 = 1100.06, d1 = -73992.3848;
  float k2 = 1002.61, d2 = -66870.724;

  //reale Messung bei 22°C ->ADCH=87
  //offsetkorrektur, um bei ADCH=87 auf den ModbusRegisterWert(MRT) 5632 zu kommen
  float off1 = -16080.82;
  float off2 = -14724.346;

  float mbr;
  if (adch <= 87)
  {
    mbr = k1 * adch + d1 + off1;
  }  else
    {
      mbr = k2 * adch + d2 + off2;
    }
  uint16_t mbInputReg01 = (uint16_t) mbr;
  int8_t vk = mbInputReg01/256;
  uint8_t nk = (mbInputReg01 & 0xff) 100/256;

  int c = fgetc(stdin);
  if(c != EOF)
  {
    printf("\r\n %02x\r\n", (uint8_t) c);

  }

}
```  
**Beschreibung**  
Zu Beginn wird mithilfe des ```ADSC``` Registers die Verbindung mit dem ADC gestarten. Danach wird ein Wert zur Kontrolle am Bildschirm ausgegeben. Als nächstes haben wir **k** und **d** in der Formel angepasst, um relativ gute Messwerte zu erhalten. Dann haben wir überprüft, ob der Wert sich im zulässigen Bereich befindet, falls dies nicht der Fall ist soll der Maximalwert ausgegeben werden, um dem Benutzer zu zeigen, dass es sich um einen Fehler handelt.
___
  
<a name="Berechnung"></a>
### 3. Berechnungen 

**Gradientberechnung:**  (ADCH = Vin *256/Vref; Annahme: V<sub>ref</sub>=1,1V)  
-45°C… 242mV => 0,242 * 256/1,1 =~56  
 25°C… 314mV => 0,314 * 256/1,1 =~73  
 85°C… 380mV => 0,380 * 256/1,1 =~88  
   
 **Gradient:** (88-56)/(85°C-(-45°C)) = **0,24/°C**   
 Daraus folgt: Alle ~4°C ändert sich der gemessene Wert; genaues Messen der Temperatur nicht möglich  
   
**Tenmperaturberechnung:**  
Als erstes haben wir den Wert der Umgebung genommen, damit wir einen fixen Startpunkt haben. Die Kennlinie des Temperatursensors kann man linear annehmen. Danach haben wir ein paar Werte mithilfe von dem Datenblatt geschätzt, die Temperatur mit 2^8 multipliziert und sind dann auf folgende Tabelle gekommen:

| Geschätzt (ADCH) |Temperatur| Umgerechnet (Temperatur) |
|:---------------:|:--------:|:------------------------:|
|    75           |-45°C     |    -11520                |  
|    92           |25°C      |     6400                 |
|    107          |85°C      |    21760                 |
  
Dannach haben wir ein Funktion nach y=kx+d erstellt um die Werte einer besseren geschätzten linearität zuweisen zu können.  
```Temperatur(16Bit) = 1040 * ADCH - 96000```  
  
___  


