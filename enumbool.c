#include <stdio.h>

enum boolean {
    false = 0, 
    true = 1
}; 

struct test {
    enum boolean testi;
    int num;
};
void func2(int ** number2);
void func(struct test * testi, int * number);
int main(void) {
    struct test test = {true, 0};
    enum boolean bool;
    int number = 516;
    int *b = &number;
    test.testi = false;

    if (test.testi == false){
        printf("%d", test.testi);
    }

    func(&test, &number);

    if (test.testi == true){
        printf("%d, %d, %d", test.testi, test.num, number);
    }

    printf("\n<<%d>>", *b);
    b = &test.num;
    printf("\n>>%d<<", *b);

     
}
void func2(int ** number2){
    **number2 = 20;
}

void func(struct test * testi, int * number) {
    testi->testi = true;
    testi->num = 15;
    *number = 200;
    func2(&number);
}