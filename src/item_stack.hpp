#pragma once

#include "inventory_item_type.hpp"

class ItemStack {
    public:
    ItemStack(int amount, InventoryItemType type);
    int getAmount();
    InventoryItemType getType();

    private:
    int amount;
    InventoryItemType type;
};
