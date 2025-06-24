#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/** Our old friend die from ex17. */
void die(const char *message)
{
	if(errno)
	{
		perror(message);
	}
	else
	{
		printf("ERROR: %s\n", message);
	}

	exit(1);
}

// a typedef creates a fake type, in this
// case for a funcion pointer
typedef int (*compare_cb)(int a, int b);

typedef int *(*sort_func )(int *arr, int cnt, compare_cb cmp);
/**
  * A classic bubble sort function that uses the
  * compare_cb to do the sorting.
  */
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
	int temp = 0;
	int i = 0;
	int j = 0;
	int *target = malloc(count * sizeof(int));

	if(!target) die("Memory error.");

	memcpy(target, numbers, count * sizeof(int));

	for(i = 0; i < count; i++)
	{
		for(j = 0; j < count - 1; j++)
		{
			if(cmp(target[j], target[j+1]) > 0)
			{
				temp = target[j+1];
				target[j+1] = target[j];
				target[j] = temp;
			}
		}
	}

	return target;
}

int sorted_order(int a, int b)
{
	return a - b;
}

int reverse_order(int a, int b)
{
	return b - a;
}

int strange_order(int a, int b)
{
	if(a == 0 || b == 0)
	{
		return 0;
	}
	else
	{
		return a % b;
	}
}

/** 
  * Used to test that we are sorting things correctly
  * by doing the sort and printing it out
  */
//void test_sorting(int *numbers, int count, compare_cb cmp)
void test_sorting(int *numbers, int count, compare_cb cmp, sort_func sort)
{
	int i = 0;
	//int *sorted = bubble_sort(numbers, count, cmp);
	int *sorted = sort(numbers, count, cmp);

	if(!sorted) die("Failed to sort as requested.");

	for(i = 0; i < count; i++)
	{
		printf("%d ", sorted[i]);
	}
	printf("\n");

	free(sorted);
}

int *simple_sort(int *num, int cnt, compare_cb cmp)
{
	int tmp;
	int i = 0;
	int j = 0;
	int *target = malloc(cnt * sizeof(int));

	memcpy(target, num, cnt * sizeof(int));
	for(i = 0; i < cnt - 1; i++)
	{
		for(j = i + 1; j < cnt; j++)
		{
			if(cmp(target[i], target[j]) > 0)
			{
				tmp = target[i];
				target[i] = target[j];
				target[j] = tmp;
			}
		}
	}

	return target;
}


void split_arr(int *num, int start, int end)
{
	if(start > end) return;
	int mid = (start + end) / 2;
	
	split_arr(num, start, mid);
	split_arr(num, mid+1, end);

}

void merge(int *arr, int start, int mid, int end)
{

}

int *merge_sort(int *num, int cnt, compare_cb cmp)
{
	int *target = malloc(cnt * sizeof(int));

	memcpu(target, num, cnt * sizeof(int));



	return target;
}


int main(int argc, char *argv[])
{
	if(argc < 2) die("USAGE: ex18 4 3 1 5 6");

	int count = argc - 1;
	int i = 0;
	char **inputs = argv + 1;

	int *numbers = malloc(count * sizeof(int));
	if(!numbers) die("Memory error.");

	for(i = 0; i < count; i++)
	{
		numbers[i] = atoi(inputs[i]);
	}

	printf("main pointer=%p\n", main);
	test_sorting(numbers, count, sorted_order, bubble_sort);
	test_sorting(numbers, count, reverse_order, bubble_sort);
	test_sorting(numbers, count, strange_order, bubble_sort);
//	test_sorting(numbers, count, die);
//	test_sorting(numbers, count, NULL);

	printf("simple sort\n");
	test_sorting(numbers, count, sorted_order, simple_sort);
	test_sorting(numbers, count, reverse_order, simple_sort);
	test_sorting(numbers, count, strange_order, simple_sort);

	free(numbers);

	return 0;
}



