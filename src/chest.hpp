#pragma once

#include "container.hpp"
#include "scene_node.hpp"

class Chest : public SceneNode, public Container {
    public:
    Chest(int capacity, sf::Vector2f position);
    int getCapacity();
    int getFreeSpace();

    private:
    int capacity;
};
