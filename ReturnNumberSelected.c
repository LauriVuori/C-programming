/*Write C-function that will return number of selected items in array,

size of array given as parameter c
item is counted item
int occurence_array(int a[], int item, int c);

example:

Test	                        Result
int a[]={1,2,3,4,5,66,4,8};
printf("%d",occurence(a,4,7));  2*/

#include <stdio.h>

int occurence(int a[], int item, int c);

int main(void){
int a[]={1,2,3,4,5,66,4,4};

printf("%d",occurence(a,4,7)); // You can change these values
}

int occurence(int a[], int item, int c){
    int count = 0;
    for(int i = 0; i<=c; i++){
        if(a[i] == item){
        count ++;
        }
    }
    return count;
}
