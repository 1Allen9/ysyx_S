#include <stdio.h>

int main(int argc, char *argv[])
{
	// create two arrays we care about
	int ages[] = {23, 43, 12, 89, 2};
	char *names[] = 
	{
		"Alan", "Frank",
		"Mary", "John", "Lisa"
	};

	// safely get the size of ages
	int count = sizeof(ages) / sizeof(int);
	int i = 0;

	// first way using indexing
	printf("backward print\n");
	for(i = count - 1; i >= 0; i--)
	{
		printf("%s has %d years alive.\n",
				names[i], ages[i]);
	}

	//printf("---------- cur_age -> names\n");
	printf("---------- backward 2ed \n");

	// setup the pointers to the start of the arrays
	//int *cur_age = (int *)names;
	int *cur_age = ages;
	char **cur_name = names;

	// second way using pointers
	//for(i = 0; i < count; i++)
	for(i = count - 1; i >= 0; i--)
	{
		printf("%s is %d years old.\n",
				*(cur_name+i), *(cur_age+i));
	}

	printf("------- backward 3rd\n");

	// third way, pointers are just arrays
	//for(i = 0; i < count; i++)
	for(i = count - 1; i >= 0; i--)
	{
		printf("%s is %d years old again.\n",
				cur_name[i], cur_age[i]);
	}

	printf("------- backward 4th\n");

	// fourth way with pointers in a stupid complex way
	for(cur_name = &names[count - 1], cur_age = &ages[count - 1];
			(cur_age - ages) >= 0;
			cur_name -= 1, cur_age -= 1)
			//cur_name++, cur_age++)
	{
		printf("%s lived %d years so far.\n",
				*cur_name, *cur_age);
	}

	return 0;
}

