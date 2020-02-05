/*Write function that raffles even numbers
Lauri Vuori*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXINT 100
#define MININT 1
int main(void)
{
srand (time(NULL));
int useFunction;
int Fuse;

printf("How many times you want to raffle:\n");
scanf("%d", &Fuse);
useFunction=raffle(Fuse);

}

void raffle(int times)
{
    int even;
    for(int i = 1; i<= times; i++){
    even = rand()%MAXINT+MININT;
    while(even%2 != 0){
    even = rand()%MAXINT+MININT;
    }
    printf("%2d:%2d\n",i,even);
    }
}
