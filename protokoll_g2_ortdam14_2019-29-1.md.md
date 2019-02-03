# Protokoll  
**Datum: 29.01.2018  
**Gruppe: 2  
**abwesend: -  
  
# Inhalt  
1. Übersetzungsvorgang C  
1. Make Tool  
1. Makefile  
  
## Übersetzungsvorgang C  
Folgende Schritte sind notwendig um den C-Quellcode in das Zielprogramm umzuwandeln:  
![Ablauf](https://github.com/ortdam14/labor/blob/master/Ablauf.png)  
Eine genaue Beschreibung ist in einem älteren Protokoll zu finden: ![Protokoll](https://github.com/HTLMechatronics/m15-la1-sx/blob/ortdam14/protokoll_g2_ortdam14_2018-11-13.md)  
## Make Tool  
![Make](https://de.wikipedia.org/wiki/Make) ist ein Build-Management-Tool, das Kommandos in Abhängigkeit von Bedingungen ausführt. Es wird hauptsächlich bei der Softwareentwicklung als Programmierwerkzeug eingesetzt.  
  
Genutzt wird es beispielsweise, um in Projekten, die aus vielen verschiedenen Dateien mit Quellcode bestehen, automatisiert alle Arbeitsschritte (Übersetzung, Linken, Dateien kopieren etc.) zu steuern, bis hin zum fertigen, ausführbaren Programm. Make ist jedoch so flexibel ausgelegt, dass es auch beliebige andere Aufgaben steuern kann, bei denen die zeitliche Abhängigkeit von Dateien eine Rolle spielt.  
  
Weitere Übersetzungstools sind "![Ant](https://de.wikipedia.org/wiki/Apache_Ant)" und "![Gradle](https://de.wikipedia.org"/wiki/Gradle).  
  
Make liest ein sogenanntes Makefile, in dem die Abhängigkeiten des Übersetzungsprozesses von Programmen formalisiert erfasst sind. Diese Formalisierung beschreibt, welche Quelltextdateien auf welche Weise durch den Compiler oder durch andere Programme zu welchen Objektdateien bzw. Ergebnissen verarbeitet werden, bzw. welche Objektdateien vom Linker zu Programmbibliotheken oder ausführbaren Programmen verbunden werden. Alle Schritte erfolgen unter Beachtung der im Makefile erfassten **Abhängigkeiten**.

## Makefile  
  
Makefiles werden in einem Texteditor geschrieben und beinhalten die Anweisungen für das Make Tool. Sie können nicht nur für den Übersetzungsvorgang von Programmen eingesetzt werden, sondern sie sind auch für andere Anwendungen, in denen die zeitliche Abhängigkeit von Dateien ein Rolle spielt, nützlich. Makefiles sind aus Zielen, Abhängigkeiten und Kommandos aufgebaut.  
  
Im Makefile werden sogenannte Ziele definiert, auch target genannt, welche mit einem Doppelpunkt dargestellt werden. Das erste Ziel ist immer das Hauptziel, wir finden es hier in der ersten Zeile. Nach dem Ziel folgen immer die Abhängigkeiten sowie die auszuführenden Kommandos.  
  
**Aufbau des Makefile**  
```
Ziel 1: Abhängigkeiten 
  ->  Kommando A
  ->  Kommando B
  ->  Kommando C

Ziel 2: Abhängigkeiten
  ->  Kommando A
  ->  Kommando B
```
Es ist zu beachten das im Makefile echte Tabulatoren verwendet werden müssen!  
  
**Wie weiß Make wann übersetzt werden muss?**  
i. Make überprüft den Zeitstempel der Dateien  
ii. Fehlt eine Datei, wird sie wenn möglich erstellt (bei fehlender main.c wird eine Fehlermeldung ausgegeben).  
  
**Zeitstempel**  
Der **Zeitstempel** gibt an wann eine Datei das letzte Mal verändert wurde. Mit dem Befehl `touch <Datei>` kann dieser Zeitstempel auf Linux-Systemen aktualisiert werden.  
