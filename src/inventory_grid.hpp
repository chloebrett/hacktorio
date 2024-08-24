#pragma once

#include "container.hpp"
#include "scene_node.hpp"
#include "player.hpp"
#include "chest.hpp"
#include <SFML/Graphics.hpp>

class InventoryGrid : public SceneNode {
    public:
    InventoryGrid(sf::Vector2f pos);
};
