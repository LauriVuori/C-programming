#include <stdio.h>

int remove_duplicate_array(int *a, int n);
int main()
{
int z[]={1,1,1,1,1,2,3,4,4,4,4};
int l=remove_duplicate_array(z,11);
printf("%d\n",l);

for(int i=0; i<l; i++)
    printf("%d ",z[i]);

  return 0;
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