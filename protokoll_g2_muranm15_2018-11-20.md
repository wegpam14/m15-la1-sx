# Protokoll ![](https://www.koerbler.com/neuigkeiten/wp-content/uploads/2013/03/htl-kaindorf.jpg):copyright:
**von Anna Murko**  
Datum: 20.11.2018  
Gruppe: 2  
Betreuer: Professor Steiner  
abwesend: Skof Jonas 
  
  Thema: **Übersetzungsvorgang am yC**  
  Definition: *Beschreibt wie ein C-Quellcode für den yC in ein ausführbares Programm übersetzt wird.*  

## Inhalt 
**:point_right: __Compiliervorgang__**  
**:point_right: __Advanced Packaging Tool__**  
**:point_right: __           Kommandos__**  
**:point_right: __Debian Package__**   
**:point_right: __Atmega 16/ C-Programm__**   
**:point_right: __           Beispiel aus dem Unterrricht__**   
**:point_right: __           Terminalauszug__**   
**:point_right: __Intelhex__**   
**:point_right: __Startup-Code__**  
**:point_right: __Implizite Deklaration/explizite Deklaration
**:point_right: __Programmausführung__**   
**:point_right: __           Präprozessieren zum Präprozessorquelltext__**   
**:point_right: __           Kompilieren zum Assemblerquelltext__**   
**:point_right: __           Programmausführung__**   
 

## :point_right: __Compiliervorgang:__ 
Im ersten Schritt wird die Datei `main.c` zur Objektdatei `main.o` übersetzt. In diesem Vorgang werden vom *Preprozessor* alle Header-Dateien eingebunden. Beim *Compilen* wird der Quelltext dann in Assemblerbefehle übersetzt. Beim *Assemblieren* wird der Assemblerquelltext dann in binäre Maschinenbefehle übersetzt.

Im zweiten Schritt wird die Objektdatei `main.o` zur ausführbaren (*executable*) Datei `main.elf` übersetzt. Dieser Vorgang wird *Linken* genannt. Hier werden alle tatsächlichen Adressen eingetragen, wodurch das Programm ausgeführt werden kann.

Der dritte Schritt wird nur benötigt, wenn das System die `main.elf` nicht ausführen kann. Die Datei `main.elf` wird zur Hex-Datei `main.hex` übersetzt. Dieser Vorgang wird *Konvertieren* genannt.

## :point_right: __Advanced Packaging Tool:__ 
Das Advanced Packaging Tool ist ein Paketverwaltungssystem, das im Bereich des Betriebssystems Debian entstanden ist und dpkg zur eigentlichen Paketverwaltung benutzt. Ziel ist es, eine einfache Möglichkeit zur Suche, Installation und Aktualisierung von Programmpaketen zur Verfügung zu stellen.  
APT besteht aus einer Programmbibliothek und mehreren diese Bibliothek nutzenden Kommandozeilen-Programmen.  

In der Datei /etc/apt/sources.list stehen die sogenannten Repositories, also Quellen für Pakete. Dies können entweder CDs oder DVDs, Verzeichnisse auf der Festplatte oder Verzeichnisse auf HTTP- oder FTP-Servern sein. Befindet sich das gesuchte Paket auf einem Server, so wird dieses automatisch heruntergeladen und installiert.
Die Pakete liegen im Debian-Paketformat vor, in dem auch die jeweiligen Abhängigkeiten der Programmpakete untereinander abgelegt sind. So werden automatisch für ein Programm auch eventuell erforderliche Programmbibliotheken mit heruntergeladen und installiert.
APT setzt auf dpkg auf. APT beschäftigt sich in erster Linie mit der Beschaffung von Paketen, dem Vergleich von verfügbaren Versionen der Pakete und der Verwaltung von Paket-Archiven.

### :point_right: __Kommandos:__ 
.)apt-get install paketname installiert ein Paket und sämtliche Abhängigkeiten und in der Standardeinstellung zusätzlich empfohlene Pakete.  
.)apt-get remove paketname entfernt ein vorhandenes Paket und die Pakete, die von diesem abhängen. Abhängigkeiten dieser Pakete oder Konfigurationsdateien werden jedoch nicht entfernt.  
.)apt-get --purge remove paketname entfernt ein Paket und die Konfigurationsdateien.  
.)apt-get upgrade bringt, sofern möglich, alle Pakete auf den neuesten Stand, installiert jedoch keine neuen Pakete (was evtl. nötig ist, um das System aktuell zu halten, falls sich Abhängigkeiten geändert haben)  
.)apt-get dist-upgrade bringt alle Pakete auf den neuesten Stand und installiert bei Bedarf neue Pakete oder entfernt Pakete, die mit den zu installierenden Paketen in Konflikt stehen.  
.)apt-get update holt die neuesten Informationen über Pakete vom Debian-Server.  
.)apt-get source paketname holt den Quelltext des Paketes vom Debian-Server in das aktuelle Verzeichnis.  
.)apt-cache search suchwort sucht nach Programmen.  
.)zum Finden von Programmen oder Dateien in noch nicht installierten Paketen kann das separate Tool apt-file oder auch dpkg -L verwendet werden    

