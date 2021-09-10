#include <stdio.h>
typedef signed char int8_t;
typedef unsigned char uint8_t;

typedef unsigned short uint16_t;
typedef signed short int16_t;

typedef unsigned int uint32_t;
typedef int int32_t;
void uint16_to_char_array(uint16_t uInteger, uint8_t * dest_array);
void uint32_to_char_array(uint32_t uInteger, uint8_t * dest_array);


int main(void) {
    uint8_t test[12] = {0};
    uint32_to_char_array(4294967295, &test[0]);
    // printf("%s", test);
    for (int i = 0; test[i] != '\0'; i++) {
        printf("<%c>", test[i]);
    }
    printf("\n");
    printf("%s", test);
}


void uint16_to_char_array(uint16_t uInteger, uint8_t * dest_array) {
    // needs atleast [6] array
	uint8_t* ptr_to_buffer;
	uint8_t int_buffer [10];

	ptr_to_buffer = &int_buffer[10];        // Point to buffer end
    *ptr_to_buffer = 0;
    do {
        // make characters, (uInteger % 10) = 5, 5 + '0' = 53=='5'
        *--ptr_to_buffer = (uInteger % 10) + '0';
    }while (uInteger /= 10 );

	while (*ptr_to_buffer) {
        *dest_array = *ptr_to_buffer;
        dest_array++;
        ptr_to_buffer++;
	}
    // end char
    *dest_array = '\0';
}
void uint32_to_char_array(uint32_t uInteger, uint8_t * dest_array) {
    // needs atleast [6] array
	uint8_t* ptr_to_buffer;
	uint8_t int_buffer [5];

	ptr_to_buffer = &int_buffer[5];        // Point to buffer end
    *ptr_to_buffer = 0;
    do {
        // make characters, (uInteger % 10) = 5, 5 + '0' = 53=='5'
        *--ptr_to_buffer = (uInteger % 10) + '0';
    }while (uInteger /= 10 );

	while (*ptr_to_buffer) {
        *dest_array = *ptr_to_buffer;
        dest_array++;
        ptr_to_buffer++;
	}
    // end char
    *dest_array = '\0';
}