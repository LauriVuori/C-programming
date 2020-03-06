/*Write a C-function that will copy array a to array b, 
int c is holding the size of original array

void copy_array(int *a, int *b, int c);*/
#include <stdio.h>
void copy_array(int *a, int *b, int c);

int main (void){
int a[]={0,1,2,3,4,5};
int b[10];
int i;
copy_array(a,b,6);
    for(i=0;i<6;i++){
        printf("%d ",*(b+i));
    }
}



void copy_array(int *a, int *b, int c){
   int i;
   for(i= 0; i < c; i++){
       b[i] = a[i];
   }
}