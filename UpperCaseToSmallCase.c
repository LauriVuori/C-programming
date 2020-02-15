/*Write a function that will replace upper case
character to lower case characters in a string
void to_lower(char *s);*/
#include <stdio.h>
void to_lower(char *s);
int main(void)
{
    char s[]="AsAddFFGrEa";
    to_lower(s);
    printf("%s", s);
}

void to_lower(char *s)
{
    int i=0;
    while(s[i] != '\0')
    {
        if(s[i]>='A' &&  s[i]<='Z'){
        s[i] += 32;
        }
    i++;
    }
}
