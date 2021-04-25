#ifndef TIC_TAC_TOE
#define TIC_TAC_TOE

#include "TicTacToeBoard.h"
#include "TicTacToeBoardDrawer.h"
#include <memory>

class TicTacToe
{
public:
    TicTacToe();
    void playGame();

private:
    TicTacToeBoard board;
    TicTacToeInputProcessor inputProcessor;
    std::unique_ptr<TicTacToeBoardDrawer> boardDrawer = std::make_unique<TicTacToeBoardDrawerImpl>();
};

#endif
