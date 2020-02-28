/*Write a function that takes a string an prints words  one per line, in a rectangular frame.

*********
* Hello *
* World *
* in    *
* a     *
* frame *
*********
*/

#include <stdio.h>

void print_boxed_text(char *s);
int main(void){
print_boxed_text("This");
}

void print_boxed_text(char *s){
    int i;
    int LongestWord = 0;
    int counter = 0;
    int spaces = 0;
    int a = 0;

    for(i= 0; s[i] != '\0' ; i++){
        if(s[i] == ' '){
            if(counter > LongestWord){
                LongestWord = counter;
                counter=0;
            }
        }
        else{
            LongestWord = i;
        }
        counter++;
    }
    for(int a = 0; a<= LongestWord +1 ; a++){
        printf("*");
    }
    printf("\n");
    i = 0;
    counter = 0;
    while(s[i] != '\0'){
        if(i== 0){
            printf("* ");
        }
        printf("%c", s[i]);
            counter ++;
            if(s[i] == ' '){
                if(counter < LongestWord){
                    spaces = LongestWord - counter;
                for(a = 0; a< spaces; a++){
                    printf(" ");
                    }
                spaces = 0;
                }
            counter = 0;
            printf("*\n* ");
            }
        i++;
    }
    spaces = 0;
        if(s[i] == '\0'){
                /*printf("counter on %d", counter);
                printf("Longestworld %d", LongestWord);*/
            if(counter < LongestWord){
            spaces = LongestWord - counter;
                for(a = 0; a< spaces; a++){
                    printf(" ");
                    }
                }
        }
    printf("*\n");
    for(int a = 0; a<= LongestWord +1; a++){
        printf("*");
    }
}



