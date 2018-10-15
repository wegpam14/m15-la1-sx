# Protokoll1 (08.10.2018)

Name: Breitenthaler Lorenz  
Klasse: 4ahme  
KNR: 1  
Gruppe: 1

--- 

## Inhalte

**1. Versionsverwaltung**  
**2. GitHub**  
    *2.1. Markdown*  
    *2.2. Erstellen einer Repository*  
**3. Umgang it dem Linux terminal**  
    *3.1. Linux Terminal*  
    *3.2. Git spezifische Befehle*  

--- 

## 1.Versionsverwaltung

*Definition*:
Bei der Versionsverwaltung wird bei jeder Änderung eines Programms, oder ähnlichem, ein "Backup" (Sogenannten "commits") erstellt. Auf diese kann jeder Zeit zurückgesprungen werden falls bei Änderungen ein grober Fehler unterlief oder eine ältere Version des Programms verlangt wird.

*Produckte*: Git, CVS, SVN, Mecury;

Git ist heutzutage das meist verwendetste System.

*Geschichte:*
[Linus Thorwald](https://de.wikipedia.org/wiki/Linus_Torvalds) war mit seinem damaligem System nicht zufrieden, da es keine offline Arbeit, welch er bei verschiedensten Geschäftsreisen im Flugzeug allerdings benötigte, zuließ. Also entwickelte er Git so weiter, dass eine zusätzliche lokale Repository erstellt wurde, mit welcher er offline arbeiten konnte. Bei wieder verbindung mit dem Internet konnte er dann seine  Änderungen auf die Remote Repository wieder hochladen.

## 2.Github

[GitHub](https://github.com) ist einer der größten remote repository anbieter weltweit.Allerdings werden nur Öffentliche Repositorys kostenlos zur verfügung gestellt.

### 2.1 Markdown

[Markdown](https://de.wikipedia.org/wiki/Markdown) ist eine vereinfachte Auszeichnungssprache, welche es sich zum Ziel gesetzt hat, dass schon die Ausgangsform ohne weitere Konvertierung leicht lesbar ist.

Zur leichteren Bedienung kann man das Sogenannte [Cheatsheet](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet) verwenden in welchem alle abkürzungen aufgelistet sind.

### 2.2. Erstellen einer Repository

Um eine neue Repository zu erstellen muss man auf der GitHub Homepage einfach nur auf "Neue Repository erstellen" drücken. Hierbei hat man ein paar Optionen zur Verfügung. Als erstes kann man wählen ob man eine public oder private Repository erwünscht. Anschließend kann man eine "README.me" Datei erstellen lassen um sein Projekt zu beschreiben. Zum Abschluss kann man noch eine "LICENCE" hinzufügen um sich rechtlich abzusichern und eine ".gitignore" Datei erstellen mit welcher nicht relevante Dateien von der Remote-Repository ignoriert werden. 

In unserem Übungsbeispiel habe wir ein öffentliches Projekt mit einer README.md Datei, einer einfachen LICENCE und einer auf C-Programme zugeschnittenen .gitignore Datei erstellt. 

## 3.1 Umgang mit dem Linux Terminal

### 3. Linux befehle

`cd <Directory>` --> Springt im Terminal zu dem angegebenem Verzeichnis  
`ls -a -l` --> Listet Verzeichnisse oder Dateien im Terminal auf. Die Option -a zeigt auch versteckte Verzeichnisse und die  
           	 Option -l gibt die Verzeichnisse und Dateien in einer formatierten Liste aus.  

### 3.2 Git spezifische Befehle

`git clone <domain der Repository>` --> Clont die Remote-Repository vom Server auf den Privatrechner  
`git pull` --> aktualisiert die lokale repository mit der remote repository  
`git add <Hinzuzufügende Datei>` --> Fügt die Änderungen din den Index ein  
`git commit -m "Commit Nachricht"` --> Verschiebt die Veränderungen mit der zusäzlich angegebenen Nachricht in die Lokale -Repository.  
`git push` --> Lädt alle commits aus der Lokalen Repository in die Remote-Repository.
