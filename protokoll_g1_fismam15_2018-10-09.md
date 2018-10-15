# Protokoll 1 (08.10.2018)
Name: Fischer Maximilian  
KNr.: 3  
Klasse: 4AHME  
Gruppe: 1  
___
### Übersicht / Verzeichniss

1. Versionsverwaltung
    1. [VCS][vcs]-Historie
    1. [Git][git]
    1. [Github][github]
1. Markdown
1. Wichtige Konsolenbefehle 
___
## **1** Versionsverwaltung

Ein Versionsverwaltungs-system wird genutzt um zu einem späteren Zeitpunkt auf alte Versionen des selben Produktes zurückgreifen zu können. 

### **1.1** VCS-Historie

Vor [Git][git] gab es einige andere [VCS][vcs] *(Version Control System)*, zu diesen gehören unteranderem:

- [CVS][cvs]
- [Subversion][subversion]
- [Mercurial][mercurial]

[Linus Torvalds][linus], der ursprüngliche Entwickler von [Git][git] sah hinter den *alten* Systemen ein Problem:
> Die lokalen Verzeichnisse haben nur mit aktiver Netzwerkverbindung funktioniert, somit war das Arbeiten an einem Projekt offline nur eingeschränkt möglich.

Dieses Problem löste [Linus][linus] mit [Git][git] indem er zu den bereits existierendem System (bestehend aus: lokalesm Verzeichnis und remote Repository) ein weiteres Repository - **das lokale Repository** - zwischenschaltete.

### **1.2** Git

Git ist das [meist genutzte][vcspopularity] VCS derzeit. Es wurde 2005 von [Linus Torvalds][linus] initiiert.

Die Hauptmerkmale von Git sind:
- dezentraler Server
- nicht-lineare Entwicklung *(umgesetzt mithilfe von branches)*
- kryptographische sicherheit der projektgeschichte

Eine gute Übersicht über die bedeutesten Git-Befehlen gibt folgende Grafik, in welcher auch der Datenstrom zu erkennen ist:

![Git Data Flow][gitdataflow]

### **1.3** Github
[Github][github] ist einer der großsten remote-repository Anbieter und stellt öffentliche Repositories nach einer Anmeldung kostenlos zur verfügung. Um private - öffentlich nicht einsehbare Repos - zu erstellen muss ein gewisser Betrag gezahlt werden.

___
### **2** Markdown

[Markdown][markdown] ist eine einfache **Auszeichnungssprache** welche es ermöglicht mit wenig Aufwand einfach-formattierte Dokumente zu erstellen welche durch den Browser **gerendert** werden.

Es ist hilfreich sich das [Cheatsheet][cheatsheet] anzusehen, in welchem verschiedenste Formattierungsoptionen erklärt werden. 

Interessant ist vorallem Syntax-Highlighting für Quelltexte. Als Beispiel:
```java
public static void demoSyntaxHighlighting(String s, int x){
    System.out.println("string: " + s + " integer: " + x);
}
```
___
### **3** Wichtige Konsolenbefehle

#### Linux

`cd` - steht für 'change directory', wechselt das aktuelle arbeitsverzeichnis zum home-verzeichnis des benutzers  

`cd <path>` - wechselt das aktuelle arbeitsverzeichnis zum angegebenen pfad  

`ls` - listet alle datein im aktuellen arbeitsverzeichnis auf  

`ls -a` - listet auch versteckte datein  

`ls -la` - zeigt mehr informationen zu den listeneinträgen  

`ll` - [alias][alias] für 'ls -la' unter ubuntu 

#### Git

`git clone <repo>` -   

`git add <files>` - fügt die angegebenen dateien zum index hinzu  

`git commit -m "message"` - schreibt die veränderten datein ins lokale repository 

`git status` - zeigt den aktuellen zustand des lokalen verzeichnisses  

`git push` - läd veränderte daten vom lokalen repository auf das remote repository hoch  


[vcs]: https://en.wikipedia.org/wiki/Version_control
[git]: https://git-scm.com/
[github]: https://github.com/
[subversion]: https://de.wikipedia.org/wiki/Subversion
[mercurial]: https://de.wikipedia.org/wiki/Mercurial
[cvs]: https://de.wikipedia.org/wiki/Concurrent_Versions_System
[cheatsheet]: https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet
[markdown]: https://de.wikipedia.org/wiki/Markdown
[linus]: https://de.wikipedia.org/wiki/Linus_Torvalds
[alias]: https://wiki.ubuntuusers.de/alias/
[vcspopularity]: https://rhodecode.com/insights/version-control-systems-2016
[gitdataflow]: https://i.stack.imgur.com/MgaV9.png "Git data flow"
