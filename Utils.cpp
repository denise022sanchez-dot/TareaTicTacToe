// Incluye el encabezado (header) donde se declararon las funciones auxiliares
// 'readMove' y 'switchPlayer'. Aquí se implementan sus definiciones.
#include "Utils.h"

// Incluye la librería estándar de entrada/salida para usar 'cin' y 'cout'
#include <iostream>

// Incluye la librería <limits> para obtener el límite máximo de tamaño del flujo de entrada.
// Se usa en 'cin.ignore()' para limpiar completamente el búfer de entrada en caso de error.
#include <limits>

// Evita tener que escribir std::cin y std::cout cada vez.
// Permite usar directamente 'cin' y 'cout'.
using std::cin;
using std::cout;

// =============================================================
//  Función: readMove
//  Propósito: solicitar al jugador que ingrese una posición válida (1–9)
// =============================================================
int readMove(char player) {
    // Bucle infinito que continuará hasta que el jugador ingrese un valor válido
    while (true) {
        // Muestra en pantalla un mensaje con el jugador actual (X o O)
        cout << "Jugador " << player << " - Ingresa una posicion (1-9): ";

        int pos; // Variable donde se almacenará la posición ingresada

        // Intenta leer un número entero desde el teclado
        if (cin >> pos) {
            // Si la lectura es exitosa (no se ingresaron letras u otros símbolos), devuelve el número
            return pos;
        }
        else {
            // Si la entrada fue inválida (por ejemplo, texto en lugar de número):

            // Limpia el estado de error del flujo 'cin' para poder seguir leyendo
            cin.clear();

            // Elimina todos los caracteres que queden en el búfer de entrada hasta llegar a un salto de línea.
            // Esto evita que la basura anterior cause más errores.
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Muestra un mensaje al usuario indicando que debe volver a intentar
            cout << "Entrada invalida. Intenta de nuevo.\n";
        }
    }
}

// =============================================================
//  Función: switchPlayer
//  Propósito: cambiar el turno entre los jugadores 'X' y 'O'
// =============================================================
char switchPlayer(char current) {
    // Usa un operador ternario para alternar:
    // Si el jugador actual es 'X', devuelve 'O'; de lo contrario, devuelve 'X'.
    return (current == 'X') ? 'O' : 'X';
}
