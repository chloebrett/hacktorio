#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>
#include "player.hpp"
#include "chest.hpp"
#include "environment.hpp"
#include "resource_patch.hpp"

using namespace std;

class Input {
    public:
    Input(
        sf::RenderWindow &window,
        Player &player,
        Chest &chest,
        Environment &environment
    );
    void handleQueuedEvents();
    void handleOngoingEvents();
    bool getIsInventoryOpen();
    int getSelectedInventoryItemIndex();
    int getSelectedOtherItemIndex();
    sf::Vector2i getMousePosition();

    private:
    sf::RenderWindow &window;
    Player &player;
    Chest &chest;
    Environment &environment;
    bool isInventoryOpen;
    int selectedInventoryItemIndex;
    int selectedOtherItemIndex;
};
