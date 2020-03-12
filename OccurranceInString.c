/*
Write a C function  (just function, main is already inside this test) that will display the occurrence of characters in a s

void display_occurrence(char s[]);
Small and capital characters are counted as separate
*/
#include <stdio.h>
void display_occurrence(char s[]);
int main(){
display_occurrence("");
}

void display_occurrence(char s[])
{
int i = 0, x;
int count[51] = {0};

    while (s[i] != '\0') {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')){
            x = s[i] - 'A';
            count[x]++;
        }
        i++;
    }

    for (i = 0; i < 51; i++){
        if(count[i]> 0){
        printf("'%c'=%d\n", i + 'A', count[i]);
        }
    }
}