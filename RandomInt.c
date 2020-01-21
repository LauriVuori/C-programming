#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(void)
{
    int x = 1, quess = 2, tries = 0;
    char TryAgain;
    srand(time(NULL));
while(TryAgain != 'n'){
    //If you want try again, need to pass back to loop quess != x
    x = 1;
    quess = 2;
    //reset tries calculator
    tries= 0;

while(quess != x){
    // Do this loop while quess is different than x
    printf("Quess one number 0-10:\n");
    scanf("%d", &quess);

    // give x random num from 0-10
    x = rand() % 1;
    // +1 tries every loop
    tries += 1;

    if(quess < x){
        printf("Quess is too low. Computers: %d, Yours: %d\n", x, quess);
    }
    if(quess > x){
        printf("Quess is too high. Computers: %d, Yours: %d\n", x, quess);
    }
    if(quess == x){
        printf("Its correct. Computers: %d, Yours: %d\n", x, quess);
        printf("You tried: %d times\n", tries);
        printf("Do you want to continue y/n\n");
        scanf(" %c", &TryAgain);
    }
}
}
    return 0;
}
