#include "../modbus_lib/include/modbus/modbus.h"

#define LOCALHOST "127.0.0.1"
#define PORT 8080
#define MAX_CONNECTIONS 1

/*modbus debugs*/
#define MODBUS_DATA_DEBUG 1
#define DEBUG_MAIN 1
#define DEBUG_MODBUS_MAPPING 1

/*modbus functions end*/


#define DISCRETE_INPUTS 8 //Read-only
#define COILS 8 //Read-Write
#define INPUT_REGISTERS 8 //Read-only
#define HOLDING_REGISTERS 8 //Read-Write

int initialize(modbus_mapping_t **mb_mapping, modbus_t **modb_ctx, 
                int * r_connectiong, int * socket, char ip_address[], uint16_t port);
void incoming(uint8_t received_message[], modbus_t * context_ptr, int * receive_con);
void createData(modbus_mapping_t *mb_mapping);