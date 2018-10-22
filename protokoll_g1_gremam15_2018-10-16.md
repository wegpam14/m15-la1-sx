### 2. Protokoll
Name: **Grebien Markus**  
Klasse: **4AHME**  
Knr: **3**


**Inhaltsverzeichnis**
 1. Übersetzungsvorgang in C
	 * Informationen
	 * Compiler
	 * Einzelne Schritte

2. Wichtige Terminalfunktionen

---

1. Übersetungvorgang in C
	* Das Übersetze eines C-Programmers erfolgt heuzutage mittels eines Compilers. Der meist verwendete ist zur zeit der GNU Compiler. Er wurde vo Richard Stallman entwickelt. Für Windows heißt dieser Compiler mingw, welches für **Min**imal **G**nu for **W**indows.

	* Compiler:
	Der Compiler besitzt mehrere Stufen. 
        ![alt text][c_compilersteps]
        + Zuerst hat man eine Quelldatei(main.c)
        + Beim Start wird diese Datei mit den headerdateien zusammengeführt und zu präprozessoren Quelltext.
        + Anschließend wird diese Datei mithilfe des Compilers zu Assemblerquelltext
        + Und zuletzt werden mithilfe vom Linker die Bibliotheksfunktionen miteingebunden und ers wird eine ausführbare Datei.

	+ Einzelne Schritte:
		 Mithilfe des `gcc` commands im Terminal können wir eine C-Datei sofort fertig Compelieren. Wenn man allerdings die einzelnen Schritte sehen will, braucht man spezielle zusatzargumente:
		+ `gcc -E main.c` mithilfe dieses Arguments kann man den präprozessoren Quelltext  als output bekommen [main.pp][main.pp_ue1]
		+ `gcc -S main.c` bekommt man den Assebler Quelltext [main.s][main.s_ue1]
		+ `gcc -c main.c`Als letzten Schritt auch noch die Objektdatei, welche für den Menschen nicht mehr gut lesbar ist [main.o][main.o_ue1] 

1. Wichtige Terminalbefehle
`whoami` = name des Benutzers
`mkdir` = erstellen eines neuen Ordners
`cat` = Fügt alle Dateien zusammen und gibt sie am Bildschirm aus
`pwd` = Aktueller Pfadname
`reset` = 
`ll` => `ls -l` = ausführliches Inhaltsverzeichnis
	+ d rwx rwx rwx d: dirctory, first group: user, second group: group, third group: all user  
    
editors: nano, gedit, VI





[c_compilersteps]: http://fbmathe.bbs-bingen.de/Informatik/C_plusplus/Uebersetzungsvorgang__c++.jpg
[main.pp_ue1]: https://github.com/HTLMechatronics/m15-la1-sx/blob/gremam15/src/ue1/main.pp
[main.s_ue1]: https://github.com/HTLMechatronics/m15-la1-sx/blob/gremam15/src/ue1/main.s
[main.o_ue1]: https://github.com/HTLMechatronics/m15-la1-sx/blob/gremam15/src/ue1/main.o

