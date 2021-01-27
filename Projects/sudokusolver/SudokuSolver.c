// solve sudoku, give parameters how large sudoku
// 
#include <stdio.h>
#include <stdlib.h>
#define N 9


int checkGrid(int * sudoku, int rowXcol, int checkNum);
int isSafe(int grid[N][N], int row, int col, int num);
int solveSuduko(int grid[N][N], int row, int col);
void allocateMemorySudoku(int ** sudoku, int rowxheight);
void printSudoku(int * sudoku, int rowXcol);
int checkRow(int * sudoku, int rowXcol, int checkNum);
int checkColum(int * sudoku, int rowXcol, int checkNum);

void print(int arr[N][N]);
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
    
    // int i = 0;
    // i = checkGrid(&sudoku[3][6], 9, 1);
                        
    if (solveSuduko(sudoku, 0, 0)==1)
        print(sudoku);
    else
        printf("No solution exists");
 
    return 0;
    // int found = 5000;
    // int checknum = 1;
    // for (int i = 0; i < 9; i++) {
    //     found = checkRow(&sudoku[i], 9, checknum);
    //     found = checkColum(&sudoku[0][i], 9, checknum);

    //     printf("\n\n");
    //     printf("found == %d, checknum = %d \n", found, checknum);
    //     printf("________________\n");
    // }

    // i = checkColum(&sudoku[0][1], 9);
    // printSudoku(sudoku, 9);
}
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
 NAME:
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
        // printf("%d\n", *p);
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
        // printf("%d ", *(sudoku + colums));
        if (*(sudoku + colums) == checkNum) {
            found = 1;
        }
    }
    return found;
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


int isSafe(int grid[N][N], int row, int col, int num) {

    if (checkRow(&grid[row], 9, num) == 1) {
        return 0;
    }
 
    // Check if we find the same num in the 
    // similar column , we return 0

    if (checkColum(&grid[0][col], 9, num) == 1) {
        return 0;
    }
    // Check if we find the same num in the 
    // particular 3*3 matrix, we return 0
    int startRow = row - row % 3, startCol = col - col % 3;
    if (checkGrid(&grid[startRow][startCol],9 ,num) == 1) {
        return 0;
    }
 
    return 1;
}

int solveSuduko(int grid[N][N], int row, int col) {
     
    // Check if we have reached the 8th row 
    // and 9th column (0
    // indexed matrix) , we are 
    // returning true to avoid
    // further backtracking
    if (row == N - 1 && col == N)
        return 1;
 
    //  Check if column value  becomes 9 ,
    //  we move to next row and
    //  column start from 0
    if (col == N) 
    {
        row++;
        col = 0;
    }
   
    // Check if the current position 
    // of the grid already contains
    // value >0, we iterate for next column
    if (grid[row][col] > 0)
        return solveSuduko(grid, row, col + 1);
 
    for (int num = 1; num <= N; num++) 
    {
         
        // Check if it is safe to place 
        // the num (1-9)  in the
        // given row ,col  ->we move to next column
        if (isSafe(grid, row, col, num)==1) 
        {
            /* assigning the num in the 
               current (row,col)
               position of the grid
               and assuming our assined num 
               in the position
               is correct     */
            grid[row][col] = num;
           
            //  Checking for next possibility with next
            //  column
            if (solveSuduko(grid, row, col + 1)==1)
                return 1;
        }
       
        // Removing the assigned num ,
        // since our assumption
        // was wrong , and we go for next 
        // assumption with
        // diff num value
        grid[row][col] = 0;
    }
    return 0;
}

void print(int arr[N][N])
{
     for (int i = 0; i < N; i++)
      {
         for (int j = 0; j < N; j++)
            printf("%d ",arr[i][j]);
         printf("\n");
       }
}