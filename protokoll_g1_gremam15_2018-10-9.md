### 1. Protokoll
Name: **Grebien Markus**  
Klasse: **4AHME**  
Knr: **3**  


**Inhaltsverzeichnis**
 1. Versionsverwaltungssysteme
	 * Systeme
	 * Aufbau
	 * Wichtige Befehle
 2. Markdown
---

1.  ### Versionsverwaltungssysteme
	1. #### Systeme:
		1. ##### [CVS][cvs_link]
			* Gehöhrt zu den ersten Versionsverwaltungssystemen
			* Wurde 1963 gegründed und die aktuellste version wurde 2008 veröffentlicht.
		2. ##### [SVN](svn_link)
			* Wurde 2004 veröffentlicht
			* Ist immer noch ein aktives Versionsverwaltungssystem
		3. ##### [Git](git_link)
			* Wurde 2005 von Linus Torvalds entwickelt.
			* Er hat als erstes auch ein Lokales Repository hinzugefügt, damit man auch ohne Internetverbindung arbeiten konnte
	
	2. #### Aufbau
		1. Es gibt vier Hauptbetsantteile:
			* Workspace
				* Hier befinded sich die IDE mit dem Programmcode.
			* index
				* Die geänderten Dateien befinden sich nach dem "adden" hier.
			* local repository
				* Um sie bereit zu machen, bringt man sie danach einmal hier her
			* remote repository
				* Ist der Server, der Weltweit erreichbr ist.
		2. Die wichtigsten befehle:
			* `git add` um vom workspace in den index zu kommen
			* `git commit` um vom index ins local reopsitory zu kommen
			* `git push` damit alle änderungen hochgeladen werden
			* `git pull` um alle änderungen vom remote repository in den workspace zu transverrieren

1. ### [Markdown][markdown_link]
	1. Wurde 2004 entwickelt
	2. ist eine art von Textdatei, die sich aber das Ziel gesetzt hat, einen Text einfach zu formatieren und trotzdem schön lesbar zu halten. 
	3. Aufgrund der vielen formatierungen gibt es eine [Seite mit allen Befehlen][markdown_cheatsheet] und einen [Markdown Editor][markdown_editor].



[cvs_link]: https://savannah.nongnu.org/project/memberlist.php?detailed=1&group=cvs
[svn_link]: https://subversion.apache.org/
[git_link]: https://github.com/
[markdown_link]: https://de.wikipedia.org/wiki/Markdown
[markdown_cheatsheet]: https://github.com/adam-p/markdown-here/wiki/Markdown-Here-Cheatsheet
[markdown_editor]: https://stackedit.io/
