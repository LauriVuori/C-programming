/*You are driving to school. You look at the clock. The is x minutes to class and
there is y kilometers left. Program that prints what is average speed (km/h) that
you get school before start*/
#include<stdio.h>

int main(void){
    float minutes, distance;
    float avSpeed;

    printf("How many minutes left to lessons start:\n");
    scanf("%f", &minutes);

    printf("How many kilometers left to drive: \n");
    scanf("%f", &distance);

    avSpeed = distance/(minutes/60);

    printf("You need to drive %0.1f km/h to get before start.\n", avSpeed);



}
