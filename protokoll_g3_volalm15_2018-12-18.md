---


---

<h1 id="protokoll-nr.-06--">Protokoll Nr. 06  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/30/HTL_Kaindorf_Logo.svg/300px-HTL_Kaindorf_Logo.svg.png" alt=""></h1>
<p>Übungsdatum: <strong>18.12.2018</strong><br>
Name: Vollmaier Alois<br>
KNr.: 14 Klasse: 4AHME<br>
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
<li><strong>[1]</strong> - Modbus
<ul>
<li>[3.1] - <em>Wie funktioniert Modbus?</em></li>
<li>[3.2] - <em>Modbus - ASCII</em></li>
<li>[3.3] - <em>Modbus - TCP</em></li>
<li>[3.4] - <em>Modbus - RTU</em></li>
</ul>
</li>
</ul>
<h2 id="modbus">[1] Modbus</h2>
<p>Bei Modbus handelt es sich um ein Kommunikationsprotokoll, welches den <strong>Datenaustausch</strong> zwischen einem <strong>Master</strong> und <strong>mehreren Slaves</strong> ermöglicht.<br>
Das <strong>offene Protokoll</strong> gehört heutzutage zum <strong>Industriestandard</strong> für die Verbindung von Computern mit Mess- und Regelsystemen.</p>
<p>siehe auch <a href="https://lms.at/dotlrn/classes/htl_elektrotechnik/610437.4AHME_LA1SX.18_19/xolrn/2148F16AC6F2E.symlink?resource_id=0-333368687&amp;m=view#167572556">Skript Modbus</a> von DI Manfred Steiner<br>
siehe auch folgende offizielle Dokumente:</p>
<ul>
<li><a href="http://www.modbus.org/docs/Modbus_Application_Protocol_V1_1b3.pdf">Modbus Application Protocol</a></li>
<li><a href="http://www.modbus.org/docs/Modbus_over_serial_line_V1_02.pdf">Modbus Over Serial Line</a></li>
<li><a href="http://www.modbus.org/docs/Modbus_Messaging_Implementation_Guide_V1_0b.pdf">Modbus Messaging Implementation Guide</a></li>
</ul>
<h3 id="wie-funktioniert-modbus">[1.1] - <strong>Wie funktioniert Modbus?</strong></h3>
<p>Die prinzipielle Funktionsweise des Protokolls ist <strong>simpel</strong>. Das Informationsprotokoll sorgt dafür, dass ein <strong>Master-Gerät</strong> (hierbei handelt es sich zumeist um einen Computer) und ein oder mehrere <strong>Slave-Geräte</strong> miteinander verbunden werden. So lassen sich zum Beispiel verschiedene Messgeräte durch einen Computer steuern, bzw. können Daten zurück an diesen übertragen werden.</p>
<p>Die Datenübertragung funktioniert dabei über drei verschiedene Wege, <strong>ASCII</strong>, <strong>RTU</strong> und <strong>TCP</strong>, welche sich für <strong>unterschiedliche Zwecke</strong> eignen. Die Übertragungssysteme können entweder <strong>Ethernet</strong> sein oder die etwas ältere Variante der <strong>seriellen</strong> <strong>Verbindung</strong>.</p>
<h3 id="modbus-ascii">[1.2] - <strong>Modbus ASCII</strong></h3>
<p>Dieser Modus zeichnet sich vor allem dadurch aus, dass er <strong>anstatt im Binär-Code</strong> zu übertragen, seine Daten <strong>in ASCII sendet</strong>, so dass sie von Menschen gelesen werden können.</p>
<p>Dies ist bei dem Senden von binär verschlüsselten Codes wesentlich schwieriger zu bewerkstelligen. <strong>Der Aufbau des Codes ist immer gleich</strong>:</p>
<p>Die Nachricht beginnt mit einem Doppelpunkt, gefolgt von der Adresse des Empfängers (in ASCII). Danach wird der auszuführende Befehl dargestellt, woraufhin die eigentliche Nachricht folgt. Diese kann in der Länge variieren. Zur Fehlerprüfung wird ein sogenannter LRC-Befehl angehängt. Jede ASCII-Nachricht endet mit den Zeichen CRLF.</p>

