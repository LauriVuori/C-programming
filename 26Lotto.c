/*
a) Kirjoita ohjelma, joka arpoo oikean lottorivin eli 7 numeroa ja 3 lisänumeroa. Mahdolliset numerot ovat 1-39.

b) Kehitä ohjelmaa siten, että se pyytää käyttäjältä tämän rivin, tulostaa oikean rivin ja ilmoittaa, kuinka monta numeroa ja lisänumeroa käyttäjällä oli oikein.

c) Arvo lottirivi ja oikea rivi. Laske montako kertaa pitää arpoa, jotta saadaan oikea rivi
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXNUMS 7

void randomizeNumbers(int * arNumbers, int * minNum, int * maxNum, int * numbersQuantity);

int main(void){

    int randomNum = 0, minNum = 1, maxNum = 39, qnty = MAXNUMS, correctNums = 0, randTimes = 0, found = 0;
    int userNumbers[MAXNUMS], correctNumbers[MAXNUMS], numbers[39] = {0};
    srand((unsigned) time(NULL));
    for (int i = 0; i < MAXNUMS; i++){
        userNumbers[i] = 0;
        correctNumbers[i] = 0;
    }
    randomizeNumbers(&correctNumbers[0], &minNum, &maxNum, &qnty);

    while (found <= 30) {
        correctNums = 0;
        randomizeNumbers(&userNumbers[0], &minNum, &maxNum, &qnty);
        for (int i = 0; i < MAXNUMS; i++){
            for (int b = 0; b < MAXNUMS; b++){
                if (correctNumbers[i] == userNumbers[b]){
                    correctNums++;
                }
            }
        }
        randTimes++;
        if (correctNums >= 7){
            found++;
        }
    }
    float test = (float)randTimes / 30;
    printf("%0.0f", test);
    
    
    // for (int i = 0; i < MAXNUMS; i++){
    //     randomNum = rand()%39+1;
    //     correctNumbers[i] = randomNum;
    //     for (int b = 0; b < i; b++){
    //         if (correctNumbers[i] == correctNumbers[b]){
    //             randomNum = rand()%39+1;
    //             correctNumbers[i] = randomNum;
    //             b = 0;
    //         }
    //     }
    //     numbers[correctNumbers[i]]++;
    // }

    // for (int i = 0; i < MAXNUMS; i++){
    //     randomNum = rand()%39+1;
    //     userNumbers[i] = randomNum;
    //     for (int b = 0; b < i; b++){
    //         if (userNumbers[i] == userNumbers[b]){
    //             randomNum = rand()%39+1;
    //             userNumbers[i] = randomNum;
    //             b = 0;
    //         }
    //     }
    //     numbers[userNumbers[i]]++;
    // }

    // for (int i = 0; i < MAXNUMS; i++){
    //     printf("%d ", correctNumbers[i]);
    // }
    // printf("\n");
    // for (int i = 0; i < MAXNUMS; i++){
    //     printf("%d ", userNumbers[i]);
    // }

 
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

}

void randomizeNumbers(int * arNumbers, int * minNum, int * maxNum, int * numbersQuantity){
    int randomNum = 0;
        for (int i = 0; i < *numbersQuantity; i++){
            randomNum = rand()% *maxNum + *minNum;
            arNumbers[i] = randomNum;
            for (int b = 0; b < i; b++){
                if (arNumbers[i] == arNumbers[b]){
                    randomNum = rand()%39+1;
                    arNumbers[i] = randomNum;
                    b = 0;
                }
            }
        }
}
