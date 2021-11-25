#include <stdio.h>
#include "../modbus_lib/include/modbus/modbus.h"
#include <errno.h>
#ifndef INCLUDE_H
#include "../include/include.h"
#endif

int initialize(modbus_mapping_t **mb_mapping, modbus_t **modb_ctx, 
                int * r_connectiong, int * socket, char ip_address[], uint16_t port) {
    *modb_ctx = modbus_new_tcp(ip_address, port);

    
    if (*modb_ctx == NULL) {
        printf("Unable to allocate libmodbus context,%s\n", modbus_strerror(errno));
        return ERROR;
    }
    // modbus_mapping_t modbus_mapping_new(int nb_bits, int nb_input_bits, int nb_registers, int nb_input_registers);*
    *mb_mapping = modbus_mapping_new(DISCRETE_INPUTS, COILS,
                                INPUT_REGISTERS, HOLDING_REGISTERS);

    if (*mb_mapping == NULL) {
        fprintf(stderr, "Failed to allecate mapping %s\n", modbus_strerror(errno));
        return ERROR;
    }
    *socket = modbus_tcp_listen(*modb_ctx, MAX_CONNECTIONS);
    if(*socket == ERROR) {
        printf("Unable to  %s", modbus_strerror(errno));
        modbus_free(*modb_ctx);
        return ERROR;
    }
    printf(YEL"\nListening connectins...\n"RESET);
    *r_connectiong = modbus_tcp_accept(*modb_ctx, socket);
    if (*r_connectiong == ERROR) {
        printf("Could not accept new connection: %s\n", modbus_strerror(errno));
        close(socket);
        modbus_free(*modb_ctx);
        return ERROR;
    }
    return OK;
}
// The function writes data to the 
// coils/bits/holding registers/input registers 
// supported by the server. 
// libmodbus has functionality for this, 
// do not attempt to access the server 
// memory map (it's a
// structure) directly.
// Hint: create an array of unsigned 8 bit values and convert bytes to bits.

// Writes data 
// Coils
// Bits
// Holding registers
// input registers
void createData();
