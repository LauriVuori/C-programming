/*Write a C-program

that will ask two distances in m,cm,mm store them into structs and add these two distances to third struct

Esimerkiksi:

Syöte	Tulos
1 1 1
2 2 2   3 3 3*/
#include <stdio.h>

struct distance
{
    int meter;
    int centimeter;
    int millimeter;
};

int main(void)
{

struct distance dis1;
struct distance dis2;
struct distance dis3;
scanf("%d %d %d", &dis1.millimeter, &dis2.millimeter, &dis3.millimeter);
scanf("%d %d %d", &dis1.centimeter, &dis2.centimeter, &dis3.centimeter);

dis1.meter = dis1.centimeter + dis1.millimeter;
dis2.meter = dis2.centimeter + dis2.millimeter;
dis3.meter = dis3.centimeter + dis3.millimeter;
printf("%d %d %d", dis1.meter,dis2.meter,dis3.meter);
}

