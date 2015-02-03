#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "rpn.h"

int evaluate(char *expression){
	int i,j;
	int res;
	char o,p;
	Stack st = createStack();
	int* token;  

	for(i=0; i<strlen(expression); i++){

		if(expression[i] != 32){
			if(expression[i] != 43 && expression[i] != 42 && expression[i] != 45 && expression[i] != 47){
				token = (int*)malloc(sizeof(int));
				*token = (atoi(expression+i));
				push(&st,(void*)token);
			}
			else{
				o = *(int*)pop(&st);
				p = *(int*)pop(&st);
				switch(expression[i]){
					case 43:
				 		res = o+p;
				 		token = &res;
				 		if(expression[i+1] == 32){
					 		push(&st,(void*)token);
				 		}
				 		else
				 			return o+p;
				 		break;
				 	case 42:
				 		res = (o*p);
				 		token = &res;
				 		if(expression[i+1] == 32){
					 		push(&st,(void*)token);
				 		}
				 		else
				 			return o*p;
				 		break;

				 	case 45:
				 		res = (p-o);
				 		token = &res;
				 		if(expression[i+1] == 32){
					 		push(&st,(void*)token);
				 		}
				 		else
				 			return p-o;
				 		break;
			// 	 	case 47:
			// 	 		o = atoi((char*)pop(&st));
			// 	 		p = atoi((char*)pop(&st));
			// 	 		l = p/o;
			// 	 		token = (int*)&l;
			// 	 		if(expression[i+1] == 32){
			// 		 		push(&st,(void*)token);
			// 	 		}
			// 	 		else
			// 	 			return p/o;
			// 	 		break;
				 }
			}
		}
	}
	return 0;
}