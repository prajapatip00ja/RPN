#include <stdio.h>
#include "expr_assert.h"
#include "rpnLinkedList.h"
#include "string.h"
//#include "stack.h"

//#include "stdlib.h"


void test_evaluate_expression(){
	char* expression = "2 3 +";
	int result;
	node_ptr node;
	ex_Node* n1,*n2,*n3;
	LinkedList list = createList();
	result =  evaluate(&list,expression);
	n1 = (ex_Node*)list.head->data;
	assertEqual(n1->start_index,0);
	assertEqual(n1->end_index,0);
	assertEqual(n1->identity,0);
	n2 = (ex_Node*)list.head->next->data;
	assertEqual(n2->start_index,2);
	assertEqual(n2->end_index,2);
	assertEqual(n2->identity,0);
	n3 = (ex_Node*)list.head->next->next->data;
	assertEqual(n3->start_index,4);
	assertEqual(n3->end_index,4);
	assertEqual(n3->identity,1);
}

void test_get_value_is_giving_specified_value(){
	char *c = "1";
	int i = 0,j=1;
	assertEqual(get_value(c,i,j),1);
}

void test_push_operation_push_the_data_in_the_list(){
	int res , i = 5;
	Stack st = createStack();
	res = push_operation(&st,(void*)&i);
	assertEqual(*(int*)(st.top->data),5);
}
