/*Write a C function that will print a cryptographically altered string, using chipper ROT13 algorithm,

"ROT13 ("rotate by 13 places", sometimes hyphenated ROT-13) is a simple letter substitution cipher that replaces a letter with the 13th letter after it, in the alphabet. ROT13 is a special case of the Caesar cipher which was developed in ancient Rome."

(https://en.wikipedia.org/wiki/ROT13)

Esimerkiksi:

Testi	Tulos
char s[]="Why did the chicken cross the road";
rot13(s);
printf("<%s>",s);
<Jul qvq gur puvpxra pebff gur ebnq>
char s[]="Gb trg gb gur bgure fvqr";
rot13(s);
printf("<%s>",s);
<To get to the other side*/
#include <stdio.h>
void rot13(char s[]);
int main(void){
    char s[]="Why did the chicken cross the road";
    //       <Jul qvq gur puvpxra pebff gur ebnq>
    rot13(s);
    printf("<%s>",s);
}

void rot13(char s[]){
    int i;

    for (i = 0; s[i] != '\0'; i++){
        if ((s[i] >= 'A' && s[i] <= 'M') || (s[i] >= 'a' && s[i] <= 'm')){
            s[i] += 13;
        }
        else if ((s[i] >='N' &&  s[i] <= 'Z') || (s[i] >= 'n' && s[i] <= 'z')){
            s[i] -= 13;
        }

    }
}