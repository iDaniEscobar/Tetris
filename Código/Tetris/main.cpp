#include <iostream>

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

    unsigned char** tablero = new unsigned char*[alto];
    for (char i = 0; i < alto; i++) {
        tablero[i] = new unsigned char[anchoBytes];
        for (char j = 0; j < anchoBytes; j++) {
            tablero[i][j] = 0;
        }
    }


    cout << endl << "Visualizacion del tablero" << endl;

    for (char i = 0; i < alto; i++) {
        cout << "|";

        for (char j = 0; j < anchoBytes; j++) {

            for (char bit = 7; bit >= 0; bit--) {

                if ((tablero[i][j] >> bit) & 1) {
                    cout << "[]";
                } else {
                    cout << "  ";
                }
            }
        }
        cout << "|" << endl;
    }



    for (char i = 0; i < alto; i++) {
        delete[] tablero[i];
    }
    delete[] tablero;

    return 0;
}
