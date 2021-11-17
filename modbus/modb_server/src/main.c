// http://manpages.ubuntu.com/manpages/precise/man7/libmodbus.7.html
// https://github.com/stephane/libmodbus/tree/master/doc
// https://libmodbus.org/docs/v3.1.6/
// https://www.fernhillsoftware.com/help/drivers/modbus/modbus-protocol.html#modbusTCP
// The Transaction Id field identifies the transaction.
// The Protocol field is zero to indicate Modbus protocol.
// The Length field is the number of following bytes.
// The Unit Address field is the PLC Address encoded as single byte.
// The Message field is a Modbus PDU. The maximum length of the Message field is is 253 bytes.
// The maximum Modbus TCP message length is 260 bytes.
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <modbus.h>
#define DEBUG 1
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

void debug_print(uint8_t message[]);
void incoming(uint8_t message[], modbus_t * context_ptr, int receive_con);
int main() {
    int socket;
    modbus_t *modb_ctx;
    int receive_con;
    int err;
    modbus_mapping_t *mb_mapping;
    uint8_t query[MODBUS_TCP_MAX_ADU_LENGTH];
    uint8_t exctracted[MODBUS_TCP_MAX_ADU_LENGTH];
    
    printf(CYN"<%p>\n"RESET, modb_ctx);
    err = initialize(&mb_mapping, &modb_ctx, &receive_con, &socket, LOCALHOST, PORT);
    printf(CYN"<%p>\n"RESET, modb_ctx);
    if (modbus_set_debug(modb_ctx, DEBUG) == -1) {
        printf("error setting debug");
    }
    if (err == ERROR) {
        printf(RED"Init failed, program shuts down\n"RESET);
    }
    printf(GRN"\nConnection established\n"RESET);
    for(;;) {
        printf("\n loop\n");

        incoming(query, modb_ctx, receive_con);
     
        modbus_reply(modb_ctx, query, receive_con, mb_mapping);
    }

    printf("Quit the loop: %s\n", modbus_strerror(errno));

    modbus_mapping_free(mb_mapping);

    if (close(socket) == -1) {
        printf("\n Error closing socket %s",modbus_strerror(errno));
    } 

    modbus_free(modb_ctx);


    return 0;
}
// Transaction Id	    Protocol	    Length	    Unit Address	    Message
//     2 Bytes	          2 Bytes	       2 Bytes	    1 Byte	        N Bytes
void incoming(uint8_t message[], modbus_t * context_ptr, int receive_con) {
    uint8_t transaction_id = 0;
    uint16_t protocol = 0;
    uint16_t lenght = 0;
    uint8_t unit_address = 0;
    uint8_t received_message[250];

    printf("INCOMING--->\n");
    receive_con = modbus_receive(context_ptr, message);   //Question 9) What does modbus_receive() do?
    for (int i = 0; i < 20; i++) {
        received_message[i] = message[i];
    }
    if (receive_con >= 0) {
        // modbus_get_byte_from_bits(const uint8_t *src, int index, unsigned int nb_bits);
        transaction_id = modbus_get_byte_from_bits(&message[0], 0, 8);
        printf("<<<<<<<<<<%d>>>><<<%d>>>>\n", transaction_id, message[0]);
    }
    printf("<------INCOMING\n");
}
// void debug_print(uint8_t message[]) {
//     for (int i = 0; i < MODBUS_TCP_MAX_ADU_LENGTH; i++) {
//         for (int ii = 0; ii < 12; ii++) {
//             printf("<%x%x>", (0x0f & (message[i]>>4)), (0x0f & message[i]));
//             i++;
//         }

//         printf("\n");
//     }
//     printf("\n");
// }

