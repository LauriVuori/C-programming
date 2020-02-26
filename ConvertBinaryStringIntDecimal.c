/*write C function that will convert binary string int decimal

unsigned int hex_to_dec(char *s);


if string has characters that cannot be converted to
decimal or conversion value is too big (32 bit value) function shall return -1*/

#include <stdio.h>
#include <math.h>
#include <string.h>

unsigned int hex_to_dec(char *s);

int main(void){
char x[]="1FFFFF";
printf("%d",hex_to_dec(x));
}

unsigned int hex_to_dec(char *s)
{
    int power = 0;
    int lenght = 0;
    long int val = 0;
    int i;
    while(s[lenght]!= '\0')
    {
    lenght ++;
    }
    lenght --;
    for(i = 0; s[i] != '\0'; i++)
    {
     if(s[i]>='0' && s[i]<='9')
        {
            power = s[i] - 48; // 1
            val += power * pow(16, lenght); // 1 * 16^1
        }
    else if(s[i]>='a' && s[i]<='f')
    {
        power = s[i] - 97 + 10;
        val += power * pow(16, lenght);
    }
    else if(s[i]>='A' && s[i]<='F')
    {
    power = s[i] - 65 + 10;
    val += power * pow(16, lenght);
    }
    else{
    return -1;
    }
    lenght --;
    power = 0;
}
if(val >= 2147483647 || val <= -2147483646){
    return -1;
}
return val;
}
