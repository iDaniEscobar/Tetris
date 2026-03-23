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

    signed char colP = (signed char)((ancho / 2) - 2);
    signed char filaP = -3;
    char tecla = ' ';

    //visualizarTableroConPieza(tablero, alto, anchoBytes, piezas[pieza], filaP, colP);

    while (tecla != 'q' && tecla != 'Q') {

        // Dibujamos el estado actual
        visualizarTableroConPieza(tablero, alto, anchoBytes, piezas[pieza], filaP, colP);

        cout << "Controles: [A]Izq, [D]Der, [S]Bajar, [W]Rotar, [Q]Salir: ";
        cin >> tecla;

        // Lógica de movimiento
        if (tecla == 'a' || tecla == 'A') {

            if (validarMovimiento(tablero, alto, anchoBytes, piezas[pieza], filaP, colP - 1)) {
                colP--;
            }
        }

        else if (tecla == 'd' || tecla == 'D') {

            if (validarMovimiento(tablero, alto, anchoBytes, piezas[pieza], filaP, colP + 1)) {
                colP++;
            }
        }

        else if (tecla == 'w' || tecla == 'W') {

        }

        else if (tecla == 's' || tecla == 'S') {

            if (validarMovimiento(tablero, alto, anchoBytes, piezas[pieza], filaP + 1, colP)) {
                filaP++;
            }
            else {
                fijarPieza(tablero, piezas[pieza], filaP, colP);
                pieza = rand() % num_pieza;
                filaP = -3;
                colP = (signed char)((ancho / 2) - 2);
                if (!validarMovimiento(tablero, alto, anchoBytes, piezas[pieza], filaP, colP)) {
                    cout << "GAME OVER" << endl;
                    tecla = 'q';
                }
            }
        }
    }


    liberarTablero(tablero, alto);
    return 0;
}
