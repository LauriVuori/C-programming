/*Write a C function that will remove ALL newlines from end of function. (This is very handy later when reading strings with fgets)

void clean_nl_from_sring(char s[]);
Esimerkiksi:

Testi	Tulos
char s[]="Hello world\n";
clean_nl_from_sring(s);
printf("<%s>",s);
                            <Hello world>
char s[]="Hello world\n\n\n";
clean_nl_from_sring(s);
printf("<%s>",s);
                                <Hello world*/

#include <stdio.h>

void clean_nl_from_sring(char s[]);

int main(void){
    char s[]="Hello world\n";
    clean_nl_from_sring(s);
    printf("<%s>",s);
}

void clean_nl_from_sring(char s[]){
    int i,a = 0;
    char tempS[50];
    
    for (i = 0; s[i] != '\0'; i++){
        if (s[i] != '\n'){
            tempS[a] = s[i];
            a++;
        }
    }
    tempS[a] = '\0';
    
    for (i = 0; tempS[i] != '\0'; i++){
        s[i] = tempS[i];
    }
    s[i] = '\0';
}