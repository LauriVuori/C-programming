#include <stdio.h>

int dividable_3_5(int i);

int main(void){
    printf("%d",dividable_3_5(15));
}

int dividable_3_5(int i){

    if ((i % 3== 0) && (i % 5 == 0)){
      return 1;
    }
    else{
      return 0;
    }
}