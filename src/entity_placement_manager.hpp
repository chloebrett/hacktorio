#pragma once

#include <SFML/Graphics.hpp>
#include "config/inventory_item_type.hpp"
#include "scene_node.hpp"
#include "entity_manager.hpp"
#include "ui/gui.hpp"

class EntityPlacementManager : public EntityManager {
    public:
    EntityPlacementManager(SceneNode &rootSceneNode, Gui &gui);
    bool tryPlaceEntity(InventoryItemType inventoryItemType, sf::Vector2f position);

    private:
    SceneNode &rootSceneNode;
    Gui &gui;
};
