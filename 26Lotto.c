/*
a) Kirjoita ohjelma, joka arpoo oikean lottorivin eli 7 numeroa ja 3 lisänumeroa. Mahdolliset numerot ovat 1-39.

b) Kehitä ohjelmaa siten, että se pyytää käyttäjältä tämän rivin, tulostaa oikean rivin ja ilmoittaa, kuinka monta numeroa ja lisänumeroa käyttäjällä oli oikein.

c) Arvo lottirivi ja oikea rivi. Laske montako kertaa pitää arpoa, jotta saadaan oikea rivi
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXNUMS 10

void randomizeNumbers(int * arNumbers, int * minNum, int * maxNum, int * numbersQuantity);

int main(void){
    int randomNum = 0;
    int userNumbers[MAXNUMS], correctNumbers[MAXNUMS], numbers[39] = {0};

    for (int i = 1; i <= MAXNUMS; i++){
        userNumbers[i] = 0;
        correctNumbers[i] = 0;
    }

    srand((unsigned) time(NULL));
    for (int i = 0; i < MAXNUMS; i++){
        randomNum = rand()%39+1;
        correctNumbers[i] = randomNum;
        for (int b = 0; b < i; b++){
            if (correctNumbers[i] == correctNumbers[b]){
                randomNum = rand()%39+1;
                correctNumbers[i] = randomNum;
                b = 0;
            }
        }
        numbers[correctNumbers[i]]++;
    }

    for (int i = 0; i < MAXNUMS; i++){
        randomNum = rand()%39+1;
        userNumbers[i] = randomNum;
        for (int b = 0; b < i; b++){
            if (userNumbers[i] == userNumbers[b]){
                randomNum = rand()%39+1;
                userNumbers[i] = randomNum;
                b = 0;
            }
        }
        numbers[userNumbers[i]]++;
    }

    // for (int i = 0; i < MAXNUMS; i++){
    //     printf("%d ", correctNumbers[i]);
    // }
    // printf("\n");
    // for (int i = 0; i < MAXNUMS; i++){
    //     printf("%d ", userNumbers[i]);
    // }
    printf("\n");
    int b = 0;
    for (int i = 0; i < MAXNUMS; i++){
        for (int b = 0; b < MAXNUMS; b++){
            if (correctNumbers[i] == userNumbers[b]){
                b++;
            }
        }
    }
    // for (int i = 0; i < MAXNUMS; i++){
    //     // printf("%d ", correctNumbers[i]);
    //     printf("%d ", userNumbers[i]);
    // }


    // printf("\n");
    // for (int i = 0; i < MAXNUMS; i++){
    //     randomNum = rand()%39+1;
    //     userNumbers[i] = randomNum;
    //     printf("%d ", userNumbers[i]);
    // }
    int *ptr = correctNumbers;
    randomizeNumbers(ptr,(int*)1,(int*)39,(int*)MAXNUMS);
}

void randomizeNumbers(int * arNumbers, int * minNum, int * maxNum, int * numbersQuantity){
    printf("%d %d %d %d", arNumbers[0], minNum, maxNum, numbersQuantity);
    for (int i = 0; i < numbersQuantity; i++){
        printf("%d %d %d %d\n", arNumbers[i], minNum, maxNum, numbersQuantity);
    }
    printf("end");
}
