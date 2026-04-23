#ifndef XOR_H
#define XOR_H

void encrypt(char* text, int shift, char key);
void decrypt(char* text, int shift, char key);

void encryptChars(char* chars, int size, int shift, char key);
void decryptChars(char* chars, int size, int shift, char key);

#endif