#define BUFFERLEN 50


struct complex {
    float real;
    float im;
};

struct complex * complex_addition(struct complex *a, struct complex *b);
void swap_complex (struct complex *number, struct complex *numbe2);
void read_complex (struct complex *number);
void print_complex (struct complex *number);
int checkInput (char * buffer);
struct complex * complex_subtract(struct complex *a, struct complex *b);
struct complex * complex_multiply(struct complex *a, struct complex *b);
struct complex * complex_divide(struct complex *a, struct complex *b);
