// '#pragma once' asegura que este archivo solo se incluya una vez durante la compilacion.
// Evita errores por definiciones duplicadas si varios archivos incluyen "Game.h".
#pragma once
#include "Board.h"

//  Estructura principal del juego: Game
struct Game {
    Board board;

    // 'current' almacena el simbolo del jugador actual ('X' o 'O'). Se inicializa con 'X', indicando que el primer turno siempre lo tiene el jugador X.
    char current{ 'X' };

    // 'run()' ejecuta una partida completa de Tic Tac Toe.
    // Controla el ciclo de turnos, las jugadas, las verificaciones de victoria o empate.
    void run(); // Ejecuta una partida completa
};

