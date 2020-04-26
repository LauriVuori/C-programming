#include <stdio.h>

int when_first_positive(void);
int main(void){
printf("%d",when_first_positive());
}

int when_first_positive(void){
char line[100];
float temps[100];
int i = 0;
FILE *fp = fopen("text.txt", "r");

    while (!feof(fp)){
        fgets(line, 100, fp);
        sscanf(line, "%f", &temps[i]);
        if (temps[i] > 0){
            return i;
        }
        i++;
    }
    fclose(fp);
    return -1;
}