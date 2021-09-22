
#include<stdio.h>

typedef signed char int8_t;
typedef unsigned char uint8_t;

typedef unsigned short uint16_t;
typedef signed short int16_t;

typedef unsigned int uint32_t;
typedef int int32_t;

#define BIT_SET(shift) (1 << (shift))

void bin(unsigned n) {
    unsigned i;
    int counter = 1;
    for (i = 1 << 31; i > 0; i = i / 2) {
        (n & i) ? printf("1") : printf("0");

        if (counter % 4 == 0) {
            printf(" ");
        }
        counter++;
    }
    printf("\n");
    printf("HEX: %X\n", n);
}

void set_time(uint8_t hours_tens, uint8_t hours, uint8_t minutes_tens, uint8_t minutes, uint8_t seconds_tens, uint8_t seconds) {
		// seconds = RTC->TR & 0xF;
		// // Bits 6:4 ST[2:0]: Second tens in BCD format
		// seconds_tens = (RTC->TR & 0x70) >> 4;
		// // Bit 11:8 MNU[3:0]: Minute units in BCD format
		// minutes = (RTC->TR & 0xF00) >> 8;
		// // Bits 14:12 MNT[2:0]: Minute tens in BCD format
		// minutes_tens = (RTC->TR & 0x7000) >> 12;
		// // Bits 19:16 HU[3:0]: Hour units in BCD format
		// hours = (RTC->TR & 0xF0000) >> 16;
		// // Bits 21:20 HT[1:0]: Hour tens in BCD format
		// hours_tens = (RTC->TR & 0x300000) >> 20;
	uint32_t t;
	uint32_t temp;
	temp |= seconds;
	temp |= seconds_tens << 4;
	t = minutes << 8;
	temp |= t;
	t = minutes_tens << 12;
	temp |= t;
	t = hours << 16;
	temp |= t;
	t = hours_tens << 20;
    printf("<<<%d>>>", t);
	temp |= t;

    printf("%d%d:%d%d:%d%d", (temp&0x300000) >> 20, (temp&0xF0000)>>16, (temp&0x7000)>>12, (temp&0xF00)>>8, (temp&0x70)>>4,(temp&0xF));
    printf("<%X>", temp);
}


void set_date(uint8_t date_tens, uint8_t date, uint8_t month_tens, uint8_t month, uint8_t year_tens, uint8_t year) {
	// Bits 31-24 Reserved
	// Bits 23:20 YT[3:0]: Year tens in BCD format
	// Bits 19:16 YU[3:0]: Year units in BCD format
	// Bits 15:13 WDU[2:0]: Week day units
	// 000: forbidden
	// 001: Monday
	// ...
	// 111: Sunday
	// Bit 12 MT: Month tens in BCD format
	// Bits 11:8 MU: Month units in BCD format
	// Bits 7:6 Reserved, must be kept at reset value.
	// Bits 5:4 DT[1:0]: Date tens in BCD format
	// Bits 3:0 DU[3:0]: Date units in BCD format

	uint32_t temp = 0;
    temp |= date;
	temp |= date_tens << 4;
    // printf("<%X>", temp);
    temp |= month_tens << 12;
    // set_date(2,1,0,9,20,21);
    // temp |= (date_tens << 4);
    temp |= (month << 8);
    temp |= (year_tens << 20);
    // temp |= (month_tens << 12);
    // temp |= (year << 16);
    // temp |= (year_tens << 20);
    
    printf("%d%d.%d%d.%d", (temp&0x30) >> 4, temp&0xf, (temp&0x1000) >> 12, (temp&0xf00)>>8, (temp&0xF00000)>>20);//, temp&0xf);
    // printf("<%X>", (1 << 11) | (1 << 10) | (1 << 9) | (1 << 8));
    // printf("<%X>", (1 << 1)|(1 << 0)|(1<<2)|(1<<3));
    printf("<%X>", (1 << 23)|(1 << 22)|(1<<21)|(1<<20));
}

int main(void) {
    int t  = 0x000;
    t = (1 << 17) | (1 << 16);
    
    bin(t);
}