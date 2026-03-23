#include <iostream>
#include "piezas.h"

using namespace std;

const unsigned short piezas[num_pieza] = {
    //I
    0b0100010001000100,

    //0100
    //0100
    //0100
    //0100

    //O
    0b0000011001100000,

    //0000
    //0110
    //0110
    //0000

    //T
    0b0100111000000000,

    //0100
    //1110
    //0000
    //0000

    //S
    0b1100011000000000,

    //1100
    //0110
    //0000
    //0000

    //L
    0b0100010001100000,

    //0100
    //0100
    //0110
    //0000
};

void dibujarPieza(unsigned short pieza) {
    for (signed char i = 0; i < 16; i++) {
        if ((pieza >> (15 - i)) & 1) cout << "[]";
        else cout << "  ";

        if ((i + 1) % 4 == 0) cout << endl;
    }
}

unsigned short rotarPiezas(unsigned short piezaOriginal) {
    unsigned short piezaRotada = 0;

    for (signed char f = 0; f < 4; f++) {
        for (signed char c = 0; c < 4; c++) {
            if ((piezaOriginal >> (15 - (f * 4 + c))) & 1) {

                signed char nuevaF = c;
                signed char nuevaC = 3 - f;

                piezaRotada |= (1 << (15 - (nuevaF * 4 + nuevaC)));
            }
        }
    }
    return piezaRotada;
}
