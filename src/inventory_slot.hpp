#pragma once

#include "container.hpp"
#include "scene_node.hpp"
#include "player.hpp"
#include "chest.hpp"

class InventorySlot : public SceneNode {
    public:
    InventorySlot(int row, int column, ItemStack *itemStack);

    private:
    ItemStack *itemStack;
    int row;
    int column;
};