<table>
<thead>
<tr>
<th align="center">Start</th>
<th align="center">Adresse</th>
<th align="center">Funktion</th>
<th align="center">Daten</th>
<th align="center">LCR</th>
<th>Ende</th>
</tr>
</thead>
<tbody>
<tr>
<td align="center">Zeichenanzahl</td>
<td align="center">2 Zeichen (:)</td>
<td align="center">2 Zeichen</td>
<td align="center">n Zeichen</td>
<td align="center">2 Zeichen</td>
<td>2 Zeichen (CRLF)</td>
</tr>
</tbody>
</table><p><strong>Standartmäßig werden  nur 7 Daten-Bits verwendet!<br>
Eine Abänderung des Übertragungsprotokolles ist immer möglich! Grund: OPEN SOURCE</strong></p>
<p><img src="https://lh3.googleusercontent.com/oXf93FG7f49IL8FFqhGlDwtn8rDdTnHm_7rXPu1lqiuQPKavAFmnJrB6MVkjN7YbfkeeeWyDDl6r=s1920" alt="enter image description here"></p>
<hr>
<h3 id="modbus-ascii-anhand-eines-beispieles-zur-datenübertragung"><strong>Modbus ASCII</strong> anhand eines Beispieles zur Datenübertragung:</h3>
<blockquote>
<p>:01  04  0000  0001 __  &lt;[CR]&gt;&lt;[LF]&gt;</p>
</blockquote>
<ol>
<li>:01 Start mit Doppelpunkt &amp; Adresse des Geräts</li>
<li>Function Code <em>04</em></li>
<li>Input Rey Adresse 1-&gt;0000</li>
<li>Anzahl der Input Register</li>
<li>LRC/CRC Prüfsumme</li>
<li>&lt;[CR]&gt;&lt;[LF]&gt;</li>
</ol>
<p>Am Ende sollte sich durch die Übertragung über Modbus folgendes Muster bilden, welches durch ein Oszilloskop ersichtlich wird:</p>
<p><img src="http://www.simplymodbus.ca/images/volts.gif" alt="enter image description here"></p>
<p>Die Daten werden als Reihe von Einsen und Nullen also Bits gesendet. Eine typische Übertragungsgeschwindigkeit beträgt <strong>9600 Baud (Bits pro Sekunde)</strong></p>
<h4 id="wie-wird-die-prüfsummelrc-gebildet">Wie wird die Prüfsumme(LRC) gebildet?</h4>
<p>Anhand eines Beispieles bilden wir nun die Prüfsumme</p>
<blockquote>
<p><strong>:0401000A000868</strong></p>
</blockquote>
<p>Übertragen werden folgende Bytes:</p>
<p>0x3a <strong>0x30 0x34 0x30 0x31 0x30 x030 0x30 0x41 0x30 0x30 0x30 0x38</strong> 0x36 0x38 0x0d 0x0a</p>
<p>Die Summe aller fett geschriebenen Bytes als 8-Bit Addition ohne Berücksichtigung des Überlaufs ergibt: <strong>0x98</strong></p>
<p><strong>Das Zweierkomplement ergibt: 0xff-0x98+1 = 0x68</strong></p>
<h3 id="modbus-tcpip">[1.3] - <strong>Modbus TCP/IP</strong></h3>
<p>Dieser <strong>Modus</strong> ist speziell für das Ethernet gedacht. Er ist dem RTU-Modus sehr ähnlich, da auch er in binären Codes sendet, allerdings müssen bei TCP-<strong>Modbus</strong> <strong>keine Kontrollbytes</strong> berechnet werden, so dass die Handhabung und Implementierung von TCP-Treibern einfacher zu bewerkstelligen sind.</p>
<p>Der Aufbau des Protokolls unterscheidet sich allerdings ein wenig vom Aufbau der RTU-Codes.</p>
<p>Am Start jeder TCP-Nachricht steht die Transaktionsnummer, welche 2 Byte groß ist. Darauf folgt das Protokollzeichen. Dieses hat immer den gleichen Aufbau: 0x0000. Danach kommen die Zahl der noch folgenden Bytes sowie die Adresse und das Funktionsfeld.</p>
<p>Am Ende der Nachricht stehen dann die Daten, welche immer unterschiedlich groß sind, je nach Länge der Nachricht.</p>
<h3 id="modbus-rtu">[1.4] - <strong>Modbus RTU</strong></h3>
<p>Der sogenannte Remote Terminal Unit Modus sendet im Gegensatz zum ASCII-Modus <strong>binäre Codes</strong>, welche vom Menschen nicht einfach lesbar sind. Allerdings ist der <strong>Datendurchsatz</strong> bei dieser Methode <strong>weitaus besser</strong>.</p>
<p>Jeder Modbus RTU Code fängt mit einer <strong>mindestens 3,5 Zeichen langen Pause an</strong>, variiert jedoch mit der Übertragungsgeschwindigkeit.</p>
<p>Danach folgen die Adresse des Empfängers, welche in 8 Bit dargestellt wird sowie der Funktionscode, welcher ebenfalls aus 8 Bit besteht.<br>
Bei Fehlern kommt es zu Codeänderungen. Überprüft wird die ganze Nachricht via CRC.<br>
Das Ende einer jeden RTU-Nachricht wird durch eine weitere Wartezeit von <strong>mindestens 3,5 Zeichen</strong> gekennzeichnet.</p>

