/*Write a C program that will manipulate a string of characters.
Program will display a menu of actions program may perform*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_menu(void);

void read_string(char s[]);
//Function will print guide text and read string

void print_string(char s[]);
//Function will print current string
int count_vowels(char s[]);
/*function that counts and returns the number of vowels in the string.
(For the purposes of this exercise, we are talking about the standard 5 vowels -- A, E, I, O, U).*/

int count_consonants(char s[]);
//a function that counts and returns the number of consonants in the string.

void to_lower(char s[]);
//a function that converts the string to all lowercase.

void to_upper(char s[]);
//a function that converts the string to all uppercase.

void read_file(char s[]);
void write_file(char s[]);
void write_string(char s[]);

#define SIZE 100
int main(void){
    char temp[SIZE];
    char command;
    char s[SIZE] = "asaADS4adLaur";

    display_menu();

    int count = 0;

    do{
        printf("\nGive command:\n");
        fgets(temp, 100, stdin);

        sscanf(temp,"%c", &command);

        switch(command){
        case 'a':
            printf("\nString has %d vowels\n",count_vowels(s));
        break;
        case 'b':
            printf("\nString has %d consonants\n",count_consonants(s));
        break;

        case 'c':
            to_upper(s);
        break;

        case 'd':
            to_lower(s);
        break;
        case 'E':
            print_string(s);
        break;
        case 'f':
            write_string(s);
        break;

        case 'g':
            read_file(s);
        break;

        case 'h':
            write_file(s);
        break;

        case 'm':
            display_menu();
        break;
        case 'x':
            printf("Program shuts down");
        break;
        }
    }while(command != 'x');





/*fprintf(filepointer, "asd %d",variable);
fclose(filepointer);*/
}

void display_menu(void){
    printf("A) Count the number of vowels in the string\nB) Count the number of consonants in the string\nC) Convert the string to uppercase\nD) Convert the string to lowercase");
    printf("\nE) Display the current string\nF) Enter another string\nG) Read string from file\nH) Write string to file\n\nM) Display this menu\nX) Exit the program");
}

count_vowels(char s[]){

    int i;
    int counter = 0;

    for(i = 0; s[i] != '\0'; i++){
            /*if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o'|| s[i] == 'u'|| s[i] == 'A' || s[i] == 'E'|| s[i] == 'I'|| s[i] == 'O'|| s[i] == 'U')
            counter++;*/

            switch(s[i])
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                counter++;
            break;

            }
        }
return counter;
}

int count_consonants(char s[]){
    int i;
    int counter = 0;
    for(i = 0; s[i] != '\0'; i++){
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z'){
                if(s[i] !='a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] && 'O' && s[i] != 'U')
                counter++;
            }
    }
return counter;
}

void to_upper(char s[]){
    int i;
    for(i = 0; s[i] != '\0'; i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            s[i] -= 32;
        }
    }
printf("%s", s);
}

void to_lower(char s[]){
        int i;
    for(i = 0; s[i] != '\0'; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] += 32;
        }
    }
printf("%s", s);
}

void print_string(char s[]){
    printf("Current string is:%s", s);
}

void read_file(char s[]){
    FILE *fp = fopen("WrittenString.c", "r");       //write file name
    if (fp == NULL){
        printf("Error while opening the file.\n");
        return 0;
    }

    printf("The contents of file are:\n");

    while((s = fgetc(fp)) != EOF){
        printf("%c", s);
    }
    fclose(fp);
}

void write_file(char s[]){
    FILE *fp = fopen("WrittenString.c", "w"); //write file name
    printf("Give new string to file:\n");
    fgets(s, SIZE, stdin);
    fprintf(fp, "%s", s);
    fclose(fp);
}

void write_string(char s[]){
            printf("Give new string:\n");
            fgets(s, SIZE, stdin);
            printf("New string is: %s", s);
}
