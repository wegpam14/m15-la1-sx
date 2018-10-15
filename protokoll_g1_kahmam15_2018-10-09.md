# 1. Protokoll (09.10.2018)
Name: Kahr Markus  
Klasse: 4AHME  
KNr.: 6  
Gruppe: 1  

## Inhalte:  

* **1. Versionswerwaltung**  
* *1.1 Definition*
* *1.2 Systeme*
* **2. Git**
 * *2.1 Git-Befehle*  
 * *2.2. Markdown* 
* **3. Linux-Befehle**
  
### 1. Versionsverwaltung

#### 1.1 Definition

Eine [Versionsverwaltung] ist ein System,
das zur Erfassung von Änderungen an Dokumenten
oder Dateien verwendet wird.
Die Versionsverwaltung ist eine Form des Variantenmanagements;
dort sind verschiedene Sprachvarianten oder modal auch anders bestimmte Varianten möglich.

#### 1.2 Systeme

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

[Versionsverwaltung]: https://de.wikipedia.org/wiki/Versionsverwaltung
[Linus Torvalds]: https://de.wikipedia.org/wiki/Linus_Torvalds
[Markdown]: https://guides.github.com/features/mastering-markdown/
