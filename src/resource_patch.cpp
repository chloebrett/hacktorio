#include "resource_patch.hpp"

#include <cstdlib>
#include <iostream>

#include "SFML/Graphics.hpp"
#include "config/constants.hpp"
#include "config/inventory_item_type.hpp"
#include "config/resource_patch_type.hpp"
#include "cursor.hpp"
#include "player.hpp"
#include "scene_node.hpp"

std::map<ResourcePatchType, sf::Color> getResourcePatchColors() {
    std::map<ResourcePatchType, sf::Color> resourcePatchColors;
    resourcePatchColors[ResourcePatchType::IRON] = sf::Color(80, 81, 84, 255);
    resourcePatchColors[ResourcePatchType::COAL] = sf::Color(23, 21, 16, 255);
    resourcePatchColors[ResourcePatchType::COPPER] = sf::Color(150, 104, 68, 255);
    resourcePatchColors[ResourcePatchType::STONE] = sf::Color(145, 145, 108, 255);
    resourcePatchColors[ResourcePatchType::WOOD] = sf::Color(84, 64, 48, 255);
    return resourcePatchColors;
}

ResourcePatch::ResourcePatch(Player *player, sf::Vector2f position,
                             ResourcePatchType resourcePatchType, int remaining)
    : player(player),
      resourcePatchType(resourcePatchType),
      remaining(remaining),
      SceneNode(
          /* position= */
          position,
          /* size= */ sf::Vector2f(1 * GRID_SIZE, 1 * GRID_SIZE),
          /* onClick= */ nullptr,
          /* onRender= */
          [this](SceneNode &node, sf::RenderWindow &window, sf::Vector2f absolutePos) {
              if (this->getRemaining() > 0) {
                  std::map<ResourcePatchType, sf::Color> resourcePatchColors =
                      getResourcePatchColors();
                  sf::RectangleShape resourcePatchRect;
                  resourcePatchRect.setSize(size);
                  resourcePatchRect.setPosition(absolutePos);
                  resourcePatchRect.setFillColor(resourcePatchColors[this->getResourcePatchType()]);
                  window.draw(resourcePatchRect);
              }
          }) {}

void ResourcePatch::handleMine() {
    if (this->getRemaining() > 0) {
        bool didMine = this->mine(this->player->getMiningSpeed() / FRAMES_PER_SECOND);
        if (didMine) {
            InventoryItemType type = this->getInventoryItemType();
            this->player->addItem(type, 1);
            this->player->updateItems();
        }
    }
}

float ResourcePatch::getRemaining() { return remaining; }

ResourcePatchType ResourcePatch::getResourcePatchType() { return resourcePatchType; }

InventoryItemType ResourcePatch::getInventoryItemType() {
    switch (static_cast<int>(resourcePatchType)) {
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

bool ResourcePatch::mine(float amount) {
    int remainingInt = std::floor(remaining);
    remaining -= amount;

    if (remaining < 0) {
        remaining = 0;
    }

    return remaining <= remainingInt;
}
