// solve sudoku, give parameters how large sudoku
#include <stdio.h>
#include <stdlib.h>

void allocateMemorySudoku(int ** sudoku, int rowxheight);
void solvesudoku(int sudoku[9][9]);
void printSudoku(int * sudoku, int rowXcol);
int checkRow(int * sudoku, int rowXcol);
int checkColum(int * sudoku, int rowXcol);

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
    int i = 0;
    i = checkRow(&sudoku[1], 9);
    printf("\n\n");

    i = checkColum(&sudoku[0][8], 9);
    // printSudoku(sudoku, 9);
}
/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:
 DESCRIPTION: [0][x] tells which colum to check
	Input: checkColum(&sudoku[0][x], 9);
	Output:
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
int checkColum(int * sudoku, int rowXcol) {
    int rows, *p;
    for (rows = 0; rows < rowXcol; rows++) {
        p = sudoku + rows * rowXcol;
        printf("%d\n", *p);
    }
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:
 DESCRIPTION: [x] tells which row to check
	Input: checkRow(&sudoku[x], 9);
	Output:
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
int checkRow(int * sudoku, int rowXcol) {
    int colums;
    for (colums = 0; colums < rowXcol; colums++) {
        printf("%d ", *(sudoku + colums));
    }
    return 0;
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