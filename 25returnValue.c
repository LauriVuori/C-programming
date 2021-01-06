#include <stdio.h>


void returnMoney(int * cash, int * ticket);

int main(void){
    int currentMoney = 500, ticket = 25;
    returnMoney(&currentMoney, &ticket);
    printf("%d\n", currentMoney);
    returnMoney(&currentMoney, &ticket);
    printf("%d\n", currentMoney);
    returnMoney(&currentMoney, &ticket);
    printf("%d\n", currentMoney);
}

void returnMoney(int * cash, int * ticket){
    *cash = *cash - *ticket;
}