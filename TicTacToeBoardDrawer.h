#ifndef TTT_BOARD_DRAWER
#define TTT_BOARD_DRAWER

#include "TicTacToeBoard.h"
#include <iostream>

class TicTacToeBoardDrawer
{
public:
    virtual void draw(const TicTacToeBoard &board) = 0;
};

class TicTacToeBoardDrawerImpl : public TicTacToeBoardDrawer
{
public:
    virtual void draw(const TicTacToeBoard &board) override;
};

#endif