## :point_right: __Debian Package:__ 
dpkg ist die Basis der Paketverwaltung des Betriebssystems Debian und das grundlegende Programm zum Installieren und Manipulieren von Debian-Binärpaketen.
Der Name dpkg ist eine Abkürzung für Debian Package. Das Debian-Software-Paket-Format wurde im Debian-Projekt entwickelt, allerdings wird dieses Paketformat und das Paketverwaltungsprogramm dpkg auch von anderen Software-Distributionen verwendet. Beispielsweise verwenden neben Debian auch das Fink-Projekt, welches Open-Source-Pakete für Mac OS X zur Verfügung stellt, und die OpenSolaris-Distribution Nexenta OS dpkg.


## :point_right: __Atmega16 / C-Programm:__ 
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

### :point_right: __Beispiel aus dem Unterricht:__ 
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


### :point_right: __Terminalauszug:__ :
```C
anna@anna-VirtualBox:~$ mkdir ueneu
anna@anna-VirtualBox:~$ cd ueneu
anna@anna-VirtualBox:~/ueneu$
anna@anna-VirtualBox:~/ueneu$ nano main.c
anna@anna-VirtualBox:~/ueneu$ cat main.c
int main() {
printf("Guten Morgen\n");
return 0;
}

anna@anna-VirtualBox:~/ueneu$
anna@anna-VirtualBox:~/ueneu$ nano main.c
anna@anna-VirtualBox:~/ueneu$ avr-gcc --version
avr-gcc (GCC) 5.4.0
Copyright (C) 2015 Free Software Foundation, Inc.
Dies ist freie Software; die Kopierbedingungen stehen in den Quellen. Es
gibt KEINE Garantie; auch nicht für MARKTGÄNGIGKEIT oder FÜR SPEZIELLE ZWECKE.

anna@anna-VirtualBox:~/ueneu$ less /etc/apt/sources.list
anna@anna-VirtualBox:~/ueneu$ ll
insgesamt 12
drwxr-xr-x  2 anna anna 4096 Nov 20 08:39 ./
drwxr-xr-x 24 anna anna 4096 Nov 20 08:32 ../
-rw-r--r--  1 anna anna  134 Nov 20 08:39 main.c
anna@anna-VirtualBox:~/ueneu$ ll ^C
anna@anna-VirtualBox:~/ueneu$ less /etc/apt/sources.list.d
/etc/apt/sources.list.d is a directory
anna@anna-VirtualBox:~/ueneu$ apt update
Paketlisten werden gelesen... Fertig
...
anna@anna-VirtualBox:~/ueneu$ sudo -i

[sudo] Passwort für anna:
root@anna-VirtualBox:~# apt update
Fehl:1 http://www.geogebra.net/linux stable InRelease
  »www.geogebra.net« konnte nicht aufgelöst werden.
...

root@anna-VirtualBox:~# apt upgrade
Paketlisten werden gelesen... Fertig
...
Abbruch.

root@anna-VirtualBox:~# exit
Abgemeldet

anna@anna-VirtualBox:~/ueneu$ dpkg --list | wc -l
1895
anna@anna-VirtualBox:~/ueneu$ ll
insgesamt 12
drwxr-xr-x  2 anna anna 4096 Nov 20 08:39 ./
drwxr-xr-x 24 anna anna 4096 Nov 20 08:32 ../
-rw-r--r--  1 anna anna  134 Nov 20 08:39 main.c
anna@anna-VirtualBox:~/ueneu$ avr-gcc --versionb
avr-gcc: Fehler: unbekannte Kommandozeilenoption »--versionb«

anna@anna-VirtualBox:~/ueneu$ lsb_release -a
No LSB modules are available.
Distributor ID:	Ubuntu
...

anna@anna-VirtualBox:~/ueneu$ avr-gcc main.c
In file included from main.c:1:0:
/usr/lib/avr/include/avr/io.h:623:6: Warnung: #warning "device type not defined" [-Wcpp]
 #    warning "device type not defined"
      ^
main.c: In Funktion »main«:
main.c:5:5: Fehler: »DDRA« nicht deklariert (erste Verwendung in dieser Funktion)
     DDRA = 0x01;
     ^
main.c:5:5: Anmerkung: jeder nicht deklarierte Bezeichner wird nur einmal für jede Funktion, in der er vorkommt, gemeldet
main.c:7:8: Fehler: »PORT« nicht deklariert (erste Verwendung in dieser Funktion)
        PORT ^=0x01;
        ^
main.c:8:8: Warnung: Implizite Deklaration der Funktion »_delay_ms« [-Wimplicit-function-declaration]
        _delay_ms(300);
        ^
anna@anna-VirtualBox:~/ueneu$ nano main.c
anna@anna-VirtualBox:~/ueneu$ avr-gcc main.c
In file included from main.c:1:0:
/usr/lib/avr/include/avr/io.h:623:6: Warnung: #warning "device type not defined" [-Wcpp]
 #    warning "device type not defined"
      ^
In file included from main.c:2:0:
/usr/lib/avr/include/util/delay.h:92:3: Warnung: #warning "F_CPU not defined for <util/delay.h>" [-Wcpp]
 # warning "F_CPU not defined for <util/delay.h>"
   ^
/usr/lib/avr/include/util/delay.h:112:3: Warnung: #warning "Compiler optimizations disabled; functions from <util/delay.h> won't work as designed" [-Wcpp]
 # warning "Compiler optimizations disabled; functions from <util/delay.h> won't work as designed"
   ^
main.c: In Funktion »main«:
main.c:6:5: Fehler: »DDRA« nicht deklariert (erste Verwendung in dieser Funktion)
     DDRA = 0x01;
     ^
main.c:6:5: Anmerkung: jeder nicht deklarierte Bezeichner wird nur einmal für jede Funktion, in der er vorkommt, gemeldet
main.c:8:8: Fehler: »PORT« nicht deklariert (erste Verwendung in dieser Funktion)
        PORT ^=0x01;
        ^
anna@anna-VirtualBox:~/ueneu$ nano main.c
anna@anna-VirtualBox:~/ueneu$ man avr-gcc
Kein Handbucheintrag für avr-gcc vorhanden
Siehe auch »man 7 undocumented« für Hilfe, wenn Handbuchseiten nicht verfügbar sind.
anna@anna-VirtualBox:~/ueneu$ avr-gcc --help
....
anna@anna-VirtualBox:~/ueneu$ avr-gcc --help | less -S
anna@anna-VirtualBox:~/ueneu$ avr-gcc --target-help | less -S
anna@anna-VirtualBox:~/ueneu$
anna@anna-VirtualBox:~/ueneu$ avr-gcc -mmcu=atmega16 main.c
In file included from main.c:2:0:
/usr/lib/avr/include/util/delay.h:92:3: Warnung: #warning "F_CPU not defined for <util/delay.h>" [-Wcpp]
 # warning "F_CPU not defined for <util/delay.h>"
   ^
/usr/lib/avr/include/util/delay.h:112:3: Warnung: #warning "Compiler optimizations disabled; functions from <util/delay.h> won't work as designed" [-Wcpp]
 # warning "Compiler optimizations disabled; functions from <util/delay.h> won't work as designed"
   ^
main.c: In Funktion »main«:
main.c:8:8: Fehler: »PORT« nicht deklariert (erste Verwendung in dieser Funktion)
        PORT ^=0x01;
        ^
main.c:8:8: Anmerkung: jeder nicht deklarierte Bezeichner wird nur einmal für jede Funktion, in der er vorkommt, gemeldet
anna@anna-VirtualBox:~/ueneu$ avr-gxx -mcu=atmega16 main.c
avr-gxx: Befehl nicht gefunden.
anna@anna-VirtualBox:~/ueneu$ avr-gcc -mcu=atmega16 main.c
avr-gcc: Fehler: unbekannte Kommandozeilenoption »-mcu=atmega16«
anna@anna-VirtualBox:~/ueneu$ avr-gcc -mmcu=atmega16 main.c
In file included from main.c:2:0:
/usr/lib/avr/include/util/delay.h:92:3: Warnung: #warning "F_CPU not defined for <util/delay.h>" [-Wcpp]
 # warning "F_CPU not defined for <util/delay.h>"
   ^
/usr/lib/avr/include/util/delay.h:112:3: Warnung: #warning "Compiler optimizations disabled; functions from <util/delay.h> won't work as designed" [-Wcpp]
 # warning "Compiler optimizations disabled; functions from <util/delay.h> won't work as designed"
   ^
main.c: In Funktion »main«:
main.c:8:8: Fehler: »PORT« nicht deklariert (erste Verwendung in dieser Funktion)
        PORT ^=0x01;
        ^
main.c:8:8: Anmerkung: jeder nicht deklarierte Bezeichner wird nur einmal für jede Funktion, in der er vorkommt, gemeldet
anna@anna-VirtualBox:~/ueneu$ avr-gcc -mmcu=atmega16 -Os main.c
In file included from main.c:2:0:
/usr/lib/avr/include/util/delay.h:92:3: Warnung: #warning "F_CPU not defined for <util/delay.h>" [-Wcpp]
 # warning "F_CPU not defined for <util/delay.h>"
   ^
main.c: In Funktion »main«:
main.c:8:8: Fehler: »PORT« nicht deklariert (erste Verwendung in dieser Funktion)
        PORT ^=0x01;
        ^
main.c:8:8: Anmerkung: jeder nicht deklarierte Bezeichner wird nur einmal für jede Funktion, in der er vorkommt, gemeldet
anna@anna-VirtualBox:~/ueneu$ nano main.c
anna@anna-VirtualBox:~/ueneu$ LL
LL: Befehl nicht gefunden.
anna@anna-VirtualBox:~/ueneu$ ll
insgesamt 12
drwxr-xr-x  2 anna anna 4096 Nov 20 09:38 ./
drwxr-xr-x 24 anna anna 4096 Nov 20 08:32 ../
-rw-r--r--  1 anna anna  182 Nov 20 09:38 main.c
anna@anna-VirtualBox:~/ueneu$ avr-gcc -mmcu=atmega16 -Os main.c
main.c: In Funktion »main«:
main.c:9:8: Fehler: »PORT« nicht deklariert (erste Verwendung in dieser Funktion)
        PORT ^=0x01;
        ^
main.c:9:8: Anmerkung: jeder nicht deklarierte Bezeichner wird nur einmal für jede Funktion, in der er vorkommt, gemeldet
anna@anna-VirtualBox:~/ueneu$ nano main.c
anna@anna-VirtualBox:~/ueneu$ nano main.x
anna@anna-VirtualBox:~/ueneu$ avr-gcc -mmcu=atmega16 -Os main.c
anna@anna-VirtualBox:~/ueneu$ ll
insgesamt 20
drwxr-xr-x  2 anna anna 4096 Nov 20 09:41 ./
drwxr-xr-x 24 anna anna 4096 Nov 20 08:32 ../
-rwxr-xr-x  1 anna anna 5748 Nov 20 09:41 a.out*
-rw-r--r--  1 anna anna  183 Nov 20 09:40 main.c
anna@anna-VirtualBox:~/ueneu$ avr-objcopy --help | less -S
anna@anna-VirtualBox:~/ueneu$ avr-objcopy -0 ihex a.out a.hex
...
anna@anna-VirtualBox:~/ueneu$ avr-objcopy -O  ihex a.out a.hex
anna@anna-VirtualBox:~/ueneu$ less a.hex
anna@anna-VirtualBox:~/ueneu$ avr-gcc ^C
anna@anna-VirtualBox:~/ueneu$ avr-gcc -mmcu=atmega16 -Os -E main.c | less -S
anna@anna-VirtualBox:~/ueneu$ avr-gcc -mmcu=atmega16 -Os -S main.c
anna@anna-VirtualBox:~/ueneu$ ll
insgesamt 60
drwxr-xr-x  2 anna anna  4096 Nov 20 10:20  ./
....
-rw-rw-r--  1 anna anna 27779 Nov 20 10:01 'Unbenannt 1.odt'
anna@anna-VirtualBox:~/ueneu$ avr-objdump -d main.o

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
anna@anna-VirtualBox:~/ueneu$ avr-gcc -mmcu=atmega16 -Os main.o

anna@anna-VirtualBox:~/ueneu$ avr-objdump -d a.out
a.out:     Dateiformat elf32-avr
...
0000008e <__stop_program>:
  8e:	ff cf       	rjmp	.-2      	; 0x8e <__stop_program>
anna@anna-VirtualBox:~/ueneu$
anna@anna-VirtualBox:~/ueneu$ ll
insgesamt 64
drwxr-xr-x  2 anna anna  4096 Nov 20 10:23  ./
drwxr-xr-x 29 anna anna  4096 Nov 20 10:06  ../
-rw-r--r--  1 anna anna   418 Nov 20 09:54  a.hex
-rwxr-xr-x  1 anna anna  5748 Nov 20 10:23  a.out*
-rw-rw-r--  1 anna anna    79 Nov 20 10:01 '.~lock.Unbenannt 1.odt#'
-rw-r--r--  1 anna anna   183 Nov 20 09:40  main.c
-rw-r--r--  1 anna anna   888 Nov 20 10:21  main.o
-rw-r--r--  1 anna anna   537 Nov 20 10:20  main.s
-rw-rw-r--  1 anna anna 27779 Nov 20 10:01 'Unbenannt 1.odt'

```

