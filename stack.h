#include "linkedList.h"
typedef struct stack Stack;

struct stack 
{
	Node* top; 
	int count;
};

Stack createStack(void);
int push(Stack*, void *);
void* pop(Stack*);

