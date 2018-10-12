# Protokoll1 (08.10.2018)

Name: Breitenthaler Lorenz
Klasse: 4ahme
KNR: 1 
Gruppe: 1

--- 

## Inhalte

1. Versionenverwaltung
2. GitHub
3. Umgang it dem Linux terminal

--- 

## 1.Versionsverwaltung

*Deffinition*:
Bei der Versionsverwaltung wird bei jeder Änderung eines Programms, oder ähnlichem,ein "Backup" (Sogenannten "commits") erstellt. Auf diese kann jeder Zeit zurückgespurungen werden falls bei Änderungen ein grober Fehler unterlief oder eineältere Version des Programms verlangt wird.

*Produckte*:Git, CVS, SVN, Mecury;

Git ist Heutzutage das meist verwendetste System.

*Geschichte:*
Linus Thorwald (hir link einfügen) war mit seinem dahrmaligem system nicht zufrieden,da es keine offline arbeit, welch er bei verschiedensten Geschäftsreisen im Flugzeeug allerdings benötigte, zuließ. Also entwickelte er Git so weiter, dass eine zusätzlichee lokale Repository erstellt wurde, mit welcher er offline arbeiten konnte. Bei wieder verbindung mit dem Internet konnte er dann seine  Änderungen auf die Remote Repository wieder hochladen.

## 2.Github

GitHub (hir link einfügen) ist einer der größten remote repository anbieter weltweit.Allerdings werden nur Öffentliche Repositorys kostenlos zur verfügung gestellt.

### 2.1 Markdown

Markdown (Hir link einfügen) ist eine vereinfachte Auszeichnungssprache, welche es sich zum Ziel gesetzt hat, dass schon die Ausgangsform ohne weitere Konvertierung leicht lesbar ist.

Zur leichteren Bedienung kann man das Sogenannte Cheatsheet verwenden in welchem alle abkürzungen aufgelistet sind.


## 3.1 Umgang mit dem Linux Terminal

### Linux befehle

cd <Directory> --> Springt im Terminal zu dem angegebenem Verzeichniss

ls -a -l --> Listet verzeichnisse oder Datein im Terminal auf. Die Option -a zeigt auch versteckte Verseichnisse und die
             Option -l gibt die Verzeichnisse und Dateien in einer formatierten Liste aus.

### 3.2 Git speziefische Befehle

git clone <domain der Repository> --> Clont die Remoterepository vom Server auf den Privatrechner

git pull --> aktualliesiert die lokale repository mit der remote repository

git add <Hizuzufügende Datei> --> Fügt die Anderungen din den Inex ein

git commit -m "Commit nachricht" --> Verschiebt die Veränderungen mit der zusäzlich angegebenen Nachricht in die Lokale repository.

git push --> Lädt alle commits aus der Lokalen Repository in die Remoterepository.
