# Protokoll 3 (20.11.2018)  
**Name:** Orthofer  
**KNR:** 8  
**Klasse:** 4AHME  
**Gruppe:** 2 
## Verzeichnis  
1. Advanced Packaging Tool  
1. Atmega 16 C-Program  
1. Befehle zur Inbetriebnahme  
## Advanced Packaging Tool  
Das [Advanced Packaging Tool](https://de.wikipedia.org/wiki/Advanced_Packaging_Tool) ist ein System zur Paketverwaltung. Es ist für das Betriebssytem Debian entwickelt worden. Ziel ist es, eine einfache Möglichkeit zur Suche, Installation und Aktualisierung von Programmpaketen zur Verfügung zu stellen.  
### Anwendungsbeispiele  
*Die Befehle funktionieren nur als Superuser (`sudo i`)*  

| Befehl | Funktion |  
| ------ | -------- |   
| `apt update` | Vergleicht Paketinformationen mit Server |  
| `apt upgrade` | Zeigt, wie viele und welche Pakete aktualisiert werden sollen |  
| `apt install <package_name>` | Installieren von Paketen |    


In der Datei `/etc/apt/sources.list` stehen die sogenannten Repositories (Quellen für Pakete). Die Pakete liegen im Debian-Paketformat (.deb) vor, in dem auch die jeweiligen Abhängigkeiten der Programmpakete untereinander abgelegt sind. So werden automatisch für ein Programm auch eventuell erforderliche Programmbibliotheken mit heruntergeladen und installiert. APT beschäftigt sich in erster Linie mit der Beschaffung von Paketen, dem Vergleich von verfügbaren Versionen der Pakete und der Verwaltung von Paket-Archiven. 
[Quelle](https://de.wikipedia.org/wiki/Advanced_Packaging_Tool)  
## Atmega 16 C-Programm  
```C
#include <avr/io.h>
#define F_CPU 12000000L
#include <util/delay.h>
int main () {
    DDRA = 0x01;
    while(1) {
    PORTA ^= 0x01;
    _delay_ms(300);
    }
    return 0;
}
```
`#include <avr/io.h>`: Enthält E/A-Definitionen, vom Befehlszeilenschalter -mmcu angegeben.  
`#define F_CPU 12000000L`: Angabe Frequenz CPU  
`#include <util/delay.h>`: Funktion für tatsächliche Zeitwerte  
`DDRA = 0x01;`: Bekanntgabe Register  
`PORTA ^= 0x01;`: Konfiguration des Registers  
`_delay_ms(300);`: LED wird mit einem delay von 300ms ein- und ausgeschalten  
  
*Ein Problem bei der Inbetriebnahme ist, dass das Befehlsmusters des Programm nur auf einen bestimmten Prozessor zugeschnitten ist.*  
  
**Es stehen zwei Optionen zur Verfügung:**
1. direkt über [avrdude](https://www.mikrocontroller.net/articles/AVRDUDE) in den Flash programmieren
1. über [Intel Hex](https://de.wikipedia.org/wiki/Intel_HEX), [Easyprogrammer](http://www.htl-mechatronik.at/ubuntu-htl/docs/EasyProgrammer.pdf) und Booten in den Flash programmieren

### Intel Hex  
Das Intel HEX-Format ist ein Datenformat zur Speicherung und Übertragung von binären Daten. Es wird heute hauptsächlich verwendet, um Programmierdaten für Mikrocontroller bzw. Mikroprozessoren, EPROMs und ähnliche Bausteine zu speichern. Es kann aber auch zur Speicherung von Lademodulen verwendet werden. Das HEX-Format ist das älteste Datenformat seiner Art und seit den 1970er Jahren in Gebrauch.  
  
| Typ | Bezeichnung |  Verwendung |
| ---- | -------- | ----------- |
| 00 | Data Record | Nutzdaten |
| 01 | End of File Record | Dateiende (sowie Startadresse bei 8-Bit-Daten) | 
| 02 | Extended Segment Address Record | Erweitere Segmentadresse für nachfolgende Nutzdaten |
| 03 | Start Segment Address Record | Startsegmentadresse (CS:IP Register) |
| 04 | Extended Linear Address Record | Erweiterte lineare Adresse, höherwertige 16 Bit der Adresse für nachfolgende Nutzdaten |
| 05 | Start Linear Address Record | Lineare Startadresse (EIP-Register) |
  
[Quelle](https://de.wikipedia.org/wiki/Intel_HEX)  
## Befehle zur Inbetriebnahme  
  
**Generieren von Intel Hex Files**  
Das Problem ist das eine ausführbare GNU-Datei nicht als Input-File akzeptiert wird. Es muss erst in eine .hex Fiel umgewandelt werden in der die Informationen gespeichert werden. Das GNU-Programm dafür heißt avr-objcopy.  

`avr-gcc -mmcu=atmega16 -Os -E main.c | -S` Befehl um das Programm für den Atmega16 lauffähig zu machen  
  
`avr-gcc -mmcu=atmega16 -Os -S main.c`**: Präprozessieren**  
*Ausschnitte*
```C
# 1 "main.c"
# 1 "<eingebaut>"
# 1 "<Kommandozeile>"
# 1 "main.c"
# 1 "/usr/lib/avr/include/avr/io.h" 1 3
# 99 "/usr/lib/avr/include/avr/io.h" 3
# 1 "/usr/lib/avr/include/avr/sfr_defs.h" 1 3
# 126 "/usr/lib/avr/include/avr/sfr_defs.h" 3
# 1 "/usr/lib/avr/include/inttypes.h" 1 3
# 37 "/usr/lib/avr/include/inttypes.h" 3
# 1 "/usr/lib/gcc/avr/5.4.0/include/stdint.h" 1 3 4
# 9 "/usr/lib/gcc/avr/5.4.0/include/stdint.h" 3 4
# 1 "/usr/lib/avr/include/stdint.h" 1 3 4
# 125 "/usr/lib/avr/include/stdint.h" 3 4

# 125 "/usr/lib/avr/include/stdint.h" 3 4
typedef signed int int8_t __attribute__((__mode__(__QI__)));
typedef unsigned int uint8_t __attribute__((__mode__(__QI__)));
typedef signed int int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int uint16_t __attribute__ ((__mode__ (__HI__)));
typedef signed int int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int uint32_t __attribute__ ((__mode__ (__SI__)));

typedef signed int int64_t __attribute__((__mode__(__DI__)));
typedef unsigned int uint64_t __attribute__((__mode__(__DI__)));
# 146 "/usr/lib/avr/include/stdint.h" 3 4
typedef int16_t intptr_t;




typedef uint16_t uintptr_t;
# 163 "/usr/lib/avr/include/stdint.h" 3 4
typedef int8_t int_least8_t;

..........

typedef uint64_t uintmax_t;
# 10 "/usr/lib/gcc/avr/5.4.0/include/stdint.h" 2 3 4
# 38 "/usr/lib/avr/include/inttypes.h" 2 3
# 77 "/usr/lib/avr/include/inttypes.h" 3
typedef int32_t int_farptr_t;



typedef uint32_t uint_farptr_t;
# 127 "/usr/lib/avr/include/avr/sfr_defs.h" 2 3
# 100 "/usr/lib/avr/include/avr/io.h" 2 3
# 298 "/usr/lib/avr/include/avr/io.h" 3
# 1 "/usr/lib/avr/include/avr/iom16.h" 1 3
# 639 "/usr/lib/avr/include/avr/iom16.h" 3
       
# 640 "/usr/lib/avr/include/avr/iom16.h" 3

  2 3

 
 );
}
# 46 "/usr/lib/avr/include/util/delay.h" 2 3
# 1 "/usr/lib/avr/include/math.h" 1 3
# 127 "/usr/lib/avr/include/math.h" 3
extern double cos(double __x) __attribute__((__const__));

..........

 uint32_t __ticks_dc;
 extern void __builtin_avr_delay_cycles(unsigned long);
 __tmp = ((
# 174 "/usr/lib/avr/include/util/delay.h"
          12000000L
# 174 "/usr/lib/avr/include/util/delay.h" 3
               ) / 1e3) * __ms;
# 184 "/usr/lib/avr/include/util/delay.h" 3
  __ticks_dc = (uint32_t)(ceil(fabs(__tmp)));


 __builtin_avr_delay_cycles(__ticks_dc);
# 210 "/usr/lib/avr/include/util/delay.h" 3
}
# 254 "/usr/lib/avr/include/util/delay.h" 3
void
_delay_us(double __us)
{
 double __tmp ;



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
# 4 "main.c" 2

# 4 "main.c"
int main () {
    
# 5 "main.c" 3
   (*(volatile uint8_t *)((0x1A) + 0x20)) 
# 5 "main.c"
        = 0x01;
    while(1) {
    
# 7 "main.c" 3
   (*(volatile uint8_t *)((0x1B) + 0x20)) 
# 7 "main.c"
         ^= 0x01;
    _delay_ms(300);
    }
    return 0;

}  
```  
**Zeile:** `(*(volatile uint8_t *)((0x1B) + 0x20))`  

`DDRA -> (*(unsigned char*)(0x1A)+0x20)`  
(unsigned char*) -> Zeiger auf unsigned character  
  
`avr-gcc -mmcu=atmega16 -Os -c main.s`**: Assemblerquelltext**  
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
