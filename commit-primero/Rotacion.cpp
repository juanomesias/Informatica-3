#include "rotacion.h"

// Rotación de un solo byte
unsigned char rotateLeft(unsigned char value, int shift) {
    return (value << shift) | (value >> (8 - shift));
}

unsigned char rotateRight(unsigned char value, int shift) {
    return (value >> shift) | (value << (8 - shift));
}

// 🔥 ROTACIÓN DE TODO EL TEXTO
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