/* ask radius and calculate area of circle
-Lauri Vuori*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    float radius, area;

    printf("What is radius of circle?\n");
    scanf(" %f", &radius);

    area = M_PI * (radius * radius);
    printf ("Area is: %0.2f", area);

    return 0;
}
