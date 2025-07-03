CFLAGS = -Wall -g -D NDEBUG

TARGET = ex20
OBJ := ${TARGET} addition
HEAD := *.h

${TARGET}: ex20.c ${HEAD}
	cc ${CFLAGS} $^ -o $@

addition: ex20-a*.c ${HEAD}
	cc ${CFLAGS} $^ -o $@

clean:
	rm -f ${OBJ}
