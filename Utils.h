// '#pragma once' indica al compilador que este archivo solo debe incluirse una vez durante la compilación. Evita errores por duplicidad de definiciones.
#pragma once
/*'readMove' solicita al jugador actual (X o O) que ingrese un número de posición (1–9). 
Si el usuario escribe un valor no válido (letras o símbolos), la función limpiará el
búfer de entrada y volverá a pedir el número.*/
int readMove(char player);

// 'switchPlayer' alterna el turno entre jugadores.
// Si el jugador actual es 'X', devolverá 'O', y viceversa.
char switchPlayer(char current);

