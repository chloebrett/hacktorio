#include "player.hpp"

#include <iostream>

Player::Player() {
    position = sf::Vector2f(128.0f, 128.0f);
};

int Player::getMoveSpeed() {
    return 4;
}

float Player::getMiningSpeed() {
    return 3; // Units per second
}
