#pragma once

#include "spatial_index.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>
#include "player.hpp"
#include "chest.hpp"
#include "environment.hpp"
#include "resource_patch.hpp"
#include "cursor.hpp"

using namespace std;

class Input {
    public:
    Input(
        sf::RenderWindow &window,
        Player &player,
        Cursor &cursor,
        SpatialIndex &spatialIndex
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
    Cursor &cursor;
    SpatialIndex &spatialIndex;
    bool isInventoryOpen;
    int selectedInventoryItemIndex;
    int selectedOtherItemIndex;
};
