#include <stdio.h>


int main(void)
{
    int a1;
    int a2;
    printf("Give 2 numbers:\n1:");
    scanf("%d", &a1);
    printf("\n2:");
    scanf("%d", &a2);

    min(a1,a2);

}


void min(int a, int b)
{
    if(a<b){
        printf("First number is smaller than second");
    }
    else if(a>b){
        printf("Second number is smaller than first");
    }

    else{
        printf("They are equal");
    }

}
