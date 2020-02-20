/*Using  function, made in Exercise 3, write a C program that will ask two numbers,
Voltage and Resistance, from user (using same function to read both) and calculate current and power consumption*/

#include <stdio.h>
int ask_integer_number(int Vmin, int Vmax, int Rmin, int Rmax);
int main(void){
    int ok = 1;
    int max, min;
    int numVmin, numVmax, numRmin, numRmax;

    printf("Give min voltage value:\n");
    scanf("%d", &numVmin);
    printf("Give max voltage value:\n");
    scanf("%d", &numVmax);

    printf("Give min resistance value:\n");
    scanf("%d", &numRmin);
    printf("Give max resistance value:\n");
    scanf("%d", &numRmax);


    while(ok == 1){
    ok=ask_integer_number(numVmin, numVmax, numRmin, numRmax);
    }
    printf("Program shuts down");
}


int ask_integer_number(int Vmin, int Vmax, int Rmin, int Rmax){
    int Vvalue;
    int Rvalue;
    float ampers;
    float power;

    printf("Give number between Voltage min:%d and max:%d\n", Vmin, Vmax);
    scanf("%d", &Vvalue);
    printf("Give number between Resistance min:%d and max:%d\n", Rmin, Rmax);
    scanf("%d", &Rvalue);

    if((Vvalue>= Vmin && Vvalue <= Vmax)&&(Rvalue >= Rmin && Rvalue <= Rmax)){
        printf("Voltage was in range (%d-%d) Resistance was in range (%d-%d):\n", Vmin, Vmax, Rmin, Rmax);
        ampers = (float)Vvalue/Rvalue;
        power = Vvalue*ampers;
        printf("Power consumption in %d ohm resistance with %d V voltage is %0.2f W and current is %0.2f A\n", Rvalue, Vvalue,power, ampers);
        return 1;
    }
    else{
        printf("Voltage or resistance was not in range (%d-%d) (%d-%d)\n", Vmin, Vmax, Rmin, Rmax);
        return 0;
    }
}
