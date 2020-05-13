/*In shop there are 500 different products, that are identified by number 1-500.
Make a program that can store amount of articles in a table. Program will 
ask the product number and article amount and store them in one dimension table.
Articles are inquired one by one, and after each article program will ask 
if user will enter new product (yes/no-question).*/


#include <stdio.h>
#define ARRAY_SIZE 50
struct product{
    int prod_amount;
    float prod_price;
};

void ask_prodamount(struct product info[ARRAY_SIZE]);
void print_products(struct product info[ARRAY_SIZE]);
void print_menu();

int main(void){
    struct product info[ARRAY_SIZE] = {0};
    char command;

    do{
        print_menu();
        scanf("%c", &command);
        switch (command)
        {
        case '1':
            ask_prodamount(info);
            break;
        
        default:
            break;
        }
    }while(command != 'n');    
}

void print_menu(){
    printf("1: ask prods\n");
    printf("n exit\n");
}


void ask_prodamount(struct product info[ARRAY_SIZE]){
int amount = 0, item_num = 0;
    printf("Give product name:\n");
    scanf("%d", &item_num);
    printf("Give product amount:\n");
    scanf("%d", &amount);

    info[5].prod_amount = amount;
}

void print_products(struct product info[ARRAY_SIZE]){
int i;
    for (i = 0; i < ARRAY_SIZE; i++){
        printf("%d: %d\n",i, info[i].prod_amount);
    }
}