#pragma once

#include <SFML/Graphics.hpp>
#include "scene_node.hpp"
#include "electric_mining_drill.hpp"
#include "entity_placement_manager.hpp"
#include "config/inventory_item_type.hpp"
#include <iostream>
#include "ui/gui.hpp"
#include "wooden_chest.hpp"

using namespace std;

EntityPlacementManager::EntityPlacementManager(SceneNode &rootSceneNode, Gui &gui) : rootSceneNode(rootSceneNode), gui(gui) {
};

bool EntityPlacementManager::tryPlaceEntity(InventoryItemType inventoryItemType, sf::Vector2f position) {
    switch (inventoryItemType) {
        case InventoryItemType::WOODEN_CHEST:
            rootSceneNode.addChild(new WoodenChest(gui, /* capacity= */ 10, position));
            return true;
        case InventoryItemType::ELECTRIC_MINING_DRILL:
            rootSceneNode.addChild(new ElectricMiningDrill(position));
            return true;
        default:
            return false;
    }
}
