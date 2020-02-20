/*Write C function that will return the number of selected character in a string

int count_char(char str[], char c);
Input parameters
str is the string where to search characters

c is the character to be counted

Return value
number of given characters in str

Program output
Give a string: Hello World
Give character to be searched: o

In string there is 2 of selected characters*/
int count_char(char str[], char c);
int main(void){

    char input[100];
    char search;
    int HowMany = 0;
    printf("Give a string:\n");
    scanf("%s", input);
    printf("Give character to be searched:\n");
    scanf(" %c", &search);
    HowMany = count_char(input, search);
    printf("In string there is %d of selected characters",HowMany);
}

int count_char(char str[], char c){
    int count = 0;
    int i = 0;
    while(str[i] != '\0'){
    if(str[i] == c){
    count++;
    }
    i++;
    }
    return count;
}
