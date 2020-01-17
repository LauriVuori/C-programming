/* Example of using arithmetic opertators in C
Lauri Vuori*/

#include <stdio.h>

int main(void)
{

	int a = 100;
	int b = 2;
	int c = 25;
	int d = 4;
	int result;

	result = a - b; //subtraction
	printf ("a=%i and b=%i\na - b = %i\n", a, b, result);
	
	result = b * c; //multiplication
	printf ("b=%i and c=%i\nb * c = %i\n", b, c, result);
	
	result = a / c; //division
	printf ("a=%i and c=%i\na / c = %i\n", a, c, result);

	result = a + b * c; //predence
	printf ("a=%i, b=%i and c=%i\na + b * c = %i\n", a, b, c, result);

	printf("a * b + c * d =%i\n", a * b + c * d);
return 0;
}
