
#include "includes.h"

/*
*********************************************************************************************************
*                                               CONSTANTS
*********************************************************************************************************
*/

#define  TASK_STK_SIZE                 512       /* Size of each task's stacks (# of WORDs)            */
#define  N_TASKS                        4       /* Number of identical tasks                          */
#define  MAXROWSXCOLS                   30


/*
*********************************************************************************************************
*                                               VARIABLES
*********************************************************************************************************
*/

OS_STK        TaskStk[N_TASKS][TASK_STK_SIZE];        /* Tasks stacks                                  */
OS_STK        TaskStartStk[TASK_STK_SIZE];
OS_EVENT      *Player1Sem;
OS_EVENT      *Player2Sem;
OS_EVENT      *PrintBoardSem;
OS_EVENT      *StatusSem;
OS_EVENT      *RandomSem;
INT16         winnerfound = 0;
INT16         delayMS = 500;
INT16         Rounds = 0, player1Wins = 0, player2Wins = 0, Draws = 0;
UINT8         rowsXcolums = 3;

char          board[MAXROWSXCOLS][MAXROWSXCOLS];
/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/

void TaskStart(void *data);        /* Function prototype of Startup task           */
void taskDrawBoard(void *data);
void task1Player(void *data);  
void task2Player(void *data);
void taskGameStatus(void *data);
void displayWinner(int player);
int checkFullTable();
void clearTable();
void printStatus();
/*
*********************************************************************************************************
*                                                MAIN
*********************************************************************************************************
*/

int main(int argc, char* argv[]) {
    int counter; 
    if (argc == 3) {
        rowsXcolums = atoi(argv[1]);
        delayMS = atoi(argv[2]);
        if ((rowsXcolums >= 2 && rowsXcolums < 20) && (delayMS >= 100)) {
            PC_DispClrScr(DISP_FGND_WHITE + DISP_BGND_BLACK);      /* Clear the screen                         */

            OSInit();                                              /* Initialize uC/OS-II                      */

            Player1Sem = OSSemCreate(0);
            Player2Sem = OSSemCreate(0);
            PrintBoardSem = OSSemCreate(0);
            StatusSem = OSSemCreate(0);
            RandomSem   = OSSemCreate(1);                          /* Random number semaphore                  */

            OSTaskCreate(TaskStart, (void *)0, &TaskStartStk[TASK_STK_SIZE - 1], 0);
            OSStart();                                             /* Start multitasking                       */
        }
        else{
            printf("\nrowsXcols >2 && delayMS >=100");
        }

    }
    else {
        printf("\n!!!!\nGive command line parameters, colXrow (example. 5 = 5x5 board), delay ms >100");
        printf("\n<Example: rtos_1.exe 3 500>");
    }

    return 0;
}


/*
*********************************************************************************************************
*                                              STARTUP TASK
*********************************************************************************************************
*/

void  TaskStart (void *pdata) {
    INT16U key;

    for (int i = 0; i < rowsXcolums; i++){
        for (int b = 0; b < rowsXcolums; b++) {
            board[i][b] = '-';
        }
    }

    pdata = pdata;                                         /* Prevent compiler warning                 */
    
    OSTaskCreate(taskDrawBoard, (void *)0, (void *)&TaskStk[0][TASK_STK_SIZE - 1], 1);
    OSTaskCreate(task1Player, (void *)0, (void *)&TaskStk[1][TASK_STK_SIZE - 1], 2);
    OSTaskCreate(task2Player, (void *)0, (void *)&TaskStk[2][TASK_STK_SIZE - 1], 3);
    OSTaskCreate(taskGameStatus, (void *)0, (void *)&TaskStk[3][TASK_STK_SIZE - 1], 4);

    for (;;) {
        // PC_DispStr(1, 1, "ESC EXIT", DISP_FGND_BLACK + DISP_BGND_GRAY);
        // Print_to_Screen(text);
        if (PC_GetKey(&key) == TRUE) {                     /* See if key has been pressed              */
            if (key == 0x1B) {                             /* Yes, see if it's the ESCAPE key          */
                exit(0);  	                           /* End program                              */
            }
        }
        OSTimeDlyHMSM(0, 0, 1, 0);                         /* Wait one second                          */
    }
}

