CFLAGS = -Wall -g

TARGET = ex15
OBJ = ${TARGET} broken addition

${TARGET}: ex15.c
	cc ${CFLAGS} $^ -o $@

broken: *bro*.c
	cc ${CFLAGS} $^ -o $@

addition: *add*.c
	cc ${CFLAGS} $^ -o $@

clean:
	rm -f ${OBJ}
