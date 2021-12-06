#include "../include/include.h"

int main(void) {
    int socket;
    modbus_t *modb_ctx;
    int receive_con;
    int err;
    modbus_mapping_t *mb_mapping;

    #ifdef DEBUG_MAIN
    fprintf(stderr,RED"\nStart, Debug main on\n"RESET);
    #endif

    // modbus tiedonsiirtoa vaadittavien muistien varaaminen ja yhteyden luonti master-laitteelle
    // err = -1 virhetilanteissa
    err = initialize(&mb_mapping, &modb_ctx, &receive_con, &socket, LOCALHOST, PORT);

    // Modbus oma debug, joka tulostaa saapuneet ja lähtevät viestit
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

        // vastaanotetaan viesti
        receive_con = modbus_receive(modb_ctx, query);

        if (receive_con >= 0) {
            // tulostetaan viestin sisältö
            // print_incoming_message on lisätty modbus.h kirjastoon.
            print_incoming_message(query, modb_ctx);
            // vastataan viestiin
            modbus_reply(modb_ctx, query, receive_con, mb_mapping);
            // printataan nykyinnen mb_mapping tietue
            // print_mapping_data on lisätty modbus.h kirjastoon.
            print_mapping_data(mb_mapping);
        }
        else {
            break;
        }        
    }

    printf("Quit the loop: %s\n", modbus_strerror(errno));

    // Vapautetaan mb_mapping varaama tila
    modbus_mapping_free(mb_mapping);

    // Suljetaan socket
    if (close(socket) == -1) {
        printf("\n Error closing socket %s",modbus_strerror(errno));
        modbus_free(modb_ctx);
        return -1;
    } 
    // Vapautetaan modbus_t tietueen varaama tila
    modbus_free(modb_ctx);

    return 0;
}