#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "autotest.h"


int main(int argc, char *argv[])
{
	LinkList *list = List_create();
	printf("This is main (test) \n");
	
	/*
	int i = 0;
	int n;
	for(i = 0; i < argc; i++)
	{
		n = atoi(argv[i+1]);
		printf("%d, %s\n", n, argv[i+1]);
		Insert_Node_to_Head(list, n );
	}
	*/
	
	Insert_Node_to_Head(list, 1);
	Insert_Node_to_Head(list, 2);
	Insert_Node_to_Head(list, 3);
	Insert_Node_to_Head(list, 4);
	Insert_Node_to_Head(list, 5);

	Print_LinkList_HeadtoTail(list);
	Print_LinkList_TailtoHead(list);

	/* rm node as a *node, need free *node heap manually
	ListNode *pop = List_rm_tail(list);
	printf("tail num = %d\n", pop->num);
	Check_List_info(list);

	ListNode *shift = List_rm_head(list);
	printf("head num = %d\n", shift->num);
	Check_List_info(list);
	*/
	int pop = List_rm_tail(list);
	//printf("tail num = %d\n", pop);
	test_is_eq(pop, 1, "tail rm ");
	int h = List_rm_head(list);
	printf("head num = %d\n", h);

	Insert_Node_to_Tail(list, 10);
	Insert_Node_to_Tail(list, 20);
	Insert_Node_to_Tail(list, 30);
	Insert_Node_to_Tail(list, 40);
	Insert_Node_to_Tail(list, 50);

	Print_LinkList_HeadtoTail(list);
	int r = List_rm_index(list, 2);
	test_is_eq(2, r, " rm No.3 idx test");
	printf("No.3 val of list is: %d\n", List_find_index(list, 2) );
	printf("No.1 val of list is: %d\n", List_find_index(list, 0) );
	printf("last val of list is: %d\n", List_find_index(list, list->cnt-1) );
	// if remove node as a *node, need free heap manully
	//free(pop);
	//free(shift);
	LinkList *cp_list = List_copy(list);
	Print_LinkList_HeadtoTail(cp_list);

	List_destroy(list);
	List_destroy(cp_list);

	return 0;
}
