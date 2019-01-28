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
