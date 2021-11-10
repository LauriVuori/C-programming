#include <stdio.h>
#include "../include/ring_buffer.h"

void init_buffer(struct buffer_type *b, uint8_t *buffer) {
    b->buffer = buffer;
    b->head = buffer;
    b->tail = buffer;
}
int add_char_to_buffer(struct buffer_type *b, uint8_t c, enum error_type *err) {
    *b->head = c;
    // Write untill end of array, else start from start
    // if (rb_data->buffer_head != rb_data->buffer) {
    //     rb_data->buffer_head += 1;
    //     // if head meets tail, move tail one ahead
    //     if (rb_data->buffer_head == rb_data->buffer_tail) {

    //         if (rb_data->buffer_tail == rb_data->buffer_end) {
    //             rb_data->buffer_tail = rb_data->buffer_start;
    //         }
    //         else {
    //             rb_data->buffer_tail += 1;
    //         }
    //     }
    // }
    // else {
    //     rb_data->buffer_head = rb_data->buffer_start;
    // }

    *err = BUFF_OK;
}
void empty_buffer(struct buffer_type *b) {

}

enum error_type create_buffer(struct buffer_type *b, int size)
{}


uint8_t get_char_from_buffer(struct buffer_type *b,
                                             enum error_type *err)
{}
int add_string_to_buffer(struct buffer_type *b, uint8_t *s,
                         enum error_type *err)
{}
uint8_t get_string_from_buffer(struct buffer_type *b, uint8_t *s,
                                     enum error_type *err)
{}
int get_buffer_state(struct buffer_type b)
{}
void print_buffer(struct buffer_type b) {
    printf("Buffer contents:\n");
    for (uint8_t i = 0; i < MAX_BUFFER; i++) {

        printf("<%d,%c>", i, (*(b.buffer+i) != '\0' ? *(b.buffer+i) : ' '));
    }
    printf("\n");
    for (uint8_t i = 0; i < MAX_BUFFER; i++) {
        if (b.head == b.buffer+i) {
            printf("  H  ");
        }
        else {
            printf("     ");
        }
    }
    printf("\n");
    for (uint8_t i = 0; i < MAX_BUFFER; i++) {
        if (b.tail == b.buffer+i) {
            printf("  T  ");
        }
        else {
            printf("     ");
        }
    }
    // printf("<<%c>>", *b.buffer);
}
uint8_t *move_pointer_to_next(struct buffer_type *b, uint8_t *p)
{}