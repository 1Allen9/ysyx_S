CFLAGS = -Wall -g

SRC = $(wildcard test[1-2].c)
OBJ = $(SRC:.c=.o)

#TARGET = main
#${TARGET}: ${OBJ}
#	echo ${SRC}
#	echo ${OBJ}
#	echo $^
#	cc ${CFLAGS} $^ -o $@
#
#${OBJ}: %.o: %.c
#	cc ${CFLAGS} -c $< -o $@

all = $(wildcard *func.c)
total_target = $(patsubst %func.c,%func.o,$(all))
${total_target}: %func.o: %func.c
	cc ${CFLAGS} -c $< -o $@


static_obj = test1.o test2.o test3.o
subst_str = $(subst ee, EE, feet on the street)

%.o: %.c
	cc ${CFLAGS} -c $< -o $@



print:
	echo ${total_target}
	echo ${all}
#	echo ${subst_str}
#	echo $(patsubst %.o, %.%6, $(static_obj))

clean:
	rm -f *.o
	rm -f ${TARGET}
