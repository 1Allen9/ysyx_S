CFLAGS = -Wall -g

TARGET = ex14
OBJ = ${TARGET} broken addition

${TARGET}: ex14.c
	cc ${CFLAGS} $^ -o $@

broken: ex14-b*.c
	cc ${CFLAGS} $^ -o $@

addition: ex14-a*.c
	cc ${CFLAGS} $^ -o $@

clean:
	rm -f ${OBJ}

