#include <iostream>
#include <string.h>
#include "board.hpp"
#include "game.hpp"

// Definitions of colors
#define DY "\e[33m"
#define DG "\e[92m"
#define DW "\e[97m"
#define DR "\e[91m"
#define DBB "\e[90m"
#define DRS "\e[0m"

/// @brief Prints help
void Help();

/// @brief Prints message to stderr
/// @param msg message to be printed
void PrintErr(std::string msg);

/// @brief Converts string to number, exits if error occures
/// @param s string to be converted to number
/// @return converted number
int CheckNumber(std::string s);

int main(int argc, char **argv)
{
    int width = 3, height = 3, win = 3;
    while (*++argv)
    {
        std::string arg = *argv;

        if (arg == "-s" || arg == "--size")
        {
            width = CheckNumber(*++argv);
            height = CheckNumber(*++argv);

            if (width <= 0 || height <= 0)
                PrintErr("size must be positive");
        }
        else if (arg == "-w" || arg == "--win")
        {
            win = CheckNumber(*++argv);

            if (win <= 0)
                PrintErr("win length must be positive");
        }
        else if (arg == "-h" || arg == "--help")
        {
            Help();
            return 0;
        }
        else
        {
            PrintErr(
                "invalid usage. Type " DY "tictactoe -h" DRS " to display help"
            );
        }
    }

    tictactoe::Board board {width, height, win, 2};
    tictactoe::Game game {board};
    game.GameLoop();

    return 0;
}

void Help()
{
    std::cout << "Welcome to help for \e[92m\e[9mTicTacToe\e[0m by ";
    // Prints name with color gradient
    std::string name = "Martan03";
    int r = 0, g = 220;
    for (int i = 0; i < name.length(); ++i)
        std::cout << "\e[38;2;" << r + i * 25 << ";"
                  << g - i * 20 << ";255m" << name[i];
    std::cout << std::endl;

    // Prints usage
    std::cout <<
        "\n" DG "Usage: " DW "tictactoe " DBB "[flags]\n\n" DRS
        DG "Flags:\n" DRS
        DY "  -h --help\n" DRS "    Displays help\n\n"
        DY "  -s --size " DW "[width] [height]\n" DRS
        "    Sets board's width and height\n\n"
        DY "  -w --win " DW "[win length]\n" DRS
        "    Sets win length"
    << std::endl;
}

void PrintErr(std::string msg)
{
    std::cerr << DR "Error: " DRS << msg << std::endl;
    exit(1);
}

int CheckNumber(std::string s)
{
    try
    {
        return stoi(s);
    }
    catch (std::invalid_argument)
    {
        PrintErr("invalid argument");
    }
    return 0;
}
