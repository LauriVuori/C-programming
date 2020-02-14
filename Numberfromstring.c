/*Write C-function that will take all numbers from a string
int strip_numbers(char *s);
return value:
New length of string*/
#include <stdio.h>
int strip_numbers(char *s);

int main(void)
{

char s[]="Hel3lo8";
printf("len=%d\n",strip_numbers(s));
printf("%s\n",s);

}

int strip_numbers(char *s)
{
int i = 0;
int b = 0;
char x[15];
while(s[i] != '\0')
{
    if(s[i]<'0' || s[i]>'9'){
        x[b]=s[i];
        b++;
        }
    i++;
}
x[b]='\0';
strcpy(s, x);
return b;
}

