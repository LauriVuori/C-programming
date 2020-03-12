#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 40
#define MIN_RAND 1
#define MAX_RAND 39
int main(void){
    srand(time(NULL));

    int array[SIZE] = {0};
    int i;
    int index = 0;
    for(i = 1; i <= 7 ; i++){
        index = rand()%MAX_RAND+MIN_RAND; //25

        if(array[index] == 0){ // 25 = 0
            array[index]++;     // [25]= 1
        }
        else{                   // 25 = 1
            while(array[index] == 1){
                index = rand()%MAX_RAND+MIN_RAND;
            }
            array[index]++;
        }
    }
    int count = 0;
    printf("User played numbers:");
    for(int i = 1; i <= 39; i++){

        if(array[i] != 0){
            count++;
            printf("%d%s",i,(count<7)?",":" ");
        }
    }
}

