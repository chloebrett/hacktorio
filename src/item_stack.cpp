#pragma once

#include "inventory_item_type.hpp"
#include "item_stack.hpp"

ItemStack::ItemStack(InventoryItemType type, int amount) : type(type), amount(amount) {}

int ItemStack::getAmount() {
    return amount;
}

InventoryItemType ItemStack::getType() {
    return type;
}
