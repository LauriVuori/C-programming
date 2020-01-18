/* C program that will ask data from user and print them
,both names, gender, age, shoe size, bank balance, address
and phone number
-Lauri Vuori*/

#include <stdio.h>

int main(void)
{
	char forename[15];
	char familyname [15];
	char gender;
	int age;
	float shoesize;
	float bbalance;
	char address[15];
	char pnumber[15];

	printf("What is your forename and familyname?\n");
	scanf("%s %s",forename, familyname);

	printf("Which gender are you M/F?\n");
	scanf(" %c", &gender);

	printf("How old are you?\n");
	scanf("%d",&age);

	printf("What is your shoe size?\n");
	scanf("%f",&shoesize);

	printf("What is your bank balance?\n");
	scanf("%f", &bbalance);

	printf("Which street do you live in?\n");
	scanf("%s", address);

	printf("What is your phone number?\n");
	scanf("%s", pnumber);

    printf("\n\nName:%s %s\nGender:%c\nAge:%i\nShoe size:%0.0f\nBank balance:%0.2f\nAdress:%s\nPhone number:%s\n",
    forename, familyname, gender, age, shoesize, bbalance, address, pnumber);
return 0;
}
