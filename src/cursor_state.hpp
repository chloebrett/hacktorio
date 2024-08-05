#pragma once

#include "item_stack.hpp"

class CursorState {
    public:
    CursorState();
    ItemStack* getItemStack();
    void setItemStack(ItemStack* itemStack);

    private:
    ItemStack* itemStack;
};
