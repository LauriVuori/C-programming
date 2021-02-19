#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWSXCOLS 5

int checkFullboard(char * board);
void displayWinner(int player);

int main(void) {
    srand((unsigned) time(NULL));

    char board[ROWSXCOLS][ROWSXCOLS];
    int row = 0, col = 0;
    
    for (int i = 0; i < ROWSXCOLS; i++){
        for (int b = 0; b < ROWSXCOLS; b++) {
            board[i][b] = '-';
        }
    }
    int fullboard = checkFullboard(&board[0][0]);
    while (fullboard == 0){
        fullboard = checkFullboard(&board[0][0]);
        if (fullboard == 0) {
            row = rand() % ROWSXCOLS;
            col = rand() % ROWSXCOLS;
            while(board[row][col] != '-') {
                row = rand() % ROWSXCOLS;
                col = rand() % ROWSXCOLS;
            }
        board[row][col] = 'X';
        }
        fullboard = checkFullboard(&board[0][0]);
        if (fullboard == 0) {
            row = rand() % ROWSXCOLS;
            col = rand() % ROWSXCOLS;
            while(board[row][col] != '-') {
                row = rand() % ROWSXCOLS;
                col = rand() % ROWSXCOLS;
            }
        board[row][col] = 'O';
        }
    }

    printf("\n");

    // char    board[3][3] = {{'x','o','-'},
    //                         {'x','o','-'},
    //                         {'x','o','-'}};
    // char    board[3][3] = {{'o','x','x'},
    //                         {'o','x','o'},
    //                         {'x','o','x'}};
    // char    board[3][3] = {{'o','o','x'},
    //                         {'x','x','o'},
    //                         {'x','o','x'}};
    // char    board[3][3] = {{'x','x','x'},
    //                         {'x','x','x'},
    //                         {'x','x','x'}};

    int counterx = 0;
    int countero = 0;
    int winnerFound = 0;
    for (int i = 0; i < ROWSXCOLS; i++) {
        for (int b = 0; b < ROWSXCOLS; b++) {
            if (board[i][b] == 'X') {
                counterx++;
                if ((counterx == ROWSXCOLS) && (winnerFound == 0)){
                    winnerFound = 1;
                    displayWinner(1);
                }
            }
            if (board[i][b] == 'O') {
                countero++;
                if ((countero == ROWSXCOLS) && (winnerFound == 0)){
                    winnerFound = 1;
                    displayWinner(0);
                }
            }
        }
        counterx = 0;
        countero = 0;
    }
    if (winnerFound == 0){
        for (int i = 0; i < ROWSXCOLS; i++) {
            for (int b = 0; b < ROWSXCOLS; b++) {
                if (board[b][i] == 'X') {
                    counterx++;
                    if ((counterx == ROWSXCOLS) && (winnerFound == 0)){
                        displayWinner(1);
                        winnerFound = 1;
                    }
                }
                if (board[b][i] == 'O') {
                    countero++;
                    if ((countero == ROWSXCOLS) && (winnerFound == 0)){
                        displayWinner(0);
                        winnerFound = 1;
                    }
                }
            }
            counterx = 0;
            countero = 0;
        }
    }
    counterx = 0;
    countero = 0;
    if (winnerFound == 0){
        for (int i = 0; i < ROWSXCOLS; i++) {
            if (board[i][i] == 'X') {
                    counterx++;
                    if ((counterx == ROWSXCOLS) && (winnerFound == 0)){
                        displayWinner(1);
                        winnerFound = 1;
                    }
            }
            if (board[i][i] == 'O') {
                countero++;
                if ((countero == ROWSXCOLS) && (winnerFound == 0)){
                    displayWinner(0);
                    winnerFound = 1;
                }   
            }
        }
    }

    int colum = ROWSXCOLS-1;
    counterx = 0;
    countero = 0;
    if (winnerFound == 0){
        for (int i = 0; i < ROWSXCOLS; i++) {
            if (board[i][colum] == 'X') {
                counterx++;
                if ((counterx == ROWSXCOLS) && (winnerFound == 0)){
                    displayWinner(1);
                    winnerFound = 1;
                }
            }
            if (board[i][colum] == 'O') {
                countero++;
                if ((countero == ROWSXCOLS) && (winnerFound == 0)){
                    displayWinner(0);
                    winnerFound = 1;
                }
            }
            colum--;
        }
    }
    printf("\n");
    for (int i = 0; i < ROWSXCOLS; i++) {
        for (int b = 0; b < ROWSXCOLS; b++) {
            printf("%c", board[i][b]);
        }
        printf("\n");
    }
}
    // if (winnerFound == 0) {
    //     if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') {
    //         displayWinner(1);
    //         winnerFound = 1;
    //     }
    // }
    // if (winnerFound == 0) {
    //     if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') {
    //         displayWinner(0);
    //         winnerFound = 1;
    //     }
    // }
void displayWinner(int player) {

    if (player == 1){
        printf("X WINNER");
    }
    else {
        printf("O winner");
    }
}

int checkFullboard(char * board) {
    char * p;
    for (int i = 0; i < ROWSXCOLS; i++) {
        for (int b = 0; b < ROWSXCOLS; b++) {
            p = (board + i * ROWSXCOLS) + b;
            if (*p == '-') {
                return 0;
            }
        }
    }
    return 1;
}