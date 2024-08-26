#pragma once

#include "container.hpp"
#include "item_stack.hpp"
#include <SFML/Graphics.hpp>
#include "rotation.hpp"

class Cursor {
    public:
    Cursor();
    ItemStack* getItemStack();
    void setItemStack(ItemStack *itemStack);
    void rotateClockwise();
    void rotateAntiClockwise();
    Rotation getRotation();

    private:
    ItemStack* itemStack;
    Rotation rotation;
};
