#include "string.h"
#include <stdio.h>

int my_strlen(char *s) {
    int counter = 0;
    for (counter = 0; *s != '\0'; counter++) {
        s++;
    }
    return counter;
}
int my_strcmp (char *s, char *d) {
    int slenght = 0, dlenght = 0;
    for (int i = 0; *s != '\0'; i++) {
        slenght++;
        s++;
    }
    s -= slenght;
    for (int i = 0; *d != '\0'; i++) {
        dlenght++;
        d++;
    }
    d -= dlenght;

    int maxlen = 0;
    if (slenght == dlenght) {
        maxlen = slenght;
    }
    else if (slenght > dlenght) {
        maxlen = slenght;
    }
    else if (slenght < dlenght) {
        maxlen = dlenght;
    }
    
    for (int i = 0; i <= maxlen; i++) {
        if (*s != *d) {
            if (*s > *d) {
                return i+1;
            }
            else {
                return -i-1;
            }
        }
        s++;
        d++;
    }
    return 0;
}

void my_strcpy(char *d,char *s) {
    for (int i = 0; *s != '\0'; i++) {
        *d = *s;
        d++;
        s++;
    }
    *d = '\0';
}

int str2upper(char *s) {
    for (int i = 0; *s != '\0'; i++){
        if ((*s <= 'z') && (*s >= 'a')) {
            *s -= 32;
        }
        s++;
    }
    return 0;
}

int str2lower(char *s) {
    for (int i = 0; *s != '\0'; i++){
        if ((*s <= 'Z') && (*s >= 'A')) {
            *s += 32;
        }
        s++;
    }
    return 0;
}

int str_strip_numbers(char *s) {
    char temp[100];
    int counter = 0, lenght = 0;
    for (int i = 0; *s != '\0'; i++) {
        if (((*s <= 'Z') && (*s >= 'A')) || ((*s <= 'z') && (*s >= 'a'))) {
            temp[lenght] = *s;
            lenght++;
        }
        s++;
        counter++;
    }
    s -= counter;

    for (int i = 0; i < lenght; i++) {
        *s = temp[i];
        s++;
    }
    *s = '\0';
    return lenght;
}

char * my_strdupl(char *s) {
    char t[100];
    char *p = &t[0];
    int i = 0;
    for (i = 0; *s != '\0'; i++){
        t[i] = *s;
        s++;
    }
    t[i] = '\0';
    return p;
}