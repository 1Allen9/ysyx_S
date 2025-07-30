#include "list.h"
#include <stdlib.h>
#include "debug.h"

LinkList *List_create()
{
	LinkList *list = calloc(1, sizeof(LinkList));
	if(list != NULL)
	{
		printf("Create list pass\n");
	}
	else
	{
		printf("Create list error, get a NULL mem\n");
	}
	return list;
}

void Insert_Node_to_Head(LinkList *list, int num)
{
	ListNode *node = calloc(1, sizeof(ListNode));
	db_chk_null(node);
	node->num = num;
	if(list->cnt == 0)
	{
		list->head = node;
		list->tail = node;
		node->prev = NULL;
		node->next = NULL;
	}
	else
	{
		list->head->prev = node;
		node->prev = NULL;
		node->next = list->head;
		list->head = node;
	}
	list->cnt++;
}

void Insert_Node_to_Tail(LinkList *list, int num)
{
	ListNode *node = calloc(1, sizeof(ListNode));
	node->num = num;

	if(list->cnt == 0)
	{
		list->head = node;
		list->tail = node;
		node->prev = NULL;
		node->next = NULL;
	}
	else
	{
		list->tail->next = node;
		node->prev = list->tail;
		node->next = NULL;
		list->tail = node;
	}

	list->cnt++;
}

void Print_LinkList_TailtoHead(LinkList *list)
{
	printf("---- print list tail to head ----\n");
	if(list->cnt == 0) {printf("The list is emtpy\n");}
	else
	{
		ListNode *cur_node = list->tail;
		for(cur_node = list->tail;cur_node != NULL; cur_node = cur_node->prev)
		{
			printf("node val: %d\n", cur_node->num);
		}
	}
}
void Print_LinkList_HeadtoTail(LinkList *list)
{
	printf("---- print list head to tail ----\n");
	if(list->cnt == 0) {printf("The list is emtpy\n");}
	else
	{
		ListNode *cur_node = list->head;
		for(cur_node = list->head; cur_node != NULL; cur_node = cur_node->next)
		{
			printf("node val: %d\n", cur_node->num);
		}
	}
}

//ListNode *List_rm_tail(LinkList *list)
int List_rm_tail(LinkList *list)
{
	//ListNode *node = NULL;//calloc(1, sizeof(ListNode));
	int num;
	db_chk_null(list);
	//db_chk_null(node);

	if(list == NULL)
	{
		printf("err list\n");
		return 0;
	}

	if(list->cnt == 0)
	{
		printf("empty list, not remove tail node\n");
		return 0;
	}
	else
	{
		//node = list->tail;
		num = list->tail->num;
		list->tail = list->tail->prev;
		list->cnt--;
		free(list->tail->next);
		list->tail->next = NULL;
	}
	//return node;
	return num;
}

int List_rm_head(LinkList *list)
{
	//ListNode *node = NULL;//calloc(1, sizeof(ListNode));
	db_chk_null(list);
	int num;

	if(list == NULL)
	{
		printf("err list\n");
		return 0;
	}

	if(list->cnt == 0)
	{
		printf("empty list, not remove head node\n");
		return 0;
	}
	else
	{
		//node = list->head;
		num = list->head->num;
		list->head = list->head->next;
		list->cnt--;
		free(list->head->prev);
		list->head->prev = NULL;
	}
	return num;
}

void List_destroy(LinkList *list)
{
	db_chk_null(list);

	ListNode *cur_node = list->head;
	for(cur_node = list->head; cur_node != NULL; cur_node = cur_node->next)
	{
		//free(cur_node);
		if(cur_node->prev != NULL) free(cur_node->prev);
	}
	free(list->tail);
	free(list);
}

void Check_List_info(LinkList *list)
{
	db_chk_null(list);
	printf("==== list info ====\n");
	if(list->cnt == 0) 
	{
		printf("An empty list\n");
		return;
	}

	printf("list->head val: %d\n", list->head->num);
	printf("list->tail val: %d\n", list->tail->num);
	printf("list->cnt: %d\n", list->cnt);
}
