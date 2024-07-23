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
    std::shared_ptr<Player> player,
    std::shared_ptr<Chest> chest,
    shared_ptr<vector<shared_ptr<ResourcePatch> > > resourcePatches,
    std::shared_ptr<bool> isInventoryOpen,
    shared_ptr<int> selectedInventoryItemIndex,
    shared_ptr<int> selectedOtherItemIndex
    );
    void handleQueuedEvents();
    void handleOngoingEvents();

    private:
    sf::RenderWindow &window;
    std::shared_ptr<Player> player;
    std::shared_ptr<Chest> chest;
    shared_ptr<vector<shared_ptr<ResourcePatch> > > resourcePatches;
    std::shared_ptr<bool> isInventoryOpen;
    shared_ptr<int> selectedInventoryItemIndex;
    shared_ptr<int> selectedOtherItemIndex;
};
