#include "Utils.h"
#include <iostream>
#include <limits>

using std::cin;
using std::cout;

//Validacion de posicion 
int readMove(char player) {
    // Bucle hasta que el jugador ingrese un valor valido
    while (true) {
        // Muestra en pantalla un mensaje con el jugador actual (X o O)
        cout << "Jugador " << player << " - Ingresa una posicion (1-9): ";

        int pos; 

        if (cin >> pos) {
            
            return pos;
        }
        else {
            
            cin.clear();

            // Se eliminan todos los caracteres que queden en el bufer de entrada hasta llegar a un salto de linea.
            // Esto evita que la basura anterior cause mas errores.
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Muestra un mensaje al usuario indicando que debe volver a intentar
            cout << "Entrada invalida. Intenta de nuevo.\n";
        }
    }
}


char switchPlayer(char current) { // Usa un operador para alternar:
    
    return (current == 'X') ? 'O' : 'X';
}
