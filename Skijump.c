/*a) Five referees that give points
print sum, give style multiplier
remove highest and lowest points*/
#include <stdio.h>

int main(void){

    int i, point, sum = 0;
    float avg = 0;
    float ref = 3;
    int highest = 0;
    int lowest = 1000;
    float jump = 0;
    float multip = 0;

    printf("How long jump was 0-130:\nLonger jump gives multiplier\n");
    scanf("%f", &jump);
    if(jump <= 40){
    multip = 0.6;
    }
    else if (jump <= 60){
    multip = 0.8;
    }
    else if (jump <= 80){
    multip = 1;
    }
    else if (jump <= 100){
    multip = 1.2;
    }
    else{
    multip = 1.4;
    }
    for(i=1; i <= 5; i++){
    printf("Give first %d.referees points from 0-10:\n", i);
    scanf("%d", &point);
    while((point >= 11) || (point <=0)){
        printf("Give higher than 0 or lower than 10\n");
        scanf("%d", &point);
    }

            if(highest <= point)
            {
            highest = point;
            }
            if(lowest >= point)
            {
            lowest = point;
            }

    sum += point;
    }
sum = sum - highest - lowest;
printf("Sum of points:%d", sum);
sum *= multip;
avg = sum / ref;
printf("Sum of points after multiplier is:%d\nAverage points are:%0.1f:", sum, avg);
printf("\nHighest:%d, Lowest:%d\n",highest, lowest);
printf("Multiplier:%0.1f", multip);
}
