#include <stdio.h>
#include <errno.h>
#ifndef INCLUDE_H
#include "../include/include.h"
#endif


// Transaction Id	    Protocol	    Length	    Unit Address	    Message
//     2 Bytes	          2 Bytes	       2 Bytes	    1 Byte	        N Bytes
// Ei käyttöä tällä hetkellä
void incoming(uint8_t received_message[], modbus_t * context_ptr) {
    int a = 0;
}