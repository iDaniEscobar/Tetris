#ifndef TABLERO_H
#define TABLERO_H

unsigned char** crearTablero(unsigned short alto, unsigned char anchoBytes);
void visualizarTablero(unsigned char** tablero, unsigned short alto, unsigned char anchoBytes);
void liberarTablero(unsigned char** tablero, unsigned short alto);

#endif
