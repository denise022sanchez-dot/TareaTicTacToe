// Incluye el encabezado "Game.h" donde se define la estructura Game.
// Este archivo contiene la implementaci�n (el "c�mo") de las funciones de Game.
#include "Game.h"

// Incluye el encabezado "Utils.h" para poder usar las funciones auxiliares
// como readMove() y switchPlayer().
#include "Utils.h"

// Incluye la biblioteca est�ndar de entrada/salida de C++
// necesaria para usar cout y mostrar mensajes en consola.
#include <iostream>

// Permite usar cout directamente sin escribir std::cout cada vez.
using std::cout;

// =============================================================
//  Implementaci�n del m�todo principal del juego: Game::run()
// =============================================================
void Game::run() {
    // Inicializa el tablero con los n�meros del 1 al 9 (vac�o para jugar)
    board.init();

    // Establece que el jugador que comienza es 'X'
    current = 'X';

    // Variable bandera que controla cu�ndo termina la partida
    bool end = false;

    // =============================================================
    //  Bucle principal del juego (se repite hasta que haya ganador o empate)
    // =============================================================
    while (!end) {
        // Muestra el estado actual del tablero en la consola
        board.draw();

        // Pide al jugador actual que ingrese una posici�n (1 a 9)
        int pos = readMove(current);

        // Comprueba si la posici�n es v�lida (dentro del rango y libre)
        if (!board.isValidMove(pos)) {
            // Si la jugada no es v�lida, muestra mensaje de error
            cout << "Movimiento no valido. Elige una casilla libre entre 1 y 9.\n";
            // Y vuelve al inicio del ciclo sin cambiar de jugador
            continue;
        }

        // Coloca la jugada del jugador actual ('X' o 'O') en el tablero
        board.makeMove(pos, current);

        // =============================================================
        //  Verificaci�n de condiciones de fin de juego
        // =============================================================

        // 1?? Verifica si el jugador actual ha ganado
        if (board.checkWin(current)) {
            // Vuelve a dibujar el tablero actualizado
            board.draw();
            // Muestra mensaje de victoria
            cout << "�Jugador " << current << " gana!\n";
            // Marca el fin del juego
            end = true;
        }
        // 2?? Si no hay ganador, verifica si el tablero est� lleno (empate)
        else if (board.checkDraw()) {
            // Dibuja el tablero final
            board.draw();
            // Muestra mensaje de empate
            cout << "Empate. No hay mas movimientos.\n";
            // Termina el bucle
            end = true;
        }
        // 3?? Si a�n no hay ganador ni empate, cambia de jugador
        else {
            // Cambia entre 'X' y 'O' usando la funci�n auxiliar de Utils
            current = switchPlayer(current);
        }
    }
}
