# Protokoll
**von Anna Murko**  
Datum: 06.11.2018  
Gruppe: 2  
Betreuer: Professor Steiner  
abwesend: -  
  
  Thema: **Versionsverwaltung**  
  Definition: *Darunter versteht man Systeme, deren Aufgabe es ist, verschieden Zustände zu verschiedenen Zeiten zu verwalten.*  

## Inhalt 
**1.Git**  
**2.Vorteile von Git**  
**3.Aufbau von Git**  
**4.wichtige Befehle**  
**5.Branches**  
**6.GitHub**  
**7.Markdown**  
**8.SSH und GitHub**  

### 1.Git  
Git ist ein beliebtes Versionsverwaltungssystem welches sehr oft verwendet wird. Mit diesem System können mehrere Personen, die an einem Projekt arbeiten, auf die gemeinsamen Daten zugreifen, aber auch für den privaten Einzelzweck ist Git sehr praktisch. Dieses System wurde von Linus Torvald entwickelt, der mit den anderen Systemen nicht zufrieden war. (z.B.:SVN,CVS,Clearcase)

### 2.Vorteile von Git
* Das Verschmelzen von Entwicklungszweigen wird unterstützt.
* Jeder Projektteilhaber hat eine lokale Kopie des Repositories.
* Es ist keine Internetverbindung notwendig.
* Die gesamten Repositories können über das Internet synchronisiert werden.

### 3.Aufbau von Git
Das Git ist wie folgt in 5 Ebenen aufgebaut:
* *workspace*                | Arbeitsbereich  
* *stash*                    | Rücksicherung der Daten aus dem Workspace  
* *index*                    | Zwischenspeicher, wenn manche Daten noch nicht für alle freigegeben werden sollen  
* *local repository*         | lokale Datenverwaltung am eigenen PC  
* *remote repository*        | gemeinsame Datenverwaltung, die sich mit den lokalen Datenverwaltungen abgleicht  

![5 Ebenen](https://camo.githubusercontent.com/6101a2b0f170b0a22db8b1077bfa2c6d7fb172bf/68747470733a2f2f692e737461636b2e696d6775722e636f6d2f4d676156392e706e67)  

### 4.wichtige Befehle
* *git add* | Dateien werden vom Workspace nach Index bewegt.  
* *git commit* | Dateien werden vom Index ins lokal repository bewegt.  
* *git push* | Dateien vom lokal repository auf Git-Server geladen.  
* *git clone* | Das gesamte Repository wird geklont.  
* *git pull* | Dateien werden vom Git-Server heruntergeladen.  
* *git status* | Alle Änderungen werden angezeigt 

### 5.Branches
Branches werden auch Verzweigungen genannt. Damit ist es möglich Funktionen getrennt voneinander zu entwickeln. Bei dem Erstellen
eines neuen Repositorys wird der "Master Branch" erstellt. In diesem Brunch sollten nur funktionsfähige Programme gespeichert werden. 

### 6.Git Hub
Damit können kostenlose Git-Systeme erstellt werden, bei denen jeder über Leserechte verfügt. Schreibrecht hat nur der Benutzer.
Private repositorys können mit Geld erworben werden.  
Bei dem Erstellen einer repository ist auf folgendes zu achten:  
* Es ist empfehlenswert eine der vorgefertigten open source Lizenzen auszuwählen.
* Es sollte die Programmiersprache ausgewählt werden, welche gewisse Datein ignoriert werden.

Mit *readme's* können Informationen an den Nutzer weiter gegeben werden.
Link zur Website: 
[GitHub](https://github.com/)

### 7.Markdown
Markdown ist ein Format, welches ein Textfile in eine HTML-Datei(PDF,...) umwandeln kann.
GitHub verwendet Markdown.

[Syntax Guide](https://guides.github.com/features/mastering-markdown/)

### 8.SSH und GitHub
