### 7. Protokoll  
Name: **Grebien Markus**  
Klasse: **4AHME**  
Knr: **3**

**Inhaltsverzeichnis**
1. [Temperatursensor Überprüfung](#TempÜbertrüfung)
1. [Codierung](#Codierung)
    * [Datentypverwendung](#Datentypverwendung)
    * [Probleme bei der Ausgabe von float](#Problems)
1. [Implementierung](#Implementierung)
1. [Quelltexterklährung](#Quellcode)

---

##### In dieser Übungseinheit haben wir mit der Übung vom letzten Mal weitergemacht. Für genauere Informationen klicken sie [hier](https://github.com/HTLMechatronics/m15-la1-sx/blob/gremam15/protokoll_g1_gremam15_2019-04-09.md)

### Temperatursensor Überprüfung <a name="TempÜbertrüfung"></a>
Zuerst mussten wir feststellen, ob unser Temperatursensor überhaupt eine lineare Funktion ist. Mithilfe einer Tabellenkalkulationssoftware konnten wir das feststellen, indem wir einfach 3 Werte verwendet haben.
Zwei dieser Werte nahmen wir aus dem Datenblatt und als dritten Wert verwendeten wir die momentane Umgebungstemperatur.

|Temperatur in °C| Volt in mV|
|:--------------:|:---------:|
|-45 |242 |
|25 |314 |
|85 |380 |

Und so bekamen wir folgendes Diagramm:  
![](https://github.com/HTLMechatronics/m15-la1-sx/blob/gremam15/util/Gerade.JPG)

Zwar nicht gut erkennbar allerdings ist das keine Gerade. Wir haben uns dann entschieden, dass wir einfach zwei Geraden nehmen. Einmal von -45°C bis 22°C und dann noch von den 22°C bis 85°C.

### Codierung <a name="Codierung"></a>
Wir verwenden einen 16-Bit Wert mit Festkommaarithmetik. Wir haben das Komma genau in die Mitte, zwischen dem achten und neuntem Bit, gesetzt. Wenn man diesen Wert nämlich mit 256 multipliziert, bekommt man einen Wert, der sehr leicht mit einem μC umzurechnen ist.

Und mit diesen Änderungen bekommen wir die fertige Tabelle:

|Temperatur in °C|Modbus Regster Wert (MRW)| Volt in mV|ADCH |
|:--------------:|:-----------------------:|:---------:|:---:|
|-45 |-11520 |242 |56,79|
|22 |5632 |311 |72,28|
|85 |21760 |380 |88,4 |

Dann kann man Mithilfe von `y=k*x+d` zwei Gleichungen aufstellen und damit auf `k` und `d` zurückrechnen:  

![](https://github.com/HTLMechatronics/m15-la1-sx/blob/gremam15/util/Gleichungen.PNG)

Durch die Annahme eines Wertes kommt es zwar zu einem Fehler, welcher aber nur sehr gering ist, ungefähr 10%.
Nun kommt noch der Fehler, dass jeder μC ein bisschen andere Werte hat, muss man einen Korrekturfaktor angeben, den wir mit `o` angeben. Bei mir sind das:
`o1 = -17180.9`  
`o2 = -15776.956`

Damit kommt man dann auf die finalen Gleichungen:  
ADCH <= 88 --> `mbr = 1100.061 * adch -73992.464 -17180.9`  
ADCH >  88 --> `mbr = 1002.611 * adch -66870.812 -15776.956`

#### Datentypverwendung <a name="Datentypverwendung"></a>
Es gibt nun zwei Möglichkeiten. Entweder man verwendet Festkommazahlen oder Fließkommazahlen.
Wenn man Fließkommazahlen verwendet ist es für den Programmierer einfacher zu lesen und zu programmieren, allerdings ist es für den μC leichter, wenn er mit Festkommazahlen rechnen kann. Diese Frage muss man sich immer als Programmierer stellen, bevor man es anfängt, denn einmal mit einem System angefangen, kann man es nicht mehr so leicht ändern.

Wir arbeiten mit Festkommazahlen, also die ersten 8 Bit für die Ganzzahl und die letzten 8 für die Kommazahl. Um zur Ganzzahl zu kommen, muss man nur die Zahl durch 256 dividieren. Für die Kommazahl wird es etwas komplizierter, den dafür muss man als Erstes den Wert mit 100 multiplizieren und dann durch 256 dividieren.

Kurz:  
`Ganzzahl = Festkommazahl/256`  
`Kommazahl = (Festkommazahl*100)/256`

#### Probleme bei der Ausgabe von float<a name="Problems"></a>
In der Standard avr-Bibliothek ist es nicht vorgesehen, dass man `float` ausgibt, wodurch man es nicht so leicht ausgeben kann. Dies kann man aber umgehen, indem an die Standardbibliothek implementiert, welche eine `float`-Ausgabe unterstützen.

### Implementierung(#Implementierung)

Wir arbeiten mit dem Level 3, wodurch in der `sys.c` schon alle Funktionen deklariert worden sind, um ein ganz normales `printf` zu verwenden.
Wir haben nun 2 Möglichkeiten:
* Wir können die `sys.c` umschreiben
* Mithilfe von `fgets` nur in der app.com

Wir haben uns entschieden, die `sys.c` nicht umzuschreiben, stattdessen arbeiten wir nur in der `app.c`.

### Quelltexterklärung <a name="Quellcode"></a>

Kompletter Quellcode [hier]LINK!!!!!

```c
  float k1 = 1100.061, d1 = -73992.464;
  float k2 = 1002.611, d2 = -66870.812;
```
Hier setzten wir einmal k und d für beide Geraden. 
```c
  float o1 = -17180.9;
  float o2 = -15776.956;
```
Nun setzen wir den Offset.
```c
  float mbr;
  if(adch <= 88) {
    mbr = k1 * adch + d1 + o1;
  } else {
    mbr = k2 * adch + d2 + o2;
  }
```
Nun testen wir, ob der Wert sich auf der ersten oder zweiten Gerade befindet und berechnen ihn dann auch richtig. 
```c
  int16_t mbInputReg01 = (int16_t)mbr;
  int8_t vk = mbInputReg01/256;
  uint8_t nk = ((mbInputReg01 & 0xff)*100)/256;
```
Nun Teilen wir den Wert in einen Vorkommawert(`vk`) und Nachkommawert(`nk`).
```c
  int c = fgetc(stdin);
  if(c != EOF) {
    printf("\r\n %02x\r\n", (uint8_t)c);
    app_handleUartByte((char) c);
  }
```
Hier übergeben wir der Methode `app_handleUartByte` einen byte, wenn etwas gekommen ist.
```c
app.h

struct App
{
  uint8_t flags_u8;
  char mudbusBuffer[32];
  uint8_t bufferIndex;
};
```
In der `app.h` haben wir im struct einen Ringbuffer für das Modbuspaket erstellt.
```c
void app_handleUartByte(char c) {
  
  if(c == ':') {
    app.bufferIndex=0;
    app.modbusBuffer[app.bufferIndex] = c;
    app.bufferIndex=1;
  } else{
    if(app.bufferIndex > 0) {
      app.modbusBuffer[app.bufferIndex++] = c;
    }
  }
}
```
Hier befindet sich nun die Zusammensetzung von unserem Protokoll. Wenn der Startbit wie gewollt ein `:` ist, so wird nun gestartet mit dem Speichern des Paketes. 

