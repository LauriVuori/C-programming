#include <stdio.h>
void UINT_TO_STRING(wint_t uInteger);

int main(void) {
    wint_t test = 23430;
    UINT_TO_STRING(test);
}
void UINT_TO_STRING(wint_t uInteger) {
    wint_t* pBuffer;
    wint_t intBuffer [6];
    int ii = 0;
    pBuffer = &intBuffer[5];
    *pBuffer = 0;
    do {
        *--pBuffer = (uInteger % 10) + '0';
    } while( uInteger /= 10 );
    while ( *pBuffer ) {
        intBuffer[ii] = *pBuffer;
        *pBuffer++;
        ii++;
    }
    printf("%s", intBuffer);
}
