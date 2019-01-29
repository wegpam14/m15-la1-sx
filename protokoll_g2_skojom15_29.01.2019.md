# Protokoll 4 #
Name: Skof Jonas  
Klasse: 4AHME  
KNR: 11  
Gruppe: 2  

## Inhalte ## 
**1.Wiederholung**  
**1.1 Make-Tools**   
**2.Makefiles**  
**3. Funktionsweise von Makefiles**  
**3.1 Zeitstempel**  
**3.2 Fehler beim Durchführen der Kommandos**  
***
# 1.Wiederholung C-Übersetzvorgang #
**Präprozessieren** ==> Bearbeitung von Anweisungen wie #include oder #define. Da diese Datei im Normalfall nicht wirklich                        entsteht, gibt es auch keine eigene Endung.  
**Kompilieren** ==>		Der durch den Präprozzessor bearbeitete Code wird in Assmeblercode umgewandelt    
**Assemblieren** ==>	Der Assemblercode wird in Maschinencode übersetzt  
**Linken** ==>	      Alle Programmteile werden durch den Linker vereint. Daraus entsteht ein ausführbares Programm  
**Umwandeln** ==>	    Die ausführbare Datei wird in ein Format umgewandelt, das der Programmer versteht. (z.B. Hex)  

## 1.1 Make-Tool ##
make liest ein sogenanntes Makefile in dem die Abhängigkeiten des Übersetzungsprozesses von Programmen formalisiert erfasst sind. Diese Formalisierung beschreibt, welche Quelltextdateien auf welche Weise durch den Compiler oder durch andere Programme zu welchen Objektdateien bzw. Ergebnissen verarbeitet werden, bzw. welche Objektdateien vom Linker zu Programmbibliotheken oder ausführbaren Programmen verbunden werden. Alle Schritte erfolgen unter Beachtung der im Makefile erfassten Abhängigkeiten.
Der gesamte Übersetzungsvorgang wird im Normalfall durch das make-Tool übernommen.
**Anwendung:**
Die Entwicklung großer Programme und Programmpakete, die aus vielen einzelnen Quelltext-Dateien bestehen und Abhängigkeiten zu separaten Bibliotheken besitzen, ist ohne make oder ähnliche Hilfsmittel kaum mehr denkbar. In der Welt des Open Source ist es üblich, dass mit dem Quellcode eines Projekts auch das Makefile veröffentlicht wird, um das compilieren einer Software zu vereinfachen
***
# 2. Makefiles #
Das Kompilieren von Quelltext-Dateien kann mit dem Programm make gesteuert werden. Dies ist vor allem dann sinnvoll, wenn es sich um ein großes Projekt handelt bei dem die Kompilierung aus vielen einzelnen Schritten und Abhängigkeiten besteht. Die einzelnen Schritte können zum Beispiel separate Kompilierungen oder andere Dateioperationen wie Kopieren und Löschen sein. Abhängigkeiten können zum Beispiel bedingte Kompilierungen sein. Diese Schritte und Abhängigkeiten werden in ein Makefile zusammengefasst, welches dann vom Programm make verarbeitet wird.

Bei der C-Prpgrammierung verwendet man normalerweise für die Übersetzung des Programs eine IDE(Integrated Development Environment) wie zum Beispiel Codeblocks oder Netbeans. Diese IDE's greifen aber auch auf das Tool make zurück.

Wird make in der Konsole aufgerufen, so wird eine Steuerdatei names Makefile ausgeführt.
Bei richtiger Einstellung des Makefile wird nur das Nötigste gemacht und schon abgeschlossene Teile weggelassen.
Ein Makefile besteht aus:
   *  einem Ziel
   *  einer Abhängigkeit
   *  einem Befehl

In der Datei Makefile befinden sich die relevanten Informationen für eine Übersetzung.

Zum Beispiel:
   *  was ist das Ziel der Übersetzung?
   *  aus welchen Dateien (Files) besteht das Projekt?
   *  welche Abhängigkeiten zwischen den Dateien sind gegegeben?
   *  welche Tools (Compiler, Linker, ...) werden wie und zu welchem Zeitpunkt aufgerufen?

***
# 3. Funktionsweise von Makefiles #
Beim Aufruf des Makefiles wird zuerst das erste Ziel aufgerufen. Die Abhängigkeiten werden dabei zuerst auf andere Ziele und dann auf Datein untersucht. Bei anderen Zielen als Abhängigkeit werden zuerst die abhängigen Ziele abgearbeitet. Bei Datein als Abhängigkeit wird der Zeitstempel von dem Ziel und der Datei verglichen um zu erfassen, ob ein neuerliches Durchführen der Kommandos überhaupt nötig ist.

## 3.1 Zeitstempel ##
Der Zeitstempel gibt an wann eine Datei das letzte Mal verändert wurde. Mit dem Befehl touch <Datei> kann dieser Zeitstempel auf Linux-Systemen aktualisiert werden.
  
## 3.2 Fehler beim Ausführen der Kommandos ##
Wenn das Makefile aufgerufen wird, läuft das Makefile soweit durch, bis ein Fehler auftritt. Das bedeutet, dass alle nachfolgenden Schritte nicht abgewickelt werden. Um das bei Befehlen, bei denen Fehler auftreten können, zu verhindern kann ein vor dem jeweiligen Kommando ein - eingefügt werden.

Ob ein Fehler aufgetreten ist lässt sich über die Rückgabewerte der Kommandos erfahren. Ist der Rückgabewert ungleich 0, so wird ein Fehler ausgegeben. In der Konsole kann der Rückgabewert des letzten Kommandors mit dem Befehle echo $?ausgeben werden

***
# 4.Übersetzung eines Programmes durch ein Makefile #
Diese kleine C-Programm soll "Guten Morgen" ausgeben. Es wurde die Datei main.c mithilfe des nano-Befehls erstellt:
```ruby
#include <stdio.h>

int main()
{
printf("Guten Morgen");
return 0;
}
```










































































