## Der Compiliervorgang-Wiederholung
Im ersten Schritt wird die Datei `main.c` zur Objektdatei `main.o` übersetzt. In diesem Vorgang werden vom *Preprozessor* alle Header-Dateien eingebunden. Beim *Compilen* wird der Quelltext dann in [Assemblerbefehle](https://de.wikipedia.org/wiki/Assembler_(Informatik)) übersetzt. Beim *Assemblieren* wird der Assemblerquelltext dann in binäre Maschinenbefehle übersetzt.

Im zweiten Schritt wird die Objektdatei `main.o` zur ausführbaren (*executable*) Datei `main.elf` übersetzt. Dieser Vorgang wird *Linken* genannt. Hier werden alle tatsächlichen Adressen eingetragen, wodurch das Programm ausgeführt werden kann.

Der dritte Schritt wird nur benötigt, wenn das System die `main.elf` nicht ausführen kann. Die Datei `main.elf` wird zur Hex-Datei `main.hex` übersetzt. Dieser Vorgang wird *Konvertieren* genannt.

## Advanced Packaging Tool
Das Advanced Packaging Tool (APT) ist ein Paketverwaltungssystem, das im Bereich des Betriebssystems Debian entstanden ist und dpkg zur eigentlichen Paketverwaltung benutzt. Ziel ist es, eine einfache Möglichkeit zur Suche, Installation und Aktualisierung von Programmpaketen zur Verfügung zu stellen. APT besteht aus einer Programmbibliothek und mehreren diese Bibliothek nutzenden Kommandozeilen-Programmen, von denen apt-get und apt-cache zentral sind. Seit Debian 3.1 wird die Benutzung von Aptitude als konsolenbasiertes APT-Frontend empfohlen.
In der Datei /etc/apt/sources.list stehen die sogenannten Repositories, also Quellen für Pakete. Dies können entweder CDs oder DVDs, Verzeichnisse auf der Festplatte oder, öfter, Verzeichnisse auf HTTP- oder FTP-Servern sein. Befindet sich das gesuchte Paket auf einem Server (oder einem lokalen Datenträger), so wird dieses automatisch heruntergeladen und installiert.
Die Pakete liegen im Debian-Paketformat (.deb) vor, in dem auch die jeweiligen Abhängigkeiten der Programmpakete untereinander abgelegt sind. So werden automatisch für ein Programm auch eventuell erforderliche Programmbibliotheken mit heruntergeladen und installiert.
APT setzt auf dpkg auf. APT beschäftigt sich in erster Linie mit der Beschaffung von Paketen, dem Vergleich von verfügbaren Versionen der Pakete und der Verwaltung von Paket-Archiven.

### Befehle
•	apt-get install paketname installiert ein Paket und sämtliche Abhängigkeiten und in der Standardeinstellung zusätzlich empfohlene Pakete (engl. recommends).  
•	apt-get remove paketname entfernt ein vorhandenes Paket und die Pakete, die von diesem abhängen. Abhängigkeiten dieser Pakete oder Konfigurationsdateien werden jedoch nicht entfernt.  
•	apt-get --purge remove paketname entfernt ein Paket und die Konfigurationsdateien.  
•	apt-get upgrade bringt, sofern möglich, alle Pakete auf den neuesten Stand, installiert jedoch keine neuen Pakete (was evtl. nötig ist, um das System aktuell zu halten, falls sich Abhängigkeiten geändert haben)  
•	apt-get dist-upgrade bringt alle Pakete auf den neuesten Stand und installiert bei Bedarf neue Pakete oder entfernt Pakete, die mit den zu installierenden Paketen in Konflikt stehen.  
•	apt-get update holt die neuesten Informationen über Pakete vom Debian-Server.  
•	apt-get source paketname holt den Quelltext des Paketes vom Debian-Server in das aktuelle Verzeichnis.  
•	apt-cache search suchwort sucht nach Programmen.  
•	zum Finden von Programmen oder Dateien in noch nicht installierten Paketen kann das separate Tool apt-file oder auch dpkg -L verwendet werden    

## dpkg
dpkg ist die Basis der Paketverwaltung des Betriebssystems Debian und das grundlegende Programm zum Installieren und Manipulieren von Debian-Binärpaketen.
Der Name dpkg ist eine Abkürzung für Debian Package. Das Debian-Software-Paket-Format wurde im Debian-Projekt entwickelt, allerdings wird dieses Paketformat und das Paketverwaltungsprogramm dpkg auch von anderen Software-Distributionen verwendet. Beispielsweise verwenden neben Debian auch das Fink-Projekt, welches Open-Source-Pakete für Mac OS X zur Verfügung stellt, und die OpenSolaris-Distribution Nexenta OS dpkg.


## atmega16 / C-Programm
Soll ein Programm für einen µC der Atmega Reihe geschrieben werden, muss das Programm mithilfe einer anderen Compiler Suite übersetzt werden. Dafür verwenden wir den AVR-GCC Kompiler.  
Die Befehle für die einzelnen Schritte sind im Prinzip die Selben. Statt _gcc_ starten die Befehle nun mit avr-gcc. Außerdem muss der Kompiler wissen, um welchen Atmega Prozessor es sich handelt und welche Taktfrequenc dieser hat.  
Der __Prozessortyp__ wird mit dem Attribut _-mmcu=type_ festgelegt, die __Taktfrequenz__ mit dem Attribut _-DF_CPU=frequencyL_ (L für Datentyp long). Außerdem kann man mit dem Attribut _-Os_ dafpr sorgen dass der __Speicherplatz__ optimal genutzt wird.  

Daten für die Atmega Prozessoren, die für unseren Laborunterricht relevant sind:  

Board | Sure Electronics DEM1 | Arduino NANO
----- | --------------------- | ------------
Prozessortyp | atmega16 | atmega328p
Frequenz | 12000000 | 16000000

Der schrittweise Kompiliervorgang bis zur main.elf, mithilfe der Shell, sieht dann wie folgt aus (verwendet wird der Arduino Nano):  
  1. __Preprozessor__: avr-gcc -Os -mmcu=atmega328p -DF_CPU=16000000L -E main.c  
  2. __Compiler__: avr-gcc -Os -mmcu=atmega328p -DF_CPU=16000000 -S main.c  
  3. __Assembler__: avr-gcc -Os -mmcu=atmega328p -DF_CPU=16000000 -c main.s  
  4. __Linker__: avr-gcc -Os -mmcu=atmega328p -DF_CPU=16000000 -o main.elf main.o

### Beispiel aus dem Unterricht:
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


###wichtige Ausschnitte

## Intelhex
Das Intel HEX-Format ist ein Datenformat zur Speicherung und Übertragung von binären Daten. Es wird heute hauptsächlich verwendet, um Programmierdaten für Mikrocontroller bzw. Mikroprozessoren, EPROMs und ähnliche Bausteine zu speichern. Es kann aber auch zur Speicherung von Lademodulen verwendet werden. Das HEX-Format ist das älteste Datenformat seiner Art und seit den 1970er Jahren in Gebrauch. Spätere Erweiterungen unterstützen speziell die segmentierte Adressierung der Intel-80x86-Prozessoren.

Eine Intel HEX-Datei liegt im ASCII-Format vor. Die Bytes der kodierten Binärdaten werden jeweils als Hexadezimalzahl aus zwei ASCII-Zeichen dargestellt. HEX-Dateien können mit einem Texteditor geöffnet und modifiziert werden. Die HEX-Datei ist in etwa doppelt so groß wie die enthaltenen Binärdaten, da die Darstellung eines Bytes mit zwei Bytes in hexadezimaler Schreibweise erfolgt. Die Datensätze sind mit einer Prüfsumme versehen, so dass Übertragungsfehler erkannt werden können.

| Typ | Bezeichnung | Verwendung |  
| --- | ----------- | ---------- |  
| 00 | Data Record | Nutzdaten |  
| 01 | End of File Record | Dateiende (sowie Startadresse bei 8-Bit-Daten) |  
| 02 | Extended Segment Address Record | Erweitere Segmentadresse für nachfolgende Nutzdaten |  
| 03 | Start Segment Address Record  | Startsegmentadresse |  
| 04 | Extended Linear Address Record | Erweiterte lineare Adresse, höherwertige 16 Bit der Adresse für nachfolgende Nutzdaten |  
| 05 | Start Linear Address Record | Lineare Startadresse |  

![Bild](https://camo.githubusercontent.com/f1d9bbfc7b436e45ab52150b7153f45e4c6399c7/68747470733a2f2f7261772e6769746875622e636f6d2f4d61726b44696e672f48544d4c355f554152545f424c2f6d61737465722f696d616765732f696d6167653033342e706e67)

## StartupCode
Der Compiler benötigt einen Startup-Code.
Er ist ein Bestandteil des Binearys, das
der C, Pascal  oder Basic - Compiler erstellt.
In ihm werden die Grundinitialisierungen des Prozessors ausgeführt,
etwa die Zeitgeber - Initialisierung, festlegen des Stackbereiches
und andere Dinge.

## Programmausführung
#### **`avr-gcc -mmcu=atmega16 -Os -S main.c` - Präprozessieren zum Preprozessorquelltext**  
*Ausschnitte:*  

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

#### **`avr-gcc -mmcu=atmega16 -Os main.o` - Programmausführung**

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


