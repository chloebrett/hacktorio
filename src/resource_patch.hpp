#pragma once

#include "SFML/Graphics.hpp"
#include "config/inventory_item_type.hpp"
#include "config/resource_patch_type.hpp"
#include "player.hpp"
#include "scene_node.hpp"

class ResourcePatch : public SceneNode {
   public:
    ResourcePatch(Player *player, sf::Vector2f position, ResourcePatchType resourcePatchType,
                  int amount);
    float getRemaining();
    bool mine(float amount);
    ResourcePatchType getResourcePatchType();
    InventoryItemType getInventoryItemType();
    void handleMine();

   private:
    float remaining;
    ResourcePatchType resourcePatchType;
    Player *player;
};
