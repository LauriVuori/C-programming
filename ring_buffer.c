#include <stdio.h>

#define BUFFER_LENGHT 15
#define BUFFER_LAST_ELEMENT BUFFER_LENGHT-1

typedef signed char int8_t;
typedef unsigned char uint8_t;

typedef unsigned short uint16_t;
typedef signed short int16_t;

typedef unsigned int uint32_t;
typedef int int32_t;


typedef struct {
    size_t rb_size;
    // read from tail
    uint8_t * buffer_tail;
    // write to head
    uint8_t * buffer_head;

    uint8_t * buffer_start;
    uint8_t * buffer_end;

    uint8_t buffer_full;
    uint8_t buffer_empty;

    uint8_t overwrite_on_off;
} ring_buffer_uint8_t;

uint8_t buffer[BUFFER_LENGHT];



void init_rb(ring_buffer_uint8_t * rb_data, uint8_t * buffer_start, uint8_t * buffer_end, uint8_t overwrite);
void write_byte_to_rb(ring_buffer_uint8_t * rb_data, uint8_t data);
uint8_t read_byte_from_rb(ring_buffer_uint8_t * rb_data);
void read_all_data(ring_buffer_uint8_t * rb_data, uint8_t * dest_buffer);
// uint8_t read_n_bytes_from_rb(ring_buffer_uint8_t * rb_data, uint8_t * dest_buffer, uint8_t bytes);  not done

void clear_rb(ring_buffer_uint8_t * rb_data);
void print_rb(ring_buffer_uint8_t * rb_data);


int main(void) {
    ring_buffer_uint8_t rb_data;
    int a = 0;
    uint8_t test_buffer[55];
    init_rb(&rb_data, &buffer[0], &buffer[BUFFER_LAST_ELEMENT], 0);
    for (uint8_t i = 0; i < 5; i += (uint8_t)1) {
        write_byte_to_rb(&rb_data, i);
    }
    
    print_rb(&rb_data);
    read_all_data(&rb_data, &test_buffer[0]);
    printf("\n\n");
    for (int i = 0; i < 10; i++) {
        printf("!%d!", test_buffer[i]);
    }

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