// Incluye el encabezado (header) donde se declara la estructura Board.
// Esto permite implementar aqu� todas sus funciones.
#include "Board.h"

// Incluye la librer�a est�ndar de C++ para manejar entrada/salida por consola (cout, endl, etc.)
#include <iostream>

// Especifica que usaremos directamente cout y endl del espacio de nombres std,
// para no escribir std::cout ni std::endl en cada l�nea.
using std::cout;
using std::endl;

// ===============================
//  Inicializaci�n del tablero
// ===============================
void Board::init() {
    char v = '1'; // Comienza con el car�cter '1', que ser� el primer n�mero en el tablero.

    // Recorre las 3 filas del tablero
    for (int r = 0; r < 3; ++r)
        // Recorre las 3 columnas del tablero
        for (int c = 0; c < 3; ++c)
            // Asigna a cada celda el n�mero correspondiente ('1'...'9')
            cells[r][c] = v++;
}

// ===============================
//  Dibuja el tablero en consola
// ===============================
void Board::draw() const {
    cout << "\n"; // Salto de l�nea antes del tablero

    // Recorre cada fila del tablero
    for (int r = 0; r < 3; ++r) {
        // Muestra las tres celdas de la fila separadas por barras verticales
        cout << " " << cells[r][0] << " | " << cells[r][1] << " | " << cells[r][2] << "\n";

        // Dibuja una l�nea divisoria entre filas (excepto despu�s de la �ltima)
        if (r < 2) cout << "---+---+---\n";
    }

    cout << "\n"; // Salto de l�nea al final del tablero
}

// =============================================
// Convierte una posici�n (1�9) a fila y columna
// =============================================
bool Board::positionToRC(int pos, int& r, int& c) {
    // Si el n�mero ingresado no est� entre 1 y 9, la posici�n es inv�lida
    if (pos < 1 || pos > 9) return false;

    pos -= 1;      // Ajusta el rango (0�8) para c�lculos con divisi�n y m�dulo
    r = pos / 3;   // La fila es el cociente de dividir por 3
    c = pos % 3;   // La columna es el residuo de dividir por 3
    return true;   // Devuelve true si la conversi�n fue v�lida
}

// =============================================
// Verifica si una posici�n est� disponible
// =============================================
bool Board::isValidMove(int pos) const {
    int r, c; // Variables para guardar fila y columna

    // Si la conversi�n falla (posici�n inv�lida), devuelve false
    if (!positionToRC(pos, r, c)) return false;

    // La posici�n es v�lida solo si no tiene una 'X' o una 'O'
    return (cells[r][c] != 'X' && cells[r][c] != 'O');
}

// =============================================
// Realiza un movimiento en el tablero
// =============================================
void Board::makeMove(int pos, char player) {
    int r, c; // Variables para fila y columna

    // Si la posici�n es v�lida, coloca el s�mbolo del jugador ('X' o 'O')
    if (positionToRC(pos, r, c))
        cells[r][c] = player;
}

// =============================================
// Funci�n auxiliar: compara tres caracteres
// =============================================

// Funci�n est�tica (solo visible en este archivo .cpp)
// Devuelve true si los tres caracteres son iguales (por ejemplo, 'X','X','X')
static bool eq3(char a, char b, char c) {
    return (a == b && b == c);
}

// =============================================
// Comprueba si el jugador actual gan�
// =============================================
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

    // Si no hay tres iguales en ninguna direcci�n, no hay ganador
    return false;
}

// =============================================
// Comprueba si el tablero est� lleno (empate)
// =============================================
bool Board::checkDraw() const {
    // Recorre todas las celdas del tablero
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c)
            // Si encuentra alguna celda que no sea X u O, todav�a no hay empate
            if (cells[r][c] != 'X' && cells[r][c] != 'O')
                return false;

    // Si todas las casillas est�n ocupadas, hay empate
    return true;
}
