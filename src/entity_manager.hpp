#pragma once

#include <SFML/Graphics.hpp>
#include "config/inventory_item_type.hpp"
#include <iostream>

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
