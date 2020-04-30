/*Address of m : 0x7ffcc3ad291c
 Value of m : 29                                                                                              
                                                                                                              
 Now ab is assigned with the address of m.                                                                    
 Address of pointer ab : 0x7ffcc3ad291c                                                                       
 Content of pointer ab : 29                                                                                   
                                                                                                              
 The value of m assigned to 34 now.                                                                           
 Address of pointer ab : 0x7ffcc3ad291c                                                                       
 Content of pointer ab : 34                                                                                   
                                                                                                              
 The pointer variable ab is assigned with the value 7 now.                                                    
 Address of m : 0x7ffcc3ad291c                                                                                
 Value of m : 7 */

#include <stdio.h>

int main(void){
    int m = 29;
    int *ab = &m;
    printf("Address of m = %p", &m);
    printf("\n Value of m=%d", m);
    printf("\nAddress of pointer ab = %p", ab);
    printf("\nValue of *ab =%i", *ab);
    m = 39;
    printf("\nValue of m is = %d", m);
    printf("\nAddress of pointer ab = %p", ab);
    printf("\nContet of *ab pointer is= %i", *ab);
    *ab = 7;
    printf("\nAddress of m = %p", &m);
    printf("\nvalue of m=%d", m);
}