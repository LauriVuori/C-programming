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
#include <string.h>

/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/
/* Control flags */
#define DEBUG 

/* Global constants */
#define ARRAY_SIZE 1000

/* Global variables */

/* Global structures */
struct temp_data{
    float temp_values[1000];
    float highest_temp_values;
    int temp_values_count;
};

/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
void draw_y_axis(void);

void draw_x_axis(void);

struct temp_data fetch();

/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/

int main(void){
    struct temp_data data;
    data = fetch();
    printf("%d", data.temp_values_count);
    printf("<%f>", data.highest_temp_values);
    //printf("%d", fetch.temp_values_count);


    for (int i = 0; i < data.temp_values_count; i++){
        printf("%f\n", data.temp_values[i]);
    }
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
struct temp_data fetch(){
    struct temp_data Fdata;
    char line[50];
    int i = 0;

    FILE *filepointer = fopen("day_temp.txt", "r");

    if (filepointer == NULL){
        printf("Error while opening the file. Maybe missing file.\n");
        printf("Write string to file.\n");
    }

    while (fgets(line, 15, filepointer) != NULL){
        
        while (line[0] < '0' ||  line[0] > '9'){
            fgets(line, 15, filepointer);
        }

        sscanf(line, "%f", &Fdata.temp_values[i]);

        if (Fdata.temp_values[i] >= Fdata.highest_temp_values){
            Fdata.highest_temp_values = Fdata.temp_values[i];
        }
        //printf("%f\n", temp_values[i]); TODO: poista
    
    i++;
    }

    printf("<%f>", Fdata.highest_temp_values);
    Fdata.temp_values_count = i;
    printf("<<<<<%d>>>>>", Fdata.temp_values_count);
    fclose(filepointer);
    return Fdata;
}