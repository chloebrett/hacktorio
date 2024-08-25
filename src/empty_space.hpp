#pragma once

#include "scene_node.hpp"
#include "ui/gui.hpp"
#include <functional>
#include <SFML/Graphics.hpp>
#include "entity_placement_manager.hpp"

class EmptySpace : public SceneNode {
    public:
    EmptySpace(sf::Vector2f pos, EntityPlacementManager &entityPlacementManager);
    bool canPlaceItem();

    private:
    EntityPlacementManager &entityPlacementManager;
};
