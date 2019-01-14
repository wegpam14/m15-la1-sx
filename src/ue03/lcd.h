#ifndef LCD_H
#define LCD_H

struct LcdTyp init();
void show(char text[]);

struct LcdTyp {
	int sn;
	char hersteller[20];
};
#endif
