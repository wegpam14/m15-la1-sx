# Protokoll 1 #
Name: Skof Jonas  
Klasse: 4AHME  
KNR: 11  
Gruppe: 2  

## Inhalte ##

**1. Versionsverwaltung**  
**2. GitHub**   
**3. Markdown**     
**4. Git spezifische Befehle**  


# 1.Versionsverwaltung #

Eine Versionverwaltung verwaltet verschiedene Abläufe zu bestimmten Zeitpunkten während eines Projektes.
Weiters wird ein Versionsverwaltungs-system genutzt um zu einem späteren Zeitpunkt auf alte Versionen des selben Produktes zurückgreifen zu können.

Ziele der Versionverwaltung sind:

-->  **Teamfähigkeit**  
-->  **Schutz for sich selbst**  
-->  **Kein Datenverlust**  

Produkte: Git, CVS, SVN, Mecury, Clearcase;

Git ist heutzutage das **meist** verwendetste System.

**Geschichte:** [Linus Torvald](https://de.wikipedia.org/wiki/Linus_Torvalds) war mit seinem damaligem System nicht zufrieden, da es keine offline Arbeit, welch er bei verschiedensten Geschäftsreisen im Flugzeug allerdings benötigte, zuließ. Also entwickelte er Git so weiter, dass eine zusätzliche lokale [Repository](https://de.wikipedia.org/wiki/Repository) erstellt wurde, mit welcher er offline arbeiten konnte. Bei wieder verbindung mit dem Internet konnte er dann seine Änderungen auf die Remote [Repository](https://de.wikipedia.org/wiki/Repository) wieder hochladen.  

# 2.Github #

![Github](index.png)  
  
GitHub ist einer der größten Remote [Repository](https://de.wikipedia.org/wiki/Repository) Anbieter weltweit. Allerdings werden nur Öffentliche [Repositorys](https://de.wikipedia.org/wiki/Repository) kostenlos zur verfügung gestellt. Dennoch ist die freie Version von Github mehr als ausreichnend um sich mit anderen Menschen auszutauschen. 
Die .gitignore gibt an welche Dateien oder Verzeichnise nicht verwaltet werden sollen.

Eine gute Übersicht über die bedeutesten Git-Befehlen gibt folgende Grafik, in welcher auch der Datenstrom zu erkennen ist:

![GitDataTransportCommands](GitDataTransportCommands.png)  

# 3. Markdown #

Markdown ist eine vereinfachte Auszeichnungssprache, welche es sich zum Ziel gesetzt hat, dass schon die Ausgangsform ohne weitere Konvertierung leicht lesbar ist.

Interessant ist vorallem Syntax-Highlighting für Quelltexte. Als Beispiel:

```javascript
function fancyAlert(arg) {
  if(arg) {
    $.facebox({div:'#foo'})
  }
}
```

Zur leichteren Bedienung kann man das Sogenannte Cheatsheet verwenden in welchem alle abkürzungen aufgelistet sind.
Es ist hilfreich sich das Cheatsheet anzusehen, in welchem verschiedenste Formattierungsoptionen erklärt werden.#

Hier sieht man die verschiedenen Markdown Befehle um z.b eine Text *Kursiv* zu machen:

✗    # Überschrift #  
✗   ## Unterüberschrift ##  
✗     * Kursiv *  
✗    ** FETT **  
✗    ~~Durchgestrichen~~  
✗   ```  syntax highlighting   ```  
✗    >Zitat  
✗  Link einfügen: [name] (link)  
✗  Bild einfügen: ![name] (Dateiname)

# 4. Git spezifische Befehle #

 git clone <repo> - > Klont die Remote-Repository vom Server auf den Privatrechner

 git add <files> - > Fügt die angegebenen dateien zum index hinzu

 git commit -m "message" - > Schreibt die veränderten datein ins lokale repository

 git status - > Zeigt den aktuellen zustand des lokalen verzeichnisses

 git push - > Lädt veränderte daten vom lokalen repository auf das remote repository hoch
  












