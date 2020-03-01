/*Write function that reverses an array, c is showing the size of array

void reverse_arrayint a[],int c);*/
void reverse_array(int a[],int c);
int main(void){
int i,a[]={44,11,1,10,100,4,1,10,8,2};
int c=10;
reverse_array(a,c);
    for(i=0;i<c;i++){
        printf("%d ",a[i]);
    }
}

void reverse_array(int a[],int c){
    int newArray[15];
    int counter = c-1;

    for(int i = 0; i <=c; i++){
        newArray[i] = a[counter];
        counter--;
    }

    for(int i = 0; i < c; i++){
        a[i] = newArray[i];
    }
}
