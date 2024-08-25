#pragma once

#include <iostream>
#include "../container.hpp"
#include "panel.hpp"
#include "../scene_node.hpp"
#include "SFML/Graphics.hpp"
#include <functional>
#include <vector>
#include "../config/constants.hpp"
#include "../renderer.hpp"
#include "../config/constants.hpp"
#include "SFML/Graphics.hpp"
#include "../player.hpp"
#include "../resource_patch.hpp"
#include "../cursor.hpp"
#include "../resource_patch.hpp"
#include "../config/inventory_item_type.hpp"
#include "../config/resource_patch_type.hpp"
#include <iostream>
#include <memory>
#include "../wooden_chest.hpp"
#include "../item_stack.hpp"
#include <vector>
#include "inventory_grid.hpp"

InventoryGrid::InventoryGrid(sf::Vector2f pos, Container *container) : container(container), SceneNode(
    /* position= */ pos,
    /* size= */ sf::Vector2f(INVENTORY_WIDTH, INVENTORY_HEIGHT),
    /* onClick= */ [](Cursor &cursor) {
        std::cout << "Inventory grid clicked" << std::endl;
    },
    /* onRender= */ [this](
        SceneNode &node,
        sf::RenderWindow &window,
        sf::Vector2f absolutePos
    ) {
        sf::RectangleShape rect;
        rect.setSize(size);
        rect.setPosition(absolutePos);
        rect.setOutlineColor(sf::Color(40, 40, 40, 255));
        rect.setOutlineThickness(2.0);
        rect.setFillColor(sf::Color(80, 80, 80, 255));

        window.draw(rect);
    }
) {}

void InventoryGrid::setContainer(Container *container) {
    this->container = container;
}

Container *InventoryGrid::getContainer() {
    return container;
}
