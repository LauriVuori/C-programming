/*Write a C function

void leap_year(int year);
to print if year is a leap year?

In the Gregorian calendar, three criteria must be taken into account to identify leap years:

The year must be evenly divisible by 4;
If the year can be evenly divided by 100, it is not a leap year; unless,
The year is also evenly divisible by 400. Then it is a leap year.
Program output
Give year: 1972
Year is a leap year*/


#include <stdio.h>

void leap_year(int year);
int main(void){
    int askYear = 0;

    printf("Give year:\n");
    scanf("%d", &askYear);
    leap_year(askYear);
}



void leap_year(int year){
    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)){
       printf("Year is a leap year");

    }
    else{
        printf("Year is not a leap year");
    }
}

