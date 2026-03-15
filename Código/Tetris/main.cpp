#include <iostream>

using namespace std;

int main()
{
    int alto, ancho;

    cout << "Ingrese el alto del tablero: ";
    cin >> alto;

    cout << "Ingrese el ancho del tablero: ";
    cin >> ancho;

    if (alto < 8 || ancho < 8 || (ancho % 8 != 0)) {
        cout << "Dimensiones no validas. Recuerde que el alto y ancho minimo es 8" << endl<< "y el ancho debe ser multiplo de 8." << endl;
        cout << "Ingrese el alto del tablero: ";
        cin >> alto;

        cout << "Ingrese el ancho del tablero: ";
        cin >> ancho;
    }

    int anchoBytes = ancho / 8;

    unsigned char** tablero = new unsigned char*[alto];
    for (int i = 0; i < alto; i++) {
        tablero[i] = new unsigned char[anchoBytes];
        for (int j = 0; j < anchoBytes; j++) {
            tablero[i][j] = 0;
        }
    }


    for (int i = 0; i < alto; i++) {
        delete[] tablero[i];
    }
    delete[] tablero;

    return 0;
}
