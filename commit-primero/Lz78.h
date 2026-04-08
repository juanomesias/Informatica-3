#ifndef LZ78_H
#define LZ78_H

// Estructura que representa una entrada en el diccionario de compresión
struct Entry {
    int prefix; // Índice del prefijo anterior en el diccionario
    char c;     // El nuevo carácter que se añade al prefijo
};

// Prototipos de las funciones para que puedan ser usadas en el .cpp
int findEntry(Entry* dict, int size, int prefix, char c);
void compressLZ78(const char* input, int indices[], char chars[], int &outSize);
void decompressLZ78(int indices[], char chars[], int size);

#endif
