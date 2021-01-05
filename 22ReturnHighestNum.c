#include <stdio.h>


int askPositiveNumbers(int *numbers);

int main(void){
    char input[25];
    int numbers[25] = {1,2,4,5,46,7,8,9,10}, highest;
    int *ptr;
    // printf("Give ten numbers:\n");
    // for (int i = 0; i < 10; i++){
    //     // gets(input);
    //     // sscanf(input, "%d", numbers[i]);
    //     printf("give num %d:", i+1);
    //     scanf("%d", &numbers[i]);
    // }
    ptr = numbers;
    highest = askPositiveNumbers(ptr);
    printf("Highest number is: %d", highest);
}

int askPositiveNumbers(int *numbers){
    int highest = -1000;
    for (int i = 0; i < 10; i++){
        printf("%d ", numbers[i]);
        if (numbers[i] >= highest){
            highest = numbers[i];
        }
    }
    return highest;
}