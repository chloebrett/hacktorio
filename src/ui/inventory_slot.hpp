#pragma once

#include "../scene_node.hpp"
#include "inventory_grid.hpp"

class InventorySlot : public SceneNode {
    public:
    InventorySlot(int row, int column, int index, InventoryGrid &grid);

    private:
    int row;
    int column;
    int index;
    InventoryGrid &grid;
};