## :point_right: __Intelhex:__ 
Das Intel HEX-Format ist ein Datenformat zur Speicherung und Übertragung von binären Daten. Es wird heute hauptsächlich verwendet, um Programmierdaten für Mikrocontroller bzw. Mikroprozessoren, EPROMs und ähnliche Bausteine zu speichern. Es kann aber auch zur Speicherung von Lademodulen verwendet werden. Das HEX-Format ist das älteste Datenformat seiner Art und seit den 1970er Jahren in Gebrauch. Spätere Erweiterungen unterstützen speziell die segmentierte Adressierung der Intel-80x86-Prozessoren.

Eine Intel HEX-Datei liegt im ASCII-Format vor. Die Bytes der kodierten Binärdaten werden jeweils als Hexadezimalzahl aus zwei ASCII-Zeichen dargestellt. HEX-Dateien können mit einem Texteditor geöffnet und modifiziert werden. Die HEX-Datei ist in etwa doppelt so groß wie die enthaltenen Binärdaten, da die Darstellung eines Bytes mit zwei Bytes in hexadezimaler Schreibweise erfolgt. Die Datensätze sind mit einer Prüfsumme versehen, so dass Übertragungsfehler erkannt werden können.

Es gibt 6 Datensatztypen:  

| Typ | Bezeichnung | Verwendung |  
| --- | ----------- | ---------- |  
| 00 | Data Record | Nutzdaten |  
| 01 | End of File Record | Dateiende (sowie Startadresse bei 8-Bit-Daten) |  
| 02 | Extended Segment Address Record | Erweitere Segmentadresse für nachfolgende Nutzdaten |  
| 03 | Start Segment Address Record  | Startsegmentadresse |  
| 04 | Extended Linear Address Record | Erweiterte lineare Adresse, höherwertige 16 Bit der Adresse für nachfolgende Nutzdaten |  
| 05 | Start Linear Address Record | Lineare Startadresse |  

