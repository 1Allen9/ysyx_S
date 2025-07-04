#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
	char *name;
	//char *name;
	int age;
	int height;
	int weight;
};

struct Person Person_create(char *name, int age, int height, int weight)
{
	struct Person who;
	assert(&who != NULL);

//	who.name = strdup(name);
	who.name = name;
	who.age = age;
	who.height = height;
	who.weight = weight;

	return who;
}
/*struct Person *Person_create(char *name, int age, int height, int weight)
{
	struct Person *who = malloc( sizeof(struct Person) );
	assert(who != NULL);

	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who;
}*/

void Person_destroy(struct Person *who)
{
	assert(who != NULL);

	free(who->name);
	free(who);
}

void Person_print(struct Person who)
{
	printf("Name: %s\n", who.name);
	printf("\tAge: %d\n", who.age);
	printf("\tHeight: %d\n", who.height);
	printf("\tWeight: %d\n", who.weight);
}

int main(int argc, char *argv[])
{
	// make two people structures
//	struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
//	struct Person *frank = Person_create("Frank Blank", 20, 72, 180);
	struct Person joe;
	struct Person frank;
	struct Person neo;
	
	joe = Person_create("Joe Alex", 32, 64, 140);
	frank = Person_create("Frank Blank", 20, 72, 180);
	neo = Person_create("Neo Q", 22, 60, 111);
/*
	joe.name = "Joe Alex";
	joe.age = 32;
	joe.height = 64;
	joe.weight = 140;
	

	frank.name = "Frank Blank";
	frank.age = 20;
	frank.height = 72;
	frank.weight = 180;
*/
	
	// print them out and where they are in memory
	printf("Joe is at memory lacation %p:\n", &joe);
	Person_print(joe);

	printf("Frank is at memory lacation %p:\n", &frank);
	Person_print(frank);

	printf("Neo is at memory lacation %p: and not use pointer\n", &neo);
	Person_print(neo);

	// make everyone age 20 years and print them again
	joe.age += 20;
	joe.height -= 2;
	joe.weight += 40;
	Person_print(joe);

	frank.age += 20;
	frank.weight += 20;
	Person_print(frank);
	//Person_destroy(joe);
	//Person_destroy(frank);
	return 0;
}


