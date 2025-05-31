#include <stdio.h>
#include "calc.h"
#include "common.h"

int main(void)
{
		int a = 6, b = 7;
		int res = 0;
		printf("hello world!\n");
		int num1 = 6, num2 = 4;
		printf("%d + %d = %d\n", num1, num2, add_int(num1, num2));
		printf("%d - %d = %d\n", num1, num2, minus_int(num1, num2));
		printf("common test: %s \n", COMMON_TEXT);

		res = minus_int(a, b);
		//res = minus_int(a, 4.3);
		printf("var test: res = %d\n", res);
		int sum = 0;
		sum = sum_loop(1, 1, 100);
		printf("sum_loop test = %d\n", sum);

		return 0;
}



