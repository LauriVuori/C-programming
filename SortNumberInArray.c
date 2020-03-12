/*Write a C function for sorting the elements in array
Write a C function for sorting the elements in array

void sort_array(int array[]);
Use constant for defining the size of an array*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>


const int MAX = 25;

void sort_array(int array[]);
int main(void){
    srand(time(NULL));
    int arr[MAX];

    for(int i = 0; i<= MAX; i++){
        arr[i] = rand() %100 -50;
    }

    printf("Content of array is:");
    for(int i = 0; i<=MAX; i++){
        printf("%d,", arr[i]);
    }
    printf("\n");
    sort_array(arr);
}

void sort_array(int array[]){
    int i;
    int a;
    int save1;
    int save2;
    for(i = 0; i<=MAX; i++){
        for(a = i; a<=MAX; a++){
            if(array[i] > array[a]){
            save1 = array[a];
            save2 = array[i];
            array[i] = save1;
            array[a] = save2;
            }
        }
    }

    printf("Content of sorted array is:");
    for(i = 0; i<=MAX; i++){
        printf("%d,", array[i]);
    }
}

