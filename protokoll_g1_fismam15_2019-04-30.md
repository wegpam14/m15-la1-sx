
# Protokoll 7 (30.04.2019) (ABWESEND)
Name: Fischer Maximilian  
KNr.: 2  
Klasse: 4AHME  
Gruppe: 1  
___

**Dieses Protokoll dient lediglich der Vollständigkeit.**

___

### Übersicht

1. Korrigieren des Programmes der vorigen Einheit
   1. Problemstelle
   1. Lösung
       1. Berechnung
       1. Ausgleich des Fehlers
1. Übertragung mithilfe von UART
___

## **1** Korrigieren des Programmes der vorigen Einheit

Der erste Schritt der Einheit bestand darin, das Programm soweit zu korrigieren, dass die richtigen Temperaturwerte angezeigt werden.

### **1.1** Problemstelle

In folgender Grafik kann erkannt werden, dass der Spannungs-, Temperaturverlauf einen Knick bei 25 °C hat.

![Skizze von Lara Hofer](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoflam15/data/Skizze.svg)
*(Skizze von [Lara Hofer](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoflam15))*

### **1.2** Lösung

Um dieses Problem zu lösen wurde die Gerade aus der ersten Einheit in zwei unabhängige lineare Funktionen (y = k * ADCH +d) zerlegt.
Im C-Programm werden die Werte dann innerhalb eines `if-else` der jeweiligen linearen Funktion zugeordnet.

|   |T (aus dem Datenblatt)| Vin (aus dem Datenblatt)| ADCH\* | Modbus Register Wert (MRT)
|:-:|:--------------------:|:-----------------------:|:------:|:-------------------------:|
| A |         -45°C        |           242 mV        |  56,79 |     -45 \* 2⁸ = -11520    |
| B |          25°C        |           314 mV        |  73,08 |      25 \* 2⁸ =   6400    |
| C |          85°C        |           380 mV        |  88,4  |      85 \* 2⁸ =  21760    |
  

\* Der ADCH Wert errechnet sich aus der Formel A*DCH = Vin \* 256/Vref.*

Vref = 1.1V (da wir die Bandgapspannung als Referenzspannung verwenden)

Multipliziert man die die Temperatur aus der Tabelle mit 2⁸, 
ergeben sich die Werte vom mbInputRegister. 
Dadurch verschieben sich die Bits um 8 Stellen und der µC kann eine einfache Division durchführen.

#### **1.2.1** Berechnung

Allgemein gilt die Formel *y = k  \* ADCH + d*. Somit kann man jetzt die Geradengleichungen aufstellen.

Die erste lineare Funktion kann man sich aus den Werten von A & B aufstellen: 
- 11520 = k * 56,79 + d
- 6400 =  k * 73,08 + d

Die zweite lineare Funktion kann aus den Werten B & C aufgestellt werden:
- k = 1100,06 
- d = -73992,49

Aus diesen beiden linearen Funktionen kann k & d ausgerechnet werden:

- 6400 = k * 73,08 + d
- 21760 = k * 88,4 + d

**k = 1002,61**

**d = -66870,809**

Somit kann man jetzt die 2 Gleichungen aufstellen:

    G1 : MRT = 1100,06 \* ADCH - 73992,49
    G2 : MRT = 1002,61 \* ADCH - 66870,809

#### **1.2.2** Ausgleich des Fehlers

	 ADCH <= 78 
		 5632 = 1100,06 * ADCH - 73992,49 - Offsetausgleich1
		 Offsetausgleich1 = 6177.19
	 ADCH > 78 
		 5632 = 1002,61 * ADCH - 66870,809 - Offsetausgleich2 
		 Offsetausgleich2 = 5700.771

Umsetzung in C der Ausgleichung:

```C
void app_main (void) {
  ADCSRA |= (1 << ADSC);
  _delay_ms(1);

  float k1 = 1100.061, d1 = -73992.464;
  float k2 = 1002.611, d2 = -66870.812;

  float o1 = -6177.19;
  float o2 = -5700.771;

  float mbr;
  uint8_t adch = ADCH;
  if (adch <= 78) { 
    mbr = k1 * adch + d1 + o1;
  } else { 
    mbr = k2 * adch + d2 + o2;
  }

  int32_t k = 1024;
  int32_t d = -82688;
  int32_t x = k * ADCH + d;

  if (x > 32768) {
    mbInputRegister = 32768;
  } else if (x < -32768) {
    mbInputRegister = -32768;
  } else {
    mbInputRegister = (int16_t) x;
  }
  
  printf("ADCH = %u  Temperatur = %d.%02d Grad Celsius   MBR = %d = 0x%d\r", ADCH, vk, nk, mbInputRegister, mbInputRegister);
}
```

## **2** Übertragung mithilfe von UART

Zuerst muss die Request - vom Client entsendet - ausgelesen werden.
Diese wird über UART gesendet und über die Standard Bibliotheksfunktion `fgetc` ausgelesen.
Das senden und empfangen des UARTs erfolgt in der *sys.c*.
In der *sys.c* sind alle Funktionen für eine UART Schnittstelle eingebaut.
Unsere Aufgabe ist es eine Modbus Schnittstelle zu machen. 

Dies kann man auf 2 Arten machen:

1. Möglichkeit: 
Lösung *streng* nur über Bibliotheksfunktionen
- **Vorteil**: *Idiotensicher*, Bei langsamen arbeiten sollte nichts schiefgehen
- **Nachteil**: Es wird ein 2. Buffer benötigt, wodurch einiges an Speicher verloren geht

2. Möglichkeit:
Man versucht die Bibliotheksfunktionen wegzulassen, dabei muss die ISR(= Empfangsroutine, die alles in einem Ringbuffer schreibt) verändert werden
- **Vorteil**: Umgehung der Bibliotheksfunktionen und Wegfallen des 2. Buffers -> mehr Specher frei für andere Sachen
- **Nachteil**: die Datei *sys.c* muss bearbeitet werden

Wir verwenden in unserer Übung **Möglichkeit 1**.

Deswegen müssen wir mithilfe von `#fgetc` jedes Zeichen einzeln aus `stdin` auslesen und dann mithilfe von unserer Funktion `#app_handleUartByte`
auswerten.

```C
  int c = fgetc(stdin);
  if (c != EOF) {
    printf("\n %02x\r\n", (uint16_t) c);
    app_handleUartByte((char) c);
  }
```

Die Zeichen werden mithilfe der Funktion `#app_handleUartByte` ausgewertet.

``` C
void app_handleUartByte (char c) {
  if (c == ':') {
    app.modbusBuffer[0] = c;
    app.bufferIndex = 1;
  } else {
    if (app.bufferIndex > 0) {
      app.modbusBuffer[app.bufferIndex++] = c;
    }
  }
}
```

Hierbei wird auf das Startbyte "**:**" gewartet.
Trifft dieses ein, werden die nachfolgenden Zeichen in einem Buffer gespeichert.
Dieses Buffer wurde zuvor in der Struktur `App` in der Header-Datei *app.h* definiert.

```C
struct App {
  uint8_t flags_u8;
  char modbusBuffer[32];
  uint16_t bufferIndex;
};
 ```
