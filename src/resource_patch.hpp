#pragma once

#include "resource_patch_type.hpp"
#include "inventory_item_type.hpp"
#include "SFML/Graphics.hpp"
#include "scene_node.hpp"

class ResourcePatch : public SceneNode
{
public:
    ResourcePatch(sf::Vector2f position);
    void init(ResourcePatchType type, int amount);
    float getRemaining();
    bool mine(float amount);
    ResourcePatchType getType();
    InventoryItemType getInventoryItemType();

private:
    float remaining;
    ResourcePatchType type;
};
