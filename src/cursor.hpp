#pragma once

#include "container.hpp"
#include "item_stack.hpp"
#include <SFML/Graphics.hpp>

class Cursor {
    public:
    Cursor(/*sf::RenderWindow &window*/);
    ItemStack* getItemStack();
    void setItemStack(ItemStack *itemStack);
    // sf::Vector2i getMousePosition();

    private:
    ItemStack* itemStack;
    // sf::RenderWindow &window;
};
