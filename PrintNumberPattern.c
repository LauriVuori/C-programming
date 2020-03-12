/*Write a C program to print the given number pattern using for loop. row is asked from user

Esimerkiksi:

Syöte	Tulos
5 
Input rows:
1        1
22      22
333    333
4444  4444
5555555555
9
Input rows:
1                1
22              22
333            333
4444          4444
55555        55555
666666      666666
7777777    7777777
88888888  88888888
999999999999999999*/


#include <stdio.h>
int main(void){
    int rows = 0, i, a,z;
    printf("Give rows:\n");
    scanf("%d", &rows);
    printf("Input rows:\n");
    for (i = 1; i <= rows; i++){
        for (a = 1; a <= i; a++){
            printf("%d", i);
        }
        for(z = 2*rows-2*i; z> 0; z--){
            printf(" ");
        }
        for (a = 1; a <= i; a++){
            printf("%d", i);
        }
        printf("\n");
    }
}
