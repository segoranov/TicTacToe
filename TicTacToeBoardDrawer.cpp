#include "TicTacToeBoardDrawer.h"

void TicTacToeBoardDrawerImpl::draw(const TicTacToeBoard& board)
{
    std::cout << "|-----------|\n";
    for (int row = 0; row < 3; row++)
    {
        std::cout << "| ";
        for (int col = 0; col < 3; col++)
        {
            std::cout << board.get(row, col) << " | ";
        }
        std::cout << "\n|-----------|\n";
    }
}