/*
*********************************************************************************************************
*                                                  TASKS
*********************************************************************************************************
*/
// OSSemPend(TaskSem, 0, &err); 
// OSSemPost(TaskSem);

void  taskDrawBoard (void *pdata) {
    INT8U err;

    OSSemPost(PrintBoardSem);
    int i = 0, fullboard = 0;
    for (;;) {
        i++;
        // Print board
        OSSemPend(PrintBoardSem, 0, &err);
        PC_DispClrScr(DISP_BGND_GRAY);
        for (int i = 0; i < rowsXcolums; i++){
            for (int b = 0; b < rowsXcolums; b++){
                PC_DispChar(b, i, board[i][b], DISP_FGND_BLACK + DISP_BGND_GRAY);
            }
        }
        printStatus();

        fullboard = checkFullTable();
        // Let status task check winner
        OSSemPost(StatusSem);
        OSTimeDlyHMSM(0, 0, 0, delayMS);                         /* Wait one second                          */
        if (fullboard == 1 && winnerfound == 0){
            PC_DispStr(0, 5, "Draw", DISP_FGND_BLACK + DISP_BGND_GRAY);
            Draws++;
            Rounds++;
            clearTable(); 
        }
        else if (fullboard == 1 && winnerfound == 1){
            Rounds++;
            clearTable();              
        }
        else if (fullboard == 0 && winnerfound == 1){
            Rounds++;
            clearTable();             
        }

        // post turns to players
        if (i % 2==0){
            OSSemPost(Player2Sem);
        }
        else {
            OSSemPost(Player1Sem);
        }
    }
}



void  task1Player (void *pdata) {
    INT8U err;
    int row = 0, col = 0, fullboard = 0;
    srand(GetCurrentThreadId());
    for (;;) {
        OSSemPend(Player1Sem, 0, &err);
        // check if winner is found
        // check if board is full
        fullboard = checkFullTable();
        if (fullboard == 0 && winnerfound == 0) {
            // code
            OSSemPend(RandomSem, 0, &err);           /* Acquire semaphore to perform random numbers        */
            row = rand() % rowsXcolums;
            col = rand() % rowsXcolums;
            while(board[row][col] != '-'){
                row = rand() % rowsXcolums; 
                col = rand() % rowsXcolums;
            }
            board[row][col] = 'X';
            OSSemPost(RandomSem);                    /* Release semaphore                                  */
            // end
        }
        OSSemPost(PrintBoardSem);
        OSTimeDlyHMSM(0, 0, 0, delayMS);                         /* Wait one second                          */
    }
}



void  task2Player (void *pdata) {
    INT8U err;
    int row = 0, col = 0, fullboard = 0;
    srand(GetCurrentThreadId());
    for (;;) {
        OSSemPend(Player2Sem, 0, &err);
        // check if winner is found
        // check if board is full
        fullboard = checkFullTable();

        if (fullboard == 0 && winnerfound == 0) {
            // Rand spot
            OSSemPend(RandomSem, 0, &err);           /* Acquire semaphore to perform random numbers        */
            row = rand() % rowsXcolums;
            col = rand() % rowsXcolums;
            while(board[row][col] != '-'){
                row = rand() % rowsXcolums;
                col = rand() % rowsXcolums;
            }
            board[row][col] = 'O';
            OSSemPost(RandomSem);                    /* Release semaphore                                  */          
        }
        OSSemPost(PrintBoardSem);
        OSTimeDlyHMSM(0, 0, 0, delayMS);                         /* Wait one second                          */
        // end

    }
}

