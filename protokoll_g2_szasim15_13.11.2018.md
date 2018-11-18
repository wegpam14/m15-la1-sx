# Protokoll (13.11.2018)
---   
Simon Szapacs  
Gruppe 2  
Knr: 12  

**Thema: Übersetzungsvorgang**  
 
## Inhalt  

1. Geschichte  
1. Übersetzungsvorgang  
2.1 *Theoretische Grundlagen*
1. Linux- Befehle  

## 1. Geschichte  
---  
![](https://upload.wikimedia.org/wikipedia/commons/thumb/6/64/Wikimania_stallman_keynote2.jpg/220px-Wikimania_stallman_keynote2.jpg)  

**Richard Matthew Stallman** (* 16. März 1953 in Manhattan, auch unter den Initialen rms bekannt) ist ein US-amerikanischer 
Aktivist und Programmierer. Er setzt sich für **Freiheiten von Software-Endnutzern** ein: die Freiheiten der Kontrolle und Kollaboration 
sollen den Nutzern **nicht** entzogen werden. **Software soll so verbreitet werden**, dass Nutzer beim Empfang der Software gleichzeitig 
die Freiheiten mitempfangen, die Software ausführen, analysieren, verbreiten und abändern zu dürfen. Software, welche diese Freiheiten
sicherstellt, als Freiheits-Rechte, die zusammen mit dem Empfang der Software mitempfangen (gewährt) werden, nennt Stallman 
**„Freie Software“**. Für Stallman ist dies eine ethische Notwendigkeit.  

[Quelle](https://de.wikipedia.org/wiki/Richard_Stallman)  



## 2. Übersetzungsvorgang  
---  
### 2.1 Theoretische Grundlagen  
Die Übersetzung des in C programmiertem Quelltext in eine von der CPU lesbaren sprache ist in mehrere Schritte unterteilt.

Convertieren in die Maschinensprache:  


1. Preprozessing (der C-Quelltext wird in Prozessoranweisungen umgeschrieben)  
2. Compiler (Erzeugt eine Assembler Quelltext Datei)  
3. Assembler (erzeugt aus dem Assembler Quelltext eine Objectdatei)  
4. Linker (weißt die Adressen zu und das Programm ist ausführbar)  
![](http://fbmathe.bbs-bingen.de/Informatik/C_plusplus/Uebersetzungsvorgang__c++.jpg)  

## Linux Befehle  
|Befehle            |Beschreibung   |
| ----------------- |:-------------:|  
|cd			|wechselt in das Home-Verzeichnis des Benutzers|  
|alias		    |Legt alias-Namen für Kommandos an|
|-a		|kurze Option|
|--all		|lange Option|
|batch		|Einmaliges ausführen eines Befehles wenn das System nicht ausgelastet ist|
|-c			|Kompiliert die Quelldateien, verknüpft sie aber nicht|
|cat		|Verbindet mehrere Dateien und gibt das Ergebnis aus|
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
|echo		|Gibt einen Text auf der Konsole aus|
|env		|Gibt alle Umgebungsvariablen aus|
|file		|Zeigt den Dateitypen einer Datei an|
|find		|Durchsucht den Verzeichnisbaum, ausgehend vom aktuellen Verzeichnis, nach einer Datei|
|free		|Zeigt die Speicherauslastung des Systems an. Geteilt in RAM und SWAP-Space|
|ftp		|Öffnet eine FTP-Session zum angegebenen Rechner |
|G			|Damit kommt man zum Ende einer Seite|
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






