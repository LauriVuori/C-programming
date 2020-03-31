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
#define MAX_DRAW_VALUE 99
#define START_ROW 6

/* Global variables */

/* Global structures */
struct file_data{
    int data_start_year,
        data_start_month,
        data_start_day,
        data_start_hour,
        data_start_min,
        data_start_sec,
        temp_values_count;
    float temp_values[ARRAY_SIZE];
    float highest_temp_value, lowest_temp_values;
};

/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
void draw_xy_axis(float temp_range, int measurements);

void draw_values(float draw_temp[],int year, int month, int day, int hour, int min, int sec);

struct file_data fetch();

/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/

int main(void){



 initscr (); 
    clear ();   
    nodelay (stdscr, TRUE);	
    
    start_color (); 
    init_pair (1, COLOR_RED, COLOR_BLACK); 
    bkgd (COLOR_PAIR (1)); 
    noecho ();

    struct file_data data_from_file; //TODO: siirrä ylös
    data_from_file = fetch();

    draw_xy_axis(data_from_file.highest_temp_value, data_from_file.temp_values_count);
    draw_values(data_from_file.temp_values, 
                data_from_file.data_start_year,\
                data_from_file.data_start_month,\
                data_from_file.data_start_day,\
                data_from_file.data_start_hour,\
                data_from_file.data_start_min,\
                data_from_file.data_start_sec);

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
 NAME:file_data
 DESCRIPTION:scan values from text file and make array
	Input: array to fill values from text file
	Output:TODO: array from scanned values
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
struct file_data fetch(){
    struct file_data Fdata;
    char line[ARRAY_SIZE];
    int i = 0;
    Fdata.lowest_temp_values = 1000;

    FILE *filepointer = fopen("day_temp.txt", "r");

    if (filepointer == NULL){
        printf("Error while opening the file. Maybe missing file.\n");
        printf("Write string to file.\n");
    }
    fgets(line, ARRAY_SIZE, filepointer);
    sscanf(line,"%*[^0123456789]%d\
                %*[^0123456789]%d\
                %*[^0123456789]%d\
                %*[^0123456789]%d\
                %*[^0123456789]%d\
                %*[^0123456789]%d",\
                &Fdata.data_start_year, \
                &Fdata.data_start_month, \
                &Fdata.data_start_day, \
                &Fdata.data_start_hour,\
                &Fdata.data_start_min,\
                &Fdata.data_start_sec);

    fgets(line,ARRAY_SIZE, filepointer); //TODO: pakko käyttää, jotta skippaa --- rivin, täytyy korjata
    
    while (fgets(line, ARRAY_SIZE, filepointer) != NULL){
        
        while(sscanf(line, "%*[^0123456789]%f", &Fdata.temp_values[i]) == 0 && sscanf(line, "%f", &Fdata.temp_values[i]) == 0){
            fgets(line, ARRAY_SIZE, filepointer);
        }
        if (Fdata.temp_values[i] >= Fdata.highest_temp_value){
            Fdata.highest_temp_value = Fdata.temp_values[i];
        }
        if (Fdata.temp_values[i] <= Fdata.lowest_temp_values){
            Fdata.lowest_temp_values = Fdata.temp_values[i];
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
 NAME:draw_xy_axis //TODO: tarkasta rakenne voisi muokata
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
 NAME:draw_values
 DESCRIPTION:
	Input:
	Output:
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
void draw_values(float draw_temp[],int year, int month, int day, int hour, int min, int sec){
    int i = 0;
    while (i <= MAX_DRAW_VALUE){ //TODO: korjaa -5 ettei tarvitsisi
        move(draw_temp[i]*2, i+START_ROW);
        printw("x");
    i++;
    }

    move(25, 120);
    printw("Date:%d.%d.%d",day,month,year);
    move (26, 120);
    printw("Time:%d:%d:%d-", hour, min, sec);  // TODO: Näyttää pelkästään lähtöajan
    move(27, 120);
}