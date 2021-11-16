/* If manpages are missing: look at */
/* https://github.com/stephane/libmodbus/tree/master/doc */
/* Simplest possible tcp modbus server: it listens on incoming traffic */
/* on a tcp port and replies with the same (?) data */
/* Modified from the libmodbus examples */
// http://manpages.ubuntu.com/manpages/precise/man7/libmodbus.7.html
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <modbus.h>

int main() {

    int socket;
    modbus_t *ctx; // Question 1) //modbus_t is a datatype, where is it defined? == modbus.h
    int rc;
    modbus_mapping_t *mb_mapping; //modbus_mapping_t is a datatype, where is it defined? == modbus.h
    
    printf("\nStart\n");
    // alkuperäinen port 502, ip 127.000.000.001
    // The modbus_new_tcp() function shall allocate 
    // and initialize a modbus_t structure to communicate with a Modbus TCP/IPv4 server.
    ctx = modbus_new_tcp("127.000.000.001", 8080); 
	
	//Question 2) From where do you find the IP address and portnumber to use? 
	
    if (ctx == NULL) {   //Question 3) What happens here?, == jos ctx ei saa (muuten null pointer) osoitetta, ei ole luote tcp yhteyttä
    
        printf("Unable to allocate libmodbus context,%s\n", modbus_strerror(errno));
        return -1;
    }
    
    printf("\nAllocating libmodbus context ok\n");

    socket = modbus_tcp_listen(ctx, 1); // luo socketin ja kuuntelee tulevia yhteyksiä. Jos Luominen ei onnistu. socket arvo -1
                                        // Question 4) What does the function do? The question marks in the printf() function below are related to this 
    
    if(socket ==-1) {
        printf("Unable to  %s", modbus_strerror(errno));
        modbus_free(ctx);  //Question 5, why is modbus_free() used here?, vapauttaa allokoidun modbus_t structuurin
        return -1;
    }
    printf("\n socket created ok\n");

    // The modbus_tcp_accept() function shall extract the first connection on the queue 
    // of pending connections, create a new socket and store it in 
    // libmodbus context given in argument. If available, accept4() with SOCK_CLOEXEC 
    // will be called instead of accept().
    rc = modbus_tcp_accept(ctx, &socket); //Question 5) What does modbus_tcp_accept() do? The question marks in the printf() function below are related to this
    
    if (rc == -1) {
        printf("Could not accept new connection: %s\n", modbus_strerror(errno));
        close(socket);  //Question 6) close sulkee socketin
        modbus_free(ctx);
        return -1;
    }
    printf("\n Connection creating complete\n");

    // The modbus_mapping_new() function shall allocate four arrays to 
    // store bits, input bits, registers and inputs registers. 
    // The pointers are stored in modbus_mapping_t structure. All values of the arrays are initialized to zero.
    mb_mapping = modbus_mapping_new(MODBUS_MAX_READ_BITS, 0,
                                    MODBUS_MAX_READ_REGISTERS, 0);
    //Question 7) What does modbus_mapping() do ? What are the feature which are set to zero? 
    

    if (mb_mapping == NULL) {
        fprintf(stderr, "Failed to allecate mapping %s\n", modbus_strerror(errno));
        close(socket);
        modbus_free(ctx);
        return -1;
    }

    printf("\n Listening\n");
    for(;;) {
        printf("\n loop\n");
        uint8_t query[MODBUS_TCP_MAX_ADU_LENGTH]; //Question 8) What is created here and what is it used for?

        rc = modbus_receive(ctx, query);   //Question 9) What does modbus_receive() do?
        if (rc >= 0) {
            modbus_reply(ctx, query, rc, mb_mapping);  //Question 10) How do modbus_reply() and modbus_receive() cooperate here?
            printf("REPLY\n");
            for (int i = 0; i < MODBUS_TCP_MAX_ADU_LENGTH; i++) {
                for (int ii = 0; ii < 12; ii++) {
                    printf("<%x%x>", (0x0f & (query[i]>>4)), (0x0f & query[i]));
                    i++;
                }

                printf("\n");
            }
            printf("\n");
        } 
        else {
            /* Connection closed by the client or server */
            break;
        }
    }

    printf("Quit the loop: %s\n", modbus_strerror(errno));

    modbus_mapping_free(mb_mapping);

    if (close(socket) == -1) {
        printf("\n Error closing socket %s",modbus_strerror(errno));
    } 

    modbus_free(ctx);


    return 0;
}//main
