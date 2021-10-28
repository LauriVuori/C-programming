#include <stdio.h>
#include <sys/socket.h>

int main(void) {
    // SOCK_STREAM TCP
    // SOCK_DGRAM UDP
    int udp_socket = socket(AF_INET, SOCK_DGRAM, 0);
    // int udp_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (udp_socket < 0) {
        printf("Error creating socket, socket not created\n");
        return 0;
    }
    printf("UDP socket is ready\n");

    //... code to use the socket
    close(udp_socket);
    printf("Socket closed\n");
}