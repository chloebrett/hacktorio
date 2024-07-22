#pragma once

#include "SFML/Graphics.hpp"
#include "entity.hpp"

class Player : public Entity {
    public:
    Player();
    int getMoveSpeed();
    float getMiningSpeed();
    int getIronCount();
    void addIron(int iron);

    private:
    int ironCount;
};
