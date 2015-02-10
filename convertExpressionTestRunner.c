#include <stdio.h>
typedef void TestFn(void);
typedef struct{
	char* name; 
	TestFn* fn;
} Test;

//code to be updated starts
TestFn setup,teardown,fixtureSetup,fixtureTearDown,test_insertInQueue_method_insert_operand_in_the_queue,test_isOperator_method_is_checking_a_token_is_an_operator,test_tostring_method_convert_a_integer_to_string,test_popAndInsertInQueue_pop_and_insert_the_operators_in_queue,test_givePrecedence_return_precedence_of_operators,test_infix_to_postfix_method_changing_the_expression_from_infix_to_postfix,test_infix_to_postfix_method_changing_the_expression_from_infix_to_postfix_11,test_infix_to_postfix_method_changing_the_expression_from_infix_to_postfix_22,test_infix_to_postfix_method_changing_the_expression_from_infix_to_postfix_33,test_infix_to_postfix_method_changing_the_expression_from_infix_to_postfix_44,test_infix_to_postfix_method_changing_the_expression_from_infix_to_postfix_55;
Test test[] = {"test_insertInQueue_method_insert_operand_in_the_queue",test_insertInQueue_method_insert_operand_in_the_queue,"test_isOperator_method_is_checking_a_token_is_an_operator",test_isOperator_method_is_checking_a_token_is_an_operator,"test_tostring_method_convert_a_integer_to_string",test_tostring_method_convert_a_integer_to_string,"test_popAndInsertInQueue_pop_and_insert_the_operators_in_queue",test_popAndInsertInQueue_pop_and_insert_the_operators_in_queue,"test_givePrecedence_return_precedence_of_operators",test_givePrecedence_return_precedence_of_operators,"test_infix_to_postfix_method_changing_the_expression_from_infix_to_postfix",test_infix_to_postfix_method_changing_the_expression_from_infix_to_postfix,"test_infix_to_postfix_method_changing_the_expression_from_infix_to_postfix_11",test_infix_to_postfix_method_changing_the_expression_from_infix_to_postfix_11,"test_infix_to_postfix_method_changing_the_expression_from_infix_to_postfix_22",test_infix_to_postfix_method_changing_the_expression_from_infix_to_postfix_22,"test_infix_to_postfix_method_changing_the_expression_from_infix_to_postfix_33",test_infix_to_postfix_method_changing_the_expression_from_infix_to_postfix_33,"test_infix_to_postfix_method_changing_the_expression_from_infix_to_postfix_44",test_infix_to_postfix_method_changing_the_expression_from_infix_to_postfix_44,"test_infix_to_postfix_method_changing_the_expression_from_infix_to_postfix_55",test_infix_to_postfix_method_changing_the_expression_from_infix_to_postfix_55};
char testFileName[] = {"convertExpressionTest.c"};
void _setup(){/*CALL_SETUP*/}
void _teardown(){/*CALL_TEARDOWN*/}
void fixtureSetup(){}
void fixtureTearDown(){}
//code to be updated ends

int testCount;
int passCount;
int currentTestFailed;

int assert_expr(int expr, const char* fileName, int lineNumber, const char* expression){
	if(expr) return 0;
	currentTestFailed = 1;
	printf("\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
	return 1;
}
int assert_equal(int val1, int val2, const char* fileName, int lineNumber,const char* expr1,const char* expr2){
	if(val1 == val2) return 0;
	currentTestFailed = 1;
	printf("\t %d == %d: failed in assertEqual(%s,%s) at %s:%d\n",val1,val2,expr1,expr2, fileName,lineNumber);
	return 1;
}

void runTest(char* name, TestFn test){
	testCount++,currentTestFailed=0;
	printf("**  %s\n",name);
	_setup();
		test();
	_teardown();
	if(!currentTestFailed) passCount++;	
}
int main(int argc, char const *argv[]){		
	int i,total = sizeof(test)/sizeof(Test);	
	fixtureSetup();
	testCount=0,passCount=0;
	printf("**------ %s ------\n",testFileName);
	for (i = 0; i < total; ++i)
		runTest(test[i].name,test[i].fn);	
	printf("** Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
	fixtureTearDown();	
	return 0;
}