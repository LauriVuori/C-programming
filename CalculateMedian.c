/*Write C function that will calculate the median value form array of integers

 int median( int given_numbers[],  int array_length):
Esimerkiksi:

Testi	Tulos
int my_array[]={4,2,1,5,3};
printf("%d",median(my_array,5));
*/

#include <stdio.h>

int median( int given_numbers[],  int array_length);
int main(void){
    int my_array[]={66,-100,2,-7,99,123,-44,22,48,53,4};
    printf("<%d>",median(my_array,11));
    //2,4,1,5,3

}

int median( int given_numbers[],  int array_length){
    int i,a;
    int temp = 0;
    float median = 0;
    
    for(i = 0; i < array_length; i++){
        for(a=i+1; a< array_length; a++){
            if(given_numbers[i]>given_numbers[a]){
                temp = given_numbers[i]; //4
                given_numbers[i] = given_numbers[a]; // 2, 
                given_numbers[a] = temp;
                temp = 0;
            }
        }
    }
    if(array_length%2 == 0){
        array_length = array_length/2;
        median = ((float)array_length + ((float)array_length+1))/2;

        return median;
    }
    else{
        median = (array_length/2 + 1);
        printf("%f", median);
        median = i;
        printf("<<<%d>>>", given_numbers[i]);
    }
    return given_numbers[i];
}
