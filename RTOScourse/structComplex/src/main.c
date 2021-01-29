#include <stdio.h>
#include <stdlib.h>
#include "complexx.h"

int main(void) {
    struct complex numbers1 = {5,2} , numbers2 = {5,2};
    struct complex numbersAr[5];
    struct complex *result;
    char menu[2], option[2];
    result = malloc(sizeof(struct complex));

    while (menu[0] != 'q'){
        printf("Options:\na)sum 2 complex numbers\nb)Sort 5 complex numbers\n"
        "c)complex multiply\nd)complex divide\ne)complex substract\n");
        printf("Give option:\n");
        fgets(menu, 2, stdin);
        fflush(stdin);
        switch (menu[0]) {
        case 'a':
            read_complex(&numbers1);
            print_complex(&numbers1);
            read_complex(&numbers2);
            print_complex(&numbers2);
            result = complex_addition(&numbers1, &numbers2);
            printf("Result:\n");
            print_complex(result);
            break;
        case 'b':
            for (int i = 0; i < 5; i++) {
                printf("Give %d numbers:\n", i+1);
                read_complex(&numbersAr[i]);
                print_complex(&numbersAr[i]);
            }
                printf("By which numbers will be sorted (R/I):\n");
                fgets(option, 2, stdin);
                fflush(stdin);
                for (int i = 0; i < 5; i++) {
                    for (int b = i; b < 5; b++){
                        if ((option[0] == 'R') && (numbersAr[i].real > numbersAr[b].real)){
                            swap_complex(&numbersAr[i], &numbersAr[b]);
                        }
                        if ((option[0] == 'I') && (numbersAr[i].im > numbersAr[b].im)){
                            swap_complex(&numbersAr[i], &numbersAr[b]);
                        }
                    }
                }
                 printf("Result:\n");
                for (int i = 0; i < 5; i++){
                    print_complex(&numbersAr[i]);
                }
            break;
        case 'c':
            read_complex(&numbers1);
            print_complex(&numbers1);
            read_complex(&numbers2);
            print_complex(&numbers2);
            result = complex_multiply(&numbers1, &numbers2);
            printf("Result:\n");
            print_complex(result);
            break;
        case 'd':
            read_complex(&numbers1);
            print_complex(&numbers1);
            read_complex(&numbers2);
            print_complex(&numbers2);
            result = complex_divide(&numbers1, &numbers2);
            printf("Result:\n");
            print_complex(result);
            break;
        case 'e':
            read_complex(&numbers1);
            print_complex(&numbers1);
            read_complex(&numbers2);
            print_complex(&numbers2);
            result = complex_subtract(&numbers1, &numbers2);
            printf("Result:\n");
            print_complex(result);
            break;
        case 'q':
            printf("Program shuts down.");
        }
    }
}
