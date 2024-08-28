#pragma once

#include <iostream>
#include <map>
#include <vector>

#include "config/inventory_item_type.hpp"
#include "item_stack.hpp"

class Container {
   public:
    Container();
    std::map<InventoryItemType, int> getContents();
    int getItemCount(InventoryItemType item);
    int getTotalItemCount();
    void addItem(InventoryItemType item, int amount);
    void removeItem(InventoryItemType item, int amount);
    std::vector<ItemStack>& getItems();
    void updateItems();
    ItemStack removeAnyItem(int maxStackSize);

   protected:
    std::map<InventoryItemType, int>* contents;
    std::vector<ItemStack> items;
};
