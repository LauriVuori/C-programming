#include "../modbus_lib/include/modbus/modbus.h"

#define LOCALHOST "127.0.0.1"
#define PORT 8080
#define MAX_CONNECTIONS 1

/*modbus debugs*/
#define MODBUS_DATA_DEBUG 0
#define DEBUG_MAIN 1
/*modbus functions end*/



#define COILS 8 //Read-Write
#define COILS_START 1
#define DISCRETE_INPUTS 8 //Read-only
#define DISCRETE_START 2
#define INPUT_REGISTERS 8 //Read-only
#define INPUT_REGI_START 3
#define HOLDING_REGISTERS 8 //Read-Write
#define HOLDING_REG_START 4


int initialize(modbus_mapping_t **mb_mapping, modbus_t **modb_ctx, 
                int * r_connectiong, int * socket, char ip_address[], uint16_t port);
// Modbuslib kirjastoon lisätty funktiot, mb_mapping tietueen ja vastaanotettavien viestien tutkimiseen, jonka vuoksi incoming on tyhjä funktio
void incoming(uint8_t received_message[], modbus_t * context_ptr);
void createData(modbus_mapping_t *mb_mapping);