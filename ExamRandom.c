#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN_RAND 0
#define MAX_RAND 11
int main(void)
{
 srand(time(NULL));

    int array[15];
    int number=0;
    for(int i = 0; i<=15; i++)
    {
    array[i] = rand()%MAX_RAND+MIN_RAND;
    }
        for(int i = 0; i<=15; i++){
            number = array[i];
            printf("\n%d:",i);
            for(int i = 0; i<=number; i++){
            printf("*");
            }
        }
}
