#include <stdio.h>

void trimRight(char a[]);

int main(void){
    char a[]="hello\n   \r   ";
    trimRight(a);
    printf("<%s>",a);
}

void trimRight(char a[]){
    int i = 0;
    int lenght = 0;
    for (i = 0; a[i] != '\0'; i++){   
    }
    lenght = i;
    while(a[lenght-1] ==' ' || a[lenght-1] =='\n' || a[lenght-1] =='\r'){
        lenght--;
    }
    a[lenght] = '\0';
}