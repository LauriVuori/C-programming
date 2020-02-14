/* Find two numbers from Write a C program that will find 
pair of numbers using the biggest number, that 
will give the predefined sum
Array is sorted i accending order, len have size of array
int find_pair(int *arr, int len, int sum, int *a, int *b);
Return value:
0 not found
1 found, a&b has the array index to numbers*/


#include <stdio.h>


int main(void)
{
int arr[]={1,2,3,9};
int a,b;
printf("%d,",find_pair(arr,6,8,&a,&b));
printf("%d %d",a,b);
}

int find_pair(int *arr, int len, int sum, int *a, int *b)
{
    int i;
    int z;
    int funsum = 0;
    for(i = 0; i<= len; i++){
        for(z = i+1; z<=len; z++){
            funsum = arr[i]+arr[z];
            if(funsum == sum){
                *a=i;
                *b=z;
                return 1;
            }
            else
            {
                funsum=0;
            }
        }
    }
    *a=i;
    *b=z;
    return 0;
}
