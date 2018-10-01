# Protokoll Nr. 01  ![](https://upload.wikimedia.org/wikipedia/commons/thumb/3/30/HTL_Kaindorf_Logo.svg/300px-HTL_Kaindorf_Logo.svg.png) 
Übungsdatum: **18.09.2018**  
Name: Vollmaier Alois  
KNr.: 15 Klasse: 4AHME  
Gruppe: 3  

Anwesenheit:  

| Anwesend | Abwesend|
| ------------- |:-------------:|
| Vezonik, Vollmaier, Wesonig, Wegl, WinterM., WinterT.    | --- |

___
### Themen-Übersicht
 - **[1]**-VB-Installation sowie der HTL-Pakete
	 - [1.1] - *VirtualBox-Installation* 
	 - [1.2] - *HTL-Packete-Installation* 
 - **[2]** - Grundbegriffe
	 - [2.1] - *Versionsverwaltung* 
	 - [2.2] - *Virtualisierung* 
 - **[3]** - Git Data Transport
	  - [3.1] - *Commands* 

## [1] VB-Installation sowie der HTL-Pakete
[1.1] - **VirtualBox-Installation** 
Ein Desktop-Computer verfügt über die grundsätzlichen Voraussetzungen für den Einsatz von Virtualisierungstechnik. Dabei steht VirtualBox als eine Open-Source-Lösung für zahlreiche Plattformen zur  Verfügung.
___
![enter image description here](https://jselec.nl/wp-content/uploads/2017/03/Virtualbox-logo.png)  

[--- OFFICIAL PAGE ---](https://www.virtualbox.org)   
| VB-Windows-[v5.2.18] [Mirror](https://download.virtualbox.org/virtualbox/5.2.18/VirtualBox-5.2.18-124319-Win.exe) |  
| VB-Linux-[v5.2.18] [Mirror](https://www.virtualbox.org/wiki/Linux_Downloads) |  
| VB-ExtensionPack-AllPlatforms [Mirror](https://download.virtualbox.org/virtualbox/5.2.18/Oracle_VM_VirtualBox_Extension_Pack-5.2.18.vbox-extpack)|  
___
**-VirtualBox in Betrieb nehmen**  
Die Website von VirtualBox stellt sämtliche für die Installation des Tools benötigten Komponenten zum Download zur Verfügung. Die Einrichtung der globalen Einstellungen erfolgt beim ersten Start von VirtualBox in einem speziellen Manager.

**-Virtuelle Maschine einrichten**  
Die Erzeugung einer virtuellen Maschine erfolgt in VirtualBox über einen speziellen Assistenten. Der Benutzer wählt das Betriebssystem sowie die Größe des Arbeitsspeichers und die Festplatte aus. Anschließend dient das Tool dazu, zusätzliche Anzeigemodi zu installieren, Peripheriegeräte anzubinden sowie eine Netzwerkverbindung einzurichten.
___

[1.2] - **HTL-Packete-Installation**   
Durch die Installation der HTL Packete erhält man alle, für den Unterricht nötigen Programme.
Die Installation erfolgt durch die Eingabe der unten aufgelisteten Befehle im Terminal.

> sudo wget -O - http://www.htl-mechatronik.at/ubuntu-htl/install | sudo bash
> apt install htl

Source: [Mirror](http://htl-mechatronik.at/ubuntu-htl/readme)

## [2] Grundbegriffe
[2.1] - **Versionsverwaltung** 

Was ist eine Versionsverwaltung?
Häufig arbeiten mehrere Leute zusammen an einem Projekt. Um dabei die Übersicht zu behalten und die Änderungen der Einzelnen gut miteinander kombinieren zu können, wird in den allermeisten Fällen eine Versionsverwaltung (englisch: "Source-Code-Management-System") eingesetzt. 

Beispiele für kostenfreie Versionsverwaltungsprogramme:

 1. **[CVS](https://www.it-visions.de/glossar/alle/3298/Concurrent_Versions_System.aspx)**
 2. **[Subversion](https://www.it-visions.de/glossar/alle/3299/Subversion.aspx)**
 3. **[Git](https://www.it-visions.de/glossar/alle/7827/Git.aspx)**
 4. **Mercurial**

Beispiele für kommerzielle Versionsverwaltungsprogramme:

 1. **Perforce**
 2. **ClearCase**
 3. **[Team Foundation Server](https://www.it-visions.de/glossar/alle/3762/Team_Foundation_Server.aspx)  ([TFS](https://www.it-visions.de/glossar/alle/3762/Team_Foundation_Server.aspx))**
 4. **[Visual Studio Team Services](https://www.it-visions.de/glossar/alle/8439/Visual_Studio_Team_Services.aspx) ([](https://www.it-visions.de/glossar/alle/8439/Visual_Studio_Team_Services.aspx)[V](https://www.it-visions.de/glossar/alle/3067/Visual_Studio_Team_System.aspx)[STS](https://www.it-visions.de/glossar/alle/3596/Security_Token_Service.aspx))**
 ___
 [2.1] - **Virtualisierung**     
 
 Unter Virtualisierung versteht man die Bereitstellung von physikalischen Hardwareressourcen für virtuelle Maschinen. Dabei kann es sich um ein oder mehrere eigenständige Gastsysteme handeln.
 
 **Eigenschaften von virtuellen Systemen:**
 
 **Partitionierung**

-   Ausführen mehrerer Betriebssysteme auf einem einzigen physischen Computer
-   Aufteilen von Systemressourcen zwischen virtuellen Maschinen

**Isolation**

-   Fehler- und Sicherheitsisolation auf Hardwareebene
-   Erweiterte Ressourcensteuerung für gleichbleibende Performance

**Kapselung**

-   Speichern des gesamten VM-Zustands in Dateien
-   Unkompliziertes Verschieben und Kopieren von virtuellen Maschinen (so einfach wie von Dateien)

**Hardwareunabhängigkeit**

-   Bereitstellung oder Migration jeder virtuellen Maschine auf jedem beliebigen physischen Server
___
## [3] Git Data Transport
[2.1] - **Commands** 
 [![Transport Commands](http://assets.osteele.com/images/2008/git-transport.png)](http://blog.osteele.com/posts/2008/05/my-git-workflow/)  
 *Repository* klonen (also z.B. downloaden)
  ```bash
  git clone my_project.git
  ```
  Bei GitHub z.B.
  ```bash
  git clone git@github.com:username/my_project.git
  ```
  (Der *repository*-Link wird bei GitHub-*repositories* jeweils rechts angezeigt)



                

