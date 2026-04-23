#include <iostream>
#include <cstring>
#include "rle.h"
#include "lz78.h"
#include "rotacion.h"
#include "xor.h"
#include "archivos.h"
#include <direct.h>


using namespace std;

bool iguales(const char* a, const char* b) {
    return strcmp(a, b) == 0;
}

int main() {


    char ruta[1000];
    _getcwd(ruta, 1000);
    cout << "Ruta actual: " << ruta << endl;

    int opcion;

    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. RLE\n";
        cout << "2. LZ78\n";
        cout << "3. Rotacion\n";
        cout << "4. Encriptacion\n";
        cout << "5. Integracion completa\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        // ───────────── RLE ─────────────
        if (opcion == 1) {
            try {
                char texto[1000];
                char comp[1000];
                char decomp[1000];

                cout << "Texto: ";
                cin.getline(texto, 1000);

                rleCompress(texto, comp);
                cout << "Comprimido: " << comp << endl;

                rleDecompress(comp, decomp);
                cout << "Descomprimido: " << decomp << endl;

                if (iguales(texto, decomp))
                    cout << "✔ OK\n";
                else
                    cout << "✘ ERROR\n";

            } catch (const char* e) {
                cout << "Error RLE: " << e << endl;
            }
        }

        // ───────────── LZ78 ─────────────
        else if (opcion == 2) {
            try {
                char texto[1000];
                int indices[1000];
                char chars[1000];
                char resultado[1000];
                int size;

                cout << "Texto: ";
                cin.getline(texto, 1000);

                compressLZ78(texto, indices, chars, size);

                cout << "Pares: ";
                for (int i = 0; i < size; i++)
                    cout << "(" << indices[i] << "," << chars[i] << ") ";
                cout << endl;

                decompressLZ78(indices, chars, size, resultado);
                cout << "Resultado: " << resultado << endl;

                if (iguales(texto, resultado))
                    cout << "✔ OK\n";
                else
                    cout << "✘ ERROR\n";

            } catch (const char* e) {
                cout << "Error LZ78: " << e << endl;
            }
        }

        // ───────────── ROTACION ─────────────
        else if (opcion == 3) {
            try {
                char texto[1000];
                int n;

                cout << "Texto: ";
                cin.getline(texto, 1000);

                cout << "Rotaciones (1-7): ";
                cin >> n;
                cin.ignore();

                char copia[1000];
                strcpy(copia, texto);

                rotateLeftText(copia, n);
                cout << "Rotado: " << copia << endl;

                rotateRightText(copia, n);
                cout << "Restaurado: " << copia << endl;

                if (iguales(texto, copia))
                    cout << "✔ OK\n";
                else
                    cout << "✘ ERROR\n";

            } catch (const char* e) {
                cout << "Error Rotacion: " << e << endl;
            }
        }

        // ───────────── ENCRIPTACION ─────────────
        else if (opcion == 4) {
            try {
                char texto[1000];
                int n;
                char key;

                cout << "Texto: ";
                cin.getline(texto, 1000);

                cout << "Rotaciones: ";
                cin >> n;

                cout << "Clave: ";
                cin >> key;
                cin.ignore();

                char copia[1000];
                strcpy(copia, texto);

                encrypt(copia, n, key);
                cout << "Encriptado: " << copia << endl;

                decrypt(copia, n, key);
                cout << "Desencriptado: " << copia << endl;

                if (iguales(texto, copia))
                    cout << "✔ OK\n";
                else
                    cout << "✘ ERROR\n";

            } catch (const char* e) {
                cout << "Error Encriptacion: " << e << endl;
            }
        }

        // ───────────── INTEGRACION ─────────────
        else if (opcion == 5) {
            try {
                char archivo[100];
                char original[1000];
                char resultado[1000];

                int metodo, n;
                char key;

                cout << "Archivo entrada: ";
                cin.getline(archivo, 100);

                cout << "Metodo (1=RLE, 2=LZ78): ";
                cin >> metodo;

                cout << "Rotaciones: ";
                cin >> n;

                cout << "Clave: ";
                cin >> key;
                cin.ignore();

                // 🔥 USAR ARCHIVO CORRECTAMENTE
                leerArchivo(archivo, original);

                // ─── RLE ───
                if (metodo == 1) {
                    char comp[1000];

                    rleCompress(original, comp);
                    encrypt(comp, n, key);

                    escribirArchivo("encriptado.txt", comp);

                    decrypt(comp, n, key);
                    rleDecompress(comp, resultado);
                }

                // ─── LZ78 ───
                else if (metodo == 2) {
                    int indices[1000];
                    char chars[1000];
                    int size;

                    compressLZ78(original, indices, chars, size);

                    encryptChars(chars, size, n, key);

                    guardarLZ78("encriptado.txt", indices, chars, size);

                    int idx2[1000];
                    char ch2[1000];
                    int size2;

                    leerLZ78("encriptado.txt", idx2, ch2, size2);

                    decryptChars(ch2, size2, n, key);

                    decompressLZ78(idx2, ch2, size2, resultado);
                }

                else {
                    throw "Metodo invalido";
                }

                escribirArchivo("resultado.txt", resultado);

                if (iguales(original, resultado))
                    cout << "✔ TODO CORRECTO\n";
                else
                    cout << "✘ ERROR FINAL\n";

            } catch (const char* e) {
                cout << "Error Integracion: " << e << endl;
            }
        }
    } while (opcion != 0);

    return 0;
}