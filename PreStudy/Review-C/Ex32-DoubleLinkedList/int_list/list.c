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
	if(list == NULL) {return;}

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

/*****
* idx count start from 0: 0=head node, list->cnt-1=tail node
  */
int List_rm_index(LinkList *list, int idx)
{
	db_chk_null(list);
	int num;//rm val
	if(idx < 0) {printf("idx:%d err, should > 0\n", idx); return 0;}

	if(idx == 0)
	{
		List_rm_head(list);
	}
	else if(idx == list->cnt - 1)
	{
		List_rm_tail(list);
	}
	else
	{
		int i = 0;
		ListNode *node = list->head;
		while( i != idx )
		{
			node = node->next;
			i++;
		}
		num = node->num;
		node->prev->next = node->next;
		node->next->prev = node->prev;
		free(node);
		list->cnt--;
	}
	return num;
}

/*****
  * idx start from 0
  */
int List_find_index(LinkList *list, int idx)
{
	db_chk_null(list);
	db_chk_lt_zero(idx);

	if(idx == 0)
	{
		return list->head->num;
	}
	else if(idx == list->cnt - 1)
	{
		return list->tail->num;
	}
	else
	{
		int i = 0;
		ListNode *node = list->head;
		while( i != idx )
		{
			node = node->next;
			i++;
		}
		return node->num;
	}
}

LinkList *List_copy(LinkList *list)
{
	db_chk_null(list);

	printf("==== copy a list ====\n");
	LinkList *new_list = List_create();
	ListNode *node = NULL;
	for(node = list->head; node != NULL; node = node->next)
	{
		Insert_Node_to_Tail(new_list, node->num);
	}

	return new_list;
}

LinkList *List_split(LinkList *list, int idx)
{
	db_chk_null(list);
	db_chk_lt_zero(idx);

	printf("==== list split ====\n");

	if(list->cnt <= 1)
	{
		printf("List can not be splited, len less than 1\n");
		return NULL;
	}

	LinkList *list2 = List_create();
	ListNode *node = list->head;

	int i = 0;
	while( i != idx)
	{
		node = node->next;
		i++;
	}
	list2->head = node;
	list2->tail = list->tail;
	list->tail = node->prev;

	list->tail->next = NULL;
	list2->head->prev = NULL;

	list2->cnt = list->cnt - idx;
	list->cnt = idx;

	return list2;
}

/*****
  * list2 append to list1
  */
LinkList *List_connect(LinkList *list1, LinkList *list2)
{
	db_chk_null(list1);
	db_chk_null(list2);
	if(list1 == list2)
	{
		printf("Can not connect the same Linklist\n");
		return NULL;
	}

	printf(">>>> list connect ====\n");

	LinkList *list_conn = List_create();
	list1->tail->next = list2->head;
	list2->head->prev = list1->tail;
	list_conn->head = list1->head;
	list_conn->tail = list2->tail;
	list_conn->cnt = list1->cnt + list2->cnt;

	// List_destroy(list1);
	// List_destroy(list2);

	// free only LinkList, keep ListNode
	free(list1);
	free(list2);


	return list_conn;
}


