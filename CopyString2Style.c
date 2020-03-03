#include<stdio.h>
#include <string.h>

int main(void){
char s[25];
char b[25];
int i;
strcpy(s, "This is a string");
printf("s:%s\n", s);
for(i = 0; s[i] != '\0'; i++){
    b[i] = s[i];
}
b[i] = '\0';
printf("b:%s\n", b);
}
