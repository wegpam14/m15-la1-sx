 # Protokoll der 1. Einheit (08.10.2018)
  Name: 		Hörmann
  Gegenstand: Labor
  Lehrer: SX
  Klasse: 4AHME
  Gruppe: 1
  ## Inhaltsverzeichnis
  

 1. Versionsverwaltung
 2.  Github
 3.  Markdown
 4.  Linux Terminal-Befehle
 
 ## 1. Versionsverwaltung
 __1.1  Definition__  
Eine **Versionsverwaltung** ist ein System, das zur Erfassung von Änderungen an Dokumenten oder Dateien verwendet wird. Alle Versionen werden in einem Archiv mit Zeitstempel und Benutzerkennung gesichert und können später wiederhergestellt werden. Unterschiedliche Software- und Applikationsversionen können so gespeichert und verwaltet werden.    _Quelle: [Wikipedia](https://de.wikipedia.org/wiki/Versionsverwaltung)_, Unterricht
__2.2 Arten der Versionsverwaltung__
Es gibt viele verschiedene Arten der Versionsverwaltung, darunter: 
 - [Git](https://de.wikipedia.org/wiki/Git)
 - CVS 
 - SVN
 - Mercury

 __Git:__ Die von [Linus Torvalds](https://de.wikipedia.org/wiki/Linus_Torvalds) initiierte open Source Software ist heute die bekannteste Art der Versionsverwaltung, sie erschien 2005 und ist auf nahezu allen gängigen Betriebssystemen Lauffähig.

## 2. Github

__2.1 Definition__
  Git ist eine freie Software zur Versionsverwaltung von Dateien.
  Die wichtigsten Unterschiede zu SVN sind:
   1. Die Repositorys werden Lokal (z.B. auf den PC) gespeichert
 2. Die Versionsverwaltung ist auch offline verfügbar

__2.2 Nutzung von Github__
Die Nutzung von Github ist sinnvoll, solange man kein Problem damit hat, dass andere Personen einblick in die Daten der gespeicherte Inhalte haben, sollte man ein Problem damit haben,  müsste man einen monatlichen Betrag zahlen. Daten die auf Github gespeichert sind, sind für jeden sichtbar, andere Programmierer haben so einblick auf ein Programm und können so die aktuellsten Version sofort bearbeiten und deren Probleme beheben. Auch sind die Daten doppelt gesichert, da man sie auf den lokalen Repository (Festplatte) und dem Remote Repository (Github) gespeichert hat.

## 3. Markdown

__3.1 Definition__
[Markdown](https://de.wikipedia.org/wiki/Markdown) ist eine vereinfachte Auszeichnungssprache entwickelt von [John Gruber](https://de.wikipedia.org/w/index.php?title=John_Gruber&action=edit&redlink=1) und [Aaron Swartz](https://de.wikipedia.org/wiki/Aaron_Swartz) . Ihr zweck ist es, auch ohne Konvertierung leicht lesbar zu sein und somit verständlich sein soll. 

__3.2 Mastering Markdown__
Der folgende Link beinhaltet verschieden Formatierungsmöglichkeiten für 
Markdown-texte, diese sollen den Text leichter lesbar und übersichtlicher machen.
Um schnell einen gut gebauten Text in Markdown zu schreiben, sollte man auch den richtigen Texteditor verwenden, hier empfiehlt sich StackEdit, mann kann aber auch andere Texteditorn verwenden.

Link für die Formatierungsmöglichkeiten: [Mastering Markdown](https://guides.github.com/features/mastering-markdown/)
Link für einen geeigneten Texteditor um mit Markdown zu schreiben: [StackEdit](https://stackedit.io/app#)

## 4. Linux Terminal-Befehle
__4.1 Befehlsliste__

    cd
 -Change Directory / Verzeichniss ändern
    
    ls
  -Datein im Verzeichnis anzeigen
  
    git --version
  -Version des _Git_ überprüfen
    
    git clone [Link]
-Um eine Kopie des Remote Repositorys in das lokale Repository zu speichern
     
    git status
-Um zu sehen, ob sich Dateien geändert haben

    git add* 
-Um alle Dateien in den Index zu bringen

     git commit
-Bringt Dateien vom Index in das lokale Repository

    git push
-Befördert die Dateien vom lokalen Repository in das Remote Repository
