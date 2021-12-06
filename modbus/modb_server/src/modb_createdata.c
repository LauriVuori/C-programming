#ifndef INCLUDE_H
#define INCLUDE_H
#include "../include/include.h"
#endif

//     uint8_t *tab_bits; coils
//     uint8_t *tab_input_bits; Discrete input
//     uint16_t *tab_input_registers; input registers
//     uint16_t *tab_registers; holding registers

// Luodaan "dummy" dataa tietueeseen
void createData(modbus_mapping_t *mb_mapping) {
    // Input registers, asetetaan 0,1,2,3... taulukon loppuun saakka.
    for (int i = 0; i < mb_mapping->nb_input_registers; i++) {
        *(mb_mapping->tab_input_registers+i) = i;
    }
    // Discrete inputs, joka toinen 1 ja 0... taulukon loppuun saakka.
    for (int i = 0; i < mb_mapping->nb_input_bits; i++) {
        // Short Hand If...Else (Ternary Operator)
        *(mb_mapping->tab_input_bits+i) = i % 2 == 0 ? 1 : 0;
    }
}