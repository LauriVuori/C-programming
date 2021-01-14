
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 6
#define MIN 1

int main(void){
    int flips[7] = {0}, dieRoll1 = 0, dieRoll2 = 0;
    srand((unsigned) time(NULL));

    for (int i = 0; i <= 100000; i++){
        dieRoll1 = rand()% MAX + MIN;
        dieRoll2 = rand()% MAX + MIN;
        flips[dieRoll1]++;
        flips[dieRoll2]++;
    }
    for (int i = 1; i <= 6; i++){
        printf("Number %d flips= %d \n",i, flips[i]);
    }

}