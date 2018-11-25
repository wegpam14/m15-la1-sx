# Protokoll 3 (25.11.2018)  
![](https://www.koerbler.com/neuigkeiten/wp-content/uploads/2013/03/htl-kaindorf.jpg)  
Name: Korrenn Marwin  
KNr.: 7  
Klasse: 4AHME  
Gruppe: 2  
___  
## Übersicht  
1. Advanced Packing Tool
    1. Wichtige APT Befehle  
    1. Debian Package  
1. Übersetzungsvorgang im µC
    1. main.c
    1. Wichtiger Zeilen aus dem Terminalauszug
    1. [Intel Hex](https://de.wikipedia.org/wiki/Intel_HEX) 
___
## 1. Advanced Packing Tool  
Das [Advanced Packing Tool](https://de.wikipedia.org/wiki/Advanced_Packaging_Tool)
ist ein Paketverwltungssystem, mit dem Ziel, eine einfache Möglichkeit zur Suche, 
Installation und Aktualisierung von Programmpaketen zur Verfügung zu stellen.  

### 1.1 Wichtige APT Befehle  
| Befehl | Funktion |  
| ------ | -------- |   
| `apt update` | ruft die Paketinformationen von verschiedenen Servern ab und vergleicht diese mit dem System |  
| `apt upgrade` | Zeigt, wie viele und welche Pakete aktualisiert werden sollen |  
| `apt install <package_name>` | installiert das Packet |  
| `apt install <package_1> <package_2> <package_3>` | hiermit kann man mehrere Packete gleichzeitig installieren|  

### 1.2 Debian Package  
Debian-Pakete dienen der Softwareinstallation auf Debian-basierten Betriebssystemen. Sie enthalten die zu installierenden Programme in komprimierter Form.
Das Paketformat wurde von Ian Murdock entwickelt, die Abkürzung Deb leitet sich hierbei aus dem ersten Teil des Namens der Distribution Debian, 
der sich wiederum von den Namen „Debra“ (der Vorname Murdocks damaliger Frau) und „Ian“ ableitet.  
___
## 2. Übersetzungsvorgang im µC  
###  2.1 main.c  

Das Programm für den µC:  

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
*Erklärung des Quelltextes:*   

| Command | Definition |  
| --------------------------------------- | ------ |  
| `#include <avr/io.h>` | enthält E/A-Definitionen für das Gerät, die vom Befehlszeilenschalter -mmcu (des Compilers) angegeben wurden. |  
| `#define F_CPU 12000000` | hier wird die Frequenz der CPU bekannt gegeben |  
| `#include <util/delay.h>` | bindet die *"Delay"* Funktion ein |  
| `PORTA ^= 0x01;` | PORTA soll als Ausgang verwenden werden |    
| `_delay_ms(300);` | um das blinkende Licht visuell mit dem Auge erfassen zu können |  

###  2.2 Wichtiger Zeilen aus dem Terminalauszug  
```C
joker@joker:~Schreibtisch/labor3$ nano main.c
joker@joker:~Schreibtisch/labor3$ cat main.c
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
joker@joker:~Schreibtisch/labor3$ avr-gcc -mmcu=atmega16 -Os main.c
joker@joker:~Schreibtisch/labor3$ ll
insgesamt 20
drwxr-xr-x  2 joker joker 4096 Nov 20 09:41 ./
drwxr-xr-x 24 joker joker 4096 Nov 20 08:32 ../
-rwxr-xr-x  1 joker joker 5748 Nov 20 09:41 a.out*
-rw-r--r--  1 joker joker  183 Nov 20 09:40 main.c
joker@joker:~Schreibtisch/labor3$ avr-gcc -mmcu=atmega16 -Os -E main.c | less -S
joker@joker:~Schreibtisch/labor3$ avr-gcc -mmcu=atmega16 -Os -S main.c
joker@joker:~Schreibtisch/labor3$ avr-objdump -d main.o
main.o:     Dateiformat elf32-avr


Disassembly of section .text.startup:

00000000 <main>:
   0:	81 e0       	ldi	r24, 0x01	; 1
   2:	8a bb       	out	0x1a, r24	; 26
   4:	91 e0       	ldi	r25, 0x01	; 1
   6:	8b b3       	in	r24, 0x1b	; 27
   8:	89 27       	eor	r24, r25
   a:	8b bb       	out	0x1b, r24	; 27
   c:	2f e7       	ldi	r18, 0x7F	; 127
   e:	3c ef       	ldi	r19, 0xFC	; 252
  10:	8a e0       	ldi	r24, 0x0A	; 10
  12:	21 50       	subi	r18, 0x01	; 1
  14:	30 40       	sbci	r19, 0x00	; 0
  16:	80 40       	sbci	r24, 0x00	; 0
  18:	01 f4       	brne	.+0      	; 0x1a <main+0x1a>
  1a:	00 c0       	rjmp	.+0      	; 0x1c <main+0x1c>
  1c:	00 00       	nop
  1e:	00 c0       	rjmp	.+0      	; 0x20 <__zero_reg__+0x1f>
joker@joker:~Schreibtisch/labor3$ avr-gcc -mmcu=atmega16 -Os main.o
a.out:     Dateiformat elf32-avr
...
0000008e <__stop_program>:
  8e:	ff cf       	rjmp	.-2      	; 0x8e <__stop_program>
joker@joker:~Schreibtisch/labor3$ ll
insgesamt 64
drwxr-xr-x  2 joker joker  4096 Nov 20 10:23  ./
drwxr-xr-x 29 joker joker  4096 Nov 20 10:06  ../
-rw-r--r--  1 joker joker   418 Nov 20 09:54  a.hex
-rwxr-xr-x  1 joker joker  5748 Nov 20 10:23  a.out*
-rw-rw-r--  1 joker joker    79 Nov 20 10:01 '.~lock.Unbenannt 1.odt#'
-rw-r--r--  1 joker joker   183 Nov 20 09:40  main.c
-rw-r--r--  1 joker joker   888 Nov 20 10:21  main.o
-rw-r--r--  1 joker joker   537 Nov 20 10:20  main.s
-rw-rw-r--  1 joker joker 27779 Nov 20 10:01 'Unbenannt 1.odt'

```  
### 2.3 Intel Hex  
Das Intel HEX-Format ist ein Datenformat zur Speicherung und Übertragung von binären Daten. Es wird heute hauptsächlich verwendet, um Programmierdaten für Mikrocontroller bzw. Mikroprozessoren, EPROMs und ähnliche Bausteine zu speichern. Es kann aber auch zur Speicherung von Lademodulen verwendet werden. Das HEX-Format ist das älteste Datenformat seiner Art und seit den 1970er Jahren in Gebrauch. Spätere Erweiterungen unterstützen speziell die segmentierte Adressierung der Intel-80x86-Prozessoren.  
![](https://www.mikrocontroller.net/attachment/200445/IntelHEX.png)  

| Typ | Bezeichnung | Verwendung |  
| --- | ----------- | ---------- |  
| 00 | Data Record | Nutzdaten |  
| 01 | End of File Record | Dateiende (sowie Startadresse bei 8-Bit-Daten) |  
| 02 | Extended Segment Address Record | Erweitere Segmentadresse für nachfolgende Nutzdaten |  
| 03 | Start Segment Address Record  | Startsegmentadresse |  
| 04 | Extended Linear Address Record | Erweiterte lineare Adresse, höherwertige 16 Bit der Adresse für nachfolgende Nutzdaten |  
| 05 | Start Linear Address Record | Lineare Startadresse |  

**Quelle:** [Wikipedia](https://de.wikipedia.org/wiki/Intel_HEX)  
