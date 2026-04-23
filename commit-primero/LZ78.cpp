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

void compressLZ78(const char* input, int indices[], char chars[], int &size) {
    if (!input)
        throw "LZ78: texto nulo";

    Entry* dict = new Entry[1000];
    int dictSize = 1;
    int prefix = 0;
    size = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (dictSize >= 999)
            throw "LZ78: diccionario lleno";

        char c = input[i];
        int index = findEntry(dict, dictSize, prefix, c);

        if (index != -1) {
            prefix = index;
        } else {
            indices[size] = prefix;
            chars[size] = c;
            size++;

            dict[dictSize].prefix = prefix;
            dict[dictSize].c = c;
            dictSize++;
            prefix = 0;
        }
    }

    delete[] dict;
}

void decompressLZ78(int indices[], char chars[], int size, char* output) {
    char** dict = new char*[1000];
    int dictSize = 1;
    int pos = 0;

    for (int i = 0; i < size; i++) {
        if (indices[i] >= dictSize)
            throw "LZ78: indice invalido";

        char* nuevo;

        if (indices[i] == 0) {
            nuevo = new char[2];
            nuevo[0] = chars[i];
            nuevo[1] = '\0';
        } else {
            int len = 0;
            while (dict[indices[i]][len] != '\0') len++;

            nuevo = new char[len + 2];

            for (int j = 0; j < len; j++)
                nuevo[j] = dict[indices[i]][j];

            nuevo[len] = chars[i];
            nuevo[len + 1] = '\0';
        }

        dict[dictSize] = nuevo;

        for (int k = 0; nuevo[k] != '\0'; k++)
            output[pos++] = nuevo[k];

        dictSize++;
    }

    output[pos] = '\0';

    for (int i = 1; i < dictSize; i++)
        delete[] dict[i];

    delete[] dict;
}

void guardarLZ78(const char* nombre, int indices[], char chars[], int size) {
    ofstream archivo(nombre);
    if (!archivo) throw "LZ78: error al guardar";

    for (int i = 0; i < size; i++)
        archivo << indices[i] << " " << chars[i] << "\n";
}

void leerLZ78(const char* nombre, int indices[], char chars[], int &size) {
    ifstream archivo(nombre);
    if (!archivo) throw "LZ78: error al leer";

    size = 0;

    while (archivo >> indices[size] >> chars[size]) {
        size++;
        if (size >= 1000)
            throw "LZ78: archivo grande";
    }
}