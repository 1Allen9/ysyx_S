CFLAGS = -Wall -g

TARGET = ex18
OBJ = ${TARGET} broken addition merge_sort

${TARGET}: ex18.c
	cc ${CFLAGS} $^ -o $@

broken: ex18-b*.c
	cc ${CFLAGS} $^ -o $@

addition: ex18-a*.c
	cc ${CFLAGS} $^ -o $@

all: ${OBJ}

run_addition:
	make addition
	valgrind -q --leak-check=full ./addition 4 7 2 3 1 0 8

merge_sort: merge_sort.c
	cc ${CFLAGS} $^ -o $@


clean:
	rm -f ${OBJ} vgcore.*



