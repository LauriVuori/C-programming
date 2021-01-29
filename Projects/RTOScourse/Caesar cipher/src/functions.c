#include <stdio.h>
#include <string.h>
#include <header.h>



void encode_message(char * original, char * coded) {
    int lenght = 0, colum = 0, row = 0;
    char intermediate_message[50][5];
    // *original = '\0';
    printf("\nGive string to encode:\n");
    fgets(original, 50, stdin);
    lenght = calculateLen(original);
    while (lenght <= 8) {
        printf("\nToo short message,(min.8) Give string to encode:\n");
        fgets(original, 50, stdin);
        lenght = calculateLen(original);
    }

    lenght--;
    original += lenght;
    while ((lenght%4) != 0) {
        *original = 32;
        original++;
        lenght++;
    }
    *original = '\0';
    original -= lenght;

    int maxrows = lenght / 4;

    for (int i = 0; i <= 4; i++) {
        for (int b = 0; b < maxrows; b++) {
                intermediate_message[b][i] = *original;
                *original++;
        }
    }
    printf("Encoding:\n");
    for (int i = 0; i < maxrows; i++) {
        for (int b= 0; b < 4; b++) {
            printf("%c ", intermediate_message[i][b]);
            *coded = intermediate_message[i][b];
            coded++;
        }
        printf("\n");
    }
    *coded = '\0';
}