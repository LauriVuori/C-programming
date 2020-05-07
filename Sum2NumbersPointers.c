/*Write a program in C to add numbers using call by reference. Go to the editor
Test Data :
Input the first number : 5
Input the second number : 6
Expected Output :

 The sum of 5 and 6  is 11 */

#include <stdio.h>
void sumnumbers(int *p1, int *p2, int *psum);

int main(void){
    int num1, num2, sum;
    printf("Give number 1 \n");
    scanf("%d", &num1);
    printf("Give number 2 \n");
    scanf("%d", &num2);
    sumnumbers(&num1, &num2, &sum);
    printf("%d", sum);
}

void sumnumbers(int *p1, int *p2, int *psum){
    printf("Give number 1 \n");
    scanf("%d", p1);
    printf("Give number 2 \n");
    scanf("%d", p2);
    *psum = *p1 + *p2;
    printf("<%d>", *psum);

}