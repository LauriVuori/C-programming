/*Write C-function that will take all  letters and numbers
from a string. Letters can be small and capital letters a-z

int strip_letters_numbers(char *s);

return value:

New length of string*/
#include <stdio.h>
int strip_letters_numbers(char *s);

int main(void){
char s[]="Kukku¤%&Luur()uu12";
printf("len=%d\n",strip_letters_numbers(s));
printf("%s\n",s);
}

int strip_letters_numbers(char *s){
	int count = 0;
	char temp[15];
	for(int i = 0; s[i] != '\0'; i++){
		if((s[i]>='0' && s[i]<= '9')||(s[i] >= 'A' && s[i]<= 'Z') || (s[i]>= 'a' && s[i]<= 'z')){
		}
		else{
        temp[count] = s[i];
            count++;
		}
	}
	int a = 0;
	for(a = 0; a <= count; a++){
        s[a]= temp[a];
	}
	s[a-1] = '\0';

	return count;
}

