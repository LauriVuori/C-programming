#include <stdio.h>



void reverse_array(char s[]);

int main(void) {
    int i;
    char a[]="";
    reverse_array(a);
    for(i=0;i<5;i++)
        printf("%c ",a[i]);
}
void reverse_array(char s[]) {
    int counter = 0, a;
    char temp[50];
    for (int i = 0; s[i] != '\0'; i++) {
        counter++;
    }
    if (counter > 0){
        a = counter;
        counter--;
        for (int i = 0; i <= a; i++) {
            temp[i] = s[counter];
            counter--;
        }

        for (int i = 0; i <= a; i++){
            s[i] = temp[i];
        }
    }
}