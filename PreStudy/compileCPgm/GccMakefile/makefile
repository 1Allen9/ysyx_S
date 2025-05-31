target := main
obj := *.o
src := *.c
head := *.h

$(target): $(obj)
	gcc -Wall -g $(obj) -o main

# %.o : %.c 
%.o : %.c $(head)
	gcc -Wall -g -c $^


clean:
	rm *.o $(target) *.gch
