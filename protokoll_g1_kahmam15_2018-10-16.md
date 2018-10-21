![HTBLA Kaindorf](https://upload.wikimedia.org/wikipedia/commons/thumb/3/30/HTL_Kaindorf_Logo.svg/1200px-HTL_Kaindorf_Logo.svg.png)

# 2. Protokoll (16.10.2018)
Name: Kahr Markus  
Klasse: 4AHME  
KNr.: 6  
Gruppe: 1  

## Inhalte:  

* **1. Übersetzungsvorgang in C**  
* *1.1 Sourcecode erstellen*
* *1.2 Konvertierung in Maschinen lesbares Programm*
* **2. Compiler**
 * *2.1 Versionen*  
 * *2.2. Arbeitsvorgang des GNU Compiler* 
* **3. Linux-Befehle**
  
### 1. Übersetzungsvorgang in C

#### 1.1 Sourcecode erstellen
  
  Zu Beginn eines Programms wird ein [Quelltext] benötigt (gewöhnliche Textdatei).
  In diesem Quelltext werden Programmieranweisungen geschrieben, welche den Aufgaben des Programms entsprechen.
  Durch Syntaxhervorhebung werden Teile des Quelltextes entsprechend ihrer Funktionalität farblich hervorgehoben, was die Lesbarkeit
  verbessert. Ebenfalls zur Verbesserung der Lesbarkeit halten sich Programmierer meist an eine bestimmte Quelltextformatierung
  (z. B. Einrückung von Unterabschnitten, Groß-/Kleinschreibung …). 

#### 1.2 Konvertierung in Maschinen lesbares Programm

* Präprozzesor (#include, #define, #...) - erzeugt einen präprozzesierten Quelltext  
* Compiler - übersetzt in Assembler (Maschinensprache)  
* Assembler - erzeugt aus der Assembler Quelltextdatei eine/n Objektdatei/Objectcode  
* Linker - übergibt die Adressen damit das Programm ausgeführt werden kann

### 2. Compiler

#### 2.1 Versionen





#### 2.2 Arbeitsvorgang des GNU Compiler

[Markdown] ist eine Möglichkeit, Text im Web zu formatieren. 
Es steuert die Anzeige eines Dokuments; Formatieren von Wörtern wie Fett oder Kursiv,
Hinzufügen von Bildern und Erstellen von Listen sind nur einige der Dinge, 
die man mit Markdown machen kann. Meistens ist Markdown nur normaler Text mit ein paar nicht-alphabetischen Zeichen wie # oder *.
Eine Markdown-Datei ist durch die Dateiendung **```.md```** oder **```.markdown```** gekennzeichnet.

### 3. Linux-Befehle

* **```whoami```** - Zeigt dir welcher Benutzer du bist
* **```pwd```** - Zeigt dir in welchem Verzeichniss du dich befindest
* **```man```** - Ruft das Manual/die Mainpages auf (z.B.: **```man 3 printf```**)
* **```mkdir <name>```** - Erstellt ein neues Verzeichniss
* **```history```** - Zeigt dir deine Befehls-History an  
* **```reset```** - Setzt die Shell zurück
* **```ls -l```** - Zeigt die Rechte auf die Dateien (Ersten 3 = Rechte der Eigentümer, Zweiten 3 = Rechte der Gruppen,  
Ersten 3 = Rechte aller Benutzer)  
* **```hexdump```** - Zeigt Bytes der Datei  
* **```hexdump -C```** - Zeigt Bytes der Datei mit Textinhalt  
* **```gcc```** - ..  
* **```./a.out```** - Führt Programm im Terminal aus  
* **```gcc -E```** - Reprozessiert die Datei  

[Quelltext]: https://de.wikipedia.org/wiki/Quelltext

