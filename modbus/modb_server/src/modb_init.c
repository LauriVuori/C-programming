#ifndef INCLUDE_H
#define INCLUDE_H
#include "../include/include.h"
#endif
// Luodaan modbus_t struktuuri
// mb_mapping tietue
// "dummy" dataa "read-only" taulukoihin
// luodaan socket ja kuunnellaan tulevia yhteyksiä
// Hyväksytään tuleva yhteys
// Virhetilanteissa palautetaan ERROR
int initialize(modbus_mapping_t **mb_mapping, modbus_t **modb_ctx, 
                int * r_connectiong, int * socket, char ip_address[], uint16_t port) {

    // The modbus_new_tcp() function shall allocate and initialize a modbus_t structure to communicate with a Modbus TCP/IPv4 server.
    *modb_ctx = modbus_new_tcp(ip_address, port);

    if (*modb_ctx == NULL) {
        printf("Unable to allocate libmodbus context,%s\n", modbus_strerror(errno));
        return ERROR;
    }
    // voidaan käyttää alla olevaa funktiota, jolloin aloitus osoite on 0
    // *mb_mapping = modbus_mapping_new(COILS, DISCRETE_INPUTS,
    //                             INPUT_REGISTERS, HOLDING_REGISTERS);

    // modbus_mapping_new_start_address funktiota käyttämällä annetaan myös aloitus osoite.
    *mb_mapping = modbus_mapping_new_start_address(COILS_START, COILS, DISCRETE_START, DISCRETE_INPUTS, HOLDING_REG_START, HOLDING_REGISTERS, INPUT_REGI_START, INPUT_REGISTERS);

    if (*mb_mapping == NULL) {
        fprintf(stderr, "Failed to allecate mapping %s\n", modbus_strerror(errno));
        return ERROR;
    }
    // luodaan "dummy" dataa modbus "read-only" tietueen osiin, jolloin voidaan modmasterilla lukea niitä.
    createData(*mb_mapping);

    // Luo socketin ja kuuntelee tulevia yhteyksiä
    *socket = modbus_tcp_listen(*modb_ctx, MAX_CONNECTIONS);

    if(*socket == ERROR) {
        printf("Unable to  %s", modbus_strerror(errno));
        modbus_free(*modb_ctx);
        return ERROR;
    }
    printf(YEL"\nListening connectins...\n"RESET);

    // Hyväksytään uusi tcp yhteys
    *r_connectiong = modbus_tcp_accept(*modb_ctx, socket);

    if (*r_connectiong == ERROR) {
        printf("Could not accept new connection: %s\n", modbus_strerror(errno));
        close(*socket);
        modbus_free(*modb_ctx);
        return ERROR;
    }

    return OK;
}

