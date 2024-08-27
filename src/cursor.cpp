#include "cursor.hpp"

#include <iostream>

#include "config/constants.hpp"
#include "container.hpp"
#include "rotation.hpp"

using namespace std;

Cursor::Cursor(/*sf::RenderWindow &window*/)
    : /*window(window),*/ itemStack(nullptr), rotation(Rotation::RIGHT) {}

ItemStack* Cursor::getItemStack() { return itemStack; }

/*sf::Vector2i Cursor::getMousePosition() {
    return sf::Mouse::getPosition(window);
}*/

void Cursor::setItemStack(ItemStack* itemStack) { this->itemStack = itemStack; }

void Cursor::rotateClockwise() {
    rotation = static_cast<Rotation>((static_cast<int>(rotation) + 1) % 4);
}

void Cursor::rotateAntiClockwise() {
    rotation = static_cast<Rotation>((static_cast<int>(rotation) + 3) % 4);
}

Rotation Cursor::getRotation() { return rotation; }
