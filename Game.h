// =============================================================
//  Directiva del preprocesador para evitar inclusiones m�ltiples
// =============================================================

// '#pragma once' asegura que este archivo solo se incluya una vez durante la compilaci�n.
// Evita errores por definiciones duplicadas si varios archivos incluyen "Game.h".
#pragma once

// Incluye el archivo "Board.h", necesario porque la estructura Game utiliza un objeto Board.
// Esto permite que Game conozca el tipo de dato 'Board' y pueda usarlo dentro de su definici�n.
#include "Board.h"

// =============================================================
//  Estructura principal del juego: Game
// =============================================================
// La palabra clave 'struct' define una estructura, similar a una clase,
// pero con acceso p�blico por defecto.
// Esta estructura controla el flujo general del juego Tic Tac Toe.
struct Game {

    // ---------------------------------------------------------
    // Atributos (variables miembro)
    // ---------------------------------------------------------

    // 'board' es un objeto de tipo Board que representa el tablero del juego.
    // Se usar� para mostrar el estado del tablero y verificar jugadas.
    Board board;

    // 'current' almacena el s�mbolo del jugador actual ('X' o 'O').
    // Se inicializa con 'X', indicando que el primer turno siempre lo tiene el jugador X.
    char current{ 'X' };

    // ---------------------------------------------------------
    // M�todos (funciones miembro)
    // ---------------------------------------------------------

    // 'run()' ejecuta una partida completa de Tic Tac Toe.
    // Controla el ciclo de turnos, las jugadas, las verificaciones de victoria o empate.
    void run(); // Ejecuta una partida completa
};