![Bild](https://camo.githubusercontent.com/f1d9bbfc7b436e45ab52150b7153f45e4c6399c7/68747470733a2f2f7261772e6769746875622e636f6d2f4d61726b44696e672f48544d4c355f554152545f424c2f6d61737465722f696d616765732f696d6167653033342e706e67)

## :point_right: __StartupCode:__ 
Der Compiler benötigt einen Startup-Code.
Er ist ein Bestandteil des Binearys, das
der C, Pascal  oder Basic - Compiler erstellt.
In ihm werden die Grundinitialisierungen des Prozessors ausgeführt,
etwa die Zeitgeber - Initialisierung, festlegen des Stackbereiches
und andere Dinge.

## :point_right: __Implizite Deklaration/explizite Deklaration__
Neben der expliziten Deklaration gibt es in einigen Programmiersprachen auch die Möglichkeit einer impliziten Deklaration von Variablen: In diesem Fall führt das erste Auftreten einer Variablen zu einer automatischen Typzuordnung.

## :point_right: __Programmausführung:__ 
:zap: mögliche Probleme: Programm könnte nicht ausgeführt werden, weil Befehlstypen ähnlich sind, Befehlsmuster aber anders und dadurch nur für den Prozessor geeignet, für den es geschrieben wurde. `a out <elf-Datei>`

### :point_right: __Präprozessieren zum Preprozessorquelltext:__ . ** - `avr-gcc -mmcu=atmega16 -Os -S main.c`   

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

#### ** :point_right: __Kompilieren zum Assemblerquelltext:__ -  `avr-gcc -mmcu=atmega16 -Os -c main.s`      

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

#### ** :point_right: __Programmausführung:__ - `avr-gcc -mmcu=atmega16 -Os main.o` 

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

