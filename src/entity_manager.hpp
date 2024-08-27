#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "config/inventory_item_type.hpp"

/** Mostly exists right now to fix a cyclic dep. TODO: rethink */
class EntityManager {
   public:
    virtual bool tryPlaceEntity(InventoryItemType inventoryItemType, sf::Vector2i position) {
        // Implementation goes here
        std::cout << "EntityManager::tryPlaceEntity" << std::endl;
        return false;
    }
};
