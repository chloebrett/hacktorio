#pragma once

#include "spatial_index.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>
#include "player.hpp"
#include "environment.hpp"
#include "resource_patch.hpp"
#include "cursor.hpp"
#include "ui/gui.hpp"

using namespace std;

class Input {
    public:
    Input(
        sf::RenderWindow &window,
        Player &player,
        Cursor &cursor,
        Gui &gui,
        SpatialIndex &spatialIndex
    );
    void handleQueuedEvents();
    void handleOngoingEvents();

    private:
    sf::RenderWindow &window;
    Player &player;
    Cursor &cursor;
    Gui &gui;
    SpatialIndex &spatialIndex;
};
