#pragma once

#include "SFML/Graphics.hpp"

class Entity {
    public:
    sf::Vector2f getPosition() {
        return position;
    }
    void setPosition(sf::Vector2f position) {
        this->position = position;
    }

    protected:
    sf::Vector2f position;
};
