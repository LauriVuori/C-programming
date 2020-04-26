#include <stdio.h>
/*Write a C_ function that will count seconds of day starting from midnight*/

struct time_t{ 
    int hours; 
    int minutes; 
    int seconds; 
};

unsigned int count_seconds(struct time_t time);

int main(void){
    struct time_t time = {12,11,12};
    printf("%d",count_seconds(time));
    
}

unsigned int count_seconds(struct time_t time){

    unsigned int sum_seconds = 0;
    sum_seconds += time.hours * 60 * 60;
    sum_seconds += time.minutes * 60;
    sum_seconds += time.seconds;
    return sum_seconds;
}