#include "player.hpp"

#include <iostream>

Player::Player() : ironCount(0), position(sf::Vector2f(128.0f, 128.0f)) {};

sf::Vector2f Player::getPosition() {
    return position;
}

void Player::setPosition(sf::Vector2f position) {
    this->position = position;
}

int Player::getMoveSpeed() {
    return 4;
}

int Player::getIronCount() {
    return ironCount;
}

void Player::addIron(int iron) {
    ironCount += iron;
}
