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

Beispiel aus dem Unterricht:


###wichtige Ausschnitte

## Intelhex
## StartuoCode
## Programmausführung

