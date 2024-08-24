#include "resource_patch.hpp"
#include "resource_patch_type.hpp"
#include "inventory_item_type.hpp"
#include "scene_node.hpp"
#include "SFML/Graphics.hpp"
#include "constants.hpp"

#include <iostream>
#include <cstdlib>

using namespace std;

std::map<ResourcePatchType, sf::Color> getResourcePatchColors()
{
    std::map<ResourcePatchType, sf::Color> resourcePatchColors;
    resourcePatchColors[ResourcePatchType::IRON] = sf::Color(80, 81, 84, 255);
    resourcePatchColors[ResourcePatchType::COAL] = sf::Color(23, 21, 16, 255);
    resourcePatchColors[ResourcePatchType::COPPER] = sf::Color(150, 104, 68, 255);
    resourcePatchColors[ResourcePatchType::STONE] = sf::Color(145, 145, 108, 255);
    resourcePatchColors[ResourcePatchType::WOOD] = sf::Color(84, 64, 48, 255);
    return resourcePatchColors;
}

ResourcePatch::ResourcePatch(sf::Vector2f position, ResourcePatchType resourcePatchType, int remaining) : resourcePatchType(resourcePatchType), remaining(remaining), SceneNode(
    /* position= */ position,
    /* size= */ sf::Vector2f(1 * GRID_SIZE, 1 * GRID_SIZE),
    /* onClick= */ []() {
        std::cout << "Resource patch clicked" << std::endl;
    },
    /* onRender= */ [this](
        SceneNode &node,
        sf::RenderWindow &window,
        sf::Vector2f absolutePos
    ) {
        if (this->getRemaining() > 0)
        {
            std::map<ResourcePatchType, sf::Color> resourcePatchColors = getResourcePatchColors();
            sf::RectangleShape resourcePatchRect;
            resourcePatchRect.setSize(size);
            resourcePatchRect.setPosition(absolutePos);
            resourcePatchRect.setFillColor(resourcePatchColors[this->getResourcePatchType()]);
            window.draw(resourcePatchRect);
        }
    }
) {}

float ResourcePatch::getRemaining()
{
    return remaining;
}

ResourcePatchType ResourcePatch::getResourcePatchType()
{
    return resourcePatchType;
}

InventoryItemType ResourcePatch::getInventoryItemType()
{
    switch (static_cast<int>(resourcePatchType))
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
