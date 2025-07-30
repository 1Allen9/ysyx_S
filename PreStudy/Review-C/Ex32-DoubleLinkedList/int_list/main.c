#include <stdlib.h>
#include <stdio.h>
#include "list.h"


int main(int argc, char *argv[])
{
	LinkList *list = List_create();
	printf("This is main (test) \n");
	/*
	int i = 0;
	for(i = 0; i < argc; i++)
	{
		Insert_Node_to_Head(list, atoi(argv[i+1]) );
	}
	*/
	//Insert_Node_to_Head(list, 10);
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
	printf("tail num = %d\n", pop);
	int h = List_rm_head(list);
	printf("tail num = %d\n", h);

	// if remove node as a *node, need free heap manully
	//free(pop);
	//free(shift);
	List_destroy(list);

	return 0;
}
