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

void Database_close(struct Connection *conn);

void die(const char *message, struct Connection *conn)
{
	if(errno)
	{
		perror(message);
	}
	else
	{
		printf("ERROR :%s\n", message);
	}

	Database_close(conn);
	exit(1);
}

void Address_print(struct Address *addr)
{
	printf("%d %s %s %s\n",
			addr->id, addr->name, addr->email, addr->gender);
}

void Database_load(struct Connection *conn)
{
	int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
	if(rc != 1) die("Failed to load database.", conn);
}

struct Connection *Database_open(const char *filename, char mode)
{
	struct Connection *conn = malloc(sizeof(struct Connection));
	if(!conn) die("Memory error", conn);

	conn->db = malloc(sizeof(struct Database));
	if(!conn->db) die("Memory error", conn);

	if(mode == 'c')
	{
		conn->file = fopen(filename, "w");
	}
	else
	{
		conn->file = fopen(filename, "r+");

		if(conn->file)
		{
			Database_load(conn);
		}
	}
	
	if(!conn->file) die("Failed to open the file", conn);

	return conn;
}

void Database_close(struct Connection *conn)
{
	if(conn)
	{
		if(conn->file) fclose(conn->file);
		if(conn->db) free(conn->db);
		free(conn);
	}
}

void Database_write(struct Connection *conn)
{
	rewind(conn->file);

	int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
	if(rc != 1) die("Failed to write database.", conn);

	rc = fflush(conn->file);
	if(rc == -1) die("Cannot flust database.", conn);
}


void Database_create(struct Connection *conn)
{
	int i = 0;

	for(i = 0; i < MAX_ROWS; i++)
	{
		// make a prototype to initialize it
		struct Address addr = {.id = i, .set = 0};
		// then just assign it
		conn->db->rows[i] = addr;
		conn->db->rows_size = g_max_rows;
		conn->db->char_size = g_max_data;
	}
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email, char *gender)
{
	struct Address *addr = &conn->db->rows[id];
	if(addr->set) die("Already set, delete it first", conn);

	addr->set = 1;
	g_max_data = conn->db->char_size;
	g_max_rows = conn->db->rows_size;
	// WARNING: bug, read thw "How To Break It" and fix this
	//char *res = strncpy(addr->name, name, MAX_DATA);
	char *res = strncpy(addr->name, name, g_max_data);
	// demostrate the strncpy bug
	if(!res) die("Name copy failed", conn);
	addr->name[g_max_data - 1] = '\0';

	res = strncpy(addr->email, email, g_max_data);
	if(!res) die("Email copy failed", conn);
	addr->email[g_max_data - 1] = '\0';

	res = strncpy(addr->gender, gender, g_max_data);
	if(!res) die("Gender copy failed", conn);
	addr->gender[g_max_data - 1] = '\0';
}

void Database_get(struct Connection *conn, int id)
{
	struct Address *addr = &conn->db->rows[id];

	if(addr->set)
	{
		Address_print(addr);
	}
	else
	{
		die("ID is not set", conn);
	}
}

void Database_delete(struct Connection *conn, int id)
{
	struct Address addr = {.id = id, .set = 0};
	conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
	int i = 0;
	struct Database *db = conn->db;

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

void Database_find(struct Connection *conn, char *key, char *val)
{
	int b_match = 0;// match flag, 1=match, 0=not match
	int i = 0;
	struct Database *db = conn->db;
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
	if(argc < 3) die("USAGE: ex17 <dbfile> <action> [action params]", NULL);

	char *filename = argv[1];
	char action = argv[2][0];
	struct Connection *conn = Database_open(filename, action);
	int id = 0;

	if(argc > 3) id = atoi(argv[3]);
	if(id >= MAX_ROWS) die("There's not that many records.", conn);

	switch(action)
	{
		case 'c':
			g_max_data = atoi(argv[3]);
			g_max_rows = atoi(argv[4]);
			printf("create db file & set max_data = %d, max_rows = %d\n",
					g_max_data, g_max_rows);
			Database_create(conn);
			Database_write(conn);
			break;

		case 'g':
			if(argc != 4) die("Need an id to get", conn);

			Database_get(conn, id);
			break;

		case 's':
			if(argc != 7) die("Need id, name, email, gender to set", conn);

			Database_set(conn, id, argv[4], argv[5], argv[6]); //name, email, gender
			Database_write(conn);
			break;

		case 'd':
			if(argc != 4) die("Need id to delete", conn);

			Database_delete(conn, id);
			Database_write(conn);
			break;

		case 'l':
			Database_list(conn);
			break;

		case 'v':
			printf("g_max_data = %d, g_max_rows = %d\n",
					conn->db->char_size, conn->db->rows_size);
			break;

		case 'f':
			if(argc != 5) die("Need name or gender to find", conn);
			Database_find(conn, argv[3], argv[4]);
			break;

		default:
			die("Invalid action, only: c=create, g=get, s=set, d=del, l=list, v=view, f=find", conn);
	}

	Database_close(conn);

	return 0;
}



