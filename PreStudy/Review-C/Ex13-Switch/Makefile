CFLAGS = -Wall -g

TARGET = ex13
OBJ = ${TARGET} broken addition

#all: ${TARGET} broken addition

${TARGET}: ex13.c
	cc ${CFLAGS} $^ -o $@

broken: ex13-b*.c
	cc ${CFLAGS} $^ -o $@

addition: ex13-a*.c
	cc ${CFLAGS} $^ -o $@


all: ${TARGET} broken addition

clean:
	rm -f ${OBJ}
