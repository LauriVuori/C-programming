#include <stdio.h>
int remove_duplicate_array(int *a, int n);


int main(void) {
    int z[]={1,1,1,1,1,2,3,4,4,4,4};
    int l=remove_duplicate_array(z,11);
    printf("%d\n",l);

    for(int i=0; i<l; i++)
        printf("%d ",z[i]);
}

int remove_duplicate_array(int *a, int n) {
    int temp[50] = {0};
    int counter = 0;
    for (int i = 0; i < n; i++) {
        // printf("%d", *a);
        temp[*a]++;
        a++;
        counter++;
    }
    a -= counter;
    counter = 0;
    for (int i = 0; i < 50; i++) {
        if (temp[i] > 0) {
            // printf("<%d, %d>", temp[i], i);
            *a = i;
            counter++;
            a++;
        }
    }
    return counter;
}