<table>
<thead>
<tr>
<th align="center">Start</th>
<th align="center">Adresse</th>
<th align="center">Funktion</th>
<th align="center">CR-Check</th>
<th align="center">Ende</th>
</tr>
</thead>
<tbody>
<tr>
<td align="center">Wartezeit1</td>
<td align="center">Byte1</td>
<td align="center">Byten</td>
<td align="center">Byte2</td>
<td align="center">ByteWartezeit</td>
</tr>
</tbody>
</table><hr>
<h3 id="bildung-des-function-codes">Bildung des Function Codes:</h3>
<p>Der Function-Code in einem Modbus-Frame <strong>definiert</strong> die <strong>Bedeutung des Frames</strong>.<br>
Im Modbus-Datenmodell werden 4 Adressräume beschrieben:</p>
<ul>
<li><strong>Discrete Inputs</strong><br>
Ein  <em>Discrete Input</em>  ist ein einzelnes Bit, das nur gelesen werden kann.<br>
Beispiele: ein Taster, ein Endschalter, …</li>
<li><strong>Coils</strong><br>
Eine  <em>Coil</em>  ist ein Bit das gelesen und beschrieben werden kann.<br>
Der Name stammt vermutlich von der Spule eines Relais.<br>
Beispiele: ein Relais, eine LED, …</li>
<li><strong>Input Registers</strong><br>
Ein  <em>Input-Register</em>  ist ein 16-Bit Wert der nur gelesen werden kann.<br>
Beispiele: ein Temperatursensor, ein ADC, die Geräte-ID, …</li>
<li><strong>Hold-Registers</strong><br>
Ein  <em>Hold-Register</em>  ist ein 16-Bit Wert der gelesen und beschrieben werden kann.<br>
Beispiele: PWM-Einheit, DAC, …</li>
</ul>
<p><strong>Nachfolgend eine Übersicht alles Function Codes:</strong></p>

