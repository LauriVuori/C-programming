
#include <unistd.h> /* needed for usleep delay*/
#include <ncurses.h>

#define PI 3.14159265


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
    int Horizontal_row = 10;
    for (i = 0; i < 50; i++){
        move (Horizontal_row, i);
        printw("*");
       usleep(5000);

    }
    //pystyrivi
    int Vertical_row = 25;
    for (i = 0; i < 25; i++){
        move (i, Vertical_row);
        printw("*");
        usleep(5000);

    }

    

    /*float x,y;
    for(x=-3.14159;x<=3.14159;x+=1.0){
        y = sin(x);
        move(x, y);
        printw("*");
        draw_line();
    }*/

    nodelay (stdscr, FALSE);	/* non block input for getch() */
    getch ();
    endwin ();
}
