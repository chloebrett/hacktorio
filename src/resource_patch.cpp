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
    switch (type)
    {
    case ResourcePatchType::RPT_IRON:
        return InventoryItemType::IIT_IRON_ORE;
    case ResourcePatchType::RPT_COAL:
        return InventoryItemType::IIT_COAL;
    case ResourcePatchType::RPT_COPPER:
        return InventoryItemType::IIT_COPPER_ORE;
    case ResourcePatchType::RPT_STONE:
        return InventoryItemType::IIT_STONE;
    case ResourcePatchType::RPT_WOOD:
        return InventoryItemType::IIT_WOOD;
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
