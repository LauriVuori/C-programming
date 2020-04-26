#include <stdio.h>
void swap(char *a, char *b);

int main(void){
    char a='a',b='b';
    swap(&a,&b);
    printf("%c %c",a,b);
}

void swap(char *a, char *b){
    char c, d;
    c = *a;
    d = *b;
    *a = d;
    *b = c;
}
