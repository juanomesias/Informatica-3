#include <iostream>
#include "lz78.h"
#include <fstream>
    using namespace std;


int findEntry(Entry* dict, int size, int prefix, char c) {
    for (int i = 0; i < size; i++) {
        if (dict[i].prefix == prefix && dict[i].c == c)
            return i;
    }
    return -1;
}


void compressLZ78(const char* input, int indices[], char chars[], int &outSize) {
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

    delete[] dict;
}


void decompressLZ78(int indices[], char chars[], int size) {
    char** dict = new char*[1000];
    int dictSize = 1;

    for (int i = 0; i < size; i++) {
        char* nuevoNodo;

        if (indices[i] == 0) {
            nuevoNodo = new char[2];
            nuevoNodo[0] = chars[i];
            nuevoNodo[1] = '\0';
        } else {
            int lenPrefijo = 0;


            while (dict[indices[i]][lenPrefijo] != '\0') {
                lenPrefijo++;
            }

            nuevoNodo = new char[lenPrefijo + 2];


            for (int j = 0; j < lenPrefijo; j++) {
                nuevoNodo[j] = dict[indices[i]][j];
            }


            nuevoNodo[lenPrefijo] = chars[i];
            nuevoNodo[lenPrefijo + 1] = '\0';
        }

        dict[dictSize] = nuevoNodo;
        cout << dict[dictSize];
        dictSize++;
    }

    cout << endl;

    for (int i = 1; i < dictSize; i++) {
        delete[] dict[i];
    }
    delete[] dict;
}

//Archivos
void guardarLZ78(const char* nombre, int indices[], char chars[], int size) {
    ofstream archivo(nombre);

    for (int i = 0; i < size; i++) {
        archivo << indices[i] << " " << chars[i] << "\n";
    }

    archivo.close();
}

void leerLZ78(const char* nombre, int indices[], char chars[], int &size) {
    ifstream archivo(nombre);

    size = 0;

    while (archivo >> indices[size] >> chars[size]) {
        size++;
    }

    archivo.close();
}