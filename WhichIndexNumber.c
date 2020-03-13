/* palauta index*/
#include <stdio.h>
int index(int array[], int num);

int main(void){
    int s[] = {15,12,11,10,-15,-1};
    int ask;
    for(int i = 0; i< 6; i++){
        printf("%d, ", s[i]);
    }
    printf("\nGive number from array:");
    scanf("%d", &ask);
    printf("%d", index(s, ask));
}

int index(int array[], int num){
    for (int i = 0; i < 6; i++){
        if(array[i] == num){
            return i;
        }
    }
    
    return -1;
}