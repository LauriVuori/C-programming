/*Write a function  (just function, main is already inside this test)  that will compare two strings if they are mach

int str_compare(char s[],char d[]);
 Return value:
0 if strings are same
-1 if s is before d in alphabets
+1 if d is before s in alphabets
Esimerkiksi:

Testi	Tulos
char s[]="Hello";
char d[]="Hello";
printf("%d",str_compare(s,d));
*/

#include <stdio.h>
int str_compare(char s[],char d[]);
int main(void){
    char s[]="Hell";
    char d[]="Hello";
    printf("%d",str_compare(s,d));
}

int str_compare(char s[],char d[]){
    int i;
    int a;
    int lenght = 0;
    for (a = 0; s[a] != '\0'; a++){
    }

    int b;
    for (b = 0; d[b] != '\0'; b++){
    }

    if (a>b){
        lenght = a;
    }
    else{
        lenght = b;
    }
    for (i = 0; i <= lenght; i++){
        if (s[i] != d[i]){
            
            if (s[i] < d[i]){
                return -1;
            }
            
            else{
                return 1;
            }
        }
    }

    return 0;
}