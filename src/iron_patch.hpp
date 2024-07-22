#pragma once

#include "SFML/Graphics.hpp"

class IronPatch {
    public:
    IronPatch();
    int getRemaining();
    void removeOne();
    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f position);

    private:
    int remaining;
    sf::Vector2f position;
};
