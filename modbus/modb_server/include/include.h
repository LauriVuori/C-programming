#include <errno.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

// halutut header tiedostot lisätään tähän
#ifndef MODB_SERVER_H
#define MODB_SERVER_H
#include "modb_server.h"
#endif



#define ERROR -1
#define OK 0
#define CREATEDATA 1

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"