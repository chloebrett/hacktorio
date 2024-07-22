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

int Player::getInventoryCount(InventoryItemType item) {
    if (inventory.find(item) == inventory.end()) {
        inventory[item] = 0;
    }
    return inventory[item];
}

void Player::addInventoryItem(InventoryItemType item, int amount) {
    if (inventory.find(item) == inventory.end()) {
        inventory[item] = 0;
    }
    inventory[item] += amount;
}

void Player::removeInventoryItem(InventoryItemType item, int amount) {
    if (inventory.find(item) == inventory.end()) {
        inventory[item] = 0;
    }
    inventory[item] -= amount;
    if (inventory[item] < 0) {
        inventory[item] = 0;
    }
}