// check game status
void  taskGameStatus (void *pdata) {
    INT8U err;
    int i = 0;
    for (;;) {
        i++;
        //check status
        OSSemPend(StatusSem, 0, &err);
        int counterx = 0;
        int countero = 0;
        int winnerFound = 0;
        for (int i = 0; i < rowsXcolums; i++) {
            for (int b = 0; b < rowsXcolums; b++) {
                if (board[i][b] == 'X') {
                    counterx++;
                    if ((counterx == rowsXcolums) && (winnerFound == 0)){
                        winnerFound = 1;
                        displayWinner(1);
                    }
                }
                if (board[i][b] == 'O') {
                    countero++;
                    if ((countero == rowsXcolums) && (winnerFound == 0)){
                        winnerFound = 1;
                        displayWinner(0);
                    }
                }
            }
            counterx = 0;
            countero = 0;
        }
        if (winnerFound == 0){
            for (int i = 0; i < rowsXcolums; i++) {
                for (int b = 0; b < rowsXcolums; b++) {
                    if (board[b][i] == 'X') {
                        counterx++;
                        if ((counterx == rowsXcolums) && (winnerFound == 0)){
                            displayWinner(1);
                            winnerFound = 1;
                        }
                    }
                    if (board[b][i] == 'O') {
                        countero++;
                        if ((countero == rowsXcolums) && (winnerFound == 0)){
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
            for (int i = 0; i < rowsXcolums; i++) {
                if (board[i][i] == 'X') {
                        counterx++;
                        if ((counterx == rowsXcolums) && (winnerFound == 0)){
                            displayWinner(1);
                            winnerFound = 1;
                        }
                }
                if (board[i][i] == 'O') {
                    countero++;
                    if ((countero == rowsXcolums) && (winnerFound == 0)){
                        displayWinner(0);
                        winnerFound = 1;
                    }   
                }
            }
        }

        int colum = rowsXcolums-1;
        counterx = 0;
        countero = 0;
        if (winnerFound == 0){
            for (int i = 0; i < rowsXcolums; i++) {
                if (board[i][colum] == 'X') {
                    counterx++;
                    if ((counterx == rowsXcolums) && (winnerFound == 0)){
                        displayWinner(1);
                        winnerFound = 1;
                    }
                }
                if (board[i][colum] == 'O') {
                    countero++;
                    if ((countero == rowsXcolums) && (winnerFound == 0)){
                        displayWinner(0);
                        winnerFound = 1;
                    }
                }
                colum--;
            }
        }

        OSTimeDlyHMSM(0, 0, 0, delayMS);                         /* Wait one second                          */
    }
}

/*
*********************************************************************************************************
*                                      NON-TASK FUNCTIONS 
*********************************************************************************************************
*/

void displayWinner(int player){
    winnerfound = 1;
    if (player == 1){
        PC_DispStr(15, 5, "Player 1 wins", DISP_FGND_BLACK + DISP_BGND_GRAY);
        player1Wins++;
    }
    else {
        PC_DispStr(15, 5, "Player 2 wins", DISP_FGND_BLACK + DISP_BGND_GRAY);
        player2Wins++;
    }
}

int checkFullTable(){
    for (int i = 0; i < rowsXcolums; i++) {
        for (int b = 0; b < rowsXcolums; b++) {
            if (board[i][b] == '-') {
                return 0;
            }
        }
    }
    return 1;
}

void clearTable() {
    for (int i = 0; i < rowsXcolums; i++){
        for (int b = 0; b < rowsXcolums; b++) {
            board[i][b] = '-';
        }
    }
    winnerfound = 0;
}

void printStatus() {
    INT8U arr[15];
    sprintf(arr, "%d ", Rounds);
    PC_DispStr(20, 13, "Rounds: ", DISP_FGND_BLACK + DISP_BGND_GRAY);
    PC_DispStr(20, 14, arr, DISP_FGND_BLACK + DISP_BGND_GRAY);
    
    sprintf(arr, "%d", player1Wins);
    PC_DispStr(20, 15, "Player 1 wins: ", DISP_FGND_BLACK + DISP_BGND_GRAY);
    PC_DispStr(20, 16, arr, DISP_FGND_BLACK + DISP_BGND_GRAY);

    sprintf(arr, "%d", player2Wins);
    PC_DispStr(20, 17, "Player 2 wins: ", DISP_FGND_BLACK + DISP_BGND_GRAY);
    PC_DispStr(20, 18, arr, DISP_FGND_BLACK + DISP_BGND_GRAY);

    sprintf(arr, "%d", Draws);
    PC_DispStr(20, 19, "Draws: ", DISP_FGND_BLACK + DISP_BGND_GRAY);
    PC_DispStr(20, 20, arr, DISP_FGND_BLACK + DISP_BGND_GRAY);
}
