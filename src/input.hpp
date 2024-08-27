#pragma once

#include <iostream>
#include <memory>

#include "SFML/Graphics.hpp"
#include "cursor.hpp"
#include "environment.hpp"
#include "player.hpp"
#include "resource_patch.hpp"
#include "spatial_index.hpp"
#include "ui/gui.hpp"

using namespace std;

class Input {
   public:
    Input(sf::RenderWindow &window, Player &player, Cursor &cursor, Gui &gui,
          SpatialIndex &spatialIndex);
    void handleQueuedEvents();
    void handleOngoingEvents();

   private:
    sf::RenderWindow &window;
    Player &player;
    Cursor &cursor;
    Gui &gui;
    SpatialIndex &spatialIndex;
};
