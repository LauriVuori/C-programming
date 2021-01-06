#include <stdio.h>

// Kirjoita funktio, joka palauttaa arvonaan parametrina välitetyn luvun itseisarvon.

// Kirjoita myös pääohjelma, jossa käytät funktiota.

int absoluteValue(int * num);

int main(void){
    int num;
    printf("Give number:\n");
    scanf("%d", &num);
    num = absoluteValue(&num);
    printf("%d", num);

}

int absoluteValue(int * num){
    int abs = 0;
    // abs = *num;
    if (*num < 0){
        while (*num < 0){
            abs++;
            *num = *num + 1;
            // printf("<%d>\n", *num);
        }
    return abs;
    }
    abs = *num;
    return abs;
}