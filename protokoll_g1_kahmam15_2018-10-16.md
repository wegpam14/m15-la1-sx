markdown HTML gerendert

Übersetzungvorgang in C:  

-Quelltext erstellen ...Sourcode (main.c)  
  -gewöhnliche Textdatei  
  -schreiben von Programmieranweisungen  
  
konvertierung in Maschinen lesbares Programm  
->Pre prozessor (#include, #define)  
-->preprozessierter Quelltext  
->compiler - übersetzt  in Assembler (Maschinensprache) 
-->Assembler Quelltextdatei  
->Assembler  
-->Objektdatei, Objectcode  
->Linker (adressen übergeben)  
-->ausführbares Programm  

Gnu Compiler  (Entwickler??)  
Visual C/C++ compiler  
. erstes verz  
.. 2. verz  
(Shell)bash  
ls - inhalt eines verzeichnisses anzeigen  
endezeichen: $ = benutzer # = admin  
~ bedeutet Homeverzeichnis  
whoiam befehl wer bin ich  
pwd welches verzeichniss bin ich  
ls --all
man(manual/mainpages) ls  
man 3 printf  
mkdir ue1 verzeichniss erstellen  
history mit pfeil taste oben/unten oder befehl histroy  
reset setzt shell zurück  
ls -l  Rechte der datei 1.3 eigentümer 2.3 gruppen 3.3 alle benutzer
d am anfang = directory  
benutzer - gruppe dateigröße datum eig name  
editoren: nano, gedit, vi  
mit cat oder less(viewer) (main.c) sichtbar machen
hexdump zeigt bytes der datei
hexdump -C  - mit textinhalt  
gcc main.c
./a.out zum ausführen  
>  verwendung?
gcc -E =reprozessieren
