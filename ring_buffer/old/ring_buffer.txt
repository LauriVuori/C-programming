#include <stdio.h>
#include "../include/ring_buffer.h"

void read_all_data(ring_buffer_uint8_t * rb_data, uint8_t * dest_buffer) {
    while (rb_data->buffer_tail != rb_data->buffer_head) {
        *dest_buffer = *rb_data->buffer_tail;
        rb_data->buffer_tail++;
        dest_buffer++;
    }
}

void init_rb(ring_buffer_uint8_t * rb_data, uint8_t * buffer_start, uint8_t * buffer_end, uint8_t overwrite) {
    uint8_t counter = 0;
    rb_data->overwrite_on_off = overwrite;
    // Set head and tail
    rb_data->buffer_head = buffer_start;
    rb_data->buffer_tail = buffer_start;

    // set start and end
    rb_data->buffer_start = buffer_start;
    rb_data->buffer_end = buffer_end;
    for (counter = 1; buffer_start != buffer_end; counter += (uint8_t)1) {
        buffer_start++;
    }
    // Set buffer lenght, elements are lenght -1
    rb_data->rb_size = counter;  
}
// WORK IN PROGRESS
void write_byte_to_rb(ring_buffer_uint8_t * rb_data, uint8_t data) {
    *rb_data->buffer_head = data;
    // 1 2 3 4
    // Write untill end of array, else start from start
    if (rb_data->buffer_head != rb_data->buffer_end) {
        rb_data->buffer_head += 1;
        // if head meets tail, move tail one ahead
        if (rb_data->buffer_head == rb_data->buffer_tail) {

            if (rb_data->buffer_tail == rb_data->buffer_end) {
                rb_data->buffer_tail = rb_data->buffer_start;
            }
            else {
                rb_data->buffer_tail += 1;
            }
        }
    }
    else {
        rb_data->buffer_head = rb_data->buffer_start;
    }
}

uint8_t read_byte_from_rb(ring_buffer_uint8_t * rb_data) {
    uint8_t data;
    data = *rb_data->buffer_tail;
    if (rb_data->buffer_tail != rb_data->buffer_end) {
        rb_data->buffer_tail += 1;
    }
    else {
        rb_data->buffer_tail = rb_data->buffer_start;
    }
    return data;
}

void clear_rb(ring_buffer_uint8_t * rb_data) {
    uint8_t * ptr;
    
    ptr = rb_data->buffer_start;

    while(ptr != rb_data->buffer_end) {
        *ptr = 0;
        ptr++;
    }
    *ptr = 0;
    rb_data->buffer_tail = rb_data->buffer_head;
}

void print_rb(ring_buffer_uint8_t * rb_data) {
    uint8_t * ptr;
    uint16_t counter = 0;
    ptr = rb_data->buffer_start;

    while(ptr != rb_data->buffer_end) {
        printf("<%d:%d>", counter, *ptr);
        ptr++;
        counter++;
    }
    printf("<%d:%d>", counter, *ptr);
}