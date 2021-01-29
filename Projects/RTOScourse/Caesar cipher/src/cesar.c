#include <stdio.h>
#include <string.h>
#include <decode.h>


int main(void) {
    char original_message[50] = {"TINMHSEPI XLSAAE"};
    char resulting_message[50], coded[50];
    read_original_message(&original_message[0]);
    decode_message(&original_message[0], &resulting_message[0]);
    read_result_message(&resulting_message[0]);
    encode_message(&original_message[0], &coded[0]);
    decode_message(&coded[0], &resulting_message[0]);
    read_result_message(&resulting_message[0]);
}