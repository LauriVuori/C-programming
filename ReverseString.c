/*write function that will reverse print a string*/

void swapstr(char *s);
int main(void){
swapstr("abcdef");
}


void swapstr(char *s){
int i = 0;
int reverse = 0;
while(s[i] != '\0'){
    i++;
}
int b = 0;
reverse = i;
while(b< i){
    reverse--;
    printf("%c", s[reverse]);
    b++;
}
}
