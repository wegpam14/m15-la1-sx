<h1 id="protokoll-nr.-03--">Protokoll Nr. 03  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/30/HTL_Kaindorf_Logo.svg/300px-HTL_Kaindorf_Logo.svg.png" alt=""></h1>
<p>Übungsdatum: <strong>02.10.2018</strong><br>
Name: Vollmaier Alois<br>
KNr.: 15 Klasse: 4AHME<br>
Gruppe: 3</p>
<p>Anwesenheit:</p>

<table>
<thead>
<tr>
<th>Anwesend</th>
<th align="center">Abwesend</th>
</tr>
</thead>
<tbody>
<tr>
<td>Vezonik, Vollmaier, Wesonig, Wegl, WinterM., WinterT.</td>
<td align="center">----</td>
</tr>
</tbody>
</table><hr>
<h3 id="themen-übersicht">Themen-Übersicht</h3>
<ul>
<li><strong>[1]</strong>-Atmel Studio
<ul>
<li>[1.1] - <em>Grundlagen</em><br>
– [1.1.1] - <em>Instruction Set Manual</em></li>
<li>[1.2] - <em>AVR Debugger</em></li>
<li>[1.3] - <em>AVR Simulator</em></li>
<li>[1.4] - <em>AVR Emulator</em></li>
<li>[1.5] - <em>Simulation des Übungsbeispiels</em></li>
</ul>
</li>
<li><strong>[2]</strong> - Grundlagen einer CPU
<ul>
<li>[2.1] - <em>Aufbau</em></li>
<li>[2.2] - <em>Speicherarten</em><br>
– [2.2.3] - <em>Flash</em><br>
– [2.2.4] - <em>SRAM - Static Random Access Memory</em><br>
– [2.2.5] - <em>DRAM - Dynamic Random Access Memory</em></li>
</ul>
</li>
<li><strong>[3]</strong> - Erklärung des Rückgabewertes beim Preprozessieren
<ul>
<li>[3.1] - <em>Type cast</em></li>
</ul>
</li>
</ul>
<h2 id="atmel-studio">[1] Atmel Studio</h2>
<p>[1.1] - <strong>Grundlagen</strong><br>
Das <strong>Atmel Studio</strong> ist eine kostenlose Entwicklungsumgebung (<a href="https://www.mikrocontroller.net/articles/Editoren/IDEs" title="Editoren/IDEs">IDE</a>) für die Programmierung der <a href="https://www.mikrocontroller.net/articles/AVR" title="AVR">AVR</a>-<a href="https://www.mikrocontroller.net/articles/Mikrocontroller" title="Mikrocontroller">Mikrocontroller</a> und <a href="https://www.mikrocontroller.net/articles/ARM" title="ARM">ARM</a>-<a href="https://www.mikrocontroller.net/articles/Mikrocontroller" title="Mikrocontroller">Mikrocontroller</a>  von Atmel. Sie basiert ab Version 5 auf der Visual Studio Shell von Microsoft und besteht aus einer Projektverwaltung, einem Editor, einem Debugger und Werkzeugen zum Beschreiben der Mikrocontroller.</p>
<hr>
<p><img src="http://micrium.com/wp-content/uploads/2012/08/Atmel-Logo.png" alt="enter image description here"></p>
<p><a href="https://www.microchip.com/mplab/avr-support/atmel-studio-7">— OFFICIAL PAGE —</a><br>
| ATMEL STUDIO-Windows (web installer)-[v7.0] <a href="http://studio.download.atmel.com/7.0.1931/as-installer-7.0.1931-web.exe">Mirror</a> |<br>
| ATMEL STUDIO-Windows (offline installer)-[v7.0] <a href="http://studio.download.atmel.com/7.0.1931/as-installer-7.0.1931-full.exe">Mirror</a> |</p>
<hr>
<p>Mit dem Atmel Studio kann in Assembler sowie in C/C++ programmiert werden. Für die Unterstützung von C/C++ musste bis einschließlich Version 4 vor der Installation des AVR Studio der GNU C Compiler für AVRs WinAVR installiert werden. Ab AVR Studio 5 ist eine vollständige Toolchain zur Entwicklung von C-Projekten enthalten.</p>
<p>[1.1.1] - <strong>Grundlagen</strong><br>
Im <strong><a href="http://ww1.microchip.com/downloads/en/devicedoc/atmel-0856-avr-instruction-set-manual.pdf">Instruction Set Manual</a></strong> werden alle verfügbaren Befehlsmuster beschrieben und erklärt.</p>
<hr>
<p>[1.2] - <strong>AVR Debugger</strong><br>
Die Atmel-Studio-Umgebung sieht unabhängig von der speziellen Debug-Plattform größtenteils identisch aus. Es existieren folgende Debug-Möglichkeiten:</p>
<ol>
<li>AVR Simulator</li>
<li>AVR In-Circuit Emulator</li>
</ol>
<hr>
<p>[1.3] - <strong>AVR Simulator</strong></p>
<ul>
<li>die meisten AVR-Mikrocontroller werden unterstützt</li>
<li>z.T langsamer als eine Emulation (insbesondere bei größeren Projekten)</li>
<li>Wechselwirkung mit Peripherie nur über vordefinierte Stimuli möglich</li>
<li>Anzeige aller Register zu jeder Zeit möglich</li>
</ul>
<hr>
<p>[1.4] - <strong>AVR Emulator</strong></p>
<ul>
<li>Unterstützung von Mikrocontrollern plattformabhängig eingeschränkt</li>
<li>z.T. schneller als Simulation</li>
<li>Debugging in tatsächlicher Hardwareumgebung</li>
<li>Register nicht uneingeschränkt lesbar</li>
</ul>
<hr>
<p>[1.5] - <strong>Simulation des Übungsbeispiels</strong><br>
Um das Prinzip der AVR-Software zu verstehen wurde ein einfaches Programm geschrieben, welches einfach 0 als Rückgabewert zurück gibt.<br>
Das C-Programm der 1. Übung sieht wie folgt aus:</p>
<pre><code>#include &lt;avr/io.h&gt;
    int main(void)
    {
        return 0;
    }  
