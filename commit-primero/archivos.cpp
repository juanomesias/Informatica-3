#include <fstream>
#include <iostream>
#include "archivos.h"

using namespace std;

void leerArchivo(const char* nombre, char* texto) {
    ifstream archivo(nombre);

    if (!archivo) {
        throw "Error al abrir archivo";
    }

    int i = 0;
    char c;

    while (archivo.get(c)) {
        texto[i++] = c;
    }

    texto[i] = '\0';

    archivo.close();
}

void escribirArchivo(const char* nombre, const char* texto) {
    ofstream archivo(nombre);

    if (!archivo) {
        throw "Error al escribir archivo";
    }

    archivo << texto;

    archivo.close();
}