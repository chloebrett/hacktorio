#pragma once

#include "container.hpp"
#include "item_stack.hpp"

class Cursor {
    public:
    Cursor();
    ItemStack* getItemStack();
    void setItemStack(ItemStack *itemStack);

    private:
    ItemStack* itemStack;
};
