using namespace std;

#include <iostream>
#include "game.hpp"
#include "player.hpp"
#include "media.hpp"

int main()
{
    Game game;
    game.start();
    std::cout << "Game started" << std::endl;

    return 0;
}
