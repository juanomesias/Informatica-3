#ifndef ROTACION_H
#define ROTACION_H

unsigned char rotateLeft(unsigned char value, int shift);
unsigned char rotateRight(unsigned char value, int shift);

void rotateLeftText(char* text, int shift);
void rotateRightText(char* text, int shift);

#endif