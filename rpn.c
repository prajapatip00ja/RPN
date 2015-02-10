#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "rpn.h"
int* token;
int flag = 0;

void pushOperaion(int *token,char *expression,int i,Stack* st){
	token = (int*)malloc(sizeof(int));
	*token = (atoi(expression+i));
	if(i>0)
		(expression[i-1]==32) && push(st,(void*)token);
	else
		push(st,(void*)token);		
}

int isOperator(char operator){
	return operator>= 42 && operator<=47;
}

int performOperation(char* expression,int i,void* first_val,void* second_val,Stack* st){
	int *res = malloc(sizeof(int));
	switch(expression[i]){
		case 43: *res = *(int*)first_val+*(int*)second_val; break;
	 	case 42: *res = *(int*)first_val*(*(int*)second_val); break;
	 	case 45: *res = (*(int*)second_val-*(int*)first_val); break;
	}
	(expression[i+1]==32) && push(st,res);
	return *res;
}

Result popAndSetResult(char* expression,int i,Stack* st){
	Result res;
	void* first_val,*second_val;
	first_val = pop(st);
	second_val = pop(st);
	if((int)first_val==0 || (int)second_val == 0)
		res = (Result){1,0};
	else
		res.status = performOperation(expression,i,first_val,second_val,st);
	return res;	
}

Result evaluate(char *expression){
	Result final_res;
	int i,first_val,second_val,final_value;
	Stack st = createStack();
	for(i=0; i<strlen(expression); i=i++){
		if(expression[i] != 32){
			if(isOperator(expression[i])==0)
				pushOperaion(token,expression,i,&st);
			else
				final_res = popAndSetResult(expression,i,&st);
		}
	}
	return final_res;
}