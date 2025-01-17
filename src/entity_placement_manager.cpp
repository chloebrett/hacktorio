#include "entity_placement_manager.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "config/inventory_item_type.hpp"
#include "config/recipe_configuration.hpp"
#include "entity/electric_mining_drill.hpp"
#include "entity/lab.hpp"
#include "entity/stone_furnace.hpp"
#include "entity/transport_belt.hpp"
#include "entity/wooden_chest.hpp"
#include "rotation.hpp"
#include "scene_node.hpp"
#include "spatial_index.hpp"
#include "ui/gui.hpp"

EntityPlacementManager::EntityPlacementManager(SceneNode &rootSceneNode,
                                               RecipeConfiguration &recipeConfiguration, Gui &gui,
                                               SpatialIndex &spatialIndex)
    : rootSceneNode(rootSceneNode),
      recipeConfiguration(recipeConfiguration),
      gui(gui),
      spatialIndex(spatialIndex) {};

bool EntityPlacementManager::tryPlaceEntity(InventoryItemType inventoryItemType,
                                            sf::Vector2f position, Rotation rotation) {
    switch (inventoryItemType) {
        case InventoryItemType::WOODEN_CHEST:
            rootSceneNode.addChild(new WoodenChest(gui, /* capacity= */ 10, position));
            return true;
        case InventoryItemType::ELECTRIC_MINING_DRILL:
            rootSceneNode.addChild(new ElectricMiningDrill(position));
            return true;
        case InventoryItemType::STONE_FURNACE:
            rootSceneNode.addChild(new StoneFurnace(gui, recipeConfiguration, position));
            return true;
        case InventoryItemType::LAB:
            rootSceneNode.addChild(new Lab(gui, position));
            return true;
        case InventoryItemType::TRANSPORT_BELT:
            rootSceneNode.addChild(new TransportBelt(gui, spatialIndex, rotation, position));
            return true;
        default:
            return false;
    }
}
