#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"
#include "rpn.h"

int tostring(char str[], int num){
    int i, rem, len = 0 , n;
    n = num;
    while (n != 0){
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++){
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = ' ';
    str[len+1] = '\0';
    return len+1;
}

int givePrecedence(char operator){
	operators op[7] ={{'+',2},{'-',2},{'*',3},{'/',3},{'^',4},{'(',10},{')',10}};
	int i,precedence;
	for(i = 0; i<7; i++){
		if(op[i].symbol==operator){
			precedence = op[i].precedence;
		}
	}
	return precedence;
}

int isOperator(char operator){
	char operators[] = {'+','-','*','/','(',')','^'};
	int i,flag = 0;
	for(i=0;i<=6;i++){
		if(operator==operators[i]){
			flag = 1;
		}
	}
	return flag;
}


void printList(LinkedList* list){
	node_ptr walker = list->head;
	while(walker!=NULL){
		printf("item = %d\n",*(int*)walker->data);	
		walker = walker->next;
	}  
}

int insertInQueue(linkedList_ptr list,char* expression,int i){
	int* token = (int*)malloc(sizeof(int));
	node_ptr node = create_node((void*)token);
	*token = (atoi(expression+i));
	if(i>0){
	if(expression[i-1]==' ')
		add_to_list(list,node);
	}
	else
	add_to_list(list,node);
	return 0;
}

int popAll(Stack* st,linkedList_ptr list){
	while(st->top!=NULL){
		void*  token = pop(st);
		node_ptr node = create_node(token);
		add_to_list(list,node);
	}
	return 0;
}

void printStack(Stack* st){
	while(st->top!=NULL){
		printf("Data= %c\n",*(char*)st->top->data);
		st->top = st->top->next;
	}
}

void popAndInsertInQueue(Stack* st,linkedList_ptr list){
	void* token = pop(st);
	node_ptr node = create_node(token);
	add_to_list(list,node);
}

void handlePanthesis(Stack* st,linkedList_ptr list){
	void* token = pop(st);
	node_ptr node = create_node(token);
	add_to_list(list,node);
	pop(st);
		
};

void makeResult(char* result,int* i,node_ptr walker,int length){
	char token = *(char*)walker->data;
	int len;
	if(!isOperator(token)){
		int number = *(int*)walker->data;
		len = tostring(result+*i,number);
		*i = *i+len;
	}
	else{
		result[*i] = token;
		(*i != length-1) && (result[*i+1] = ' ');
		*i = *i+2;
	}
	
}

char* makeResultExpression(linkedList_ptr list,char* expression){
	int len1 = strlen(expression);
	int len2;
	char* result = malloc(len1);
	int i = 0,number;
	node_ptr walker = list->head;
	while(walker!=NULL){
		makeResult(result,&i,walker,len1);
		walker = walker->next;
	}
	return result;
}

void comparePrecedence(void* operator,Stack* st,linkedList_ptr list){
	int precedenceOfOperator = givePrecedence(*(char*)operator);
 	int	precedenceOfTopElementOfStack = givePrecedence(*(char*)st->top->data);
	if(precedenceOfTopElementOfStack>precedenceOfOperator)
		(*(char*)st->top->data!='(') && popAll(st,list);
	else if(precedenceOfTopElementOfStack==precedenceOfOperator)
		popAndInsertInQueue(st,list);
} 

void checkPrecedenceAndPush(Stack* st,void* operator,int count,linkedList_ptr list){
	if(count == 0){
		push(st,operator);
		return;
	}
	comparePrecedence(operator,st,list);
	push(st,operator);
};

int handleOperators(char* expression,int i,Stack* st,linkedList_ptr list,int count){
	if(expression[i]==')')
		handlePanthesis(st,list);
	else{
		checkPrecedenceAndPush(st, (expression+i),count,list);
	}
	return 0;
}

char* infixToPostfix(char* expression){
	int i,count = 0;
	Stack st = createStack();
	LinkedList list = createList();
	for (i = 0; i < strlen(expression);i++){
		isdigit(expression[i]) && insertInQueue(&list,expression,i);
		
		if(isOperator(expression[i])==1){
			handleOperators(expression,i,&st,&list,count);
			count++;
		}
	}
	popAll(&st,&list);
	return makeResultExpression(&list,expression);
}