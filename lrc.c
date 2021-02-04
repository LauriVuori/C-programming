#include <stdio.h>
struct mb_message {
    unsigned char address;
    unsigned char function;
    unsigned int start_address;
    unsigned int stop_address;
    unsigned char amount;
};

unsigned char create_lrc(struct mb_message m);
int main(void) {
        
    struct mb_message m;

    m.address=0xed;
    m.function = 3;
    m.start_address = 0xd877;
    m.amount = 2;
    printf("<%02X>",create_lrc(m));
}
// e   d  0  3 d  8  7  7  0  0  0  2 -> 0010 1111 1000 = -8, 0010 0100 0001, 1011 1100
// 65 64 30 33 64 38 37 37 30 30 30 32 = 488
// ed03d8770002
// ed 03 d8 77 00 02
// 64 decimaali 0100 0000 -> 191 1011 1111
unsigned char create_lrc(struct mb_message m) {
    unsigned char  bytes[2];
    unsigned char bit = 0;
    int sum = 0;
    bytes[0] = *((unsigned char*)&(m.start_address)+1);
    bytes[1] = *((unsigned char*)&(m.start_address)+0);
    sum += m.address;
    sum += m.function;
    sum += m.amount;
    sum += bytes[0];
    sum += bytes[1];
    bit = -sum;
    return bit;
}