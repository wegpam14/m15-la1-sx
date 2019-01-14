ue03: main.o lcd.o log.o
	gcc -o ue03 main.o lcd.o log.o

main.o: main.c lcd.h log.h
	gcc -c main.c

lcd.o: lcd.c lcd.h log.h
	gcc -c lcd.c

log.o: log.c log.h lcd.h
	gcc -c log.c

clean:
	echo "alles gelöscht"
	-rm *.o
	-rm ue03
