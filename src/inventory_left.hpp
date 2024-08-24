#pragma once

#include "container.hpp"
#include "scene_node.hpp"
#include "player.hpp"
#include "chest.hpp"

class InventoryLeft : public SceneNode {
    public:
    InventoryLeft(Player &player);

    private:
    Player &player;
};
