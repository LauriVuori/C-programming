/*Write C-function that will take all letters from a string. Letters can be small and capital letters a-z

int strip_letters(char *s);

return value:

New length of string
Esimerkiksi:

Testi	Tulos
char s[]="0He8llo";
printf("len=%d\n",strip_letters(s));
printf("%s\n",s);*/

#include <stdio.h>
int strip_letters(char *s);
int main(void){
char s[]="0He8llo#&";
printf("len=%d\n",strip_letters(s));
printf("%s\n",s);
}

int strip_letters(char *s){
    int i = 0;
    int a = 0;
    char z[15] ={};
    while(s[i] != '\0')
    {
        if((s[i]>='A' && s[i]<='Z')||(s[i]>='a' && s[i]<='z')){
        //you can put else inside here to strip all other than letters
        }
        else{
        z[a] = s[i];
        a++;
        }
    i++;
    }
z[a] = '\0';
strcpy(s,z);
return a;
}

