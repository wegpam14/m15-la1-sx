![HTBLA Kaindorf](https://upload.wikimedia.org/wikipedia/commons/thumb/3/30/HTL_Kaindorf_Logo.svg/1200px-HTL_Kaindorf_Logo.svg.png)
# 4. Protokoll (08.01.2019)
Name: Kahr Markus  
Klasse: 4AHME  
KNr.: 6  
Gruppe: 1  
___

## Inhalte:  

* **1. Übersetzungsvorgang in C**  
  * *1.1 Sourcecode erstellen*
  * *1.2 Konvertierung in Maschinen lesbares Programm*
* **2. GNU-Projekt**
* **3. Makefile**
   * *2.1 mega AVR μC Speicher*  
* **3. Atmel Studio**
* **4. Assembler-Befehle**

 
___
  
### 1. Übersetzungsvorgang in C

  
![Uebersetzungsvorgang](http://fbmathe.bbs-bingen.de/Informatik/C_plusplus/Uebersetzungsvorgang__c++.jpg)  

#### 1.1 Sourcecode erstellen
  
  Zu Beginn eines Programms wird ein [Quelltext] benötigt (gewöhnliche Textdatei).
  In diesem Quelltext werden Programmieranweisungen geschrieben, welche den Aufgaben des Programms entsprechen.
  Durch Syntaxhervorhebung werden Teile des Quelltextes entsprechend ihrer Funktionalität farblich hervorgehoben, was die Lesbarkeit
  verbessert. Ebenfalls zur Verbesserung der Lesbarkeit halten sich Programmierer meist an eine bestimmte Quelltextformatierung
  (z. B. Einrückung von Unterabschnitten, Groß-/Kleinschreibung …). 

#### 1.2 Konvertierung in Maschinen lesbares Programm

* [Präprozessor]:   
Präprozessorbefehle beginnen mit immer mit einem "#" und enden nicht mit einemSemikolon (#include <stdio.h>, #define ...). Präprozessordateien werden "Header-Dateien" (* .h) gennant, da sie im Kopf der C-Datei stehen.  
  
**Unterschied zwischen "" und <> bei dem #include:**  
  
-Wenn die Variante mit den Anführungszeichen gewählt wird, sucht der Preprozessor die angegebene Datei zuerst im Verzeichnis der Quelldatei. Kann er die betreffende Datei dort nicht finden, dann durchsucht er anschließend all jene Verzeichnisse, die er normalerweise bei der #include-Anweisung mit spitzen Klammern berücksichtigt. Anführungszeichen um den Dateinamen finden im allgemeinen dann Verwendung, wenn Header-Dateien einzufügen sind, die der Programmierer selbst erstellt hat.  
  
-Hingegen sollten Sie den Dateinamen in spitze Klammern setzen, wenn Sie sich auf Header-Dateien der Standardbibliothek beziehen. In diesem Fall erfolgt die Suche in extra angegebenen include-Verzeichnissen. Die Liste der Verzeichnisse, die dabei berücksichtigt werden, muß entweder über ein Optionsmenü bekanntgegeben werden, sofern eine integrierte Entwicklungsumgebung vorliegt, oder in Form einer Umgebungsvariable verfügbar sein. Die Kommandozeilen-Versionen von C-Compilern erwarten die Angaben über include-Verzeichnisse meist in Form eines Arguments.

* [Compiler]:  
Der Compiler verarbeitet die Quelltextdatei in eine maschinenlesbare Sprache (Assembler).  
Befehle für den Compiler sind:  
**``gcc -c``** - Erzeugt eine Objektdatei, auch Objectcode genannt -> **``main.o``**  
**```gcc -S```** - Codiert die Datei in einen Assembler-Quelltext -> **``main.s``**  
**``gcc -E``** -Reprozessiert die Datei -> **``main.s``**  
  
* [Assembler]:  
Der Assembler erzeugt aus der Assembler Quelltextdatei eine/n Objektdatei/Objectcode  
  
* [Linker]:  
Übergibt die Adressen und es ergibt sich schlussendlich ein ausführbares Programm.  


#### 2. [GNU-Projekt]


___

### 2. 2. GNU-Projek

#### 2.1 [mega AVR] μC Speicher ([ATmega328P])

* [Flash] (Segmente werden angesprochen)
  * [Floating-Gate-Transistor] um den [Tunneleffekt] zu verwenden  
  ![FGT](https://upload.wikimedia.org/wikipedia/commons/thumb/a/a9/FGMOS_Symbol.svg/330px-FGMOS_Symbol.svg.png)
*  [EE-PROM](Einzelne Bits werden angesprochen)
*  [SRAM](Flüchtiger Speicher)
___
### 3. Atmel Studio

[Atmel Studio 7] ist eine integrierte Entwicklungsplattform (IDP) für die Entwicklung und das Debugging aller AVR®- und SAM-Mikrocontroller-Anwendungen. In unserer Laboreinheit haben wir einen ATmega328P mit folgenden Programm simuliert:  
```C
#include <avr/io.h>

int main(void)
{

 volatile unsigned char a = 0x10;
 volatile unsigned char b = 0x20;  
	
 return a + b;
}
```

___
### 4. [Assembler-Befehle]


* **```CLR <R>```** - Alle Werte im Register werden auf 0 gesetzt
* **```OUT <A,R>```** - Speichert Daten in das I/O-Register
* **```IN <R,A>```** - Holt Daten aus dem I/O-Register
* **```SER <R>```** - Alle Werte im Register werden auf 1 gesetzt
* **```LDI <R,K>```** - Ladet eine 8 Bit Konstante in das Register
* **```RCALL <k>```** - Speichert in den Stack
* **```RET```** - Holt Wert aus dem Stack und speichert diesen im Programm Counter
* **```CLI```** - Löscht das I-Flag
* **```RJMP <k>```** -  Springt in eine Adresse (z.B.: **```RJMP PC-0x0000```** => Endlose Schleife)
* **```PUSH <R>```** - Speichert das Register in den Stack
* **```POP <R>```** - Gibt Variable aus dem Stack frei  
* **```STD```** - Speichert Daten aus den Registern **X**, **Y** oder **Z**
* **```LDD```** - Holt Daten aus den Registern **Y** oder **Z**
* **```LDS <R,k>```** - Holt Daten aus dem SRAM
* **```ADC <R>```** - Addiert mit C-Flag
* **```ADD <R>```** - Addiert ohne C-Flag
* **```MOV <R,R>```** - Kopiert in ein Register (Source-Register unverändert)
* **```CPI <R,K>```** - Vergleicht ein Register mit einer Konstanten
* **```STS <k,R>```** - Speichert direkt Daten aus einem Register
* **```BRNE <R>```** - Spingt wenn kein Z-Flag gesetzt is (else)


[Präprozessor]: https://de.wikipedia.org/wiki/C-Pr%C3%A4prozessor
[Compiler]: https://de.wikipedia.org/wiki/Compiler
[Assembler]: https://de.wikipedia.org/wiki/Assembler_(Informatik)
[Linker]: https://de.wikipedia.org/wiki/Linker_(Computerprogramm)
[GNU-Projekt]: https://de.wikipedia.org/wiki/GNU-Projekt
