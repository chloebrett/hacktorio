#pragma once

#include "SFML/Graphics.hpp"
#include "config/inventory_item_type.hpp"
#include "container.hpp"
#include "cursor.hpp"
#include "scene_node.hpp"

class Player : public SceneNode, public Container {
   public:
    Player();
    int getMoveSpeed();
    float getMiningSpeed();
};
