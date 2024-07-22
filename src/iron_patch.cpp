#include "iron_patch.hpp"

#include <iostream>
#include <cstdlib>

IronPatch::IronPatch() : remaining(rand() % 21 + 5) {};

sf::Vector2f IronPatch::getPosition() {
    return position;
}

void IronPatch::setPosition(sf::Vector2f position) {
    this->position = position;
}

int IronPatch::getRemaining() {
    return remaining;
}

void IronPatch::removeOne() {
    remaining--;
}
