/*Write a C -function that will print a given string from a string array pointed by pointers pointer.

void print_string(char **p, int amount);
Array have been defined like

const char *array[20];*/

const char *array[20];
#include <stdio.h>
void print_string(char **p, int i);
int main(void){
char *a[20]={"Hello","cat","dog","horse","tree","car"};
print_string(a,4);
}

void print_string(char **p, int i)
{
printf("%s", p[i]);
}
