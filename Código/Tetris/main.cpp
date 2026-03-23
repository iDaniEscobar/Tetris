#include <iostream>
#include "tablero.h"
#include "piezas.h"
#include <ctime>
#include <cstdlib>


using namespace std;

int main()
{
    //Para ver el tablero

    unsigned short alto, ancho;

    cout << "Ingrese el alto del tablero: ";
    cin >> alto;

    cout << "Ingrese el ancho del tablero: ";
    cin >> ancho;

    while (alto < 8 || ancho < 8 || (ancho % 8 != 0)) {
        cout << "Dimensiones no validas. Recuerde que el alto y ancho minimo es 8" << endl<< "y el ancho debe ser multiplo de 8." << endl;
        cout << "Ingrese el alto del tablero: ";
        cin >> alto;

        cout << "Ingrese el ancho del tablero: ";
        cin >> ancho;
    }

    unsigned char anchoBytes = (unsigned char)(ancho / 8);

    unsigned char** tablero = crearTablero(alto, anchoBytes);

    cout << endl << "Visualizacion del tablero" << endl;

    //visualizarTablero(tablero, alto, anchoBytes);


    // Pruebas de visualización de piezas
    srand(time(0));

    signed char pieza = rand() % num_pieza;
    unsigned short piezaActual = piezas[pieza];

    signed char colP = (signed char)((ancho / 2) - 2);
    signed char filaP = -3;
    char tecla = ' ';

    //visualizarTableroConPieza(tablero, alto, anchoBytes, piezas[pieza], filaP, colP);

    while (tecla != 'q' && tecla != 'Q') {
         //Visualizacion del tablero
        visualizarTableroConPieza(tablero, alto, anchoBytes, piezaActual, filaP, colP);

        cout << "Controles: [A]Izq, [D]Der, [S]Bajar, [W]Rotar, [Q]Salir: ";
        cin >> tecla;

        // Lógica de movimiento
        if (tecla == 'a' || tecla == 'A') {

            if (validarMovimiento(tablero, alto, anchoBytes, piezaActual, filaP, colP - 1)) {
                colP--;
            }
        }

        else if (tecla == 'd' || tecla == 'D') {

            if (validarMovimiento(tablero, alto, anchoBytes, piezaActual, filaP, colP + 1)) {
                colP++;
            }
        }

        else if (tecla == 'w' || tecla == 'W') {
            unsigned short piezaProvisional = rotarPiezas(piezaActual);

            if (validarMovimiento(tablero, alto, anchoBytes, piezaProvisional, filaP, colP)) {
                piezaActual = piezaProvisional;
            }
        }

        else if (tecla == 's' || tecla == 'S') {

            if (validarMovimiento(tablero, alto, anchoBytes, piezaActual, filaP + 1, colP)) {
                filaP++;
            }
            else {
                fijarPieza(tablero, piezaActual, filaP, colP);

                eliminarFilas(tablero, alto, anchoBytes);

                pieza = rand() % num_pieza;
                piezaActual = piezas[pieza];
                filaP = -3;
                colP = (signed char)((ancho / 2) - 2);
                if (!validarMovimiento(tablero, alto, anchoBytes, piezaActual, filaP, colP)) {
                    cout << "GAME OVER" << endl;
                    tecla = 'q';
                }
            }
        }
    }


    liberarTablero(tablero, alto);
    return 0;
}
