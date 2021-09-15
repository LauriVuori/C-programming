#include <stdio.h>
typedef signed char int8_t;
typedef unsigned char uint8_t;

typedef unsigned short uint16_t;
typedef signed short int16_t;

typedef unsigned int uint32_t;
typedef int int32_t;
void uint16_to_char_array(uint16_t uInteger, uint8_t * dest_array);
void uint32_to_char_array(uint32_t uInteger, uint8_t * dest_array);
void uint8_to_char_array(uint8_t uInteger, uint8_t * dest_array);

void print(uint8_t * string) {	
    for (int i = 0; *string != '\0'; i++) {
		printf("%c", *string);
		string++;
	}
    printf("\n");
}

int main(void) {
    uint8_t integer8[12] = {0};
    uint8_t integer16[12] = {0};
    uint8_t integer32[12] = {0};
    // uint8_to_char_array(200, &integer8[0]);
    // uint16_to_char_array(5000, &integer16[0]);
    // print(&integer16[0]);
	uint8_to_char_array(255, &integer8[0]);
	print(&integer8[0]);
    // for (int i = 0; integer16[i] != '\0'; i++) {
    //     printf("<%c><%d>\n", integer16[i], integer16[i]);
    // }
    uint16_to_char_array(65000, integer16);
    print(integer16);
    // printf("\n");
    uint32_to_char_array(1120000, &integer32[0]);
	print(integer32);
	//     for (int i = 0; integer32[i] != '\0'; i++) {
    //     printf("<%c><%d>\n", integer32[i], integer32[i]);
    // }
}
void uint8_to_char_array(uint8_t uInteger, uint8_t * dest_array) {
    // needs atleast [6] array
	uint8_t* ptr_to_buffer;
	uint8_t int_buffer [5];

	ptr_to_buffer = &int_buffer[4];        // Point to buffer end
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

void uint16_to_char_array(uint16_t uInteger, uint8_t * dest_array) {
	// needs atleast [6] array
	uint8_t* ptr_to_buffer;
	uint8_t int_buffer [11];

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
	uint8_t int_buffer [12];

	ptr_to_buffer = &int_buffer[11];        // Point to buffer end
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