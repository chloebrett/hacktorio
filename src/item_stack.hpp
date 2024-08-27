#pragma once

#include "config/inventory_item_type.hpp"

struct ItemStack {
    InventoryItemType type;
    int count;
};
