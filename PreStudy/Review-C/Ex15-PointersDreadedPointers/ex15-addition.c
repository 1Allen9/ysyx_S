#include <stdio.h>

void PrintFunc(char *name, int *age)
{
	printf("%s is %d years old.\n",
			name, *age);
}

int main(int argc, char *argv[])
{
	//print the command arguments
	int cnt = argc;
	for(cnt = 0; cnt < argc; cnt++)
	{
		printf("No.%d arg is: %s\n", cnt, *(argv+cnt));
	}
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
	
	printf("**********************************\n");
	printf("******** use array ********\n");
	printf("**********************************\n");
	// first way using indexing
	for(i = 0; i < count; i++)
	{
		//printf("%s has %d years alive.\n",
		//		names[i], ages[i]);
		PrintFunc(names[i], ages + i);
	}

	printf("---------- first end\n");

	// setup the pointers to the start of the arrays
	int *cur_age = ages;
	char **cur_name = names;

	// second way using pointers
	for(i = 0; i < count; i++)
	{
		//printf("%s is %d years old.\n",
		//		(cur_name[i]), (cur_age[i]) );
		PrintFunc( *(cur_name+i), cur_age + i);
	}

	printf("------- second end\n");

	// third way, pointers are just arrays
	for(i = 0; i < count; i++)
	{
		//printf("%s is %d years old again.\n",
		//		cur_name[i], cur_age[i]);
		PrintFunc( cur_name[i], cur_age + i);
	}

	printf("------- third end\n");

	// fourth way with pointers in a stupid complex way
	for(cur_name = names, cur_age = ages;
			(cur_age - ages) < count;
			cur_name++, cur_age++)
	{
		//printf("%s lived %d years so far.\n",
		//		*cur_name, *cur_age);
		PrintFunc( *cur_name, cur_age);
	}



	printf("**********************************\n");
	printf("******** use pointer ********\n");
	printf("**********************************\n");
	// first way using indexing
	for(i = 0; i < count; i++)
	{
		printf("%s has %d years alive.\n",
				*(names+i), *(ages+i));
	}

	printf("----------\n");

	// setup the pointers to the start of the arrays
	cur_age = ages;
	cur_name = names;

	// second way using pointers
	for(i = 0; i < count; i++)
	{
		printf("%s is %d years old.\n",
				//(cur_name[i]), (cur_age[i]) );
				*(cur_name+i), *(cur_age+i));
	}

	printf("-------\n");

	// third way, pointers are just arrays
	for(i = 0; i < count; i++)
	{
		printf("%s is %d years old again.\n",
				*(cur_name+i), *(cur_age+i));
				//cur_name[i], cur_age[i]);
	}

	printf("-------\n");

	// fourth way with pointers in a stupid complex way
	for(cur_name = names, cur_age = ages;
			(cur_age - ages) < count;
			cur_name++, cur_age++)
	{
		printf("%s lived %d years so far.\n",
				*cur_name, *cur_age);
	}
	
	printf("========= use while loop =======\n");
	cur_name = names; 
	cur_age = ages;
	while( (cur_age - ages) < count )
	{
		printf("%s lived %d years so far.\n",
				*cur_name, *cur_age);
		cur_name++;
		cur_age++;
	}
		
	printf("************** print addres *********\n");
	for(i = 0; i < count; i++)
	{
		printf("ages val = %d, address = %p\n",
				*(ages + i), (ages + i) );
		printf("names val = %s, address = %p\n",
				*(names + i), (names + i) );
	}

	return 0;
}

