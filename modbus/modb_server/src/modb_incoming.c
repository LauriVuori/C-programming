#include <stdio.h>
#include <errno.h>
#ifndef INCLUDE_H
#include "../include/include.h"
#endif


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
    uint8_t mb_message[MODBUS_MAX_PDU_LENGTH];
    uint8_t output_bytes[100];
    uint8_t header_len = 0;
    uint8_t byte_count = 0;
    header_len = modbus_get_header_length(context_ptr);
    *receive_con = modbus_receive(context_ptr, received_message);   //Question 9) What does modbus_receive() do?
    if (*receive_con >= 0) {
        printf(BLU"MESSAGE FRAME:\n"RESET);
        printf(GRN"Header Lenght: <%d>\n", header_len);
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
            printf(YEL"READ COILS:\n"RESET);
            starting_address = (modbus_get_byte_from_bits(received_message, 8, 1) << 8) | (modbus_get_byte_from_bits(received_message, 9, 1));
            printf(GRN"Transaction id: <%x%x%x%x>\n"RESET, (0x0f & (starting_address >> 12)), (0x0f & starting_address >> 8), (0x0f & starting_address >> 4), (0x0f & starting_address));
            quantity_of_registers = (modbus_get_byte_from_bits(received_message, 10, 1) << 8) | (modbus_get_byte_from_bits(received_message, 11, 1));
            printf(GRN"quantity_of_registers: <%x%x%x%x>\n"RESET, (0x0f & (quantity_of_registers >> 12)), (0x0f & quantity_of_registers >> 8), (0x0f & quantity_of_registers >> 4), (0x0f & quantity_of_registers));
        }
        else if (function_code == MODBUS_FC_READ_DISCRETE_INPUTS) {
            printf(YEL"READ DISCRETE INPUTS\n"RESET);
            starting_address = (modbus_get_byte_from_bits(received_message, 8, 1) << 8) | (modbus_get_byte_from_bits(received_message, 9, 1));
            printf(GRN"Starting address: <%x%x%x%x>\n"RESET, (0x0f & (starting_address >> 12)), (0x0f & starting_address >> 8), (0x0f & starting_address >> 4), (0x0f & starting_address));
            quantity_of_registers = (modbus_get_byte_from_bits(received_message, 10, 1) << 8) | (modbus_get_byte_from_bits(received_message, 11, 1));
            printf(GRN"quantity_of_registers: <%x%x%x%x>\n"RESET, (0x0f & (quantity_of_registers >> 12)), (0x0f & quantity_of_registers >> 8), (0x0f & quantity_of_registers >> 4), (0x0f & quantity_of_registers));
        }
        else if (function_code == MODBUS_FC_READ_HOLDING_REGISTERS) {
            printf(YEL"READ HOLDING REGISTERS\n"RESET);
            starting_address = (modbus_get_byte_from_bits(received_message, 8, 1) << 8) | (modbus_get_byte_from_bits(received_message, 9, 1));
            printf(GRN"Starting address: <%x%x%x%x>\n"RESET, (0x0f & (starting_address >> 12)), (0x0f & starting_address >> 8), (0x0f & starting_address >> 4), (0x0f & starting_address));
            quantity_of_registers = (modbus_get_byte_from_bits(received_message, 10, 1) << 8) | (modbus_get_byte_from_bits(received_message, 11, 1));
            printf(GRN"quantity_of_registers: <%x%x%x%x>\n"RESET, (0x0f & (quantity_of_registers >> 12)), (0x0f & quantity_of_registers >> 8), (0x0f & quantity_of_registers >> 4), (0x0f & quantity_of_registers));
        }
        else if (function_code == MODBUS_FC_READ_INPUT_REGISTERS) {
            printf(YEL"READ INPUT REGISTERS\n"RESET);
            starting_address = (modbus_get_byte_from_bits(received_message, 8, 1) << 8) | (modbus_get_byte_from_bits(received_message, 9, 1));
            printf(GRN"Starting address: <%x%x%x%x>\n"RESET, (0x0f & (starting_address >> 12)), (0x0f & starting_address >> 8), (0x0f & starting_address >> 4), (0x0f & starting_address));
            quantity_of_registers = (modbus_get_byte_from_bits(received_message, 10, 1) << 8) | (modbus_get_byte_from_bits(received_message, 11, 1));
            printf(GRN"quantity_of_registers: <%x%x%x%x>\n"RESET, (0x0f & (quantity_of_registers >> 12)), (0x0f & quantity_of_registers >> 8), (0x0f & quantity_of_registers >> 4), (0x0f & quantity_of_registers));
        }
        else if (function_code == MODBUS_FC_WRITE_SINGLE_COIL) {
            printf(YEL"WRITE SINGLE COIL\n"RESET);
            starting_address = (modbus_get_byte_from_bits(received_message, 8, 1) << 8) | (modbus_get_byte_from_bits(received_message, 9, 1));
            printf(GRN"Starting address: <%x%x%x%x>\n"RESET, (0x0f & (starting_address >> 12)), (0x0f & starting_address >> 8), (0x0f & starting_address >> 4), (0x0f & starting_address));
            output_value = (modbus_get_byte_from_bits(received_message, 10, 1) << 8) | (modbus_get_byte_from_bits(received_message, 11, 1));
            printf(GRN"output_value: <%x%x%x%x>\n"RESET, (0x0f & (output_value >> 12)), (0x0f & output_value >> 8), (0x0f & output_value >> 4), (0x0f & output_value));
        }
        else if (function_code == MODBUS_FC_WRITE_SINGLE_REGISTER) {
            printf(YEL"WRITE SINGLE REGISTERS\n"RESET);
            starting_address = (modbus_get_byte_from_bits(received_message, 8, 1) << 8) | (modbus_get_byte_from_bits(received_message, 9, 1));
            printf(GRN"Starting address: <%x%x%x%x>\n"RESET, (0x0f & (starting_address >> 12)), (0x0f & starting_address >> 8), (0x0f & starting_address >> 4), (0x0f & starting_address));
            output_value = (modbus_get_byte_from_bits(received_message, 10, 1) << 8) | (modbus_get_byte_from_bits(received_message, 11, 1));
            printf(GRN"output_value: <%x%x%x%x>\n"RESET, (0x0f & (output_value >> 12)), (0x0f & output_value >> 8), (0x0f & output_value >> 4), (0x0f & output_value));          
        }
        else if (function_code == MODBUS_FC_WRITE_MULTIPLE_COILS) {
            printf(YEL"WRITE MULTIPLE COILS\n"RESET);
            starting_address = (modbus_get_byte_from_bits(received_message, 8, 1) << 8) | (modbus_get_byte_from_bits(received_message, 9, 1));
            printf(GRN"Starting address: <%x%x%x%x>\n"RESET, (0x0f & (starting_address >> 12)), (0x0f & starting_address >> 8), (0x0f & starting_address >> 4), (0x0f & starting_address));
            quantity_of_registers = (modbus_get_byte_from_bits(received_message, 10, 1) << 8) | (modbus_get_byte_from_bits(received_message, 11, 1));
            printf(GRN"quantity_of_registers: <%x%x%x%x>\n"RESET, (0x0f & (quantity_of_registers >> 12)), (0x0f & quantity_of_registers >> 8), (0x0f & quantity_of_registers >> 4), (0x0f & quantity_of_registers));
            byte_count = modbus_get_byte_from_bits(received_message, 12, 1);
            printf(GRN"BYTE count: <%x%x>\n"RESET, (0x0f & byte_count >> 4), (0x0f & byte_count));
            printf(GRN"Output values:"RESET);
            for (int i = 0; i < byte_count; i++) {
                output_bytes[i]= modbus_get_byte_from_bits(received_message, 13+i, 1);
                printf(GRN"<%x%x>"RESET, (0x0f & output_bytes[i] >> 4), (0x0f & output_bytes[i]));
            }
            printf("\n");
        }
        else if (function_code == MODBUS_FC_WRITE_MULTIPLE_REGISTERS) {
            printf(YEL"WRITE MULTIPLE REGISTERS\n"RESET);
            starting_address = (modbus_get_byte_from_bits(received_message, 8, 1) << 8) | (modbus_get_byte_from_bits(received_message, 9, 1));
            printf(GRN"Starting address: <%x%x%x%x>\n"RESET, (0x0f & (starting_address >> 12)), (0x0f & starting_address >> 8), (0x0f & starting_address >> 4), (0x0f & starting_address));
            quantity_of_registers = (modbus_get_byte_from_bits(received_message, 10, 1) << 8) | (modbus_get_byte_from_bits(received_message, 11, 1));
            printf(GRN"quantity_of_registers: <%x%x%x%x>\n"RESET, (0x0f & (quantity_of_registers >> 12)), (0x0f & quantity_of_registers >> 8), (0x0f & quantity_of_registers >> 4), (0x0f & quantity_of_registers));
            byte_count = modbus_get_byte_from_bits(received_message, 12, 1);
            printf(GRN"BYTE count: <%x%x>\n"RESET, (0x0f & byte_count >> 4), (0x0f & byte_count));
            //output bytes start from 13
            printf(GRN"Output values:"RESET); 
            for (int i = 0; i <= byte_count; i++) {
                output_bytes[i]= modbus_get_byte_from_bits(received_message, 13+i, 1);
                printf(GRN"<%x%x>"RESET, (0x0f & output_bytes[i] >> 4), (0x0f & output_bytes[i]));
            }
            printf("\n");
             
        }
        printf(BLU"MESSAGE FRAME ENDS\n"RESET);
    }
}