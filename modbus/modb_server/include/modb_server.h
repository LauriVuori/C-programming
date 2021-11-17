#include <stdio.h>
#include <modbus.h>

#define LOCALHOST "127.0.0.1"
#define PORT 8080
#define MAX_CONNECTIONS 1

#define DISCRETE_INPUTS 8 //Read-only
#define COILS 8 //Read-Write
#define INPUT_REGISTERS 0 //Read-only
#define HOLDING_REGISTERS 0 //Read-Write

int initialize(modbus_mapping_t **mb_mapping, modbus_t **modb_ctx, 
                int * r_connectiong, int * socket, char ip_address[], uint16_t port);
void createData();