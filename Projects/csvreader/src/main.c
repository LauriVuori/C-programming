#include <stdio.h>
#include <string.h>
//#include "dec.h"

void printWithDelimiter(char * str);

int main (void) {
    char str[80];
    char oneline [200] = {};
    const char s[2] = ";";
    char *token;
    //FILE *fp = fopen("../csv/test.txt", "r");

    FILE *fp = fopen("../csv/2.1.2021.csv", "r");

    while (!feof(fp)) {
        
        fgets(oneline, 200, fp);
        printWithDelimiter(oneline);
        // printf("%s", oneline);
    }
    fclose(fp);

//    /* get the first token */
//    token = strtok(str, s);
   
//    /* walk through other tokens */
//    while( token != NULL ) {
//       printf( " %s\n", token );
//       token = strtok(NULL, s);
//    }
   
   return(0);
}
void printWithDelimiter(char * str) {
    const char delimiter[2] = ";";
    char *token;
    token = strtok(str, delimiter);
    while( token != NULL ) {
      printf("-%s\n", token );
      token = strtok(NULL, delimiter);
    }
}

// int main () {
//    char str[80] = "This; is; - www;tutorialspoint.com - website;";
//    const char s[2] = ";";
//    char *token;
   
//    /* get the first token */
//    token = strtok(str, s);
   
//    /* walk through other tokens */
//    while( token != NULL ) {
//       printf( " %s\n", token );
//       token = strtok(NULL, s);
//    }
   
//    return(0);
// }