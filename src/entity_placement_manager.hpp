#pragma once

#include <SFML/Graphics.hpp>

#include "config/inventory_item_type.hpp"
#include "config/recipe_configuration.hpp"
#include "entity_manager.hpp"
#include "rotation.hpp"
#include "scene_node.hpp"
#include "spatial_index.hpp"
#include "ui/gui.hpp"

class EntityPlacementManager : public EntityManager {
   public:
    EntityPlacementManager(SceneNode &rootSceneNode, RecipeConfiguration &recipeConfiguration,
                           Gui &gui, SpatialIndex &spatialIndex);
    bool tryPlaceEntity(InventoryItemType inventoryItemType, sf::Vector2f position,
                        Rotation rotation);

   private:
    SceneNode &rootSceneNode;
    RecipeConfiguration &recipeConfiguration;
    Gui &gui;
    SpatialIndex &spatialIndex;
};
