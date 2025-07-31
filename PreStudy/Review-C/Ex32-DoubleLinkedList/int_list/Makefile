CFLAGS = -Wall -g

TARGET = link_list

SRC = $(wildcard *.c)
HEAD = $(wildcard *.h)
OBJ = $(SRC:%.c=%.o)

${TARGET}: ${OBJ} ${HEAD}
	cc  ${CFLAGS} $^ -o $@

#${OBJ}: ${SRC}
#	cc ${CFALGS} -c $< -o $@

%.o:%.c
	cc ${CFLAGS} -c $^ -o $@

.PHONY: clean

clean:
	rm -f ${TARGET} ${OBJ} *core.*

print:
	echo ${SRC}
	echo ${OBJ}

