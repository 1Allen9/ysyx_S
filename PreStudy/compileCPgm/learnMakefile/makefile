CC = gcc # Flag for implict rules
CFLAGS = -g # Flag for implict rules. Turn on debug info

goal := makeCpgm


$(goal): $(SRC) $(HEAD)
	gcc $(SRC) -o $@

SRC := $(wildcard *.c)
HEAD := $(wildcard *.h)

# $(target): $(SRC) $(HEAD)
# 	cc $(target) -o $(SRC)
checkfile:
	@echo "src file: $(SRC)"
	@echo "head file: $(HEAD)"


clean:
	rm -f $(goal) 
