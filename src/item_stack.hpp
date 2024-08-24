#pragma once

#include "inventory_item_type.hpp"

class ItemStack {
    public:
    ItemStack(InventoryItemType type, int amount);
    int getAmount();
    InventoryItemType getType();

    private:
    int amount;
    InventoryItemType type;
};
