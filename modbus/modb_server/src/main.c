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

#include "../include/include.h"

// void print_mapping_data(modbus_mapping_t *mb_mapping);
void testing(modbus_t *ctx, const uint8_t *req,
                 int req_length, modbus_mapping_t *mb_mapping);


int main(void) {
    int socket;
    modbus_t *modb_ctx;
    int receive_con;
    int err;
    modbus_mapping_t *mb_mapping;

    #ifdef DEBUG_MAIN
    fprintf(stderr,RED"\nStart, Debug main on\n"RESET);
    #endif

    err = initialize(&mb_mapping, &modb_ctx, &receive_con, &socket, LOCALHOST, PORT);

    if (modbus_set_debug(modb_ctx, MODBUS_DATA_DEBUG) == -1) {
        printf("error setting debug");
        return -1;
    }
    if (err == ERROR) {
        printf(RED"Init failed, program shuts down\n"RESET);
        return -1;
    }
    printf(GRN"\nConnection established\n"RESET);
    for(;;) {
        printf(GRN"\nWaiting for incoming message...\n"RESET);
        uint8_t query[MODBUS_TCP_MAX_ADU_LENGTH];
        incoming(query, modb_ctx, &receive_con);
        
        if (receive_con >= 0) {
            modbus_reply(modb_ctx, query, receive_con, mb_mapping);
            print_mapping_data(mb_mapping);
        }
        else {
            break;
        }        
    }

    printf("Quit the loop: %s\n", modbus_strerror(errno));
    modbus_mapping_free(mb_mapping);

    if (close(socket) == -1) {
        printf("\n Error closing socket %s",modbus_strerror(errno));
        modbus_free(modb_ctx);
        return -1;
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
//     uint8_t *tab_bits; coils
//     uint8_t *tab_input_bits; Discrete input
//     uint16_t *tab_input_registers; input registers
//     uint16_t *tab_registers; holding registers
// } modbus_mapping_t;
// void print_mapping_data(modbus_mapping_t *mb_mapping) {
//     int counter = 1;
//     printf(RED"Coils:\n"RESET);
//     printf(RED"Address range: %d-%d\n"RESET,
//     mb_mapping->start_bits+1, 
//     mb_mapping->start_bits + mb_mapping->nb_bits+1);

//     for (int i = 0; i < mb_mapping->nb_bits; i++) {
//         printf(GRN"<%d>"RESET, *(mb_mapping->tab_bits+i));
//         if (counter % 8 == 0) {
//             printf("\n");
//         }
//         counter++;
//     }
//     counter = 1;
//     printf("\n");
//     printf(RED"Discretes Input:\n"RESET);
//     printf(RED"Address range: %d-%d\n"RESET, 
//     mb_mapping->start_input_bits+1, 
//     mb_mapping->start_input_bits + mb_mapping->nb_input_bits+1);
//     for (int i = 0; i < mb_mapping->nb_input_bits; i++) {
//         printf(GRN"<%d>"RESET, *(mb_mapping->tab_input_bits+i));
//         if (counter % 8 == 0) {
//             printf("\n");
//         }
//         counter++;
//     }
//     counter = 1;
//     printf("\n");

//     printf(RED"Input Registers:\n"RESET);
//     printf(RED"Address range: %d-%d\n"RESET, 
//     mb_mapping->start_input_registers+1, 
//     mb_mapping->start_input_registers + mb_mapping->nb_input_registers+1);
//     for (int i = 0; i < mb_mapping->nb_input_registers; i++) {
//         printf(GRN"<%d>"RESET, *(mb_mapping->tab_input_registers+i));
//         if (counter % 8 == 0) {
//             printf("\n");
//         }
//         counter++;
//     }
//     counter = 1;
//     printf("\n");
//     printf(RED"Holding registers:\n"RESET);
//     printf(RED"Address range: %d-%d\n"RESET, 
//     mb_mapping->start_registers+1, 
//     mb_mapping->start_registers + mb_mapping->nb_registers+1);
//     for (int i = 0; i < mb_mapping->nb_registers; i++) {
//         printf(GRN"<%d>"RESET, *(mb_mapping->tab_registers+i));
//         if (counter % 8 == 0) {
//             printf("\n");
//         }
//         counter++;
//     }
//     printf("\n");
    
// }
