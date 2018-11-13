# Protokoll
**von Anna Murko**  
Datum: 13.11.2018  
Gruppe: 2  
Betreuer: Professor Steiner  
abwesend: Skof Jonas 
  
  Thema: **Übersetzungsvorgang**  
  Definition: *Beschreibt wie ein C-Quellcode in ein ausführbares Programm übersetzt wird.*  

## Inhalt 
**1.Historie**  
**2.Übersetzungsvorgang-Ablauf**  
**3.Linux-Befehle**  

### 1.Historie
![](https://upload.wikimedia.org/wikipedia/commons/thumb/1/19/Richard_Stallman_speaking_at_Wikimania_2005-08-07.jpg/220px-Richard_Stallman_speaking_at_Wikimania_2005-08-07.jpg)

**Richard Stallman**, *Gründer des GNU-Projekts und der Freien-Software-Bewegung*  
Die **Freie-Software-Bewegung** ist eine soziale Bewegung mit den Zielen, Freie Software zu propagieren und damit bestimmte Freiheiten für Benutzer von Software zu erreichen oder diese zu wahren: Die Freiheit, die Software auszuführen, zu studieren und zu ändern sowie Kopien der Software mit oder ohne Änderungen verteilen zu können. Obwohl er sich auf Traditionen und Philosophien unter Mitgliedern der 1970er Hackerkultur und Akademia stützte, gründete Richard Stallman formell die *Bewegung im Jahr 1983 durch die Gründung des GNU-Projekts*. Im Jahr 1985 gründete er auch die **Free Software Foundation (FSF)**, um die Bewegung zu unterstützen.

[Quelle](https://en.wikiquote.org/wiki/Richard_Stallman)



### 2.Übersetzungsvorgang  
Ein Projekt kann aus mehreren Quelltextdateien bestehen. Wird der Übersetzungsvorgang gestartet, muss für jede Quelltextdatei die   gesamte **Sequenz** durchlaufen werden. Die punktierten Linien in der Grafik bezeichnen Positionen innerhalb der **Sequenz**, für die der Ablauf abgebrochen und einen entsprechende Ausgabedatei geschrieben werden kann.   
Der **Präprozessor** ist ein simpler Textersetzer, der zu Beginn der **Sequenz** gestartet wird. Er durchsucht den Quelltext nach Anweisungen,   die für ihn bestimmt sind - sogenannten  **Präprozessoranweisungen** - und führt diese Befehle im Text aus.   
Der Text wird durch den  **Präprozessor** also modifiziert, bevor er zum **Compiler** weitergereicht wird. 
Im Anschluss daran findet eine **Syntaxüberprüfung** statt. Es wird überprüft, ob der Text den formalen Regeln der Programmiersprache C folgt. Der Quelltext wird auch nach -einfachen- häufigen Fehlern untersucht.

Erst dann wir der eigentliche **Compiler** gestartet und die Befehle in Assemblersprache übersetzt.Durch diesen Zwischenschritt ist es möglich, verschiedene **Assemblierer** zu verwenden. Mit einer Option an den Compiler kann die **Sequenz** hier unterbrochen und eine Textdatei in **Assembelerformat** geschrieben werden.
Anschließend wird das Programm durch den **Assemblierer** assembliert, das heißt in Maschinensprache umgewandelt. Er schreibt schreibt die Objektdatei,die in Maschinensprache übersetzte Quelltextdatei.
Zwischen **Compiler und Assemblierer** kann noch ein **Optimierungsschritt** eingefügt werden. Der **Optimierer** optimiert den **Assemblercode** nach ihm bekannten Richtlinien. Es gibt verschiedene Arten der **Optimierung**: Optimierung nach Laufzeit, beziehungsweise nach der Codegröße. **Optimierer** nimmt Änderungen im **Assemblercode** vor. 
Für jede Quelltextdatei wird eine Objektdatei erzeugt.

Um ein ausführbares Programm zu erhalten, müssen alle Objektdateien, die je ein Modul des Gesamtprogrammes darstellen, kombiniert werden. 

![Übersetzungsvorgang Grafik](https://github.com/HTLMechatronics/m15-la1-sx/blob/muranm15/%C3%9Cbersetzungsvorgang.GIF)![Linkvorgang](https://github.com/HTLMechatronics/m15-la1-sx/blob/muranm15/Linker.GIF)  
l.Übersetzungsvorgang-r.Linkvorgang

[Quelle](https://books.google.at/books?id=oB0pBAAAQBAJ&pg=PA22&lpg=PA22&dq=%C3%BCbersetzungsvorgang+c-quellcode&source=bl&ots=8boxsovb99&sig=gwpyd02OwmRP4ewChDTzRp9vyqI&hl=de&sa=X&ved=2ahUKEwjx85H8jdLeAhVKsKQKHX-6CDIQ6AEwCXoECAUQAQ#v=onepage&q=%C3%BCbersetzungsvorgang%20c-quellcode&f=false)

### 3.Linux-Befehle

|Befehle            |Beschreibung   |
| ----------------- |:-------------:|
|alias		    |Legt alias-Namen für Kommandos an|
|-a		|kurze Option|
|--all		|lange Option|
|batch		|Einmaliges ausführen eines Befehles wenn das System nicht ausgelastet ist|
|-c			|Kompiliert die Quelldateien, verknüpft sie aber nicht|
|cat		|Verbindet mehrere Dateien und gibt das Ergebnis aus|
|cd			|wechselt in das Home-Verzeichnis des Benutzers|
|cd -		|wechselt in das vorherige Verzeichnis|
|cd ..		|wechselt in das übergeordnete Verzeichnis|
|cd /		|wechselt in das Hauptverzeichnis|
|cd 		|Wechselt in das angegebene Verzeichnis|
|chgrp		|Gruppenzugehörigkeit einer Datei ändern||
|chmod		|Zugriffsrechte ändern|
|chown		|Eigentümer einer Datei ändern|
|clear		|Löscht die Konsole|
|cp			|Kopiert Dateien und Verzeichnisse|
|cpio		|Kopiert Dateien in bzw. aus Archiven|
|df			|Zeigt die Speicherauslastung der Partitionen des Systems an,|
|dirname	|Gibt nur den Pfad zu einer Datei aus|
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
|groupadd	|Anlegen einer neuen User-Gruppe|
|groupdel	|Löschen einer bestehenden User-Gruppe|
|groupmod	|Ändern der Daten einer bestehenden User-Gruppe|
|groups		|Zeigt die Gruppenzugehörigkeit eines Users|
|halt		|Runterfahren des Systems|
|history	|Gibt die Einträge im History-File des Users nummeriert aus|
|hostname	|Zeigt den Namen des Rechners an|
|hexdump -C	|Codierung wird ausgegeben|
|ifconfig	|zeigt die aktuelle IP-Adresse |
|ipchains	|Tool zur Konfiguration der Kernel-Firewall|
|kill		|Beendet den Prozess mit der uebergebenen Prozess-ID |
|killall	|Beendet alle Prozesse mit dem uebergebenen Namen|
|killproc	|Beendet den Prozess, dessen ausfuehrbare Datei im uebergebenen Pfad zu finden ist|
|less 		|Pager zum Anzeigen von (Text-)Dateien auf der Kommandozeile|
|ll			|Es erscheint eine Liste|
|ln			|Erstellt einen Link zu einer Datei/Verzeichnis|
|locate		|Sucht Dateien mittels eines Indexes, der durch updatedb erstellt wird|
|login		|Als Benutzer anmelden|
|logname	|Gibt den eigenen Login-Namen aus|
|ls			|Zeigt den Inhalt des aktuellen oder des angegebenen Verzeichnisses an|
|man		|Ausgabe der Handbuchseite zu einem Befehl oder einer Anwenundung|
|mkdir		|Legt ein neues Verzeichnis an|
|mv			|Verschiebt Dateien und Verzeichnisse |
|\n			|Man kommt zur nächsten Position|
|nano main.c|Man wechselt in den Editor, wo man ein C-Programm schreiben kann|
|netdate	|Zeitsynchronisation mit einem entferntem Rechner|
|netstat	|Gibt Informationen über Netzwerkverbindungen, Routingtabellen aus|
|newgrp		|Ändern der aktuellen Gruppe|
|nice		|Setzt die Priorität eines Prozesses|
|nl			|Nummeriert die Zeilen der Ausgabe|
|nohup		|Startet ein Programm immun gegen SIGHUPs|
|pidof		|Gibt die PID(s) des Prozesses mit dem uebergebenen Namen aus|
|pstree		|Zeigt alle Prozesse in einer Baumdarstellung an|
|pwd		|Zeigt das aktuelle Verzeichnis an|
|q			|Verlassen des Handbuchs|
|rcp		|Remote Copy. Kopierfunktion auf einem entfernten Rechner.|
|rev		|Zeichenfolge umkehren|
|rm -rf 	|Löscht Dateien und Verzeichnisse unterhalb|
|rmdir		|Löscht ein Verzeichnis|
|route		|statische Routen anlegen|
|-S			|Stoppt nach der eigentlichen Kompilierungsstufe. Das Programm wird jedoch nicht zusammengebaut|
|Shift+n	|1 Position zurück hüpfen|
|Strg+o		|Datei speichern|
|Strg+x		|Editor beenden|
|Strg+r		|Datei öffnen|
|sort		|Sortiert die Ausgabe von Programmen, bzw Dateien|
|su			|Neue Session mit anderem Account aufmachen|
|sudo		|Befehl als root ausführen.|
|sum		|Ermittelt Dateilänge und Prüfsumme einer Datei|
|tail		|Die letzten Zeilen einer Daei lassen sich anzeigen, wird nicht angegeben wie viele Zeilen es sein sollen, dann 10|
|telnet		|öffnet eine Telnet-Session zum angegebenen Rechner |
|touch		|Ändert den Zeitstempel von Dateien. Wenn eine Datei nicht existiert, wird sie mit einer Grösse von 0 Byte angelegt|
|tty		|Zeigt das device an, über das man angemeldet ist|
|type		|Zeigt den Typen einer Datei und die Interpretation des Dateinamens als Parameter an|
|updatedb	|Erstellt einen Suchindex ueber das gesammte Dateisystem fuer locate|
|uptime		|Zeigt die Uptime der Maschine an. Die Uptime ist die Zeit seit dem letzten Reboot.|
|whereis 	|Sucht das Binary (ausfuehrbare Datei), den Quellcode und die man-Page eines Programmes|
|which		|Gibt den ersten gefunden Pfad eines Programmes im Pfad an|
|who		|Gibt die Login-Namen der momentan eingelogten User aus|
|whoami		|Gibt den eigenen Login-Namen aus|

**[Quelle](https://wiki.ubuntuusers.de/Shell/Befehls%C3%BCbersicht/)**
