#pragma once

#include <map>
#include "inventory_item_type.hpp"

class Container {
    // TODO: maybe move this to a C++ file? (and likewise for Entity)
    public:
    std::map<InventoryItemType, int> getContents() {
        return contents;
    }
    int getItemCount(InventoryItemType item) {
        if (contents.find(item) == contents.end()) {
            contents[item] = 0;
        }
        return contents[item];
    }
    int getTotalItemCount() {
        int total = 0;
        for (auto const& [item, count] : contents) {
            total += count;
        }
        return total;
    }
    void addItem(InventoryItemType item, int amount) {
        if (contents.find(item) == contents.end()) {
            contents[item] = 0;
        }
        contents[item] += amount;
    }
    void removeItem(InventoryItemType item, int amount) {
        if (contents.find(item) == contents.end()) {
            contents[item] = 0;
        }
        contents[item] -= amount;
        if (contents[item] < 0) {
            contents[item] = 0;
        }
    }

    protected:
    std::map<InventoryItemType, int> contents;
};
