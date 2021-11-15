#include <stdio.h>
#include "../include/include.h"


uint8_t transmission_buffer[MAX_BUFFER];
uint8_t recive_buffer[MAX_BUFFER];

int main(void) {
    struct buffer_type tb;
    int err;
    int i, len;

    printf("THIS IS MAIN\n");

    init_buffer(&tb,transmission_buffer, &transmission_buffer[MAX_BUFFER-1], 0);
    for (int i = 0; i < 15; i++) {
        add_byte_to_buffer(&tb, i + 'a',(enum error_type*)&err);
    }
    // len = check_byte_count_in_buffer(&tb);
}

// init_buffer,
// determine if queue is empty or not
// determine if queue is full or ont
// get one byte from to queue, TAIL
// put a byte in to queue, HEAD,
// flush or clear
// print ring buffer


