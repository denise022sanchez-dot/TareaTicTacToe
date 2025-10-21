// =============================================================
//  Inclusión de librerías y encabezados necesarios
// =============================================================

// Incluye la librería estándar <iostream> para manejar entrada y salida de datos,
// como 'cout' (salida por consola) y 'cin' (entrada por teclado).
#include <iostream>

// Incluye el encabezado "Game.h", que contiene la estructura 'Game' y su método 'run()'.
// Este archivo es fundamental, ya que 'main' crea un objeto de tipo Game para ejecutar el juego.
#include "Game.h"

// Permite usar directamente 'cin' y 'cout' sin tener que escribir 'std::' antes de cada uno.
// Por ejemplo, podemos usar 'cout <<' en lugar de 'std::cout <<'.
using std::cin;
using std::cout;

// =============================================================
//  Función principal del programa
// =============================================================
// Todo programa en C++ comienza su ejecución en la función 'main()'.
// Aquí se inicializa y controla el flujo principal del juego Tic Tac Toe.
int main() {
    // -------------------------------------------------------------
    // Optimización de entrada/salida
    // -------------------------------------------------------------
    // Desactiva la sincronización entre C++ (iostream) y C (stdio)
    // para mejorar la velocidad de entrada/salida de datos.
    std::ios::sync_with_stdio(false);

    // Desvincula el flujo estándar 'cin' del flujo 'cout'.
    // Esto evita que 'cout' se vacíe automáticamente antes de leer con 'cin',
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

        // Llama al método 'run()' del objeto 'Game',
        // el cual ejecuta todo el ciclo del juego (jugadas, turnos, ganador, empate, etc.).
        g.run();

        // -------------------------------------------------------------
        // Pregunta al usuario si desea volver a jugar
        // -------------------------------------------------------------
        cout << "\n¿Deseas jugar otra vez? (s/n): ";

        char opc;   // Variable para almacenar la respuesta del jugador
        cin >> opc; // Lee la opción ingresada por el usuario

        // Si la opción no es 's' o 'S', se termina el ciclo (y por tanto el programa)
        if (opc != 's' && opc != 'S')
            again = false;
    }

    // -------------------------------------------------------------
    // Mensaje final de despedida
    // -------------------------------------------------------------
    cout << "Gracias por jugar. ¡Hasta luego!\n";

    // Retorna 0 indicando que el programa terminó correctamente.
    return 0;
}
