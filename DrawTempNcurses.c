/***************************************************************************
 *   Copyright (C) $Year$ by $Lauri Vuori$   *
 *   $Email$   *
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
     $Source$ 

 2.  DESCRIPTION

 3.  VERSIONS
       Original:
         $Date$ / $Lauri Vuori$

       Version history:

**********************************************************************/

/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include <stdio.h>
#include <ncurses.h>

/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/
/* Control flags */
#define DEBUG 

/* Global constants */
#define ARRAY_SIZE 1000

/* Global variables */

/* Global structures */

/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
void draw_y_axis(void);

void draw_x_axis(void);

void scan_values_from_txt(float temp_values[]);

/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/

int main(void){
    float temp_values[ARRAY_SIZE];
    scan_values_from_txt(temp_values);
    /*initscr (); 
    clear ();   
    nodelay (stdscr, TRUE);	
    
    start_color (); 
    init_pair (1, COLOR_RED, COLOR_BLACK); 
    bkgd (COLOR_PAIR (1)); 
    noecho ();


    
    nodelay (stdscr, FALSE);
    getch ();
    endwin ();*/

} /* end of main */

/*********************************************************************
*    FUNCTIONS                                                       *
**********************************************************************/

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:scan_values_from_txt
 DESCRIPTION:scan values from text file and make array
	Input: array to fill values from text file
	Output:TODO: array from scanned values
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
void scan_values_from_txt(float temp_values[]){
    FILE *filepointer = fopen("day_temp.txt", "r");
    if (filepointer == NULL){
        printf("Error while opening the file. Maybe missing file.\n");
        printf("Write string to file.\n");
    }

    for (int i = 0; i<= 500; i++){
        fscanf(filepointer, "%f", temp_values[i]);
        if (temp_values[i]> 0 && ){
            printf("%f\n", temp_values[i]);
        }
    }
    fclose(filepointer);
}

/*
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
*/