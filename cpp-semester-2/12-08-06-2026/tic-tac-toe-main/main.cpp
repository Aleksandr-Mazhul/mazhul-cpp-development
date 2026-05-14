#include <iostream>
#include <stdexcept>
#include <utility>

#include "Game.h"
#include "HumanPlayer.h"
#include "BotPlayer.h"

int main() {
    std::cout << "Tic-Tac-Toe skeleton scenario\n";

    /*try {
        HumanPlayer playerX("Player 1", 'X');
        HumanPlayer playerO("Player 2", 'O');
        Game game(std::move(playerX), std::move(playerO),3);
        game.run();
    }
    catch (const std::logic_error& e) {
        std::cout << "Caught stub: " << e.what() << '\n';
        std::cout << "Implement the method and run again.\n";
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << '\n';
    }*/
    try {
        HumanPlayer playerX("Player 1", 'X');
        BotPlayer playerO("Player 2", 'O');
        Game game(std::move(playerX), std::move(playerO), 3);//?????????????? проблема с ссылками
        game.run();
    }
    catch (const std::logic_error& e) {
        std::cout << "Caught stub: " << e.what() << '\n';
        std::cout << "Implement the method and run again.\n";
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << '\n';
    }

    return 0;
}
