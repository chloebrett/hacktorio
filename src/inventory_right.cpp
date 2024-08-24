#pragma once

#include <iostream>
#include "container.hpp"
#include "inventory.hpp"
#include "scene_node.hpp"
#include "SFML/Graphics.hpp"
#include <functional>
#include <vector>
#include "constants.hpp"
#include "renderer.hpp"
#include "constants.hpp"
#include "SFML/Graphics.hpp"
#include "player.hpp"
#include "resource_patch.hpp"
#include "inventory_left.hpp"
#include "game.hpp"
#include "resource_patch.hpp"
#include "inventory_item_type.hpp"
#include "resource_patch_type.hpp"
#include <iostream>
#include <memory>
#include "chest.hpp"
#include "item_stack.hpp"
#include <vector>
#include "cursor_state.hpp"
#include "inventory_right.hpp"

InventoryRight::InventoryRight(Chest &chest) : chest(chest), SceneNode(
    /* position= */ sf::Vector2f(INVENTORY_WIDTH + INVENTORY_PADDING * 2, INVENTORY_PADDING),
    /* size= */ sf::Vector2f(INVENTORY_WIDTH, INVENTORY_HEIGHT),
    /* onClick= */ []() {
        std::cout << "Inventory right clicked" << std::endl;
    },
    /* onRender= */ [this](
        SceneNode &node,
        sf::RenderWindow &window,
        sf::Vector2f absolutePos
    ) {
        sf::RectangleShape rightRect;
        rightRect.setSize(size);
        rightRect.setPosition(absolutePos);
        rightRect.setOutlineColor(sf::Color(40, 40, 40, 255));
        rightRect.setOutlineThickness(1.0);
        rightRect.setFillColor(sf::Color(80, 80, 80, 255));

        window.draw(rightRect);
    }
) {}
