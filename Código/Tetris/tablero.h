#ifndef TABLERO_H
#define TABLERO_H

unsigned char** crearTablero(unsigned short alto, unsigned char anchoBytes);
void visualizarTablero(unsigned char** tablero, unsigned short alto, unsigned char anchoBytes);
void liberarTablero(unsigned char** tablero, unsigned short alto);
void visualizarTableroConPieza(unsigned char** tablero, unsigned short alto, unsigned char anchoBytes,
                               unsigned short piezaForma, signed char filaP, signed char colP);
void fijarPieza(unsigned char** tablero, unsigned short piezaForma, signed char filaP, signed char colP);
bool validarMovimiento(unsigned char** tablero, unsigned short alto, unsigned char anchoBytes,
                       unsigned short piezaForma, signed char nuevaFila, signed char nuevaCol);

#endif
