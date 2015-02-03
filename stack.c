#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

Stack createStack(){
	Stack st = {0,0};
	return st;	
}

int push(Stack* st,void* i){
	node_ptr n = (Node*)calloc(sizeof(Node),1);
	n->data  = i;
	printf(" push = %d\n",*(int*)n->data);
	if(st->count!=0){
		n->next = (st->top);
	}
	st->top = n;
	return ++st->count;
}

void* pop(Stack* st){
	node_ptr node = (Node*)calloc(sizeof(Node),1);
	if(st->count == 0){
		return NULL;
	}
	node->data = st->top->data;
	if(st->count==1){
		st->top = NULL;
		st->count--;
	}
	else{
		st->top = st->top->next;
		st->count--;
	}
	printf("pop = %d\n",*(int*)node->data);
	return node->data;
};