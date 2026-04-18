#include "xor.h"
#include "rotacion.h"

// XOR real
void xorCipher(char* text, char key) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = text[i] ^ key;
    }
}

// 🔐 ENCRIPTAR = rotación + XOR
void encrypt(char* text, int shift, char key) {
    rotateLeftText(text, shift);
    xorCipher(text, key);
}

// 🔓 DESENCRIPTAR = XOR + rotación inversa
void decrypt(char* text, int shift, char key) {
    xorCipher(text, key);
    rotateRightText(text, shift);
}