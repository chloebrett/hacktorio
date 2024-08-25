#pragma once

#include "container.hpp"
#include "cursor.hpp"
#include "constants.hpp"
#include <iostream>

using namespace std;

Cursor::Cursor(EntityManager &entityManager) :
    entityManager(entityManager), itemStack(nullptr) {}

ItemStack* Cursor::getItemStack() {
    return itemStack;
}

void Cursor::setItemStack(ItemStack *itemStack) {
    this->itemStack = itemStack;
}

void Cursor::handleLeftClickOnEmptySpace(sf::Vector2i pos) {
    cout << "Cursor::handleLeftClickOnEmptySpace" << endl;
    if (itemStack != nullptr) {
        cout << "Cursor::handleLeftClickOnEmptySpace itemStack != null" << endl;
        bool success = entityManager.tryPlaceEntity(itemStack->getType(), pos);
        cout << "Cursor::handleLeftClickOnEmptySpace success: " << success << endl;
        if (success) {
            // TODO: memory leak
            this->itemStack = new ItemStack(itemStack->getType(), itemStack->getAmount() - 1);
        }
    }
}
