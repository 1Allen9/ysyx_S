CFLAGS = -Wall -g -D NDEBUG

TARGET = ex20
OBJ := ${TARGET} addition
#HEAD := *.h

${TARGET}: ex20.c dbg.h
	cc ${CFLAGS} -U NDEBUG $^ -o $@

addition: ex20-a*.c dbg-addition.h
	cc ${CFLAGS} $^ -o $@

clean:
	rm -f ${OBJ}
