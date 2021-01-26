// solve sudoku, give parameters how large sudoku
#include <stdio.h>
#include <stdlib.h>

void allocateMemorySudoku(int ** sudoku, int rowxheight);
void solvesudoku(int sudoku[9][9]);
void printSudoku(int * sudoku, int rowXcol);
int main(void) {
    // int rowxheight = 9;
    // int **sudoku = malloc(sizeof(int[rowxheight])); // same, naming the type directly
    // for (int row = 0; row <= rowxheight; row++){
    //     sudoku[row] = malloc(sizeof(int[rowxheight]));
    // }

    // for (int row = 0; row <= rowxheight; row++) {
    //     for (int colum = 0; colum < rowxheight; colum++) {
    //         sudoku[row][colum] = 0;
    //         printf("%1d ", sudoku[row][colum]);
    //     }
    //     printf("\n");
    // }
    int sudoku[9][9] = {{0,0,0,0,0,7,9,0,5},
                        {1,0,0,0,9,0,6,0,4},
                        {0,5,0,0,2,0,7,0,3},
                        {0,8,0,0,4,0,0,7,0},
                        {0,0,0,7,0,9,0,0,0},
                        {0,2,0,0,5,0,0,6,0},
                        {3,0,0,0,1,0,0,5,0},
                        {6,0,4,0,0,0,0,0,2},
                        {0,0,5,9,0,0,0,0,0}};

    printSudoku(sudoku, 9);
}
void printSudoku(int * sudoku, int rowXcol) {
    int *p, rows, colums;
    for(rows = 0; rows < rowXcol; rows++){
        p = sudoku + rows * rowXcol;
        for(colums = 0; colums < rowXcol; colums++) {
            printf("%d ", *(p + colums));
        }
        printf("\n");
    }
}

void solvesudoku(int sudoku[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int b = 0; b < 9; b++) {
            printf("%1d ", sudoku[i][b]);
        }
        printf("\n");
    }
}