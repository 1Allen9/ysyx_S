#include <stdio.h>

int main()
{
//	int age; 
	int age = 10;
	int height = 72;

	printf("I am %3d years old.\n", age);
	printf("I am %3d years old.use \\r a the end.\r", age);
	////////	Broken CODE		////////
	//printf("I am %d years old.\n",); //broken code
	//printf("I am %3d years old.\n" age);
	//printf("I am  years old.\n", age);
	printf("I am %04d inches tall.\n", height);
	printf("12345678-------- split line --------\n");
	printf("\t:Use \\t at the begining. I am %04d inches tall.\n", height);
	printf("Use\t\\t after \"Use\". I am %04d inches tall.\n", height);

	return 0;
}

