#ifndef TTT_INPUT_PROCESSOR_H
#define TTT_INPUT_PROCESSOR_H

#include <string>

class TicTacToeBoard;
struct Coordinates;

class TicTacToeInputProcessor
{
public:
    TicTacToeInputProcessor(TicTacToeBoard *board);

    Coordinates getNextPlayerMove();

private:
    bool playerInputIsValid(const std::string &playerInput) const;
    static Coordinates calculcateCoordinatesFromPlayerInput(int playerInput);

    TicTacToeBoard *board;
};

#endif
