/*Write C-function that will return the index number to the biggest number in array, size of array given as parameter

int find_big(int a[], int c);*/

#include <stdio.h>

int find_big(int a[], int c);
int main(void){
    int a[]={1,2,3,4,5,66,7,8};
    printf("%d",find_big(a,7));
}


int find_big(int a[], int c)
{
    int i;
    int biggest = 0;
    int index = 0;
    for (i = 0; i<c; i++){
    if(a[i] > biggest){
        biggest = a[i];
        index = i;
        }
    }
    return index;
}