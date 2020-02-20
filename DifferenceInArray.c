/*Write a C function that will return the difference between of maximum and minimum values of an array

Array is ended with value 0 (the last element is zero)

Array is filled by user input in main and the maximum size of array is defined with named constant MAX_ARRAY

Function prototype is
double difference(double array[]); */

#include <stdio.h>
const int MAX_ARRAY=1000;

double difference(double array[]);
int main(void){
    double Mainarray[MAX_ARRAY];
    int i = 0;
    double x = 0;
    printf("Give an array:\n");

    while(Mainarray[i-1] != 0){
        scanf("%lf", &Mainarray[i]);
        i++;
    }
    difference(Mainarray);
}


double difference(double array[]){

    int i = 0;
    int min = 1000;
    int max = -1000;
    double difference= 0;

    while(array[i] != '\0'){

        if(array[i]<min){
            min=array[i];
        }
        if(array[i]>max){
            max=array[i];
        }
        i++;
    }
    difference = abs(min) + max;
    printf("The difference of elements in array is: %0.2lf", difference);
}
