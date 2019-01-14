#include <stdio.h>
#include "lcd.h"

void logLcd(struct LcdTyp typ) {
	printf("logLcd: %s %d\n", typ.hersteller, typ.sn);
}

void logMain(char text[]) {
	printf("logMain: %s\n", text);
}
