#include <stdio.h>

#define MAX 70
#define MIN 20
int ask_integer_number(int min, int max);
int main(void){
ask_integer_number(MIN,MAX);
}

int ask_integer_number(int min, int max){
    int number = 0;
    printf("Give number between %d and %d:\n", MIN, MAX);
    scanf("%d", &number);
        while(number<=min || number>= max){
            printf("Number was not in range (%d-%d):", MIN,MAX);
            scanf("%d", &number);
        }
    printf("User given number was: %d", number);
}
