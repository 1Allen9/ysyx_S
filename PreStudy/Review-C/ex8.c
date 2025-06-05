#include <stdio.h>

	char full_name[] = {
		'Z', 'e', 'd',
		' ', 'A', '.', ' ',
		'S', 'h', 'a', 'w'
	};
int main(int argc, char *argv[])
{
	int areas[] = {10, 12, 13, 14, 20};
	char name[] = "Zed";
//	char full_name[] = {
//		'Z', 'e', 'd',
//		' ', 'A', '.', ' ',
//		'S', 'h', 'a', 'w' 
		//'S', 'h', 'a', 'w', '\0'
//	};

	//WARNING: On some systems you may have to change the 
	// %ld in this code to a %u since it will use unsigned ints
	printf("The size of an int: %ld\n", sizeof(int));
	printf("The size of areas (int[]): %ld\n",
			sizeof(areas) );
	printf("The number of ints in areas: %ld\n",
			sizeof(areas) / sizeof(int));
	printf("The first area is %d, the 2nd %d.\n",
			areas[10], areas[1]);
			//areas[0], areas[1]);

	printf("The size of a char: %ld\n", sizeof(char));
	printf("The size of name (char[]): %ld\n",
			sizeof(name));
	printf("The size of chars: %ld\n",
			sizeof(name) / sizeof(char));

	printf("The size of full_name (char[]): %ld\n",
			sizeof(full_name));
	printf("The number of chars: %ld\n",
			sizeof(full_name) / sizeof(char));

	printf("name=\"%s\" and full_name=\"%s\"\n",
			name, full_name);

	printf("------- make it broken -----------\n");
	printf("Access name[10]: %c \n", name[10]);
	printf("int name[4]: %d \n", name[4]);
	printf("Access full_name[20]: %c \n", full_name[20]);
	areas[0] = 100;
	areas[4] = 400;
	printf("\n After areas[0] = 100; area[0]=%d\n", areas[0]);
	printf("After areas[4] = 100; area[4]=%d\n", areas[4]);
	name[1] = '@';
	full_name[10] = '^';
	printf("After assignment, name[1]=%c, name=%s\n", name[1], name);
	printf("After assignment, full_name[10]=%c, full_name=%s\n",
			full_name[10], full_name);
	areas[0] = name[0];
	printf("\nPut name[0] to areas[0], than areas[0]=%d(int), %c(char)\n",
			areas[0], areas[0]);
	return 0;
}

