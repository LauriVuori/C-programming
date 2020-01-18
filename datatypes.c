/* Example using different data types in C
Lauri Vuori*/

#include <stdio.h>

int main (void)
{
	int intergerVar = 100;
	float floatingVar = 75.452;
	double doubleVar = 5.23e+12;
	char charVar = 'K';

	_Bool boolVar = 0;

	printf ("intergerVar = %i\n", intergerVar);
	printf ("floatingVar = %f\n", floatingVar);
	printf ("doubleVar = %e\n", doubleVar);
	printf ("doubleVar = %g\n", doubleVar);
	printf ("charVar = %c\n", charVar);
	printf ("boolVar = %i\n", boolVar);
return 0;
}
