#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "rpnLinkedList.h"

int isOperator(char operator){
	return operator>= 42 && operator<=47;
}

int get_value(char* expression,int start,int end){
	return atoi(expression+start);
}

int push_operation(Stack* st,void* i){
	push_operation(st,i);
	return 0;
}

void makeTokenList(LinkedList* list,char* expression){
	int i;
	ex_Node* n; 
	//Stack st = createStack();
	for (i = 0; i < strlen(expression); i++)
	{ 
		if(expression[i]!=32){
			ex_Node* node1 = (ex_Node*)malloc(sizeof(ex_Node));
			node_ptr node = create_node((void*)node1);
			add_to_list(list,node);
			if(isOperator(expression[i])==0){
				node1->identity = 0;
				node1->start_index = i;
				node1->end_index = i;
				node1->fn_ptr1 = &get_value;
				node1->fn_ptr2 = &push_operation;
			}
			else{
				node1->identity = 1;
				node1->start_index = i;
				node1->end_index = i;
				//node1->fn_ptr2 = &pop_Operation;
			}
		}	
	}
};

int processList(LinkedList* list,char* expression){
	

}

int evaluate(LinkedList* list,char *expression){
	makeTokenList(list,expression);
	processList(list,expression);
	return 0;
}