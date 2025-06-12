CFLAGS = -Wall -g

TARGET = ex12
OBJ = ${TARGET} broken addition


all: ${TARGET} broken addition

${TARGET}: ex12.c
	cc ${CFLAGS} ex12.c -o ${TARGET}

broken: ex12-b*.c
	cc ${CFLAGS} $^ -o $@

addition: ex12-add*.c
	cc ${CFLAGS} $^ -o $@


clean: 
	rm -f ${OBJ}
	@#rm -f ${TARGET} 
