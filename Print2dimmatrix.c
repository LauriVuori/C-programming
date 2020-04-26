#include <stdio.h>
void print_matrix(int a[4][4], int b[4][4]);
int main(void){
    int i = 0;
    int a[4][4]={{2,2,2,2},
                 {3,3,3,3},
                 {2,2,2,2},
                 {3,3,3,3}};

    int b[4][4]={{2,2,2,2},{3,3,3,3},{2,2,2,2},{3,3,3,3}};
    print_matrix(a,b);
}

void print_matrix(int a[4][4], int b[4][4]){
    int i, n = 0;
    while (n < 4){
        for (i = 0; i < 4; i++){
                printf("%3d", a[n][i]+b[n][i]);
        }
        printf("\n");
        n++;
    }
}