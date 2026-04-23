#ifndef LZ78_H
#define LZ78_H

struct Entry {
    int prefix;
    char c;
};

int findEntry(Entry* dict, int size, int prefix, char c);

void compressLZ78(const char* input, int indices[], char chars[], int &size);
void decompressLZ78(int indices[], char chars[], int size, char* output);

void guardarLZ78(const char* nombre, int indices[], char chars[], int size);
void leerLZ78(const char* nombre, int indices[], char chars[], int &size);

#endif