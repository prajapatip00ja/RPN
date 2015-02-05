typedef struct result Result;
#include "stack.h"

struct result {
  int error;
  int status;
};

Result evaluate(char *expression);
void pushOperaion(int* token,char* expression,int i,Stack *st);
int popOperation(char expression,Stack* st);