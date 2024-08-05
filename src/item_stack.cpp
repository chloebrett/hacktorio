#pragma once

#include "inventory_item_type.hpp"
#include "item_stack.hpp"

ItemStack::ItemStack(int amount, InventoryItemType type) {
    this->amount = amount;
    this->type = type;
}

int ItemStack::getAmount() {
    return amount;
}

InventoryItemType ItemStack::getType() {
    return type;
}
