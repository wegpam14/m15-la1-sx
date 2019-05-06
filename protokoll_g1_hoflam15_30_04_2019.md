
 # 7.Protokoll
 - Name: Lara Hofer
 - Datum, Ort: 30. April 2019, AUT Labor Kaindorf
 - Gruppe: 1
 - Anwesend: Breitenthaler, Grebien, Hofer, Hörmann, Kahr
 - Abwesend: Fischer
 
## Inhaltsangabe
1. Problembehebung

	*[1.1]  Berechnung*

	*[1.2] Fehler ausgleichen*

2. Start der Übertragung

## Problembehebung
Mit der linearen Formel *T = ADCH \* k + d* kann man die Daten aus dem ADCH Register in eine Temperatur umrechnen. 

**Problem:** Die Werte im Datenblatt stimmen nicht zu einer genauen Gerade überein. Die Gerade hat einen leichten Knick von 10%.

![Skizze](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoflam15/data/Skizze.svg)

**Lösung:** Man zerlegt die Gerade in zwei Geraden. Mit einem "if-else" kann man die Werte dann der jeweiligen Geraden zuteilen. 

|   |T (aus dem Datenblatt)| Vin (aus dem Datenblatt)| ADCH\* | Modbus Register Wert (MRT)
|:-:|:--------------------:|:-----------------------:|:------:|:-------------------------:|
| A |         -45°C        |           242 mV        |  56,79 |     -45 \* 2⁸ = -11520    |
| B |          25°C        |           314 mV        |  73,08 |      25 \* 2⁸ =   6400    |
| C |          85°C        |           380 mV        |  88,4  |      85 \* 2⁸ =  21760    |
  

\* Der ADCH Wert errechnet sich aus der Formel A*DCH = Vin \* 256/Vref.*

Vref = 1,1V (aus dem Datenblatt entnommen)

Multipliziert man die die Temperatur aus der Tabelle mit 2⁸, ergeben sich die Werte vom mbInputRegister. Dadurch verschieben sich die Bits um 8Stellen und der µC kann eine einfache Division durchführen.

#### Berechnung

Allgemein geltet die Formel *MRT = k  \* ADCH + d*. Somit kann man jetzt die Geradengleichungen aufstellen.

Die Gerade 1 kann man sich aus den Werten von A & B aufstellen: 

    1.) -11520 = k * 56,79 + d
    
    2.)  6400 =  k * 73,08 + d

Aus diesen beiden Gleichungen kann man sich dann k & d ausrechnen. 

- k = 1100,06 

- d = -73992,49

Die Gerade 2 kann man sich aus den Werten B & C aufstellen:

    1.) 6400 = k * 73,08 + d
    
    2.) 21760 = k * 88,4 + d

- k = 1002,61

- d = -66870,809

Somit kann man jetzt die 2 Gleichungen aufstellen:

    G1 : MRT = 1100,06 \* ADCH - 73992,49
    G2 : MRT = 1002,61 \* ADCH - 66870,809

#### Fehler ausgleichen

Beim letzten Mal haben wir für k & d einfach den Mittelwert angenommen, somit waren die Werte falsch.

Startet man das Programm vom letzten Mal so wird unterschiedlich vom Chip, aufgrund der Prozessvariation, die Temperatursensorausgangsspannung anders ausgegeben. Bei meinem war der ADCH Wert 88. 

Umsetzung in C:

```C
void app_main (void) {
   ADCSRA |= (1 << ADSC);
   _delay_ms(1);


   // Werte laut Datenblatt
   float mrb;
   float k1 = 1100.061, d1 = -73992.486;
   float k2 = 1002.61, d2 = -66870.812;



   if(ADCH <= 88) { //Zuteilung der Werte zur passenden Gerade
      mrb = k1 * ADCH + d1;
   }else if (ADCH > 88 ){
      mrb = k1 * ADCH + d1;
   }


   int16_t mbInputRegister1 = (int16_t)mrb;
   int8_t vk = mbInputRegister1 /256;
   uint8_t nk = ((mbInputRegister1 & 0xff) * 100) /256;

   printf("ADCH --> %u    Reg 1: %d   \r",ADCH, mbInputRegister1);

}
```
Wie oben erwähnt ist die Ausgabe des ADCH Wertes von Chip zu Chip unterschiedlich. Somit liegt noch ein Fehler vor. 

