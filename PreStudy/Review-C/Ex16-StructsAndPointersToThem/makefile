#CFLAGS = -Wall 
CFLAGS = -Wall -g

TARGET = ex16
OBJ = ${TARGET} broken addition

${TARGET}: ex16.c
	cc ${CFLAGS} $^ -o $@

broken: ex16-b*.c
	cc ${CFLAGS} $^ -o $@

addition: ex16-a*.c
	cc ${CFLAGS} $^ -o $@

clean:
	rm -f ${OBJ} vgcore.*

