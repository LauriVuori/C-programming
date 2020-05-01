/*Write a C_ function that will count difference with two times in seconds*/

#include <stdio.h>

struct time_t { 
    int hours; 
    int minutes; 
    int seconds; 
};

int time_diff(struct time_t time1, struct time_t time2);

int main(void){
struct time_t time1={12,12,12};
struct time_t time2={12,12,12};
    printf("%d",time_diff(time1,time2));

}
int time_diff(struct time_t time1, struct time_t time2){
    unsigned int sum_seconds1 = 0, sum_seconds2 = 0, difference = 0;
    sum_seconds1 += time1.hours * 60 * 60;
    sum_seconds1 += time1.minutes * 60;
    sum_seconds1 += time1.seconds;
    sum_seconds2 += time2.hours * 60 * 60;
    sum_seconds2 += time2.minutes * 60;
    sum_seconds2 += time2.seconds;
    difference = sum_seconds1 - sum_seconds2;
    return difference;
    
}