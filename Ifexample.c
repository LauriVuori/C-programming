/*Kirjoita ohjelma, joka kysyy k�ytt�j�lt� lompakossa olevan raham��r�n ja lihapiirakan hinnan.

Ohjelma tutkii, onko k�ytt�j�ll� varaa ostaa lihapiirakka.
Jos on, ohjelma ilmoittaa, kuinka paljon lompakkoon j�� viel� rahaa.
Muuten ohjelma kehottaa k�ytt�j�� paastoamaan.

K�yt� vain kahta muuttujaa. �l� v�henn� lompakon sis�lt��, ellet voi ostaa lihapiirakkaa.*/
#include <stdio.h>
int main(void)
{
    int money, food;

    printf("How much money do you have?\n");
    scanf("%d", &money);
    printf("How much food costs\n");
    scanf("%d", &food);

    if(money < food){
        printf("You dont have enough money");
    }
    else{
        printf("You have %d � left in wallet", money - food);
    }
}
