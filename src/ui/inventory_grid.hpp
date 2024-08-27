#pragma once

#include <SFML/Graphics.hpp>

#include "../container.hpp"
#include "../scene_node.hpp"

class InventoryGrid : public SceneNode {
   public:
    InventoryGrid(sf::Vector2f pos, Container *container);
    void setContainer(Container *container);
    Container *getContainer();

   private:
    Container *container;
};
