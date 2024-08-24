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
#include "inventory_slot.hpp"

InventorySlot::InventorySlot(int row, int column, ItemStack *itemStack) : row(row), column(column), itemStack(itemStack), SceneNode(
    /* position= */ sf::Vector2f(column * GRID_SIZE, row * GRID_SIZE),
    /* size= */ sf::Vector2f(GRID_SIZE, GRID_SIZE),
    /* onClick= */ [row, column]() {
        std::cout << "Inventory slot (" << column << "," << row << ") clicked" << std::endl;
    },
    /* onRender= */ [this](
        SceneNode &node,
        sf::RenderWindow &window,
        sf::Vector2f absolutePos
    ) {
        sf::RectangleShape itemRect;
        itemRect.setPosition(absolutePos);
        itemRect.setSize(size);
        itemRect.setFillColor(sf::Color(0, 0, 0, 0));
        itemRect.setOutlineColor(sf::Color(40, 40, 40, 255));
        itemRect.setOutlineThickness(1.0);
        window.draw(itemRect);
    }
) {}
