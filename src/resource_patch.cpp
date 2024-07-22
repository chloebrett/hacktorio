#include "resource_patch.hpp"
#include "resource_patch_type.hpp"

#include <iostream>
#include <cstdlib>

void ResourcePatch::init(ResourcePatchType type)
{
    this->type = type;
    remaining = rand() % 6 + 5; // 5-10 units
}

float ResourcePatch::getRemaining()
{
    return remaining;
}

ResourcePatchType ResourcePatch::getType()
{
    return type;
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
