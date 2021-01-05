/*Tehtävä 21
Kirjoita funktio, joka pyytää käyttäjältä luvun annetulta väliltä ja tarkistaa luvun kelvollisuuden.

Mikäli luku ei ole annetulla välillä tai se ei ole numeerinen, sitä pyydetään funktiossa uudelleen. '

Funktio palauttaa kutsujalleen käyttäjän syöttämän luvun.

Funktiota kutsutaan seuraavasti:

luku = pyyda_luku_valilta (alaraja, ylaraja);
Käytä funktiossa sscanf()-funktion palauttamaa arvoa, joka ilmaisee onnistuneiden syötteiden lukumäärän:

    gets (rivi);
    onnistui = sscanf (rivi,"%f",&syote);
    while (onnistui != 1 /* tai luku ei ole välillä */
    // {
        // printf ("Virheellinen syöte!")
        /* tässä täytyy lukea uudelleen */
    // }
/*
Jos sscanf() onnistuu lukemaan yhden syötteen, onnistui-muuttuja saa arvon 1. 
Jos arvoksi tulee 0, syöte ei ole numeerinen. Mikäli käyttäjä antaa syötteeksi pelkän ENTER:n painalluksen, sscanf() palauttaa arvon -1.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int askNumber(int max, int low);

int main(void) {
    int num, max, min, isNum;
    char row[25];
    printf("Give two numbers:\n");
    gets(row);
    isNum = sscanf(row, "%d %d", &max, &min);
    while (isNum != 2){
        printf("Give TWO numbers:\n");
        gets(row);
        isNum = sscanf(row, "%d %d", &max, &min);
    }
    num = askNumber(max, min);
    if (num != 1) {
        printf("%d is not between %d-%d", num, max, min);
    }
    else {
        printf("%d is between %d-%d", num, max, min);
    }
}

int askNumber(int max, int low) {
    int isNumber;
    float checkNumber;
    char row[25];
    printf("Give number between %d-%d:\n", max, low);
    gets(row);
    isNumber = sscanf (row,"%f", &checkNumber);
    while (isNumber != 1) {
        printf ("is not a number\n");
        printf("Give new number:");
        gets(row);
        isNumber = sscanf (row,"%f", &checkNumber);
    }
    return isNumber;
}