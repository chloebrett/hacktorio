#pragma once

#include "item_stack.hpp"
#include "cursor_state.hpp"
#include <cstddef>

CursorState::CursorState() {
    this->itemStack = nullptr;
}

ItemStack* CursorState::getItemStack() {
    return itemStack;
}

void CursorState::setItemStack(ItemStack* itemStack) {
    this->itemStack = itemStack;
}
