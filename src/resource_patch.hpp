#pragma once

#include "resource_patch_type.hpp"
#include "inventory_item_type.hpp"
#include "SFML/Graphics.hpp"
#include "entity.hpp"

class ResourcePatch : public Entity
{
public:
    void init(ResourcePatchType type);
    float getRemaining();
    bool mine(float amount);
    ResourcePatchType getType();
    InventoryItemType getInventoryItemType();

private:
    float remaining;
    ResourcePatchType type;
};
