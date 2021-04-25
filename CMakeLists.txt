cmake_minimum_required(VERSION 3.10)

project(TicTacToe)

add_executable(TicTacToe
    main.cpp
    TicTacToeInputProcessor.cpp
    TicTacToe.cpp
    TicTacToeBoard.cpp
    TicTacToeBoardDrawer.cpp)
