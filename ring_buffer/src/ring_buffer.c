#include <stdio.h>
#include "../include/include.h"
// init buffer
void init_buffer(struct buffer_type *r_buffer, uint8_t *buffer_start, uint8_t *buffer_end) {
    r_buffer->buffer_start = buffer_start;
    r_buffer->head = buffer_start;
    r_buffer->tail = buffer_start;
    r_buffer->buffer_end = buffer_end;
}
// adds byte to char. 
int add_byte_to_buffer(struct buffer_type *r_buffer, uint8_t byte, enum error_type *err) {
    if (r_buffer->head+1 == r_buffer->tail) {
        *err = BUFFER_FULL;
        return -1;
    }

    if (r_buffer->head == r_buffer->buffer_end) {
        if (r_buffer->tail == r_buffer->buffer_start) {
            *err = BUFFER_FULL;
            return -1;
        }
    }

    *r_buffer->head = byte;
    
    if (r_buffer->head == r_buffer->buffer_end) {
        if (r_buffer->tail == r_buffer->buffer_start) {
            *err = BUFFER_FULL;
            return -1;
        }
        r_buffer->head = r_buffer->buffer_start;
    }
    else {
        r_buffer->head++;
    }

    *err = BUFF_OK;
    return OK;
}

// int check_byte_count_in_buffer(struct buffer_type *r_buffer) {
//     uint8_t *test;
//     uint8_t counter = 0;
//     uint8_t multiplier = 0;
//     test = r_buffer->tail;
//     while (test != r_buffer->head){
//         counter++;
//         test++;
//         print_buffer(*r_buffer);
//         if (test == r_buffer->buffer_end) {
//             test = r_buffer->buffer_start;
//         }
//     }
//     return counter;
// }

// count bytes from tail to head
// Not implemented yet is that if array is larger that 255
int check_byte_count_in_buffer(struct buffer_type *r_buffer) {
    uint8_t *ptr;
    uint8_t counter = 0;
    // uint8_t multiplier = 0;
    ptr = r_buffer->tail;
    while (ptr != r_buffer->head){
        if (ptr == r_buffer->buffer_end) {
            counter++;
            ptr = r_buffer->buffer_start;
        }
        else {
            counter++;
            ptr++;
        }
    }
    return counter;
}
void empty_buffer(struct buffer_type *r_buffer) {
    printf("a");
}

enum error_type create_buffer(struct buffer_type *r_buffer, int size) {
    printf("a");
    enum error_type a = BUFF_OK;
    return a;
}


uint8_t get_char_from_buffer(struct buffer_type *r_buffer,
                                             enum error_type *err) {
    printf("a");
    uint8_t a = 0;
    return a;
}
int add_string_to_buffer(struct buffer_type *r_buffer, uint8_t *s,
                         enum error_type *err) {
    printf("a");
    int a = 0;
    return a;
}
uint8_t get_string_from_buffer(struct buffer_type *r_buffer, uint8_t *s,
                                     enum error_type *err) {
    printf("a");
    uint8_t a = 0;
    return a;
}
int get_buffer_state(struct buffer_type r_buffer) {
    printf("a");
    int a = 0;
    return a;
}
void print_buffer(struct buffer_type r_buffer) {

    int size = 0;
    for (size = 0; (r_buffer.buffer_start + size) != r_buffer.buffer_end; size++);

    printf("Buffer contents:\n");
    for (uint8_t i = 0; i <= size; i++) {

        printf("<%d,%c>", i, (*(r_buffer.buffer_start+i) != ('\0') ? *(r_buffer.buffer_start+i) : ' '));
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
    printf("\n");
    // printf("<<%d>>", *r_buffer.buffer_start);
}
uint8_t *move_pointer_to_next(struct buffer_type *r_buffer, uint8_t *p) {
    return p;
}