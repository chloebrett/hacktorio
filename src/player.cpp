#include "player.hpp"

#include <iostream>

Player::Player() : ironCount(0) {
    position = sf::Vector2f(128.0f, 128.0f);
};

int Player::getMoveSpeed() {
    return 4;
}

float Player::getMiningSpeed() {
    return 3; // Units per second
}

int Player::getIronCount() {
    return ironCount;
}

void Player::addIron(int iron) {
    ironCount += iron;
    std::cout << "Player now has " << ironCount << " iron" << std::endl;
}
