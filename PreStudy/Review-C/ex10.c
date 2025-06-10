#include <stdio.h> 

int main(int argc, char *argv[])
{
	int i = 0;

	// go through each string in argv
	// why am I skipping argv[0]?
	printf("argc: %d, argv[0]: %s\n",argc, argv[0]);
	for(i = 1; i < argc; i++)
	{
		printf("arg %d: %s\n", i, argv[i]);
	}

	// let's make our own array of strings
	char *states[] = 
	{
		"California", "Oregon",
		NULL, "Texas"
	};
	int num_states = 4;

	for(i = 0; i < num_states; i++)
	{
		printf("state %d: %s\n", i, states[i]);
	}

	printf("--------- append --------------\n");
	printf("What kind of code can put in \"for\"?\n");
	int num = 0;
	for(i = 0, num = 6, printf("test\n"); (i < 2) & (num > 0); i++, num--)
	{
		
		printf("i=%d \n", i);
		printf("num=%d \n", num);
	}

	printf("Set argv/states before printing\n");
	argv[1] = states[1];
	states[2] = argv[2];
	printf("argv[1]=%s, states[2]=%s\n", argv[1], states[2]);

	return 0;
}

