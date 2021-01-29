#include <stdio.h>
#include <stdlib.h>
#include "complexx.h"


void swap_complex (struct complex *number, struct complex *numbe2) {
    struct complex temp = {0,0};
    temp.real = number->real;
    temp.im = number->im;
    number->im = numbe2->im;
    number->real = numbe2->real;
    numbe2->im = temp.im;
    numbe2->real = temp.real;
}
struct complex * complex_addition(struct complex *a, struct complex *b) {
    struct complex *ptr;
    ptr = malloc(sizeof(struct complex));
    ptr->im = a->im + b->im;
    ptr->real = a->real + b->real;
    return ptr;
}
struct complex * complex_multiply(struct complex *a, struct complex *b) {
    struct complex *ptr;
    ptr = malloc(sizeof(struct complex));
    ptr->im = a->im * b->im;
    ptr->real = a->real * b->real;
    return ptr;
}
struct complex * complex_subtract(struct complex *a, struct complex *b) {
    struct complex *ptr;
    ptr = malloc(sizeof(struct complex));
    ptr->im = a->im - b->im;
    ptr->real = a->real - b->real;
    return ptr;
}
struct complex * complex_divide(struct complex *a, struct complex *b) {
    struct complex *ptr;
    ptr = malloc(sizeof(struct complex));
    ptr->im = a->im / b->im;
    ptr->real = a->real / b->real;
    return ptr;
}

int checkInput (char * buffer) {
    int lenght = 0, dotcounter = 0;
    for (lenght = 0; *buffer != '\0'; lenght++) {
        buffer++;
    }
    buffer -= lenght;


    for (int i = 0; i < lenght-1; i++) {
        if (((*buffer >= '0') && (*buffer <= '9')) || 
            ((*buffer == '.') && (dotcounter == 0)) && (i > 0)) {
            if (*buffer == '.'){
                dotcounter++;
            }
            buffer++;
        } 
        else {
            return 1;
        }
    }
    return 0;
}

void read_complex(struct complex *number) {
    char buffer[BUFFERLEN];

    int flag = 1;
    printf("Give real and imaginary numbers:\n");
    printf("Give first real part:\n");
    while (flag == 1){
        fgets(buffer, BUFFERLEN, stdin);
        flag = checkInput(&buffer[0]);
        if (flag == 1) {
            printf("Error, give new input\n");
        }
    }
    number->real = atof(buffer);

    fflush(stdin);
    flag = 1;
    printf("Give imaginary part:\n");
    while (flag == 1){
        fgets(buffer, BUFFERLEN, stdin);
        flag = checkInput(&buffer[0]);
        if (flag == 1) {
            printf("Error, give new input\n");
        }
    }
    number->im = atof(buffer);
}

void print_complex(struct complex *number) {
   printf("(%0.2f %0.2fi)\n", number->real, number->im);
}