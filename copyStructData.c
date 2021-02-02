#include <stdio.h>
struct data
{
    int a;
    float b;
    char s[10];
};

void struct_copy(struct data * a, struct data * b);

int main(void) {
struct data a={200,3.2,{"JabaDaBa"}};
struct data b;
struct_copy(&a,&b);
printf("%d %.2f %s\n", b.a, b.b, b.s);

}

void struct_copy(struct data * a, struct data * b) {
    b->a = a->a;
    b->b = a->b;


    int i = 0;
    for (i = 0; a->s[i] != '\0'; i++) {
        b->s[i] = a->s[i];
    }
    b->s[i] = '\0';
}