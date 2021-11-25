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

// #ifndef CREATEDIR_H
// #define CREATEDATA_H
// void createData();
// #endif


#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "../modbus_lib/include/modbus/modbus.h"
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

// void debug_print(uint8_t message[]);
void print_maps(modbus_mapping_t *mb_mapping);
void testing(modbus_t *ctx, const uint8_t *req,
                 int req_length, modbus_mapping_t *mb_mapping);
int main(void) {
    int socket;
    modbus_t *modb_ctx;
    int receive_con;
    int err;
    modbus_mapping_t *mb_mapping;
    if (DEBUG == 1) {
        printf(RED"\nDEBUG ON\n"RESET);
    }
    uint8_t exctracted[MODBUS_TCP_MAX_ADU_LENGTH];
    
    err = initialize(&mb_mapping, &modb_ctx, &receive_con, &socket, LOCALHOST, PORT);

    if (modbus_set_debug(modb_ctx, DEBUG) == -1) {
        printf("error setting debug");
        return -1;
    }
    if (err == ERROR) {
        printf(RED"Init failed, program shuts down\n"RESET);
        return -1;
    }
    printf(GRN"\nConnection established\n"RESET);
    for(;;) {
        printf("\nWaiting for incoming message...\n");
        uint8_t query[MODBUS_TCP_MAX_ADU_LENGTH];
        uint8_t msg[100];
        uint8_t msg_len = 0;
        msg_len = incoming(query, modb_ctx, &receive_con, msg);
        printf("\n<<<<%d>>>\n", msg_len);
        // int a = modbus_receive(modb_ctx, query);
        if (receive_con >= 0) {
            modbus_reply(modb_ctx, query, receive_con, mb_mapping);
            // send_msg(modbus_t *ctx, uint8_t *msg, int msg_length);
            // uint8_t msg[50] = {0x1,0x2,0x3,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x6,0x0,0x0,0x0,0x6,0x0,0x0,0x0,0x7,0xf,0xf,0xf,0xf};
            // uint8_t msg[50] = {0x0,0x1,0x0,0x0,0x0,0x6,0x0,0x5,0x0,0x0,0x0,0x0};
            // uint8_t byte_count = 0;
            // byte_count = modbus_get_byte_from_bits(query, 12, 1);
            // for (int i = 0; i < 13; i++) {
            //     printf("\n<<%x>>\n", msg[i]);
            // }
            printf("\n");
            for (int i = 0; i < msg_len; i++) {
                printf("<!%x!>", msg[i]);
            }
            printf("\n");
            send_msg(modb_ctx, msg, msg_len);
            // createData(&mb_mapping, &modb_ctx, query);
            // print_maps(mb_mapping);
            // printf("\n--->");
            // for (int i = 0; i < 8; i++) {
            //     printf("!<%d>!", *(mb_mapping->tab_bits+i));
            // }
            // createData(mb_mapping, query);

        }
        else {
            break;
        }

         
    }

    printf("Quit the loop: %s\n", modbus_strerror(errno));

    modbus_mapping_free(mb_mapping);

    if (close(socket) == -1) {
        printf("\n Error closing socket %s",modbus_strerror(errno));
    } 

    modbus_free(modb_ctx);

    return 0;
}

// typedef struct _modbus_mapping_t {
//     int nb_bits;
//     int start_bits;
//     int nb_input_bits;
//     int start_input_bits;
//     int nb_input_registers;
//     int start_input_registers;
//     int nb_registers;
//     int start_registers;
//     uint8_t *tab_bits;
//     uint8_t *tab_input_bits;
//     uint16_t *tab_input_registers;
//     uint16_t *tab_registers;
// } modbus_mapping_t;
void print_maps(modbus_mapping_t *mb_mapping) {
    // uint8_t *tab_bits;
    // uint8_t *tab_input_bits;
    // uint16_t *tab_input_registers;
    // uint16_t *tab_registers;
    // bits
    // for (int i = 0; i < 8; i++) {
    //     printf("<%d>", *(mb_mapping->tab_bits+i));
    // }
    for (int i = 0; i < 8; i++) {
        // printf("<%d>", *(mb_mapping->tab_bits+i));
        *(mb_mapping->tab_bits+i) = i; 
        printf("<%d>", *(mb_mapping->tab_bits+i));
    }
    
}
// void debug_print(uint8_t received_message[]) {
//     for (int i = 0; i < MODBUS_TCP_MAX_ADU_LENGTH; i++) {
//         for (int ii = 0; ii < 12; ii++) {
//             printf("<%x%x>", (0x0f & (received_message[i]>>4)), (0x0f & received_message[i]));
//             i++;
//         }

//         printf("\n");
//     }
//     printf("\n");
// }

