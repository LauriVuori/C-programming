/***************************************************************************
 *   Copyright (C) $Year$ by $Lauri Vuori$   *
 *   $laurivuori.lv@gmail.com$   *
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
     $Sin_curses.c$ 

 2.  DESCRIPTION
     Draw Sine wave on x y axis using Ncurses
 3.  VERSIONS
       Original:
         $25.3.2020$ / $Lauri Vuori$

       Version history:
        25.3.2020
**********************************************************************/

/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/

#include <ncurses.h>
#include <unistd.h>
#include <math.h>

/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/
/* Control flags */

/* Global constants */
#define ROW_LENGHT 40
#define Y_ROW 20
#define X_ROW 20
#define FIRST_COLOR 1
#define SIN_SCALING 10

/* Global variables */

/* Global structures */

/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
void draw_xy_axis(void);

int scale_sin(float value);

void draw_sin(void);
/*********************************************************************
*    MAIN PROGRAM                                                    *
**********************************************************************/
int main(void){
    initscr (); 
    clear ();   
    nodelay (stdscr, TRUE);	
    
    start_color (); 
    init_pair (FIRST_COLOR, COLOR_RED, COLOR_BLACK); 
    bkgd (COLOR_PAIR (FIRST_COLOR)); 
    noecho ();

    draw_xy_axis();
    draw_sin();
    
    nodelay (stdscr, FALSE);
    getch ();
    endwin ();
} /* end of main */

/*********************************************************************
*    FUNCTIONS                                                       *
**********************************************************************/
/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:draw_axis
 DESCRIPTION: Draw x and y axis 
	Input:
	Output: Draw x and y axis to terminal
  Used global variables:
  Used global constants: ROW_LENGHT, X_ROW, Y_ROW
 REMARKS when using this function:
*********************************************************************/

void draw_xy_axis(void){
    int draw_location = 0;
    int drawing_speed = 20000;
    curs_set(0);

    for (draw_location = 0; draw_location <= ROW_LENGHT; draw_location++){
        move (draw_location, X_ROW);
        printw("*");

        move (Y_ROW, draw_location);
        printw("*");

        refresh();
        usleep(drawing_speed);
    }
    move(Y_ROW, draw_location);
    printw(">");

    refresh();
    usleep(drawing_speed);
} /* end of draw_axis */

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:scale_sin
 DESCRIPTION: Scale sin to be compatible for Ncurses
	Input: Value for calculating sin
	Output: scaled sin value to Y_ROW
  Used global variables:
  Used global constants: Y_ROW
 REMARKS when using this function:
*********************************************************************/
int scale_sin(float value){
    float calculated_sin = 0;

    calculated_sin = sin(value);
    calculated_sin = SIN_SCALING * calculated_sin + Y_ROW;
    return calculated_sin;
} /* end of scale_sin */

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:draw_sin
 DESCRIPTION: draw sine wave and get scaled sin from scale_sin function
	Input: none
	Output: drawn sine wave
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
void draw_sin(void){
    float scaled_sin = 0;
    float sin = 0;
    int x_axis = 0;
    int drawing_speed = 130000;
    float sin_range = 3.14;

    for (sin = sin_range; sin>= -sin_range ; sin-= 0.157){
        scaled_sin = scale_sin(sin);

        move (scaled_sin, x_axis);
        printw("0");
        
        x_axis++;
        refresh();
        drawing_speed -= 2500;
        usleep(drawing_speed);
    }
} /* end of draw_sin */