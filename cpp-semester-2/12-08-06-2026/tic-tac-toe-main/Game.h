#pragma once

#include <array>
#include <utility>

#include "Board.h"
#include "HumanPlayer.h"

class Game
{
public:
    Game(std::unique_ptr<Player> first, std::unique_ptr<Player> second, int boardSize)
        : board(boardSize)
    {
        players[0] = std::move(first);
        players[1] = std::move(second);
    }


    void run()
    {
        board.reset();
        board.print();

        int current = 0;
        while (true)
        {
            const Player& player = *players[current];

            auto [row, col] = player.readMove(board);

            if (!board.placeMark(row, col, player.getMark()))
            {
                std::cout << "This cell is already taken! Try again.\n";
                continue;
            }

            board.print();

            if (board.hasWinner(player.getMark()))
            {
                std::cout << "\n******************************\n";
                std::cout << "*" << player.getName() << " wins!*\n";
                std::cout << "******************************\n\n";
                break;
            }

            if (board.isFull())
            {
                std::cout << "\n******************************\n";
                std::cout << "It's a draw! \n";
                std::cout << "******************************\n\n";
                break;
            }

            current = 1 - current;
        }
    }

private:
    Board board;
    std::array<std::unique_ptr<Player>, 2> players;
};
