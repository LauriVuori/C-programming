/*Write a function  (just function, main is already inside this test)that will return the count of  occurens of character in a string

int occurens(char s[],char c);
 Return value:

0 if not found*/

#include <stdio.h>
int occurens(char s[],char c);
int main(void){
    char s[]="Hello";
    printf("%d",occurens(s,'l'));
}

int occurens(char s[],char c){
    int i;
    int counter = 0;
    for (i = 0; s[i] != '\0'; i++){
        if(s[i] == c){
            counter++;
        }
    }
    if(counter > 0){
        return counter;
    }
    else{
        return 0;
    }
}