</code></pre>
<p><strong>Disassemblierung des Programmes:</strong></p>
<pre><code>--- N:\ftp\hooks\data-with-backup\simulated\windows\Users\Vollmaier\Alois\Shared\Documents\Atmel Studio\7.0\BoardProject1_Gcc__Uebung\Project\Debug/../src/main.c
int main(void){
	return 0;
}
0000003D  LDI R24,0x00		Load immediate
0000003E  LDI R25,0x00		Load immediate
0000003F  RET 		Subroutine return
</code></pre>
<p>Die beiden Register mit dem Namen <code>R24</code> und <code>R25</code> werden für diesen Rückgabewert verwendet. Mit <code>LDI´R24, R25</code> wird in beide Register eine 0 geschrieben, somit ist der Rückgabewert des Programms 0.</p>
<p>Danach wurde ein Programm geschrieben welches eine LED am PORTB des Arduino Nano steuert:</p>
<pre><code>#include &lt;avr/io.h&gt;
int main()
{
DDBR =0x20;
PORTB =0x20;
return 0;
}
</code></pre>
<p><strong>Startup Routine:</strong></p>
<ul>
<li>R1 wird auf 0 gesetzt</li>
<li>Die Statusflags werden zurückgesetzt</li>
<li>Der Stack-Pointer wird inizialisiert</li>
<li>Ein Spring zum eigentlichen Programm wird ausgeführt</li>
</ul>
<hr>
<p><strong>Übersicht</strong> der <strong>wichtigsten Maschinenbefehle</strong> die im Unterricht erklärt wurden:</p>
<ol>
<li><strong>Transportbefehle</strong></li>
</ol>
<blockquote>
<pre><code>  Lade Register A aus m            Load           LDA m 
  Speichere Register A in m        Store          STA m 
  Transportiere von m2 nach m1     Move           MOV m1,m2 
  Lade 0 in Register A             Clear          CLRA
</code></pre>
</blockquote>
<ol start="2">
<li><strong>Ein-/Ausgabebefehle</strong></li>
</ol>
<blockquote>
<pre><code>  Lade A vom Kanal (Port) n        Input          IN A,n 
  Gib A aus auf Kanal (Port) n     Output         OUT A,n
</code></pre>
</blockquote>
<ol start="3">
<li><strong>Arithmetische Befehle</strong></li>
</ol>
<blockquote>
<pre><code>  Addiere Speicherinhalt zu A      Add            ADDA m 
  Subtrahiere Speicherinhalt von A Subtract       SUBA m 
  Multipliziere A mit m            Multiply       MULA m 
  Erhöhe A um 1                    Increment      INCA 
  Vermindere A um 1                Decrement      DECA
