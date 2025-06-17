CFLAGS = -Wall -g

TARGET = ex17
OBJ = ${TARGET} broken addition

${TARGET}: ex17.c
	cc ${CFLAGS} $^ -o $@

broken: ex17-b*.c
	cc ${CFLAGS} $^ -o $@

addition: ex17-a*.c
	cc ${CFLAGS} $^ -o $@

clean:
	rm -f ${OBJ} vgcore.*

