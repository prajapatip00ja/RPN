#include "Stack.h"
typedef struct expression_node{
	int identity;
	int start_index;
	int end_index;
	int (*fn_ptr1)(char*,int,int);
	int (*fn_ptr2)(Stack*,void*);
}ex_Node;
int evaluate(LinkedList* list,char *expression);
int get_value(char*,int,int);
int push_operation(Stack*,void*);
int pop_Operation(Stack*,void*);