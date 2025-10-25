#include "Game.h"
#include "Utils.h"
#include <iostream>

using std::cout;


void Game::run() {
    // Inicializa el tablero con los números del 1 al 9
    board.init();

    // El jugador que comienza es 'X'
    current = 'X';

    bool end = false;

    // El juego se repite hasta que haya un ganador o empate
    while (!end) {
        // Muestra el estado actual del tablero en la consola
        board.draw();

        // Pide al jugador actual que ingrese una posición
        int pos = readMove(current);

        // Para comprobar que la posisicion ingresada esté dentro del rango y libre
        if (!board.isValidMove(pos)) {

            cout << "Movimiento no valido. Elige una casilla libre entre 1 y 9.\n";
            
            continue;
        }

        // Coloca la jugada del jugador actual ('X' o 'O') en el tablero
        board.makeMove(pos, current);


        // Se Verifica si el jugador actual ha ganado
        if (board.checkWin(current)) {
            // Vuelve a dibujar el tablero actualizado
            board.draw();
            
            cout << "¡Jugador " << current << " gana!\n";
            end = true;
        }
        //S i nadie gana verifica si hubo empate
        else if (board.checkDraw()) {
            // Dibuja el tablero final
            board.draw();
            
            cout << "Empate. No hay mas movimientos.\n";
            
            end = true;
        }
        //Si aún no hay ganador ni empate, cambia de jugador
        else {
            current = switchPlayer(current);
        }
    }
}
