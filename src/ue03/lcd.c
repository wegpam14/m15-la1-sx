#include <stdio.h>
#include "lcd.h"
#include "log.h"

struct LcdTyp init() {
	printf("lcd.c init() aufgerufen\n");
	struct LcdTyp rv = {123456, "Irgendwas"};
	logLcd(rv);
	return rv;
}


void show (char s[]) {
	printf("lcd.c show %s\n", s);
}
