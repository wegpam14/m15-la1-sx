## Protokoll 6

Name: Sarah Vezonik  
Datum, Ort: 18. Dezember 2018, Kaindorf  
Gruppe: 3  
Anwesend: Vezonik, Vollmaier, Wegl, Winter M., Winter T.;  
Abwesend: Wesonig


----------
### Inhaltsverzeichnis
[1] Modbus - ASCII  
[2] Temperatur Sensor  
[3] ADC  
[4] ADCH ADCL  
[5] Modbus RTU  
[6] Programmbeschreibung  


----------

### [1] Modbus - ASCII


----------


**ASCII-Modbus**
Im Modbus ASCII wird keine Binärfolge, sondern ASCII-Code übertragen. Dadurch ist es direkt für den Menschen lesbar, allerdings ist der Datendurchsatz im Vergleich zu RTU geringer.

![enter image description here](https://raw.githubusercontent.com/HTLMechatronics/m15-la1-sx/vezsam15/Modbus%20ASCII.png)

**Protokollaufbau**
Im ASCII-Modus beginnen Nachrichten mit einem vorangestellten Doppelpunkt, das Ende der Nachricht wird durch die Zeichenfolge Carriage return – Line feed (CRLF) markiert.

Die ersten zwei Bytes enthalten zwei ASCII-Zeichen, die die Adresse des Empfängers darstellen. Der auszuführende Befehl ist auf den nächsten zwei Bytes codiert. Über weitere n Zeichen folgen die Daten. Über das gesamte Telegramm (ohne Start- und Ende-Markierung) wird zur Fehlerprüfung ein LRC ausgeführt, dessen Paritätsdatenwort in den abschließenden zwei Zeichen untergebracht wird. Tritt während der Übertragung eines Frames eine Pause von > 1s auf, wird der Frame als Fehlerfall bewertet. Der Benutzer kann ein längeres Timeout konfigurieren.
Start 	Adresse 	Funktion 	Daten 	LR-Check 	Ende
1 Zeichen (:) 	2 Zeichen 	2 Zeichen 	n Zeichen 	2 Zeichen 	2 Zeichen (CRLF) 

| Start |Adresse|Funktion |  Daten |  LR-Check | Ende
|---|---|---|---|---|
| 1Zeichen (:)  |2 Zeichen   |2 Zeichen   |  n Zeichen | 2 Zeichen  | 2 Zeichen (CRLF)

**Bsp:** 

    :010400000001xxcrxLF
 **Erklärung:**   
|  Funktion Code | RegisterAdresse|Anzahl   |LRC   |   
|---|---|---|---|---|
|  04 |0000   |0001   |xx   | 


----------


### [2] Temperatursensor


----------


**Technische Daten des DS18B20**

 - Betriebsspannung – 3.0V bis 5.5V  
 - Messbarer Temperaturbereich von -55°C bis +125°C
 - Toleranz – ±0.5°C
 - Auflösung des Thermometers von 9 bis 12bit
 - jeder Sensor hat einen eindeutigen und einmaligen 64bit Code auf
     dem onboard ROM 
 - nähert ich Schritt für Schritt an den Wert an: 



![enter image description here](https://raw.githubusercontent.com/HTLMechatronics/m15-la1-sx/vezsam15/Temperatursensor.png)


----------

### [3] ADC


----------


Wenn es darum geht, Spannungen zu messen, wird der Analog-/Digital-Wandler (kurz: A/D-Wandler) oder englisch Analog Digital Converter (ADC) benutzt. Er konvertiert eine elektrische Spannung in eine Digitalzahl. Prinzipiell wird dabei die Messspannung mit einer Referenzspannung verglichen. Die Zahl drückt daher das Verhältnis der Messspannung zu dieser Referenzspannung aus. Sie kann in gewohnter Weise von einem Mikrocontroller weiterverarbeitet werden. 

 - mit 50 - 200 kHz betreiben
 - **Wichtig:**
 Da sich der Kondensator entladet, ist dass Ergebnis unter 50 kHz nicht mehr richtig!
  
**Berechnung:**

 - ADC = (Vin * 1024)/ Vref 
 - ADCH = ADC/4

|  Temperatur | Voltage  |   ADC | ADCH
|---|---|---|---|---|
| -45°C  | 242mV  |   223 | 55
|   +25°C| 314mV  |   292 |73
|   +85°C|  380mV |  353 |88


----------


### [4] ADCH ADCL

----------


Da das Ergebnis des ADC ein 10 Bit Wert ist, passt dieser Wert naturgemäß nicht in ein einzelnes Register, das ja bekanntlich nur 8 Bit breit ist. Daher wird das Ergebnis in 2 Register ADCL und ADCH abgelegt. Standardmäßig (d.h. ADLAR = 0) werden von den 10 Ergebnisbits die niederwertigsten 8 im Register ADCL abgelegt und die noch fehlenden 2 Bits im Register ADCH an den niederwertigsten Bitpositionen gespeichert.  


 
![ASCL ADCH](https://raw.githubusercontent.com/HTLMechatronics/m15-la1-sx/vezsam15/ADCH_ADCL.PNG)

**Links oder Rechtsbündig?**  

In unserem Fall ist **linksbündig** besser, da wir nur 8 Bits brauchen und diese somit im ADCH sind.

**Prozentuell:**

10 Bit  = 0 ... 1023 
10 Bit = 1/1023 = 0,1%

----------

[5]Modbus RTU

----------

Das Modbus RTU basiert auf dem Modbus-Protokoll, bei welchem es sich um ein Kommunikationsprotokoll handelt, welches auf einer Master-Slave-Architektur basiert, die auch als Client-Server-Verbindung bezeichnet werden kann. Der Ursprung dieser technischen Applikation liegt in der Arbeit vom Unternehmen Gould-Modicon, welches den Modbus seit 1979 entwickelte, mit dem Zweck der Kommunikation der speicherprogrammierbaren Steuerungen. Der entscheidende Vorteil, welcher auch die Wichtigkeit dieser Anwendung und deren Festigung als ein Standard verursachte, liegt darin, dass es sich hier um ein offenes Protokoll handelt. Als offen gilt hierbei ein Standard nur dann, wenn er für alle Anwender leicht zugänglich, einsetzbar und ausbaufähig ist.


###  **app.c**

    void app_init (void)
    {
      memset((void *)&app, 0, sizeof(app));
      ADMUX = (1 << REFS1) | (1<< REFS0) | ( 1<< ADLAR) | 0x08;
      ADCSRA = (1<< ADEN) | 7; // 7 bedeutet durch 128, dass sind 125 kHz
      app.modbus.frameIndex = -1;
    }

    void app_task_16ms (void) {
      
      app.adch = ADCH;
      ADCSRA |= (1<< ADSC); //Starte ADC
     
    }
    void app_handleUartByte(char c){
      
      struct Modbus *p = &app.modbus;
      
      if (p ->frameIndex < 0)
      {
        return;
      }
    if( c == ':'){
      
        p ->frameIndex = 0;
        p->frameError = 0;
      }
    else if ( c == '\n'){
      if (p->frameError == 0){
        app_parseModbusFrame();
      }
    }
    else if (p ->frameIndex  < 16){
      p ->frameIndex [p ->frameIndex] = c;
    }
    else if (p -> errCnt == 0)
      {
        p->frameError = 1;
        if(p->errCnt < 0xffff){
          p-> errCnt++;
        }
      }
    }
    
###  **app.h**
    
    struct Modbus // Struktur um alle Komponenten 
					    für Modbus gesammelt zu haben (Überichtlich)
    {
     char frame[16];
     int8_t frameIndex;
     uint16_t frameError;
     uint16_t errCnt;
    };
    
    struct App
    {
      uint8_t adch;
      struct Modbus modbus;
      
    };

 - struct um alle Komponenten für Modbus gesammelt zu haben (übersichtlicher)

 ###  **sys.c**


        ISR (SYS_UART_RECEIVE_VECTOR)
	    {
	      static uint8_t lastChar;
	      uint8_t c = SYS_UDR;
    
	      if (c=='R' && lastChar=='@')
	      {
	        wdt_enable(WDTO_15MS);
	        wdt_reset();
	        while(1) {};
	      }
	      lastChar = c;
	      app_handleUartByte(c);

----------

[6]**Programmbeschreibung**

----------
Der Analog-Digital-Wandler wandelt eine analoge Eingangsspannung durchs sukzessive Approximation (Bild im Anhang) in einen 10-bit Digitalwert.

 - max Wert = ausgewählten Referenzspannung - 1 LSB
 - min Wert = GND

Die Referenzspannung für den Analog-Digital-Wandler:  Bits **REFS1** und **REFS0** im ADMUX-Register Die Referenzspannung liegt am AVCC Pin an. (Möglich VCC oder die interne Referenzspannung von **2,56V**.)
Der Analog-Digital-Wandler erzeugt ein 10-bit Ergebnis: **ADCH** und **ADC.**
optional kann das Ergebnis aber auch linksbündig in ADCH und ADCL geschrieben werden. Die Einstellung erfolgt mit dem ADLAR-Bit im ADMUX-Register.

1. Register des ADC’s initialisieren und der app.modbus.frameIndex auf -1 gesetzt um in einen Idle Zustand zu gehen.
2.  linksbündige Wert des ADCH Registers in eine Zwischenvariable gespeichert und der ADC gestartet, indem das ADCH Register gesetzt wird.
3. Übertragung des Temperaturwertes auf die Konsole des PC’s.

**Sukzessive Approximation**
![enter image description here](http://www.vias.org/mikroelektronik/img/adcsukap.png)



