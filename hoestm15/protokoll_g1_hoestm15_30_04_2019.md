 # Protokoll der 7. Einheit (30.04.2019)
  Name: Hörmann
  
  Gegenstand: Labor
  
  Lehrer: SX
  
  Klasse: 4AHME
  
  Gruppe: 1
  ## Inhaltsverzeichnis

 1. Korrektur des Programmes
 2. Offset korrigieren
 3. Übertragung via UART
 
 
## 1. Korrektur des Programmes
Der erste Schritt in der Einheit bestand darin, das alte Programm soweit zu korrigieren, dass die richtigen Werte angezeigt werden, da wir noch immer starke Schwankungen zwischen den Messwerten und den Werten in der Tabelle hatten. In folgender Grafik kann erkannt werden, dass der Spannungs-, Temperaturverlauf einen Knick bei 25 °C hat.
![](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoestm15/hoestm15/Images/tabelle.png)

Um die Werte auf diese beiden Kurven anzupassen, werden einfach zwei Gleichungen (MRT = k * ADCH +d) erstellt und die Werte k und d ausgerechnet.  

Zunächst wird nochmal der Wert '1780hex' auf seine Richtigkeit überprüft. 
1780 hex = 6016
6016 / 256 = 23,5°C

![](https://github.com/HTLMechatronics/m15-la1-sx/blob/hoestm15/hoestm15/Images/23%2C5CelsiusSVG.svg)

| Temperatur | V in | ADCH | Modbus Register Wert "MRW" |
|:-------------:|:-----:|:--------:|:-------------------:|
|-45°C|242mV|56,79|-45°C * 2⁸ = -11520|
|25°C|314mV|73,08|25 * 2⁸ = 6400|
|85°C|380mV|88,4|85 * 2⁸ = 2176|

Formel für ADCH = Vin (256/Vref)
 
 MRT = k * ADCH + d
 Als nächstes rechnen wir die Steigung  und den Offset für beide Kurven aus:
	Gleichungspaar 1:
	
	I:  -11520 = k1 * 56,79 + d1 
		 *d* = -11520 - k1 * 56,79
	II: 6400 = k1 * 733,08 + d1
		k1 = 1100,06
		d1 = -73992,49
Gleichungspaar 2:

	I: 6400 = k2 * 73,08 + d2
		d2 = 6400 - k2 * 73,08
	II: 21760 = k2 * 88,4 + d2
		k2 = 1006,61 
		d2 = -66870,809

Als nächstes wird der ADCH Wert für eine Temperatur von 22°C ausgerechnet, da dies der ungefähren Raumtemperatur entspricht. 

	22°C -> 73,04 - 56,79 = 16,29
		16,29 / (25 + 45) = 0,2327
		73,08 - 0,2327 * 25 = 67,2621
		67,2621 + 22 * 0,2327 = 72,381

| Temperatur | ADCH |
|:--------:|:-:|
|22°C|72,3815mV|

	22 * 2⁸ = 5632

Da bei meinem aktuellen Programm eine Raumtemperatur von 78 °C angezeigt wird, muss der Offset so angepasst werden, das dieser Wert auf 22°C sinkt.
		
## 2. Offset korrigieren
 
	 ADCH <= 78 
		 5632 = 1100,06 * ADCH - 73992,49 - Offsetausgleich1
		 Offsetausgleich1 = 6177.19
	 ADCH > 78 
		 5632 = 1002,61 * ADCH - 66870,809 - Offsetausgleich2 
		 Offsetausgleich2 = 5700.771

Umsetzung in C:

```C
void app_main (void) {
   ADCSRA |= (1 << ADSC);
   _delay_ms(1);
   
    //Werte für Steigung und Offset deklarieren
   float k1 = 1100.061, d1 = -73992.464; 
   float k2 = 1002.611, d2 = -66870.812;
   
    //Werte für Offsetkorrektur deklarieren
   float o1 = -6177.19;
   float o2 = -5700.771;
   
   float mbr; 
   uint8_t adch = ADCH;
   if(adch <= 78) { //wenn Wert unter 78 liegt werden die Werte für die untere kurve genommen
     mbr = k1 * adch +d1 +o1; // Modbus Register Wert durch formel ausrechen 
   } else { //ligen die Werte über 78, dann wird die Steigung und der Offset der oberen Kurve genommen.
     mbr = k2 * adch + d2 + o2;
   }

   int32_t k = 1024;
   int32_t d = -82688;
   int32_t x = k * ADCH + d;

   if(x > 32768){
      mbInputRegister = 32768;
   } else if(x < -32768) {
      mbInputRegister = -32768;
   } else {
      mbInputRegister = (int16_t)x;
   }
//Wert des ADCH, der Temperatur und des MBR ausgebens
   printf("ADCH = %u  Temperatur = %d.%02d Grad Celsius   MBR = %d = 0x%d\r", ADCH, vk, nk, mbInputRegister, mbInputRegister);
}
```



## 3. Übertragung via UART

Es gibt 2 Möglichkeiten übertragene Daten auszulesen:

 1. Über Bibliotheksklassen
 2. ohne Bibliotheksklassen

Unsere Realisierung erfolgte über die erste Möglichkeit:
	
```C
	void app_main (void) {
   ADCSRA |= (1 << ADSC);  
   
   float k1 = 1100.061, d1 = -73992.464;
   float k2 = 1002.611, d2 = -66870.812;
   
   float o1 = -6177.19;
   float o2 = -5700.771;
   
   float mbr;
   uint8_t adch = ADCH;
   if(adch <= 78) {
     mbr = k1 * adch +d1 +o1;
   } else {
     mbr = k2 * adch + d2 + o2;
   }

   int16_t mbInputRegister = (int16_t)mbr;
   
   uint8_t vk = mbInputRegister / 256;
   uint8_t nk = ((mbInputRegister & 0xff) * 10) /256;
    
    //Auslesen der Empfangenen Request
   int c = fgetc(stdin);
   if(c != EOF) {
     printf("\n %02x\r\n", (uint16_t)c);
     app_handleUartByte((char) c);
   }
}
```

```C
void app_handleUartByte(char c){
//Ausewrtung der Empfangenen Daten
   if(c == ':') { //Warten auf Startbyte ':', sobalt dies eintrifft werden Daten im Buffer gespeichert
      app.modbusBuffer[0] =c; 
      app.bufferIndex = 1;
   } else {
      if(app.bufferIndex > 0){
	 app.modbusBuffer[app.bufferIndex++] = c;
      }
   }
}
```
```C
struct App
{
//Buffer in Headerdatei erstellen

  uint8_t flags_u8;
  char modbusBuffer[32];
  uint8_t bufferindex;
          
};
```
