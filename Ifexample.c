/*Kirjoita ohjelma, joka kysyy käyttäjältä lompakossa olevan rahamäärän ja lihapiirakan hinnan.

Ohjelma tutkii, onko käyttäjällä varaa ostaa lihapiirakka.
Jos on, ohjelma ilmoittaa, kuinka paljon lompakkoon jää vielä rahaa.
Muuten ohjelma kehottaa käyttäjää paastoamaan.

Käytä vain kahta muuttujaa. Älä vähennä lompakon sisältöä, ellet voi ostaa lihapiirakkaa.*/
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
        printf("You have %d € left in wallet", money - food);
    }
}
