#include <stdio.h>
#include <string.h>
#include <ctype.h>

// forward declarations
void print_letters(int len, char arg[]);

void print_arguments(int argc, char *argv[])
{
	int i = 0;
	int len = strlen(argv[i]);
	for(i = 0; i < argc; i++)
	{
		len = strlen(argv[i]);
		print_letters(len, argv[i]);
	}
}

void print_letters(int len, char arg[])
{
	int i = 0;

	for(i = 0; i <= len; i++)
	{
		char ch = arg[i];

//		if(can_print_it(ch))
		if( isalpha( arg[i]) || isblank( arg[i] ) )
		//if( isalnum(arg[i]) )
		{
			printf("'%c' == %d ", ch, ch);
		}
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	//printf("len = %ld.\n", strlen("len"));
	print_arguments(argc, argv);
	return 0;
}

