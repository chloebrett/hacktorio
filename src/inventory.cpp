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

Inventory::Inventory(Player &player, Chest &chest) : player(player), chest(chest), SceneNode(
    /* position= */ pos,
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

        sf::RectangleShape leftRect;
        leftRect.setSize(sf::Vector2f(INVENTORY_WIDTH, INVENTORY_HEIGHT));
        leftRect.setPosition(INVENTORY_H_MARGIN + INVENTORY_PADDING, INVENTORY_V_MARGIN + INVENTORY_PADDING);
        leftRect.setOutlineColor(sf::Color(40, 40, 40, 255));
        leftRect.setOutlineThickness(2.0);
        leftRect.setFillColor(sf::Color(80, 80, 80, 255));

        sf::RectangleShape rightRect;
        rightRect.setSize(sf::Vector2f(INVENTORY_WIDTH, INVENTORY_HEIGHT));
        rightRect.setPosition(INVENTORY_H_MARGIN + INVENTORY_WIDTH + INVENTORY_PADDING * 2, INVENTORY_V_MARGIN + INVENTORY_PADDING);
        rightRect.setOutlineColor(sf::Color(40, 40, 40, 255));
        rightRect.setOutlineThickness(1.0);
        rightRect.setFillColor(sf::Color(80, 80, 80, 255));

        window.draw(mainRect);
        window.draw(leftRect);
        window.draw(rightRect);
    }
) {}
