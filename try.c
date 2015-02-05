#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main(int argc, char const *argv[]) {
	int o = 10;
	Stack st = createStack();
	push(&st,(void*)&o);
	printf("%d",*(int*)st.top->data);
	return 0;
}

