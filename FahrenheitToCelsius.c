/*Program that asks Celsius degrees and
converts them to fahrenheit. Formula C = 5/9 x (F-32)
or F=1.8*C+32
-Lauri Vuori*/

#include <stdio.h>

int main(void)
{
    float celsius;
    float fahrenheit;

    printf ("How many degrees of celsius there is:\n");
    scanf ("%f", &celsius);

    fahrenheit = 1.8 * celsius + 32;

    printf ("There is: %0.2f fahrenheits", fahrenheit);
return 0;
}
