#include <stdio.h>
#include "lcd.h"
#include "log.h"

//Expliziete Deklaration von Funktionen
//void init();
//void show(char tect [] );

int main () {

	struct LcdTyp typ = init();
	logMain("Programm gestartet");
	printf("Nr: %d, Hersteller: %s", typ.sn, typ.hersteller);
	printf("Hallo\n");
	show("Guten Morgen\n");

	return 0;
}
