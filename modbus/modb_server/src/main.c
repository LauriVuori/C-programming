#include <stdio.h>
#include <errno.h>
#include <modbus.h>
#ifndef INCLUDE_H
#include "../include/include.h"
#endif
// The function
// 1. sets up a modbus mapping
// 2. calls the createData() function
// 3. opens a TCP socket
// 4. waits for incoming data.
// 5. when the TCP handshake with the Modbus master is complete, the function returns. Return
// value: 0 on success, -1 on error.


int main() {
    int socket;
    modbus_t *modb_ctx;
    int receive_con;
    int err;
    modbus_mapping_t *mb_mapping;
    err = initialize(mb_mapping, modb_ctx, &receive_con, &socket, LOCALHOST, PORT);
    if (err == ERROR) {
        printf(RED"Init failed, program shuts down\n"RESET);
    }
    printf(GRN"\nConnection established\n"RESET);
}


