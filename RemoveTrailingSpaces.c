/*Write a function to remove all trailing blanks from the right end of a string. 
Assume the prototype is
void trimRight(char a[]);
*/


#include <stdio.h>
void trimRight(char a[]);

int main(void){
char a[]="hel  lasdo       ";
trimRight(a);
printf("<%s>",a);
}

void trimRight(char a[]){
    int i = 0;
    int lenght = 0;
    for (i = 0; a[i] != '\0'; i++){   
    }
    lenght = i;
    while(a[lenght-1] ==' '){
        lenght--;
    }
    a[lenght] = '\0';
}