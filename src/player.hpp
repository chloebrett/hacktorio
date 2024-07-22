#pragma once

#include "container.hpp"
#include "inventory_item_type.hpp"
#include "SFML/Graphics.hpp"
#include "entity.hpp"
using namespace std;

class Player : public Entity, public Container {
    public:
    Player();
    int getMoveSpeed();
    float getMiningSpeed();
};
