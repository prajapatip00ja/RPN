#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define atoa(x) #x

void tostring(char str[], int num){
    int i, rem, len = 0, n;
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
    str[len] = '\0';
}

int main(int argc, char const *argv[]) {
   char string[5];
   int num = 345676879;
   tostring(string,num);
   //char c = num+'0';
    printf("%s\n",string);
    return 0;
}


