#pragma once

#include "container.hpp"
#include "scene_node.hpp"
#include "gui.hpp"

class Chest : public SceneNode, public Container {
    public:
    Chest(Gui &gui, int capacity, sf::Vector2f position);
    int getCapacity();
    int getFreeSpace();

    private:
    int capacity;
    Gui &gui;
};
