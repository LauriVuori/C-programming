#include <stdio.h>
#define ARRAY_SIZE 1000

void readText(int number);

int main(void){
int word;
    scanf("%d", &word);
    readText(word);
}

void readText(int number){
    FILE *filepointer = fopen("words.txt", "r");
    char line[ARRAY_SIZE];
    char words[ARRAY_SIZE][ARRAY_SIZE];
    int i = 0;


    while (fgets(line, 1000, filepointer) != NULL){
        sscanf(line, "%s", words[i]);
        i++;
    }
    printf("%s", words[number-1]);
    fclose(filepointer);
}