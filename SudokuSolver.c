// solve sudoku, give parameters how large sudoku
#include <stdio.h>
#include <stdlib.h>

void allocateMemorySudoku(int ** sudoku, int rowxheight);

int main(void) {
    int rowxheight = 9;


    int **sudoku = malloc(sizeof(int[rowxheight])); // same, naming the type directly
    for (int row = 0; row <= rowxheight; row++){
        sudoku[row] = malloc(sizeof(int[rowxheight]));
    }

    for (int row = 0; row <= rowxheight; row++) {
        for (int colum = 0; colum < rowxheight; colum++) {
            sudoku[row][colum] = 0;
            printf("%1d ", sudoku[row][colum]);
        }
        printf("\n");
    }
}