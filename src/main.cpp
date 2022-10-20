#include <iostream>
#include <string.h>
#include "board.hpp"
#include "game.hpp"

void Help();
bool IsNumber(std::string s);

int main(int argc, char *argv[])
{
    if (argc == 2 && strcmp(argv[1], "help") == 0)
    {
        Help();
        return 0;
    }
    switch (argc)
    {
        case 1:
        {
            tictactoe::Board board {3, 3, 3, 2};
            tictactoe::Game game {board};
            game.GameLoop();
            break;
        }
        case 2:
            std::cout << "\u001b[31mInvalid usage:\u001b[0m 2 parameters necessary" << std::endl;
            break;
        case 3:
        {
            if (!IsNumber(argv[1]) || !IsNumber(argv[2]))
            {
                std::cout << "\u001b[31mInvalid usage:\u001b[0m coordinates must be numbers" << std::endl;
                break;
            }
            tictactoe::Board board {atoi(argv[1]), atoi(argv[2]), 5, 2};
            tictactoe::Game game {board};
            game.GameLoop();
            break;
        }
        default:
            std::cout << "\u001b[31mInvalid usage:\u001b[0m help to show help" << std::endl;
            break;
    }
    return 0;
}

void Help()
{
    std::cout << "\u001b[35mTicTacToe\u001b[0m help!" << std::endl;
    std::cout << "\n\u001b[33mUsage:\u001b[0m" << std::endl;
    std::cout << "  \u001b[33mtictactoe\u001b[0m <\u001b[33;1mwidth\u001b[0m> <\u001b[33;1mheight\u001b[0m>" << std::endl;
    std::cout << "    starts a game, width and height are optional" << std::endl;
}

bool IsNumber(std::string s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
