#include "transport_belt.hpp"

#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>
#include <vector>

#include "../config/constants.hpp"
#include "../config/game_resources.hpp"
#include "../container.hpp"
#include "../cursor.hpp"
#include "../entity.hpp"
#include "../rotation.hpp"
#include "../spatial_index.hpp"
#include "../ui/gui.hpp"
#include "wooden_chest.hpp"

TransportBelt::TransportBelt(Gui& gui, SpatialIndex& spatialIndex, Rotation rotation,
                             sf::Vector2f pos)
    : gui(gui),
      spatialIndex(spatialIndex),
      rotation(rotation),
      pos(pos),
      Entity(
          /* position= */
          pos,
          /* size= */ sf::Vector2f(GRID_SIZE, GRID_SIZE),
          /* onClick= */
          [this](Cursor& cursor) {
              std::cout << "Belt clicked" << std::endl;
              this->gui.showPanelForContainer(this);
          },
          /* onRender= */
          [this](SceneNode& node, sf::RenderWindow& window, sf::Vector2f absolutePos) {
              sf::Sprite sprite = *GameResources::getInstance().getSprite("entity-transport-belt");
              sprite.setPosition(absolutePos);
              sprite.setTextureRect(getImageMask());
              window.draw(sprite);
          }) {}

sf::IntRect TransportBelt::getImageMask() {
    switch (rotation) {
        case Rotation::UP:
            return sf::IntRect(15, 19 + 64 * 2, 34, 34);
        case Rotation::RIGHT:
            return sf::IntRect(15, 19, 34, 34);
        case Rotation::DOWN:
            return sf::IntRect(15, 19 + 64 * 3, 34, 34);
        case Rotation::LEFT:
            return sf::IntRect(15, 19 + 64, 34, 34);
    }
}

sf::Vector2f TransportBelt::getOutputPosition() {
    switch (rotation) {
        case Rotation::UP:
            return pos + sf::Vector2f(0, -GRID_SIZE);
        case Rotation::RIGHT:
            return pos + sf::Vector2f(GRID_SIZE, 0);
        case Rotation::DOWN:
            return pos + sf::Vector2f(0, GRID_SIZE);
        case Rotation::LEFT:
            return pos + sf::Vector2f(-GRID_SIZE, 0);
    }
}

Container* TransportBelt::getOutputContainer() {
    std::vector<SceneNode*> nodes = spatialIndex.nodesAt(sf::Vector2i(getOutputPosition()));
    for (SceneNode* node : nodes) {
        if (Container* container = dynamic_cast<Container*>(node)) {
            return container;
        }
    }
    return nullptr;
}

void TransportBelt::onTick() {
    Container* outputContainer = getOutputContainer();
    if (outputContainer != nullptr) {
        std::cout << "Output container found" << std::endl;
    } else {
        return;
    }

    transferItemTicksRemaining--;

    if (transferItemTicksRemaining <= 0) {
        ItemStack item = this->removeAnyItem(/* maxStackSize= */ 1);
        if (item.type != InventoryItemType::NONE) {
            outputContainer->addItem(item.type, item.count);
            outputContainer->updateItems();
        }
        transferItemTicksRemaining = 1 * FRAMES_PER_SECOND;  // 1 second
        // TODO: change to actual belt speed
    }
}
