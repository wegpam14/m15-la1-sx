# Protokoll 1 (06.11.2018)

**Name:** Marwin Korrenn  
**Klasse:** 4AHME  
**Gruppe:** 2  
**KNr.:** 7  
 
### Inhaltsangabe
1. Versionsverwaltunssysteme  
1. [Git](https://git-scm.com/)  
1. [Github](https://github.com/)  
1. [Markdown](https://guides.github.com/features/mastering-markdown/)  
1. Consolen Befehle  
    1. Linux  
    1. Git   

## 1. Versionsverwaltung  
*Definition:*  
Die [Versionsverwaltung](https://de.wikipedia.org/wiki/Versionsverwaltung) ist ein System, mit dem man änderungen an Dateien und Dokumenten managen kann. Alle Versionen werden mit den Daten der Zeit und des Benutzers gesichert und können jederzeit wieder abgerufen werden.  

*Beispielprodukte:* clearcase (teuer/für Firmen); cvs; svn; mecury; Git (Linus Thorwald)  

## 2. Git
[Git](https://de.wikipedia.org/wiki/Git) ist ein begrenzt kostenfreies Versionsverwaltungssystem welches von Linus Torwald 2005 entwickelt wurde weil es ihn nerfte, dass man für alle bisherigen Versionsverwaltungssysteme eine Internetverbindung benötigte um vernünftig damit arbeiten zu können.  

Er löste sein eigenes Problem indem er in den eigenen Rechner einen "Lokcal Reprository" integrierte.  

Abgesehen davon dass es das meistgenutzteste Versionsverwaltungssystem ist, zeichnet Git sich außerdem durch
- einen dezentraler Server  
- eine nicht-lineare Entwicklung *(umgesetzt mithilfe von branches)*  
- eine kryptographische Sicherheit der Projektgeschichte  

Einen übersichtlichen Einblick über die wichtigsten Git - Befehle verschafft uns diese Grafik:  

![Grafik](https://camo.githubusercontent.com/6101a2b0f170b0a22db8b1077bfa2c6d7fb172bf/68747470733a2f2f692e737461636b2e696d6775722e636f6d2f4d676156392e706e67)  
*Index (Stage Area):* Kurze Speicherung von kleinen Änderungen.  
*Stash:* Zwischendateien speichern aber nicht in den Rep. Überspielen.  

## 3. Github  
[Github](https://de.wikipedia.org/wiki/GitHub) ist einer der größten remote-repository Anbieter.

Allerdings gilt bei kostenloser Benutzung die Philosophie:  
**"Im Git ist man selbst dafür zuständig sein geistiges Eigentum rechtlich zu schützen (Lizenzen)."**  

## 4. Markdown      
[Markdown](https://guides.github.com/features/mastering-markdown/) versucht das dokumentieren mit einem Texteditor, was schnell und einfach funktioniert, grafisch in eine gut auszulesende und übersichtliches Format zu invertieren.  
> Zur leichteren Bedienung kann man das Sogenannte [Cheatsheet](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet) verwenden in welchem alle abkürzungen aufgelistet sind.  
[Lorenz Breitentaler, Protokoll 1](https://github.com/HTLMechatronics/m15-la1-sx/edit/brelom15/protokoll_g1_brelom15_091018.md)  

## 5. Consolen Befehle  
### i Linux  

`cd` - (change directory) wechselt das aktuelle Arbeitsverzeichnis zum Home-Verzeichnis des Benutzers  

`cd <path>` - wechselt das aktuelle Arbeitsverzeichnis zum angegebenen Pfad  

`ls` - listet alle Datein im aktuellen Arbeitsverzeichnis auf  

`ls -a` - listet auch versteckte Datein  

`ls -la` - zeigt mehr Informationen zu den Listeneinträgen  

`ll` -  für 'ls -la' unter ubuntu 

### ii Git  

`git add <files>` - fügt die angegebenen dateien zum Index hinzu  

`git commit -m "message"` - schreibt die veränderten Datein ins lokale Repository 

`git status` - zeigt den aktuellen Zustand des lokalen Verzeichnisses  

`git push` - läd veränderte Daten vom lokalen Repository auf das remote repository hoch  

[Maximilian Fischer, Protokoll 1](https://github.com/HTLMechatronics/m15-la1-sx/edit/fismam15/protokoll_g1_fismam15_2018-10-09.md)  
 
[Versionsverwaltung]:(https://de.wikipedia.org/wiki/Versionsverwaltung)  
[Git]:(https://de.wikipedia.org/wiki/Git)  
[Git]:(https://git-scm.com/)  
[Github]:(https://github.com/)
[Github]:(https://de.wikipedia.org/wiki/GitHub)  
[Markdown]:(https://guides.github.com/features/mastering-markdown/)  
[Lorenz Breitentaler, Protokoll 1]:(https://github.com/HTLMechatronics/m15-la1-sx/edit/brelom15/protokoll_g1_brelom15_091018.md)  
[Maximilian Fischer, Protokoll 1]:(https://github.com/HTLMechatronics/m15-la1-sx/edit/fismam15/protokoll_g1_fismam15_2018-10-09.md)  
