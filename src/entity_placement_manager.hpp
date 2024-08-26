#pragma once

#include <SFML/Graphics.hpp>
#include "config/inventory_item_type.hpp"
#include "scene_node.hpp"
#include "entity_manager.hpp"
#include "ui/gui.hpp"
#include "config/recipe_configuration.hpp"
#include "spatial_index.hpp"
#include "rotation.hpp"

class EntityPlacementManager : public EntityManager {
    public:
    EntityPlacementManager(
        SceneNode &rootSceneNode, RecipeConfiguration &recipeConfiguration, Gui &gui, SpatialIndex &spatialIndex
    );
    bool tryPlaceEntity(InventoryItemType inventoryItemType, sf::Vector2f position, Rotation rotation);

    private:
    SceneNode &rootSceneNode;
    RecipeConfiguration &recipeConfiguration;
    Gui &gui;
    SpatialIndex &spatialIndex;
};
