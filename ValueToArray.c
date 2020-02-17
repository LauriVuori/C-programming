/*Write function that will add value (given as parameter) to all elentnts in array, c is showing the size of array

void add_to_array(int a[],int value,int c);

Esimerkiksi:

Testi	Tulos
int i,a[]={44,11,1,10,100,4,1,10,8,2};
int c=10;
add_to_array(a,33,c);
for(i=0;i<c;i++)
    printf("%d ",a[i]);*/
#include <stdio.h>
void add_to_array(int a[],int value,int c);
int main(void){
    int i,a[]={44,11,1,10,100,4,1,10,8,2};
    int c=10;
    add_to_array(a,33,c);

        for(i=0;i<c;i++){
            printf("%d ",a[i]);
        }
}

void add_to_array(int a[],int value,int c){

    for(int i = 0; i< c; i++){
        a[i]+=value;
    }

}
