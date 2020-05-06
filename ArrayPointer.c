/*Input the number of elements to store in the array :5
Input 5 number of elements in the array :
element - 0 : 5
element - 1 : 7
element - 2 : 2
element - 3 : 9
element - 4 : 8
Expected Output :

 The elements you entered are :                                                                               
 element - 0 : 5                                                                                              
 element - 1 : 7                                                                                              
 element - 2 : 2                                                                                              
 element - 3 : 9                                                                                              
 element - 4 : 8  */

 #include <stdio.h>

 int main(void){
     int array[5] = {5, 7, 2, 9, 8};
     
     for (int i = 0; i < 5; i++){
         printf("entered elements:%d pointer: %d\n",array[i], *(array+i));
     }
 }