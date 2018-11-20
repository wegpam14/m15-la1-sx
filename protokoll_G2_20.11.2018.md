# 3. Protokoll

![](https://www.htl-kaindorf.at/images/startpage/logoMecha.png) 

Name: Perl Nicolas  
Kat.-Nr.: 10  
Klasse: 4AHME  
Gruppe: 2  

| Anwesend | Abwesend |  
| --------------------------------------- | -------- |  
| M.Korrenn, A.Murko, D.Orthofer, N.Perl, S.Szapacs | J.Skof |  
___

### Themen-Übersicht
 - **1)** - Advanced Packaging Tool
 	- **1.1)** - Wichtige APT Commands  
 - **2)** - Atmega16 C-Programm  
 	- **2.1)** - Programm und dessen Commands   
	- **2.2)** - Probleme bei Inbetriebnahme  
	- **2.3)** - Intelhex  
 - **3)** - Inbetriebnahme
 
___
	
## **1.) - Advanced Packaging Tool -**  
Das [Advanced Packaging Tool](https://de.wikipedia.org/wiki/Advanced_Packaging_Tool) (APT) ist ein Paketverwaltungssystem, das im Bereich des Betriebssystems Debian entstanden ist. dpkg wird hierbei zur eigentlichen Paketverwaltung benutzt.  
Ziel hierbei ist es, eine einfache Möglichkeit zur Suche, Installation und Aktualisierung von Programmpaketen zur Verfügung zu stellen.  

### **1.1) - Wichtige APT Commands -**  

**Wichtig:**  
Angegebene Befehle funktionieren nur als Superuser:  
-> Command `sudo -i` um als jener zu agieren, `exit` um sich wieder abzumelden  

| Befehl | Funktion |  
| ------ | -------- |   
| `apt update` | Ruft die Paketinformationen von verschiedenen Servern ab, vergleicht diese mit System |  
| `apt upgrade` | Zeigt, wie viele und welche Pakete aktualisiert werden sollen |  
| `apt install <package_name>` | Installieren von Paketen |  
| `apt install <package_1> <package_2> <package_3>` | wird genutzt, um mehrere Pakete gleichzeitig zu installieren |  

In der Datei `/etc/apt/sources.list` stehen die sogenannten Repositories( Quellen für Pakete, z.B.Verzeichnisse auf der Festplatte)  

Die Pakete liegen im [Debian](https://de.wikipedia.org/wiki/Debian)-Paketformat (.deb) vor, in dem auch die jeweiligen Abhängigkeiten der Programmpakete untereinander abgelegt sind. So werden automatisch für ein Programm auch eventuell erforderliche Programmbibliotheken mit heruntergeladen und installiert.

APT setzt auf dpkg auf. APT beschäftigt sich in erster Linie mit der Beschaffung von Paketen, dem Vergleich von verfügbaren Versionen der Pakete und der Verwaltung von Paket-Archiven. 

___

#### Implizierte Deklaration:

Erst nach der Deklaration kann einer Variablen ein Ausdruck zugewiesen werden. Neben der expliziten Deklaration gibt es aber auch die Möglichkeit einer impliziten Deklaration von Variablen: In diesem Fall führt das erste Auftreten einer Variablen zu einer automatischen Typzuordnung. 

## **2.) - Atmega16 C-Programm -**  
### **2.1) - Programm und dessen Commands -**  
```C
#include <avr/io.h>
#define F_CPU 12000000L
#include <util/delay.h>

int main()
{
  DDRA = 0x01;
  while(1)
  {
    PORTA ^= 0x01;
    _delay_ms(300);
  }
  return 0;
}
```

| Command | Definition |  
| --------------------------------------- | ------ |  
| `#include <avr/io.h>` | enthält E/A-Definitionen für das Gerät, die vom Befehlszeilenschalter -mmcu = des Compilers angegeben wurden. |  
| `#define F_CPU 12000000` | Frequenz der CPU bekannt geben |  
| `#include <util/delay.h>` | Komfortfunktion, bei denen die tatsächlichen Zeitwerte angegeben werden können |  
| `PORTA ^= 0x01;` | PORTA soll als Ausgang verwenden werden: man muss das Register konfigurieren: Setzten -> eine logische 1 (5 Volt) |    
| `_delay_ms(300);` | um das blinkende Licht visuell mit dem Auge erfassen zu können |  


### **2.2) - Probleme bei Inbetriebnahme -**  
-> Programm läuft nicht am PC, da Befehlstypen ähnlich sind, jedoch die Befehlsmuster anders  
-> nur für **den einen** Prozessor geeignet, für den es geschrieben wurde 

#### `a out <elf-Datei>`  
*2 Optionen*:  
-> `avrdude` direkt in Flash hineinprogrammieren  
-> über Intelhex, Easyprogrammer und Booten in Flash programmieren  

### **2.3) - Intelhex -**  

Das Intel HEX-Format ist ein Datenformat zur Speicherung und Übertragung von binären Daten. Es wird heute hauptsächlich verwendet, um Programmierdaten für Mikrocontroller bzw. Mikroprozessoren zu speichern.

| Typ | Bezeichnung | Verwendung |  
| --- | ----------- | ---------- |  
| 00 | Data Record | Nutzdaten |  
| 01 | End of File Record | Dateiende (sowie Startadresse bei 8-Bit-Daten) |  
| 02 | Extended Segment Address Record | Erweitere Segmentadresse für nachfolgende Nutzdaten |  
| 03 | Start Segment Address Record  | Startsegmentadresse |  
| 04 | Extended Linear Address Record | Erweiterte lineare Adresse, höherwertige 16 Bit der Adresse für nachfolgende Nutzdaten |  
| 05 | Start Linear Address Record | Lineare Startadresse |  

![](https://www.mikrocontroller.net/attachment/200445/IntelHEX.png)  

**Quelle:** [Wikipedia](https://de.wikipedia.org/wiki/Intel_HEX)  

___

## **3.) - Inbetriebnahme -**  

##### `avr-objcopy -O ihex a.out a.hex`  
Man hat die Binärdatei der Anwendung, aber wie bekommen wir sie in den Prozessor?  
Eine ausführbare GNU-Datei wird nicht als Eingabedatei akzeptiert. Folge: Extrahieren von Teilen der Binärdatei und das Speichern der Informationen in Hex-Dateien. Das GNU-Dienstprogramm, das dies ausführt, heißt avr-objcopy.  
`less a.hex` -> Datei ansehen  
`avr-gcc -mmcu=atmega16 -Os -E main.c | -S` -> Um eine C-Datei mit avr-gcc optimiert zu einem lauffähigen Programm für einen ATmega16 zu compilieren

*- Der Startupcode -*  
Der Startcode initialisiert den Mikrocontroller und muss mit der Konfiguration des Hardware-Designs übereinstimmen. 

->  [Bootloader und Startupcode](https://stackoverflow.com/questions/15696258/what-is-the-bootloader-and-startup-code-in-embedded-systems/15697047)

___

#### **`avr-gcc -mmcu=atmega16 -Os -S main.c` - Präprozessieren zum Preprozessorquelltext**  
*Ein kleiner Ausschnitt des Preprozessorquelltexts:*  

```C
 uint32_t __ticks_dc;
 extern void __builtin_avr_delay_cycles(unsigned long);
 __tmp = ((
# 263 "/usr/lib/avr/include/util/delay.h"
          12000000L
# 263 "/usr/lib/avr/include/util/delay.h" 3
               ) / 1e6) * __us;
# 273 "/usr/lib/avr/include/util/delay.h" 3
  __ticks_dc = (uint32_t)(ceil(fabs(__tmp)));


 __builtin_avr_delay_cycles(__ticks_dc);
# 299 "/usr/lib/avr/include/util/delay.h" 3
}
# 6 "main.c" 2


# 7 "main.c"
int main()
{
  
# 9 "main.c" 3
 (*(volatile uint8_t *)((0x1A) + 0x20)) 
# 9 "main.c"
      = 0x01;
  while(1)
  {
    
# 12 "main.c" 3
   (*(volatile uint8_t *)((0x1B) + 0x20)) 
# 12 "main.c"
         ^= 0x01;
    _delay_ms(300);
  }
  return 0;
}

```
##### Zeile: `(*(volatile uint8_t *)((0x1B) + 0x20))`  

`DDRA -> (*(unsigned char*)(0x1A)+0x20)`  
(unsigned char*) -> Zeiger auf unsigned character  
(0x1A)+0x20 = 0x3A=58 -> Konstanten  

--> ***(Adresse 58)** -> greift auf Inhalt der Adresse zu  

___

#### **`avr-gcc -mmcu=atmega16 -Os -c main.s` - Kompilieren zum Assemblerquelltext**    

```C
.file	"main.c"
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__SREG__ = 0x3f
__tmp_reg__ = 0
__zero_reg__ = 1
	.section	.text.startup,"ax",@progbits
.global	main
	.type	main, @function
main:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	ldi r24,lo8(1)
	out 0x1a,r24
	ldi r25,lo8(1)
.L2:
	in r24,0x1b
	eor r24,r25
	out 0x1b,r24
	ldi r18,lo8(719999)
	ldi r19,hi8(719999)
	ldi r24,hlo8(719999)
1:	subi r18,1
	sbci r19,0
	sbci r24,0
	brne 1b
	rjmp .
	nop
	rjmp .L2
	.size	main, .-main
	.ident	"GCC: (GNU) 5.4.0"
```
___

#### **`avr-gcc -mmcu=atmega16 -Os main.o` - compiliertes Programm ausführen**

```C
#include <avr/io.h>

#define F_CPU 12000000L

#include <util/delay.h>

int main()
{
  DDRA = 0x01;
  while(1)
  {
    PORTA ^= 0x01;
    _delay_ms(300);
  }	
  return 0;
}
```

___

