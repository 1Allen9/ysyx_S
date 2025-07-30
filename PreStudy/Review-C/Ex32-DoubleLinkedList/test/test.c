#include "minunit.h"
//#include "List.h"
#include "../src/List.h"
#include <assert.h>

static List *list = NULL;
char *test1 = "test1 data";
char *test2 = "test2 data";
char *test3 = "test3 data";
char *test4 = "test4 data";
char *test5 = "test5 data";
char *test6 = "test6 data";

static List *list2 = NULL;


char *test_create()
{
    list = List_create();
    mu_assert(list != NULL, "Failed to create list.");

    //list2 = List_create();
    //mu_assert(list2 != NULL, "Failed to create list.");

	//printf("list2 addr: %p, list addr:%p\n", list2, list);

    return NULL;
}

char *test_list_copy()
{

	list2 = List_create();
	//list2 = List_copy(list);
	List_copy(list, list2);
	ListNode *node = list2->first;//list2 first node

	printf("==== list copy ====\n");
	printf("new list addr: %p, list addr:%p\n", list2, list);

	LIST_FOREACH(list, first, next, cur)
	{
		mu_assert(cur->value == node->value, "val err, Wrong in copy");
		printf("list1 val: %s, list2 val: %s\n", (char*)cur->value, (char*)node->value);
		printf("list1 add: %p, list2 add: %p\n", cur, node);
		node = node->next;
	}

	return NULL;
}

char *test_destroy()
{
	List_clear_destroy(list);
	//List_clear_destroy(list2);	
	return NULL;
}


char *test_push_pop()
{
	// insert node at last
	List_push(list, test1);
	mu_assert(List_last(list) == test1, "Wrong last value.");

	List_push(list, test2);
	mu_assert(List_last(list) == test2, "Wrong last value");


	List_push(list, test3);
	mu_assert(List_last(list) == test3, "Wrong last value.");
	mu_assert(List_count(list) == 3, "Wrong count on push.");

	char *val = List_pop(list);
	mu_assert(val == test3, "Wrong value on pop. test3");

	val = List_pop(list);
	mu_assert(val == test2, "Wrong value on pop. test2");

	val = List_pop(list);
	mu_assert(val == test1, "Wrong value on pop. test1");
	mu_assert(List_count(list) == 0, "Wrong count after pop.");

	return NULL;
}


char *test_unshift()
{
	// insert node at first
	List_unshift(list, test1);
	mu_assert(List_first(list) == test1, "Wrong first value. test1");

	List_unshift(list, test2);
	mu_assert(List_first(list) == test2, "Wrong first value. test2");

	List_unshift(list, test3);
	mu_assert(List_first(list) == test3, "Wrong last value. test3");
	mu_assert(List_count(list) == 3, "Wrong count on unshift.");

	return NULL;
}


char *test_remove()
{
	// we only need to test the middle remove case since push/shift
	// already tests the other cases

	char *val = List_remove(list, list->first->next);
	mu_assert(val == test2, "Wrong removed element.");
	mu_assert(List_count(list) == 2, "Wrong count after remove.");
	mu_assert(List_first(list) == test3, "Wrong first after remove.");
	mu_assert(List_last(list) == test1, "Wrong last after remove.");

	return NULL;
}

char *test_shift()
{
	mu_assert(List_count(list) != 0, "Wrong count before shift.");

	char *val = List_shift(list);
	mu_assert(val = test3, "Wrong value on shift.");

	val = List_shift(list);
	mu_assert(val == test1, "Wrong value on shift.");
	mu_assert(List_count(list) == 0, "Wrong count after shift.");

	return NULL;
}


char *all_test()
{
	mu_suite_start();

	mu_run_test(test_create);
	mu_run_test(test_push_pop);// add node @ last and pop
	mu_run_test(test_unshift);// add node @ head
	mu_run_test(test_list_copy);// copy
	mu_run_test(test_remove);// 
	mu_run_test(test_shift);
	mu_run_test(test_destroy);

	return NULL;
}

RUN_TEST(all_test);

