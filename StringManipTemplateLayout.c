/***************************************************************************
 *   Copyright (C) $2020$ by $Lauri Vuori$                                 *
 *   $laurivuori.lv@gmail.com$                                             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/*********************************************************************

 1.  NAME
     $StringManipTemplateLayout.c$

 2.  DESCRIPTION
     This program 
 3.  VERSIONS
       Original:
         $7.3.2020$ / $lauri Vuori$

       Version history:
       7.3.2020, 13.53 -Lauri Vuori

**********************************************************************/

/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/
/* Control flags */

/* Global constants */
#define ARRAY_SIZE 1000
#define STRING_END '\0'
/* Global variables */


/* Global structures */

/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
void display_menu(void);

void read_string(char main_string[]);

void print_string(char main_string[]);

int count_vowels(char main_string[]);

int count_consonants(char main_string[]);

void to_lower(char main_string[]);

void to_upper(char main_string[]);

void read_file(char main_string[]);

void write_file(char main_string[]);

void write_string(char main_string[]);

char ask_command();

/*********************************************************************
*    MAIN PROGRAM                                                    *
**********************************************************************/

int main(void){
    char main_string[ARRAY_SIZE] = "";
    char users_command;
    
    FILE *filepointer = fopen("WrittenString.txt", "r");

    if (filepointer == NULL){
        printf("Error while opening the file. Maybe missing file.\n");
        write_string(main_string);
    }

    else{
        fgets(main_string, ARRAY_SIZE, filepointer);
    }
    
    fclose(filepointer);

    display_menu();

    do{
        users_command = ask_command();

        switch (users_command){
        
            case 'a':
                printf("\nString has %d vowels\n", count_vowels(main_string));
                break;

            case 'b':
                printf("\nString has %d consonants\n", count_consonants(main_string));
                break;

            case 'c': 
                to_upper(main_string);  
                break;

            case 'd':
                to_lower(main_string);
                break;

            case 'e':
                print_string(main_string);
                break;

            case 'f':
                write_string(main_string);
                break;

            case 'g':
                read_file(main_string);
                break;

            case 'h':
                write_file(main_string);
                break;

            case 'm':
                display_menu();
                break;

            case 'x':
                printf("Program shuts down");
                break;

        }
    }while (users_command != 'x');

} /* end of main */

/*********************************************************************
*    FUNCTIONS                                                       *
**********************************************************************/

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:display_menu
 DESCRIPTION: print menu with options to modify string
	Input: none
	Output: none
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/

