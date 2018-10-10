# Protokoll 1 (08.10.2018)
Name: Fischer Maximilian  
KNr.: 3  
Klasse: 4AHME  
Gruppe: 1  
___
### Übersicht / Verzeichniss

1. Versionsverwaltung
    1. VCS-Historie
    1. [Git][git]
    1. [Github][github]
1. Markdown
1. Wichtige Konsolenbefehle 
___
## **1** Versionsverwaltung

### **1.1** Historie

Vor git gab es einige andere VCS *(Version Control System)*, zu diesen gehören unteranderem:

- [CVS][cvs]
- [Subversion][subversion]
- [Mercuria][mercurial]

[Linus Torvalds][linus], der Entwickler hinter git sah hinter den *alten* Systemen ein Problem:
> Die lokalen Verzeichnisse haben nur mit aktiver netzwerkverbindung funktioniert, somit war das arbeiten an einem Projekt offline unerdenklich.

Dieses Problem löste [Linus][linus] mit [Git][git] indem er zu den bereits existierendem System (lokales Verzeichnis und remote Repository) ein weiteres Repository, das lokale Repository zwischenschaltete.

### **1.2** Git

### **1.3** Github
[Github][github] ist einer der großsten remote-repository Anbieter und stellt öffentliche Repositories nach einer Anmeldung kostenlos zur verfügung.
___
### **2** Markdown

[Markdown][markdown] ist eine einfache **Auszeichnungssprache** welche durch den Browser **gerendert** werden.

Es ist hilfreich sich das [Cheatsheet][cheatsheet] anzusehen, in welchem verschiedenste Formattierungsoptionen erklärt werden. 

Interessant ist vorallem syntax highlighting für code segmente. 
```java
public static void testSyntaxHighlighting(String s, int x){
    System.out.println("ein string: " + s + " ein integer: " + x);
}
```

___
### **3** Wichtige Konsolenbefehle

##### Linux 

`cd` - steht für 'change directory', wechselt das aktuelle arbeitsverzeichnis zum home-verzeichnis des benutzers  
`cd <path>` - wechselt das aktuelle arbeitsverzeichnis zum angegebenen pfad  
`ls` - listet alle datein im aktuellen arbeitsverzeichnis auf  
`ls -a` - listet auch versteckte datein  
`ls -la` - zeigt mehr informationen zu den listeneinträgen  
`ll` - alias für 'ls -la' unter ubuntu 

##### Git

`git clone <repo>` -   
`git add <files>` - fügt die angegebenen dateien zum index hinzu  
`git commit -m "message"` - schreibt die veränderten datein ins lokale repository 
`git status` - zeigt den aktuellen zustand des lokalen verzeichnisses  
`git push` - läd veränderte daten vom lokalen repository auf das remote repository hoch  

[git]: https://git-scm.com/"
[github]: https://github.com/"
[subversion]: https://de.wikipedia.org/wiki/Subversion"
[mercurial]: https://de.wikipedia.org/wiki/Mercurial"
[cvs]: https://de.wikipedia.org/wiki/Concurrent_Versions_System"
[cheatsheet]: https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet"
[markdown]: https://de.wikipedia.org/wiki/Markdown"
[linus]: https://de.wikipedia.org/wiki/Linus_Torvalds"
