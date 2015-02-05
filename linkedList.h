typedef struct node Node;
typedef struct linkedlist LinkedList;
typedef Node* node_ptr;
typedef LinkedList* linkedList_ptr;
typedef struct student Student;
typedef char* String;

struct student {
	int id;
	char symbol;
};

struct node {
	void* data;
	node_ptr next;
};

struct linkedlist
{
	Node* head;
	Node* tail;
	int count;
};

LinkedList createList(void);
int add(int a,int b);
node_ptr create_node(void* data);
int add_to_list(LinkedList *,Node *);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
void traverse(LinkedList,void (*addOne)(void* data));
void* getElementAt(LinkedList list, int i);
int indexOf(LinkedList list, void* data);
void* deleteElementAt(LinkedList *list, int);
int asArray(LinkedList, void **);
LinkedList* filter(LinkedList, int (*fn_ptr)(void*));