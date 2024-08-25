#pragma once

#include "container.hpp"
#include "config/inventory_item_type.hpp"
#include "SFML/Graphics.hpp"
#include "cursor.hpp"
#include "scene_node.hpp"
using namespace std;

class Player : public SceneNode, public Container {
    public:
    Player();
    int getMoveSpeed();
    float getMiningSpeed();
};
