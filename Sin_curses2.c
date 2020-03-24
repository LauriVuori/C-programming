#include <ncurses.h>
#include <unistd.h> /* needed for usleep delay*/
#include <math.h>


void draw_axis(void);
int scale_sin(float value);
void draw_sin(void);
void draw_sinback(void);

int draw_again(void);


int main(void){
    initscr (); //Function will change the screen into ncurses mode.
    clear ();   //Clear()-function will clean whole screen
    nodelay (stdscr, TRUE);	/* gnon block input for getch() */

    start_color (); //in ncurses we may also use colors. Before colors may be used it have to be enabled
    //init_color (COLOR_BLACK, 0, 0, 1000);
    init_pair (1, COLOR_RED, COLOR_BLACK); //init_pair()-function will crete a combination of foreground color and background colo
                                      //init_pair(index, foreground, background);
    bkgd (COLOR_PAIR (1));  // with bkgb()-function we take the color pair (defined with function init_pair()) in use
                            //similar to bkgd
                            /*attron(COLOR_PAIR(1));
                            mvaddch(y, x, 'x');
                            attroff(COLOR_PAIR(2));*/
    curs_set(0); // Sometimes we do not need to show the cursor position (like in games). Showing cursor may be taken away
    /*getch() Read one character from keyboard.  If program does not need to wait user, use nodelay, nodelay()
    /*In ncurses mode is also possible to read keyboard without program to stop to read user input. with nodelay()-function waiting can be enabled or disabled*/
    //nodelay (stdscr, TRUE);
   
    noecho ();			/* stop echo of input */
    int draw = 1;
    while(draw == 1){
    draw_axis();
    draw_sin();
    draw_sinback();
    draw = draw_again();
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
    for (i = -3.14; i<= 3.14 ; i+= 0.157){
        x = scale_sin(i);
        move (x, x_axis);
        printw("0");
        x_axis++;
        refresh();
        speed -= 2500;
        usleep(speed);
    }
}

void draw_sinback(void){
    float x = 0;
    float i = 0;
    int x_axis = 40;
    int speed = 130000;
    for (i = -3.14; i<= 3.14 ; i+= 0.157){
        x = scale_sin(i);
        move (x, x_axis+1);
        printw("0");
        x_axis--;
        refresh();
        speed -= 2500;
        usleep(speed);
    }
}

int draw_again(void){
    clear ();
    move (15, 15);
    printw("Start again??? Y/N");
    return 1;
}