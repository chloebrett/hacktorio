#include "resource_patch.hpp"
#include "resource_patch_type.hpp"
#include "inventory_item_type.hpp"

#include <iostream>
#include <cstdlib>

void ResourcePatch::init(ResourcePatchType type, int amount)
{
    this->type = type;
    remaining = amount;
}

float ResourcePatch::getRemaining()
{
    return remaining;
}

ResourcePatchType ResourcePatch::getType()
{
    return type;
}

InventoryItemType ResourcePatch::getInventoryItemType()
{
    switch (static_cast<int>(type))
    {
    case static_cast<int>(ResourcePatchType::IRON):
        return InventoryItemType::IRON_ORE;
    case static_cast<int>(ResourcePatchType::COAL):
        return InventoryItemType::COAL;
    case static_cast<int>(ResourcePatchType::COPPER):
        return InventoryItemType::COPPER_ORE;
    case static_cast<int>(ResourcePatchType::STONE):
        return InventoryItemType::STONE;
    case static_cast<int>(ResourcePatchType::WOOD):
        return InventoryItemType::WOOD;
    }
}

bool ResourcePatch::mine(float amount)
{
    int remainingInt = std::floor(remaining);
    remaining -= amount;

    std::cout << "Remaining amount of resource: " + std::to_string(remaining) << std::endl;

    if (remaining < 0)
    {
        remaining = 0;
    }

    return remaining <= remainingInt;
}
