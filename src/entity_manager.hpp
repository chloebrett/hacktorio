#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "config/inventory_item_type.hpp"

using namespace std;

/** Mostly exists right now to fix a cyclic dep. TODO: rethink */
class EntityManager {
   public:
    virtual bool tryPlaceEntity(InventoryItemType inventoryItemType, sf::Vector2i position) {
        // Implementation goes here
        cout << "EntityManager::tryPlaceEntity" << endl;
        return false;
    }
};