</code></pre>
</blockquote>
<ol start="4">
<li><strong>Sprungbefehle</strong></li>
</ol>
<blockquote>
<p><code>Unbedingter Sprung Jump JMP adr</code></p>
</blockquote>
<hr>
<h2 id="grundlagen-einer-cpu">[2] Grundlagen einer CPU</h2>
<p>[2.1] - <strong>Aufbau</strong><br>
Der Prozessor, abgekürzt auch <strong>CPU</strong> (<strong>Central Processing Unit</strong>) bezeichnet, ist das <strong>Herzstück</strong> <strong>eines jeden Computers</strong>, ohne ihn kann kein Rechner funktionieren.</p>
<p>Aufgaben einer CPU:</p>
<ol>
<li>Einbringen von Daten und Befehlen in den Mikroprozessor</li>
<li>Bearbeiten (verändern) der Daten</li>
<li>Ausgabe der Daten aus dem Mikroprozessor<br>
<img src="https://img.picload.org/image/dcllprii/cpu_svg.png" alt="enter image description here"><br>
Quelle: FIV-Skriptum <a href="https://lms.at/dotlrn/classes/digi/610437.4AHME_FIV.18_19/xolrn/EC743ABCF7AB5.symlink?resource_id=0-300238136&amp;m=view#188315330">Mirror</a></li>
</ol>
<p>Man kann ein Prozessor in vier Bereiche unterteilen:</p>
<ol>
<li>
<p>Der <strong>erste</strong> der vier Bereiche dient zur <strong>Bearbeitung von Daten</strong> und besteht aus der <strong>ALU</strong> und den <strong>Datenregistern</strong>.<br>
Er wird Datenwerk genannt.</p>
</li>
<li>
<p>Der <strong>zweite</strong> der vier Bereiche dient der <strong>Adressberechnung</strong> und besteht aus dem <strong>Befehlszähler</strong> und dem Adressregistern.<br>
<em>Er wird Adresswerk genannt.</em></p>
</li>
<li>
<p>Der <strong>dritte</strong> der vier Bereiche dient der <strong>Befehlsausführung</strong> und besteht aus dem <strong>Befehlsregister</strong> und dem <strong>Befehlsdekodierer</strong>, mit dem alle Bausteine über Steuerleitungen angeschlossen sind.<br>
<em>Er wird Steuerwerk genannt.</em></p>
</li>
<li>
<p>Der <strong>vierte</strong> der vier Bereiche dient der <strong>Busbehandlung</strong> des Prozessors diesen Busbehandlung wird gesorgt dass alle ankommende Signale korrekt und fehlerfrei in die CPU übernommen oder nach außen gegeben werden.</p>
</li>
</ol>
<p>Ein Prozessor besteht aus einer arithmetisch-logischen Einheit in Verbindung mit einem Zähler und einem Satz von Registern, die alle Daten des Prozessors aufnehmen:</p>
<p><strong>-   Datenregister</strong><br>
<strong>-   Adressregister</strong><br>
<strong>-   Befehlsregister</strong><br>
<strong>-   Befehlszähler</strong></p>
<p>Ein Prozessor hat einen <strong>schnellen Zwischenspeicher</strong>, dieser nennt man  <em>Register</em>. In diesem Zwischenspeicher werden Zahlenwerte eingetragen die auch wieder entnommen werden können. Der Prozessor kann wesentlich schneller auf den Register zugreifen als auf die Speicherzelle.  <em>Befehlssatz</em>  ist die Gesamtheit der Befehle die ein Prozessor ausführen kann. Diese Befehlen lassen sich in Klasse einteilen</p>
<ul>
<li><strong>_Speicher-Operationen</strong>:_ Diese Operationen ermöglichen den Datenaustausch zwischen den verschiedenen Registern und dem Hauptspeicher.</li>
<li><strong>_Arithmetische Operationen</strong>:_ Der Prozessor führt Operationen wie Addition oder Subtraktion aus.</li>
<li><strong>_Logische Operationen</strong>:_  Boolesche Operationen zum logischen Verknüpfen von Daten.</li>
<li><strong>_Sprungoperationen</strong>:_ Ermöglichen Verzweigungen in Programmen. Es gibt zwei Arten von Sprüngen: unbedingte Sprünge und bedingte Sprünge an Adressen.</li>
</ul>
<p>[2.2] - <strong>Speicherarten</strong><br>
Grundsätzlich unterscheiden wir aus Sicht des Programmierers Arbeitsspeicher und Programmspeicher.
Im Programmspeicher ist das eigentliche Programm, also die Maschinenbefehle, zu finden. Der Arbeitsspeicher wird während der Ausführung des Programmes (während der Arbeit) für Variable, Rücksprungadressen, ... benötigt.
<p>[2.2.1] - <strong>Der Flash</strong></p>
<p>Flash-Speicher bzw. Flash-Memory kombiniert die Vorteile von Halbleiterspeicher und Festplatten. Wie jeder andere Halbleiterspeicher kommt Flash-Speicher ohne bewegliche Teile aus. Und die Daten bleiben wie bei einer Festplatte auch nach dem Abschalten der Energieversorgung erhalten.<br>
Der Flash-Speicher hat sich aus dem EEPROM (Electrical Erasable and Programmable Read Only Memory) entwickelt.</p>
<h4 id="vorteile-von-flash-speicher">Vorteile von Flash-Speicher</h4>
<ul>
<li>Die gespeicherten Daten bleiben auch bei fehlender Versorgungsspannung erhalten. Auf eine Erhaltungsladung kann verzichtet werden. Somit ist auch der Energieverbrauch und die Wärmeentwicklung geringer.</li>
<li>Wegen fehlender beweglicher Teile ist Flash geräuschlos, unempfindlich gegen Erschütterungen und magnetische Felder.</li>
<li>Im Vergleich zu Festplatten haben Flash-Speicher eine sehr kurze Zugriffszeit. Lese- und Schreibgeschwindigkeit sind über den gesamten Speicherbereich weitestgehend konstant.</li>
<li>Die erreichbare Speichergröße ist durch die einfache und platzsparende Anordnung der Speicherzellen nach oben offen.</li>
</ul>
<h4 id="nachteile-von-flash-speicher">Nachteile von Flash-Speicher</h4>
<ul>
<li>begrenzte Schreib- bzw. Löschvorgänge</li>
<li>begrenzte Speicherkapazität</li>
<li>hoher Preis</li>
</ul>
<p>[2.2.2] - <strong>SRAM - Static Random Access Memory</strong></p>
<p>SRAM ist ein statischer Halbleiterspeicher, was bedeutet, dass der Speicherinhalt mittels Flip-Flops gespeichert wird und so nach dem Abruf des Speicherinhaltes erhalten bleibt. Dadurch ist der Stromverbrauch sehr hoch, was aber zu einem schnellen Arbeiten innerhalb des Speichers führt.<br>
Aufgrund seines hohen Preises und des großen Stromverbrauchs wird SRAM nur als Cache- oder Pufferspeicher mit geringen Kapazitäten verwendet.</p>
<ul>
<li>Speicherung erfolgt in Flip-Flops</li>
<li>sehr schnell</li>
<li>kein Refresh nötig</li>
<li>hoher Stromverbrauch</li>
<li>Einsatz als L1-, L2- und L3-Cache</li>
</ul>
<p>[2.2.3] - <strong>DRAM - Dynamic Random Access Memory</strong></p>
<p>DRAM ist der einfachste und billigste Speicher. Im Computer-Bereich ist DRAM als Arbeitsspeicher bzw. Hauptspeicher der bevorzugte Halbleiterspeicher, den es in verschiedensten Varianten und Weiterentwicklungen gibt. Heute ist der SDRAM der am weitesten verbreitete Halbleiterspeicher in der Computertechnik. Es gibt zwar auch noch andere Typen, wie zum Beispiel FRAM oder MRAM, die in der Computertechnik aber nur eine geringe Rolle spielen und in Spezialsystemen vorkommen.</p>
<ul>
<li>Kondensator als Speicherelement</li>
<li>Speicherhaltung durch Refresh der Speicherzellen</li>
<li>langsam</li>
<li>geringer Stromverbrauch</li>
<li>Einsatz als Arbeitsspeicher oder Hauptspeicher</li>
</ul>
<p>Eine DRAM-Speicherzelle besteht aus einem Transistor und einem Kondensator (1T1C), der das eigentliche Speicherelement ist. In einer DRAM-Speicherzelle wird ein Bit durch die Ladung des Kondensators gespeichert. Die Messung der Spannung am Speicherkondensator (Lesen) und dessen anschließende Aufladung (Schreiben) benötigen eine gewisse Zeit.</p>
<h2 id="erklärung-des-rückgabewertes-beim-preprozessieren">[3] Erklärung des Rückgabewertes beim Preprozessieren</h2>
<p>Beim Preprozessierungsvorgang unseres Programmes gab es einen Rückgabewert welcher in der Einheit analysiert wurde.<br>
Es war herauszufinden was <strong>volatile</strong> bezweckt.</p>
<pre><code>(*(volatile uint8_t*)((0x05)+(0x20)) = 0x20;
</code></pre>
<p>Der Operator <strong>volatile</strong> sagt dem Compiler, dass der Inhalt einer Variablen sich außerhalb des normalen Programmflusses ändern kann. Das kann zum Beispiel dann passieren, wenn ein Programm aus einer Interrupt-Service-Routine einen Wert erwartet und dann über diesen Wert einfach pollt (kein schönes Verhalten, aber gut zum Erklären von volatile).<br>
[3.1] - <strong>Type cast</strong></p>
<p><code>(volatile uint8_t*)</code>  → Type cast</p>
<ul>
<li>Datentypen in C sind Systemabhängig<br>
Um so Etwas zu vermeiden gibt es folgenden Trick:</li>
</ul>
<p>char c= 3;<br>
int x= (int) c;<br>
main.c</p>
<p>Das ist eine sogenannte Datentypumwandlung</p>
<ul>
<li><code>(int)</code>  -&gt; Wird in diesem Zusammenhang  <strong>Type cast</strong>  genannt</li>
</ul>

