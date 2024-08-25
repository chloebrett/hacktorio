#pragma once

#include <map>
#include "config/inventory_item_type.hpp"
#include <vector>
#include "item_stack.hpp"
#include <iostream>

using namespace std;

class Container {
    // TODO: maybe move this to a C++ file?
    public:
    Container() {
        this->contents = map<InventoryItemType, int>();
    }
    map<InventoryItemType, int> getContents() {
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
    vector<ItemStack> &getItems() {
        return items;
    }

    void updateItems() {
        vector<ItemStack> items;
        for (auto const& [item, count] : contents) {
            if (count > 0) {
                items.push_back(ItemStack(item, count));
            }
        }
        sort(items.begin(), items.end(), [](ItemStack a, ItemStack b) {
            return a.getAmount() < b.getAmount();
        });
        this->items = items;
    }

    protected:
    map<InventoryItemType, int> contents;
    vector<ItemStack> items;
};
