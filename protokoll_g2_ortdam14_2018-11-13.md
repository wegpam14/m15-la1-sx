# Protokoll 2 (13.11.2018)  
**Name:** Orthofer  
**KNR:** 8  
**Klasse:** 4AHME  
**Gruppe:** 2  
## Verzeichnis  
1. GNU Projekt  
1. Übersetzungsvorgang C-Programm  
1. Linux-Befehle  
## GNU Projekt  
Die Entwicklung des GNU Projekts geht auf Richard Stallman zurück. Ziel war es, ein offenes, UNIX-ähnliches Betriebssystem zu schaffen, das Nutjzer kopieren, verändern und selbst weiter verbreiten dürfen. GNU gehört zur sogenannten [Free Software](https://de.wikipedia.org/wiki/Freie_Software). Bekanntheit erlangte es durch die GNU General Public License. Bekannte GNU Programme sind die [GNU Compiler Collection](https://de.wikipedia.org/wiki/GNU_Compiler_Collection), der [GNU Debugger](https://de.wikipedia.org/wiki/GNU_Debugger) sowie Werkzeuge der [GNU Core Utilities](https://de.wikipedia.org/wiki/GNU_Core_Utilities).  
![GNU Logo](https://upload.wikimedia.org/wikipedia/commons/thumb/3/39/Official_gnu.svg/220px-Official_gnu.svg.png)  
*GNU Logo*  
## Übersetzungsvorgang C-Programm  
### Präprozessor  
Das Verständnis zur Funktionsweise des Präprozessors ist sehr wichtig um QUellcode schreiben zu können und auch zu verstehen. Er stellt die erste Instanz vor dem eigentlichen kompilieren eines C-Programmes dar. Der Präprozessor durchsucht den Quelltext und ersetzt bestimmte Teile davon nach Vorgabe. Es ist eine Aufbereitung für das eigentliche Kompilieren. Der Präprozessor kann nicht garantieren das der aufbereitete Code sinnvoll oder richtig ist.  
![Präprozessor](https://github.com/ortdam14/labor/blob/master/Pr%C3%A4prozessor.PNG)  
### Compiler  
Der C-Compiler erhält den vom Präprozessor aufbereiteten Quellcode und übersetzt diesen aus der Hochsprache in einen Maschinencode. Die zwei vom Compiler ausgeführten Sprachen werden in weitere drei Phasen unterteilt. Der erzeugte Maschinencode wird als Object Datei gespeichert (durch .o Dateiendung erkennbar). Diese Object Files führt der Linker im letzten Arbeitsschritt zusammen.  
### Linker  
Der Linker "verbindet" nach erfolgreichem kompilieren die Object Files zu einer zentral ausführbaren Datei. Es wird zwischen den statistischen- und dynamischen Linken unterschieden.    
**Statistisches Linken:** Hier wird das gesamte Projekt einmalig zu einer ausführbaren Datei gelinked. Werden Änderungen vorgenommen muss dieser Vorgang wiederholt werden.    
**Dynamisches Linken:** Im Gegensatz zum Statistischen Linken werden die Object Files auf flexiblere weise verbunden. Nachteil ist, dass das Programm nicht mehr portabel ist, da DLL-Dateien, die bei jedem Programmstart neu eingebunden werden, schon am System sein müssen.  
![Linker](https://github.com/ortdam14/labor/blob/master/Linker.PNG) 
![Ablauf](https://github.com/ortdam14/labor/blob/master/Ablauf.png)    
*Stellt den gesamten Ablauf dar*  
[Quelle](https://commons.wikimedia.org/wiki/File:GCC_Schema.svg)  
## Linux Befehle 
### Shell  
Unter einer [Shell](https://de.wikipedia.org/wiki/Shell_(Betriebssystem)) versteht man eine Software mit der ein Benutzer mit dem Betriebssystem interagieren kann, auch "Mensch-Maschine-Schnittstelle" genannt. Der [Kernel](https://de.wikipedia.org/wiki/Kernel_(Betriebssystem)) stellt den "Kern" eines Betriebssystems dar, währendessen die Shell die "äußerste Schicht" darstellt. Textshells liefern meist ihre eigene Skriptsprache mit. Hier wären einige der wichtigsten Befehle unter Linux:  

|Befehle            |Beschreibung   |
| ----------------- |:-------------:|
|whoami		|Gibt den eigenen Login-Namen aus|
|sudo		|Befehl als root ausführen.|
|su			|Neue Session mit anderem Account aufmachen|
|cd [Verzeichnis]			    |Wechselt in das Verzeichnis|
|	cd..	|Wechselt ein Verzeichnis höher|
|cd/		|Wechselt in das Wurzelverzeichnis|
|cd-		|Wechselt in das vorherige Verzeichnis|
|mv			|Verschiebt eine Datei|
|rm		|Löscht eine Datei|
|ls			|Zeigt Order Inhalt an|
|mkdir		|Erzeugt ein Verzeichnis|
|rmdir		|Löscht ein Verzeichnis|
|pwd		|Zeigt aktuelles Verzeichnis|
|cat [Datei] 		|Zeigt Inhalt einer Datei|
|which		|Zeigt an, wo sich Programm befindet|
|touch		|Erzeugt leere Datei|
|cp		|Kopiert Dateien|
|clear		|Löscht die Konsole|
|cp			|Kopiert Dateien und Verzeichnisse|
|history		|alle Kommandos die eingegeben wurden|
|hexdump main.o - C			|Binärdatei ausgeben|
|objdump -d main.o	|Objektfile wird reverseengineered|
|du			|Zeigt den Speicherverbrauch einzelner Verzeichnisse an |
|-E			|Stoppt nach den Präprozessorbefehlen|
|echo		|Gibt einen Text auf der Konsole aus|
|env		|Gibt alle Umgebungsvariablen aus|
|file		|Zeigt den Dateitypen einer Datei an|
|find		|Durchsucht den Verzeichnisbaum, ausgehend vom aktuellen Verzeichnis, nach einer Datei|
|free		|Zeigt die Speicherauslastung des Systems an. Geteilt in RAM und SWAP-Space|
|ftp		|Öffnet eine FTP-Session zum angegebenen Rechner |
|G			|Damit kommt man zum Ende einer Seite|
|g			|Damit kommt man zum Anfang einer Seite|
|gcc main.c	|Main "ausführen"|
|grep		|Sucht nach einer Zeichenfolge in einer Datei, oder einer umgeleiteten Ausgabe |
|groups		|Zeigt die Gruppenzugehörigkeit eines Users|
|history	|Gibt die Einträge im History-File des Users nummeriert aus|
|ifconfig	|zeigt die aktuelle IP-Adresse |
|ipchains	|Tool zur Konfiguration der Kernel-Firewall|
|less 		|Viewer zum Anzeigen von (Text-)Dateien auf der Kommandozeile|
|ll			|Es erscheint eine Liste|
|locate		|Sucht Dateien mittels eines Indexes, der durch updatedb erstellt wird|
|logname	|Gibt den eigenen Login-Namen aus|
|ls			|Zeigt den Inhalt des aktuellen oder des angegebenen Verzeichnisses an|
|man		|Ausgabe der Handbuchseite zu einem Befehl oder einer Anwenundung|
|mv			|Verschiebt Dateien und Verzeichnisse |
|\n			|Man kommt zur nächsten Position|
|nano main.c|Man wechselt in den Editor, wo man ein C-Programm schreiben kann|
|netdate	|Zeitsynchronisation mit einem entferntem Rechner|
|netstat	|Gibt Informationen über Netzwerkverbindungen, Routingtabellen aus|
|newgrp		|Ändern der aktuellen Gruppe|
|uptime		|Zeigt die Uptime der Maschine an. Die Uptime ist die Zeit seit dem letzten Reboot.|
|nl			|Nummeriert die Zeilen der Ausgabe|
|pstree		|Zeigt alle Prozesse in einer Baumdarstellung an|
|type		|Zeigt den Typen einer Datei und die Interpretation des Dateinamens als Parameter an|
|q			|Verlassen des Handbuchs|
|rm -rf 	|Löscht Dateien und Verzeichnisse unterhalb|
|rmdir		|Löscht ein Verzeichnis|
|-S			|Stoppt nach der eigentlichen Kompilierungsstufe. Das Programm wird jedoch nicht zusammengebaut|
|Shift+n	|Eine Position zurück|
|Strg+o		|Datei speichern|
|Strg+x		|Editor beenden|
|Strg+r		|Datei öffnen|
|sort		|Sortiert die Ausgabe von Programmen, bzw Dateien|
|sum		|Ermittelt Dateilänge und Prüfsumme einer Datei|
|tty		|Zeigt das Gerät an, über das man angemeldet ist|
