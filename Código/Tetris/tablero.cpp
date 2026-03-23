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


void visualizarTableroConPieza(unsigned char** tablero, unsigned short alto, unsigned char anchoBytes,
                               unsigned short piezaForma, signed char filaP, signed char colP) {

    for (signed char i = 0; i < (signed char)alto; i++) {
        cout << "|";
        for (signed char j = 0; j < (signed char)anchoBytes; j++) {
            for (signed char bit = 7; bit >= 0; bit--) {

                signed char colReal = (j * 8) + (7 - bit);
                bool pintarBloque = false;

                if ((tablero[i][j] >> bit) & 1) {
                    pintarBloque = true;
                }

                if (i >= filaP && i < filaP + 4 && colReal >= colP && colReal < colP + 4) {
                    signed char fRel = i - filaP;
                    signed char cRel = colReal - colP;

                    if ((piezaForma >> (15 - (fRel * 4 + cRel))) & 1) {
                        pintarBloque = true;
                    }
                }

                if (pintarBloque) cout << "[]";
                else cout << "  ";
            }
        }
        cout << "|" << endl;
    }
}
