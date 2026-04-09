#include "rle.h"


    void rleCompress(const char* input, char* output) {
    int i = 0, j = 0;

    while (input[i] != '\0') {
        char current = input[i];
        int count = 1;


        while (input[i] == input[i + 1]) {
            count++;
            i++;
        }


        output[j++] = current;

        output[j++] = count + '0';

        i++;
    }

    output[j] = '\0';
}

void rleDecompress(const char* input, char* output) {
    int i = 0, j = 0;

    while (input[i] != '\0') {
        char c = input[i++];
        int count = input[i++] - '0';

        for (int k = 0; k < count; k++) {
            output[j++] = c;
        }
    }

    output[j] = '\0';
}



