#include "TicTacToeBoard.h"
#include <iostream>
#include <algorithm>

const Symbol PLAYER_1_SYMBOL = 'O';
const Symbol PLAYER_2_SYMBOL = 'X';
const Symbol EMPTY_SPACE_SYMBOL = ' ';

TicTacToeBoard::TicTacToeBoard()
{
    init();
}

Symbol TicTacToeBoard::get(int x, int y) const
{
    return matrix[x][y];
}

void TicTacToeBoard::set(int x, int y, char symbol)
{
    matrix[x][y] = symbol;
}

GameStatus TicTacToeBoard::getGameStatus() const
{
    return gameStatus;
}

void TicTacToeBoard::makeMove(Coordinates playerMove)
{
    if (gameStatus != GameStatus::GAME_NOT_OVER)
    {
        return;
    }

    if (player1ToMove_)
    {
        set(playerMove.x, playerMove.y, PLAYER_1_SYMBOL);
        player1ToMove_ = false;
    }
    else
    {
        set(playerMove.x, playerMove.y, PLAYER_2_SYMBOL);
        player1ToMove_ = true;
    }

    setGameStatus();
}

bool TicTacToeBoard::player1ToMove() const
{
    return player1ToMove_;
}

void TicTacToeBoard::init()
{
    for (int i = 0; i < 3; i++)
    {
        matrix.push_back(Row{EMPTY_SPACE_SYMBOL, EMPTY_SPACE_SYMBOL, EMPTY_SPACE_SYMBOL});
    }
}

void TicTacToeBoard::setGameStatus()
{
    checkRows();
    checkColumns();
    checkDiagonals();
    if (gameStatus != GameStatus::GAME_NOT_OVER) return;
    if (allMovesArePlayed())
    {
        gameStatus = GameStatus::DRAW;
    }
}

void TicTacToeBoard::checkRows()
{
    auto allEqual = [](const Row &row) { return std::equal(row.begin() + 1, row.end(), row.begin()); };
    for (const auto &row : matrix)
    {
        if (allEqual(row) && row[0] != EMPTY_SPACE_SYMBOL)
        {
            gameStatus = (row[0] == PLAYER_1_SYMBOL ? GameStatus::PLAYER_1_WON : GameStatus::PLAYER_2_WON);
        }
    }
}

void TicTacToeBoard::checkColumns()
{
    for (int column = 0; column < 3; column++)
    {
        checkColumn(column);
    }
}

void TicTacToeBoard::checkColumn(int column)
{
    if (matrix[0][column] == matrix[1][column] &&
        matrix[1][column] == matrix[2][column] &&
        matrix[0][column] != EMPTY_SPACE_SYMBOL)
    {
        gameStatus = (matrix[0][column] == PLAYER_1_SYMBOL ? GameStatus::PLAYER_1_WON : GameStatus::PLAYER_2_WON);
    }
}

void TicTacToeBoard::checkDiagonals()
{
    // main diagonal
    if (matrix[0][0] == matrix[1][1] &&
        matrix[1][1] == matrix[2][2] &&
        matrix[1][1] != EMPTY_SPACE_SYMBOL)
    {
        gameStatus = (matrix[1][1] == PLAYER_1_SYMBOL ? GameStatus::PLAYER_1_WON : GameStatus::PLAYER_2_WON);
    }

    // secondary diagonal
    if (matrix[0][2] == matrix[1][1] &&
        matrix[1][1] == matrix[2][0] &&
        matrix[1][1] != EMPTY_SPACE_SYMBOL)
    {
        gameStatus = (matrix[1][1] == PLAYER_1_SYMBOL ? GameStatus::PLAYER_1_WON : GameStatus::PLAYER_2_WON);
    }
}

bool TicTacToeBoard::allMovesArePlayed() const
{
    for (const auto &row : matrix)
    {
        for (const auto &symbol : row)
        {
            if (symbol == EMPTY_SPACE_SYMBOL)
            {
                return false;
            }
        }
    }
    return true;
}
