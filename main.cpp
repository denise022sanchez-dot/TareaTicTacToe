#include <iostream>
#include "Game.h"

using std::cin;
using std::cout;

int main() {
    
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== Tic Tac Toe (Gato) ===\n";

    
    bool again = true;  // Variable de control para repetir el juego

    // Mientras el jugador desee seguir jugando...
    while (again) {
        
        Game g;
        g.run();

        
        cout << "\nDeseas jugar otra vez? (s/n): ";
        char opc;   
        cin >> opc; 

        // Si la opcion no es 's' o 'S', se termina el programa
        if (opc != 's' && opc != 'S')
            again = false;
    }

    cout << "Gracias por jugar. Hasta luego!\n";

    return 0;
}
