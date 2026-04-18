#include <iostream>
#include "rle.h"
#include "xor.h"
#include "rotacion.h"
#include "lz78.h"
#include "archivos.h"

using namespace std;

int main() {
    try {

        int opcion;
        char texto[100];

        do {
            cout << "MENU PRINCIPAL\n";
            cout << "1. RLE\n";
            cout << "2. LZ78\n";
            cout << "3. Rotacion de bits\n";
            cout << "4. Encriptacion (Rotacion + XOR)\n";
            cout << "5. Integracion completa\n";   // 🔥 AQUÍ VA
            cout << "0. Salir\n";
            cout << "Opcion: ";
            cin >> opcion;
            cin.ignore();

            switch (opcion) {

            case 1: {
                char comprimido[100];
                char descomprimido[100];

                cout << "Ingrese texto: ";
                cin.getline(texto, 100);

                rleCompress(texto, comprimido);
                cout << "Texto Comprimido: " << comprimido << endl;

                rleDecompress(comprimido, descomprimido);
                cout << "Texto Descomprimido: " << descomprimido << endl;

                break;
            }

            case 2: {
                cout << "Ingrese texto: ";
                cin.getline(texto, 100);

                int indices[100];
                char chars[100];
                int size;

                compressLZ78(texto, indices, chars, size);

                cout << "Texto Comprimido: ";
                for (int i = 0; i < size; i++)
                    cout << indices[i] << chars[i] << " ";

                cout << "\nTexto Descomprimido: ";
                decompressLZ78(indices, chars, size);
                cout << endl;
                break;
            }

            case 3: {
                int n;
                cout << "Ingrese texto: ";
                cin.getline(texto, 100);

                cout << "Numero de rotaciones: ";
                cin >> n;
                cin.ignore();

                rotateLeftText(texto, n);
                cout << "Texto Rotado: " << texto << endl;

                rotateRightText(texto, n);
                cout << "Texto Original: " << texto << endl;

                break;
            }

            case 4: {
                char key;
                int n;

                cout << "Ingrese texto: ";
                cin.getline(texto, 100);

                cout << "Numero de rotaciones: ";
                cin >> n;

                cout << "Clave: ";
                cin >> key;
                cin.ignore();

                encrypt(texto, n, key);
                cout << "Texto Encriptado: " << texto << endl;

                decrypt(texto, n, key);
                cout << "Texto Desencriptado: " << texto << endl;

                break;
            }

            case 5: {   // 🔥 ESTE ERA EL PROBLEMA PRINCIPAL

                int metodo;
                char archivoEntrada[50];

                char texto[1000];
                char comprimido[1000];
                char descomprimido[1000];

                int indices[1000];
                char chars[1000];
                int size;

                int n;
                char key;

                cout << "Archivo de entrada: ";
                cin.getline(archivoEntrada, 50);

                cout << "Metodo (1=RLE, 2=LZ78): ";
                cin >> metodo;

                cout << "Rotaciones: ";
                cin >> n;

                cout << "Clave: ";
                cin >> key;
                cin.ignore();

                // 🔹 Leer archivo
                leerArchivo(archivoEntrada, texto);

                if (metodo == 1) {

                    // RLE
                    rleCompress(texto, comprimido);

                    // Encriptar
                    encrypt(comprimido, n, key);

                    escribirArchivo("encriptado.txt", comprimido);

                    // Desencriptar
                    decrypt(comprimido, n, key);

                    // Descomprimir
                    rleDecompress(comprimido, descomprimido);

                    escribirArchivo("resultado.txt", descomprimido);

                } else {

                    // LZ78
                    compressLZ78(texto, indices, chars, size);

                    guardarLZ78("encriptado.txt", indices, chars, size);

                    leerLZ78("encriptado.txt", indices, chars, size);

                    cout << "Texto reconstruido: ";
                    decompressLZ78(indices, chars, size);
                }

                cout << "Proceso completado\n";
                break;
            }

            }

        } while (opcion != 0);

        return 0;

    } catch (...) {
        cout << "Ocurrio un error en el programa" << endl;
        return 1;
    }
}