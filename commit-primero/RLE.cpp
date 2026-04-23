#include "rle.h"

void rleCompress(const char* input, char* output) {
    if (!input || !output)
        throw "RLE: puntero nulo";

    int i = 0, j = 0;

    while (input[i] != '\0') {
        char current = input[i];
        int count = 1;

        while (input[i + count] == current) {
            count++;
        }

        if (count > 9)
            throw "RLE: max 9 repeticiones";

        output[j++] = current;
        output[j++] = count + '0';

        i += count;
    }

    output[j] = '\0';
}

void rleDecompress(const char* input, char* output) {
    if (!input || !output)
        throw "RLE: puntero nulo";

    int i = 0, j = 0;

    while (input[i] != '\0') {
        char c = input[i++];
        int count = input[i++] - '0';

        if (count <= 0)
            throw "RLE: error descompresion";

        for (int k = 0; k < count; k++) {
            output[j++] = c;
        }
    }

    output[j] = '\0';
}