#include "board.hpp"

namespace tictactoe
{
    Board::Board(int sizeX, int sizeY, int toWin, int playerCount):
        sizeX(sizeX),
        sizeY(sizeY),
        player(1),
        toWin(toWin),
        playerCount(playerCount),
        board(sizeY, std::vector<int>(sizeX, 0))
    {}

    bool Board::Place(int x, int y)
    {
        // when tile on coordinates is not empty
        if (board[y - 1][x - 1] != 0)
            return false;
        board[y - 1][x - 1] = player;
        return true;
    }

    int Board::CheckWin()
    {
        int win = -1;
        for (int i = 0; i < sizeY; ++i)
        {
            for (int j = 0; j < sizeX; ++j)
            {
                // When there's zero on board, game is still running
                if (board[i][j] == 0)
                    win = 0;
                else if (CheckWinRow(j, i) ||
                    CheckWinCol(j, i) ||
                    CheckWinDiagUp(j, i) ||
                    CheckWinDiagDown(j, i))
                    return board[i][j];
            }
        }
        return win;
    }

    bool Board::CheckWinRow(int x, int y)
    {
        int plr = board[y][x];
        for (int i = 0; i < toWin; ++i)
        {
            if (y + i >= sizeY)
                return false;
            if (plr != board[y + i][x])
                return false;
        }
        return true;
    }

    bool Board::CheckWinCol(int x, int y)
    {
        int plr = board[y][x];
        for (int i = 0; i < toWin; ++i)
        {
            if (x + i >= sizeX)
                return false;
            if (plr != board[y][x + i])
                return false;
        }
        return true;
    }

    bool Board::CheckWinDiagDown(int x, int y)
    {
        int plr = board[y][x];
        for (int i = 0; i < toWin; ++i)
        {
            if (y + i >= sizeY || x + i >= sizeX)
                return false;
            if (plr != board[y + i][x + i])
                return false;
        }
        return true;
    }

    bool Board::CheckWinDiagUp(int x, int y)
    {
        int plr = board[y][x];
        for (int i = 0; i < toWin; ++i)
        {
            if (y - i < 0 || x + i >= sizeX)
                return false;
            if (plr != board[y - i][x + i])
                return false;
        }
        return true;
    }

    void Board::NextPlayer()
    {
        player = player % playerCount + 1;
    }

    int Board::GetWidth() { return sizeX; }
    int Board::GetHeight() { return sizeY; }
    int Board::GetPlayer() { return player; }
    int Board::GetTile(int x, int y) { return board[y][x]; }
}