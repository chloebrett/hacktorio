#pragma once

#include <SFML/Graphics.hpp>
#include <functional>

#include "entity_placement_manager.hpp"
#include "scene_node.hpp"
#include "ui/gui.hpp"

class EmptySpace : public SceneNode {
   public:
    EmptySpace(sf::Vector2f pos, EntityPlacementManager &entityPlacementManager);
    bool canPlaceItem();

   private:
    EntityPlacementManager &entityPlacementManager;
};
