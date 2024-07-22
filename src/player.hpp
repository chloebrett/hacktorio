#pragma once

#include "inventory_item_type.hpp"
#include "SFML/Graphics.hpp"
#include "entity.hpp"
using namespace std;

class Player : public Entity {
    public:
    Player();
    int getMoveSpeed();
    float getMiningSpeed();
    int getInventoryCount(InventoryItemType item);
    void addInventoryItem(InventoryItemType item, int amount);
    void removeInventoryItem(InventoryItemType item, int amount);

    private:
    map <InventoryItemType, int> inventory;
};
