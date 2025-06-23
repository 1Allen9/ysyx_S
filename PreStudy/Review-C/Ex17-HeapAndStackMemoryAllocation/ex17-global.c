#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

int g_max_data = MAX_DATA;
int g_max_rows = MAX_ROWS;

struct Address 
{
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
	char gender[MAX_DATA];
};

struct Database
{
	int rows_size;
	int char_size;
	struct Address rows[MAX_ROWS];
};

struct Connection
{
	FILE *file;
	struct Database *db;
};
struct Connection g_conn;

void Database_close();

void die(const char *message)
{
	if(errno)
	{
		perror(message);
	}
	else
	{
		printf("ERROR :%s\n", message);
	}

	Database_close();
	exit(1);
}

void Address_print(struct Address *addr)
{
	printf("%d %s %s %s\n",
			addr->id, addr->name, addr->email, addr->gender);
}

void Database_load(void)
{
	int rc = fread(g_conn.db, sizeof(struct Database), 1, g_conn.file);
	if(rc != 1) die("Failed to load database.");
}

struct Connection *Database_open(const char *filename, char mode)
{
	// g_conn = malloc(sizeof(struct Connection));
	// if(!g_conn) die("Memory error");

	// g_conn->db = malloc(sizeof(struct Database));
	// if(!g_conn->db) die("Memory error");
	
	g_conn.db = malloc(sizeof (struct Database));
	if(mode == 'c')
	{
		g_conn.file = fopen(filename, "w");
	}
	else
	{
		g_conn.file = fopen(filename, "r+");

		if(g_conn.file)
		{
			Database_load();
		}
	}
	
	if(!g_conn.file) die("Failed to open the file");

	return &g_conn;
}

void Database_close(void)
{
	// if(g_conn)
	{
		if(g_conn.file) fclose(g_conn.file);
		if(g_conn.db) free(g_conn.db);
		// free(g_conn);
	}
}

void Database_write(void)
{
	rewind(g_conn.file);

	int rc = fwrite(g_conn.db, sizeof(struct Database), 1, g_conn.file);
	if(rc != 1) die("Failed to write database.");

	rc = fflush(g_conn.file);
	if(rc == -1) die("Cannot flust database.");
}


void Database_create(void)
{
	int i = 0;

	for(i = 0; i < MAX_ROWS; i++)
	{
		// make a prototype to initialize it
		struct Address addr = {.id = i, .set = 0};
		// then just assign it
		g_conn.db->rows[i] = addr;
		g_conn.db->rows_size = g_max_rows;
		g_conn.db->char_size = g_max_data;
	}
}

void Database_set(int id, const char *name, const char *email, char *gender)
{
	struct Address *addr = &g_conn.db->rows[id];
	if(addr->set) die("Already set, delete it first");

	addr->set = 1;
	g_max_data = g_conn.db->char_size;
	g_max_rows = g_conn.db->rows_size;
	// WARNING: bug, read thw "How To Break It" and fix this
	//char *res = strncpy(addr->name, name, MAX_DATA);
	char *res = strncpy(addr->name, name, g_max_data);
	// demostrate the strncpy bug
	if(!res) die("Name copy failed");
	addr->name[g_max_data - 1] = '\0';

	res = strncpy(addr->email, email, g_max_data);
	if(!res) die("Email copy failed");
	addr->email[g_max_data - 1] = '\0';

	res = strncpy(addr->gender, gender, g_max_data);
	if(!res) die("Gender copy failed");
	addr->gender[g_max_data - 1] = '\0';
}

void Database_get( int id)
{
	struct Address *addr = &g_conn.db->rows[id];

	if(addr->set)
	{
		Address_print(addr);
	}
	else
	{
		die("ID is not set");
	}
}

void Database_delete( int id)
{
	struct Address addr = {.id = id, .set = 0};
	g_conn.db->rows[id] = addr;
}

void Database_list(void)
{
	int i = 0;
	struct Database *db = g_conn.db;

	for(i = 0; i < db->rows_size; i++)
	//for(i = 0; i < MAX_ROWS; i++)
	{
		struct Address *cur = &db->rows[i];

		if(cur->set)
		{
			Address_print(cur);
		}
	}
}

void Database_find( char *key, char *val)
{
	int b_match = 0;// match flag, 1=match, 0=not match
	int i = 0;
	struct Database *db = g_conn.db;
	if( strcmp(key, "name") == 0)
	{
		for(i = 0; i < db->rows_size; i++)
		{
			if( strcmp( db->rows[i].name, val) == 0)
			{
				printf("Great! Found name: %s, and the address is:", val);
				Address_print(&db->rows[i]);
				b_match = 1;
			}
		}
//		if(!b_match) printf("Not found %s in the database\n", val);
	}
	else if( strcmp(key, "gender") == 0)
	{
		for(i = 0; i < db->rows_size; i++)
		{
			if( strcmp( db->rows[i].gender, val) == 0)
			{
				//printf("Great! Found %s, and the address is:", name);
				Address_print(&db->rows[i]);
				b_match = 1;
			}
		}
//		if(!b_match) printf("Not found %s in the database\n", val);
	}
	
	if(!b_match) printf("Not found %s in the database\n", val);
	
}

int main(int argc, char *argv[])
{
	if(argc < 3) die("USAGE: ex17 <dbfile> <action> [action params]");

	char *filename = argv[1];
	char action = argv[2][0];
	// struct Connection *conn = Database_open(filename, action);
	Database_open(filename, action);
	int id = 0;

	if(argc > 3) id = atoi(argv[3]);
	if(id >= MAX_ROWS) die("There's not that many records.");

	switch(action)
	{
		case 'c':
			g_max_data = atoi(argv[3]);
			g_max_rows = atoi(argv[4]);
			printf("create db file & set max_data = %d, max_rows = %d\n",
					g_max_data, g_max_rows);
			Database_create();
			Database_write();
			break;

		case 'g':
			if(argc != 4) die("Need an id to get");

			Database_get(id);
			break;

		case 's':
			if(argc != 7) die("Need id, name, email, gender to set");

			Database_set( id, argv[4], argv[5], argv[6]); //name, email, gender
			Database_write();
			break;

		case 'd':
			if(argc != 4) die("Need id to delete");

			Database_delete( id);
			Database_write();
			break;

		case 'l':
			Database_list();
			break;

		case 'v':
			printf("g_max_data = %d, g_max_rows = %d\n",
					g_conn.db->char_size, g_conn.db->rows_size);
			break;

		case 'f':
			if(argc != 5) die("Need name or gender to find");
			Database_find(argv[3], argv[4]);
			break;

		default:
			die("Invalid action, only: c=create, g=get, s=set, d=del, l=list, v=view, f=find");
	}

	Database_close();

	return 0;
}



