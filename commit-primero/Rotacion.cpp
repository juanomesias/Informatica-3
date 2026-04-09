#include "rotacion.h"


unsigned char rotateLeft(unsigned char value, int shift) {
    return (value << shift) | (value >> (8 - shift));
}

unsigned char rotateRight(unsigned char value, int shift) {
    return (value >> shift) | (value << (8 - shift));
}

void rotateLeftText(char* text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = rotateLeft(text[i], shift);
    }
}

void rotateRightText(char* text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = rotateRight(text[i], shift);
    }
}