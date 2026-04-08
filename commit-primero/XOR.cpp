#include "xor.h"

void xorCipher(char* text, char key) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = text[i] ^ key;
    }
}
