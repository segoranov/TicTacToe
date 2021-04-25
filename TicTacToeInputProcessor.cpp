
#include "TicTacToeInputProcessor.h"
#include "TicTacToeBoard.h"
#include <iostream>
#include <string>

TicTacToeInputProcessor::TicTacToeInputProcessor(TicTacToeBoard *board) : board{board} {}

Coordinates TicTacToeInputProcessor::getNextPlayerMove()
{
    std::string playerInput;
    do
    {
        std::cin.clear();
        std::cout << (board->player1ToMove() ? "\nPlayer 1" : "\nPlayer 2") << " to move (choose cell number between 1 and 9)>> ";
        std::getline(std::cin, playerInput);
        if (!playerInputIsValid(playerInput))
        {
            std::cout << "Choose an empty cell number between 1 and 9!\n";
        }
    } while (!std::cin || !playerInputIsValid(playerInput));
    std::cout << '\n';
    return calculcateCoordinatesFromPlayerInput(std::stoi(playerInput));
}

bool TicTacToeInputProcessor::playerInputIsValid(const std::string &playerInput) const
{
    int playerInputNum;
    try
    {
        playerInputNum = std::stoi(playerInput);
    }
    catch (...)
    {
        return false;
    }

    if (playerInputNum < 1 || playerInputNum > 9)
    {
        return false;
    }

    auto coordinates = TicTacToeInputProcessor::calculcateCoordinatesFromPlayerInput(playerInputNum);
    return board->get(coordinates.x, coordinates.y) == EMPTY_SPACE_SYMBOL;
}

Coordinates TicTacToeInputProcessor::calculcateCoordinatesFromPlayerInput(int playerInput)
{
    if (playerInput < 0 || playerInput > 9)
    {
        throw "Invalid player input, cannot calculate coordinates.";
    }

    const int x = (playerInput - 1) / 3;
    const int y = (playerInput - 1) % 3;
    return {x, y};
}
