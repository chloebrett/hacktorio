#pragma once

#include "container.hpp"
#include "entity.hpp"

class Chest : public Entity, public Container {
    public:
    Chest(int capacity);
    int getCapacity();
    int getFreeSpace();

    private:
    int capacity;
};
