# Protokoll
## Protokoll 1 - 18.9.2018

### Versionsverwaltung

* kommezielle Systeme
* freie Systeme
  * Git (SUN, CVS, ...) -> von Linus Torfals
  
Git ist eine freie Software zur Versionsverwaltung von Dateien.
Die wesentlichen Unterschiede zu Subversion (SVN)
* Repositories werden lokal gespeichert
* Die Versionsverwaltung ist auch offline verfügbar
* Abgleich des lokalen Repository mit einem zentralen Repository möglich
* Versionskennung erfolgt über SHA-1 Hashes anstatt von Versionsnummern
* Es werden nicht einzelne Datei versioniert sondern Datei- bzw. Verzeichnis-Snapshots

(Zeile 9 bis 15 stammt aus dem LMS Kurs LA)
 
 ![Versionsverwaltung](https://www.linux-user.de/ausgabe/2006/10/084-svn/prinzip.png)
 
 ### Installation von VirtualBox
 
Zu Beginn der Stunde installierten wir (die, die es zuhause noch nicht getan hatten) "VirtualBox" um Linux auf unseren Rechnern laufen lassen zu können.  
Zunächt führten wir ein Systemupdate durch:
* Mit dem Befehl **sudo -i** wurden wir zum "Superuser"
* **apt update** -> Neueinlesen der Paketlisten
* **apt dist-upgrade** -> Installierte Pakete wenn möglich auf verbesserte Version aktualisieren + Pakete installieren bzw. entfernen
* **apt install htl** -> HTL-Pakte installieren

### Mastering Markdown

Markdown ist eine sehr einfache Art und Weise um Texte für die GitHub Plattform zu formatieren.  

[Mastering Markdown](https://guides.github.com/features/mastering-markdown/)

Dort findet man die wichtigsten Befehle um zb. Wörter fett oder kursiv zu schreiben, Bilder und Links einzufügen, eine Tabelle oder Auflistung zu erstellen, Syntax highlighting durchzuführen oder Emojis hinzuzufügen.
