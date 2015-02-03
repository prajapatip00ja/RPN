#include <stdio.h>
#include "expr_assert.h"
#include "rpn.h"

void test_evaluate_expression(){
	char* expression = "2 3 +";
	int result;
	result =  evaluate(expression);
	assertEqual(result,5);
}

void test_evaluate_expression_multiply(){
	char* expression = "2 3 *";
	int result;
	result =  evaluate(expression);
	assertEqual(result,6);
}

void test_evaluate_expression_minus(){
	char* expression = "2 3 -";
	int result;
	result =  evaluate(expression);
	assertEqual(result,-1);
}

// void test_evaluate_expression_divide(){
// 	char* expression = "2 3 /";
// 	double result;
// 	result =  evaluate(expression);
// 	assertEqual(result,1.5);
// }

void test_evaluate_expression_d(){
	char* expression = "2 3 4 + -";
	int result;
	result =  evaluate(expression);
	assertEqual(result,-5);
}

void test_evaluate_expression_b(){
	char* expression = "2 4 3 - +";
	int result;
	result =  evaluate(expression);
	assertEqual(result,3);
}

void test_evaluate_expression_o(){
	char* expression = "1 2 3 4 5 * * * *";
	int result;
	result =  evaluate(expression);
	assertEqual(result,120);
}



