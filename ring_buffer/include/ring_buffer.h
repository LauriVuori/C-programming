#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_LENGHT 10
#define BUFFER_LAST_ELEMENT BUFFER_LENGHT-1

typedef signed char int8_t;
typedef unsigned char uint8_t;

typedef unsigned short uint16_t;
typedef signed short int16_t;

typedef unsigned int uint32_t;
typedef int int32_t;


#define MAX_BUFFER 10 ///< Length of global buffer space

#define OK 1     ///< OK
#define ERROR -1 ///< Error

#define BUFF_LEN(a, b) a < b ? b - a : a - b

//! \enum error_type enumerators for error conditions
enum error_type {
    BUFF_OK,        /*! No error */
    BUFFER_EMPTY,   /*! Buffer is empty */
    BUFFER_FULL,    /*! Buffer is full */
    BUFFER_OVERRUN, /*! Try to read over buffer end */
    BUFFER_ERROR,
    UNKNOWN_ERROR
};

/*
\struct buffer_type
*/
struct buffer_type {
    uint8_t *head;   ///< Current adding position of the buffer
    uint8_t *tail;   ///< Currently last entry
    uint8_t *buffer; ///< Pointer to buffer
};

void init_buffer(struct buffer_type *b, uint8_t *buffer);

void empty_buffer(struct buffer_type *b);

enum error_type create_buffer(struct buffer_type *b, int size);
int add_char_to_buffer(struct buffer_type *b, uint8_t c, enum error_type *err);
uint8_t get_char_from_buffer(struct buffer_type *b, enum error_type *err);
int add_string_to_buffer(struct buffer_type *b, uint8_t *s, enum error_type *err);
uint8_t get_string_from_buffer(struct buffer_type *b, uint8_t *s,
                            enum error_type *err);
int get_buffer_state(struct buffer_type b);
void print_buffer(struct buffer_type b);
uint8_t *move_pointer_to_next(struct buffer_type *b, uint8_t *p);

enum error_type is_buffer_full(struct buffer_type *b);
enum error_type is_buffer_empty(struct buffer_type *b);
int get_buffer_length(struct buffer_type *b);

extern uint8_t transmission_buffer[MAX_BUFFER];
extern uint8_t recive_buffer[MAX_BUFFER];