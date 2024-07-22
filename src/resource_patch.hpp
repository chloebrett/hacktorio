#pragma once

#include "resource_patch_type.hpp"
#include "SFML/Graphics.hpp"
#include "entity.hpp"

class ResourcePatch : public Entity
{
public:
    void init(ResourcePatchType type);
    float getRemaining();
    bool mine(float amount);
    ResourcePatchType getType();

private:
    float remaining;
    ResourcePatchType type;
};
