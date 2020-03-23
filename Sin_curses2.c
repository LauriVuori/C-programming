#include <ncurses.h>
#include <unistd.h> /* needed for usleep delay*/
#include <math.h>


void draw_axis(void);
int scale_sin(float value);

int main(void){
    initscr (); //Function will change the screen into ncurses mode.
    clear ();   //Clear()-function will clean whole screen
    nodelay (stdscr, TRUE);	/* gnon block input for getch() */

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


    draw_axis();
    float x = 0;
    float i = 0;
    int x_axis = 0;
    for (i = -3.14; i<= 3.14 ; i+= 0.157){
        
        x = scale_sin(i);
        move (x, x_axis);
        printw("*");
        x_axis++;
        //printf("%f\n", x);
    }

    nodelay (stdscr, FALSE);	/* non block input for getch() */
    getch ();
    endwin ();
}

void draw_axis(void){
    int i = 0;
    curs_set(0);
    int Horizontal_row = 20;
    int Vertical_row = 20;
    
    for (i = 0; i <= 40; i++){
        move (i, Vertical_row);
        printw("*");
        move (Horizontal_row, i);
        printw("*");
        refresh();
        //usleep(20000);
    }
    move(Horizontal_row, i);
    printw(">");
    refresh ();
    //usleep(20000);
}


int scale_sin(float value){
    //printf("%f\n", value);
    float sine = 0;

    sine = sin(value);
    sine = 10 * sine + 20;
    return sine;
}

