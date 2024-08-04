#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>
#include "player.hpp"
#include "chest.hpp"
#include "resource_patch.hpp"

using namespace std;

class Input {
    public:
    Input(
        sf::RenderWindow &window,
        Player &player,
        Chest &chest,
        vector<ResourcePatch*> &resourcePatches
    );
    void handleQueuedEvents();
    void handleOngoingEvents();
    bool getIsInventoryOpen();
    int getSelectedInventoryItemIndex();
    int getSelectedOtherItemIndex();

    private:
    sf::RenderWindow &window;
    Player &player;
    Chest &chest;
    vector<ResourcePatch*> &resourcePatches;
    bool isInventoryOpen;
    int selectedInventoryItemIndex;
    int selectedOtherItemIndex;
};
