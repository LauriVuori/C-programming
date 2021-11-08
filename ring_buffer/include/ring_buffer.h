
#define BUFFER_LENGHT 10
#define BUFFER_LAST_ELEMENT BUFFER_LENGHT-1

typedef signed char int8_t;
typedef unsigned char uint8_t;

typedef unsigned short uint16_t;
typedef signed short int16_t;

typedef unsigned int uint32_t;
typedef int int32_t;


typedef struct Ring_buffer{
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



void init_rb(ring_buffer_uint8_t * rb_data, uint8_t * buffer_start, uint8_t * buffer_end, uint8_t overwrite);
void write_byte_to_rb(ring_buffer_uint8_t * rb_data, uint8_t data);
uint8_t read_byte_from_rb(ring_buffer_uint8_t * rb_data);
void read_all_data(ring_buffer_uint8_t * rb_data, uint8_t * dest_buffer);
// uint8_t read_n_bytes_from_rb(ring_buffer_uint8_t * rb_data, uint8_t * dest_buffer, uint8_t bytes);  not done

void clear_rb(ring_buffer_uint8_t * rb_data);
void print_rb(ring_buffer_uint8_t * rb_data);

// uint8_t buffer[BUFFER_LENGHT];