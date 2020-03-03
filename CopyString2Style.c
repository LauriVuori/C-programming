#include<stdio.h>
#include <string.h>

int main(void){
char s[25];
char b[25];
char c[25];
int i;
strcpy(s, "This is a string");
strcpy(c, s);
printf("s:%s\n", s);
printf("c:%s\n", c);
for(i = 0; s[i] != '\0'; i++){
    b[i] = s[i];
}
b[i] = '\0';
printf("b:%s\n", b);
}
