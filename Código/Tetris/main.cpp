#include <iostream>
#include "tablero.h"

using namespace std;

int main()
{
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

    visualizarTablero(tablero, alto, anchoBytes);
    liberarTablero(tablero, alto);

    return 0;
}
