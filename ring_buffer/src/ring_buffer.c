#include <stdio.h>
#include "../include/include.h"
void init_buffer(struct buffer_type *r_buffer, uint8_t *buffer_start, uint8_t *buffer_end) {
    r_buffer->buffer_start = buffer_start;
    r_buffer->head = buffer_start;
    r_buffer->tail = buffer_start;
    r_buffer->buffer_end = buffer_end;
}
int add_byte_to_buffer(struct buffer_type *r_buffer, uint8_t byte, enum error_type *err) {
    *r_buffer->head = byte;
    // Write untill end of array, else start from start
    // if (r_buffer->head != r_buffer->buffer) {
    //     r_buffer->head += 1;
    //     // if head meets tail, move tail one ahead
    //     if (r_buffer->head == r_buffer->tail) {

    //         if (r_buffer->tail == r_buffer->buffer_end) {
    //             r_buffer->tail = r_buffer->buffer_start;
    //         }
    //         else {
    //             r_buffer->buffer_tail += 1;
    //         }
    //     }
    // }
    // else {
    //     r_buffer->head = r_buffer->buffer_start;
    // }

    *err = BUFF_OK;
}
void empty_buffer(struct buffer_type *r_buffer) {

}

enum error_type create_buffer(struct buffer_type *r_buffer, int size)
{}


uint8_t get_char_from_buffer(struct buffer_type *r_buffer,
                                             enum error_type *err)
{}
int add_string_to_buffer(struct buffer_type *r_buffer, uint8_t *s,
                         enum error_type *err)
{}
uint8_t get_string_from_buffer(struct buffer_type *r_buffer, uint8_t *s,
                                     enum error_type *err)
{}
int get_buffer_state(struct buffer_type r_buffer)
{}
void print_buffer(struct buffer_type r_buffer) {

    int size = 0;
    for (size = 0; (r_buffer.buffer_start + size) != r_buffer.buffer_end; size++);

    printf("Buffer contents:\n");
    for (uint8_t i = 0; i <= size; i++) {

        printf("<%d,%c>", i, (*(r_buffer.buffer_start+i) != '\0' ? *(r_buffer.buffer_start+i) : ' '));
    }
    printf("\n");
    for (uint8_t i = 0; i <= size; i++) {
        if (r_buffer.head == r_buffer.buffer_start+i) {
            printf("  H  ");
        }
        else {
            printf("     ");
        }
    }
    printf("\n");
    for (uint8_t i = 0; i <= size; i++) {
        if (r_buffer.tail == r_buffer.buffer_start+i) {
            printf("  T  ");
        }
        else {
            printf("     ");
        }
    }
    printf("<<%c>>", *r_buffer.buffer_start);
}
uint8_t *move_pointer_to_next(struct buffer_type *r_buffer, uint8_t *p)
{}