

#include <stdio.h>

int days_in_month(int month);
int main(void){
    int number =0;
    printf("Give month number:\n");
    scanf("%d", &number);

    days_in_month(number);
}

int days_in_month(int month){
int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
switch(month)
{
    case 1:
    printf("There are days %d in January", days[1]);
    break;

    case 2:
    printf("There are days %d in February", days[2]);
    break;

    case 3:
    printf("There are days %d in March", days[3]);
    break;

    case 4:
    printf("There are days %d in April", days[4]);
    break;

    case 5:
    printf("There are days %d in May", days[5]);
    break;

    case 6:
    printf("There are days %d in June", days[6]);
    break;

    case 7:
    printf("There are days %d in July", days[7]);
    break;

    case 8:
    printf("There are days %d in August", days[8]);
    break;

    case 9:
    printf("There are days %d in September", days[9]);
    break;

    case 10:
    printf("There are days %d in October", days[10]);
    break;

    case 11:
    printf("There are days %d in Bvember", days[11]);
    break;

    case 12:
    printf("There are days %d in December", days[12]);
    break;
    default:
        printf("That is not month");
}
}

