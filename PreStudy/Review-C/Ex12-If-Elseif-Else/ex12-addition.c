#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;
	argc--;

	if(argc == 0)
	{
		printf("You have none argument. You fu_k.\n");
	}
	else if(argc == 1)
	{
		printf("You only have one argument. You suck.\n");
	}
	else if(argc > 1 && argc < 4)
	{
		printf("Here's your argument:\n");

		for(i = 1; i < argc + 1; i++)
		{
			printf("%s ", argv[i]);
		}
	}
	else
	{
		printf("You have too many arguments. You suck.\n");
	}

	return 0;
}

