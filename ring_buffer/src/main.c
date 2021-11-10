#include <stdio.h>
#include "../include/ring_buffer.h"


uint8_t transmission_buffer[MAX_BUFFER];
uint8_t recive_buffer[MAX_BUFFER];

int main(void) {
    struct buffer_type tb;
    int err;
    int i, len;


    // init_buffer(&tb,transmission_buffer);
    // len = add_char_to_buffer(&tb, 'a', (enum error_type*)&err);
    // print_buffer(tb);
    // ring_buffer_uint8_t rb_data;
    // int a = 0;
    // uint8_t test_buffer[55];
    // init_rb(&rb_data, &buffer[0], &buffer[BUFFER_LAST_ELEMENT], 0);
    // for (uint8_t i = 0; i < 5; i += (uint8_t)1) {
    //     write_byte_to_rb(&rb_data, i);
    // }
    
    // print_rb(&rb_data);
    // read_all_data(&rb_data, &test_buffer[0]);
    // printf("\n\n");
    // for (int i = 0; i < 10; i++) {
    //     printf("!%d!", test_buffer[i]);
    // }

    // write_byte_to_rb(&rb_data, (uint8_t)5);
    // write_byte_to_rb(&rb_data, (uint8_t)7);
    // for (int i = 0; i < 15; i++) {
    //     printf("<%d>", buffer[i]);
    // }
    // printf("\n");


    

    // get_rb_size(&test, buffer);
    // printf("%d\n", test.rb_size);
    // test.rb_size = sizeof(buffer) / sizeof(buffer[0]);
    // printf("<%d>\n", test.rb_size);
}

// init_buffer,
// determine if queue is empty or not
// determine if queue is full or ont
// get one byte from to queue, TAIL
// put a byte in to queue, HEAD,
// flush or clear
// print ring buffer


