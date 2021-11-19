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
void incoming(uint8_t message[], modbus_t * context_ptr, int * receive_con);
int main() {
    int socket;
    modbus_t *modb_ctx;
    int receive_con;
    int err;
    modbus_mapping_t *mb_mapping;
    
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
        uint8_t query[MODBUS_TCP_MAX_ADU_LENGTH];
        incoming(query, modb_ctx, &receive_con);
        // int a = modbus_receive(modb_ctx, query);
        if (receive_con >= 0) {
            modbus_reply(modb_ctx, query, receive_con, mb_mapping);
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
// Transaction Id	    Protocol	    Length	    Unit Address	    Message
//     2 Bytes	          2 Bytes	       2 Bytes	    1 Byte	        N Bytes
void incoming(uint8_t received_message[], modbus_t * context_ptr, int * receive_con) {
    uint16_t transaction_id = 0;
    uint16_t protocol = 0;
    uint16_t lenght = 0;
    uint8_t unit_address = 0;
    uint8_t function_code = 0;
    uint16_t starting_address = 0;
    uint16_t quantity_of_registers = 0;
    uint16_t output_value = 0;
    uint16_t byte_count = 0;
    uint8_t mb_message[MODBUS_MAX_PDU_LENGTH];

    printf("INCOMING--->\n");
    *receive_con = modbus_receive(context_ptr, received_message);   //Question 9) What does modbus_receive() do?
    printf("\n");
    if (*receive_con >= 0) {
        /************************************ message frame end ******************/
        transaction_id = (modbus_get_byte_from_bits(received_message, 0, 1) << 8) | (modbus_get_byte_from_bits(received_message, 1, 1));
        printf(GRN"Transaction id: <%x%x%x%x>\n"RESET, (0x0f & (transaction_id >> 12)), (0x0f & transaction_id >> 8), (0x0f & transaction_id >> 4), (0x0f & transaction_id));
        protocol = (modbus_get_byte_from_bits(received_message, 2, 1) << 8) | (modbus_get_byte_from_bits(received_message, 3, 1));
        printf(GRN"Protocol: <%x%x%x%x>\n"RESET, (0x0f & (protocol >> 12)), (0x0f & protocol >> 8), (0x0f & protocol >> 4), (0x0f & protocol));
        lenght = (modbus_get_byte_from_bits(received_message, 4, 1) << 8) | (modbus_get_byte_from_bits(received_message, 5, 1));
        printf(GRN"Msg lenght: <%x%x%x%x>\n"RESET, (0x0f & (lenght >> 12)), (0x0f & lenght >> 8), (0x0f & lenght >> 4), (0x0f & lenght));
        unit_address = modbus_get_byte_from_bits(received_message, 6, 1);
        printf(GRN"Unit address: <%x%x>\n"RESET, (0x0f & unit_address >> 4), (0x0f & unit_address));
        function_code = modbus_get_byte_from_bits(received_message, 7, 1);
        printf(MAG"Function code: <%x%x>\n"RESET, (0x0f & function_code >> 4), (0x0f & function_code));
        // starting address start from 8
        if (function_code == MODBUS_FC_READ_COILS) {
            printf("READ COILS:\n");
            starting_address = (modbus_get_byte_from_bits(received_message, 8, 1) << 8) | (modbus_get_byte_from_bits(received_message, 9, 1));
            printf(GRN"Transaction id: <%x%x%x%x>\n"RESET, (0x0f & (starting_address >> 12)), (0x0f & starting_address >> 8), (0x0f & starting_address >> 4), (0x0f & starting_address));
            quantity_of_registers = (modbus_get_byte_from_bits(received_message, 10, 1) << 8) | (modbus_get_byte_from_bits(received_message, 11, 1));
            printf(GRN"quantity_of_registers: <%x%x%x%x>\n"RESET, (0x0f & (quantity_of_registers >> 12)), (0x0f & quantity_of_registers >> 8), (0x0f & quantity_of_registers >> 4), (0x0f & quantity_of_registers));

        }
        else if (function_code == MODBUS_FC_READ_DISCRETE_INPUTS) {
            printf("\nREAD DISCRETE INPUTS\n");
            starting_address = (modbus_get_byte_from_bits(received_message, 8, 1) << 8) | (modbus_get_byte_from_bits(received_message, 9, 1));
            printf(GRN"Starting address: <%x%x%x%x>\n"RESET, (0x0f & (starting_address >> 12)), (0x0f & starting_address >> 8), (0x0f & starting_address >> 4), (0x0f & starting_address));
            quantity_of_registers = (modbus_get_byte_from_bits(received_message, 10, 1) << 8) | (modbus_get_byte_from_bits(received_message, 11, 1));
            printf(GRN"quantity_of_registers: <%x%x%x%x>\n"RESET, (0x0f & (quantity_of_registers >> 12)), (0x0f & quantity_of_registers >> 8), (0x0f & quantity_of_registers >> 4), (0x0f & quantity_of_registers));
        }
        else if (function_code == MODBUS_FC_READ_HOLDING_REGISTERS) {
            printf("\nREAD HOLDING REGISTERS\n");
            starting_address = (modbus_get_byte_from_bits(received_message, 8, 1) << 8) | (modbus_get_byte_from_bits(received_message, 9, 1));
            printf(GRN"Starting address: <%x%x%x%x>\n"RESET, (0x0f & (starting_address >> 12)), (0x0f & starting_address >> 8), (0x0f & starting_address >> 4), (0x0f & starting_address));
            quantity_of_registers = (modbus_get_byte_from_bits(received_message, 10, 1) << 8) | (modbus_get_byte_from_bits(received_message, 11, 1));
            printf(GRN"quantity_of_registers: <%x%x%x%x>\n"RESET, (0x0f & (quantity_of_registers >> 12)), (0x0f & quantity_of_registers >> 8), (0x0f & quantity_of_registers >> 4), (0x0f & quantity_of_registers));
        }
        else if (function_code == MODBUS_FC_READ_INPUT_REGISTERS) {
            printf("\n READ INPUT REGISTERS\n");
            starting_address = (modbus_get_byte_from_bits(received_message, 8, 1) << 8) | (modbus_get_byte_from_bits(received_message, 9, 1));
            printf(GRN"Starting address: <%x%x%x%x>\n"RESET, (0x0f & (starting_address >> 12)), (0x0f & starting_address >> 8), (0x0f & starting_address >> 4), (0x0f & starting_address));
            quantity_of_registers = (modbus_get_byte_from_bits(received_message, 10, 1) << 8) | (modbus_get_byte_from_bits(received_message, 11, 1));
            printf(GRN"quantity_of_registers: <%x%x%x%x>\n"RESET, (0x0f & (quantity_of_registers >> 12)), (0x0f & quantity_of_registers >> 8), (0x0f & quantity_of_registers >> 4), (0x0f & quantity_of_registers));
        }
        else if (function_code == MODBUS_FC_WRITE_SINGLE_COIL) {
            printf("\nWRITE SINGLE COIL\n");
            starting_address = (modbus_get_byte_from_bits(received_message, 8, 1) << 8) | (modbus_get_byte_from_bits(received_message, 9, 1));
            printf(GRN"Starting address: <%x%x%x%x>\n"RESET, (0x0f & (starting_address >> 12)), (0x0f & starting_address >> 8), (0x0f & starting_address >> 4), (0x0f & starting_address));
            output_value = (modbus_get_byte_from_bits(received_message, 10, 1) << 8) | (modbus_get_byte_from_bits(received_message, 11, 1));
            printf(GRN"output_value: <%x%x%x%x>\n"RESET, (0x0f & (output_value >> 12)), (0x0f & output_value >> 8), (0x0f & output_value >> 4), (0x0f & output_value));
        }
        else if (function_code == MODBUS_FC_WRITE_SINGLE_REGISTER) {
            printf("\nWRITE SINGLE REGISTERS\n");
            starting_address = (modbus_get_byte_from_bits(received_message, 8, 1) << 8) | (modbus_get_byte_from_bits(received_message, 9, 1));
            printf(GRN"Starting address: <%x%x%x%x>\n"RESET, (0x0f & (starting_address >> 12)), (0x0f & starting_address >> 8), (0x0f & starting_address >> 4), (0x0f & starting_address));
            output_value = (modbus_get_byte_from_bits(received_message, 10, 1) << 8) | (modbus_get_byte_from_bits(received_message, 11, 1));
            printf(GRN"output_value: <%x%x%x%x>\n"RESET, (0x0f & (output_value >> 12)), (0x0f & output_value >> 8), (0x0f & output_value >> 4), (0x0f & output_value));          
        }
        else if (function_code == MODBUS_FC_WRITE_MULTIPLE_COILS) {
            printf("\nWRITE MULTIPLE COILS\n");
            starting_address = (modbus_get_byte_from_bits(received_message, 8, 1) << 8) | (modbus_get_byte_from_bits(received_message, 9, 1));
            printf(GRN"Starting address: <%x%x%x%x>\n"RESET, (0x0f & (starting_address >> 12)), (0x0f & starting_address >> 8), (0x0f & starting_address >> 4), (0x0f & starting_address));
            quantity_of_registers = (modbus_get_byte_from_bits(received_message, 10, 1) << 8) | (modbus_get_byte_from_bits(received_message, 11, 1));
            printf(GRN"quantity_of_registers: <%x%x%x%x>\n"RESET, (0x0f & (quantity_of_registers >> 12)), (0x0f & quantity_of_registers >> 8), (0x0f & quantity_of_registers >> 4), (0x0f & quantity_of_registers));
        }
        else if (function_code == MODBUS_FC_WRITE_MULTIPLE_REGISTERS) {
            printf("\nWRITE MULTIPLE REGISTERS\n");

        }
        
        /************************************ message frame end ******************/
        // for (int i = 0; i < lenght-1; i++) {
        //     mb_message[i] = received_message[7+i];
        //     printf(YEL"<%x>"RESET,received_message[7+i]);
        // }
    }
    printf("<------INCOMING\n");
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

