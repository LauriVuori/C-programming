// solve sudoku, give parameters how large sudoku
// 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 9


int checkGrid(int * sudoku, int rowXcol, int checkNum);
int checkRules(int * sudoku, int row, int col, int num, int rowXcol);
int solveSudoku(int * sudoku, int row, int colum, int rowXcolum);
void allocateMemorySudoku(int ** sudoku, int rowxheight);
void printSudoku(int * sudoku, int rowXcol);
int checkRow(int * sudoku, int rowXcol, int checkNum);
int checkColum(int * sudoku, int rowXcol, int checkNum);
void suffleSudoku(int * sudoku, int rowXcol);

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

    //esim. 1,2,3,4,6,8
    // eka rivi, tarkista onko 1, ei ole 1
    // lasketaan mahdollisuudet jos on 1 mahdollisuus, aseta luku

    int sudoku[9][9] = {{0,0,0,0,0,7,9,0,5},
                        {1,0,0,0,9,0,6,0,4},
                        {0,5,0,0,2,0,7,0,3},
                        {0,8,0,0,4,0,0,7,0},
                        {0,0,0,7,0,9,0,0,0},
                        {0,2,0,0,5,0,0,6,0},
                        {3,0,0,0,1,0,0,5,0},
                        {6,0,4,0,0,0,0,0,2},
                        {0,0,5,9,0,0,0,0,0}};

    if (solveSudoku(&sudoku[0][0], 0, 0, 9) == 1) {
        printSudoku(&sudoku[0][0], 9);
    }
    else {
        printf("No solution exists");
    }
    return 0;
}


/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: suffleSudoku
 DESCRIPTION: 
	Input: 
	Output:
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
void suffleSudoku(int * sudoku, int rowXcol) {
    // rand if put number or not, rand num, check row to not same number, check colum not same number, go next spot,
}


/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: checkGrid
 DESCRIPTION: check 3x3 grid if there is number already
	Input: sudoku, rows/colums and number to check
	Output:
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
int checkGrid(int * sudoku, int rowXcol, int checkNum) {
    int *p, found = 0;
    for (int row = 0; row < 3; row++) {
        for (int colum = 0; colum < 3; colum++) {
            p = (sudoku + row * 9) + colum;
            if (*p == checkNum) {
                found = 1;
            }
        }
    }
    return found;
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: checkColum
 DESCRIPTION: [0][x] tells which colum to check
	Input: checkColum(&sudoku[0][x], 9);
	Output:
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
int checkColum(int * sudoku, int rowXcol, int checkNum) {
    int rows, *p, found = 0;
    for (rows = 0; rows < rowXcol; rows++) {
        p = sudoku + rows * rowXcol;
        if (*p == checkNum) {
            found = 1;
        }
    }
    return found;
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
int checkRow(int * sudoku, int rowXcol, int checkNum) {
    int colums, found = 0;
    for (colums = 0; colums < rowXcol; colums++) {
        if (*(sudoku + colums) == checkNum) {
            found = 1;
        }
    }
    return found;
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: Print sudoku
 DESCRIPTION: 
	Input: checkRow(&sudoku[x], 9);
	Output:
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
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

int checkRules(int * sudoku, int row, int col, int num, int rowXcol) {
    
    if (checkRow((sudoku + row * rowXcol), rowXcol, num) == 1) {
        return 0;
    }
 
    // Check if we find the same num in the 
    // similar column , we return 0

    if (checkColum(sudoku + col, 9, num) == 1) {
        return 0;
    }
    // Check if we find the same num in the 
    // particular 3*3 matrix, we return 0
    int startRow = row - row % 3, startCol = col - col % 3;
    if (checkGrid(((sudoku + startRow * rowXcol) + startCol),9 ,num) == 1) {
        return 0;
    }

    return 1;
}

int solveSudoku(int * sudoku, int row, int colum, int rowXcolum) {
    if (row == rowXcolum - 1 && colum == rowXcolum) {
        return 1;
    }

    if (colum == rowXcolum) {
        row++;
        colum = 0;
    }
    if (*((sudoku + row * rowXcolum)+ colum) > 0 ) {
        return solveSudoku(sudoku, row, colum + 1, rowXcolum);
    }

    for (int num = 1; num <= rowXcolum; num++) {
        if (checkRules(sudoku, row, colum, num, rowXcolum) == 1) {
            *((sudoku + row * rowXcolum) + colum) = num;

            if (solveSudoku(sudoku, row, colum + 1, rowXcolum) == 1) {
                return 1;
            }
        }
        *((sudoku + row * rowXcolum) + colum) = 0;
    }
    return 0;
}