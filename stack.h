typedef struct stack Stack;
typedef struct node Node;
typedef Node* node_ptr;


struct node
{
	void* data;
	Node* next;
};
struct stack 
{
	Node* top; 
	int count;
};


Stack createStack(void);
int push(Stack*, void *);
void * pop(Stack*);

