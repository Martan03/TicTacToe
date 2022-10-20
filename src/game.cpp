#include "game.hpp"

namespace tictactoe
{
    Game::Game(Board board):
        board(board),
        started(true)
    {}

    void Game::GameLoop()
    {
        int x, y;
        std::string msg;
        while (started)
        {
            // Draw
            DrawBoard();
            DrawPlayer(board.GetPlayer());
            std::cout << " turn" << std::endl;

            // scans coordinates
            std::cin >> x >> y;

            // when coordinates are out of boundaries
            if (x <= 0 || x > board.GetWidth() ||
                y <= 0 || y > board.GetHeight())
            {
                std::cin.clear();
                std::cin >> msg;

                if (msg == "quit")
                    started = false;
            }
            else if (board.Place(x, y))
            {
                started = !CheckWin();
            }
        }
    }

    void Game::DrawBoard()
    {
        // set cursor to top and clear screen
        std::cout << "\033[H\033[2J   ";

        for (int i = 0; i < board.GetWidth(); ++i)
            std::cout << (i + 1 < 10 ? "  " : " ") << i + 1;
        std::cout << std::endl;

        for (int i = 0; i < board.GetHeight(); ++i)
        {
            for (int j = -1; j < board.GetWidth(); ++j)
            {
                if (j == -1)
                    std::cout << (i + 1 < 10 ? "  " : " ") << i + 1;
                else
                    DrawPlayer(board.GetTile(j, i));
            }
            std::cout << std::endl;
        }
    }

    void Game::DrawPlayer(int plr)
    {
        switch (plr)
        {
            case 0:
                std::cout << "  .";
                break;
            case 1:
                std::cout << "  \u001b[0;92mX\u001b[0m";
                break;
            case 2:
                std::cout << "  \u001b[0;91mO\u001b[0m";
                break;
            default:
                std::cout << "  ?";
        }
    }

    bool Game::CheckWin()
    {
        int win = board.CheckWin();
        std::cout << win << std::endl;

        if (win == 0)
        {
            board.NextPlayer();
            return false;
        }
        else if (win == -1)
        {
            DrawBoard();
            std::cout << "It's a draw" << std::endl;

            return true;
        }
        else
        {
            DrawBoard();
            DrawPlayer(board.GetPlayer());
            std::cout << " won!" << std::endl;

            return true;
        }    
    }
}