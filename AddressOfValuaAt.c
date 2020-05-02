/*Pointer : Demonstrate the use of & and * operator :                                                          
--------------------------------------------------------                                                      
 m = 300                                                                                                      
 fx = 300.600006                                                                                              
 cht = z                                                                                                      
                                                                                                              
 Using & operator :                                                                                           
-----------------------                                                                                       
 address of m = 0x7ffda2eeeec8                                                                                
 address of fx = 0x7ffda2eeeecc                                                                               
 address of cht = 0x7ffda2eeeec7                                                                              
                                                                                                              
 Using & and * operator :                                                                                     
-----------------------------                                                                                 
 value at address of m = 300                                                                                  
 value at address of fx = 300.600006                                                                          
 value at address of cht = z                      

Using only pointer variable :                                                                                
----------------------------------                                                                            
 address of m = 0x7ffda2eeeec8                                                                                
 address of fx = 0x7ffda2eeeecc                                                                               
 address of cht = 0x7ffda2eeeec7                                                                              
                                                                                                              
 Using only pointer operator :                                                                                
----------------------------------                                                                            
 value at address of m = 300                                                                                  
 value at address of fx= 300.600006                                                                           
 value at address of cht= z */

 #include <stdio.h>

 int main(void){
     int m = 300, *p1;
     float fx = 300.600006, *p2;
     char cht = 'z', *p3;

     p1 = &m;
     p2 = &fx;
     p3 = &cht;


    printf("address of m =%p\n", &m);
    printf("address of fx =%p\n", &fx);
    printf("address of cht =%p\n", &cht);

     printf("Value of m =%d\n", *(&m));
     printf("Value of fx =%f\n", *(&fx));
     printf("Value of cht =%c\n", *(&cht));

     printf("address of m =%p\n", p1);
     printf("address of fx =%p\n", p2);
     printf("address of cht =%p\n", p3);   
     
     printf("Value of m =%d\n", *p1);
     printf("Value of fx =%f\n", *p2);
     printf("Value of cht =%c\n", *p3);
 }