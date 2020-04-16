#include <stdio.h>
int check_if_palindrome(char s[]);
int main(void){
    printf("%d",check_if_palindrome("saippuakauppias"));
}

int check_if_palindrome(char s[]){
    int lenght = 0, i;

    for (i = 0; s[i] != '\0'; i++){
        lenght++;
    }
    lenght--;
    i = 0;
    
        while(lenght >= 0){
            if(s[i] != s[lenght]){
                return 0;
            }
            i++;
            lenght--;
        }
return 1;
}