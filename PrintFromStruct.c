#include <stdio.h>

struct person{
    char name[30];
    int age;
    float salary;
    int shoe_size;
};

void print_struct (struct person a);

int main(void){
    struct person a={{"Charley Brown"},24,3550,43};
    print_struct(a);
}
void print_struct (struct person a){
    printf("%s %d %0.2f %d", a.name, a.age, a.salary, a.shoe_size);
}