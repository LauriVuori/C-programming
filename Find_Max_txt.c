#include <stdio.h>



float find_max(void);
int main(void){

    float max_value;
    max_value = find_max();
    printf("%f", max_value);
}


float find_max(void){
    char line[1000];
    float temp[1000];
    float max =0;
    int i = 0;
    FILE *fp = fopen("day_temp.txt", "r");

    while(!feof(fp)){
        fgets(line, 1000, fp);

        sscanf(line, "%f", &temp[i]);
            if (temp[i] > max){
                max = temp[i];
            }
        i++;
    }
    return max;
}