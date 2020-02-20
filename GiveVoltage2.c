#include <stdio.h>

#define VMAX 100
#define VMIN 0
#define RMAX 65
#define RMIN 1
int ask_integer_number(int min, int max);
int main(void){
    int voltage=0;
    int resistance=0;
    float ampers=0;
printf("Give Voltage between %d and %d:", VMIN,VMAX);
voltage = ask_integer_number(VMIN,VMAX);
printf("Give Resistance between %d and %d:", RMIN,RMAX);
resistance = ask_integer_number(RMIN,RMAX);
ampers = (float)voltage/resistance;
printf("Power consumption in %d ohm resistance with %d V voltage is %0.0f W and current is %0.1f A", resistance, voltage,(float)voltage*ampers, ampers);



}

int ask_integer_number(int min, int max){
    int number = 0;
    scanf("%d", &number);
        while(number<=min || number>= max){
            printf("Number was not in range (%d-%d):", min,max);
            scanf("%d", &number);
        }
    return number;
}
