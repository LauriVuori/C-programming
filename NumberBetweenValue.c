/*Write a C function ask_integer_number to ask number from user as
many times as needed to get number on range. Function prototype
int ask_integer_number(int min, int max);
Write also main program to test your function
Give number between 20 and 70: 10
Number was not in range (20-70): 33

User given number was 33*/
#include <stdio.h>
int ask_integer_number(int min, int max);
int main(void){
    int ok = 1;
    int max, min;
    int number1, number2;

    printf("Give max value:\n");
    scanf("%d", &number1);
    printf("Give min value:\n");
    scanf("%d", &number2);


    while(ok == 1){
    ok=ask_integer_number(number2, number1);
    }
    printf("Program shuts down");
}


int ask_integer_number(int min, int max){
    int number;
    printf("Give number between %d and %d:\n", min, max);
    scanf("%d", &number);
    if(number>= min && number <= max){
        printf("Number was in range (%d-%d):\n", min, max);
        return 1;
    }
    else{
        printf("Number was not in range (%d-%d):\n", min, max);
        return 0;
    }
}