<table>
<thead>
<tr>
<th>Function-Code</th>
<th>Hex</th>
<th>Subcode</th>
<th>Name</th>
<th>Typ</th>
</tr>
</thead>
<tbody>
<tr>
<td>1</td>
<td>01</td>
<td></td>
<td>Read Coils</td>
<td>Bit</td>
</tr>
<tr>
<td>2</td>
<td>02</td>
<td></td>
<td>Read Dicrete Inputs</td>
<td>Bit</td>
</tr>
<tr>
<td>3</td>
<td>03</td>
<td></td>
<td>Read Holding Registers</td>
<td>16-Bit</td>
</tr>
<tr>
<td>4</td>
<td>04</td>
<td></td>
<td>Read Input Register</td>
<td>16-Bit</td>
</tr>
<tr>
<td>5</td>
<td>05</td>
<td></td>
<td>Write Single Coil</td>
<td>Bit</td>
</tr>
<tr>
<td>6</td>
<td>06</td>
<td></td>
<td>Write Single Register</td>
<td>16-Bit</td>
</tr>
<tr>
<td>7</td>
<td>07</td>
<td></td>
<td>Read Exception Status</td>
<td>Diagnose</td>
</tr>
<tr>
<td>8</td>
<td>08</td>
<td>0-18,20</td>
<td>Diagnostic</td>
<td>Diagnose</td>
</tr>
<tr>
<td>11</td>
<td>0B</td>
<td></td>
<td>Get Com event counter</td>
<td>Diagnose</td>
</tr>
<tr>
<td>12</td>
<td>0C</td>
<td></td>
<td>Get Com Event Log</td>
<td>Diagnose</td>
</tr>
<tr>
<td>15</td>
<td>0F</td>
<td></td>
<td>Write Multiple Coils</td>
<td>Bit</td>
</tr>
<tr>
<td>16</td>
<td>10</td>
<td></td>
<td>Write Multiple Registers</td>
<td>16-Bit</td>
</tr>
<tr>
<td>17</td>
<td>11</td>
<td></td>
<td>Report Server ID</td>
<td>Diagnose</td>
</tr>
<tr>
<td>20</td>
<td>14</td>
<td></td>
<td>Read File record</td>
<td>File record access</td>
</tr>
<tr>
<td>21</td>
<td>15</td>
<td></td>
<td>Write File record</td>
<td>File record access</td>
</tr>
<tr>
<td>22</td>
<td>16</td>
<td></td>
<td>Mask Write Register</td>
<td>16-Bit</td>
</tr>
<tr>
<td>23</td>
<td>17</td>
<td></td>
<td>Read/Write Multiple Registers</td>
<td>16-Bit</td>
</tr>
<tr>
<td>24</td>
<td>18</td>
<td></td>
<td>Read FIFO queue</td>
<td>16-Bit</td>
</tr>
<tr>
<td>43</td>
<td>2B</td>
<td>14</td>
<td>Read device Identification</td>
<td>Diagnose</td>
</tr>
<tr>
<td>43</td>
<td>2B</td>
<td>13,14</td>
<td>Encapsulated Interface Transport</td>
<td></td>
</tr>
<tr>
<td>43</td>
<td>2B</td>
<td>13</td>
<td>CANopen General Reference</td>
<td></td>
</tr>
</tbody>
</table><p>*Anhand dieser Grundlagen kann im nächsten Schritt unser Temperatursensor auf dem Chip des Atmega 328P angesteuert und ausgelesen werden.</p>
<h2 id="modbus-1">[2] Modbus</h2>
<p>Nach dem erlernen der Grundlagen war das Ziel dieser Stunde, eine funktionstüchtige Temperaturmesseinheit zu realisieren. Verwendet wurde dazu der integrierte Temperatursensor des Atmega 328p des Arduino Nano Boards. Siehe <a href="http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf">Datenblatt</a></p>
<p>Die meisten neuen AVR-Chips verfügen über einen internen Temperatursensor. Es wird nicht oft verwendet, da er nicht genau ist. Es gibt jedoch eine Reihe von Situationen, in denen dieser Sensor eingesetzt werden kann.</p>
<p><strong>Beliebte AVR-Chips, die über einen internen Temperatursensor verfügen:</strong></p>
<p>ATmega8 : <strong>Nein</strong><br>
ATmega8L : <strong>Nein</strong><br>
ATmega8A : <strong>Nein</strong><br>
ATmega168 : <strong>Nein</strong><br>
ATmega168A : <strong>Ja</strong><br>
ATmega168P : <strong>Ja</strong><br>
ATmega328 : <strong>Ja</strong><br>
ATmega328P : <strong>Ja</strong><br>
ATmega1280 (Arduino Mega) : <strong>Nein</strong><br>
ATmega2560 (Arduino Mega 2560) : <strong>Nein</strong><br>
ATmega32U4 (Arduino Leonardo) : <strong>Ja</strong></p>
<p><strong>Verwendung</strong><br>
Die Innentemperatur ist die Temperatur im Inneren des Chips, genau wie die CPU-Temperatur eines Computers. Wenn der Arduino nicht schläft, steigt diese Temperatur. Wenn Ausgangspins zur Stromzufuhr verwendet werden (z.B. zur Ansteuerung einer LED), steigt die Innentemperatur weiter an.</p>
<p>Diese Innentemperatur kann nicht zum Ablesen der Umgebungstemperatur verwendet werden.</p>
<p>Die Umgebungstemperatur kann gemessen werden, wenn der Arduino eingeschaltet wird, aber nur, wenn der Arduino länger als 10 Minuten ausgeschaltet war.</p>
<p>In Situationen mit hohen Temperaturen könnte eine kalibrierte Temperaturmessung Schäden vermeiden. Die meisten neueren AVR-Chips haben einen Temperaturbereich von bis zu 85 Grad Celsius. Mit dem Arduino kann das Gerät ausgeschaltet oder bei 80 Grad Celsius selbst ausgeschaltet werden.</p>
<p><strong>Genauigkeit</strong><br>
Laut Datenblatt kann die Temperatur um 10 Grad Celsius fallen. Aber eine Genauigkeit von etwa 2 Grad Celsius ist möglich, wenn Verstärkung und Offset gemessen werden.</p>
<p>Für genaue Temperaturen sollte jeder Chip kalibriert werden. Wenn einige Arduinos des gleichen Typs verwendet werden, kann sich der interne Temperatursensor dennoch unterscheiden.</p>
<p>Verstärkung und Offset<br>
Die Verstärkung und der Offset sind für die verschiedenen Typen unterschiedlich. Es ist auch bei älteren und neueren Chips anders.</p>
<p>Benutzen Sie dies, um mit den ATmega328-Typen zu beginnen (Temperatur in Grad Celsius):</p>
<p><strong>Temperatur = (ADCW - 324.31) / 1.22</strong></p>
<h3 id="programm-code">[1.1] - <strong>Programm-Code?</strong></h3>
<p><strong>Beschreibung des Programmes</strong><br>
Der Analog-Digital-Wandler wandelt eine analoge Eingangsspannung durch succsessive Approximation in einen 10-bit Digitalwert. Der kleinste Wert enstpricht GND, der maximale Wert entspricht der ausgewählten Referenzspannung minus ein LSB.</p>
<p>Die Referenzspannung für den Analog-Digital-Wandler kann durch die Bits <strong>REFS1</strong> und <strong>REFS0</strong> im <strong>ADMUX</strong>-Register ausgewählt werden, die Referenzspannung liegt dann auch am AVCC Pin an. Möglich sind VCC oder die interne Referenzspannung von <strong>2,56V</strong>.</p>
<p>Der Analog-Digital-Wandler erzeugt ein 10-bit Ergebnis, das in den ADC Data Registern <strong>ADCH</strong> und <strong>ADCL</strong> abgelegt wird. Normalerweise wird das Ergebnis rechtsbündig in den beiden Registern abgelegt, optional kann das Ergebnis aber auch linksbündig in <strong>ADCH</strong> und <strong>ADCL</strong> geschrieben werden. Die Einstellung erfolgt mit dem ADLAR-Bit im <strong>ADMUX</strong>-Register.</p>
<p>Zuerst wurden diese Register des ADC’s initialisiert und der app.modbus.frameIndex auf -1 gesetzt um in einen Idle Zustand zu gehen.</p>
<p>Im nächsten Schritt wird der linksbündige Wert des ADCH Registers in eine Zwischenvariable gespeichert und der ADC gestartet indem das ADCH Register gesetzt wird.</p>
<p>Am Ende erfolgt noch die Übertragung des Temperaturwertes auf di Konsole des PC’s.</p>
<h3 id="app.c">app.c</h3>
<pre class=" language-c"><code class="prism  language-c"><span class="token keyword">void</span> <span class="token function">app_init</span> <span class="token punctuation">(</span><span class="token keyword">void</span><span class="token punctuation">)</span>

