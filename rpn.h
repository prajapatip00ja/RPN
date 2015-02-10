typedef struct result Result;
//typedef char* String;
#include "stack.h"

typedef struct token{
	int* intToken;
	char* charToken;
}tokens;

typedef struct {
 char symbol;
 int precedence;
}operators;

struct result {
  int error;
  int status;
};

Result evaluate(char *expression);
void pushOperaion(int* token,char* expression,int i,Stack *st);
Result popOperation(char* expression,int,Stack* st);
char* infixToPostfix(char* expression);
char* removeSpace(char* expression);
int insertInQueue(linkedList_ptr,char*,int);
void popAndInsertInQueue(Stack*,linkedList_ptr);
int givePrecedence(char);
int isOperator(char);
int tostring(char*,int); 
