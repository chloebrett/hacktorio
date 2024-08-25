#pragma once

#include "container.hpp"
#include "cursor.hpp"
#include "config/constants.hpp"
#include <iostream>

using namespace std;

Cursor::Cursor(/*sf::RenderWindow &window*/) : /*window(window),*/ itemStack(nullptr) {}

ItemStack* Cursor::getItemStack() {
    return itemStack;
}

/*sf::Vector2i Cursor::getMousePosition() {
    return sf::Mouse::getPosition(window);
}*/

void Cursor::setItemStack(ItemStack *itemStack) {
    this->itemStack = itemStack;
}
