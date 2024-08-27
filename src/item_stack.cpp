#pragma once

#include "item_stack.hpp"

#include "config/inventory_item_type.hpp"

/** Class should be immutable! Don't pass around references/pointers. */
ItemStack::ItemStack(InventoryItemType type, int amount) : type(type), amount(amount) {}

int ItemStack::getAmount() { return amount; }

InventoryItemType ItemStack::getType() { return type; }
