/*
*/
#include "../include/my_math.h"
float calc_average(float data[], int size)
{
	int i;
	float average=0;

	for (i=1;i<=size;i++)
	{
	average=average+data[i];
	}

    return average/size;
}

