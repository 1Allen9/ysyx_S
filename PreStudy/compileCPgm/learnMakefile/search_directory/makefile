CFLAGS = -Wall -g
INCLUDE = -I header -I src -I src/**/


TARGET = mainpro

#OBJ_DIR = .
#SRC_DIR = ./src
#SRC = $(wildcard $(SRC_DIR)/*.c)
#OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRC))

SRC = $(wildcard *.c src/*.c src/**/*.c)
OBJ = $(SRC:.c=.o)

${TARGET}: ${OBJ}
	cc ${CFLAGS} $^ -o $@


%.o: %.c
	cc ${CFLAGS} ${INCLUDE} -c $< -o $@


clean:
	rm -f *.o ./**/*.o
	rm -f ${TARGET}

print:
	echo ${OBJ}
	echo ${SRC}
