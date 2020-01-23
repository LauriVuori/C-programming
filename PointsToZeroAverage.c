/* user gives points, untill given 0
count average from given numbers.
print smallest given number
-Lauri Vuori*/

#include <stdio.h>
int main(void)
{

    float points, average, sum = 0;
    int counter = 0;
    float low = 10000;

    while(points != 0){
        printf("Give number, 0 to stop:\n");
        scanf("%f", &points);
        if(points > 0){
        counter += 1;
        sum += points;
        printf("sum is:%0.0f\n", sum);
        printf("counter is:%d\n", counter);
        if(low > points){
            low = points;
            printf("new smallest number:%0.0f\n", low);
        }
        }
    }
    average = sum/counter;
    printf("Average is %0.2f, smallest number given: %f", average, low);
}
