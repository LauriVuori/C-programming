#include <ncurses.h>
#include <unistd.h> /* needed for usleep delay*/
#include <math.h>


void draw_axis(void);
int scale_sin(float value);
void draw_sin(void);


int main(void){
    initscr (); //Function will change the screen into ncurses mode.
    clear ();   //Clear()-function will clean whole screen
    nodelay (stdscr, TRUE);	/* gnon block input for getch() */
    
    start_color (); 
    init_pair (1, COLOR_RED, COLOR_BLACK); 
    bkgd (COLOR_PAIR (1)); 
    noecho ();			/* stop echo of input */

    draw_axis();
    draw_sin();
    

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
        usleep(20000);
    }
    move(Horizontal_row, i);
    printw(">");
    refresh ();
    usleep(20000);
}


int scale_sin(float value){
    float sine = 0;
    sine = sin(value);
    sine = 10 * sine + 20;
    return sine;
}

void draw_sin(void){
    float x = 0;
    float i = 0;
    int x_axis = 0;
    int speed = 130000;
    for (i = 3.14; i>= -3.14 ; i-= 0.157){
        x = scale_sin(i);
        move (x, x_axis);
        printw("0");
        x_axis++;
        refresh();
        speed -= 2500;
        usleep(speed);
    }
}