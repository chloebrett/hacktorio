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

Inventory::Inventory() : SceneNode(
    /* position= */ sf::Vector2f(0, 0),
    /* size= */ sf::Vector2f(GRID_SIZE, GRID_SIZE),
    /* onClick= */ []() {
        std::cout << "Inventory clicked" << std::endl;
    },
    /* onRender= */ [this](
        SceneNode &node,
        sf::RenderWindow &window,
        sf::Vector2f parentPos
    ) {
        sf::RectangleShape mainRect;
        mainRect.setSize(sf::Vector2f(INVENTORY_WIDTH * 2 + INVENTORY_PADDING * 3, INVENTORY_HEIGHT + INVENTORY_PADDING * 2));
        mainRect.setPosition(INVENTORY_H_MARGIN, INVENTORY_V_MARGIN);
        mainRect.setFillColor(sf::Color(120, 120, 120, 255));

        window.draw(mainRect);
    }
) {}
