// Incluye el encabezado (header) donde se declararon las funciones auxiliares
// 'readMove' y 'switchPlayer'. Aqu� se implementan sus definiciones.
#include "Utils.h"

// Incluye la librer�a est�ndar de entrada/salida para usar 'cin' y 'cout'
#include <iostream>

// Incluye la librer�a <limits> para obtener el l�mite m�ximo de tama�o del flujo de entrada.
// Se usa en 'cin.ignore()' para limpiar completamente el b�fer de entrada en caso de error.
#include <limits>

// Evita tener que escribir std::cin y std::cout cada vez.
// Permite usar directamente 'cin' y 'cout'.
using std::cin;
using std::cout;

// =============================================================
//  Funci�n: readMove
//  Prop�sito: solicitar al jugador que ingrese una posici�n v�lida (1�9)
// =============================================================
int readMove(char player) {
    // Bucle infinito que continuar� hasta que el jugador ingrese un valor v�lido
    while (true) {
        // Muestra en pantalla un mensaje con el jugador actual (X o O)
        cout << "Jugador " << player << " - Ingresa una posicion (1-9): ";

        int pos; // Variable donde se almacenar� la posici�n ingresada

        // Intenta leer un n�mero entero desde el teclado
        if (cin >> pos) {
            // Si la lectura es exitosa (no se ingresaron letras u otros s�mbolos), devuelve el n�mero
            return pos;
        }
        else {
            // Si la entrada fue inv�lida (por ejemplo, texto en lugar de n�mero):

            // Limpia el estado de error del flujo 'cin' para poder seguir leyendo
            cin.clear();

            // Elimina todos los caracteres que queden en el b�fer de entrada hasta llegar a un salto de l�nea.
            // Esto evita que la basura anterior cause m�s errores.
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Muestra un mensaje al usuario indicando que debe volver a intentar
            cout << "Entrada invalida. Intenta de nuevo.\n";
        }
    }
}

// =============================================================
//  Funci�n: switchPlayer
//  Prop�sito: cambiar el turno entre los jugadores 'X' y 'O'
// =============================================================
char switchPlayer(char current) {
    // Usa un operador ternario para alternar:
    // Si el jugador actual es 'X', devuelve 'O'; de lo contrario, devuelve 'X'.
    return (current == 'X') ? 'O' : 'X';
}
