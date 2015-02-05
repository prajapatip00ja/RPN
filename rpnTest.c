#include <stdio.h>
#include "expr_assert.h"
#include "rpn.h"

void test_evaluate_expression_plus(){
	char* expression = "2 3 +";
	Result result;
	result =  evaluate(expression);
	assertEqual(result.status,5);
}

void test_evaluate_expression_with_extra_operator(){
	char* expression = "2 3 + +";
	Result result;
	result =  evaluate(expression);
	assertEqual(result.status,0);
	assertEqual(result.error,1);
}

void test_evaluate_expression_multiply(){
	char* expression = "2 3 *";
	Result result;
	result =  evaluate(expression);
	assertEqual(result.status,6);
}

void test_evaluate_expression_minus(){
	char* expression = "2 3 -";
	Result result;
	result =  evaluate(expression);
	assertEqual(result.status,-1);
}

void test_evaluate_expression_v1_1(){
	char* expression = "2 3 4 + -";
	Result result;
	result =  evaluate(expression);
	assertEqual(result.status,-5);
}

void test_evaluate_expression_v1_2(){
	char* expression = "2 4 3 - +";
	Result result;
	result =  evaluate(expression);
	assertEqual(result.status,3);
}

void test_evaluate_expression_v1_3(){
	char* expression = "12 2 3 4 5 * * * *";
	Result result;
	result =  evaluate(expression);
	assertEqual(result.status,1440);
}


void test_evaluate_expression_v2_0(){
	char* expression = "5 1 2 + 4 * + 3 -";
	Result result;
	result =  evaluate(expression);
	assertEqual(result.status,14);
}

void test_evaluate_expression_v2_1(){
	char* expression = "2 2 2 * 2 - 3 + +";
	Result result;
	result =  evaluate(expression);
	assertEqual(result.status,7);
}

void test_evaluate_expression_v2_2(){
	char* expression = "2 2 2 2 2 * * 2 + + 2 - *";
	Result result;
	result =  evaluate(expression);
	assertEqual(result.status,20);
}

void test_evaluate_expression_v2_3(){
	char* expression = "2 2 - 2 2 2 * 2 - - -";
	Result result;
	result =  evaluate(expression);
	assertEqual(result.status,0);
}

void test_evaluate_expression_v2_4(){
	char* expression = "13 15 65 * +";
	Result result;
	result =  evaluate(expression);
	assertEqual(result.status,988);
}

void test_push_operation_00(){
	char* expression = "1";
	int *token,i=0;
	Stack st = createStack();
	pushOperaion(token,expression,i,&st);
	assertEqual(1,*(int*)(st.top->data));
}

void test_push_operation_11(){
	char* expression = " 1";
	int *token,i=0;
	Stack st = createStack();
	pushOperaion(token,expression,i,&st);
	assertEqual(1,*(int*)(st.top->data));
}

void test_pop_operation_00(){
	char* expression = "1 2";
	char operand = '+';
	int *token,res1,res2,i=0,j=2;
	Stack st = createStack();
	pushOperaion(token,expression,i,&st);
	assertEqual(1,*(int*)(st.top->data));
	pushOperaion(token,expression,j,&st);
	assertEqual(2,*(int*)(st.top->data));
	res1 = popOperation(operand,&st);
	assertEqual(res1,3);
}

void test_evaluate_expression_v1(){
	char* expression = "2 4 3 - +";
	Result result;
	result =  evaluate(expression);
	assertEqual(result.status,3);
}

void test_evaluate_expression_v2(){
	char* expression = "2 4 3 - + +";
	Result result;
	result =  evaluate(expression);
	assertEqual(result.status,0);
}


