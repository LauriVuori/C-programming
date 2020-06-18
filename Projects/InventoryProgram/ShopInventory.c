/*In shop there are 500 different products, that are identified by number 1-500.
Make a program that can store amount of articles in a table. Program will 
ask the product number and article amount and store them in one dimension table.
Articles are inquired one by one, and after each article program will ask 
if user will enter new product (yes/no-question).*/


#include <stdio.h>


#define ARRAY_SIZE 50

//typedef
typedef struct {
    int prod_amount[50];
    float prod_price[50];
}product;

void ask_prodamount(product *info);
void print_products(product *info);
void print_added_products(int item_nums[ARRAY_SIZE], int item_amounts[ARRAY_SIZE], int counter);
void add_products_file(int item_nums[ARRAY_SIZE], int item_amounts[ARRAY_SIZE], int counter);
char ask_command();
void print_menu();
void read_inventory(product *info);

int main(void){
product info = {0};
char command;

read_inventory(&info);
    print_menu();
    do{

        command = ask_command();

        switch (command)
        {
        case 'a':
            print_menu();
            break;

        case 'b':
            ask_prodamount(&info);
            break;
        
        case 'c':
            print_products(&info);
            break;
        case 'd':
            read_inventory(&info);
            break;
        }
    }while(command != 'n');    
}

void print_menu(){
    printf("A:print menu\n");
    printf("B:Ask product amount:\n");
    printf("C:Print products\n");
    printf("D:Read invetory\n");
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


void ask_prodamount(product *info){
int amount = 0, item_num = 0, counter = 0;
char temporal_array[ARRAY_SIZE] = {0}, command = 'y';
int changed_items[ARRAY_SIZE] ={0}, changed_amounts[ARRAY_SIZE];

    while(command == 'y'){
        printf("Give product name/number:\n");
            while(item_num <= 0 || item_num >= ARRAY_SIZE){
                fgets(temporal_array, ARRAY_SIZE, stdin);
                sscanf(temporal_array, "%d", &item_num);
            }   

        printf("Give product amount:\n");
        fgets(temporal_array, ARRAY_SIZE, stdin);
        sscanf(temporal_array, "%d", &amount);

        info->prod_amount[item_num] = amount;
        changed_items[counter] = item_num;
        changed_amounts[counter] = amount;
        amount = 0;
        item_num = 0;
        counter++;
        
        printf("Do you want to continue Y/N\n");
        command = ask_command();
    }
    
    print_added_products(changed_items, changed_amounts, counter);
    add_products_file(changed_items,changed_amounts,counter);
}

void print_added_products(int item_nums[ARRAY_SIZE], int item_amounts[ARRAY_SIZE], int counter){
printf("You added following items:\n");
    
    for (int i = 0; i < counter; i++){
        printf("product%3d:%3d pcs\n", item_nums[i], item_amounts[i]);
    }
}

void print_products(product *info){
int i;

    for (i = 0; i < ARRAY_SIZE; i++){
        printf("%d: %d\n",i, info->prod_amount[i]);
    }
}
//TODO: ei lue kuin luvun
void read_inventory(product *info){
    int inv, i = 0, counter = 0;
    char temp[1000];
    FILE *fp;
    fp = fopen("inventory.txt","r");

    while (fgets(temp, 100, fp) != NULL){
        sscanf(temp, "'' '%d'",&info->prod_amount[i]);
        printf("%d", info->prod_amount[i]);
        i++;
    }
    counter = i;
    fclose(fp);
}

void add_products_file(int item_nums[ARRAY_SIZE], int item_amounts[ARRAY_SIZE], int counter){
printf("You added following items:\n");
    
    for (int i = 0; i < counter; i++){
        printf("product%3d:%3d pcs\n", item_nums[i], item_amounts[i]);
    }
}