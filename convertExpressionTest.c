#include <stdio.h>
#include <stdlib.h>
#include "expr_assert.h"
#include "rpn.h"
#include "string.h"

void test_insertInQueue_method_insert_operand_in_the_queue(){
	char *operand1 = "1";
	char *operand2 = "2";
	LinkedList list = createList();
	insertInQueue(&list,operand1);
	assertEqual(*(int*)list.head->data,1);
	assertEqual(*(int*)list.tail->data,1);
	insertInQueue(&list,operand2);
	assertEqual(*(int*)list.head->next->data,2);
	assertEqual(*(int*)list.tail->data,2);
}

void test_isOperator_method_is_checking_a_token_is_an_operator(){
	char operator = '^';
	assertEqual(isOperator(operator),1);
}

void test_tostring_method_convert_a_integer_to_string(){
	int n = 1;
	char* expected = "1 ";
	char* str = (char*)malloc(sizeof(char)*20);
	tostring(str,1);
	printf("%s",str);
	assertEqual(strcmp(str,expected),0);
	free(str);
}

void test_popAndInsertInQueue_pop_and_insert_the_operators_in_queue(){
	char a='+',b='-';
	LinkedList list = createList();
	Stack st = createStack();
	push(&st,(void*)&a);
	push(&st,(void*)&b);
	popAndInsertInQueue(&st,&list);
	assertEqual(*(char*)list.head->data,'-');
	assertEqual(*(char*)list.tail->data,'-');
}

void test_givePrecedence_return_precedence_of_operators(){
	char operator = '+';
	int precedence = givePrecedence(operator);
	assertEqual(precedence,2);
}

void test_infix_to_postfix_method_changing_the_expression_from_infix_to_postfix(){
	char* expression = "2 + 3";
	char* result;
	char* expected = "2 3 + ";
	result = infixToPostfix(expression);
	assertEqual(strcmp(expected,result),0);
}

void test_infix_to_postfix_method_changing_the_expression_from_infix_to_postfix_11(){
	char* expression = "3 + 4 * 2";
	char* result;
	char* expected = "3 4 2 * + ";
	result = infixToPostfix(expression);
	assertEqual(strcmp(expected,result),0);
}

void  test_infix_to_postfix_method_changing_the_expression_from_infix_to_postfix_22(){
	char* expression = "3 + 4 * 5 - 2";
	char* result;
	char* expected = "3 4 5 * + 2 - ";
	result = infixToPostfix(expression);
	printf("%s",result);
	assertEqual(strcmp(expected,result),0);
}

void  test_infix_to_postfix_method_changing_the_expression_from_infix_to_postfix_33(){
	char* expression = "3 + 4 * 5 / 2";
	char* result;
	char* expected = "3 4 5 * 2 / + ";
	result = infixToPostfix(expression);
	assertEqual(strcmp(expected,result),0);
}

void  test_infix_to_postfix_method_changing_the_expression_from_infix_to_postfix_44(){
	char* expression = "3 + 4 * 5";
	char* result;
	char* expected = "3 4 5 * + ";
	result = infixToPostfix(expression);
	assertEqual(strcmp(expected,result),0);
}

void  test_infix_to_postfix_method_changing_the_expression_from_infix_to_postfix_55(){
	char* expression = "3 + (4 - 5) * 2";
	char* result;
	char* expected = "3 4 5 - 2 * + ";
	result = infixToPostfix(expression);
	assertEqual(strcmp(expected,result),0);
}