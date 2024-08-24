#pragma once

#include "container.hpp"
#include "scene_node.hpp"
#include "player.hpp"
#include "chest.hpp"

class Inventory : public SceneNode {
    public:
    Inventory(Player &player, Chest &chest);

    private:
    Player &player;
    Chest &chest;
};
