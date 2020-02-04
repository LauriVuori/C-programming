/* Write function that prints parameters stars*/


int main(void)
{
    int ask;
    printf("give number of stars:\n");
    scanf("%d", &ask);
    testfunc(ask);
}

void testfunc(int num){
    int i = 0;
    while(i != num){
        printf("*");
        i++;
    }

}
