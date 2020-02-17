/*Write a C function

void is_equal(int n1, int n2);

to check whether two numbers are equal or not.

Example:

test	result
is_equal(15,15);
numbers are equal
is_equal(10,15);
numbers are not equal*/
#include <stdio.h>
void is_equal(int n1, int n2);
int main(void){
is_equal(15,15);
}

void is_equal(int n1, int n2){
    if(n1 == n2){
        printf("numbers are equal");
    }
    else{
        printf("numbers are not equal");
    }
}
