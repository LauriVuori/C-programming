/*Write a function that will replace small case
character to upper case characters in a string
void to_lower(char *s);*/
#include <stdio.h>
#include <ctype.h>
int to_lower(char *s);
int main(void)
{
    char s[]="HellASDkOYaAo";
    to_lower(s);
    printf("%s", s);
}

int to_lower(char *s)
{
    int i=0;
    while(s[i] != '\0')
    {
    if(isupper(s[i])){
        s[i] = tolower(s[i]);
    }
    i++;
    }
}
