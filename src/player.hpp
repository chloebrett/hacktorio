#pragma once

#include "SFML/Graphics.hpp"

class Player {
    public:
    Player();
    int getMoveSpeed();
    int getIronCount();
    void addIron(int iron);
    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f position);

    private:
    int ironCount;
    sf::Vector2f position;
};
