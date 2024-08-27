#pragma once

#include <iostream>
#include <map>
#include <vector>

#include "config/inventory_item_type.hpp"
#include "item_stack.hpp"

using namespace std;

class Container {
    // TODO: maybe move this to a C++ file?
   public:
    Container() {
        map<InventoryItemType, int>* contents = new map<InventoryItemType, int>();
        this->contents = contents;
    }
    map<InventoryItemType, int> getContents() { return *contents; }
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
        cout << "Adding " << amount << " " << static_cast<int>(item) << endl;
        if (contents == nullptr) {
            cout << "Contents is null" << endl;
        } else {
            cout << "Contents is not null" << endl;
        }
        cout << contents->size() << endl;
        if (contents->find(item) == contents->end()) {
            cout << "T" << endl;
            (*contents)[item] = 0;
        }
        cout << "After: " << (*contents)[item] << endl;
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
    vector<ItemStack>& getItems() { return items; }

    void updateItems() {
        vector<ItemStack> items;
        for (auto const& [item, count] : *contents) {
            if (count > 0) {
                items.push_back(ItemStack(item, count));
            }
        }
        sort(items.begin(), items.end(),
             [](ItemStack a, ItemStack b) { return a.getAmount() < b.getAmount(); });
        this->items = items;
    }

    /** Picks any item and removes it. Not necessarily random but may be random. */
    ItemStack* removeAnyItem(int maxStackSize) {
        for (auto const& [item, count] : *contents) {
            if (count > 0) {
                int amount = min(count, maxStackSize);
                (*contents)[item] -= amount;
                if ((*contents)[item] == 0) {
                    contents->erase(item);
                }
                return new ItemStack(item, amount);
            }
        }
        return nullptr;
    }

   protected:
    map<InventoryItemType, int>* contents;
    vector<ItemStack> items;
};
