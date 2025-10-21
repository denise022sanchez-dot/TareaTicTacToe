// Incluye la librería estándar <array>, que permite usar arreglos (vectores) de tamaño fijo en C++.
// Aquí se usará para representar el tablero 3x3 del juego.
#include <array>

// Define un alias de tipo (type alias) llamado 'BoardGrid'.
// Este alias representa una matriz de 3x3 de caracteres (char).
// std::array<std::array<char, 3>, 3> equivale a un tablero con 3 filas y 3 columnas.
using BoardGrid = std::array<std::array<char, 3>, 3>;

// =============================================================
//  Estructura principal: Board (tablero del juego)
// =============================================================
// La palabra clave 'struct' define una estructura, que es un tipo de dato
// que agrupa variables y funciones relacionadas bajo un mismo nombre.
struct Board {

    // 'cells' representa el tablero del juego como una matriz 3x3 de caracteres.
    // Cada posición almacenará un símbolo: 'X', 'O' o un número ('1'..'9').
    // Se inicializa vacía con llaves {}.
    BoardGrid cells{};

    // -------------------------------------------------------------
    // Funciones miembro del tablero (métodos)
    // -------------------------------------------------------------

    // Inicializa el tablero llenando las celdas con los caracteres '1' a '9'.
    // Esto sirve para mostrar las posiciones disponibles al inicio del juego.
    void init();

    // Dibuja el tablero en la consola (usando cout).
    // Es 'const' porque no modifica el contenido del tablero.
    void draw() const;

    // Verifica si una posición (1–9) está libre o ya ocupada.
    // Devuelve 'true' si la casilla aún no tiene una 'X' ni una 'O'.
    bool isValidMove(int pos) const;

    // Marca la posición indicada con el símbolo del jugador ('X' o 'O').
    void makeMove(int pos, char player);

    // Comprueba si el jugador actual ha ganado la partida.
    // Analiza filas, columnas y diagonales.
    bool checkWin(char player) const;

    // Verifica si el tablero está lleno y no hay ganador (empate).
    bool checkDraw() const;

    // Convierte una posición (1–9) en coordenadas de fila y columna.
    // Ejemplo: posición 5 → fila 1, columna 1 (centro del tablero).
    // Es 'static' porque no necesita un objeto Board para ejecutarse.
    static bool positionToRC(int pos, int& r, int& c);
    // ↑ 'int&' indica que los valores de r y c se devuelven por referencia.
};
