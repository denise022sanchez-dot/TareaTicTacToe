// =============================================================
//  Inclusi�n de librer�as y encabezados necesarios
// =============================================================

// Incluye la librer�a est�ndar <iostream> para manejar entrada y salida de datos,
// como 'cout' (salida por consola) y 'cin' (entrada por teclado).
#include <iostream>

// Incluye el encabezado "Game.h", que contiene la estructura 'Game' y su m�todo 'run()'.
// Este archivo es fundamental, ya que 'main' crea un objeto de tipo Game para ejecutar el juego.
#include "Game.h"

// Permite usar directamente 'cin' y 'cout' sin tener que escribir 'std::' antes de cada uno.
// Por ejemplo, podemos usar 'cout <<' en lugar de 'std::cout <<'.
using std::cin;
using std::cout;

// =============================================================
//  Funci�n principal del programa
// =============================================================
// Todo programa en C++ comienza su ejecuci�n en la funci�n 'main()'.
// Aqu� se inicializa y controla el flujo principal del juego Tic Tac Toe.
int main() {
    // -------------------------------------------------------------
    // Optimizaci�n de entrada/salida
    // -------------------------------------------------------------
    // Desactiva la sincronizaci�n entre C++ (iostream) y C (stdio)
    // para mejorar la velocidad de entrada/salida de datos.
    std::ios::sync_with_stdio(false);

    // Desvincula el flujo est�ndar 'cin' del flujo 'cout'.
    // Esto evita que 'cout' se vac�e autom�ticamente antes de leer con 'cin',
    // lo que mejora el rendimiento del programa.
    cin.tie(nullptr);

    // -------------------------------------------------------------
    // Mensaje inicial de bienvenida
    // -------------------------------------------------------------
    cout << "=== Tic Tac Toe (Gato) en C++ ===\n";

    // -------------------------------------------------------------
    // Ciclo principal del programa (permite jugar varias veces)
    // -------------------------------------------------------------
    bool again = true;  // Variable de control para repetir el juego

    // Mientras el jugador desee seguir jugando...
    while (again) {
        // Crea un objeto de tipo 'Game'.
        // Cada vez que se ejecuta este bloque, se inicia una nueva partida.
        Game g;

        // Llama al m�todo 'run()' del objeto 'Game',
        // el cual ejecuta todo el ciclo del juego (jugadas, turnos, ganador, empate, etc.).
        g.run();

        // -------------------------------------------------------------
        // Pregunta al usuario si desea volver a jugar
        // -------------------------------------------------------------
        cout << "\n�Deseas jugar otra vez? (s/n): ";

        char opc;   // Variable para almacenar la respuesta del jugador
        cin >> opc; // Lee la opci�n ingresada por el usuario

        // Si la opci�n no es 's' o 'S', se termina el ciclo (y por tanto el programa)
        if (opc != 's' && opc != 'S')
            again = false;
    }

    // -------------------------------------------------------------
    // Mensaje final de despedida
    // -------------------------------------------------------------
    cout << "Gracias por jugar. �Hasta luego!\n";

    // Retorna 0 indicando que el programa termin� correctamente.
    return 0;
}
