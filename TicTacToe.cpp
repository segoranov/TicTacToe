#include "TicTacToe.h"
#include <iostream>

TicTacToe::TicTacToe()
    : inputProcessor{&board}
{
}

void TicTacToe::playGame()
{
    while (board.getGameStatus() == GameStatus::GAME_NOT_OVER)
    {
        boardDrawer->draw(board);
        board.makeMove(inputProcessor.getNextPlayerMove());
    }

    boardDrawer->draw(board);
    std::cout << '\n';

    if (board.getGameStatus() == GameStatus::DRAW)
    {
        std::cout << "Draw!\n";
    }
    else
    {
        std::cout << "Winner: Player "
                  << (board.getGameStatus() == GameStatus::PLAYER_1_WON ? "1" : "2")
                  << ". Congratulations!\n";
    }
}
