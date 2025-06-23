#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 5

#define STACK_FULL 1
#define STACK_NOT_FULL 0
#define STACK_EMPTY 1
#define STACK_NOT_EMPTY 0


typedef struct
{
	int top;
	int val[CAPACITY];
	int is_full;
	int is_empty;
}Stack;

int Check_Stack_Full(Stack *S)
{
	if(S->top + 1 == CAPACITY) S->is_full = STACK_FULL;
	else S->is_full = STACK_NOT_FULL;
	
	return S->is_full;
}

int Check_Stack_Empty(Stack *S)
{
	if(S->top == -1)
	{
		//printf("Stack is empty\n");
		S->is_empty = STACK_EMPTY;
		return STACK_EMPTY;
	}
	else
	{
		//printf("Stack is not empty\n");
		S->is_empty = STACK_NOT_EMPTY;
		return STACK_NOT_EMPTY;
	}
}

void Push(Stack *S, int num)
{
	if( S->is_full == STACK_FULL)
	{
		printf("Stack is full, not push\n");
		return;
	}

	S->top++;
	S->val[S->top] = num;
	Check_Stack_Full(S);

}

void Top(Stack *S)
{
	printf("Stack top val: %d\n", S->val[S->top]);
}

void Pop(Stack *S)
{
	if( Check_Stack_Empty(S) == STACK_EMPTY) 
	{
		printf("Stack is empty, can not pop\n");
		return;
	}

	S->val[S->top] = 0;
	S->top--;
	Check_Stack_Empty(S);

}

void Stack_Info(Stack *S)
{
	printf("Stack top = %d\n", S->top);
	printf("Stack is_full = %d\n", S->is_full);
	printf("Stack is_empty = %d\n", S->is_empty);
}
	
void Stack_View(Stack *S)
{
	int i = 0;
	if( Check_Stack_Empty(S) == STACK_EMPTY ) return;
	printf("Stack val = ");
	for( i = 0; i < S->top + 1; i++)
	{
		printf("%d ", S->val[i]);
	}
	printf("\n");
}

void Stack_Init(Stack *S)
{
	S->top = -1;
	S->is_empty = STACK_EMPTY;
	S->is_full = STACK_NOT_FULL;
}

int main(int argc, char *argv[])
{
	Stack stack;
	Stack_Init(&stack);
	int i = 0;

	//Stack_Info(&stack);

	
	for(i = 1; i < argc; i++)
	{
		Push(&stack, atoi( argv[i] ) );
	}
	
	Stack_View(&stack);

	printf("chekc top\n");
	Top(&stack);

	printf("pop top val\n");
	Pop(&stack);

	Top(&stack);

	Stack_View(&stack);
	Stack_Info(&stack);

	return 0;
}
