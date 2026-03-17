#include <iostream>
#include "tablero.h"

using namespace std;

unsigned char** crearTablero(unsigned short alto, unsigned char anchoBytes) {
    unsigned char** tablero = new unsigned char*[alto];
    for (signed char i = 0; i < alto; i++) {
        tablero[i] = new unsigned char[anchoBytes];
        for (signed char j = 0; j < anchoBytes; j++) tablero[i][j] = 0;
    }
    return tablero;
}

void visualizarTablero(unsigned char** tablero, unsigned short alto, unsigned char anchoBytes) {
    for (signed char i = 0; i < alto; i++) {
        cout << "|";
        for (signed char j = 0; j < anchoBytes; j++) {
            for (signed char bit = 7; bit >= 0; bit--) {
                if ((tablero[i][j] >> bit) & 1) cout << "[]";
                else cout << "  ";
            }
        }
        cout << "|" << endl;
    }
}

void liberarTablero(unsigned char** tablero, unsigned short alto) {
    for (int i = 0; i < alto; i++) delete[] tablero[i];
    delete[] tablero;
}
