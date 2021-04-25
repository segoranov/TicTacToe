#ifndef TTT_BOARD_H
#define TTT_BOARD_H

#include "TicTacToeInputProcessor.h"
#include <vector>

using Symbol = char;
using Row = std::vector<Symbol>;

extern const Symbol PLAYER_1_SYMBOL;
extern const Symbol PLAYER_2_SYMBOL;
extern const Symbol EMPTY_SPACE_SYMBOL;

enum class GameStatus
{
    PLAYER_1_WON,
    PLAYER_2_WON,
    DRAW,
    GAME_NOT_OVER
};

struct Coordinates
{
    int x;
    int y;
};

class TicTacToeBoard
{
public:
    TicTacToeBoard();

    Symbol get(int x, int y) const;

    void set(int x, int y, char symbol);

    GameStatus getGameStatus() const;

    void makeMove(Coordinates coordinates);

    bool player1ToMove() const;

private:
    void init();
    void setGameStatus();
    void checkRows();
    void checkColumns();
    void checkColumn(int column);
    void checkDiagonals();
    bool allMovesArePlayed() const;

    using Matrix = std::vector<Row>;
    Matrix matrix;
    bool player1ToMove_ = true;
    GameStatus gameStatus = GameStatus::GAME_NOT_OVER;
};

#endif
