# Protokoll 3  
Name: Simon Szapacs  
Kat. Nr.: 12  
Klasse: 4AHME  
Gruppe: 2  
Abwesend: Jonas Skof  


Thema: **Übersetzungsvorgang am µC**

## Übersicht  
**1)** Advanced Packing Tool  
	**1.1)** Wichtige APT Commands  
**2)** Atmega 16 C-Programm  
	**2.1)** Programm  
	**2.2)** Intelhex  
**3)** Inbetriebnahme des Programms  


## 1) Adavnced Packing Tool  

Das Advanced PAcking Tool ist ein Paketverwaltungssystem.  
Mit diesem System möchte man erreichen, dass man einen einfache Möglichkeit hat zur Suche, Installation, Aktualisierung von Programmpaketen.


### 1.2) Wichtige ATP Commands  
Für diese Befehle muss man als Superuser eingelogget sein, sonnst funktionieren diese nicht!  

| Befehl | Funktion |  
| ------ | -------- |  
| `apt upgrade` | Zeigt, welche und wie viele Pakete aktualisiert werden müssen |  
| `apt install <package_1> <package_2> <package_3>` | brauch man, um mehrere Pakete gleichzeitig zu installieren |  
| `apt install <package_name>` | Installieren von Paketen |  
| `apt update` | Ruft die Paketinformationen von verschiedenen Servern ab und vergleicht diese anschließend mit System |  


## 2) Atmega 16 C-Programm  

### 2.1) Programm  
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

### 2.2) Intelhex  
Das Intel HEX-Format ist ein Datenformat zur Speicherung und Übertragung von binären Daten. Heutzutage verwendet man das Programm nur mehr um Programmierdaten für Mikrocontroller bzw. Mikroprozessoren zu speichern.  

| Typ | Bezeichnung | Verwendung |  
| --- | ----------- | ---------- |  
| 00 | Data Record | Nutzdaten |  
| 01 | End of File Record | Dateiende (sowie Startadresse bei 8-Bit-Daten) |  
| 02 | Extended Segment Address Record | Erweitere Segmentadresse für nachfolgende Nutzdaten |  
| 03 | Start Segment Address Record  | Startsegmentadresse |  
| 04 | Extended Linear Address Record | Erweiterte lineare Adresse, höherwertige 16 Bit der Adresse für nachfolgende Nutzdaten |  
| 05 | Start Linear Address Record | Lineare Startadresse |  


## 3) Inbetriebnahme 


**Der Startcode**  
Der Startcode initialisiert den Mikrocontroller und muss mit der Konfiguration des Hardware-Designs übereinstimmen.  

**Preprozessorquelltext:**  
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
**Kompilieren zum Assamblertext:**  
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
**Programmausführung:**  
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









