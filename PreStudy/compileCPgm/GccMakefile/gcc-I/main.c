#include <stdio.h>
#include "display.h"
#include "Print.h"
#include "show.h"

int main(int argc, char *argv[])
{
	show1();
	show2();
	show3();
	show4();

	MyPrint("print test");
	display_test();
}
