#pragma once

#include <iostream>
#include "container.hpp"
#include "entity.hpp"
#include "chest.hpp"

Chest::Chest(int capacity) {
    this->capacity = capacity;
}

int Chest::getCapacity() {
    return capacity;
}

int Chest::getFreeSpace() {
    std::cout << "contents.size(): " << contents.size() << ", capacity: " << capacity << std::endl;
    return capacity - getTotalItemCount();
}
