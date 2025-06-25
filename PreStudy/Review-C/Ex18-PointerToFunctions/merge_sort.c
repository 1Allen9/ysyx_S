#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAUSE {printf("pause:"); getchar();}

typedef int (*compare_cb)(int a, int b);

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



void merge(int *arr, int start, int mid, int end, compare_cb cmp)
{
    printf("---- merge func -----\n");
    int left_cnt = mid - start + 1;
    int right_cnt = end - mid;

    // int l_arr[left_cnt] = {0};
    // int r_arr[right_cnt] = {0};
    printf("left_cnt:%d\n", left_cnt);
    printf("right_cnt:%d\n", right_cnt);
    printf("st: %d, mid: %d, ed: %d\n", start, mid, end);
    printf("arr: ");
    
    for (size_t i = 0; i < end - start + 1; i++)
    {
        printf("%d ", arr[start + i]);
    } printf("\n");
    PAUSE
    
    int *l_arr = malloc(left_cnt * sizeof(int));
    if(!l_arr){printf("malloc error\n");return;}
    memcpy(l_arr, &arr[start], left_cnt * sizeof(int));
    
    int *r_arr = malloc(right_cnt * sizeof(int));
    if(!r_arr){printf("malloc error\n");return;}
    memcpy(r_arr, &arr[mid+1], right_cnt * sizeof(int));

    int i = 0;
    printf("l: ");
    for ( i = 0; i < left_cnt; i++)
    {
        printf("%d ", l_arr[i]);
    } printf("\n");
    
    printf("r:");
    for ( i = 0; i < right_cnt; i++)
    {
        printf("%d ", r_arr[i]);
    } printf("\n");

    PAUSE
    free(l_arr);
    free(r_arr);
}

void mg_sort(int *num, int start, int end, compare_cb cmp)
{
    if(start >= end) {printf("mg_sort return\n"); return;}
    int mid = (start + end) / 2;
    printf("st: %d, mid: %d, ed: %d\n", start, mid, end);
    mg_sort(num, start, mid, cmp);
    mg_sort(num, mid+1, end, cmp);

    merge(num, start, mid, end, cmp);

    int i = 0;
    printf("sorted: ");
    for ( i = 0; i < (end - start + 1); i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");
    
}


int main(int argc, char *argv[])
{
    if(argc < 2) 
    {
        printf("USAGE: ex18 4 3 1 5 6\n");
        return 1;
    }

    int count = argc - 1;
    int i = 0;
    char **inputs = argv + 1;

    int *numbers = malloc(count * sizeof(int));
    if(!numbers) {printf("Memory error\n"); return 1;}

    for ( i = 0; i < count; i++)
    {
        numbers[i] = atoi(inputs[i]);
    }

    mg_sort(numbers, 0, count - 1, sorted_order);
    mg_sort(numbers, 0, count - 1, reverse_order);
    
}
