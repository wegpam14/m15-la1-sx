![HTBLA Kaindorf](https://github.com/HTLMechatronics/m15-la1-sx/blob/kahmam15/rsz_htl_kaindorf_logosvg.png)
# 7. Protokoll (30.04.2019)
Name: Kahr Markus  
Klasse: 4AHME  
KNr.: 6  
Gruppe: 1  
___

## Inhalte:  

* **1. [Problem](#Server-client)**  
   * *1.1 [Lösung](#response)*  
* **2. [
* **2. [Programm](#Programm)**  
   * *2.1 [app_main](#Main-Programm)* 
   * *2.2 [app_handleUartByte](#Register-Konfiguration)*  
   * *2.3 [app.h](#header)*   
   
___
  <a name="Server-client"></a>
### 1. Problem
In dieser Einheit haben wir festgestellt, dass unsere Systeme unterschiedlich große Abweichungen vom eigentlichen Temperaturwert haben. 
Als wir die aus dem Datenblatt entnommen Werte in einem Diagramm dargestellt haben, konnten wir erkennen, dass die Linie einen Knick hat und zwei verschiedene Geraden beschriebt.  

| Temperatur (°C) | Spannung (mV) |  
|:---------------:|:--------------|  
|-45 |242 |
|25  |314 |
|85  |380 |

![Diagramm](https://github.com/HTLMechatronics/m15-la1-sx/blob/kahmam15/Diagramm.PNG)  
*Die rote Gerade zeigt die zuerst erwartete Linie.*  
*Die blaue Linie  zeigt die wahre Linie (Es ist eine kleine Abweichung zu erkennen)*
    
<a name="response"></a>
#### 1.1 Lösung  
Um dieses Problem zu lösen, teilten wir die Linie beim Knick in zwei Geraden auf (Gerade1: -45°C... 22°C; Gerade2: 22°C... 85°C) und fragten dann im Programm mithilfe einer *if-Schleife* ab, ob sich der gemessene Wert auf der oberen oder unteren Gerade befindet.  
  
**1)** Zuerst haben wir die genau Werte für den ADCH entnommen und mithilfe von [linearer Interpolation] den ADCH-Wert für unsere Raumtemperatur (22°C) ermittelt:  

| Temperatur (°C) | Spannung (mV) | ADCH | MRT |  
|:---------------:|:-------------:|:----:|:---:|  
|-45 |242 |56,79 |-11520 |
|22  |??? |**72,38** | 5632 |
|25  |314 |73,08 |6400 |
|85  |380 |88,4  |21760 |  
  
**MRT = Modbusregister-Wert = k * ADCH + d**  
  
___
**2)** Dann haben wir 3 Gleichungen aufgestellt um unser **k** und **d** neu zu berechnen:  
**Gleichung1**: -11520=k*56,79+d  
**Gleichung2**: -6400=k*73,08+d  
**Gleichung3**: -21760=k*88,4+d  

Aus **Gl1** und **Gl2**: 6400-k*73,08  = -11520-k*56,79  
Daraus ergibt sich: **k = 1100,06 | d = -73992,3848**  
  
Aus **Gl2** und **Gl3**: 6400-k*73,08 = 21760-k*88,4  
Daraus ergibt sich: **k = 1002,61 | d = -66870,724**  
  
___
**3)** Als nächstes haben wir den **Korrekturfaktor** berechnet um bei einem ADCH=87 auf den Modbusregister-Wert 5632 zu kommen:  
**Gl4**: *5632 = 1100,06 * 87 + d* daraus ergibt sich **d = -90073,22**  
**Gl5**: *5632 = 1002.61 * 87 + d* daraus ergibt sich **d = -81595,07**  
  
Aus dem **d** von **Gl1 + Gl2 und Gl4** folgt:  
**Korrekturfaktor** = -90073,22 + 73992,3848 = **-16080,82**  
  
Aus dem **d** von **Gl2 + Gl3 und Gl5** folgt:  
**Korrekturfaktor** = -81595,07 + 66870,724 = **-14724,346**  
  
* **Korrekturfaktor = Offset**  


___  

<a name="Programm"></a>
### 2. Programm   
    
<a name="Main-Programm"></a>
#### 2.1 app_main
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
<a name="Register-Konfiguration"></a>
#### 2.2 app_handleUartyByte

```c
void app_handleUartByte(char c)
{
  //Wenn das Startbit ":" empfangen wird, soll gespeichert werden
  if(c == ':')
  {
    app.bufferIndex = 0;
    app.mudbusBuffer[app.bufferIndex] = c;
    app.bufferIndex = 1;
  } else
  {
    if(app.bufferIndex > 0)
    {
      app.mudbusBuffer[app.bufferIndex++] = c;
    }
  }
}
```  

<a name="header"></a>
#### 2.3 app.h  

```c
struct App
{
  uint8_t flags_u8;
  //Modbusbuffer für 32 Zeichen erstellen
  char mudbusBuffer[32];
  uint8_t bufferIndex;
};
```
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

[linearer Interpolation]:https://www.bauformeln.de/mathematik/lineare-interpolation/
