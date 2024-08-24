#pragma once

#include "container.hpp"
#include "scene_node.hpp"
#include "player.hpp"
#include "chest.hpp"

class InventoryRight : public SceneNode {
    public:
    InventoryRight(Chest &chest);

    private:
    Chest &chest;
};
