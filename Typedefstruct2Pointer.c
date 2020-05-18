#include <stdio.h>

typedef struct{
    int num;
    float num2;
}test;

void testfunc(test *numbers);

int main(void){
test numbers[50];
    

    testfunc(&numbers);
    printf("<%d>", numbers.num[5]);
    for(int i = 0; i < 50; i++){
        printf("%d\n", numbers.num[i]);
    }
}

void testfunc(test *numbers){
numbers->num[5] = 15;
}