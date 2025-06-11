#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	//go though each string in argv

	int i = argc - 1;
	while(i >= 0)
	{
		printf("arg %d: %s\n", i, argv[i]);
		i--;
	}

	// let's make our own array of strings
	//char *states[] = 
	char states[][50] = 
	{
		"California", "Oregon",
		"Washington", "Texas"
	};

	int num_states = 4;
	i = 0; // watch for this
	while(i < num_states)
	{
		printf("init state %d: %s\n", i, states[i]);
		i++;
	}

	i = 0;
	while(i < num_states)
	//while(i < argc)
	{
		//strcpy(states[i], argv[i]);
		*states[i] = *argv[i];
		//states[i] = argv[i];
		printf("copy argv to states, then states %d is: %s\n", i, states[i]);
		i++;
	}

	return 0;
}


