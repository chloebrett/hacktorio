#pragma once

#include <SFML/Graphics.hpp>
#include "scene_node.hpp"
#include "electric_mining_drill.hpp"
#include "entity_placement_manager.hpp"
#include "config/inventory_item_type.hpp"
#include <iostream>

using namespace std;

EntityPlacementManager::EntityPlacementManager(SceneNode &rootSceneNode) : rootSceneNode(rootSceneNode) {
};

bool EntityPlacementManager::tryPlaceEntity(InventoryItemType inventoryItemType, sf::Vector2f position) {
    cout << "EntityPlacementManager::tryPlaceEntity" << endl;
    rootSceneNode.addChild(new ElectricMiningDrill(position));
    return true;
}
