#include <stdio.h>
int remove_duplicate_array(int *a, int n);


int main(void) {
int z[]={-111,1,-111,1,0,2,3,33,33,4,4,23,4,23};
int l=remove_duplicate_array(z,14);
printf("%d\n",l);

for(int i=0; i<l; i++)
    printf("%d ",z[i]);
}

int remove_duplicate_array(int *a, int n) {
    int i = 0, b = 0, counter = 0;

    int temp[500];

    for (i = 0; i < n; i++) {
        for (b = 0; b < counter; b++) {
            if (*(a+i) == temp[b]) {
                b = counter;
            }
        }
        if (b == counter) {
            temp[counter] = *(a+i);
            counter++;
        }
        
    }
    for (int i = 0; i < counter; i++){
        *a = temp[i];
        a++;
    }
    return counter;
}