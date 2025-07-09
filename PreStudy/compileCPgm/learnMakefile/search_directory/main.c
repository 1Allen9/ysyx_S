#include <stdio.h>
#include "text.h"
#include "src.h"
#include "show.h"


int main(int argc, char *argv[])
{
	printf("This is main\n");
	printf("File in the makefile path\n");
	
	printf("string in subdirecotry: %s\n", TEXT);
	src_info();
	show_func("file in subsub directory\n");
}
