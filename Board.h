#include <array> //Libreria estandar que permite el uso de vectores

// Define un alias de tipo (type alias) llamado 'BoardGrid'. Que equivale a una matriz 3x3 para el tablero del juego
using BoardGrid = std::array<std::array<char, 3>, 3>;

struct Board {

    BoardGrid cells{};


    // Inicializa el tablero llenando las celdas con los caracteres '1' a '9'.
    void init();

    // Dibuja el tablero en la consola (usando cout). Y 'const' porque no modifica el contenido del tablero.
    void draw() const;

    bool isValidMove(int pos) const;

    // Marca la posición indicada con el símbolo del jugador X o O
    void makeMove(int pos, char player);

    // Comprueba si el jugador actual ha ganado la partida. Analiza filas, columnas y diagonales.
    bool checkWin(char player) const;

    // Verifica si el tablero está lleno y hay empate
    bool checkDraw() const;

    static bool positionToRC(int pos, int& r, int& c);
};
