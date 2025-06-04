#include <stdio.h>

int main(int argc, char *argv[])
{
	int distance = 100;
	float power = 2.345f;
	double super_power = 56789.4532;
	char initial = 'A';
	char first_name[] = "Zed";
	char last_name[] = "Shaw";
	char empty_c[] = "";

	printf("You are %03d miles away.\n", distance);
	printf("You are %*3d miles away.\n", distance);
	printf("You are %x miles away.(hex)\n", distance);
	printf("You are 0x%05X miles away.(hex)\n", distance);
	printf("You are %o miles away.(Oct)\n", distance);
	printf("You are %06o miles away.(Oct)\n", distance);
	printf("You have %f levels of power.\n", power);
	printf("You have %6.8f levels of power.\n", power);
	printf("You have %f awesome super power.\n", super_power);
	printf("You have %6.9f awesome super power.\n", super_power);
	printf("I have an initial %c.\n", initial);
	printf("I have a first name %s.\n", first_name);
	printf("I have a last name %s.\n", last_name);
	printf("My whole name is %s %c. %s.\n", 
			//initial, first_name, last_name);
			first_name, initial, last_name);
	printf("print a empty string %s.\n", empty_c);
	//printf("print a empty string %c.\n", empty_c);

	return 0;
}
	
