#pragma once

#include <SFML/Graphics.hpp>
#include "inventory_item_type.hpp"
#include "scene_node.hpp"
#include "entity_manager.hpp"

class EntityPlacementManager : public EntityManager {
    public:
    EntityPlacementManager(SceneNode &rootSceneNode);
    bool tryPlaceEntity(InventoryItemType inventoryItemType, sf::Vector2i position);

    private:
    SceneNode &rootSceneNode;
};
