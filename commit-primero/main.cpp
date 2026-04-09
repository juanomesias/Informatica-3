#include <iostream>
#include "rle.h"
#include "xor.h"
#include "rotacion.h"
#include "lz78.h"

using namespace std;

int main() {
    try {

        int opcion;
        char texto[100];

        do {
            cout << "\n--- MENU PRINCIPAL ---\n";
            cout << "1. RLE\n";
            cout << "2. LZ78\n";
            cout << "3. Rotacion de bits\n";
            cout << "4. XOR\n";
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

                rotateLeftText(texto, n);
                cout << "Texto Rotado: " << texto << endl;

                rotateRightText(texto, n);
                cout << "Texto Original: " << texto << endl;
                break;
            }

            case 4: {
                char key;
                cout << "Ingrese texto: ";
                cin.getline(texto, 100);
                cout << "Clave: ";
                cin >> key;

                xorCipher(texto, key);
                cout << "Texto Encriptado: " << texto << endl;

                xorCipher(texto, key);
                cout << "Texto Desencriptado: " << texto << endl;
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