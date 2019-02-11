# Protokoll  
**Datum:** 5.2.2019  
**Gruppe:** 2  
**Abwesend:** -  
  
## Inhalt  
1. Kernel  
2. Übungsbeispiel  
  
## Kernel  
Ein [Kernel](https://de.wikipedia.org/wiki/Kernel_(Betriebssystem)) ist der zentrale Bestandteil eines Betriebssystems. In ihm ist die Prozess- und Datenorganisation festgelegt, auf der alle weiteren Softwarebestandteile des Betriebssystems aufbauen. Er bildet die innerste Softwareschicht des Systems und hat direkten Zugriff auf die Hardware.  
  
## Aufgaben des Kernels   
**Ein Betriebssystem-Kernel hat die folgenden Aufgaben:**  
  
1. Schnittstelle zu Anwenderprogrammen (Starten, Beenden, Ein-/Ausgabe, Speicherzugriff)  
1. Kontrolle des Zugriffs auf Prozessor, Geräte, Speicher (Scheduler, Gerätetreiber, Speicherschutz). Möglichst alleiniger Zugriff des Kernels auf diese Ressourcen.  
1. Verteilung der Ressourcen wie zum Beispiel der Prozessorzeit bzw. der Prozessoren auf die Anwenderprogramme.  
1. Strukturierung der Ressourcen, etwa Abbildung von Dateisystemen auf blockorientierte Geräte wie Festplattenlaufwerke, Netzwerkstack auf Netzwerkkarten.  
1. Auflösung von Zugriffskonflikten, etwa Verriegelung bei Mehrprozessorsystemen, Warteschlangen bei knappen Ressourcen.
1. Virtualisierung der Ressourcen (Prozessor: Prozesse, Festplatte: Dateien, Netzwerkkarte: z. B. Sockets, Speicher: virtueller Speicher, Geräte: Spezialdateien).  
1. Überwachung von Zugriffsrechten auf Dateien und Geräte bei Mehrbenutzersystemen.  
  
## Kernelmodul  
Ein Kernel-Modul ist ein spezielles Programm, das im laufenden Betrieb in den Kernel eines Betriebssystems geladen und wieder daraus entfernt werden kann.  
  
Kernel-Module werden häufig für Gerätetreiber verwendet, da eine große Auswahl der Module für die unterschiedlichsten Hardware-Komponenten mit dem Betriebssystem mitgeliefert werden können, aber nur die wirklich benötigten Treiber in den Speicher geladen werden müssen.  
  
