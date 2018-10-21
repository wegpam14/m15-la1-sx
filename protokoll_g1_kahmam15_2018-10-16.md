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
 * *2.2. Arbeitsvorgang GNU Compiler* 
* **3. Linux-Befehle**
  
### 1. Übersetzungsvorgang in C

#### 1.1 Sourcecode erstellen
  
  Zu Beginn eines Programms wird ein [Quelltext] benötigt (gewöhnliche Textdatei).
  In diesem Quelltext werden Programmieranweisungen geschrieben, welche den Aufgaben des Programms entsprechen.
   

#### 1.2 Konvertierung in Maschinen lesbares Programm

Vor dem Git-System gab es auch einige andere **VCS (Version Control Systems)** ,
jedoch hat sich Git, entwickelt von [Linus Torvalds], stark durchgesetzt da er mit diesem
System ein großes Problem behob. Er fügte zwischen dem lokalen Verzeichnis und dem remote repository
ein lokales repository hinzu. Somit gab es keine weiteren Probleme beim sichern der Daten ohne Internetverbindung.

### 2. Git

#### 2.1 Git-Befehle

**git add** - fügt Dateien zum Index hinzu  
**git commit** - schreibt die Datei aus dem Index in das lokale Repository  
**git push** - schreibt die Datei aus dem lokalen Repository in das remote Repository  
**git status** - zeigt den aktuellen Zustand der Datei im lokalen Repository


#### 2.2 Markdown

[Markdown] ist eine Möglichkeit, Text im Web zu formatieren. 
Es steuert die Anzeige eines Dokuments; Formatieren von Wörtern wie Fett oder Kursiv,
Hinzufügen von Bildern und Erstellen von Listen sind nur einige der Dinge, 
die man mit Markdown machen kann. Meistens ist Markdown nur normaler Text mit ein paar nicht-alphabetischen Zeichen wie # oder *.
Eine Markdown-Datei ist durch die Dateiendung **```.md```** oder **```.markdown```** gekennzeichnet.

### 3. Linux-Befehle

* **```cd```** - Pfad wechseln
* **```ls```** - Liste aller Dateien im aktuellen Verzeichnis
* **```ls -a```** - listet auch verdeckte Dateien (z.B.: .gitignore)
* **```ls -la```** - zeigt weitere Informationen aus der Liste
* **```ll```** - Codewort für **```ls -la```** in Ubuntu

[Quelltext]: https://de.wikipedia.org/wiki/Quelltext
[Linus Torvalds]: https://de.wikipedia.org/wiki/Linus_Torvalds
[Markdown]: https://guides.github.com/features/mastering-markdown/
