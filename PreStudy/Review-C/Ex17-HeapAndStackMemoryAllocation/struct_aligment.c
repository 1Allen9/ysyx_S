#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

struct Address
{
	double d;
	int id;
	int set;
	char name[20];
	char email[50];
};

struct Database
{
	char c;
	int rows_size;
	int char_size;
	struct Address rows[10];
};

struct Connection
{
	int *p;
	FILE *file;
	struct Database *db;
};

int main(void)
{
	FILE *fp;
	printf("size of Address: %ld\n", sizeof( struct Address) );
	printf("size of Database: %ld\n", sizeof( struct Database) );
	printf("size of Connection: %ld\n", sizeof( struct Connection) );
	printf("size of FILE * : %ld\n", sizeof(fp) );
	printf("size of *db : %ld\n", sizeof(struct Database *) );
	printf("size of *int : %ld\n", sizeof(int *) );
}

