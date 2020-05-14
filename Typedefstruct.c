#include <stdio.h>

typedef struct{
    int num;
    float num2;
}test;

void testfunc(test *numbers);

int main(void){
test numbers;

    testfunc(&numbers);
    printf("%d", numbers.num);
}

void testfunc(test *numbers){
numbers->num = 15;
}