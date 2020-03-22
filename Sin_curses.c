
#include <ncurses.h>
#include <unistd.h> /* needed for usleep delay*/
#include <math.h>
#define PI 3.14159265

void draw_line();
int main (void){
    int i;

    initscr (); //Function will change the screen into ncurses mode.
    clear ();   //Clear()-function will clean whole screen
    nodelay (stdscr, TRUE);	/* non block input for getch() */

    start_color (); //in ncurses we may also use colors. Before colors may be used it have to be enabled
    
    init_pair (1, COLOR_WHITE, COLOR_BLUE); //init_pair()-function will crete a combination of foreground color and background colo
                                            //init_pair(index, foreground, background);
    init_pair (2, COLOR_BLUE, COLOR_WHITE);
    bkgd (COLOR_PAIR (2));  // with bkgb()-function we take the color pair (defined with function init_pair()) in use
                            //similar to bkgd
                            /*attron(COLOR_PAIR(1));
                            mvaddch(y, x, 'x');
                            attroff(COLOR_PAIR(2));*/

    curs_set(0); // Sometimes we do not need to show the cursor position (like in games). Showing cursor may be taken away
    /*getch() Read one character from keyboard.  If program does not need to wait user, use nodelay, nodelay()
    /*In ncurses mode is also possible to read keyboard without program to stop to read user input. with nodelay()-function waiting can be enabled or disabled*/
    //nodelay (stdscr, TRUE);
   
    noecho ();			/* stop echo of input */
    //vaakarivi
    int Horizontal_row = 30;
    int Vertical_row = 30;
    for (i = 0; i <= 60; i++){
        move (i, Vertical_row);
        printw("*");
        if(i == 25){
            move(25, Vertical_row+1);
            printw("5");
            move(Horizontal_row+1, 25);
            printw("-5");
        }
        else if(i == 20){
            move(20, Vertical_row+1);
            printw("10");
            move(Horizontal_row+1, 20);
            printw("-10");

        }
        else if(i == 15){
            move(15, Vertical_row+1);
            printw("15"); 
            move(Horizontal_row+1, 15);
            printw("-15");
        }
        else if(i == 30){
            move(29, Vertical_row+1);
            printw("0");
        }
        else if(i == 35){
            move(35, Vertical_row+1);
            printw("-5");
            move(Horizontal_row+1, 35);
            printw("5");
        }
        else if(i == 40){
            move(40, Vertical_row+1);
            printw("-10");
            move(Horizontal_row+1, 40);
            printw("10");
        }
        else if(i == 45){
            move(45, Vertical_row+1);
            printw("-15");
            move(Horizontal_row+1, 45);
            printw("15");
        }
        move (Horizontal_row, i);
        printw("*");
        refresh();
        usleep(20000);
    }
    move(Horizontal_row, i);
    printw(">");
    refresh ();
    usleep(20000);
    float x, y, a=25, h= 0, b = 9.5, k=0;
    for (i = 0; i <= 60; i++){
        y = a*sin(((i-h)/b)+k);
        move(y+30, i);
        printw("0");
        refresh ();
        usleep(20000);
    }

    nodelay (stdscr, FALSE);	/* non block input for getch() */
    getch ();
    endwin ();
}

