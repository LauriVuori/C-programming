/*Write a C function

void which_quadrant(int x, int y);

to accept a coordinate point in a XY coordinate system and determine in which quadrant the coordinate point lies

                   ^

                   |

         1        |        2

                   |

------------------------------->

                   |

         3        |         4

                   |
                   */
#include <stdio.h>

void which_quadrant(int x, int y);
int main(void){
which_quadrant(-4,5);
}

void which_quadrant(int x, int y)
{
    if(x < 0 && y > 0){
        printf("The coordinate point (%d,%d) lies in the first quadrant.",x,y);
    }
    else if(x > 0 && y > 0){
        printf("The coordinate point (%d,%d) lies in the second quadrant.",x,y);
    }
     else if(x < 0 && y < 0){
        printf("The coordinate point (%d,%d) lies in the third quadrant.",x,y);
    }
    else{
        printf("The coordinate point (%d,%d) lies in the fourth quadrant.",x,y);
    }
}
