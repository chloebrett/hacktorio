#pragma once

#include <iostream>
#include <map>
#include <vector>

#include "config/inventory_item_type.hpp"
#include "item_stack.hpp"

class Container {
    // TODO: maybe move this to a C++ file?
   public:
    Container() {
        std::map<InventoryItemType, int>* contents = new std::map<InventoryItemType, int>();
        this->contents = contents;
    }
    std::map<InventoryItemType, int> getContents() { return *contents; }
    int getItemCount(InventoryItemType item) {
        if (contents->find(item) == contents->end()) {
            (*contents)[item] = 0;
        }
        return (*contents)[item];
    }
    int getTotalItemCount() {
        int total = 0;
        for (auto const& [item, count] : *contents) {
            total += count;
        }
        return total;
    }
    void addItem(InventoryItemType item, int amount) {
        std::cout << "Adding " << amount << " " << static_cast<int>(item) << std::endl;
        if (contents == nullptr) {
            std::cout << "Contents is null" << std::endl;
        } else {
            std::cout << "Contents is not null" << std::endl;
        }
        std::cout << contents->size() << std::endl;
        if (contents->find(item) == contents->end()) {
            std::cout << "T" << std::endl;
            (*contents)[item] = 0;
        }
        std::cout << "After: " << (*contents)[item] << std::endl;
        (*contents)[item] += amount;
    }
    void removeItem(InventoryItemType item, int amount) {
        if (contents->find(item) == contents->end()) {
            (*contents)[item] = 0;
        }
        (*contents)[item] -= amount;
        if ((*contents)[item] < 0) {
            (*contents)[item] = 0;
        }
    }
    std::vector<ItemStack>& getItems() { return items; }

    void updateItems() {
        std::vector<ItemStack> items;
        for (auto const& [item, count] : *contents) {
            if (count > 0) {
                ItemStack itemStack;
                itemStack.type = item;
                itemStack.count = count;
                items.push_back(itemStack);
            }
        }
        sort(items.begin(), items.end(),
             [](ItemStack a, ItemStack b) { return a.count < b.count; });
        this->items = items;
    }

    /** Picks any item and removes it. Not necessarily random but may be random. */
    ItemStack removeAnyItem(int maxStackSize) {
        for (auto const& [item, count] : *contents) {
            if (count > 0) {
                int amount = std::min(count, maxStackSize);
                (*contents)[item] -= amount;
                if ((*contents)[item] == 0) {
                    contents->erase(item);
                }
                ItemStack itemStack;
                itemStack.type = item;
                itemStack.count = amount;
                return itemStack;
            }
        }
        ItemStack itemStack;
        itemStack.type = InventoryItemType::NONE;
        itemStack.count = 0;
        return itemStack;
    }

   protected:
    std::map<InventoryItemType, int>* contents;
    std::vector<ItemStack> items;
};
