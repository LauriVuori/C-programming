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
void print_added_products(int item_num, int amount);
char ask_command();
void print_menu();

int main(void){
struct product info[ARRAY_SIZE] = {0};
char command;


    print_menu();
    do{

        command = ask_command();

        switch (command)
        {
        case 'a':
            print_menu();
            break;

        case 'b':
            ask_prodamount(info);
            break;
        
        case 'c':
            print_products(info);
            break;
        }
    }while(command != 'n');    
}

void print_menu(){
    printf("A:print menu\n");
    printf("B:Ask product amount:\n");
    printf("C:Print products");
    printf("N exit\n");
}

char ask_command(void){
int A_to_a = 32;
char return_command, temporal_array[ARRAY_SIZE];
        
    printf("Give command:\n");
    fgets(temporal_array, ARRAY_SIZE, stdin);
    sscanf(temporal_array, "%c", &return_command);

    if (return_command >= 'A' && return_command <= 'Z' ){
        return_command = return_command + A_to_a;
    }
    return return_command;
}


void ask_prodamount(struct product info[ARRAY_SIZE]){
int amount = 0, item_num = 0, counter = 0;
char temporal_array[ARRAY_SIZE], command = 'y';
int changed_items[ARRAY_SIZE], changed_amounts[ARRAY_SIZE];

    while(command == 'y'){
        printf("Give product name/number:\n");
            while(item_num <= 0 || item_num >= ARRAY_SIZE){
                fgets(temporal_array, ARRAY_SIZE, stdin);
                sscanf(temporal_array, "%d", &item_num);
            }   

        printf("Give product amount:\n");
        fgets(temporal_array, ARRAY_SIZE, stdin);
        sscanf(temporal_array, "%d", &amount);

        info[item_num].prod_amount = amount;
        changed_items[counter] = item_num;
        changed_amounts[counter] = amount;
        amount = 0;
        item_num = 0;
        counter++;
        printf("Do you want to continue Y/N\n");
        command = ask_command();
    }

    print_added_products(item_num, amount);
}

void print_added_products(int item_nums[ARRAY_SIZE], int item_amounts[ARRAY_SIZE]){
    printf("You added following items:\n");
    printf("Item number: %d\nAmount:%d\n", item_num, amount);
}

void print_products(struct product info[ARRAY_SIZE]){
int i;

    for (i = 0; i < ARRAY_SIZE; i++){
        printf("%d: %d\n",i, info[i].prod_amount);
    }
}