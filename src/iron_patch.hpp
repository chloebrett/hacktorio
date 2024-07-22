#pragma once

#include "SFML/Graphics.hpp"
#include "entity.hpp"

class IronPatch : public Entity
{
public:
    void init();
    float getRemaining();
    bool mine(float amount);

private:
    float remaining;
};
