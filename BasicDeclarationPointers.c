/* Pointer : Show the basic declaration of pointer :                                                            
-------------------------------------------------------                                                       
 Here is m=10, n and o are two integer variable and *z is an integer                                          
                                                                                                              
 z stores the address of m  = 0x7ffd40630d44                                                                  
                                                                                                              
 *z stores the value of m = 10                                                                                
                                                                                                              
 &m is the address of m = 0x7ffd40630d44                                                                      
                                                                                                              
 &n stores the address of n = 0x7ffd40630d48                                                                  
                                                                                                              
 &o  stores the address of o = 0x7ffd40630d4c                                                                 
                                                                                                              
 &z stores the address of z = 0x7ffd40630d50 */

 #include <stdio.h>
void pointertest(int *mAddress);
int main(void){
int m = 10 , n, o;
int *z = &m;
    printf("z stores address of m = %p\n", z);
    printf("*z stores value of m= %i\n", *z);
    printf("&m is address of m= %p", &m);
    printf("&n stores the address of n = %p\n", &n);
	printf("&o  stores the address of o = %p\n", &o);
	printf("&z stores the address of z = %p\n\n", &z);
    pointertest(&m); // same as *p
    printf("New value assigned to m = %d", m);

 }

 void pointertest(int *mAddress){
     printf("mAddress is address of m in function= <%p>\n", mAddress);
     *mAddress = 1;
 }