#include <stdio.h>

int main(int argc, char *argv[])
{
	int numbers[4] = {0};
	char name[4] = {'a'};

	// first, print them out raw
	printf("numbers: %d %d %d %d\n",
			numbers[0], numbers[1],
			numbers[2], numbers[3]);

	printf("name each: %c %c %c %c\n",
			name[0], name[1],
			name[2], name[3]);

	printf("name: %s\n", name);

	// setup the numbers
	numbers[0] = 'A';
	numbers[1] = 'B';
	numbers[2] = 'c';
	numbers[3] = 'D';


	// setup the name
	name[0] = 100;
	name[1] = 101;
	name[2] = 103;
	name[3] = '\n';

	//then print them out initialized
	printf("print numbers as char: %c %c %c %c\n",
    		numbers[0], numbers[1],
    		numbers[2], numbers[3]);

    printf("print name eadh as int: %d %d %d %d\n",
    		name[0], name[1],
    		name[2], name[3]);
    //print the name link a string
    printf("name: %s\n", name);

	// another way to use name
	char *another = "Zed";
	//&name = "Fuk";
	char another_name[4] = "fnk";
	printf("another: %s\n", another);
	printf("use name as *point: %s\n", another_name);

	printf("another each: %c %c %c %c\n",
			another[0], another[1],
			another[2], another[3]);

	return 0;
}

