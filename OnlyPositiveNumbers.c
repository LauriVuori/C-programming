/* User gives 5 positive int numbers,
program accepts only positive numbers.
If input is false, ask input again
-Lauri Vuori*/

#include <stdio.h>

int main(void)
{
    int interger, i, sum = 0;
    printf("Give 5 positive intergers\n");

    for(i=1; i <= 5; i += 1){
        printf("%d.", i);
        scanf("%d", &interger);

        while(interger < 0){
        printf("Only positive numbers:\n");
        scanf("%d", &interger);
        }

    sum += interger;
    }
    printf("Sum is:%d", sum);
}


