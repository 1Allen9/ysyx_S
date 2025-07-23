CFLAGS = -Wall -g -I src

#SRC = $(wildcard *.c src/*.c )
SRC = $(wildcard *.c  src/*.c test/*.c)
OBJ = $(SRC:%.c=%.o)

TARGET = ex32

${TARGET}: ${OBJ}
	cc ${CFLAGS} $^ -o $@


.PHONY:clean

clean:
	rm -f ${TARGET} ${OBJ}


print:
	echo ${SRC}
	echo ${OBJ}