<span class="token punctuation">{</span>

<span class="token function">memset</span><span class="token punctuation">(</span><span class="token punctuation">(</span><span class="token keyword">void</span> <span class="token operator">*</span><span class="token punctuation">)</span><span class="token operator">&amp;</span>app<span class="token punctuation">,</span> <span class="token number">0</span><span class="token punctuation">,</span> <span class="token keyword">sizeof</span><span class="token punctuation">(</span>app<span class="token punctuation">)</span><span class="token punctuation">)</span><span class="token punctuation">;</span>

ADMUX <span class="token operator">=</span> <span class="token punctuation">(</span><span class="token number">1</span> <span class="token operator">&lt;&lt;</span> REFS1<span class="token punctuation">)</span> <span class="token operator">|</span> <span class="token punctuation">(</span><span class="token number">1</span><span class="token operator">&lt;&lt;</span> REFS0<span class="token punctuation">)</span> <span class="token operator">|</span> <span class="token punctuation">(</span> <span class="token number">1</span><span class="token operator">&lt;&lt;</span> ADLAR<span class="token punctuation">)</span> <span class="token operator">|</span> <span class="token number">0x08</span><span class="token punctuation">;</span>

ADCSRA <span class="token operator">=</span> <span class="token punctuation">(</span><span class="token number">1</span><span class="token operator">&lt;&lt;</span> ADEN<span class="token punctuation">)</span> <span class="token operator">|</span> <span class="token number">7</span><span class="token punctuation">;</span> <span class="token comment">// 7 bedeutet durch 128, dass sind 125 kHz</span>

app<span class="token punctuation">.</span>modbus<span class="token punctuation">.</span>frameIndex <span class="token operator">=</span> <span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">;</span>

<span class="token punctuation">}</span>

