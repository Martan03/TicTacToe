#pragma once
#include <iostream>
#include <vector>

namespace tictactoe
{
    class Board
    {
    public:
        Board(int sizeX, int sizeY, int toWin, int playerCount);

        /// @brief Place current player to the coordinates
        /// @param x x coordinate
        /// @param y y coordinate
        /// @return true on success, else false
        bool Place(int x, int y);

        /// @brief Checks win
        /// @return -1 - draw, 0 - playing, player number - win
        int CheckWin();

        /// @brief Sets player to the next player on turn
        void NextPlayer();

        /// @brief Board width getter
        /// @return board width (sizeX)
        int GetWidth();

        /// @brief Board height getter
        /// @return board height (sizeY)
        int GetHeight();

        /// @brief Current player getter
        /// @return current player
        int GetPlayer();

        /// @brief Getter for tile in board
        /// @param x x coordinate
        /// @param y y coordinate
        /// @return value of board on coordinates
        int GetTile(int x, int y);
    private:
        int sizeX, sizeY, player, toWin;
        int playerCount;
        std::vector<std::vector<int>> board;
        bool CheckWinRow(int x, int y);
        bool CheckWinCol(int x, int y);
        bool CheckWinDiagUp(int x, int y);
        bool CheckWinDiagDown(int x, int y);
    };
}