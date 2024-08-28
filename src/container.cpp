#pragma once

#include "container.hpp"

#include <iostream>
#include <map>
#include <vector>

#include "config/inventory_item_type.hpp"
#include "item_stack.hpp"

Container::Container() {
    std::map<InventoryItemType, int>* contents = new std::map<InventoryItemType, int>();
    this->contents = contents;
}

std::map<InventoryItemType, int> Container::getContents() { return *contents; }

int Container::getItemCount(InventoryItemType item) {
    if (contents->find(item) == contents->end()) {
        (*contents)[item] = 0;
    }
    return (*contents)[item];
}

int Container::getTotalItemCount() {
    int total = 0;
    for (auto const& [item, count] : *contents) {
        total += count;
    }
    return total;
}

void Container::addItem(InventoryItemType item, int amount) {
    if (contents->find(item) == contents->end()) {
        (*contents)[item] = 0;
    }
    (*contents)[item] += amount;
}

void Container::removeItem(InventoryItemType item, int amount) {
    if (contents->find(item) == contents->end()) {
        (*contents)[item] = 0;
    }
    (*contents)[item] -= amount;
    if ((*contents)[item] < 0) {
        (*contents)[item] = 0;
    }
}

std::vector<ItemStack>& Container::getItems() { return items; }

void Container::updateItems() {
    std::vector<ItemStack> items;
    for (auto const& [item, count] : *contents) {
        if (count > 0) {
            ItemStack itemStack;
            itemStack.type = item;
            itemStack.count = count;
            items.push_back(itemStack);
        }
    }
    sort(items.begin(), items.end(), [](ItemStack a, ItemStack b) { return a.count < b.count; });
    this->items = items;
}

/** Picks any item and removes it. Not necessarily random but may be random. */
ItemStack Container::removeAnyItem(int maxStackSize) {
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
