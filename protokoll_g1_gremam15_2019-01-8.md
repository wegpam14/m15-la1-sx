### 1. Protokoll
Name: **Grebien Markus**  
Klasse: **4AHME**  
Knr: **3**  


**Inhaltsverzeichnis**
 1. Makefile
	 + Aufbau
	 + Kompeliervorgang
 2. 
---

### 1.  Makefile
	
In einem Makefile stehen die nötgen Informationen, welche zum übersetztenvon Projekten dringend notwendig sind. Diese Datei macht das Entwickeln von großen projekten effizienter. Und bei Änderungen wird nur doe Datei mit den Änderungen Kompiliert und nicht das gesamte Projekt.
Mithilfe von dem befehl `make` wird diese Datei abgearbeitet. Falls man keine zusätzlichen Parameter angibt, wird einfach der Befehl ausgeführt, welcher ganz oben steht. Dies funktioniert so, obwohles keine direkte priorität gibt, allesdings wird eben das, was ganz oben steht als "default target" verwendet.

In unserem Fall Kompiliert er die dateien zusammen und bindet die nötigen Header Files dazu.
	
```Makefile
ue03: main.o lcd.o log.o
	gcc -o ue03 main.o lcd.o log.o

main.o: main.c lcd.h log.h
	gcc -c main.c

lcd.o: lcd.c lcd.h log.h
	gcc -c lcd.c

log.o: log.c log.h lcd.h
	gcc -c log.c

clean:
	echo "alles gelöscht"
	-rm *.o
	-rm ue03
```

Mithilfe von `ue03` Kompelieren wir die Dateien miteindnder.
Um alle KOmpiliertenObjektdateien(.o) zu löschen, verwenden wir den zusatzparameter `clean`.

Der Übersetzungsvorgang von einer c(c++) Datei:
![c_compilersteps]

Probleme des Compilers:
+ Tunnelblick
	+ Er sieht nur die momentan zu Kompelierende Datei und sonst nichts. Das kan dazu führen, dass wenn Funktionen in einer `header file` definiert sind, er sie nicht sieht, wenn er z.B. die main.c kompiliert, wodurch ein Fehler ausgegeben wird.
	+ Allerding ist der Kompiler schlau genug, um zu erkennen, ob es sich um eine Funktion handelt oder nicht. Jedenfalls versucht es es mit einer Funktion, weil nach den Namen der Funkton runde Klammern () kommen.
	+ Er nimmt funktionen nit einem `int`  als rückgabewert an. Dies nennt man  implizite Implemetntion.
+ Doppeldefinitionen
	+ Wenn eine `header file`mehr als einmal Implementiert wird kann es zu doppeldefinitionen kommen.
	+ Bei einem `struct` hat das zur Folge, weil es ja nur einmal deiniert werden darf, selbst wenn es zweimal genau gleich aussaut, dass der Compiler sagt, dass er nicht fertig machen kann, weil das `struct` schon definiert ist.


Wichtige Befehle:
`history` -> Mit diesem Befehl kann man sich seine Befehlshistory anschauen
`echo` -> Kann einen Text im Terminal ausgeben
`nano` -> Öffnen einen Editor, mit welchen man z.B. c oder Makefiles schreiben kann.
`make` -> Wenn man diesen Befehlausführt, versucht er im derzeitem Verzeichnis eine Makefile zu finden. Falls eine Voranden ist, führt er sie aus.





[c_compilersteps]: http://fbmathe.bbs-bingen.de/Informatik/C_plusplus/Uebersetzungsvorgang__c++.jpg
