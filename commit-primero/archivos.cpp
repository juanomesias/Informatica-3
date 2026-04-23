#include "archivos.h"
#include <fstream>

using namespace std;

void leerArchivo(const char* nombre, char* texto) {
    ifstream archivo(nombre);
    if (!archivo) throw "Error al abrir archivo";

    int i = 0;
    char c;

    while (archivo.get(c)) {
        texto[i++] = c;
        if (i >= 1000) throw "Archivo muy grande";
    }

    if (i == 0) throw "Archivo vacio";

    texto[i] = '\0';
}

void escribirArchivo(const char* nombre, const char* texto) {
    ofstream archivo(nombre);
    if (!archivo) throw "Error al escribir archivo";

    archivo << texto;
}