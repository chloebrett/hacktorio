#pragma once

#include "../container.hpp"
#include "../entity.hpp"
#include "../scene_node.hpp"
#include "../ui/gui.hpp"

class WoodenChest : public Entity, public Container {
   public:
    WoodenChest(Gui &gui, int capacity, sf::Vector2f position);
    int getCapacity();
    int getFreeSpace();

   private:
    int capacity;
    Gui &gui;
};
