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

bool validarMovimiento(unsigned char** tablero, unsigned short alto, unsigned char anchoBytes,
                       unsigned short piezaForma, signed char nuevaFila, signed char nuevaCol) {

    for (signed char f = 0; f < 4; f++) {
        for (signed char c = 0; c < 4; c++) {
            if ((piezaForma >> (15 - (f * 4 + c))) & 1) {
                signed char fDestino = nuevaFila + f;
                signed char cDestino = nuevaCol + c;

                if (cDestino < 0 || cDestino >= (anchoBytes * 8)) {
                    return false;
                }

                if (fDestino >= (signed char)alto) {
                    return false;
                }

                if (fDestino >= 0) {
                    signed char j = cDestino / 8;
                    signed char bit = 7 - (cDestino % 8);
                    if ((tablero[fDestino][j] >> bit) & 1) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void fijarPieza(unsigned char** tablero, unsigned short piezaForma, signed char filaP, signed char colP) {
    for (signed char f = 0; f < 4; f++) {
        for (signed char c = 0; c < 4; c++) {

            if ((piezaForma >> (15 - (f * 4 + c))) & 1) {
                signed char fTab = filaP + f;
                signed char cTab = colP + c;

                if (fTab >= 0) {
                    signed char j = cTab / 8;
                    signed char bit = 7 - (cTab % 8);

                    tablero[fTab][j] |= (1 << bit);
                }
            }
        }
    }
}

void eliminarFilas(unsigned char** tablero, unsigned short alto, unsigned char anchoBytes) {

    for (signed char i = alto - 1; i >= 0; i--) {
        bool filaLlena = true;

        for (signed char j = 0; j < anchoBytes; j++) {
            if (tablero[i][j] != 255) {
                filaLlena = false;
                break;
            }
        }

        if (filaLlena) {
            for (signed char k = i; k > 0; k--) {
                for (signed char j = 0; j < anchoBytes; j++) {
                    tablero[k][j] = tablero[k - 1][j];
                }
            }

            for (signed char j = 0; j < anchoBytes; j++) {
                tablero[0][j] = 0;
            }

            i++;
        }
    }
}