<span class="token keyword">void</span> <span class="token function">app_task_16ms</span> <span class="token punctuation">(</span><span class="token keyword">void</span><span class="token punctuation">)</span> <span class="token punctuation">{</span>

app<span class="token punctuation">.</span>adch <span class="token operator">=</span> ADCH<span class="token punctuation">;</span>

ADCSRA <span class="token operator">|</span><span class="token operator">=</span> <span class="token punctuation">(</span><span class="token number">1</span><span class="token operator">&lt;&lt;</span> ADSC<span class="token punctuation">)</span><span class="token punctuation">;</span> <span class="token comment">//Starte ADC</span>

<span class="token punctuation">}</span>

<span class="token keyword">void</span> <span class="token function">app_handleUartByte</span><span class="token punctuation">(</span><span class="token keyword">char</span> c<span class="token punctuation">)</span><span class="token punctuation">{</span>

<span class="token keyword">struct</span> Modbus <span class="token operator">*</span>p <span class="token operator">=</span> <span class="token operator">&amp;</span>app<span class="token punctuation">.</span>modbus<span class="token punctuation">;</span>

<span class="token keyword">if</span> <span class="token punctuation">(</span>p <span class="token operator">-&gt;</span>frameIndex <span class="token operator">&lt;</span> <span class="token number">0</span><span class="token punctuation">)</span>

<span class="token punctuation">{</span>

<span class="token keyword">return</span><span class="token punctuation">;</span>

<span class="token punctuation">}</span>

<span class="token keyword">if</span><span class="token punctuation">(</span> c <span class="token operator">==</span> <span class="token string">':'</span><span class="token punctuation">)</span><span class="token punctuation">{</span>

p <span class="token operator">-&gt;</span>frameIndex <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">;</span>

p<span class="token operator">-&gt;</span>frameError <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">;</span>

<span class="token punctuation">}</span>

<span class="token keyword">else</span> <span class="token keyword">if</span> <span class="token punctuation">(</span> c <span class="token operator">==</span> <span class="token string">'\n'</span><span class="token punctuation">)</span><span class="token punctuation">{</span>

<span class="token keyword">if</span> <span class="token punctuation">(</span>p<span class="token operator">-&gt;</span>frameError <span class="token operator">==</span> <span class="token number">0</span><span class="token punctuation">)</span><span class="token punctuation">{</span>

<span class="token function">app_parseModbusFrame</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span>

<span class="token punctuation">}</span>

<span class="token punctuation">}</span>

<span class="token keyword">else</span> <span class="token keyword">if</span> <span class="token punctuation">(</span>p <span class="token operator">-&gt;</span>frameIndex <span class="token operator">&lt;</span> <span class="token number">16</span><span class="token punctuation">)</span><span class="token punctuation">{</span>

p <span class="token operator">-&gt;</span>frameIndex <span class="token punctuation">[</span>p <span class="token operator">-&gt;</span>frameIndex<span class="token punctuation">]</span> <span class="token operator">=</span> c<span class="token punctuation">;</span>

<span class="token punctuation">}</span>

<span class="token keyword">else</span> <span class="token keyword">if</span> <span class="token punctuation">(</span>p <span class="token operator">-&gt;</span> errCnt <span class="token operator">==</span> <span class="token number">0</span><span class="token punctuation">)</span>

<span class="token punctuation">{</span>

p<span class="token operator">-&gt;</span>frameError <span class="token operator">=</span> <span class="token number">1</span><span class="token punctuation">;</span>

<span class="token keyword">if</span><span class="token punctuation">(</span>p<span class="token operator">-&gt;</span>errCnt <span class="token operator">&lt;</span> <span class="token number">0xffff</span><span class="token punctuation">)</span><span class="token punctuation">{</span>

p<span class="token operator">-&gt;</span> errCnt<span class="token operator">++</span><span class="token punctuation">;</span>

<span class="token punctuation">}</span>

<span class="token punctuation">}</span>

<span class="token punctuation">}</span>

