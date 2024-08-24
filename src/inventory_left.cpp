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
#include "cursor.hpp"
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

InventoryLeft::InventoryLeft(Player &player) : player(player), SceneNode(
    /* position= */ sf::Vector2f(INVENTORY_PADDING, INVENTORY_PADDING),
    /* size= */ sf::Vector2f(INVENTORY_WIDTH, INVENTORY_HEIGHT),
    /* onClick= */ [](Cursor &cursor) {
        std::cout << "Inventory left clicked" << std::endl;
    },
    /* onRender= */ [this](
        SceneNode &node,
        sf::RenderWindow &window,
        sf::Vector2f absolutePos
    ) {
        sf::RectangleShape leftRect;
        leftRect.setSize(size);
        leftRect.setPosition(absolutePos);
        leftRect.setOutlineColor(sf::Color(40, 40, 40, 255));
        leftRect.setOutlineThickness(2.0);
        leftRect.setFillColor(sf::Color(80, 80, 80, 255));

        window.draw(leftRect);
    }
) {}
