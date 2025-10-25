// Incluye el encabezado (header) donde se declara la estructura Board. Que permite implementar aquí todas sus funciones.
#include "Board.h"
#include <iostream>

// Especifica que usaremos directamente cout y endl del espacio de nombres std, para no escribir std::cout ni std::endl en cada línea.
using std::cout;
using std::endl;

//TABLERO
void Board::init() {
    char v = '1'; // Comienza con el carácter '1', que será el primer número en el tablero.

    // Recorre las 3 filas del tablero
    for (int r = 0; r < 3; ++r)
        // Recorre las 3 columnas del tablero
        for (int c = 0; c < 3; ++c)
            // Asigna a cada celda el número correspondiente ('1'...'9')
            cells[r][c] = v++;
}

//Para mostrar el tablero en consola
void Board::draw() const {
    cout << "\n";

    // Recorre cada fila del tablero
    for (int r = 0; r < 3; ++r) {
        // Muestra las tres celdas de la fila separadas por barras verticales
        cout << " " << cells[r][0] << " | " << cells[r][1] << " | " << cells[r][2] << "\n";
        if (r < 2) cout << "---+---+---\n";
    }

    cout << "\n"; // Salto de línea al final del tablero
}

//Convierte posiciones 1-9 a fila y columna
bool Board::positionToRC(int pos, int& r, int& c) {
    // Si el número ingresado no está entre 1 y 9, la posición es inválida
    if (pos < 1 || pos > 9) return false;

    pos -= 1;      
    r = pos / 3;   
    c = pos % 3;   
    return true;  
}

//Validacion para posiciones disponibles
bool Board::isValidMove(int pos) const {
    int r, c; // Variables para guardar fila y columna

    // Si la conversión falla (posición inválida), devuelve false
    if (!positionToRC(pos, r, c)) return false;

    // La posición es válida solo si no tiene una 'X' o una 'O'
    return (cells[r][c] != 'X' && cells[r][c] != 'O');
}

//Movimientos del jugador
void Board::makeMove(int pos, char player) {
    int r, c; // Variables para fila y columna

    // Si la posición es válida, coloca el símbolo del jugador X o O
    if (positionToRC(pos, r, c))
        cells[r][c] = player;
}

// Devuelve true si los tres caracteres son iguales (por ejemplo, 'X','X','X')
static bool eq3(char a, char b, char c) {
    return (a == b && b == c);
}

//Para identificar al ganador
bool Board::checkWin(char p) const {
    // Revisa las 3 filas
    for (int r = 0; r < 3; ++r)
        // Si los tres valores de la fila son iguales al jugador, hay victoria
        if (eq3(cells[r][0], cells[r][1], cells[r][2]) && cells[r][0] == p)
            return true;

    // Revisa las 3 columnas
    for (int c = 0; c < 3; ++c)
        // Si los tres valores de la columna son iguales al jugador, hay victoria
        if (eq3(cells[0][c], cells[1][c], cells[2][c]) && cells[0][c] == p)
            return true;

    // Revisa la diagonal principal (de arriba izquierda a abajo derecha)
    if (eq3(cells[0][0], cells[1][1], cells[2][2]) && cells[0][0] == p)
        return true;

    // Revisa la diagonal secundaria (de arriba derecha a abajo izquierda)
    if (eq3(cells[0][2], cells[1][1], cells[2][0]) && cells[0][2] == p)
        return true;

    // Si no hay tres iguales en ninguna dirección, no hay ganador
    return false;
}

//Comprueba que haya o no empate
bool Board::checkDraw() const {
    // Recorre todas las celdas del tablero
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c)
            // Si encuentra alguna celda que no sea X u O, todavía no hay empate
            if (cells[r][c] != 'X' && cells[r][c] != 'O')
                return false;

    // Si todas las casillas están ocupadas, hay empate
    return true;
}
