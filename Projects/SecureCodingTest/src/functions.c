#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "userCredentials.h"
#include "funcDeclarations.h"


void print_data(char * name){
    for (int i = 0; *name != '\0'; i++) {
        printf("%c", *name);
        name++;
    }
}

void set_admin_credentials( char * firstname, 
                            char * lastname, 
                            char * username, 
                            char * password, 
                            struct admin * admin) {
    strcpy(admin->admin_firstname, firstname);
    strcpy(admin->admin_lastname, lastname);
    strcpy(admin->admin_username, username);
    strcpy(admin->admin_password, password);
}
void set_user_credentials(  char * firstname, 
                            char * lastname, 
                            char * username, 
                            char * password, 
                            struct user * user) {
                                
    strcpy(user->user_firstname, firstname);
    strcpy(user->user_lastname, lastname);
    strcpy(user->user_username, username);
    strcpy(user->user_password, password);
}