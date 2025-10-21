// =============================================================
//  Directiva para evitar inclusiones múltiples del mismo archivo
// =============================================================

// '#pragma once' indica al compilador que este archivo solo debe incluirse una vez
// durante la compilación. Evita errores por duplicidad de definiciones.
#pragma once


// =============================================================
//  Declaraciones de funciones auxiliares (prototipos)
// =============================================================

// 'readMove' solicita al jugador actual (X o O) que ingrese un número de posición (1–9).
// Si el usuario escribe un valor no válido (letras o símbolos), la función limpiará el
// búfer de entrada y volverá a pedir el número.
// Parámetro: 'player' → indica quién está jugando ('X' o 'O').
// Retorna: número entero de la posición elegida.
int readMove(char player);

// 'switchPlayer' alterna el turno entre jugadores.
// Si el jugador actual es 'X', devolverá 'O', y viceversa.
// Parámetro: 'current' → jugador actual.
// Retorna: carácter del nuevo jugador ('X' o 'O').
char switchPlayer(char current);
