#include <stdio.h>

struct distance
{
    int meter;
    int centimeter;   
    int millimeter;
};

int main(void)
{
struct distance d1={1,0,0};
struct distance d2={6,1,1},d3;
    d3.meter = d1.meter + d2.meter;
    d3.centimeter = d1.centimeter + d2.centimeter;
    d3.millimeter = d1.millimeter + d2.millimeter;

    printf("%d %d %d", d3.meter, d3.centimeter, d3.millimeter);

    
}