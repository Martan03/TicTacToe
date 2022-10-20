#pragma once
#include <iostream>
#include <string>
#include "board.hpp"

namespace tictactoe
{
    class Game
    {
    public:
        Game(Board board);

        /// @brief main game loop
        void GameLoop();
    private:
        Board board;
        bool started;

        /// @brief Draws board
        void DrawBoard();

        /// @brief Draws player with color
        /// @param plr player number
        void DrawPlayer(int plr);

        /// @brief Checks if game was win
        /// @return true if won or draw, else false
        bool CheckWin();
    };
}