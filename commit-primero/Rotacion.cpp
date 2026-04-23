#include "rotacion.h"

unsigned char rotL(unsigned char v, int s) {
    return (v << s) | (v >> (8 - s));
}

unsigned char rotR(unsigned char v, int s) {
    return (v >> s) | (v << (8 - s));
}

void rotateLeftText(char* text, int shift) {
    if (!text) throw "Rotacion: texto nulo";
    if (shift <= 0 || shift >= 8) throw "Rotacion invalida";

    for (int i = 0; text[i] != '\0'; i++)
        text[i] = rotL(text[i], shift);
}

void rotateRightText(char* text, int shift) {
    if (!text) throw "Rotacion: texto nulo";
    if (shift <= 0 || shift >= 8) throw "Rotacion invalida";

    for (int i = 0; text[i] != '\0'; i++)
        text[i] = rotR(text[i], shift);
}