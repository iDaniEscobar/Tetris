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

    signed char colInicial = (signed char)((ancho / 2) - 2);
    signed char filaInicial = 0;

    visualizarTableroConPieza(tablero, alto, anchoBytes, piezas[pieza], filaInicial, colInicial);


    liberarTablero(tablero, alto);
    return 0;
}
