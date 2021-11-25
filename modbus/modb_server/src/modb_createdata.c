#include <stdio.h>
#include "../modbus_lib/include/modbus/modbus.h"
#include <errno.h>
#ifndef INCLUDE_H
#include "../include/include.h"
#endif
// The function writes data to the coils/bits/holding registers/input registers 
// supported by the server. 
// libmodbus has functionality for this, do not attempt to access the server
//  memory map (it's a structure) directly.
// Hint: create an array of unsigned 8 bit values and convert bytes to bits.

// *(mb_mapping->tab_bits+i) = i; 
// modbus_set_bits_from_byte()
void createData(modbus_mapping_t *mb_mapping, uint8_t received_message[]) {
    uint8_t receive[11];
    uint8_t function_code = 0;
    uint8_t starting_address = 0;
    uint16_t output_value = 0;
    function_code = modbus_get_byte_from_bits(received_message, 7, 1);
    starting_address = (modbus_get_byte_from_bits(received_message, 8, 1) << 8) | (modbus_get_byte_from_bits(received_message, 9, 1));
    
    printf(RED"\nFunction code: <%x%x>\n"RESET, (0x0f & function_code >> 4), (0x0f & function_code));
    switch (function_code)
    {
    case MODBUS_FC_WRITE_SINGLE_COIL:
        output_value = (modbus_get_byte_from_bits(received_message, 10, 1) << 8) | (modbus_get_byte_from_bits(received_message, 11, 1));
        output_value = output_value == 0xff00 ? 1 : 0;
        modbus_set_bits_from_byte(mb_mapping->tab_bits, starting_address, output_value);
        if(DEBUG == 1) {
            printf(RED"\nDEBUG STARTS---->\n"RESET);
            for (int i = 0; i < 8; i++) {
                printf("<%d>", *(mb_mapping->tab_bits+i));
            }
            printf(RED"\nDEBUD ENDS----->\n"RESET);
        
        }
        break;
    case MODBUS_FC_WRITE_SINGLE_REGISTER:
        
        break;
    default:
        break;
    }

}