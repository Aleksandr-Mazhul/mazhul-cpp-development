#pragma once

#include <stdexcept>
#include <string>
#include <utility>
#include <ctime>

#include "Board.h"
#include "Player.h"

class BotPlayer: public Player{
public:
    BotPlayer(std::string name, char mark) :Player (std::move(name), mark) {
    }

    std::pair<int, int> readMove(const Board& board) const override {
        while (true) {
            int randomRow = std::rand() % board.getSize() + 1;
            int randomColumn = std::rand() % board.getSize() + 1;
            if (board.isCellEmpty(randomRow,randomColumn)) {
                return { randomRow,randomColumn };
            }
        }
    }

};
