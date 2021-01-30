#include <stdio.h>

int median(int *given_numbers, int array_length);
int main(void){
    // int my_array[]={66,-100,2,-7,99,123,-44,22,48,53,4};
    // printf("%d",median(my_array,11));  
    // int my_array[]={4,2,1,5,3};
    // printf("",median(my_array,5));
    int my_array[]={0,0,0,0,0,0,0,0,0};
    printf("%d",median(my_array,9));
}
int median(int *given_numbers, int array_length) {
    int temp;
    if ((array_length%2) == 0) {
        return 0;
    }

    for (int i = 0; i < array_length; i++) {
        for (int b = i+1; b < array_length; b++) {
            if (*(given_numbers+i) > *(given_numbers+b)) {
                temp = *(given_numbers+i);
                *(given_numbers+i) = *(given_numbers+b);
                *(given_numbers+b) = temp;
            }
        }
    }
    return *(given_numbers + ((array_length-1)/2));
}
