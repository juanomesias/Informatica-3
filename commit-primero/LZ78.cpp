#include <iostream>
#include <cstring> // Para strlen y strcpy
#include "lz78.h"

using namespace std;

// Función auxiliar para buscar en el diccionario (Arreglo estático)
int findEntry(Entry* dict, int size, int prefix, char c) {
    for (int i = 0; i < size; i++) {
        if (dict[i].prefix == prefix && dict[i].c == c)
            return i;
    }
    return -1;
}

void compressLZ78(const char* input, int indices[], char chars[], int &outSize) {
    // Memoria dinámica para el diccionario de compresión
    Entry* dict = new Entry[1000];
    int dictSize = 1;
    int currentPrefix = 0;
    outSize = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i];
        int index = findEntry(dict, dictSize, currentPrefix, c);

        if (index != -1) {
            currentPrefix = index;
        } else {
            indices[outSize] = currentPrefix;
            chars[outSize] = c;
            outSize++;

            dict[dictSize].prefix = currentPrefix;
            dict[dictSize].c = c;
            dictSize++;
            currentPrefix = 0;
        }
    }
    delete[] dict; // Liberamos la memoria dinámica
}

void decompressLZ78(int indices[], char chars[], int size) {
    // Arreglo de punteros (Memoria dinámica)
    // Cada posición del diccionario apuntará a una cadena de caracteres en el heap
    char** dict = new char*[1000];
    int dictSize = 1;

    for (int i = 0; i < size; i++) {
        char* nuevoNodo;

        if (indices[i] == 0) {
            // Caso base: solo un carácter
            nuevoNodo = new char[2];
            nuevoNodo[0] = chars[i];
            nuevoNodo[1] = '\0';
        } else {
            // Caso compuesto: prefijo previo + nuevo carácter
            int lenPrefijo = strlen(dict[indices[i]]);
            nuevoNodo = new char[lenPrefijo + 2]; // +1 para el char, +1 para el '\0'

            strcpy(nuevoNodo, dict[indices[i]]); // Copiamos el prefijo
            nuevoNodo[lenPrefijo] = chars[i];    // Añadimos el nuevo char
            nuevoNodo[lenPrefijo + 1] = '\0';    // Cerramos la cadena
        }

        dict[dictSize] = nuevoNodo;
        cout << dict[dictSize];
        dictSize++;
    }
    cout << endl;

    // Limpieza de memoria dinámica (Crucial para evitar Memory Leaks)
    for (int i = 1; i < dictSize; i++) {
        delete[] dict[i];
    }
    delete[] dict;
}

















