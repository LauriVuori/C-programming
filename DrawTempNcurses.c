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
#define MAX_DRAW_VALUE 105

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
void draw_xy_axis(float temp_range, int measurements);

void draw_temp_values(float draw_values[]);

struct temp_data fetch();

/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/

int main(void){
    struct temp_data data_from_file;
    data_from_file = fetch();

    //draw_y_axis(data_from_file.highest_temp_values);

 initscr (); 
    clear ();   
    nodelay (stdscr, TRUE);	
    
    start_color (); 
    init_pair (1, COLOR_RED, COLOR_BLACK); 
    bkgd (COLOR_PAIR (1)); 
    noecho ();

    draw_xy_axis(data_from_file.highest_temp_values, data_from_file.temp_values_count);
    draw_temp_values(data_from_file.temp_values);

    
    nodelay (stdscr, FALSE);
    getch ();
    endwin ();

} /* end of main */

/*********************************************************************
*    FUNCTIONS                                                       *
**********************************************************************/

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N TODO:
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
    char line[ARRAY_SIZE];
    int i = 0;

    FILE *filepointer = fopen("day_temp.txt", "r");

    if (filepointer == NULL){
        printf("Error while opening the file. Maybe missing file.\n");
        printf("Write string to file.\n");
    }

    while (fgets(line, ARRAY_SIZE, filepointer) != NULL){
        
        while (line[0] < '0' ||  line[0] > '9'){
            fgets(line, ARRAY_SIZE, filepointer);
        }
        sscanf(line, "%f", &Fdata.temp_values[i]);

        if (Fdata.temp_values[i] >= Fdata.highest_temp_values){
            Fdata.highest_temp_values = Fdata.temp_values[i];
        }
    i++;
    }
    Fdata.temp_values_count = i;
    fclose(filepointer);
    return Fdata;
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:draw_x&y_axis //TODO: tarkasta rakenne voisi muokata
 DESCRIPTION:
	Input:
	Output:
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
void draw_xy_axis(float temp_range, int measurements){
    float y_axis = 0;
    curs_set(0);
    int x_axis = 6, i = 0, s = 0;
    temp_range = temp_range*2+2;
    while (i <= temp_range){
        move(i,0);
        printw("%0.1f", y_axis);
        y_axis += 0.5;
        i++;
    }
    i = 0;
    while (x_axis <= 105){
        move(temp_range, x_axis);
        printw("%d", i); //TODO:muuta i, kuvaamaan alariviä
        
        if (i == 9){
            i = 0;
        }
        else {
            i++;
        }
        if (i == 1){
            move(temp_range+1, x_axis);
            printw("%d", s);
            s++;
        }
        x_axis++;
    }
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:draw_temp_values
 DESCRIPTION:
	Input:
	Output:
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
void draw_temp_values(float draw_values[]){
    int i = 0;
    while (i <= 99){ //TODO: korjaa -5 ettei tarvitsisi
        move(draw_values[i]*2, i+6);
        printw("x");
    i++;
    }


}