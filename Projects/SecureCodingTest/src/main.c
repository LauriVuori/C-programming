#include <stdio.h>
#include <stdlib.h>
#include "userCredentials.h"
#include "funcDeclarations.h"

int main(void) {
    struct admin admin = {"admin"};  
    print_data(&admin.admin_username[0]);
    set_admin_credentials((char*)"asd", (char*)"asd", (char*)"asd", (char*)"asd", &admin);
}
