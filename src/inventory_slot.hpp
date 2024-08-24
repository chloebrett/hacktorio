#pragma once

#include "container.hpp"
#include "scene_node.hpp"
#include "player.hpp"
#include "chest.hpp"

class InventorySlot : public SceneNode {
    public:
    InventorySlot(int row, int column, int index, Container &container);

    private:
    int row;
    int column;
    int index;
    Container &container;
};