</code></pre>
<h3 id="app.h">app.h</h3>
<pre class=" language-c"><code class="prism  language-c"><span class="token keyword">struct</span> Modbus <span class="token comment">// Struktur um alle Komponenten</span>

<span class="token punctuation">{</span>

<span class="token keyword">char</span> frame<span class="token punctuation">[</span><span class="token number">16</span><span class="token punctuation">]</span><span class="token punctuation">;</span>

int8_t frameIndex<span class="token punctuation">;</span>

uint16_t frameError<span class="token punctuation">;</span>

uint16_t errCnt<span class="token punctuation">;</span>

<span class="token punctuation">}</span><span class="token punctuation">;</span>

<span class="token keyword">struct</span> App

<span class="token punctuation">{</span>

uint8_t adch<span class="token punctuation">;</span>

<span class="token keyword">struct</span> Modbus modbus<span class="token punctuation">;</span>

<span class="token punctuation">}</span><span class="token punctuation">;</span>
</code></pre>
<h3 id="sys.c">sys.c</h3>
<pre class=" language-c"><code class="prism  language-c"><span class="token function">ISR</span> <span class="token punctuation">(</span>SYS_UART_RECEIVE_VECTOR<span class="token punctuation">)</span>

<span class="token punctuation">{</span>

<span class="token keyword">static</span> uint8_t lastChar<span class="token punctuation">;</span>

uint8_t c <span class="token operator">=</span> SYS_UDR<span class="token punctuation">;</span>

<span class="token keyword">if</span> <span class="token punctuation">(</span>c<span class="token operator">==</span><span class="token string">'R'</span> <span class="token operator">&amp;&amp;</span> lastChar<span class="token operator">==</span><span class="token string">'@'</span><span class="token punctuation">)</span>

<span class="token punctuation">{</span>

<span class="token function">wdt_enable</span><span class="token punctuation">(</span>WDTO_15MS<span class="token punctuation">)</span><span class="token punctuation">;</span>

<span class="token function">wdt_reset</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span>

<span class="token keyword">while</span><span class="token punctuation">(</span><span class="token number">1</span><span class="token punctuation">)</span> <span class="token punctuation">{</span><span class="token punctuation">}</span><span class="token punctuation">;</span>

<span class="token punctuation">}</span>

lastChar <span class="token operator">=</span> c<span class="token punctuation">;</span>

<span class="token function">app_handleUartByte</span><span class="token punctuation">(</span>c<span class="token punctuation">)</span><span class="token punctuation">;</span>
</code></pre>

