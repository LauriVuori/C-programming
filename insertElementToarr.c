#include <stdio.h>
// Write a C function that will insert a element into array

void insert_element(int *array, int size, int number_to_be_inserted, int position);

int main(void) {
    int a[11]={1,2,3,4,6,7,8,9,0};

    insert_element(a,9,5,4);

    for (int i=0;i<10;i++){
        printf("%d ",a[i]);
    }
}

void insert_element(int *array, int size, int number_to_be_inserted, int position) {
    if (size > 1) {
        for (int i = size-1; i >= position; i--) {
                *(array+i) = *(array+i-1);
        }
    }
    else{
        *(array+size) = *(array);
    }
    *(array+position) = number_to_be_inserted;
}
