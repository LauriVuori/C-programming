#include <stdio.h>
#include <string.h>
void read_original_message(char * original_message);
void read_result_message(char * result_message);
void encode_message(char * original, char * coded);
void decode_message(char * original_message, char * resulting_message);
int calculateLen(char * original_message);

int main(void) {

    char original_message[50] = {"TINMHSEPI XLSAAE"};
    char resulting_message[50], coded[50];
    read_original_message(&original_message[0]);

    decode_message(&original_message[0], &resulting_message[0]);
    read_result_message(&resulting_message[0]);
    encode_message(&original_message[0], &coded[0]);
    // read_original_message(&original_message[0]);
    // printf("<%s>", original_message);
    // decode_message(&original_message[0], &resulting_message[0]);
    // printf("<%d>", strlen(original_message));
}

void encode_message(char * original, char * coded) {
    int lenght = 0;
    char intermediate_message[50][5];
    // *original = '\0';
    printf("\nGive string to encode:\n");
    fgets(original, 50, stdin);
    lenght = calculateLen(original);
    while (lenght <= 8) {
        printf("\nToo short message,(min.8) Give string to encode:\n");
        fgets(original, 50, stdin);
        lenght = calculateLen(original);
    }

    original += lenght;
    while ((lenght%4) != 0) {
        *original = 32;
        original++;
        lenght++;
    }
    *original = '\0';
    original -= lenght;
    // kooodaus
}

void decode_message(char * original_message, char * resulting_message) {
    char intermediate_message[50][5];
    int lenght = 0, colum = 0, row = 0;
    lenght = calculateLen(original_message);
    printf("Decoding: \n");
    for (int i = 0; i < lenght; i++) {
        intermediate_message[row][colum] = *original_message;
        printf("%c ", *original_message);
        colum++;

        if (colum == 4) {
            printf("\n");
            intermediate_message[row][colum] = '\0';
            row++;
            colum = 0;
        }
        original_message++;
    }

    for (int i = 0; i < 4; i++) {
        for (int b = 0; b < row; b++) {
            *resulting_message = intermediate_message[b][i];
            resulting_message++;
        }
    }
    *resulting_message = '\0';

}

// void decode_message(char * original_message, char * decoding_message, char * resulting_message) {
//     printf("Decoding: \n");
//     int colums = 0, rows = 0;
//     for (int i = 0; *original_message != '\0'; i++) {
//         if ((i % 4 == 0) && (i > 1)) {
//             printf("\n");
//             rows++;
//             *((decoding_message + rows * 50) + colums + 1) = '\0';
//             colums = 0;
//         }
//         *((decoding_message + rows * 50) + colums) = *original_message;
//         printf("%c ", *((decoding_message + rows * 50) + colums));
//         original_message++;
//         colums++;
//     }

//     for (int i = 0; i < rows; i++) {
//         for (int b = 0; *decoding_message != '\0'; b++) {
//             *resulting_message = *(decoding_message + i * 50 + b );
//             resulting_message++;
//         }
//     }
// }

// Calculate original messages lenght
int calculateLen(char * result_message) {
    int lenght = 0;
    for (int i = 0; *result_message != '\0'; i++) {
        lenght++;
        result_message++;
    }
    return lenght;
}

//read original message
void read_original_message(char *original_message) {
    printf("In original message the where 16 characters\nThe original message was:\n");
    for (int i = 0; *original_message != '\0'; i++) {
        printf("%c", *original_message);
        original_message++;
    }
    printf("\n");
}

// read result
void read_result_message(char * result_message) {
    printf("\nResult is:\n");
    int lenght = 0;
    lenght = calculateLen(result_message);
    for (int i = 0; i < lenght; i++) {
        printf("%c", *result_message);
        result_message++;
    }
}