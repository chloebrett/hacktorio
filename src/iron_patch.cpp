#include "iron_patch.hpp"

#include <iostream>
#include <cstdlib>

void IronPatch::init()
{
    remaining = rand() % 6 + 5; // 5-10 iron
}

float IronPatch::getRemaining()
{
    return remaining;
}

bool IronPatch::mine(float amount)
{
    int remainingInt = std::floor(remaining);
    remaining -= amount;

    std::cout << "Remaining iron: " + std::to_string(remaining) << std::endl;

    if (remaining < 0)
    {
        remaining = 0;
    }

    return remaining <= remainingInt;
}
