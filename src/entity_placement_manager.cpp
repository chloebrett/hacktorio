#pragma once

#include <SFML/Graphics.hpp>
#include "scene_node.hpp"
#include "electric_mining_drill.hpp"
#include "entity_placement_manager.hpp"
#include "inventory_item_type.hpp"

EntityPlacementManager::EntityPlacementManager(SceneNode &rootSceneNode) : rootSceneNode(rootSceneNode) {
};

bool EntityPlacementManager::tryPlaceEntity(InventoryItemType inventoryItemType, sf::Vector2i position) {
    cout << "EntityPlacementManager::tryPlaceEntity" << endl;
    rootSceneNode.addChild(new ElectricMiningDrill(sf::Vector2f(position)));
    return true;
}
