#include "xor.h"
#include "rotacion.h"

void xorC(char* text, char key) {
    for (int i = 0; text[i] != '\0'; i++)
        text[i] ^= key;
}

void encrypt(char* text, int shift, char key) {
    rotateLeftText(text, shift);
    xorC(text, key);
}

void decrypt(char* text, int shift, char key) {
    xorC(text, key);
    rotateRightText(text, shift);
}

void encryptChars(char* chars, int size, int shift, char key) {
    for (int i = 0; i < size; i++) {
        unsigned char v = chars[i];
        v = (v << shift) | (v >> (8 - shift));
        v ^= key;
        chars[i] = v;
    }
}

void decryptChars(char* chars, int size, int shift, char key) {
    for (int i = 0; i < size; i++) {
        unsigned char v = chars[i];
        v ^= key;
        v = (v >> shift) | (v << (8 - shift));
        chars[i] = v;
    }
}