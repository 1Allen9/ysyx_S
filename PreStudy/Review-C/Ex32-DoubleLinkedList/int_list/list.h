#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>

typedef struct Node
{
	struct Node *prev;
	struct Node *next;
	int num;
}ListNode;

typedef struct LinkList
{
	ListNode *head;
	ListNode *tail;
	int cnt;
}LinkList;

LinkList *List_create();
void Insert_Node_to_Head(LinkList *list, int num);
void Insert_Node_to_Tail(LinkList *list, int num);
void Print_LinkList_HeadtoTail(LinkList *list);
void Print_LinkList_TailtoHead(LinkList *list);
// ListNode *List_rm_head(LinkList *list);
// ListNode *List_rm_tail(LinkList *list);
int List_rm_tail(LinkList *list);
int List_rm_head(LinkList *list);
int List_rm_index(LinkList *list, int idx);
void List_destroy(LinkList *list);
void Check_List_info(LinkList *list);
int List_find_index(LinkList *list, int idx);
LinkList *List_copy(LinkList *list);


#endif

