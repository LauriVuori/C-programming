/*Write a function that automatically print English text in Morse code

void print_morse(char *s);

Characters from A-Z  and '  ' and numbers 0-9 will be converted.

Unknown characters are printed with '?'*/

#include <stdio.h>


void print_morse(char *s);
int main(void){


print_morse("HELLO WORLD");

}
void print_morse(char *s){
int i;
int pointer = 0;
char *morse[37]={".-","-...","-.-.","-..",".","..-.","--.",
                "....","..",".---","-.-",".-..","--","-.",
                "---",".--.","--.-",".-.","...","-","..-",
                "...-",".--","-..-","-.--","--..","-----",
                ".----","..---","...--","....-",".....",
                "-....","--...","---..","----.","/"};


    for(i = 0; s[i] != '\0'; i++){  //65 = A

        if(s[i]>= 'A' && s[i]<= 'Z'){
            pointer = s[i] - 65;
            printf("%s", morse[pointer]);
            printf(" ");
        }
        else if(s[i]>= '0' && s[i]<='9'){
            pointer = s[i] - 22;
            printf("%s", morse[pointer]);
            printf(" ");
        }
        else if(s[i] == ' '){
            printf("  ");
        }
        else{
            printf("?");
        }
        pointer = 0;
    }
}