Eine Möglichkeit den Fehler zu korrigieren wäre den Offset hinauf oder hinab zu verschieben.

Als mittlere Temperatur nahmen wir 22°C an und berechneten den ADCH Wert durch einsetzten in G1. Somit ergibt sich ein Wert von *72,3815.* Aus *22°C \* 2⁸* ergibt sich der *MRT Wert = 5632*.  Diese MRT Wert muss jetzt für alle ADCH Werte, Chip - unabhängig, ausgegeben werden. Um das zu erreichen, muss ein Korrekturfaktor "o" eingebaut werden. Diesen kann man aus **Einsetzen in die Gleichung 5632 =  1100,06 * 72,3815 - 73992,49 - o**  ermitteln.

! Wichtig ist noch: 
- Wenn der Wert kleiner ADCH = 88 ist, wird die G1 verwendet.
- Ist er größer als ADCH = 88, wird G2 verwendet.

Umsetzung in C:
```C
void app_main (void) {
   ADCSRA |= (1 << ADSC);
   _delay_ms(1);


   // Werte laut Datenblatt
   float mrb;
   float k1 = 1100.061, d1 = -73992.486;
   float k2 = 1002.61, d2 = -66870.812;

   //Korrekturfaktoren
   float o1 = -16080.734, o2 = -14724.27;

   if(ADCH <= 88) {  // Zuteilung des Wertes zur passenden Gleichung
      mrb = k1 * ADCH + d1 + o1;
   }else if (ADCH > 88 ){
      mrb = k1 * ADCH + d1 + o1;
   }


   int16_t mbInputRegister1 = (int16_t)mrb;
   int8_t vk = mbInputRegister1 /256;
   uint8_t nk = ((mbInputRegister1 & 0xff) * 100) /256;

   printf("ADCH --> %u    Reg 1: %d   Temperatur: %d,%u \r",ADCH, mbInputRegister1, vk, nk);

   }
}
```
Zu guter Letzt wird noch der zu übertragende Wert in den Vorkomma- und Nachkomma Wert aufgeteilt um nur ganzzahlige Werte übertragen zu müssen.

## Start der Übertragung
Zuerst muss die empfangene Request ausgelesen werden. Diese wird über einen UART gesendet und über die Standard Bibliotheksfunktion `fgetc` ausgelesen. Das senden und empfangen des UARTs erfolgt in der *sys.c*. In der *sys.c* sind alle Funktionen für eine UART Schnittstelle eingebaut. Unsere Aufgabe ist es eine Modbus Schnittstelle zu machen. 
Dies kann man auf 2 Arten machen:
1. Möglichkeit: 
man arbeitet streng über Bibliotheksfunktionen
der Vorteil dabei ist, wenn man  nicht so schnell ist, kann einem nichts passieren
der Nachteil ist, man muss wahrscheinlich mehr Buffer machen, das verlangt mehr Speicher

2. Möglichkeit:
man versucht die Bibliotheksfunktionen wegzulassen, dabei muss die ISR(= Empfangsroutine, die alles in einem Ringbuffer schreibt) verändert werden
der Vorteil ist, man umgeht die Bibliotheksfunktionen und braucht keinen 2. Buffer; mehr Speicher
der Nachteil ist, man muss die sys.c ändern

Wir verwenden Möglichkeit 1.

```C
int c = fgetc(stdin);
   if (c != EOF){
      printf("\r\n %02x \r\n", (uint8_t)c);
      app_handleUartByte((char)c);
```
Um die empfangenen Zeichen auszuwerten, werden sie anschließend der Funktion`app_handleUartByte((char)c)` übertragen.
``` C
void app_handleUartByte(char c){
   if(c == ':') {
      app.modbusBuffer[0] =c;
      app.bufferIndex = 1;
   } else {
      if(app.bufferIndex > 0){
	 app.modbusBuffer[app.bufferIndex++] = c;
      }
   }
}
```
Hierbei wird auf das Startbyte ":" gewartet. Trifft dieses ein, werden die nachfolgenden Zeichen in einem Buffer gespeichert. Dieses Buffer wurde zuvor in einer Struktur in der Header-Datei festgelegt.

```C
struct App
{
  uint8_t flags_u8;
  char modbusBuffer[32];
  uint16_t bufferIndex;
};
 ```



