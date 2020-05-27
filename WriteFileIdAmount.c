#include <stdio.h>


int main(void){
    FILE *filepointer = fopen("WrittenString.txt", "w"); 
    for(int i = 0; i <= 49; i++){
    fprintf(filepointer, "\"id:%d\" \"amount:0\"\n", i);
    }
    fclose(filepointer);
}