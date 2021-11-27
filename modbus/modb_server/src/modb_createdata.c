#ifndef INCLUDE_H
#define INCLUDE_H
#include "../include/include.h"
#endif
// The function writes data to the coils/bits/holding registers/input registers 
// supported by the server. 
// libmodbus has functionality for this, do not attempt to access the server
//  memory map (it's a structure) directly.
// Hint: create an array of unsigned 8 bit values and convert bytes to bits.

// *(mb_mapping->tab_bits+i) = i; 
// modbus_set_bits_from_byte()
// #define DISCRETE_INPUTS 8 //Read-only
// #define COILS 8 //Read-Write
// #define INPUT_REGISTERS 8 //Read-only
// #define HOLDING_REGISTERS 8 //Read-Write
//     uint8_t *tab_bits; coils
//     uint8_t *tab_input_bits; Discrete input
//     uint16_t *tab_input_registers; input registers
//     uint16_t *tab_registers; holding registers
void createData(modbus_mapping_t *mb_mapping) {
    for (int i = 0; i < mb_mapping->nb_input_registers; i++) {
        *(mb_mapping->tab_input_registers+i) = i;
    }
    for (int i = 0; i < mb_mapping->nb_input_bits; i++) {
        *(mb_mapping->tab_input_bits+i) = i % 2 == 0 ? 1 : 0;
    }
}