void display_menu(void){
    printf( "A) Count the number of vowels in the string\n"
            "B) Count the number of consonants in the string\n"
            "C) Convert the string to uppercase\n"
            "D) Convert the string to lowercase\n"
            "E) Display the current string\n"
            "F) Enter another string\n"
            "G) Read string from file\n"
            "H) Write string to file\n\n"
            "M) Display this menu\n"
            "X) Exit the program\n");
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:ask_command
 DESCRIPTION: ask character from user, return letter always in lower case
	Input: none
	Output: asked character in lower case
  Used global variables:
  Used global constants:ARRAY_SIZE
 REMARKS when using this function: 
*********************************************************************/

char ask_command(void){
    int A_to_a = 32;
    char return_command;
    char temporal_array[ARRAY_SIZE];
        
    printf("Give command:\n");
    fgets(temporal_array, ARRAY_SIZE, stdin);
    sscanf(temporal_array, "%c", &return_command);

    if (return_command >= 'A' && return_command <= 'Z' ){
        return_command = return_command + A_to_a;
    }
    return return_command;
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: count_vowels
 DESCRIPTION: count vowels in string and return sum of counted vowels
	Input: string for counting vowels
	Output: vowels sum from string
  Used global variables:
  Used global constants: STRING_END
 REMARKS when using this function:
*********************************************************************/

int count_vowels(char main_string[]){
    int i;
    int vowels_sum = 0;

    for(i = 0; main_string[i] != STRING_END; i++){
        switch(main_string[i]){
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
                vowels_sum++;
            break;    
        }
    }
    return vowels_sum;
} 

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: count_consonants
 DESCRIPTION: count consonants in string and return consonants sum
	Input: string for counting consonants
	Output: consonants sum from string
  Used global variables:
  Used global constants: STRING_END
 REMARKS when using this function:
*********************************************************************/

int count_consonants(char main_string[]){
    int i;
    int consonants_sum = 0;

    for (i = 0; main_string[i] != STRING_END; i++){
            if (main_string[i] >= 'a' && main_string[i] <= 'z' || 
                main_string[i] >= 'A' && main_string[i] <= 'Z'){

                if (main_string[i] !='a' && 
                    main_string[i] != 'e' && 
                    main_string[i] != 'i' && 
                    main_string[i] != 'o' && 
                    main_string[i] != 'u' && 
                    main_string[i] != 'A' && 
                    main_string[i] != 'E' && 
                    main_string[i] != 'I' && 
                    main_string[i] != 'O' && 
                    main_string[i] != 'U'){
                consonants_sum++;
                }
            }
    }
    return consonants_sum;
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: to_upper
 DESCRIPTION: turn all lower case letter in string to uppercase
	Input: string to change letters to uppercase
	Output: string with all letters changed to uppercase
  Used global variables:
  Used global constants: STRING_END
 REMARKS when using this function:
*********************************************************************/

void to_upper(char main_string[]){
    int i;
    int a_to_A = 32;

    for (i = 0; main_string[i] != STRING_END; i++){

        if (main_string[i] >= 'a' && main_string[i] <= 'z'){
            main_string[i] -= a_to_A;
        }
    }
    printf("String converted to upper: %s", main_string);
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: to_lower
 DESCRIPTION: turn all uppercase letters in string to lower case
	Input: string to change letters to lowercase
	Output: string with all letters changed to lowercase
  Used global variables:
  Used global constants: STRING_END
 REMARKS when using this function:
*********************************************************************/

void to_lower(char main_string[]){
    int i;
    int A_to_a = 32;

    for (i = 0; main_string[i] != STRING_END; i++){

        if (main_string[i] >= 'A' && main_string[i] <= 'Z'){
            main_string[i] += A_to_a;
        }
    }
    printf("String converted to lower: %s", main_string);
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: print_string
 DESCRIPTION: print string
	Input: string to be printed
	Output: print string brought to function
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/

void print_string(char main_string[]){
    printf("Current string is:%s", main_string);
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: write_string
 DESCRIPTION: ask string from user and write it in to brought string
	Input: string to be written over by user input
	Output: string from user input
  Used global variables:
  Used global constants: ARRAY_SIZE
 REMARKS when using this function:
*********************************************************************/

void write_string(char main_string[]){
    printf("Give new string:\n");
    fgets(main_string, ARRAY_SIZE, stdin);
    printf("New string is: %s", main_string);
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: read_file
 DESCRIPTION: read string from file and print it
	Input: string to be written over with files text
	Output: string written from text file
  Used global variables:
  Used global constants: ARRAY_SIZE
 REMARKS when using this function:  
*********************************************************************/

void read_file(char main_string[]){
    FILE *filepointer = fopen("WrittenString.txt", "r");
    if (filepointer == NULL){
        printf("Error while opening the file. Maybe missing file.\n");
        printf("Write string to file.\n");
        write_string(main_string);
    }

    printf("The contents of file are:\n");
    fgets(main_string, ARRAY_SIZE, filepointer);
    printf("%s", main_string);

    fclose(filepointer);
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: write_file
 DESCRIPTION: write string to text  file
	Input: string to be written in text file
	Output: string written in text file
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/

void write_file(char main_string[]){
    FILE *filepointer = fopen("WrittenString.txt", "w"); 
    printf("String will be written in file:%s", main_string);
    fprintf(filepointer, "%s", main_string);
    fclose(filepointer);
}


