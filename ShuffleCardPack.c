/*Shuffle 52 card pack*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Shuffle(int *Ci, int *Ri);

int main(void){
    int cards[52]= {0};
    int i = 0;
    int r = 0;
    srand((unsigned) time(NULL));

    for (i = 0; i <= 51; i++){
        cards[i] = i; 
    }

    for (i = 0; i <= 51; i++){
    r = rand()%(52-i)+i;
    Shuffle(&cards[i], &cards[r]);
    }

    for (i = 0; i <= 51; i++){
        printf("%d\n", cards[i]);
    }

}

void Shuffle(int *Ci, int *Ri){
    int  temp;
    temp = *Ci;
    *Ci = *Ri;
    *Ri = temp;
}