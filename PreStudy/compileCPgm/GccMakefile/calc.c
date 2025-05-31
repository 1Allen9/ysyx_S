#include <stdio.h>


int add_int(int num1, int num2)
{
		return (num1 + num2);
}


int minus_int(int num1, int num2)
{
		return (num1 - num2);
}

int sum_loop(int st_num, int step_num, int cnt)
{
	int sum = 0;
	if(cnt < 1) 
	{
			printf("your cnt is [%d], error, cnt must greater than 0!\n", cnt);
			return sum;
	}
	//sum = st_num;
	for(int i = 0; i < cnt; i++)
	{
		sum += st_num;	
		st_num += step_num;
	}
	return sum;
}
