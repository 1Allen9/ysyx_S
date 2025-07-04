CFLAGS = -Wall -g -I header -I show


TARGET = main

${TARGET}: main.c display.c show.c Print.c Print.c
	cc ${CFLAGS}  $^ -o $@

clean:
	rm -f *.o ${TARGET}
