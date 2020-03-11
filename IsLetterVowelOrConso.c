/*Write C function (just function, main is done by exercise)

int vowel(char letter);
that will check if character is a vowel.

return value:

1 character is vowel
0 character is consonant
-1 if character is not a letter
Use Finnish vowel settings (Y is a vowel) but only characters from A-Z are checked, case of letter should not affect to result

Esimerkiksi:

Testi	Tulos
printf("%d",vowel('a'));
1*/
#include <stdio.h>
int vowel(char letter);
int main(void){

    printf("%d",vowel('p'));
}

int vowel(char letter){
    if(letter>= 'A' && letter <= 'Z'){
        letter += 32;
    }
    if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' || letter == 'y'){
        return 1;
    }
    
    if(letter>= 'a' && letter <= 'z')
    if(letter != 'a' || letter != 'e' || letter != 'i' || letter != 'o' || letter != 'u'){
        return 0;
    }

    else{
        return -1;
    }
}