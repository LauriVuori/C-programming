/*Write a C-function that will print 2 dim matrix, Matrix is fixed size 2x2 */

#include <stdio.h>
void print_matrix(int a[2][2]);
int main(void){

int a[2][2]={{2,2},{3,3}};
    print_matrix(a);
}

void print_matrix(int a[2][2]){
int i, n = 0;
    while (n < 2){
        for (i = 0; i < 2; i++){
                printf("%3d", a[n][i]);
        }
        printf("\n");
        n++;
    }
}