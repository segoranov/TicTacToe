#include "TicTacToe.h"
#include <iostream>
#include <string>

bool doesUserWantToPlayAnotherGame()
{
    std::cout << "\nIf you want to player another game, type 'y': ";
    std::string userInput;
    std::getline(std::cin, userInput);
    return userInput == "y";
}

int main()
{
    std::cout << "Welcome to TicTacToe!\n";
    do
    {
        TicTacToe().playGame();
    } while (doesUserWantToPlayAnotherGame());
    std::cout << "\nThank you for playing TicTacToe! Goobye...\n";
}
