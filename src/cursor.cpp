#pragma once

#include "container.hpp"
#include "cursor.hpp"
#include "constants.hpp"

Cursor::Cursor() : itemStack(nullptr) {}

ItemStack* Cursor::getItemStack() {
    return itemStack;
}

void Cursor::setItemStack(ItemStack *itemStack) {
    this->itemStack = itemStack;
}
