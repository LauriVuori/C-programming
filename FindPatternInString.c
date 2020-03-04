/*Create a C function that will find the pattern in the string

int find_string(char *s, char *a);

Function will return

position in string
-1 if string is not found*/
int find_string(char *s, char *a);
int main(void){
    printf("%d",find_string("HiihaaHello","l0"));

}


int find_string(char *s, char *a){
    int i;
    int counter = -1;
    for(i = 0; s[i] != '\0'; i++){
        if(s[i] == a[0] && s[i+1] == a[1]){
            counter = i;
            return counter;
        }
    }
    return counter;
}
