
#include<stdio.h>

typedef signed char int8_t;
typedef unsigned char uint8_t;

typedef unsigned short uint16_t;
typedef signed short int16_t;

typedef unsigned int uint32_t;
typedef int int32_t;



void bin(unsigned n) {
    unsigned i;
    int counter = 1;
    for (i = 1 << 31; i > 0; i = i / 2) {
        (n & i) ? printf("1") : printf("0");

        if (counter % 4 == 0) {
            printf(" ");
        }
        counter++;
    }
    printf("\n");
}
 
int main(void) {
    bin((1 << 18));
}